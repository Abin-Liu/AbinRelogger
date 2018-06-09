//////////////////////////////////////////////////////////////////////
// Thread.cpp
//
// CThread, a Win32 API wrapping class for basic thread operations.
// This is a pure virtual class, you need to derive your own class
// from CThread and implement the "ThreadProc" member function.
//
// After enough consideration I decided not to support suspending &
// resuming methods. In my opinion those are the most dangerous things
// your can ever do to your threads, suspending a thread may cause
// unpredicted results, for example, a thread can be suspended before
// releasing ownership of synchronization objects, in which case
// deadlocks occur.
//
// If, however, you must maintain suspending & resuming, you are free
// to do so in your own CThread derived classes, and of course do it
// at your own risk...
// 
// Abin (abinn32@yahoo.com)
// 4th May, 2006
//////////////////////////////////////////////////////////////////////
#include "stdafx.h" // Include if needed
#include "Thread.h"
#include <assert.h>

/////////////////////////////////////////////////////////////////////////////////
// CThread Implementation
/////////////////////////////////////////////////////////////////////////////////
CThread::CThread():
m_hThread(NULL), m_dwThreadID(0), m_bAbort(FALSE), m_ncsType(CS_NONE), m_pcs(NULL), m_dwStartTime(0), m_dwStopTime(0)
{
}

CThread::~CThread()
{
	if (m_hThread)
	{
		Stop(2000); // Stop the thread if it's running
		::CloseHandle(m_hThread);
	}

	// If we already have an internal CRITICAL_SECTION, delete it.
	if (m_ncsType == CS_INTERNAL && m_pcs)
	{
		::DeleteCriticalSection(m_pcs);
		delete m_pcs;
	}
}

DWORD CThread::Start(int nPriority)
{
	if (IsAlive())
	{
		::SetLastError(ERROR_TOO_MANY_TCBS);
		return 0;
	}

	m_dwStartTime = 0;
	m_dwStopTime = 0;
	m_bAbort = FALSE;
	m_dwThreadID = 0;	

	if (m_hThread)
		::CloseHandle(m_hThread);
	
	// Create the thread
	m_hThread = ::CreateThread(NULL, 0, _InternalProc, (LPVOID)this, 0, &m_dwThreadID);
	if (m_hThread == NULL)
		m_dwThreadID = 0;
	else
		::SetThreadPriority(m_hThread, nPriority);

	return m_dwThreadID;	
}

void CThread::Stop(DWORD dwTimeout)
{
	// terminate the thread if it's running
	m_bAbort = TRUE; // Set the stopping flag
	
	if (::WaitForSingleObject(m_hThread, dwTimeout) != WAIT_TIMEOUT)
		return; // done

	::TerminateThread(m_hThread, -1); // Terminate if timeout, this is rude, though.
	::SetLastError(ERROR_TIMEOUT);
}

void CThread::PostQuitMessage()
{
	m_bAbort = TRUE; // Set the stopping flag
}

BOOL CThread::IsStopping() const
{
	return m_bAbort;
}

DWORD CThread::_InternalProc(LPVOID lpParameter)
{
	CThread* pThread = (CThread*)lpParameter;
	assert (pThread);

	pThread->m_dwStartTime = ::GetTickCount();
	pThread->m_dwStopTime = 0;
	pThread->OnStart();

	DWORD dwExitCode = pThread->ThreadProc(); // Call the thread proc

	pThread->m_dwStopTime = ::GetTickCount();
	pThread->OnStop();
	return dwExitCode;
}

DWORD CThread::GetAge() const
{
	if (m_dwStartTime == 0)
		return 0; // never started

	if (m_dwStopTime == 0)
		return ::GetTickCount() - m_dwStartTime; // running

	return m_dwStopTime - m_dwStartTime; // stopped
}

DWORD CThread::IsAlive() const
{
	return GetExitCode() == STILL_ACTIVE;
}

BOOL CThread::SetPriority(int nPriority) const
{
	return ::SetThreadPriority(m_hThread, nPriority);
}

int CThread::GetPriority() const
{
	return ::GetThreadPriority(m_hThread);
}

void CThread::Sleep(DWORD dwLength, DWORD dwFragment) const
{
	// Only sleep as long as m_iAbort is zero. It may slow your application down
	// if dwFragment is very small.
	if (dwLength == 0 || m_bAbort)
		return;

	if (dwFragment == 0)
	{
		::Sleep(dwLength);
		return;
	}

	if (dwFragment < 100)
		dwFragment = 100;

	if (dwLength <= dwFragment)
	{
		::Sleep(dwLength);
		return;
	}

	if (dwFragment > dwLength)
		dwFragment = dwLength;

	DWORD dwRemain = dwLength % dwFragment;
	DWORD dwSteps = dwLength / dwFragment;

	for (DWORD i = 0; !m_bAbort && i < dwSteps; i++)
		::Sleep(dwFragment);

	if (!m_bAbort && dwRemain)
		::Sleep(dwRemain);	
}

DWORD CThread::GetID() const
{
	return IsAlive() ? m_dwThreadID : 0;
}

DWORD CThread::GetExitCode() const
{
	if (m_hThread == NULL)
		return 0;

	DWORD dwCode = 0;
	::GetExitCodeThread(m_hThread, &dwCode);
	return dwCode;
}

BOOL CThread::SetCriticalSection(int nType, LPCRITICAL_SECTION pcs)
{
	// nType check
	if (nType != CS_NONE && nType != CS_EXTERNAL && nType != CS_INTERNAL)
	{
		assert(FALSE);
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	// External CRITICAL_SECTION? pcs must be a valid address
	if (nType == CS_EXTERNAL && pcs == NULL)
	{
		assert(FALSE);
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (m_ncsType == nType)
		return TRUE; // No changes required.

	// If we already have an internal CRITICAL_SECTION, delete it.
	if (m_ncsType == CS_INTERNAL && m_pcs)
	{
		::DeleteCriticalSection(m_pcs);
		delete m_pcs;
	}

	m_ncsType = nType;
	m_pcs = NULL;

	if (m_ncsType == CS_EXTERNAL)
	{
		// Assign an external CRITICAL_SECTION address
		m_pcs = pcs;
	}
	else if (m_ncsType == CS_INTERNAL)
	{
		assert(pcs == NULL);

		// Create an internal CRITICAL_SECTION
		m_pcs = new CRITICAL_SECTION;
		assert(m_pcs);
		::InitializeCriticalSection(m_pcs);
	}
	else
	{
		assert(pcs == NULL);
	}

	return TRUE;
}

void CThread::EnterCriticalSection()
{
	assert(m_pcs);
	::EnterCriticalSection(m_pcs);
}

void CThread::LeaveCriticalSection()
{
	assert(m_pcs);
	::LeaveCriticalSection(m_pcs);
}

/////////////////////////////////////////////////////////////////////////////////
// End of CThread Implementation
/////////////////////////////////////////////////////////////////////////////////