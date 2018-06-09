// Bot.cpp: implementation of the CBot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ARelogger.h"
#include "Bot.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
/////////////////////////////
/////////////////////////////////////////

CBot::CBot(LPCCONFIGDATA pConfig) : m_pConfig(pConfig)
{
	m_bHideGame = FALSE;
	m_dwExistingDiabloID = 0;
	m_dwExistingDemonbuddyID = 0;
	m_bDetach = FALSE;
	m_hParentWnd = NULL;
	m_bDebug = FALSE;
	SetInterval(1000);
}

CBot::~CBot()
{
	Stop(TRUE);
}

DWORD CBot::Start(CWnd *pParentWnd)
{
	ASSERT(pParentWnd);
	m_hParentWnd = pParentWnd->m_hWnd;	

	const CBot* pConflict = AfxGetManager().GetDiabloConflict(this);
	if (pConflict == NULL)		
		return CTickThread::Start();

	::PostMessage(m_hParentWnd, WM_DIABLO_CONFLICT, (WPARAM)this, (LPARAM)pConflict);
	return 0;
}

void CBot::Stop(BOOL bDetach)
{
	ShowWindows(TRUE);
	m_bDetach = bDetach;
	CTickThread::Stop(6000);
}

CString CBot::GetName() const
{
	return m_sName;
}

void CBot::SetName(LPCTSTR lpszName)
{
	m_sName = lpszName;
}

BOOL CBot::Load(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword)
{
	m_sName = ini.GetString(lpszSection, _T("Name"));
	if (m_sName.IsEmpty())
		return FALSE;

	m_bHideGame = ini.GetBool(lpszSection, _T("Hide game"), FALSE);
	m_diablo.Load(ini, lpszSection);
	m_demonBuddy.Load(ini, lpszSection, lpszPassword);	
	return TRUE;
}

void CBot::Save(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword) const
{
	ini.WriteString(lpszSection, _T("Name"), m_sName);
	ini.WriteBool(lpszSection, _T("Hide game"), m_bHideGame);
	m_diablo.Save(ini, lpszSection);
	m_demonBuddy.Save(ini, lpszSection, lpszPassword);
}

void CBot::PauseResume()
{
	if (IsPaused())
		Resume();
	else
		Pause();
}

BOOL CBot::OnMonitorTick()
{
	HWND hDiabloWnd = m_diablo.UpdateWindow(FALSE);
	HWND hDemonBuddyWnd = m_demonBuddy.UpdateWindow(FALSE);
	
	if (!hDemonBuddyWnd && m_demonBuddy.GetExitCode() == 12)
	{		
		ReportState(BOT_MONITOR_TRIPWIRE);
		PostQuitMessage(); // stop the thread
		return TRUE;
	}
	
	if (!hDiabloWnd)
	{
		ReportState(BOT_MONITOR_DIABLO_CLOSED);
		return FALSE;
	}

	if (!hDemonBuddyWnd)
	{
		ReportState(BOT_MONITOR_DEMONBUDDY_CLOSED);
		return FALSE;
	}

	BOOL bGameStateChanged = m_diablo.UpdateGameState();
	int nGameState = m_diablo.GetGameState();	
	NotifyGameStateChange(bGameStateChanged, nGameState);

	if (nGameState == GAME_DISCONNECTED && m_diablo.GetGameStateAge() > m_pConfig->nDisconnect * 1000)
	{		
		ReportState(BOT_MONITOR_DIABLO_DISCONNECTED);
		return FALSE;
	}

	if (nGameState != GAME_JOINED && m_diablo.GetGameStateAge() > m_pConfig->nLeave * 1000)
	{
		ReportState(BOT_MONITOR_OUT_OF_GAME);
		return FALSE;
	}
	
	if (m_diablo.GetHungTime() > m_pConfig->nDiabloHung * 1000)
	{
		ReportState(BOT_MONITOR_DIABLO_UNRESPONSIVE);
		m_diablo.Terminate(TRUE);
		return FALSE;
	}

	if (m_demonBuddy.GetHungTime() > m_pConfig->nDemonbuddyHung * 1000)
	{
		ReportState(BOT_MONITOR_DEMONBUDDY_UNRESPONSIVE);
		m_demonBuddy.Terminate(TRUE);
		return FALSE;
	}

	if (m_pConfig->bNoMin && ::IsIconic(hDiabloWnd))
	{
		ReportState(BOT_MONITOR_DIABLO_MINIMIZED);
		::ShowWindow(hDiabloWnd, SW_RESTORE);
	}	

	return TRUE;
}

CDiablo3& CBot::GetDiablo()
{
	return m_diablo;
}

const CDiablo3& CBot::GetDiablo() const
{
	return m_diablo;
}

CDemonbuddy& CBot::GetDemonBuddy()
{
	return m_demonBuddy;
}

const CDemonbuddy& CBot::GetDemonBuddy() const
{
	return m_demonBuddy;
}

void CBot::OnStart()
{
	CTickThread::OnStart();
	m_bDetach = FALSE;
	ReportState(BOT_STATE_START);
	SetState(BOT_LAUNCH_PREPARE, 500);
}

void CBot::OnStop()
{	
	CTickThread::OnStop();
	SetState(0);	

	m_diablo.Close(m_bDetach);
	m_demonBuddy.Close(m_bDetach);
	ReportState(BOT_STATE_STOP);
}

void CBot::OnPause()
{
	ReportState(BOT_STATE_PAUSE);
}

void CBot::OnResume()
{
	ReportState(BOT_STATE_RESUME);
}

void CBot::NotifyGameStateChange(BOOL bChanged, int nState) const
{
	if (!bChanged)
		return;

	switch (nState)
	{
	case GAME_LOGIN_SCREEN:
		ReportState(BOT_DIABLO_LOGIN_SCREEN);
		break;

	case GAME_JOINED:
		ReportState(BOT_DIABLO_GAME_JOINED);
		break;

	case GAME_LEFT:
		ReportState(BOT_DIABLO_GAME_LEFT);
		break;

	case GAME_DISCONNECTED:
		ReportState(BOT_DIABLO_GAME_DISCONNECTED);
		break;

	default:
		break;
	}
}

void CBot::SetHideGame(BOOL bHide)
{
	if (!m_bHideGame == !bHide)
		return;

	m_bHideGame = bHide;
	
	if (bHide)
		ReportState(BOT_SET_HIDE_WINDOW_TRUE);
	else
		ReportState(BOT_SET_HIDE_WINDOW_FALSE);

	if (GetState() == BOT_LAUNCH_SUCCESSFUL)
		ShowWindows(!bHide);	
}

BOOL CBot::GetHideGame() const
{
	return  m_bHideGame;
}

void CBot::OnTick(int nState, DWORD dwStateAge)
{
	switch (nState)
	{
	case BOT_LAUNCH_PREPARE:		

		if (m_diablo.IsAlive() || m_demonBuddy.IsAlive())
		{
			m_diablo.Terminate(FALSE);
			m_demonBuddy.Terminate(FALSE);
			ReportState(BOT_LAUNCH_CLEANUP);
		}
		else
		{	
			SetState(BOT_LAUNCH_START_DIABLO, 3000);	
		}
		
		break;

	case BOT_LAUNCH_START_DIABLO:

		LaunchDiablo();		
		break;

	case BOT_LAUNCH_WAIT_DIABLO:
		
		m_diablo.UpdateGameState();
		if (m_diablo.IsIdle() && m_diablo.UpdateWindow() && m_diablo.GetGameState() == GAME_LOGIN_SCREEN)
		{
			ReportState(BOT_DIABLO_LOGIN_SCREEN);
			ReportState(BOT_LAUNCH_DIABLO_SUCCESS);
			SetState(BOT_LAUNCH_START_DEMONBUDDY1, 5000);
		}
		else if (dwStateAge > m_pConfig->nDiabloLaunch * 1000)
		{
			ReportState(BOT_LAUNCH_START_DIABLO_FAILED);
			LaunchRetry();
		}

		break;

	case BOT_LAUNCH_START_DEMONBUDDY1:

		LaunchDemonbuddy(BOT_LAUNCH_WAIT_DEMONBUDDY1);
		break;

	case BOT_LAUNCH_WAIT_DEMONBUDDY1:

		WaitDemonbuddy(BOT_LAUNCH_WAIT_BNET_LOGIN, BOT_LAUNCH_START_DEMONBUDDY1, dwStateAge);
		break;

	case BOT_LAUNCH_WAIT_BNET_LOGIN:
		
		m_diablo.UpdateGameState();
		if (m_diablo.GetGameState() == GAME_LOGIN_SUCCESS)
		{
			ReportState(BOT_DIABLO_LOGIN_SUCCESS);
			SetState(BOT_LAUNCH_WAIT_JOIN_GAME, 2000);
		}
		else if (m_diablo.GetGameState() == GAME_LOGIN_FAIL)
		{
			ReportState(BOT_DIABLO_LOGIN_FAILED);
			PostQuitMessage();
		}
		else if (dwStateAge > m_pConfig->nBNetLogin * 1000)
		{
			// login timeout
			ReportState(BOT_LAUNCH_BNET_LOGIN_TIMEOUT);
			LaunchRetry();
		}
		break;

	case BOT_LAUNCH_WAIT_JOIN_GAME:

		m_diablo.UpdateGameState();
		if (m_diablo.GetGameState() == GAME_JOINED)
		{
			ReportState(BOT_DIABLO_GAME_JOINED);

			if (m_pConfig->bDB2x)
			{
				ReportState(BOT_LAUNCH_CLOSE_DEMONBUDDY);	
				m_demonBuddy.Terminate(FALSE);			
				SetState(BOT_LAUNCH_CHECK_DEMONBUDDY_CLOSE);
			}
			else
			{
				ReportState(BOT_LAUNCH_SUCCESSFUL);
				SetState(BOT_LAUNCH_SUCCESSFUL);
			}			
		}
		else if (dwStateAge > m_pConfig->nJoin * 1000)
		{
			ReportState(BOT_LAUNCH_JOIN_GAME_FAILED);
			LaunchRetry();
		}

		break;

	case BOT_LAUNCH_CHECK_DEMONBUDDY_CLOSE:
		
		if (!m_demonBuddy.IsAlive())
		{
			ReportState(BOT_LAUNCH_DEMONBUDDY_CLOSED);
			ReportState(BOT_LAUNCH_WAIT_GAME_STABLIZE);
			SetState(BOT_LAUNCH_START_DEMONBUDDY2, 20000);
		}

		break;

	case BOT_LAUNCH_START_DEMONBUDDY2:

		LaunchDemonbuddy(BOT_LAUNCH_WAIT_DEMONBUDDY2);		
		break;

	case BOT_LAUNCH_WAIT_DEMONBUDDY2:

		WaitDemonbuddy(BOT_LAUNCH_SUCCESSFUL, BOT_LAUNCH_START_DEMONBUDDY2, dwStateAge);
		break;

	case BOT_LAUNCH_SUCCESSFUL:
		
		if (!OnMonitorTick())
			LaunchRetry();

		break;

	default:
		break;
	}
}

BOOL CBot::IsLaunching() const
{
	return GetState() != BOT_LAUNCH_SUCCESSFUL && IsAlive();
}

void CBot::OnStateChange()
{
	ReportState(GetState());
	if (m_bHideGame && GetState() == BOT_LAUNCH_SUCCESSFUL)
	{		
		ReportState(BOT_LAUNCH_HIDE_WINDOWS);
		ShowWindows(FALSE);
	}
}

void CBot::ReportState(int nStateID) const
{
	if (::IsWindow(m_hParentWnd))
		::PostMessage(m_hParentWnd, WM_BOT_STATE, (WPARAM)nStateID, (LPARAM)this);
}

void CBot::LaunchRetry()
{
	m_dwExistingDiabloID = 0;
	m_dwExistingDemonbuddyID = 0;
	ReportState(BOT_LAUNCH_PREPARE);
	SetState(BOT_LAUNCH_PREPARE, 5000);
}

void CBot::Debug()
{
	m_bDebug = TRUE;
}

void CBot::LaunchDiablo()
{
	int nResult = m_diablo.Launch(m_pConfig->bReuseWnd);
	if (nResult == PROCESS_ATTACHED)
	{
		ReportState(BOT_LAUNCH_DIABLO_REUSED);
		SetState(BOT_LAUNCH_START_DEMONBUDDY2);
	}
	else if (nResult == PROCESS_CREATED)
	{
		SetState(BOT_LAUNCH_WAIT_DIABLO, 3000);
	}
	else
	{
		ReportState(BOT_LAUNCH_START_DIABLO_FAILED);
		LaunchRetry();
	}			
}

void CBot::LaunchDemonbuddy(int nNextState)
{
	int nResult = m_demonBuddy.Launch(m_diablo.GetID(), m_pConfig->bReuseWnd);
	if (nResult == PROCESS_ATTACHED)
	{
		ReportState(BOT_LAUNCH_DEMONBUDDY_REUSED);
		SetState(BOT_LAUNCH_SUCCESSFUL);
	}
	else if (nResult == PROCESS_CREATED)
	{
		SetState(nNextState, 3000);
	}
	else
	{
		ReportState(BOT_LAUNCH_START_DEMONBUDDY_FAILED);
		LaunchRetry();
	}
}

void CBot::WaitDemonbuddy(int nNextState, int nErrorState, DWORD dwStateAge)
{
	if (m_demonBuddy.UpdateWindow())
	{
		ReportState(BOT_LAUNCH_DEMONBUDDY_SUCCESS);
		SetState(nNextState, 2000);
	}
	/*
	else if (m_demonBuddy.CloseErrorWindow())
	{
		ReportState(BOT_LAUNCH_CLOSE_DEMONBUDDY_ERROR);
		m_demonBuddy.Terminate(FALSE);
		SetState(nErrorState, 5000);
	}
	*/
	else if (dwStateAge > m_pConfig->nDiabloLaunch * 1000)
	{
		ReportState(BOT_LAUNCH_START_DEMONBUDDY_FAILED);
		LaunchRetry();
	}				
}

void CBot::ShowWindows(BOOL bShow)
{
	int nShowCmd = bShow ? SW_SHOWNORMAL : SW_HIDE;
	HWND hWnd = m_diablo.IsWindow();
	if (hWnd)
		::ShowWindow(hWnd, nShowCmd);

	hWnd = m_demonBuddy.IsWindow();
	if (hWnd)
		::ShowWindow(hWnd, nShowCmd);
}
