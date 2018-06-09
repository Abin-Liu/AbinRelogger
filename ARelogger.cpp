// ARelogger.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ARelogger.h"
#include "AReloggerDlg.h"
#include "Includes\TextCrypto.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AReloggerApp

BEGIN_MESSAGE_MAP(AReloggerApp, CWinApp)
	//{{AFX_MSG_MAP(AReloggerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AReloggerApp construction

AReloggerApp::AReloggerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	TextCrypto::Randomize();
	m_bInitialized = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only AReloggerApp object

AReloggerApp theApp;

CBotManager& AfxGetManager()
{
	return theApp.m_manager;
}

/////////////////////////////////////////////////////////////////////////////
// AReloggerApp initialization

BOOL AfxIsFileExists(LPCTSTR lpszPath)
{
	return ::GetFileAttributes(lpszPath) != -1;
}

BOOL AfxSetLocale(LPCTSTR lpszLocale)
{
	return theApp.m_lang.SetLocale(lpszLocale);
}

BOOL AfxSameLocale(LPCTSTR lpszLocale)
{
	return theApp.m_lang.GetLocale().CompareNoCase(lpszLocale) == 0;
}

CString _LANG(int nID)
{
	return theApp.m_lang.GetText(nID);
}

BOOL AReloggerApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.	

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif	
	
	SetInstanceUniqueID(_T("{299B29D7-CB62-4949-8230-B643DB32DF80}"));
	if (!IsInstanceUnique())
	{
		RestorePrevInstanceMainWnd();
		return FALSE;
	}

	SetRegistryKey(_T("Abin"));
	CString sLocale = GetProfileString(_T(""), _T("Locale"));
	if (sLocale.IsEmpty())
		sLocale = CLanguage::GetDefaultLocale();

	m_lang.SetLocale(sLocale);

	AReloggerDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	m_bInitialized = TRUE;
	return FALSE;
}

int AReloggerApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if (m_bInitialized)
		WriteProfileString(_T(""), _T("Locale"), m_lang.GetLocale());
	return CWinApp::ExitInstance();
}