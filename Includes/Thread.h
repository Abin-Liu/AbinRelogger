//////////////////////////////////////////////////////////////////////
// Thread.h
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

#ifndef __THREAD_H__
#define __THREAD_H__

#include <windows.h>

/////////////////////////////////////////////////////////////////////////////////
// CThread Class
// 
// The generic thread definition.
/////////////////////////////////////////////////////////////////////////////////
class CThread  
{
public:
	
	// Constructors & Destructor
	CThread();
	virtual ~CThread();

	// Start & stop
	virtual DWORD Start(int nPriority = THREAD_PRIORITY_NORMAL); // Start a thread
	virtual void Stop(DWORD dwTimeout = INFINITE); // Stop the running thread
	virtual void PostQuitMessage(); // Set the stopping flag and return immediately, a healthy thread should stop shortly

	// Thread status
	DWORD GetID() const; // Retrieve thread ID
	DWORD IsAlive() const; // Is the thread is alive?
	BOOL IsStopping() const; // The thread being stopped? Application's ThreadProc function shall keep tracking this!
	DWORD GetAge() const; // Age of the thread, in milliseconds 
	DWORD GetExitCode() const; // Retrieve thread exit code

	// Conditional sleep, only sleep when IsStopping() returns zero
	void Sleep(DWORD dwLength, DWORD dwFragment = 100) const;

	// Thread priority
	BOOL SetPriority(int nPriority) const; // Set thread priority
	int GetPriority() const;	

	/////////////////////////////////////////////////////////////////////////////
	// Set the CRITICAL_SECTION object for sync, parameters:
	//
	// pcs - address of a CRITICAL_SECTION object when nType equals to CS_EXTERNAL.
	// nType - specifies type of the CRITICAL_SECTION object, this value can be:
	//
	// CS_NONE: none, pcs is ignored, subsequent calls to EnterCriticalSection or LeaveCriticalSection will cause assertion failures.
	// CS_EXTERNAL: use an external CRITICAL_SECTION object, pcs must be valid address to an already initialized CRITICAL_SECTION object.
	// CS_INTERNAL: maintain an internal CRITICAL_SECTION object, pcs is ignored.
	//
	// By default, CThread does not use any CRITICAL_SECTION object for synchronization until SetCriticalSection is
	// explicitly called.
	/////////////////////////////////////////////////////////////////////////////
	enum { CS_NONE = 0, CS_EXTERNAL, CS_INTERNAL };
	virtual BOOL SetCriticalSection(int nType, LPCRITICAL_SECTION pcs);

	// Synchronization. SetCriticalSection (with nType being CS_EXTERNAL or CS_INTERNAL) must have been called before.
	virtual void EnterCriticalSection();
	virtual void LeaveCriticalSection();

protected:

	/////////////////////////////////////////////////////////////////////////////
	// The thread process function, must be overridden! This is actually the core
	// of any derived classes. A thread is meaningless without implementing this
	// method. 
	/////////////////////////////////////////////////////////////////////////////
	virtual DWORD ThreadProc() = 0;
	virtual void OnStart() {}
	virtual void OnStop() {}

private:	

	static DWORD WINAPI _InternalProc(LPVOID lpParameter); // The primitive thread proc
	
	volatile BOOL m_bAbort; // Abort signal
	HANDLE m_hThread; // The thread handle
	int m_ncsType; // CRITICAL_SECTION type
	LPCRITICAL_SECTION m_pcs; // Address of the CRITICAL_SECTION object, can be NULL
	DWORD m_dwStartTime;
	DWORD m_dwStopTime;
	DWORD m_dwThreadID;
};

#endif // __THREAD_H__
