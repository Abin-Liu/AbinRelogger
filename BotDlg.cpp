// BotDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "BotDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBotDlg dialog


CBotDlg::CBotDlg(const CBot* pBot, CWnd* pParent /*=NULL*/)
	: CDialog(CBotDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBotDlg)
	m_bUseBNetAuth = FALSE;
	m_sBNetRestoreCode = _T("");
	m_sBNetSerial = _T("");
	m_sDemonBuddyKey = _T("");
	m_sUserAccount = _T("");
	m_sUserPassword = _T("");
	m_sName = _T("");
	//}}AFX_DATA_INIT

	if (pBot)
	{
		m_sName = pBot->GetName();
		pBot->GetDiablo().GetConfig(m_sDiabloPath);
		pBot->GetDemonBuddy().GetConfig(m_sDemonBuddyPath, m_sDemonBuddyKey, m_sProfilePath, m_sUserAccount, m_sUserPassword, m_bUseBNetAuth, m_sBNetSerial, m_sBNetRestoreCode);
	}
}


void CBotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBotDlg)
	DDX_Control(pDX, IDC_NAME, m_wndName);
	DDX_Control(pDX, IDC_USERPASSWORD, m_wndUserPassword);
	DDX_Control(pDX, IDC_USERACCOUNT, m_wndUserAccount);
	DDX_Control(pDX, IDC_DEMONBUDDYKEY, m_wndDemonBuddyKey);
	DDX_Control(pDX, IDC_USEBNETAUTH, m_wndUseBNetAuth);
	DDX_Control(pDX, IDC_BNETSERIAL, m_wndBNetSerial);
	DDX_Control(pDX, IDC_BNETRESTORECODE, m_wndBNetRestoreCode);
	DDX_Control(pDX, IDC_DEMONBUDDYPATH, m_wndDemonBuddyPath);
	DDX_Control(pDX, IDC_PROFILEPATH, m_wndProfilePath);
	DDX_Control(pDX, IDC_DIABLOPATH, m_wndDiabloPath);
	DDX_Check(pDX, IDC_USEBNETAUTH, m_bUseBNetAuth);
	DDX_Text(pDX, IDC_BNETRESTORECODE, m_sBNetRestoreCode);
	DDX_Text(pDX, IDC_BNETSERIAL, m_sBNetSerial);
	DDX_Text(pDX, IDC_DEMONBUDDYKEY, m_sDemonBuddyKey);
	DDX_Text(pDX, IDC_USERACCOUNT, m_sUserAccount);
	DDX_Text(pDX, IDC_USERPASSWORD, m_sUserPassword);
	DDX_Text(pDX, IDC_NAME, m_sName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBotDlg, CDialog)
	//{{AFX_MSG_MAP(CBotDlg)
	ON_BN_CLICKED(IDC_USEBNETAUTH, OnUsebnetauth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBotDlg message handlers

BOOL CBotDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_wndDiabloPath.ModifyButtonStyle(0, BC_CTL_FOLDERSONLY);
	m_wndDiabloPath.SetPathName(m_sDiabloPath);
	m_wndDemonBuddyPath.ModifyButtonStyle(0, BC_CTL_FOLDERSONLY);
	m_wndDemonBuddyPath.SetPathName(m_sDemonBuddyPath);
	m_wndProfilePath.SetPathName(m_sProfilePath);
	m_wndBNetRestoreCode.EnableWindow(m_bUseBNetAuth);
	m_wndBNetSerial.EnableWindow(m_bUseBNetAuth);

	SetWindowText(_LANG(LANG_TASK_TITLE));
	_WLANG(IDC_FRAME_TASK, LANG_TASK_FRAME_TASK);
	_WLANG(IDC_LBL_TASKNAME, LANG_TASK_TASK_NAME);
	_WLANG(IDC_LBL_DIABLOPATH, LANG_TASK_DIABLO_PATH);
	_WLANG(IDC_LBL_ACCPUNT, LANG_TASK_ACCOUNT);
	_WLANG(IDC_LBL_PASSWORD, LANG_TASK_PASSWORD);
	_WLANG(IDC_USEBNETAUTH, LANG_TASK_I_USE_BNET_AUTHENTICATOR);
	_WLANG(IDC_LBL_SERIAL, LANG_TASK_SERIAL);
	_WLANG(IDC_LBL_RESTORECODE, LANG_TASK_RESTORE_CODE);
	_WLANG(IDC_LBL_DEMONBUDDYPATH, LANG_TASK_DEMONBUDDY_PATH);
	_WLANG(IDC_AUTHCODE, LANG_TASK_AUTHORIZE_CODE);
	_WLANG(IDC_LBL_PROFILEPATH, LANG_TASK_PROFILE_PATH);
	_WLANG_OKCANCEL;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBotDlg::OnUsebnetauth() 
{
	// TODO: Add your control notification handler code here
	BOOL bChecked = m_wndUseBNetAuth.GetCheck();
	m_wndBNetRestoreCode.EnableWindow(bChecked);
	m_wndBNetSerial.EnableWindow(bChecked);
}

BOOL CBotDlg::VerifyEdit(CString &sText, CEditEx *pEdit, LPCTSTR lpszName)
{
	sText.TrimLeft();
	sText.TrimRight();
	if (!sText.IsEmpty())
		return TRUE;

	CString sMsg;
	sMsg.Format(_LANG(LANG_MSG_INPUT_CANNOT_BE_EMPTY), lpszName);
	MessageBox(sMsg, _LANG(LANG_MSG_INVALID_INPUT_TITLE), MB_ICONEXCLAMATION);

	pEdit->SetFocus();
	pEdit->Highlight();
	return FALSE;
}

BOOL CBotDlg::VerifyPath(CString &rPath, CBrowseCtrl *pCtl, LPCTSTR lpszFile, LPCTSTR lpszName)
{
	rPath = pCtl->GetPathName();
	CString sTest = rPath;	
	if (lpszFile)
	{
		sTest += _T('\\');
		sTest += lpszFile;
	}

	if (AfxIsFileExists(sTest))
		return TRUE;

	CString sMsg;
	sMsg.Format(_LANG(LANG_MSG_INPUT_INVALID_PATH), (LPCTSTR)rPath, lpszName);
	MessageBox(sMsg, _LANG(LANG_MSG_INVALID_INPUT_TITLE), MB_ICONEXCLAMATION);
	pCtl->SetFocus();
	return FALSE;
}

void CBotDlg::OnOK() 
{
	// TODO: Add extra validation here
	if (!UpdateData(TRUE))
		return;

	if (!VerifyEdit(m_sName, &m_wndName, _LANG(LANG_TASK_TASK_NAME)) 
		|| !VerifyEdit(m_sUserAccount, &m_wndUserAccount, _LANG(LANG_TASK_ACCOUNT))
		|| !VerifyEdit(m_sUserPassword, &m_wndUserPassword, _LANG(LANG_TASK_PASSWORD))
		|| !VerifyEdit(m_sDemonBuddyKey, &m_wndDemonBuddyKey, _LANG(LANG_TASK_AUTHORIZE_CODE)))
	{
		return;
	}

	if (m_bUseBNetAuth 
		&& (!VerifyEdit(m_sBNetSerial, &m_wndBNetSerial, _LANG(LANG_TASK_SERIAL))
		|| !VerifyEdit(m_sBNetRestoreCode, &m_wndBNetRestoreCode, _LANG(LANG_TASK_RESTORE_CODE))))
	{
		return;
	}

	if (!VerifyPath(m_sDiabloPath, &m_wndDiabloPath, _T("Diablo III.exe"), _T("Diablo III"))
		|| !VerifyPath(m_sDemonBuddyPath, &m_wndDemonBuddyPath, _T("Demonbuddy.exe"), _T("DemonBuddy"))
		|| !VerifyPath(m_sProfilePath, &m_wndProfilePath, NULL, _LANG(LANG_TASK_PROFILE_PATH)))
	{
		return;
	}

	//if (DemonbuddyExeConfused(m_sDemonBuddyPath, this))
	//	return;

	EndDialog(IDOK);
}
