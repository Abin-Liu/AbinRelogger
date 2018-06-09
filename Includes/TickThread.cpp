//////////////////////////////////////////////////////////////////////
// TickThread.cpp
//
// Abin
// 2016-03-15
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TickThread.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTickThread::CTickThread() :
m_dwInterval(100), m_bPaused(FALSE), m_nState(0), m_dwStateTime(0), m_dwMinAge(0)
{
}

CTickThread::~CTickThread()
{
	Stop();
}

void CTickThread::SetState(int nState, DWORD dwMinAge)
{
	if (m_nState != nState)
	{
		m_nState = nState;
		m_dwStateTime = ::GetTickCount();
		m_dwMinAge = dwMinAge;		
	}
}

int CTickThread::GetState() const
{
	return m_nState;
}

DWORD CTickThread::GetStateAge() const
{
	return ::GetTickCount() - m_dwStateTime;
}

DWORD CTickThread::Start(int nInitialState)
{
	m_nState = nInitialState;

	DWORD dwResult = CThread::Start();
	if (dwResult)
		OnStateChange();
	else
		m_nState = 0;

	return dwResult;
}

void CTickThread::Pause()
{
	if (!m_bPaused && IsAlive())
	{
		m_bPaused = TRUE;
		OnPause();
	}
}

void CTickThread::Resume()
{
	if (m_bPaused && IsAlive())
	{
		m_bPaused = FALSE;
		OnResume();
	}
}

BOOL CTickThread::IsPaused() const
{
	return m_bPaused;
}

DWORD CTickThread::ThreadProc()
{
	m_bPaused = FALSE;
	m_dwStateTime = ::GetTickCount();

	int nPrevState = 0;

	while (!IsStopping())
	{
		if (!m_bPaused)
		{
			if (nPrevState != m_nState)
			{
				nPrevState = m_nState;
				OnStateChange();
			}
			
			DWORD m_dwStateAge = ::GetTickCount() - m_dwStateTime;
			if (m_dwStateAge >= m_dwMinAge)
				OnTick(m_nState, m_dwStateAge);
			else
				OnTick(0, 0); // We guarantee OnTick is called for every pulse, even useless ones
		}
		
		Sleep(m_dwInterval, 100);
	}

	if (m_bPaused)
	{
		m_bPaused = FALSE;
		OnResume();
	}

	if (m_nState)
	{
		m_nState = 0;
		OnStateChange();
	}

	return 0;
}

void CTickThread::SetInterval(DWORD dwInterval)
{
	if (dwInterval < 100)
		dwInterval = 100;

	if (m_dwInterval != dwInterval)
		m_dwInterval = dwInterval;
}

DWORD CTickThread::GetInterval() const
{
	return m_dwInterval;
}


