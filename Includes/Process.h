//////////////////////////////////////////////////////////////////////
// Process.h
//
// Abin
// 2016-03-12
//////////////////////////////////////////////////////////////////////

#ifndef __PROCESS_H__
#define __PROCESS_H__

class CProcess  
{
public:	

	CProcess();
	virtual ~CProcess();

	virtual BOOL Create(LPCTSTR lpszExePath, LPCTSTR lpszParams, LPCTSTR lpszLocation, BOOL bHasWindow = TRUE);
	virtual void Terminate(BOOL bForceKill);
	virtual BOOL Attach(DWORD dwProcessID, BOOL bHasWindow = TRUE);
	virtual void Detach();
	virtual HWND UpdateWindow(BOOL bVisibleOnly = TRUE);
	BOOL EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam = 0, BOOL bVisibleOnly = TRUE) const; // Enumerates all windows created by this process
	
	DWORD GetID() const;
	DWORD GetExitCode() const;
	BOOL IsAlive() const;
	HWND IsWindow() const;
	BOOL IsIdle() const;
	BOOL IsResponsive() const;
	DWORD GetLastResponse() const;
	DWORD GetHungTime() const; // Time elapsed since the last time the window was responsive

	static BOOL GetProcessFilePath(DWORD dwProcessID, LPTSTR lpszBuff, int nMaxLen, BOOL bDirectoryOnly = FALSE);
	static DWORD FindProcessByName(LPCTSTR lpszName);
	static BOOL KillProcess(DWORD dwProcessID, DWORD dwExitCode = 0);
	static DWORD GetProcessIDFromHandle(HANDLE hProcess);

protected:	

	// Overrides
	virtual void OnCreate() {}
	virtual void OnTerminate() {}
	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual BOOL CompareWindow(HWND hWnd) const { return TRUE; } // Return TRUE if hWnd is our main window

private:	
	
	void _AttachInfo(DWORD dwProcessID, HANDLE hProcess, BOOL bHasWindow, BOOL bCreate);
	void _DetachInfo(BOOL bTerminate);
	
	static BOOL CALLBACK _FindMainWndProc(HWND hWnd, LPARAM lParam);

	DWORD m_dwProcessID; // Process ID
	HANDLE m_hProcess; // Process handle
	HWND m_hMainWnd; // Process main window
	DWORD m_dwStartTime; // Process attaching time
	DWORD m_dwLastResponse;	// Last time the process main window was responsive
	BOOL m_bHasWindow; // Whether we need to check process main window
};

#endif // __PROCESS_H__
