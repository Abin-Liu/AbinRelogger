// PwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "PwdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPwdDlg dialog


CPwdDlg::CPwdDlg(LPCTSTR lpszOldPwd, CWnd* pParent /*=NULL*/)
	: CDialog(CPwdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPwdDlg)
	m_sPassword = _T("");
	m_sLabel = _T("");
	//}}AFX_DATA_INIT
	m_bOldPwd = lpszOldPwd != NULL;
	m_sOldPwd = lpszOldPwd;
	m_sLabel = m_bOldPwd ? _LANG(LANG_PASSWORD_OLD_PASSWORD) : _LANG(LANG_PASSWORD_PASSWORD);
}


void CPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPwdDlg)
	DDX_Control(pDX, IDC_PWD, m_wndPassword);
	DDX_Text(pDX, IDC_PWD, m_sPassword);
	DDX_Text(pDX, IDC_LABEL, m_sLabel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPwdDlg, CDialog)
	//{{AFX_MSG_MAP(CPwdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPwdDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_bOldPwd && m_sPassword != m_sOldPwd)
	{
		MessageBox(_LANG(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT), _LANG(LANG_MSG_INVALID_INPUT_TITLE), MB_ICONEXCLAMATION);
		m_wndPassword.SetFocus();
		m_wndPassword.Highlight();
		return;
	}
	EndDialog(IDOK);
}

BOOL CPwdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(_LANG(LANG_PASSWORD_TITLE));
	_WLANG_OKCANCEL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
