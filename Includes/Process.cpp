// Process.cpp: implementation of the CProcess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Process.h"
#include <TLHELP32.H>
#include <Psapi.h>
#pragma comment(lib,"Psapi.lib")

struct PROCESS_ENUM_WINDOW_DATA
{
	DWORD dwProcessID;
	WNDENUMPROC fnEnumProc;
	LPARAM lParam;
	BOOL bVisibleOnly;
};

// Genetic enum proc
BOOL CALLBACK _EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	PROCESS_ENUM_WINDOW_DATA* pData = (PROCESS_ENUM_WINDOW_DATA*)lParam;
	ASSERT(pData);

	if (pData->bVisibleOnly && !::IsWindowVisible(hWnd))
		return TRUE;

	DWORD pid = 0;
	::GetWindowThreadProcessId(hWnd, &pid);
	if (pid != pData->dwProcessID)
		return TRUE;
	
	if (pData->fnEnumProc && pData->fnEnumProc(hWnd, pData->lParam))
		return TRUE;

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcess::CProcess()
{
	m_dwProcessID = 0;
	m_hProcess = NULL;
	m_hMainWnd = NULL;
	m_dwStartTime = 0;
	m_bHasWindow = FALSE;	
	m_dwLastResponse = 0;
}

CProcess::~CProcess()
{
	if (m_hProcess)
		::CloseHandle(m_hProcess);
}

DWORD CProcess::GetExitCode() const
{
	if (m_hProcess == NULL)
		return 0;

	DWORD dwExitCode = 0;
	::GetExitCodeProcess(m_hProcess, &dwExitCode);
	return dwExitCode;
}

BOOL CProcess::IsAlive() const
{	
	return GetExitCode() == STILL_ACTIVE;
}

DWORD CProcess::GetID() const
{
	return IsAlive() ? m_dwProcessID : 0;
}

BOOL CALLBACK CProcess::_FindMainWndProc(HWND hWnd, LPARAM lParam)
{
	CProcess* pData = (CProcess*)lParam;
	ASSERT(pData);	
	
	if (pData->CompareWindow(hWnd))
	{
		// Main window found, stop enum
		pData->m_hMainWnd = hWnd;
		return FALSE;
	}
	
	return TRUE;
}

HWND CProcess::UpdateWindow(BOOL bVisibleOnly)
{
	if (!m_bHasWindow)
		return NULL;

	if (!IsAlive())
	{
		m_hMainWnd = NULL;
		return NULL;
	}	

	if (!::IsWindow(m_hMainWnd))
	{	m_hMainWnd = NULL;		
		EnumWindows(_FindMainWndProc, (LPARAM)this, bVisibleOnly);
	}

	if (m_hMainWnd == NULL)
		return NULL;

	if (m_hMainWnd && ::SendMessageTimeout(m_hMainWnd, 0, 0, 0, SMTO_ABORTIFHUNG, 200, NULL))
		m_dwLastResponse = ::GetTickCount();

	return m_hMainWnd;
}

void CProcess::_AttachInfo(DWORD dwProcessID, HANDLE hProcess, BOOL bHasWindow, BOOL bCreate)
{
	m_dwProcessID = dwProcessID;
	m_hProcess = hProcess;
	m_bHasWindow = bHasWindow;
	m_hMainWnd = NULL;
	m_dwStartTime = ::GetTickCount();
	m_dwLastResponse = ::GetTickCount();

	if (bCreate)
		OnCreate();
	else
		UpdateWindow();

	OnAttach();
}

void CProcess::_DetachInfo(BOOL bTerminate)
{
	m_dwProcessID = 0;
	::CloseHandle(m_hProcess);
	m_hProcess = NULL;
	m_bHasWindow = FALSE;
	m_hMainWnd = NULL;
	m_dwStartTime = 0;
	m_dwLastResponse = 0;

	OnDetach();

	if (bTerminate)
		OnTerminate();
}

BOOL CProcess::Create(LPCTSTR lpszExePath, LPCTSTR lpszParams, LPCTSTR lpszLocation, BOOL bHasWindow)
{
	if (m_hProcess != NULL)
		return FALSE;

	if (lpszExePath == NULL || *lpszExePath == 0)
		return FALSE;
	
	PROCESS_INFORMATION info = { 0 };
	STARTUPINFO dummy = { sizeof(STARTUPINFO) };

	LPTSTR pszParams = NULL;
	if (lpszParams && *lpszParams)
	{
		// need to insert a space in front
		pszParams = new TCHAR[_tcslen(lpszParams) +2];
		pszParams[0] = _T(' ');
		_tcscpy(&(pszParams[1]), lpszParams);
	}

	BOOL bResult = ::CreateProcess(lpszExePath, pszParams, NULL, NULL, FALSE, 0, NULL, lpszLocation, &dummy, &info);

	if (pszParams)
	{
		delete [] pszParams;
		pszParams = NULL;
	}

	if (bResult)
	{		
		::CloseHandle(info.hThread); // sorry not interested
		_AttachInfo(info.dwProcessId, info.hProcess, bHasWindow, TRUE);	
	}

	return bResult;
}

void _Send_WM_CLOSE(HWND hWnd, DWORD dwTimeout)
{
	::SendMessageTimeout(hWnd, WM_CLOSE, 0, 0, SMTO_ABORTIFHUNG | SMTO_NOTIMEOUTIFNOTHUNG, dwTimeout, NULL);
}

static BOOL CALLBACK _CloseWindowProc(HWND hWnd, LPARAM lParam)
{
	_Send_WM_CLOSE(hWnd, lParam);
	return TRUE;
}

void CProcess::Terminate(BOOL bForceKill)
{
	if (m_dwProcessID == 0)
		return;
	
	if (IsWindow())
		_Send_WM_CLOSE(m_hMainWnd, 6000);

	if (IsAlive())
		EnumWindows(_CloseWindowProc, 6000); // Send WM_CLOSE to all associated windows	

	if (bForceKill && IsAlive())
		::TerminateProcess(m_hProcess, 0); // only call if extremely necessary!
	
	_DetachInfo(TRUE);
}

BOOL CProcess::Attach(DWORD dwProcessID, BOOL bHasWindow)
{
	if (m_hProcess != NULL)
		return FALSE;

	if (dwProcessID == 0)
		return FALSE;

	HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_TERMINATE, FALSE, dwProcessID);

	if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE)
		return FALSE;
	
	_AttachInfo(dwProcessID, hProcess, bHasWindow, FALSE);
	return TRUE;
}

void CProcess::Detach()
{
	if (m_dwProcessID)
		_DetachInfo(FALSE);
}

HWND CProcess::IsWindow() const
{
	return ::IsWindow(m_hMainWnd) ? m_hMainWnd : NULL;
}

DWORD CProcess::GetLastResponse() const
{
	return m_dwLastResponse;
}

DWORD CProcess::GetHungTime() const
{
	return ::GetTickCount() - m_dwLastResponse;
}

BOOL CProcess::IsIdle() const
{
	return m_hProcess == NULL || ::WaitForInputIdle(m_hProcess, 200) != WAIT_TIMEOUT;
}

BOOL CProcess::IsResponsive() const
{
	return m_hMainWnd == NULL || ::SendMessageTimeout(m_hMainWnd, 0, 0, 0, SMTO_ABORTIFHUNG, 200, NULL);
}

BOOL CProcess::EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam, BOOL bVisibleOnly) const
{
	if (lpEnumFunc == NULL || !IsAlive())
		return FALSE;

	PROCESS_ENUM_WINDOW_DATA data = { 0 };
	data.dwProcessID = m_dwProcessID;
	data.fnEnumProc = lpEnumFunc;
	data.lParam = lParam;
	data.bVisibleOnly = bVisibleOnly;
	return ::EnumWindows(_EnumWindowsProc, (LPARAM)&data);
}

DWORD CProcess::FindProcessByName(LPCTSTR lpszName)
{
	if (lpszName == NULL || *lpszName == 0)
		return 0;

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcess = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcess == INVALID_HANDLE_VALUE)
		return 0;
	
	DWORD dwProcessID = 0;
	BOOL bOK = ::Process32First(hProcess, &pe32);
	while (bOK)
	{
		if (_tcsicmp(pe32.szExeFile, lpszName) == 0)
		{
			dwProcessID = pe32.th32ProcessID;
			break;
		}
		
		bOK = ::Process32Next(hProcess, &pe32);
	}

	::CloseHandle(hProcess);
	return dwProcessID;
}

BOOL CProcess::KillProcess(DWORD dwProcessID, DWORD dwExitCode)
{
	HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, dwProcessID);
	if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE)
		return FALSE;

	::TerminateProcess(hProcess, dwExitCode);
	::CloseHandle(hProcess);
	return TRUE;
}

BOOL CProcess::GetProcessFilePath(DWORD dwProcessID, LPTSTR lpszBuff, int nMaxLen, BOOL bDirectoryOnly)
{
	if (lpszBuff == NULL || nMaxLen < 1)
		return FALSE;

	*lpszBuff = 0;
	
	HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, dwProcessID);
	if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE)
		return FALSE;

	HMODULE hModule = NULL; 
	DWORD cbNeeded = 0;

	BOOL bResult = ::EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded);
	if (bResult)
		bResult = ::GetModuleFileNameEx(hProcess, hModule, lpszBuff, nMaxLen);

	if (bResult && bDirectoryOnly)
	{
		LPTSTR p = _tcsrchr(lpszBuff, _T('\\'));
		if (p)
			*p = 0;
	}

	::CloseHandle(hProcess);
	return bResult;
}

HMODULE hKernel32 = ::LoadLibraryA("Kernel32.dll");

typedef DWORD (WINAPI * FN_GETPROCESSID)(HANDLE);
FN_GETPROCESSID _GetProcessId = FN_GETPROCESSID(::GetProcAddress(hKernel32, "GetProcessId"));

DWORD CProcess::GetProcessIDFromHandle(HANDLE hProcess)
{
	if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE || _GetProcessId == NULL)
		return 0;

	return _GetProcessId(hProcess);
}