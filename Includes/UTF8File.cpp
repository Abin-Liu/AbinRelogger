///////////////////////////////////////////////////////////////////////////
// UTF8File.h
//
// A set of function for UTF-8 text file reading and writing.
// Pure Win32 API wrapping, no additional dependencies.
//
// Abin (abinn32@yahoo.com)
// May 30, 2006
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // Include if needed
#include "UTF8File.h"

// The "UTF8-tag" that must be inserted at the very begining of every UTF8 file.
#define UTF8TAG_LEN		3
static const BYTE UTF8TAG[UTF8TAG_LEN] = { 0xef, 0xbb, 0xbf };

BOOL _UTF8FileTest(HANDLE hFile)
{
	BYTE aHeader[UTF8TAG_LEN] = { 0 };
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwRead = 0;
		::ReadFile(hFile, aHeader, UTF8TAG_LEN, &dwRead, NULL);
	}	
	return ::memcmp(UTF8TAG, aHeader, UTF8TAG_LEN) == 0;
}

BOOL IsUTF8FileA(LPCSTR lpszFilePath)
{
	HANDLE hFile = ::CreateFileA(lpszFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	BOOL bOK = _UTF8FileTest(hFile);
	::CloseHandle(hFile);
	return bOK;
}

BOOL IsUTF8FileW(LPCWSTR lpszFilePath)
{
	HANDLE hFile = ::CreateFileW(lpszFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	BOOL bOK = _UTF8FileTest(hFile);
	::CloseHandle(hFile);
	return bOK;
}

DWORD UTF8ReadFileA(LPCSTR lpszFilePath, LPSTR lpszBuffer, DWORD dwMaxChars)
{
	if (lpszFilePath == NULL || lpszBuffer == NULL || dwMaxChars < 2)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return 0;
	}
	
	DWORD dwALen = 0;
	lpszBuffer[0] = 0;

	HANDLE hFile = ::CreateFileA(lpszFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;
	
	// Read the row file (UTF8 data) into a block	
	DWORD dwFLen = ::GetFileSize(hFile, NULL);
	if (dwFLen)
	{
		LPSTR pData = new CHAR[dwFLen];
		DWORD dwRead = 0;
		::ReadFile(hFile, pData, dwFLen, &dwRead, NULL);

		LPSTR p = pData;
		// SKip the UTF8 tag, if any
		if (dwFLen >= UTF8TAG_LEN && ::memcmp(pData, UTF8TAG, UTF8TAG_LEN) == 0)
		{
			p += UTF8TAG_LEN;
			dwFLen -= UTF8TAG_LEN;
		}

		if (dwFLen)
		{
			// Cast the UTF8 data into wide-chars
			LPWSTR pwsz = new WCHAR[dwFLen];
			DWORD dwWLen = ::MultiByteToWideChar(CP_UTF8, 0, p, dwFLen, pwsz, dwFLen);
			// Cast the wide-chars into MB string
			dwALen = ::WideCharToMultiByte(CP_ACP, 0, pwsz, dwWLen, lpszBuffer, dwMaxChars - 1, NULL, NULL);
			delete [] pwsz;
			// null-terminate it
			lpszBuffer[dwALen] = 0;			
		}

		delete [] pData;
	}
	
	::CloseHandle(hFile);
	return dwALen;
}

DWORD UTF8ReadFileW(LPCWSTR lpszFilePath, LPWSTR lpszBuffer, DWORD dwMaxChars)
{
	if (lpszFilePath == NULL || lpszBuffer == NULL || dwMaxChars < 2)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return 0;
	}

	DWORD dwWLen = 0;
	lpszBuffer[0] = 0;

	HANDLE hFile = ::CreateFileW(lpszFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	// Read the row file (UTF8 data) into a block	
	DWORD dwFLen = ::GetFileSize(hFile, NULL);
	if (dwFLen)
	{
		LPSTR pData = new CHAR[dwFLen];
		DWORD dwRead = 0;
		::ReadFile(hFile, pData, dwFLen, &dwRead, NULL);

		LPSTR p = pData;
		// SKip the UTF8 tag, if any
		if (dwFLen >= UTF8TAG_LEN && ::memcmp(pData, UTF8TAG, UTF8TAG_LEN) == 0)
		{
			p += UTF8TAG_LEN;
			dwFLen -= UTF8TAG_LEN;
		}

		if (dwFLen)
		{
			// Cast the UTF8 data into wide-chars
			dwWLen = ::MultiByteToWideChar(CP_UTF8, 0, p, dwFLen, lpszBuffer, dwMaxChars - 1);
			// null-terminate it
			lpszBuffer[dwWLen] = 0;			
		}

		delete [] pData;
	}
	
	::CloseHandle(hFile);
	return dwWLen;
}

DWORD UTF8WriteFileA(LPCSTR lpszFilePath, LPCSTR lpszString)
{
	if (lpszFilePath == NULL || lpszString == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return 0;
	}

	HANDLE hFile = ::CreateFileA(lpszFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	DWORD dwWritten = 0;
	::WriteFile(hFile, UTF8TAG, UTF8TAG_LEN, &dwWritten, NULL);
	dwWritten = 0;
	
	DWORD dwALen = ::strlen(lpszString);
	if (dwALen)
	{
		// Cast the MB string into wide-chars
		LPWSTR pwsz = new WCHAR[dwALen];
		DWORD dwWLen = ::MultiByteToWideChar(CP_ACP, 0, lpszString, dwALen, pwsz, dwALen);
		if (dwWLen)
		{
			// Cast the wide-chars into UTF8 block
			LPSTR psz = new CHAR[dwALen * 3];
			DWORD dwFLen = ::WideCharToMultiByte(CP_UTF8, 0, pwsz, dwWLen, psz, dwALen * 3, NULL, NULL);
			::WriteFile(hFile, psz, dwFLen, &dwWritten, NULL);			
			delete [] psz;			
		}		
		delete [] pwsz;		
	}
	
	::CloseHandle(hFile);
	return dwWritten + UTF8TAG_LEN;
}

DWORD UTF8WriteFileW(LPCWSTR lpszFilePath, LPCWSTR lpszString)
{
	if (lpszFilePath == NULL || lpszString == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return 0;
	}

	HANDLE hFile = ::CreateFileW(lpszFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	DWORD dwWritten = 0;
	::WriteFile(hFile, UTF8TAG, UTF8TAG_LEN, &dwWritten, NULL);
	dwWritten = 0;
	
	DWORD dwWLen = ::wcslen(lpszString);
	if (dwWLen)
	{
		// Cast the wide-chars into UTF8 block
		LPSTR psz = new CHAR[dwWLen * 3];
		DWORD dwFLen = ::WideCharToMultiByte(CP_UTF8, 0, lpszString, dwWLen, psz, dwWLen * 3, NULL, NULL);			
		::WriteFile(hFile, psz, dwFLen, &dwWritten, NULL);			
		delete [] psz;			
	}
	
	::CloseHandle(hFile);
	return dwWritten + UTF8TAG_LEN;
}
