// ConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog


CConfigDlg::CConfigDlg(int nOper, LPCONFIGDATA pData, CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
{
	m_pData = (pData);
	//{{AFX_DATA_INIT(CConfigDlg)
	m_bDB2x = pData->bDB2x;
	m_bNoMin = pData->bNoMin;
	m_bTripWire = TRUE; // Forced on at the moment
	m_nDemonbuddyHung = pData->nDemonbuddyHung;
	m_nDisconnect = pData->nDisconnect;
	m_nDiabloHung = pData->nDiabloHung;
	m_nJoin = pData->nJoin;
	m_nDiabloLaunch = pData->nDiabloLaunch;
	m_nLeave = pData->nLeave;
	m_bReuseWnd = pData->bReuseWnd;
	m_nLogin = pData->nBNetLogin;
	m_nOper = nOper;
	//}}AFX_DATA_INIT
}


void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfigDlg)
	DDX_Control(pDX, IDC_TIME_LOGIN, m_wndLogin);
	DDX_Control(pDX, IDC_TIME_LEAVE, m_wndLeave);
	DDX_Control(pDX, IDC_TIME_LAUNCHGAME, m_wndDiabloLaunch);
	DDX_Control(pDX, IDC_TIME_JOIN, m_wndJoin);
	DDX_Control(pDX, IDC_TIME_GAME_HUNG, m_wndDiabloHung);
	DDX_Control(pDX, IDC_TIME_DISCONNECT, m_wndDisconnect);
	DDX_Control(pDX, IDC_TIME_DB_HUNG, m_wndDemonbuddyHung);
	DDX_Check(pDX, IDC_DB_2X_LOGIN, m_bDB2x);
	DDX_Check(pDX, IDC_PREVENT_MIN, m_bNoMin);
	DDX_Check(pDX, IDC_TRIPWIRE, m_bTripWire);
	DDX_Text(pDX, IDC_TIME_DB_HUNG, m_nDemonbuddyHung);
	DDX_Text(pDX, IDC_TIME_DISCONNECT, m_nDisconnect);
	DDX_Text(pDX, IDC_TIME_GAME_HUNG, m_nDiabloHung);
	DDX_Text(pDX, IDC_TIME_JOIN, m_nJoin);
	DDX_Text(pDX, IDC_TIME_LAUNCHGAME, m_nDiabloLaunch);
	DDX_Text(pDX, IDC_TIME_LEAVE, m_nLeave);
	DDX_Check(pDX, IDC_REUSEWND, m_bReuseWnd);
	DDX_Text(pDX, IDC_TIME_LOGIN, m_nLogin);
	DDX_Radio(pDX, IDC_LISTOPER, m_nOper);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CConfigDlg)
	ON_BN_CLICKED(IDC_DEFAULT, OnDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg message handlers

void CConfigDlg::OnDefault() 
{
	// TODO: Add your control notification handler code here
	m_bNoMin = TRUE;
	m_bDB2x = TRUE;
	m_bTripWire = TRUE;
	m_bReuseWnd = TRUE;

	m_nDemonbuddyHung = 60;
	m_nDisconnect = 30;
	m_nDiabloHung = 60;
	m_nJoin = 300;
	m_nDiabloLaunch = 60;
	m_nLeave = 300;
	m_nLogin = 300;
	m_nOper = LIST_OPER_START_STOP;
	UpdateData(FALSE);
}

void CConfigDlg::OnOK() 
{
	// TODO: Add extra validation here
	if (!UpdateData(TRUE))
		return;

	m_pData->bDB2x = m_bDB2x;
	m_pData->bNoMin = m_bNoMin;
	m_pData->nDemonbuddyHung = m_nDemonbuddyHung;
	m_pData->nDisconnect = m_nDisconnect;
	m_pData->nDiabloHung = m_nDiabloHung;
	m_pData->nJoin = m_nJoin;
	m_pData->nDiabloLaunch = m_nDiabloLaunch;
	m_pData->nLeave = m_nLeave;
	m_pData->bTripWire = TRUE; // Forced on
	m_pData->bReuseWnd = m_bReuseWnd;
	m_pData->nBNetLogin = m_nLogin;

	EndDialog(IDOK);
}

BOOL CConfigDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	EnableToolTips(TRUE);
	m_wndTooltip.Create(this);
	m_wndTooltip.SetDelayTime(200);
	m_wndTooltip.SetDelayTime(TTDT_AUTOPOP, 3600000);
	m_wndTooltip.SetMaxTipWidth(400);

	SetWindowText(_LANG(LANG_CONFIG_TITLE));

	m_wndTooltip.AddTool(GetDlgItem(IDC_PREVENT_MIN), _LANG(LANG_CONFIG_TOOLTIP_PREVENT_MIN));
	m_wndTooltip.AddTool(GetDlgItem(IDC_DB_2X_LOGIN), _LANG(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN));
	m_wndTooltip.AddTool(GetDlgItem(IDC_REUSEWND), _LANG(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS));
	
	_WLANG(IDC_FRAME_DBLCLK_LIST, LANG_CONFIG_DBLCLK_TASK_LIST);
	_WLANG(IDC_LISTOPER, LANG_CONFIG_NO_OPERATION);
	_WLANG(IDC_OPER_EDIT, LANG_CONFIG_OPEN_TASK_EDITING_WINDOW);
	_WLANG(IDC_OPER_STARTSTOP, LANG_CONFIG_CYCLE_START_STOP);
	_WLANG(IDC_OPER_STARTDETACH, LANG_CONFIG_CYCLE_START_STOP_NO_KILL);
	_WLANG(IDC_OPER_STARTPAUSE, LANG_CONFIG_CYCLE_START_PAUSE_RESUME);
	_WLANG(IDC_FRAME_TASK_CONTROL, LANG_CONFIG_TASK_CONTROL);
	_WLANG(IDC_PREVENT_MIN, LANG_CONFIG_PREVENT_DIABLO_MINIMIZED);
	_WLANG(IDC_TRIPWIRE, LANG_CONFIG_MONITOR_TRIPWIRE_EVENT);
	_WLANG(IDC_DB_2X_LOGIN, LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY);
	_WLANG(IDC_REUSEWND, LANG_CONFIG_ATTACH_EXISTING_PROCESSES);
	_WLANG(IDC_FRAME_TIMEOUT, LANG_CONFIG_TIMEOUT);
	_WLANG(IDC_LBL_SCREEN, LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO);
	_WLANG(IDC_LBL_LOGIN, LANG_CONFIG_TIMEOUT_BNET_LOGIN);
	_WLANG(IDC_LBL_JOIN, LANG_CONFIG_TIMEOUT_CREATE_GAME);
	_WLANG(IDC_LBL_LEFT, LANG_CONFIG_TIMEOUT_OUT_OF_GAME);
	_WLANG(IDC_LBL_DISCONNECT, LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED);
	_WLANG(IDC_LBL_DIABLO_HUNG, LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE);
	_WLANG(IDC_LBL_DEMONBUDDY_HUNG, LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE);
	_WLANG(IDC_LBL_FORCE_RESTART, LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT);
	_WLANG(IDC_DEFAULT, LANG_CONFIG_RESTORE_DEFAULTS);

	_WLANG(IDC_LBL_S1, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S2, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S3, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S4, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S5, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S6, LANG_CONFIG_SECONDS);
	_WLANG(IDC_LBL_S7, LANG_CONFIG_SECONDS);

	_WLANG_OKCANCEL;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CConfigDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_wndTooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
