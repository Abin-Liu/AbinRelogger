//////////////////////////////////////////////////////////////////////
// TickThread.h
//
// Abin
// 2016-03-15
//////////////////////////////////////////////////////////////////////

#ifndef __TICKTHREAD_H__
#define __TICKTHREAD_H__

#include "Thread.h"

class CTickThread : public CThread  
{
public:	

	CTickThread();
	virtual ~CTickThread();

	void SetInterval(DWORD dwInterval = 200);
	DWORD GetInterval() const;

	void SetState(int nState, DWORD dwMinAge = 0);
	int GetState() const;
	DWORD GetStateAge() const;
	
	virtual DWORD Start(int nInitialState = 0);
	virtual void Pause();
	virtual void Resume();
	virtual BOOL IsPaused() const;

protected:
	
	virtual void OnPause() {}
	virtual void OnResume() {}
	virtual void OnStateChange() {}

	virtual void OnTick(int nState, DWORD dwStateAge) = 0; // Pure virtual

private:

	DWORD ThreadProc();

	DWORD m_dwInterval; // Interval
	BOOL m_bPaused;
	int m_nState;
	DWORD m_dwStateTime;
	DWORD m_dwMinAge;
};

#endif // __TICKTHREAD_H__
