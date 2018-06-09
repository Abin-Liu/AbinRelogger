#include "stdafx.h"
#include "TextCrypto.h"

/*---------------Encrypted String Format--------------------

0        1        2        3        4(in DWORD)
0        8        16       24       32(in BYTE)
xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx .........................
CRC      rand     pwd      len      contents
\-----------Header(4)-------------/ \---Contents(various)---/
-----------------------------------------------------------*/

// key indices in bytes
#define TEXTCRYPTO_IDX_BYTE_CHECKSUM	0  // CRC-32 checksum location
#define TEXTCRYPTO_IDX_BYTE_RAND		8  // Random seed location
#define TEXTCRYPTO_IDX_BYTE_PWD		16 // Password CRC-32 checksum location
#define TEXTCRYPTO_IDX_BYTE_LEN		24 // Actual length location
#define TEXTCRYPTO_IDX_BYTE_CONTENTS	32 // Beginning of contents

// key indices in dwords
#define TEXTCRYPTO_IDX_DWORD_CHECKSUM	0  // CRC-32 checksum location
#define TEXTCRYPTO_IDX_DWORD_RAND		1  // Random seed location
#define TEXTCRYPTO_IDX_DWORD_PWD		2 // Password CRC-32 checksum location
#define TEXTCRYPTO_IDX_DWORD_LEN		3 // Actual length location
#define TEXTCRYPTO_IDX_DWORD_CONTENTS	4 // Beginning of contents

// header length
#define TEXTCRYPTO_LEN_ENTIRE_HEADER	32 // Total header length

// byte threshold
#define TEXTCRYPTO_BYTE_THRESHOLD	8 // byte length threshold (in bytes)

#define TEXTCRYPTO_TEXTCRYPTO_CODE_TABLE_SIZE	64 // Total 64 entries in the code table

// Code Table, "magical numbers" used for encryption/decryption
static const DWORD TEXTCRYPTO_CODE_TABLE[] = {
	0x8714668F, 0x15896769, 0x410DD373, 0x56CC4937, // 1
	0xDBC64283, 0x8DCF38BD, 0xB2F795D4, 0xE1CD2DC1, // 2
	0xBDE4ED07, 0x975C6403, 0x9BBAF741, 0xA4EB4323, // 3
	0xFB164504, 0xBD0495EA, 0xAE4E7F84, 0xC2ED1A8D, // 4
	0xA7826C21, 0x068646A6, 0x937C9CF8, 0x3326AFFE, // 5
	0xF7284FE7, 0x0E3D48E9, 0x92C61B8F, 0x3FCC812A, // 6
	0x4E59E861, 0x971941A1, 0xBBFC6524, 0x56742AB8, // 7
	0xE80C6431, 0x2ACD43CE, 0xAFBF3885, 0xD9E70A21, // 8

	0xC6EF31BF, 0x4B7A4EA6, 0xB18DA2A5, 0x9DA3C5DF, // 9
	0x97395918, 0x66374F0D, 0x978DE1B0, 0xF8712B92, // 10
	0xCB7F64B8, 0xF32A49C7, 0x8882BCD1, 0x8D6F1F3E, // 11
	0xB8E94BC5, 0x85A04DA3, 0xA0D02CB9, 0xD7D24E96, // 12
	0x9EB05095, 0xC272491B, 0xAA7B76C7, 0xC25E5AB7, // 13
	0x4E7BFD54, 0x10324DAE, 0xB1D51125, 0x9B1D3963, // 14
	0xA8A827EB, 0x349D44FC, 0xAB3F8E9C, 0x44B867C9, // 15
	0x167684F9, 0x130D4AD5, 0xAFEF5CE1, 0x0F148F9C  // 16
 };

// Index modifiers
static const DWORD TEXTCRYPTO_ODD_KEY  = 0xBD2D7AF3; // Used to encrypt odd-index chars
static const DWORD TEXTCRYPTO_EVEN_KEY = 0xA0FB16F1; // Used to encrypt even-index chars

int TEXTCRYPTO_IsValidSrc(LPCSTR lpSrc);
DWORD TEXTCRYPTO_Extract(LPCSTR lpSrc, int nOffset);
int TEXTCRYPTO_PatchLength(int nLen, int nThreshold);
DWORD TEXTCRYPTO_CalcCRC(LPCSTR lpSrc);
BOOL TEXTCRYPTO_VerifyChecksum(LPCSTR lpSrc);
BOOL TEXTCRYPTO_VerifyPassword(LPCSTR lpSrc, LPCSTR lpPassword, DWORD dwRand);
DWORD TEXTCRYPTO_CalcPassword(LPCSTR lpPassword);
DWORD TEXTCRYPTO_DecDWORD(BOOL bMod, DWORD dwSrc, DWORD dwPasswordMod = 0, DWORD dwRand = 0);
DWORD TEXTCRYPTO_EncDWORD(BOOL bMod, DWORD dwSrc, DWORD dwPasswordMod = 0, DWORD dwRand = 0);
DWORD TEXTCRYPTO_ApplyIndices(DWORD dwVal, DWORD dwIdx, BOOL bEncrypt);
DWORD TEXTCRYPTO_RandDWORD();
DWORD TEXTCRYPTO_CRCReflect(DWORD dwRef, BYTE ch);
LPSTR TEXTCRYPTO_AllocAnsiStr(LPCWSTR lpszText);
BOOL TEXTCRYPTO_PramsPrecheck(LPCSTR lpszText, LPSTR lpszBuff, int nMaxLength);
BOOL TEXTCRYPTO_PramsPrecheck(LPCWSTR lpszText, LPWSTR lpszBuff, int nMaxLength);

////////////////////////////////////////////////////////////////////////////////////
// Implementation
////////////////////////////////////////////////////////////////////////////////////

DWORD TEXTCRYPTO_RandDWORD()
{
	BYTE b1 = BYTE(32 + (::rand() % 95));
	BYTE b2 = BYTE(32 + (::rand() % 95));
	BYTE b3 = BYTE(32 + (::rand() % 95));
	BYTE b4 = BYTE(32 + (::rand() % 95));
	return MAKELONG(MAKEWORD(b1, b2), MAKEWORD(b3, b4));
}

DWORD TEXTCRYPTO_Extract(LPCSTR lpSrc, int nOffset)
{
	char sz[9] = "";
	::strncpy(sz, lpSrc + nOffset, 8);
	return ::strtoul(sz, NULL, 16);
}

int TEXTCRYPTO_IsValidSrc(LPCSTR lpSrc)
{
	if (lpSrc == NULL)
		return 0;

	const int LEN = ::strlen(lpSrc);
	if ((LEN % 8) != 0)
		return 0;

	if (LEN < TEXTCRYPTO_LEN_ENTIRE_HEADER + TEXTCRYPTO_BYTE_THRESHOLD * 2)
		return 0;

	for (int i = 0; i < LEN; i++)
	{
		if ((lpSrc[i] < 'A' || lpSrc[i] > 'F') && (lpSrc[i] < '0' || lpSrc[i] > '9'))
			return 0; // not in hexadecimal format
	}

	return LEN;
}

// Return a number that can be evenly divided by a threshold,
// for example, suppose the threshold is 8:
// Given 1, it returns 8, given 9, it returns 16, etc. 
int TEXTCRYPTO_PatchLength(int nLen, int nThreshold)
{
	if (nThreshold < 2)
		return nLen;

	int nPatch = nLen % nThreshold;
	if (nPatch > 0)
		nPatch = nThreshold - nPatch;
	return nLen + nPatch;
}

DWORD TEXTCRYPTO_CRCReflect(DWORD dwRef, BYTE ch)
{
    DWORD dwValue = 0;

    // Swap bit 0 for bit 7
    // bit 1 for bit 6, etc.
    for(int i = 1; i < (ch + 1); i++)
    {
        if (dwRef & 1)
            dwValue |= 1 << (ch - i);
        dwRef >>= 1;
    }

    return dwValue;
}

static const DWORD TEXTCRYPTO_CRC_POLYNOMIAL = 0x04C11DB7;
static DWORD TEXTCRYPTO_CRC_TABLE[256] = { 0 };

// Calculates CRC-32 value of a string
DWORD TEXTCRYPTO_CalcCRC(LPCSTR lpSrc)
{	
	if (lpSrc == NULL || *lpSrc == 0)
		return 0;

	for (int i = 0; i <= 0xff; i++)
	{
        TEXTCRYPTO_CRC_TABLE[i] = TEXTCRYPTO_CRCReflect(i, 8) << 24;
        for (int j = 0; j < 8; j++)
            TEXTCRYPTO_CRC_TABLE[i] = (TEXTCRYPTO_CRC_TABLE[i] << 1) ^ (TEXTCRYPTO_CRC_TABLE[i] & (1 << 31) ? TEXTCRYPTO_CRC_POLYNOMIAL : 0);
        TEXTCRYPTO_CRC_TABLE[i] = TEXTCRYPTO_CRCReflect(TEXTCRYPTO_CRC_TABLE[i], 32);
	}

	int nLen = ::strlen(lpSrc);
	DWORD dwResult = 0xffffffff;

	LPBYTE p = (LPBYTE)lpSrc;

    while (nLen--)
        dwResult = (dwResult >> 8) ^ TEXTCRYPTO_CRC_TABLE[(dwResult & 0xff) ^ *p++];

	return dwResult ^ 0xffffffff;
}

BOOL TEXTCRYPTO_VerifyChecksum(LPCSTR lpSrc)
{
	// extract CRC value, it's the first 8 bytes
	const DWORD ORIG_CRC = TEXTCRYPTO_DecDWORD(TRUE, TEXTCRYPTO_Extract(lpSrc, 0), 0, 0); // The original crc

	// calculate real CRC and compare
	return ORIG_CRC == TEXTCRYPTO_CalcCRC(lpSrc + 8);
}

BOOL TEXTCRYPTO_VerifyPassword(LPCSTR lpSrc, LPCSTR lpPassword, DWORD dwRand)
{
	// extract password value
	const DWORD ORIG_CRC = TEXTCRYPTO_DecDWORD(TRUE, TEXTCRYPTO_Extract(lpSrc, TEXTCRYPTO_IDX_BYTE_PWD), 0, dwRand); // The original crc
	
	// always returns TRUE if originally not password protected.
	return (ORIG_CRC == 0) ? TRUE : (ORIG_CRC == TEXTCRYPTO_CalcCRC(lpPassword));
}

DWORD TEXTCRYPTO_CalcPassword(LPCSTR lpPassword)
{
	if (lpPassword == NULL || *lpPassword == 0)
		return 0;

	const int LEN = ::strlen(lpPassword);
	const int NEWLEN = TEXTCRYPTO_PatchLength(LEN, 4);
	BYTE* psz = new BYTE[NEWLEN];

	// Get an array of bytes related to lpPassword, excessing spaces are filled with zeros
	::memset(psz, 0, NEWLEN);
	::memcpy(psz, lpPassword, LEN);

	// Stack elements together to get a DWORD
	DWORD dwVal = 0, dwMod = 0;
	::memcpy(&dwVal, psz, 4);

	for (int i = 4; i < NEWLEN; i+= 4)
	{
		::memcpy(&dwMod, &psz[i], 4);
		dwVal ^= dwMod;
	}

	delete [] psz;
	return dwVal;
}

DWORD TEXTCRYPTO_ApplyIndices(DWORD dwVal, DWORD dwIdx, BOOL bEncrypt)
{
	BYTE b[4];
	for (int m = 0; m < 4; m++)
		b[m] = BYTE(dwIdx + m);

	const DWORD MOD = MAKELONG(MAKEWORD(b[0], b[1]), MAKEWORD(b[2], b[3])); 
		
	if (bEncrypt)
	{
		dwVal ^= MOD;
		dwVal ^= ((dwIdx % 2) == 0 ? TEXTCRYPTO_EVEN_KEY : TEXTCRYPTO_ODD_KEY);
	}
	else
	{			
		dwVal ^= ((dwIdx % 2) == 0 ? TEXTCRYPTO_EVEN_KEY : TEXTCRYPTO_ODD_KEY);
		dwVal ^= MOD;
	}

	return dwVal;
}

DWORD TEXTCRYPTO_DecDWORD(BOOL bMod, DWORD dwSrc, DWORD dwPasswordMod, DWORD dwRand)
{	
	if (bMod)
	{
		dwSrc ^= dwPasswordMod;		
		dwSrc ^= dwRand;
		for (int j = TEXTCRYPTO_TEXTCRYPTO_CODE_TABLE_SIZE - 1; j >= 0 ; j--)
			dwSrc ^= TEXTCRYPTO_CODE_TABLE[j];
	}

	return dwSrc;
}

DWORD TEXTCRYPTO_EncDWORD(BOOL bMod, DWORD dwSrc, DWORD dwPasswordMod, DWORD dwRand)
{
	if (bMod)
	{
		for (int j = 0; j < TEXTCRYPTO_TEXTCRYPTO_CODE_TABLE_SIZE; j++)
			dwSrc ^= TEXTCRYPTO_CODE_TABLE[j];			
		dwSrc ^= dwRand;
		dwSrc ^= dwPasswordMod;			
	}

	return dwSrc;
}

LPSTR TEXTCRYPTO_AllocAnsiStr(LPCWSTR lpszText)
{
	if (lpszText == NULL || *lpszText == 0)
		return NULL;

	const int BUFF_LEN = ::wcslen(lpszText) + 2;
	LPSTR pszText = new CHAR[BUFF_LEN];
	if (pszText)
		::WideCharToMultiByte(CP_ACP, 0, lpszText, -1, pszText, BUFF_LEN, NULL, NULL);
	else
		::SetLastError(ERROR_OUTOFMEMORY);

	return pszText;	
}

void TextCrypto::Randomize()
{
	::srand(::time(NULL));
}

BOOL TEXTCRYPTO_PramsPrecheck(LPCSTR lpszText, LPSTR lpszBuff, int nMaxLength)
{
	if (lpszText == NULL || lpszBuff == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (nMaxLength < 1)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}

	*lpszBuff = 0;
	return TRUE;
}

BOOL TEXTCRYPTO_PramsPrecheck(LPCWSTR lpszText, LPWSTR lpszBuff, int nMaxLength)
{
	if (lpszText == NULL || lpszBuff == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (nMaxLength < 1)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}

	*lpszBuff = 0;
	return TRUE;
}

BOOL TextCrypto::Encrypt(LPCSTR lpszText, LPCSTR lpszPassword, LPSTR lpszBuff, int nMaxLength)
{	
	if (!TEXTCRYPTO_PramsPrecheck(lpszText, lpszBuff, nMaxLength))
		return FALSE;
	
	if (*lpszText == 0)
		return TRUE;

	if (nMaxLength < TEXTCRYPTO_LEN_ENTIRE_HEADER + 2)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}

	if (*lpszPassword == 0)
		lpszPassword = NULL;

	const int SRC_LEN = ::strlen(lpszText);
	const int BUFF_SIZE = TEXTCRYPTO_LEN_ENTIRE_HEADER + TEXTCRYPTO_PatchLength(SRC_LEN, TEXTCRYPTO_BYTE_THRESHOLD) * 2;

	if (nMaxLength < BUFF_SIZE)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}

	const int DWCOUNT = (BUFF_SIZE - TEXTCRYPTO_LEN_ENTIRE_HEADER) / 8; // dwords needed
	const int RAND = MAKELONG(WORD(::rand() + 1), WORD(::rand() + 1));
	const DWORD PWDCRC = TEXTCRYPTO_CalcCRC(lpszPassword);
	const DWORD PWDMOD = TEXTCRYPTO_CalcPassword(lpszPassword);

	LPDWORD pHeader = new DWORD[4];
	LPDWORD pContents = new DWORD[DWCOUNT];	

	// Encrypt the header
	pHeader[TEXTCRYPTO_IDX_DWORD_RAND] = TEXTCRYPTO_EncDWORD(TRUE, RAND, 0, 0);
	pHeader[TEXTCRYPTO_IDX_DWORD_PWD]  = TEXTCRYPTO_EncDWORD(TRUE, PWDCRC,	0, RAND);
	pHeader[TEXTCRYPTO_IDX_DWORD_LEN]  = TEXTCRYPTO_EncDWORD(TRUE, SRC_LEN, PWDMOD, RAND);

	int i = 0;

	for (i = 0; i < TEXTCRYPTO_IDX_DWORD_CONTENTS; i++)
		::sprintf(lpszBuff + i * 8, "%08X", pHeader[i]);

	// Fill spaces with random "textual" bytes (32-127)
	for (i = 0; i < DWCOUNT; i++)
		pContents[i] = TEXTCRYPTO_RandDWORD();

	::memcpy(pContents, lpszText, SRC_LEN);	

	// Encrypt contents
	for (i = 0; i < DWCOUNT; i++)
	{
		pContents[i] = TEXTCRYPTO_EncDWORD(TRUE, pContents[i], PWDMOD, RAND);
		pContents[i] = TEXTCRYPTO_ApplyIndices(pContents[i], i, TRUE);
		::sprintf(lpszBuff + TEXTCRYPTO_IDX_BYTE_CONTENTS + i * 8, "%08X", pContents[i]);
	}

	delete [] pHeader;
	delete [] pContents;

	// Calc and write CRC for whole string
	char szCrc[9] = "";
	DWORD dwCrc = TEXTCRYPTO_CalcCRC(lpszBuff + TEXTCRYPTO_IDX_BYTE_RAND);
	::sprintf(szCrc, "%08X", TEXTCRYPTO_EncDWORD(TRUE, dwCrc, 0, 0));
	::memcpy(lpszBuff, szCrc, 8);

	return TRUE;
}

BOOL TextCrypto::Encrypt(LPCWSTR lpszText, LPCWSTR lpszPassword, LPWSTR lpszBuff, int nMaxLength)
{
	if (!TEXTCRYPTO_PramsPrecheck(lpszText, lpszBuff, nMaxLength))
		return FALSE;
	
	if (*lpszText == 0)
		return TRUE;

	if (nMaxLength < TEXTCRYPTO_LEN_ENTIRE_HEADER + 2)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}
	
	LPSTR pszText = TEXTCRYPTO_AllocAnsiStr(lpszText);
	if (pszText == NULL)
		return FALSE;

	LPSTR pszPassword = NULL;
	if (lpszPassword && *lpszPassword)
	{
		pszPassword = TEXTCRYPTO_AllocAnsiStr(lpszPassword);
		if (pszPassword == NULL)
		{
			delete [] pszText;
			return FALSE;
		}
	}

	LPSTR pszBuff = new CHAR[nMaxLength];
	if (pszBuff == NULL)
	{
		delete [] pszText;
		if (pszPassword)
			delete [] pszPassword;

		::SetLastError(ERROR_OUTOFMEMORY);
		return FALSE;
	}
		
	BOOL bResult = Encrypt(pszText, pszPassword, pszBuff, nMaxLength);

	if (pszText)
		delete [] pszText;

	if (pszPassword)
		delete [] pszPassword;

	if (bResult)
		::MultiByteToWideChar(CP_ACP, 0, pszBuff, -1, lpszBuff, nMaxLength);

	delete [] pszBuff;	
	return TRUE;	
}

BOOL TextCrypto::Decrypt(LPCSTR lpszText, LPCSTR lpszPassword, LPSTR lpszBuff, int nMaxLength)
{
	if (!TEXTCRYPTO_PramsPrecheck(lpszText, lpszBuff, nMaxLength))
		return FALSE;
	
	if (*lpszText == 0)
		return TRUE;

	const int SRC_LEN = TEXTCRYPTO_IsValidSrc(lpszText);
	if (SRC_LEN == 0)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (!TEXTCRYPTO_VerifyChecksum(lpszText))
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	const int RAND = TEXTCRYPTO_DecDWORD(TRUE, TEXTCRYPTO_Extract(lpszText, TEXTCRYPTO_IDX_BYTE_RAND), 0, 0);
	if (!TEXTCRYPTO_VerifyPassword(lpszText, lpszPassword, RAND))
	{
		::SetLastError(ERROR_INVALID_PASSWORD);
		return FALSE;
	}

	const DWORD PWDMOD = TEXTCRYPTO_CalcPassword(lpszPassword);
	const int ACT_LEN = TEXTCRYPTO_DecDWORD(TRUE, TEXTCRYPTO_Extract(lpszText, TEXTCRYPTO_IDX_BYTE_LEN), PWDMOD, RAND);
	if (ACT_LEN == 0)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (nMaxLength < ACT_LEN)
	{
		::SetLastError(ERROR_BAD_LENGTH);
		return FALSE;
	}

	const int DWCOUNT = (SRC_LEN - TEXTCRYPTO_LEN_ENTIRE_HEADER) / 8;
	DWORD* pContents = new DWORD[DWCOUNT];
	
	// convert the string into dword format
	LPCSTR psz = lpszText + TEXTCRYPTO_IDX_BYTE_CONTENTS;
	for (int i = 0; i < DWCOUNT; i++)
	{
		pContents[i] = TEXTCRYPTO_Extract(lpszText, TEXTCRYPTO_IDX_BYTE_CONTENTS + i * 8);
		pContents[i] = TEXTCRYPTO_ApplyIndices(pContents[i], i, FALSE);
		pContents[i] = TEXTCRYPTO_DecDWORD(TRUE, pContents[i], PWDMOD, RAND);	
	}

	::memcpy(lpszBuff, pContents, ACT_LEN);
	lpszBuff[ACT_LEN] = 0;
	return TRUE;
}

BOOL TextCrypto::Decrypt(LPCWSTR lpszText, LPCWSTR lpszPassword, LPWSTR lpszBuff, int nMaxLength)
{
	if (!TEXTCRYPTO_PramsPrecheck(lpszText, lpszBuff, nMaxLength))
		return FALSE;
	
	if (*lpszText == 0)
		return TRUE;

	LPSTR pszText = TEXTCRYPTO_AllocAnsiStr(lpszText);
	if (pszText == NULL)
		return FALSE;

	LPSTR pszPassword = NULL;
	if (lpszPassword && *lpszPassword)
	{
		pszPassword = TEXTCRYPTO_AllocAnsiStr(lpszPassword);
		if (pszPassword == NULL)
		{
			delete [] pszText;
			return FALSE;
		}
	}

	BOOL bResult = Decrypt(pszText, pszPassword, (LPSTR)lpszBuff, nMaxLength);

	delete [] pszText;

	if (pszPassword)
		delete [] pszPassword;

	if (!bResult)
		return FALSE;

	pszText = ::strdup((LPSTR)lpszBuff);

	::MultiByteToWideChar(CP_ACP, 0, pszText, -1, lpszBuff, nMaxLength);
	delete [] pszText;
	
	return TRUE;
}
