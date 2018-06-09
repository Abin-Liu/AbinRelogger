// Diablo3.cpp: implementation of the CDiablo3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ARelogger.h"
#include "Diablo3.h"
#include "Includes\Ini.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDiablo3::CDiablo3()
{
	m_dwReadSize = 0;
	m_nGameState = GAME_UNKNOWN;
	m_dwGameStateTime = 0;
	m_dwFreeDiabloID = 0;
}

CDiablo3::~CDiablo3()
{
}

BOOL CDiablo3::IsDiabloWindow(HWND hWnd)
{
	TCHAR szClass[63] = _T("");
	::GetClassName(hWnd, szClass, 63);
	return _tcscmp(szClass, _T("D3 Main Window Class")) == 0;
}

BOOL CDiablo3::CompareWindow(HWND hWnd) const
{
	return IsDiabloWindow(hWnd);
}

void CDiablo3::GetConfig(CString &sPath) const
{
	sPath = m_sPath;
}

void CDiablo3::SetConfig(LPCTSTR lpszPath)
{
	m_sPath = lpszPath;
}

int CDiablo3::Launch(BOOL bReuseWnd)
{
	m_nGameState = GAME_UNKNOWN;
	m_dwReadSize = 0;

	FindFreeDiablo(bReuseWnd);
	
	if (m_dwFreeDiabloID)
	{
		if (Attach(m_dwFreeDiabloID, TRUE))
			return PROCESS_ATTACHED;
	}

	if (Create(m_sPath + _T("\\Diablo III.exe"), _T("-launch"), m_sPath, TRUE))
		return PROCESS_CREATED;

	return PROCESS_FAILED;
}

void CDiablo3::Save(CIni& ini, LPCTSTR lpszSection) const
{	
	ini.WriteString(lpszSection, _T("Diablo Path"), m_sPath);
}

void CDiablo3::Load(CIni& ini, LPCTSTR lpszSection)
{
	m_sPath = ini.GetString(lpszSection, _T("Diablo Path"));
}

int CDiablo3::GetGameState() const
{
	return m_nGameState;
}

DWORD CDiablo3::GetGameStateAge() const
{
	return m_dwGameStateTime ? ::GetTickCount() - m_dwGameStateTime : 0;
}

BOOL CDiablo3::CheckStateChange(int nOldState, int nNewState)
{
	if (nOldState == nNewState)
		return FALSE;

	if (nOldState == GAME_UNKNOWN)
		return TRUE;
	
	if (nNewState == GAME_DISCONNECTED && nOldState != GAME_LOGIN_SUCCESS && nOldState != GAME_JOINED && nOldState != GAME_LEFT)
		return FALSE;

	return TRUE;
}

BOOL CDiablo3::UpdateGameState()
{
	if (m_sPath.IsEmpty())
		return FALSE;

	CStdioFile file;
	if (!file.Open(m_sPath + _T("\\D3Debug.txt"), CFile::modeRead))
		return FALSE;

	const DWORD dwSize = file.GetLength();
	if (dwSize == 0 || dwSize == m_dwReadSize)
	{
		file.Close();
		return FALSE;
	}

	if (dwSize < m_dwReadSize)
		m_dwReadSize = 0;

	if (m_dwReadSize)
		file.Seek(m_dwReadSize, CFile::begin);

	BOOL bReadOK = FALSE;
	int nGameState = GAME_UNKNOWN;
	CString sLine;
	while (file.ReadString(sLine))
	{
		for (int i = 0; i < NUM_DIABLO_STATES; i++)
		{
			const DIABLO_STATE_ENTRY& entry = DIABLO_STATE_ENTRIES[i];
			if (sLine.Find(entry.lpszText) == -1)
				continue;

			if (!CheckStateChange(nGameState, entry.nStateID))
				continue;

			bReadOK = TRUE;
			nGameState = entry.nStateID;
		}
	}

	file.Close();
	m_dwReadSize = dwSize;	
	
	if (!bReadOK || m_nGameState == nGameState)
		return FALSE;

	m_nGameState = nGameState;
	m_dwGameStateTime = ::GetTickCount();
	return TRUE; // state changed
}


CString CDiablo3::GetPathName() const
{
	return m_sPath;
}

void CDiablo3::Close(BOOL bReuseWindow)
{
	if (bReuseWindow)
		Detach();
	else
		Terminate(FALSE);
}

BOOL CDiablo3::EnumFreeProc(HWND hWnd, LPARAM lParam)
{
	CDiablo3* pData = (CDiablo3*)lParam;
	ASSERT(pData);

	if (!IsDiabloWindow(hWnd))
		return TRUE;

	DWORD pid = 0;
	::GetWindowThreadProcessId(hWnd, &pid);

	if (AfxGetManager().IsDiabloOwned(pid))
		return TRUE;

	TCHAR szPath[MAX_PATH + 1] = _T("");		
	GetProcessFilePath(pid, szPath, MAX_PATH, FALSE);
	CString sExePath = pData->GetPathName() + _T("\\Diablo III.exe");	
	if (sExePath.CompareNoCase(szPath))
		return TRUE;

	pData->m_dwFreeDiabloID = pid;	
	return FALSE;
}

DWORD CDiablo3::FindFreeDiablo(BOOL bReuseWnd)
{
	m_dwFreeDiabloID = 0;
	if (bReuseWnd)
		::EnumWindows(EnumFreeProc, (LPARAM)this);
	return m_dwFreeDiabloID;
}
