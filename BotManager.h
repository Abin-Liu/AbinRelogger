// BotManager.h: interface for the CBotManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOTMANAGER_H__B86CFDD7_0572_44A8_8F12_A0F772F2BB95__INCLUDED_)
#define AFX_BOTMANAGER_H__B86CFDD7_0572_44A8_8F12_A0F772F2BB95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Includes\ini.h"
#include "Bot.h"
#include <afxtempl.h>

class CBotManager  
{
public:	
	
	CBotManager();
	virtual ~CBotManager();

	int Load(CIni& ini, LPCTSTR lpszPassword);
	int Save(CIni& ini, LPCTSTR lpszPassword) const;
	LPCONFIGDATA GetConfig();
	LPCCONFIGDATA GetConfig() const;

	int GetCount() const;
	const CBot* GetByIndex(int nIndex) const;
	CBot* Add();
	void Delete(int nIndex);
	int GetAliveCount() const;
	int Find(const CBot* pBot) const;
	void HideAll();
	void ShowAll();
	void StopAll();

	BOOL GetStateText(int nStateID, CString& rText) const;
	static int StateRequirePID(int nStateID);
	static BOOL IsErrorState(int nState);

	const CBot* IsDiabloOwned(DWORD dwProcessID) const;
	const CBot* IsDemonbuddyOwned(DWORD dwProcessID) const;
	const CBot* GetDiabloConflict(const CBot *pBot) const;

protected:

	void InitStateMap();
	
	CONFIGDATA m_config;
	CArray<CBot*, CBot*> m_aBotArray;
	CMap<int, int, int, int> m_stateMap;
};

#endif // !defined(AFX_BOTMANAGER_H__B86CFDD7_0572_44A8_8F12_A0F772F2BB95__INCLUDED_)
