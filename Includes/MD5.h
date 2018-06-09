/////////////////////////////////////////////////////
// MD5.h
//
// Calculation MD5 checksum for data blocks or files.
//
// Abin (abinn32@yahoo.com)
// 2011-9-25
/////////////////////////////////////////////////////

#ifndef __CHECKSUM_H__
#define __CHECKSUM_H__

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define MD5_STR_LENGTH	32

/////////////////////////////////////////////////////
// Callback function called during calculation process of MD5
// checksum, return non-zero to proceed, or zero to abort.
/////////////////////////////////////////////////////
typedef BOOL (CALLBACK *fnMD5Callback)(int nSequenceCount, int nSequenceID, LPVOID lParam);

namespace MD5
{
	void CalcData(LPCVOID lpData, DWORD dwDataSize, LPSTR lpszBuff);
	void CalcData(LPCVOID lpData, DWORD dwDataSize, LPWSTR lpszBuff);
	void CalcText(LPCSTR lpszText, LPSTR lpszBuff);
	void CalcText(LPCWSTR lpszText, LPWSTR lpszBuff);
	BOOL CalcFile(LPCSTR lpszFilePath, LPSTR lpszBuff, fnMD5Callback fnCallback = NULL, LPVOID lParam = 0);
	BOOL CalcFile(LPCWSTR lpszFilePath, LPWSTR lpszBuff, fnMD5Callback fnCallback = NULL, LPVOID lParam = 0);	
};

#endif // __CHECKSUM_H__
