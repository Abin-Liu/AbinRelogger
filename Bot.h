// Bot.h: interface for the CBot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOT_H__C4B1E100_8249_42EC_8F1E_6C8469D6E995__INCLUDED_)
#define AFX_BOT_H__C4B1E100_8249_42EC_8F1E_6C8469D6E995__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Includes\TickThread.h"
#include "Constants.h"
#include "Diablo3.h"
#include "Demonbuddy.h"

class CBot : public CTickThread
{
public:		

	CBot(LPCCONFIGDATA pConfig);
	virtual ~CBot();

	CString GetName() const;
	void SetName(LPCTSTR lpszName);

	CDiablo3& GetDiablo();
	const CDiablo3& GetDiablo() const;
	CDemonbuddy& GetDemonBuddy();
	const CDemonbuddy& GetDemonBuddy() const;

	BOOL Load(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword);
	void Save(CIni& ini, LPCTSTR lpszSection, LPCTSTR lpszPassword) const;

	DWORD Start(CWnd *pParentWnd);
	void Stop(BOOL bDetach);
	void PauseResume();
	BOOL IsLaunching() const;

	void SetHideGame(BOOL bHide);
	BOOL GetHideGame() const;

	void Debug();

protected:
	void ShowWindows(BOOL bShow);

	void LaunchDemonbuddy(int nNextState);
	void LaunchDiablo();
	void LaunchRetry();
	void WaitDemonbuddy(int nNextState, int nErrorState, DWORD dwStateAge);

	void OnTick(int nState, DWORD dwStateAge);

	void OnPause();
	void OnResume();
	BOOL OnMonitorTick();
	void OnStop();
	void OnStart();
	void NotifyGameStateChange(BOOL bChanged, int nState) const;
	void ReportState(int nStateID) const;
	void OnStateChange();

	DWORD m_dwExistingDiabloID;
	DWORD m_dwExistingDemonbuddyID;
	CString m_sName;
	CDiablo3 m_diablo;
	CDemonbuddy m_demonBuddy;
	LPCCONFIGDATA m_pConfig;
	BOOL m_bHideGame;
	BOOL m_bDetach;
	HWND m_hParentWnd;
	BOOL m_bDebug;
};

#endif // !defined(AFX_BOT_H__C4B1E100_8249_42EC_8F1E_6C8469D6E995__INCLUDED_)
