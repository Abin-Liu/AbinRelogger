// Demonbuddy.cpp: implementation of the CDemonbuddy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ARelogger.h"
#include "Demonbuddy.h"
#include "Includes\UTF8File.h"
#include "Includes\Ini.h"
#include "Includes\TextCrypto.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDemonbuddy::CDemonbuddy()
{
	m_dwFreeDemonbuddyID = 0;
	m_dwFreeDiabloID = 0;
}

CDemonbuddy::~CDemonbuddy()
{

}

BOOL CDemonbuddy::CompareWindow(HWND hWnd) const
{
	return IsDemonbuddyWindow(hWnd);
}

void CDemonbuddy::GetConfig(CString &rPath, CString &rKey, CString &rProfile, CString &rBNAccount, CString &rBNPassword, BOOL &rBNAuth, CString &rBNSerial, CString &rBNResCode) const
{
	rPath = m_sPath;
	rKey = m_sKey;
	rProfile = m_sProfile;
	rBNAccount = m_sBNAccount;
	rBNPassword = m_sBNPassword;
	rBNAuth = m_bBNAuth;
	rBNSerial = m_sBNSerial;
	rBNResCode = m_sBNResCode;
}

void CDemonbuddy::SetConfig(LPCTSTR lpszPath, LPCTSTR lpszKey, LPCTSTR lpszProfile, LPCTSTR lpszBNAccount, LPCTSTR lpszBNPassword, BOOL bBNAuth, LPCTSTR lpszBNSerial, LPCTSTR lpszBNResCode)
{
	m_sPath = lpszPath;
	m_sKey = lpszKey;
	m_sProfile = lpszProfile;
	m_sBNAccount = lpszBNAccount;
	m_sBNPassword = lpszBNPassword;
	m_bBNAuth = bBNAuth;
	m_sBNSerial = lpszBNSerial;
	m_sBNResCode = lpszBNResCode;
}

CString CDemonbuddy::GetProfileName() const
{
	CString sFileName;
	int nPos = m_sProfile.ReverseFind(_T('\\'));
	if (nPos == -1)
		sFileName = m_sProfile;
	else
		sFileName = m_sProfile.Mid(nPos + 1);

	//nPos = sFileName.ReverseFind(_T('.'));
	//if (nPos == -1)
		return sFileName;

	//return sFileName.Left(nPos);
}

int CDemonbuddy::Launch(DWORD dwDiabloProcID, BOOL bReuseWnd)
{
	if (dwDiabloProcID == 0)
		return FALSE;

	FindFreeDemonbuddy(dwDiabloProcID, bReuseWnd);

	if (m_dwFreeDemonbuddyID)
	{
		if (Attach(m_dwFreeDemonbuddyID, TRUE))
			return PROCESS_ATTACHED;
	}	

	CString sParams = _T("-autostart -noflash  -routine=\"Trinity\"");

	CString sTemp;
	sTemp.Format(_T(" -pid=%d"), dwDiabloProcID);
	sParams += sTemp;

	sTemp.Format(_T(" -key=%s"), (LPCTSTR)m_sKey);
	sParams += sTemp;

	sTemp.Format(_T(" -profile=\"%s\""), (LPCTSTR)m_sProfile);
	sParams += sTemp;

	sTemp.Format(_T(" -bnetaccount=\"%s\""), (LPCTSTR)m_sBNAccount);
	sParams += sTemp;

	sTemp.Format(_T(" -bnetpassword=\"%s\""), (LPCTSTR)m_sBNPassword);
	sParams += sTemp;

	if (m_bBNAuth)
	{
		sTemp.Format(_T(" -authenticatorserial=\"%s\""), (LPCTSTR)m_sBNSerial);
		sParams += sTemp;

		sTemp.Format(_T(" -authenticatorrestorecode=\"%s\""), (LPCTSTR)m_sBNResCode);
		sParams += sTemp;
	}

	if (Create(m_sPath + _T("\\Demonbuddy.exe"), sParams, m_sPath, TRUE))
		return PROCESS_CREATED;

	return PROCESS_FAILED;
}

void CDemonbuddy::Save(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword) const
{
	ini.WriteString(lpszSection, _T("DemonBuddy Path"), m_sPath);
	ini.WriteString(lpszSection, _T("Profile"), m_sProfile);
	ini.WriteBool(lpszSection, _T("BNet Auth"), m_bBNAuth);

	TCHAR szTemp[501] = _T("");

	TextCrypto::Encrypt(m_sBNAccount, lpszPassword, szTemp, 500);
	ini.WriteString(lpszSection, _T("BNet Account"), szTemp);

	TextCrypto::Encrypt(m_sBNPassword, lpszPassword, szTemp, 500);
	ini.WriteString(lpszSection, _T("BNet Password"), szTemp);

	TextCrypto::Encrypt(m_sBNSerial, lpszPassword, szTemp, 500);
	ini.WriteString(lpszSection, _T("BNet Serial"), szTemp);

	TextCrypto::Encrypt(m_sBNResCode, lpszPassword, szTemp, 500);
	ini.WriteString(lpszSection, _T("BNet Restore"), szTemp);

	TextCrypto::Encrypt(m_sKey, lpszPassword, szTemp, 500);
	ini.WriteString(lpszSection, _T("DemonBuddy Key"), szTemp);	
}

void CDemonbuddy::Load(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword)
{
	m_sPath = ini.GetString(lpszSection, _T("DemonBuddy Path"));
	m_sProfile = ini.GetString(lpszSection, _T("Profile"));
	m_bBNAuth = ini.GetBool(lpszSection, _T("BNet Auth"), FALSE);

	LPTSTR psz = m_sBNAccount.GetBuffer(256);
	TextCrypto::Decrypt(ini.GetString(lpszSection, _T("BNet Account")), lpszPassword, psz, 255);
	m_sBNAccount.ReleaseBuffer();	

	psz = m_sBNPassword.GetBuffer(256);
	TextCrypto::Decrypt(ini.GetString(lpszSection, _T("BNet Password")), lpszPassword, psz, 255);
	m_sBNPassword.ReleaseBuffer();

	psz = m_sBNSerial.GetBuffer(256);
	TextCrypto::Decrypt(ini.GetString(lpszSection, _T("BNet Serial")), lpszPassword, psz, 255);
	m_sBNSerial.ReleaseBuffer();

	psz = m_sBNResCode.GetBuffer(256);
	TextCrypto::Decrypt(ini.GetString(lpszSection, _T("BNet Restore")), lpszPassword, psz, 255);
	m_sBNResCode.ReleaseBuffer();

	psz = m_sKey.GetBuffer(256);
	TextCrypto::Decrypt(ini.GetString(lpszSection, _T("DemonBuddy Key")), lpszPassword, psz, 255);
	m_sKey.ReleaseBuffer();
}

BOOL CDemonbuddy::IsDemonbuddyWindow(HWND hWnd)
{
	TCHAR szTitle[63] = _T("");
	::GetWindowText(hWnd, szTitle, 63);	
	return _tcscmp(szTitle, _T("Demonbuddy")) == 0 || _tcsstr(szTitle, _T("Demonbuddy - ")) == szTitle || _tcsstr(szTitle, _T("DB - ")) == szTitle;
}

CString CDemonbuddy::GetPathName() const
{
	return m_sPath;
}

void CDemonbuddy::Close(BOOL bReuseWindow)
{
	if (bReuseWindow)
		Detach();
	else
		Terminate(FALSE);
}

BOOL CDemonbuddy::CloseErrorWindow() const
{
	HWND hWnd = NULL;
	EnumWindows(CloseErrorWindowProc, (LPARAM)&hWnd, TRUE);
	if (hWnd)
		::PostMessage(hWnd, WM_CLOSE, 0, 0);
	return TRUE;
}

BOOL CDemonbuddy::CloseErrorWindowProc(HWND hWnd, LPARAM lParam)
{
	TCHAR szTitle[63] = _T("");
	::GetWindowText(hWnd, szTitle, 63);
	if (_tcscmp(szTitle, _T("Error")))
		return TRUE;

	HWND* p = (HWND*)lParam;
	if (p)
		*p = hWnd;
	return FALSE;
}

#define SEARCH_PATTERN	_T("Attached to Diablo III with pid: ")
const int PATTERN_LEN = _tcslen(SEARCH_PATTERN);

BOOL CDemonbuddy::CheckDemonbuddyLog(LPCTSTR lpszPathName, LPCTSTR lpszFileName, DWORD dwDiabloProcID)
{
	CStdioFile file;
	CString sCopy;
	BOOL bOK = file.Open(lpszPathName, CFile::modeRead);

	if (!bOK)
	{
		sCopy = AfxGetAppEx()->GetAppDir() + _T('\\') + lpszFileName;
		::CopyFile(lpszPathName, sCopy, FALSE);		
		bOK = file.Open(sCopy, CFile::modeRead);
	}

	DWORD dwID = 0;

	if (bOK)
	{
		CString sLine;		
		for (int i = 0; i < 30 && file.ReadString(sLine); i++)
		{
			int nPos = sLine.Find(SEARCH_PATTERN);
			if (nPos != -1)
			{
				dwID = _ttoi(sLine.Mid(nPos + PATTERN_LEN));
				break;
			}
		}

		file.Close();

		if (sCopy.GetLength())
			::DeleteFile(sCopy);
	}	

	return dwID == dwDiabloProcID;
}

BOOL CDemonbuddy::IsAttachedToDiablo(LPCTSTR lpszFolder, DWORD dwProcID, DWORD dwDiabloProcID)
{
	if (dwProcID == 0 || dwDiabloProcID == 0)
		return FALSE;

	CString sSearch;
	sSearch.Format(_T("%s\\Logs\\%d *.txt"), lpszFolder, dwProcID);
	CFileFind ff;
	BOOL bOK = ff.FindFile(sSearch);
	while (bOK)
	{
		bOK = ff.FindNextFile();
		if (CheckDemonbuddyLog(ff.GetFilePath(), ff.GetFileName(), dwDiabloProcID))
			return TRUE;		
	}	

	return FALSE;
}

BOOL CDemonbuddy::EnumFreeProc(HWND hWnd, LPARAM lParam)
{
	CDemonbuddy* pData = (CDemonbuddy*)lParam;
	ASSERT(pData);
	
	if (!IsDemonbuddyWindow(hWnd))
		return TRUE;

	DWORD pid = 0;
	::GetWindowThreadProcessId(hWnd, &pid);	

	TCHAR szPath[MAX_PATH + 1] = _T("");		
	GetProcessFilePath(pid, szPath, MAX_PATH, TRUE);
	if (*szPath == 0)
		return TRUE;	

	CString sFolder = pData->GetPathName();
	if (sFolder.CompareNoCase(szPath))
		return TRUE;

	if (AfxGetManager().IsDemonbuddyOwned(pid))
		return TRUE;

	if (!IsAttachedToDiablo(sFolder, pid, pData->m_dwFreeDiabloID))
		return TRUE;

	pData->m_dwFreeDemonbuddyID = pid;	
	return FALSE;
}

DWORD CDemonbuddy::FindFreeDemonbuddy(DWORD dwDiabloID, BOOL bReuseWnd)
{	
	m_dwFreeDemonbuddyID = 0;
	m_dwFreeDiabloID = 0;

	if (dwDiabloID == 0)
		return 0;

	if (bReuseWnd)
	{
		m_dwFreeDiabloID = dwDiabloID;
		::EnumWindows(EnumFreeProc, (LPARAM)this);
	}
	
	return m_dwFreeDemonbuddyID;
}

CString CDemonbuddy::GetProfilePath() const
{
	return m_sProfile;
}
