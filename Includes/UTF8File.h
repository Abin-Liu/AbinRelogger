///////////////////////////////////////////////////////////////////////////
// UTF8File.h
//
// A set of function for UTF-8 text file reading and writing.
// Pure Win32 API wrapping, no additional dependencies.
//
// Abin (abinn32@yahoo.com)
// May 30, 2006
///////////////////////////////////////////////////////////////////////////

#ifndef __UTF8FILE_H__
#define __UTF8FILE_H__

#include <windows.h>

///////////////////////////////////////////////////////////////////////////
//		IsUTF8File
//-------------------------------------------------------------------------
// Check whether a file contains UTF8 encoded contents.
//
// lpszFilePath: [in] Path of the file to be examed.
//
// Return values: Non-zero if the file contains UTF8 encoded contents, zero otherwise.
///////////////////////////////////////////////////////////////////////////
BOOL IsUTF8FileA(LPCSTR lpszFilePath);
BOOL IsUTF8FileW(LPCWSTR lpszFilePath);

///////////////////////////////////////////////////////////////////////////
//		UTF8ReadFile
//-------------------------------------------------------------------------
// Read from an UTF8-encoded text file, decode the file contents, and put 
// decoded text into a character string buffer.
//
// lpszFilePath: [in] Path of the source UTF8 file location.
// lpszBuffer: [out] Pointer to the string buff to receive decoded text.
// dwMaxChars: [in] The maximum number of characters lpszBuffer can store.
//					The null-terminator is included.
//
// Return values: number of characters that have been put into lpszBuffer.
///////////////////////////////////////////////////////////////////////////
DWORD UTF8ReadFileA(LPCSTR lpszFilePath, LPSTR lpszBuffer, DWORD dwMaxChars);
DWORD UTF8ReadFileW(LPCWSTR lpszFilePath, LPWSTR lpszBuffer, DWORD dwMaxChars);

///////////////////////////////////////////////////////////////////////////
//		UTF8WriteFile
//-------------------------------------------------------------------------
// Encode a given string into UTF8 format and write the encoded contents
// to a disk file.
//
// lpszFilePath: [in] Path of the destination UTF8 file location.
// lpszString: [in] Pointer to a null-terminated string to be encoded.
//
// Return values: number of bytes that have been saved into file lpszFilePath.
///////////////////////////////////////////////////////////////////////////
DWORD UTF8WriteFileA(LPCSTR lpszFilePath, LPCSTR lpszString);
DWORD UTF8WriteFileW(LPCWSTR lpszFilePath, LPCWSTR lpszString);

#ifdef UNICODE
#define IsUTF8File		IsUTF8FileW
#define UTF8ReadFile	UTF8ReadFileW
#define UTF8WriteFile	UTF8WriteFileW
#else
#define IsUTF8File		IsUTF8FileA
#define UTF8ReadFile	UTF8ReadFileA
#define UTF8WriteFile	UTF8WriteFileA
#endif

#endif // __UTF8FILE_H__