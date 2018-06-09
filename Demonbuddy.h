// Demonbuddy.h: interface for the CDemonbuddy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMONBUDDY_H__60D38C5D_8708_42FA_8D85_72197DD2BC3E__INCLUDED_)
#define AFX_DEMONBUDDY_H__60D38C5D_8708_42FA_8D85_72197DD2BC3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Includes\Process.h"
#include "Includes\Ini.h"

class CDemonbuddy : public CProcess  
{
public:	
		
	CDemonbuddy();
	virtual ~CDemonbuddy();

	int Launch(DWORD dwDiabloProcID, BOOL bReuseWnd);
	void Close(BOOL bReuseWindow);

	void GetConfig(CString& rPath, CString& rKey, CString& rProfile, CString& rBNAccount, CString& rBNPassword, BOOL& rBNAuth, CString& rBNSerial, CString& rBNResCode) const;
	void SetConfig(LPCTSTR lpszPath, LPCTSTR lpszKey, LPCTSTR lpszProfile, LPCTSTR lpszBNAccount, LPCTSTR lpszBNPassword, BOOL bBNAuth, LPCTSTR lpszBNSerial, LPCTSTR lpszBNResCode);
	CString GetProfileName() const;
	CString GetProfilePath() const;
	CString GetPathName() const;

	void Save(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword) const;
	void Load(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword);

	static BOOL IsDemonbuddyWindow(HWND hWnd);
	BOOL CloseErrorWindow() const;


	DWORD FindFreeDemonbuddy(DWORD dwDiabloID, BOOL bReuseWnd);

protected:
	
	BOOL CompareWindow(HWND hWnd) const;
	static BOOL CALLBACK CloseErrorWindowProc(HWND hWnd, LPARAM lParam);
	static BOOL CALLBACK EnumFreeProc(HWND hWnd, LPARAM lParam);
	static BOOL IsAttachedToDiablo(LPCTSTR lpszFolder, DWORD dwProcID, DWORD dwDiabloProcID);
	static BOOL CheckDemonbuddyLog(LPCTSTR lpszPathName, LPCTSTR lpszFileName, DWORD dwDiabloProcID);

	CString m_sPath;
	CString m_sKey;
	CString m_sProfile;
	CString m_sBNAccount;
	CString m_sBNPassword;
	BOOL m_bBNAuth;
	CString m_sBNSerial;	
	CString m_sBNResCode;
	DWORD m_dwFreeDemonbuddyID;
	DWORD m_dwFreeDiabloID;
};

#endif // !defined(AFX_DEMONBUDDY_H__60D38C5D_8708_42FA_8D85_72197DD2BC3E__INCLUDED_)
