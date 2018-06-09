// BotManager.cpp: implementation of the CBotManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ARelogger.h"
#include "BotManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBotManager::CBotManager()
{
	::memset(&m_config, 0, sizeof(m_config));
	InitStateMap();
}

CBotManager::~CBotManager()
{
	StopAll();

	for (int i = 0; i < m_aBotArray.GetSize(); i++)
		delete m_aBotArray[i];

	m_aBotArray.RemoveAll();
}

int CBotManager::GetCount() const
{
	return m_aBotArray.GetSize();
}

const CBot* CBotManager::GetByIndex(int nIndex) const
{
	if (nIndex < 0 || nIndex >= m_aBotArray.GetSize())
		return NULL;

	return m_aBotArray[nIndex];
}

CBot* CBotManager::Add()
{	
	CBot* pBot = new CBot(&m_config);
	m_aBotArray.Add(pBot);
	return pBot;
}

void CBotManager::Delete(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_aBotArray.GetSize())
		return;

	CBot* pBot = m_aBotArray[nIndex];
	m_aBotArray.RemoveAt(nIndex);

	pBot->Stop(FALSE);
	delete pBot;
}

int CBotManager::Find(const CBot *pBot) const
{
	if (pBot == NULL)
		return -1;

	for (int i = 0; i < m_aBotArray.GetSize(); i++)
	{
		if (pBot == m_aBotArray[i])
			return i;
	}

	return  -1;
}

const CBot* CBotManager::GetDiabloConflict(const CBot *pBot) const
{
	if (pBot == NULL)
		return NULL;

	const CString sPath = pBot->GetDiablo().GetPathName();
	
	for (int i = 0; i < m_aBotArray.GetSize(); i++)
	{
		const CBot* p = m_aBotArray[i];
		if (p != pBot && p->IsAlive() && sPath.CompareNoCase(p->GetDiablo().GetPathName()) == 0)
			return p;
	}

	return NULL;
}

const CBot* CBotManager::IsDiabloOwned(DWORD dwProcessID) const
{
	if (dwProcessID == 0)
		return NULL;

	for (int i = 0; i < m_aBotArray.GetSize(); i++)
	{
		const CBot* pBot = m_aBotArray[i];
		if (pBot->GetDiablo().GetID() == dwProcessID)
			return pBot;
	}

	return NULL;
}

const CBot* CBotManager::IsDemonbuddyOwned(DWORD dwProcessID) const
{
	if (dwProcessID == 0)
		return NULL;

	for (int i = 0; i < m_aBotArray.GetSize(); i++)
	{
		const CBot* pBot = m_aBotArray[i];
		if (pBot->GetDemonBuddy().GetID() == dwProcessID)
			return pBot;
	}

	return NULL;
}

int CBotManager::GetAliveCount() const
{
	int nCount = 0;
	for (int i = 0; i < m_aBotArray.GetSize(); i++)
	{
		if (m_aBotArray[i]->IsAlive())
			nCount++;
	}
	return nCount;
}

void CBotManager::ShowAll()
{
	for (int i = 0; i < m_aBotArray.GetSize(); i++)
		m_aBotArray[i]->SetHideGame(FALSE);
}

void CBotManager::HideAll()
{
	for (int i = 0; i < m_aBotArray.GetSize(); i++)
		m_aBotArray[i]->SetHideGame(TRUE);
}

void CBotManager::StopAll()
{
	for (int i = 0; i < m_aBotArray.GetSize(); i++)
		m_aBotArray[i]->Stop(FALSE);
}

LPCONFIGDATA CBotManager::GetConfig()
{
	return &m_config;
}

LPCCONFIGDATA CBotManager::GetConfig() const
{
	return &m_config;
}

int CBotManager::Load(CIni& ini, LPCTSTR lpszPassword)
{
	// General
	m_config.bDB2x = ini.GetBool(_T("General"), _T("Demonbuddy 2x load"), TRUE);
	m_config.bNoMin = ini.GetBool(_T("General"), _T("Prevent minimize"), TRUE);
	m_config.bTripWire = TRUE; //ini.GetBool(_T("General"), _T("TripWire event"), TRUE); // currently forced on
	m_config.bReuseWnd = ini.GetBool(_T("General"), _T("Reuse processes"), TRUE);

	// Timeout
	m_config.nDiabloLaunch = ini.GetUInt(_T("Timeout"), _T("Game launch"), 60);
	m_config.nBNetLogin = ini.GetUInt(_T("Timeout"), _T("Game login"), 300);
	m_config.nJoin = ini.GetUInt(_T("Timeout"), _T("Game creation"), 300);
	m_config.nLeave = ini.GetUInt(_T("Timeout"), _T("Game leave"), 300);
	m_config.nDisconnect = ini.GetUInt(_T("Timeout"), _T("Game disconnect"), 30);
	m_config.nDiabloHung = ini.GetUInt(_T("Timeout"), _T("Game hung"), 60);
	m_config.nDemonbuddyHung = ini.GetUInt(_T("Timeout"), _T("Demonbuddy hung"), 60);

	// Bot data
	int nCount = 0;
	const int BOTS = ini.GetInt(_T("General"), _T("Bots"), 0);
	for (int i = 0; i < BOTS; i++)
	{
		CString sSection;
		sSection.Format(_T("Bot %d"), i + 1);
		CBot* pBot = new CBot(&m_config);
		if (pBot->Load(ini, sSection, lpszPassword))
		{
			nCount++;
			m_aBotArray.Add(pBot);
		}
		else
		{
			delete pBot;
			break;
		}
	}

	return nCount;
}

int CBotManager::Save(CIni& ini, LPCTSTR lpszPassword) const
{
	// General
	ini.WriteBool(_T("General"), _T("Demonbuddy 2x load"), m_config.bDB2x);
	ini.WriteBool(_T("General"), _T("Prevent minimize"), m_config.bNoMin);
	ini.WriteBool(_T("General"), _T("TripWire event"), TRUE); // currently forced on
	ini.WriteBool(_T("General"), _T("Reuse processes"), m_config.bReuseWnd);

	// Timeout
	ini.WriteUInt(_T("Timeout"), _T("Game launch"), m_config.nDiabloLaunch);
	ini.WriteUInt(_T("Timeout"), _T("Game login"), m_config.nBNetLogin);
	ini.WriteUInt(_T("Timeout"), _T("Game creation"), m_config.nJoin);
	ini.WriteUInt(_T("Timeout"), _T("Game leave"), m_config.nLeave);
	ini.WriteUInt(_T("Timeout"), _T("Game disconnect"), m_config.nDisconnect);
	ini.WriteUInt(_T("Timeout"), _T("Game hung"), m_config.nDiabloHung);
	ini.WriteUInt(_T("Timeout"), _T("Demonbuddy hung"), m_config.nDemonbuddyHung);

	// Bot data
	const int BOTS = m_aBotArray.GetSize();
	ini.WriteInt(_T("General"), _T("Bots"), BOTS);

	for (int i = 0; i < BOTS; i++)
	{
		CString sSection;
		sSection.Format(_T("Bot %d"), i + 1);
		m_aBotArray[i]->Save(ini, sSection, lpszPassword);
	}
	
	return BOTS;
}

void CBotManager::InitStateMap()
{
	m_stateMap.SetAt(BOT_MONITOR_TRIPWIRE, LANG_LOG_MONITOR_TRIPWIRE);
	m_stateMap.SetAt(BOT_MONITOR_DIABLO_CLOSED, LANG_LOG_MONITOR_DIABLO_CLOSED);
	m_stateMap.SetAt(BOT_MONITOR_DEMONBUDDY_CLOSED, LANG_LOG_MONITOR_DEMONBUDDY_CLOSED);
	m_stateMap.SetAt(BOT_MONITOR_OUT_OF_GAME, LANG_LOG_MONITOR_OUT_OF_GAME);	
	m_stateMap.SetAt(BOT_MONITOR_DIABLO_DISCONNECTED, LANG_LOG_MONITOR_DIABLO_DISCONNECTED);
	m_stateMap.SetAt(BOT_MONITOR_DIABLO_UNRESPONSIVE, LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE);
	m_stateMap.SetAt(BOT_MONITOR_DEMONBUDDY_UNRESPONSIVE, LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE);
	m_stateMap.SetAt(BOT_MONITOR_DIABLO_MINIMIZED, LANG_LOG_MONITOR_DIABLO_MINIMIZED);

	m_stateMap.SetAt(BOT_SET_HIDE_WINDOW_TRUE, LANG_LOG_SET_HIDE_WINDOW_TRUE);
	m_stateMap.SetAt(BOT_SET_HIDE_WINDOW_FALSE, LANG_LOG_SET_HIDE_WINDOW_FALSE);

	m_stateMap.SetAt(BOT_DIABLO_LOGIN_SCREEN, LANG_LOG_DIABLO_LOGIN_SCREEN);
	m_stateMap.SetAt(BOT_DIABLO_LOGIN_SUCCESS, LANG_LOG_DIABLO_LOGIN_SUCCESS);
	m_stateMap.SetAt(BOT_DIABLO_LOGIN_FAILED, LANG_LOG_DIABLO_LOGIN_FAILED);
	m_stateMap.SetAt(BOT_DIABLO_GAME_JOINED, LANG_LOG_DIABLO_GAME_JOINED);
	m_stateMap.SetAt(BOT_DIABLO_GAME_LEFT, LANG_LOG_DIABLO_GAME_LEFT);
	m_stateMap.SetAt(BOT_DIABLO_GAME_DISCONNECTED, LANG_LOG_DIABLO_GAME_DISCONNECTED);
	
	m_stateMap.SetAt(BOT_LAUNCH_ERROR_RETRY, LANG_LOG_LAUNCH_ERROR_RETRY);
	m_stateMap.SetAt(BOT_LAUNCH_PREPARE, LANG_LOG_LAUNCH_PREPARE);
	m_stateMap.SetAt(BOT_LAUNCH_CLEANUP, LANG_LOG_LAUNCH_CLEANUP);	
	m_stateMap.SetAt(BOT_LAUNCH_PREPARE_DIABLO, LANG_LOG_LAUNCH_PREPARE_DIABLO);
	m_stateMap.SetAt(BOT_LAUNCH_START_DIABLO, LANG_LOG_LAUNCH_START_DIABLO);
	m_stateMap.SetAt(BOT_LAUNCH_START_DIABLO_FAILED, LANG_LOG_LAUNCH_START_DIABLO_FAILED);
	m_stateMap.SetAt(BOT_LAUNCH_DIABLO_REUSED, LANG_LOG_LAUNCH_DIABLO_REUSED);
	m_stateMap.SetAt(BOT_LAUNCH_DIABLO_SUCCESS, LANG_LOG_LAUNCH_DIABLO_SUCCESS);
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_DIABLO, LANG_LOG_LAUNCH_WAIT_DIABLO);
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_BNET_LOGIN, LANG_LOG_LAUNCH_WAIT_BNET_LOGIN);
	m_stateMap.SetAt(BOT_LAUNCH_BNET_LOGIN_TIMEOUT, LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT);	
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_JOIN_GAME, LANG_LOG_LAUNCH_WAIT_JOIN_GAME);
	m_stateMap.SetAt(BOT_LAUNCH_JOIN_GAME_FAILED, LANG_LOG_LAUNCH_JOIN_GAME_FAILED);
	m_stateMap.SetAt(BOT_LAUNCH_PREPARE_DEMONBUDDY, LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_START_DEMONBUDDY1, LANG_LOG_LAUNCH_START_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_START_DEMONBUDDY2, LANG_LOG_LAUNCH_START_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_START_DEMONBUDDY_FAILED, LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED);
	m_stateMap.SetAt(BOT_LAUNCH_DEMONBUDDY_REUSED, LANG_LOG_LAUNCH_DEMONBUDDY_REUSED);
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_DEMONBUDDY1, LANG_LOG_LAUNCH_WAIT_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_DEMONBUDDY2, LANG_LOG_LAUNCH_WAIT_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_DEMONBUDDY_SUCCESS, LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS);
	m_stateMap.SetAt(BOT_LAUNCH_CLOSE_DEMONBUDDY_ERROR, LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR);
	m_stateMap.SetAt(BOT_LAUNCH_CLOSE_DEMONBUDDY, LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY);
	m_stateMap.SetAt(BOT_LAUNCH_CHECK_DEMONBUDDY_CLOSE, LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE);
	m_stateMap.SetAt(BOT_LAUNCH_DEMONBUDDY_CLOSED, LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED);
	m_stateMap.SetAt(BOT_LAUNCH_WAIT_GAME_STABLIZE, LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE);
	m_stateMap.SetAt(BOT_LAUNCH_SUCCESSFUL, LANG_LOG_LAUNCH_SUCCESSFUL);
	m_stateMap.SetAt(BOT_LAUNCH_HIDE_WINDOWS, LANG_LOG_LAUNCH_HIDE_PROCESSES);

	m_stateMap.SetAt(BOT_STATE_LAUNCH, LANG_LOG_STATE_LAUNCH);
	m_stateMap.SetAt(BOT_STATE_MONITOR, LANG_LOG_STATE_MONITOR);
	m_stateMap.SetAt(BOT_STATE_START, LANG_LOG_STATE_START);
	m_stateMap.SetAt(BOT_STATE_STOP, LANG_LOG_STATE_STOP);
	m_stateMap.SetAt(BOT_STATE_PAUSE, LANG_LOG_STATE_PAUSE);
	m_stateMap.SetAt(BOT_STATE_RESUME, LANG_LOG_STATE_RESUME);
}

BOOL CBotManager::GetStateText(int nStateID, CString &rText) const
{
	int nLangID = 0;
	if (!m_stateMap.Lookup(nStateID, nLangID))
		return FALSE;

	rText = _LANG(nLangID);
	return TRUE;	
}

int CBotManager::StateRequirePID(int nStateID)
{
	int nResult = REQ_PID_NONE;
	switch (nStateID)
	{
	case BOT_LAUNCH_DIABLO_REUSED:
	case BOT_LAUNCH_DIABLO_SUCCESS:
		nResult = REQ_PID_DIABLO;
		break;

	case BOT_LAUNCH_DEMONBUDDY_REUSED:
	case BOT_LAUNCH_DEMONBUDDY_SUCCESS:
		nResult = REQ_PID_DEMONBUDDY;
		break;

	default:
		break;
	}

	return nResult;
}

BOOL CBotManager::IsErrorState(int nState)
{
	BOOL bResult = FALSE;
	switch (nState)
	{
	case BOT_MONITOR_DIABLO_CLOSED:
	case BOT_MONITOR_DEMONBUDDY_CLOSED:
	case BOT_MONITOR_OUT_OF_GAME:
	case BOT_MONITOR_DIABLO_DISCONNECTED:
	case BOT_MONITOR_DIABLO_UNRESPONSIVE:
	case BOT_MONITOR_DEMONBUDDY_UNRESPONSIVE:
		bResult = TRUE;
		break;

	default:
		break;
	}

	return bResult;
}