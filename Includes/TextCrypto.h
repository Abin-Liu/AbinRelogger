////////////////////////////////////////////////////////////////
// TextCrypto.h
//
// Encrypts text with password protection
//
// Abin
// 2016-03-20
////////////////////////////////////////////////////////////////

#ifndef __TEXTENCRYPT_H__
#define __TEXTENCRYPT_H__

namespace TextCrypto
{
	void Randomize(); // You should call this once when your app starts

	////////////////////////////////////////////////////////////////
	// Parameters:
	//
	// [IN] lpszText -- The source string to be encrypted/decrypted, cannot be NULL
	// [IN] lpszPassword -- The password to protect our encrypted string, can be NULL
	// [OUT] lpszBuff - The buffer to receive encrypted/decrypted results, cannot be NULL
	// [IN] nMaxLength - The maximum length lpszBuff has, if this value is smaller than actually needed, the functions fail
	//
	// Error codes (returned by ::GetLastError() after functions fail)
	//
	// ERROR_INVALID_PARAMETER -- One or more parameters are invalid, usually lpszText/lpszBuff being NULL
	// ERROR_OUTOFMEMORY -- Failed to allocate memory
	// ERROR_BAD_LENGTH -- nMaxLength is smaller than actually needed 
	// ERROR_CRC -- CRC checksum failed, lpszText is not a valid encrypted string. Only for Decrypt
	// 
	////////////////////////////////////////////////////////////////

	BOOL Encrypt(LPCSTR lpszText, LPCSTR lpszPassword, LPSTR lpszBuff, int nMaxLength); // Encrypt lpszText into lpszBuff
	BOOL Encrypt(LPCWSTR lpszText, LPCWSTR lpszPassword, LPWSTR lpszBuff, int nMaxLength);
	BOOL Decrypt(LPCSTR lpszText, LPCSTR lpszPassword, LPSTR lpszBuff, int nMaxLength); // Decrypt lpszText into lpszBuff
	BOOL Decrypt(LPCWSTR lpszText, LPCWSTR lpszPassword, LPWSTR lpszBuff, int nMaxLength);
};

#endif // __TEXTENCRYPT_H__