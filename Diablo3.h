// Diablo3.h: interface for the CDiablo3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIABLO3_H__85ED957E_52F3_4C7E_9ADE_0596DF13CDC4__INCLUDED_)
#define AFX_DIABLO3_H__85ED957E_52F3_4C7E_9ADE_0596DF13CDC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Includes\Process.h"
#include "Includes\Ini.h"

class CDiablo3 : public CProcess  
{
public:

	CDiablo3();
	virtual ~CDiablo3();

	int Launch(BOOL bReuseWnd);
	void Close(BOOL bReuseWindow);

	void GetConfig(CString& sPath) const;
	void SetConfig(LPCTSTR lpszPath);

	void Save(CIni& ini, LPCTSTR lpszSection) const;
	void Load(CIni& ini, LPCTSTR lpszSection);

	BOOL UpdateGameState();
	int GetGameState() const;
	DWORD GetGameStateAge() const;
	CString GetPathName() const;
	DWORD FindFreeDiablo(BOOL bReuseWnd);

	static BOOL IsDiabloWindow(HWND hWnd);

protected:

	static BOOL CheckStateChange(int nOldState, int nNewState);
	BOOL CompareWindow(HWND hWnd) const;

	static BOOL CALLBACK EnumFreeProc(HWND hWnd, LPARAM lParam);

	CString m_sPath;
	DWORD m_dwReadSize;
	int m_nGameState;
	DWORD m_dwGameStateTime;
	DWORD m_dwFreeDiabloID;
};

#endif // !defined(AFX_DIABLO3_H__85ED957E_52F3_4C7E_9ADE_0596DF13CDC4__INCLUDED_)
