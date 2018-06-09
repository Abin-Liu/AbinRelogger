// NewPwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "NewPwdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg dialog


CNewPwdDlg::CNewPwdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewPwdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewPwdDlg)
	m_sPwd = _T("");
	m_sPwd2 = _T("");
	//}}AFX_DATA_INIT
}


void CNewPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewPwdDlg)
	DDX_Control(pDX, IDC_PWD2, m_wndPwd2);
	DDX_Control(pDX, IDC_PWD, m_wndPwd);
	DDX_Text(pDX, IDC_PWD, m_sPwd);
	DDX_Text(pDX, IDC_PWD2, m_sPwd2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewPwdDlg, CDialog)
	//{{AFX_MSG_MAP(CNewPwdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg message handlers

void CNewPwdDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_sPwd != m_sPwd2)
	{
		MessageBox(_LANG(LANG_MSG_PASSWORD_REPEAT_MISMATCH), _LANG(LANG_MSG_INVALID_INPUT_TITLE), MB_ICONEXCLAMATION);
		m_wndPwd2.SetFocus();
		m_wndPwd2.Highlight();
		return;
	}

	EndDialog(IDOK);
}

BOOL CNewPwdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(_LANG(LANG_PASSWORD_CREATE_TITLE));
	_WLANG(IDC_NEW_PASSWORD, LANG_PASSWORD_CREATE_NEW_PASSWORD);
	_WLANG(IDC_REPEAT_PASSWORD, LANG_PASSWORD_CREATE_REPEAT_PASSWORD);
	_WLANG_OKCANCEL;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
