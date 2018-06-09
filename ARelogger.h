// ARelogger.h : main header file for the ARELOGGER application
//

#if !defined(AFX_ARELOGGER_H__155B1DEB_6FCF_4643_B639_B74A96F85989__INCLUDED_)
#define AFX_ARELOGGER_H__155B1DEB_6FCF_4643_B639_B74A96F85989__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Includes\WinAppEx.h"
#include "Version.h"
#include "Constants.h"
#include "Languages.h"
#include "BotManager.h"

/////////////////////////////////////////////////////////////////////////////
// AReloggerApp:
// See ARelogger.cpp for the implementation of this class
//

class AReloggerApp : public CWinAppEx
{
public:
	BOOL SetLanguage(int nIndex);
	AReloggerApp();
	CBotManager m_manager;
	CLanguage m_lang;
	BOOL m_bInitialized;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AReloggerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(AReloggerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BOOL AfxIsFileExists(LPCTSTR lpszPath);
CBotManager& AfxGetManager();
BOOL AfxSetLocale(LPCTSTR lpszLocale);
BOOL AfxSameLocale(LPCTSTR lpszLocale);

CString _LANG(int nID);
#define _WLANG(x, y) SetDlgItemText(x, _LANG(y));
#define _WLANG_OKCANCEL	SetDlgItemText(IDOK, _LANG(LANG_MENU_OK)); SetDlgItemText(IDCANCEL, _LANG(LANG_MENU_CANCEL));


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARELOGGER_H__155B1DEB_6FCF_4643_B639_B74A96F85989__INCLUDED_)
