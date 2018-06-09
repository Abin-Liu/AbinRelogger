// LoginFailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "LoginFailDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginFailDlg dialog


CLoginFailDlg::CLoginFailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginFailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginFailDlg)
	//}}AFX_DATA_INIT
}


void CLoginFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginFailDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginFailDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginFailDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDRETRY, OnRetry)
	ON_BN_CLICKED(IDIGNORE, OnIgnore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginFailDlg message handlers

void CLoginFailDlg::OnDestroy() 
{
	UpdateData(TRUE);
	CDialog::OnDestroy();	
}

void CLoginFailDlg::OnRetry() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDRETRY);
}

void CLoginFailDlg::OnIgnore() 
{
	// TODO: Add your control notification handler code here
	if (MessageBox(_LANG(LANG_MSG_DELERE_DATA_TEXT), _LANG(LANG_MSG_DELETE_DATA_TITLE), MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		EndDialog(IDIGNORE);
}

BOOL CLoginFailDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(_LANG(LANG_PASSWORD_INVALID_TITLE));
	_WLANG(IDC_TEXT, LANG_PASSWORD_INVALID_TEXT);
	_WLANG(IDRETRY, LANG_PASSWORD_RETRY);
	_WLANG(IDCANCEL, LANG_MENU_CANCEL);
	_WLANG(IDIGNORE, LANG_PASSWORD_CLEAN_EXIT);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
