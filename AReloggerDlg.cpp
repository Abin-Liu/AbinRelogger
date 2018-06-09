// AReloggerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARelogger.h"
#include "AReloggerDlg.h"
#include "BotDlg.h"
#include "PwdDlg.h"
#include "NewPwdDlg.h"
#include "LoginFailDlg.h"
#include "Includes\Md5.h"
#include "Includes\PopupMenu.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg(CWnd* pParent);

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_sAboutVer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg(CWnd* pParent) : CDialog(CAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_sAboutVer = _T("");
	//}}AFX_DATA_INIT
	m_sAboutVer.Format(_T("ARelogger %s"), (LPCTSTR)AfxGetVersion());
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_ABOUTVER, m_sAboutVer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AReloggerDlg dialog

AReloggerDlg::AReloggerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AReloggerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AReloggerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ini.SetPathName(AfxGetAppEx()->GetAppDir() + _T("\\ARelogger.ini"));
	m_bLoginOK = FALSE;
	m_bExiting = TRUE;
	m_nListOper = LIST_OPER_NONE;

	m_log.SetLocale(_T("chs"));
}

void AReloggerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AReloggerDlg)
	DDX_Control(pDX, IDC_LOGSIZE, m_wndLogSize);
	DDX_Control(pDX, IDC_EDIT, m_wndEdit);
	DDX_Control(pDX, IDC_DELETE, m_wndDelete);
	DDX_Control(pDX, IDC_CLONE, m_wndClone);
	DDX_Control(pDX, IDC_LOG, m_wndLog);
	DDX_Control(pDX, IDC_BOTLIST, m_wndBotList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(AReloggerDlg, CDialog)
	//{{AFX_MSG_MAP(AReloggerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_COMMAND(ID_POPUP_EXIT, OnPopupExit)
	ON_COMMAND(ID_POPUP_SHOWWND, OnPopupShowwnd)
	ON_WM_TIMER()
	ON_COMMAND(ID_POPUP_ABOUT, OnPopupAbout)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_CLONE, OnClone)
	ON_UPDATE_COMMAND_UI(ID_TASK_START, OnUpdateTaskStart)
	ON_COMMAND(ID_TASK_START, OnTaskStart)
	ON_UPDATE_COMMAND_UI(ID_TASK_STOP, OnUpdateTaskStop)
	ON_COMMAND(ID_TASK_STOP, OnTaskStop)
	ON_UPDATE_COMMAND_UI(ID_TASK_PAUSERESUME, OnUpdateTaskPauseresume)
	ON_COMMAND(ID_TASK_PAUSERESUME, OnTaskPauseresume)
	ON_UPDATE_COMMAND_UI(ID_TASK_EDIT, OnUpdateTaskEdit)
	ON_COMMAND(ID_TASK_EDIT, OnTaskEdit)
	ON_UPDATE_COMMAND_UI(ID_TASK_DELETE, OnUpdateTaskDelete)
	ON_COMMAND(ID_TASK_DELETE, OnTaskDelete)
	ON_UPDATE_COMMAND_UI(ID_TASK_CLONE, OnUpdateTaskClone)
	ON_COMMAND(ID_TASK_CLONE, OnTaskClone)
	ON_COMMAND(ID_TASK_NEW, OnTaskNew)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_WM_INITMENUPOPUP()
	ON_COMMAND(ID_MENU_SETTINGS_PASSWORD, OnMenuSettingsPassword)
	ON_BN_CLICKED(IDC_OPENLOG, OnOpenlog)
	ON_BN_CLICKED(IDC_CLEARLOG, OnClearlog)
	ON_COMMAND(ID_MENU_SETTINGS, OnMenuSettings)
	ON_UPDATE_COMMAND_UI(ID_TASK_HIDEGAMES, OnUpdateTaskHidegames)
	ON_COMMAND(ID_TASK_HIDEGAMES, OnTaskHidegames)
	ON_BN_CLICKED(IDC_HIDEALL, OnHideall)
	ON_BN_CLICKED(IDC_SHOWALL, OnShowall)
	ON_BN_CLICKED(IDC_STOPALL, OnStopall)
	ON_UPDATE_COMMAND_UI(ID_TASK_DETACH, OnUpdateTaskDetach)
	ON_COMMAND(ID_TASK_DETACH, OnTaskDetach)
	ON_COMMAND(ID_TRAY_HIDEALL, OnTrayHideall)
	ON_COMMAND(ID_TRAY_SHOWALL, OnTrayShowall)
	ON_COMMAND(ID_TRAY_STOPALL, OnTrayStopall)
	ON_BN_CLICKED(IDC_DEBUG, OnDebug)
	ON_UPDATE_COMMAND_UI(ID_MENU_LANG_ENG, OnUpdateMenuLangEng)
	ON_COMMAND(ID_MENU_LANG_ENG, OnMenuLangEng)
	ON_UPDATE_COMMAND_UI(ID_MENU_LANG_CHS, OnUpdateMenuLangChs)
	ON_COMMAND(ID_MENU_LANG_CHS, OnMenuLangChs)
	ON_UPDATE_COMMAND_UI(ID_MENU_LANG_CHT, OnUpdateMenuLangCht)
	ON_COMMAND(ID_MENU_LANG_CHT, OnMenuLangCht)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_REQ_PASSWORD, OnReqPassword)
	ON_MESSAGE(WM_TRAY_NOTIFY, OnTrayNotify)
	ON_MESSAGE(WM_BOT_STATE, OnBotState)
	ON_MESSAGE(WM_DIABLO_CONFLICT, OnDiabloConflict)
	ON_MESSAGE(WM_LANGUAGE_CHANGED, OnLanguageChanged)
	ON_LVEX_MESSAGE(OnListNotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AReloggerDlg message handlers

BOOL AReloggerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetWindowText(CString(_T("ARelogger ")) + AfxGetVersion(TRUE));
	
	m_wndLog.SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	m_wndLog.SetBackColor(::GetSysColor(COLOR_WINDOW));

	m_log.Initialize(AfxGetAppEx()->GetAppDir() + _T("\\ARelogger.txt"), FALSE, &m_wndLog, &m_wndLogSize);

	m_wndMainMenu.LoadMenu(IDR_MENU_MAIN);
	m_wndMainMenu.LoadToolbar(IDR_TOOLBAR1);
	SetMenu(&m_wndMainMenu);

	m_wndTrayMenu.LoadMenu(IDR_MENU_TRAY);
	m_wndTrayMenu.LoadToolbar(IDR_TOOLBAR1);

	m_wndBotList.AddColumn(NULL, 0, LVEX_FMT_HIDDEN);
	m_wndBotList.AddColumn(_LANG(LANG_MAIN_LIST_COLUMN_NAME), 180);
	m_wndBotList.AddColumn(_LANG(LANG_MAIN_LIST_COLUMN_AGE), 95, LVEX_FMT_SECONDS);
	m_wndBotList.AddColumn(_T("Diablo III"), 95, LVEX_FMT_INT);
	m_wndBotList.AddColumn(_T("Demonbuddy"), 85, LVEX_FMT_INT);
	m_wndBotList.AddColumn(_LANG(LANG_MAIN_LIST_COLUMN_PROFILE), 190);	

	m_wndBotList.SetImageList(IDB_BOT_IMG, 20);
	m_wndTray.Create(this, WM_TRAY_NOTIFY, _T("ARelogger"), m_hIcon, 0);

#ifdef _DEBUG
	GetDlgItem(IDC_DEBUG)->ShowWindow(SW_SHOW);
#endif

	UpdateLanguage(FALSE);

	m_log.Append(_LANG(LANG_LOG_APP_STARTED));
	PostMessage(WM_REQ_PASSWORD);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void AReloggerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout(this);
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void AReloggerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR AReloggerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void AReloggerDlg::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
{
	CDialog::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);

	if (pPopupMenu && (pPopupMenu == m_wndMainMenu.GetSubMenu(1) || pPopupMenu == m_wndMainMenu.GetSubMenu(2)))
		CmdRouteMenu(this, pPopupMenu);
}

BOOL AReloggerDlg::AskForNewPwd()
{
	MessageBox(_LANG(LANG_MSG_CREATE_PASSWORD_TEXT), _LANG(LANG_MSG_CREATE_PASSWORD_TITLE));
	CNewPwdDlg dlg(this);
	if (dlg.DoModal() != IDOK)
		return FALSE;

	m_sPassword = dlg.m_sPwd;
	m_log.Append(_LANG(LANG_LOG_PASSWORD_CREATED));
	return TRUE;
}

BOOL AReloggerDlg::Login(LPCTSTR lpszChecksum)
{
	TCHAR szMd5[33] = _T("");

	while (TRUE)
	{
		CPwdDlg dlg(NULL, this);
		if (dlg.DoModal() != IDOK)
			break;
	
		MD5::CalcText(dlg.m_sPassword, szMd5);
		if (_tcsicmp(szMd5, lpszChecksum) == 0)
		{
			m_log.Append(_LANG(LANG_LOG_LOGIN_SUCCESSFUL));
			m_sPassword = dlg.m_sPassword;
			Load();
			return TRUE;
		}

		m_log.Append(_LANG(LANG_LOG_INVALID_PASSWORD));	
		CLoginFailDlg failDlg(this);
		int nResult = failDlg.DoModal();
		if (nResult == IDIGNORE)
		{
			m_log.Append(_LANG(LANG_LOG_DATA_DELETED));
			::DeleteFile(m_ini.GetPathName());
			break;
		}

		if (nResult != IDRETRY)
			break;
	}	
	
	return FALSE;
}

LRESULT AReloggerDlg::OnReqPassword(WPARAM wParam, LPARAM lParam)
{
	m_bLoginOK = FALSE;
	CString sChecksum = m_ini.GetString(_T("General"), _T("MD5"));
	if (sChecksum.IsEmpty())
	{
		m_log.Append(_LANG(LANG_LOG_DATA_NOT_FOUND));
		m_bLoginOK = AskForNewPwd();
	}
	else
	{
		m_bLoginOK = Login(sChecksum);	
	}

	if (m_bLoginOK)
	{
		m_bExiting = FALSE;		
		m_log.Append(NULL);
		SetTimer(ID_TMR_TICK, 1000, NULL);
	}
	else
	{
		PostMessage(WM_CLOSE);
	}

	return 0;
}

void AReloggerDlg::OnDestroy() 
{	
	KillTimer(ID_TMR_TICK);	

	if (m_bLoginOK)
	{
		AfxGetManager().StopAll();
		Save();
	}
	
	m_log.Append(_LANG(LANG_LOG_APP_EXIT));
	m_log.Append(_T("-------------------------------------------"), NULL, FALSE);
	m_log.Append(NULL);
	CDialog::OnDestroy();	
}

void AReloggerDlg::Load()
{
	m_nListOper = m_ini.GetInt(_T("General"), _T("Dbl-click oper"), LIST_OPER_START_STOP);
	int nCount = AfxGetManager().Load(m_ini, m_sPassword);

	for (int i = 0; i < nCount; i++)
	{
		const CBot* pBot = AfxGetManager().GetByIndex(i);
		m_wndBotList.AddItem(NULL, (DWORD)pBot);
		UpdateBotInfo(UPDATE_BOT_SETTINGS, pBot, i);
	}

	CString sLog;
	sLog.Format(_LANG(LANG_LOG_DATA_LOADED), nCount);
	m_log.Append(sLog);
}

void AReloggerDlg::Save()
{
	::DeleteFile(m_ini.GetPathName());

	// Write checksum	
	TCHAR szMd5[33] = _T("");
	MD5::CalcText(m_sPassword, szMd5);

	m_ini.WriteString(_T("General"), _T("MD5"), szMd5);	
	m_ini.WriteInt(_T("General"), _T("Dbl-click oper"), m_nListOper);

	int nCount = AfxGetManager().Save(m_ini, m_sPassword);
	
	CString sLog;
	sLog.Format(_LANG(LANG_LOG_DATA_SAVED), nCount);
	m_log.Append(sLog);
}

void AReloggerDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if (m_bExiting)
		EndDialog(IDCANCEL);
	else
		ShowWindow(SW_HIDE);
}

void AReloggerDlg::OnPopupShowwnd() 
{
	// TODO: Add your command handler code here
	if (IsIconic())
		ShowWindow(SW_RESTORE);
	ShowWindow(SW_SHOW);
	SetForegroundWindow();
}

LRESULT AReloggerDlg::OnTrayNotify(WPARAM wParam, LPARAM lParam)
{
	if (lParam == WM_RBUTTONUP)
	{
		SetForegroundWindow();
		if (IsWindowEnabled())
			PopupMenu(m_wndTrayMenu.GetSubMenu(0), this);
	}
	else if (lParam == WM_LBUTTONDBLCLK)
	{		
		OnPopupShowwnd();
	}
	
	return 0;
}

void AReloggerDlg::OnPopupExit() 
{
	// TODO: Add your command handler code here
	OnExit();
}

void AReloggerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == ID_TMR_TICK)
		OnTick();

	CDialog::OnTimer(nIDEvent);
}

void AReloggerDlg::OnPopupAbout() 
{
	// TODO: Add your command handler code here
	OnPopupShowwnd();
	CAboutDlg dlg(this);
	dlg.DoModal();
}

void AReloggerDlg::OnTick()
{
	static int nTckCount = 0;
	nTckCount++;

	if (nTckCount > 6)
	{
		nTckCount = 0;
		DWORD dwProcessID = CProcess::FindProcessByName(_T("BlizzardError.exe"));		
		if (dwProcessID)
		{
			CProcess::KillProcess(dwProcessID);
			m_log.Append(_LANG(LANG_LOG_KILLED_BLIZZARD_ERROR));
		}
	}

	for (int i = 0; i < AfxGetManager().GetCount(); i++)
	{
		const CBot* pBot = AfxGetManager().GetByIndex(i);
		if (pBot->IsAlive())
			UpdateBotInfo(UPDATE_BOT_AGE | UPDATE_BOT_PROCESS, pBot, i);
	}	
}

LRESULT AReloggerDlg::OnBotState(WPARAM wParam, LPARAM lParam)
{
	CBot* pBot = (CBot*)lParam;
	if (!pBot)
		return 0;	

	CString sText;
	if (AfxGetManager().GetStateText(wParam, sText))
	{
		int nResult = CBotManager::StateRequirePID(wParam);
		if (nResult)
		{
			CString sFmt(sText);
			if (nResult == REQ_PID_DIABLO)
				sText.Format(sFmt, pBot->GetDiablo().GetID());
			else
				sText.Format(sFmt, pBot->GetDemonBuddy().GetID());
		}		
	
		m_log.Append(sText, pBot ? pBot->GetName() : (LPCTSTR)NULL);

		if (CBotManager::IsErrorState(wParam))
			m_wndTray.ShowBalloon(sText, CString(_T("ARelogger - ")) + pBot->GetName());
	}

	DWORD dwStates = UPDATE_BOT_RUN;
	if (wParam == BOT_STATE_STOP)
		dwStates |= UPDATE_BOT_PROCESS;

	UpdateBotInfo(dwStates, pBot);
	/*
	
	if (wParam == BOT_SET_HIDE_WINDOW_TRUE || wParam == BOT_SET_HIDE_WINDOW_FALSE)
		dwStates |= UPDATE_BOT_PROCESS;

		UpdateBotInfo(UPDATE_BOT_RUN | UPDATE_BOT_PROCESS, pBot);
	else
		UpdateBotInfo(UPDATE_BOT_RUN, pBot);

BOT_SET_HIDE_WINDOW_TRUE
*/

	return 0;
}

void AReloggerDlg::UpdateButtons()
{
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	BOOL bRunning = pBot ? pBot->IsAlive() : FALSE;
	m_wndEdit.EnableWindow(pBot && !bRunning);
	m_wndDelete.EnableWindow(pBot && !bRunning);
	m_wndClone.EnableWindow(pBot != NULL);
}

LRESULT AReloggerDlg::OnListNotify(WPARAM wParam, LPARAM lParam)
{
	LPLVEXNOTIFY lpvn = (LPLVEXNOTIFY)wParam;
	ASSERT(lpvn);

	switch (lpvn->nNotifyType)
	{
	case LVEX_WM_SELCHANGE:
		UpdateButtons();
		break;
		
	case LVEX_WM_DBLCLICK:
		OnListOper();
		break;

	case LVEX_WM_RCLICK:
		PopupMenu(m_wndMainMenu.GetSubMenu(1), this);
		break;	

	default:
		break;
	}

	return (LRESULT)0;
}

void AReloggerDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	CBotDlg dlg(NULL, this);
	if (dlg.DoModal() != IDOK)
		return;

	CBot* pBot = AfxGetManager().Add();
	pBot->SetName(dlg.m_sName);
	pBot->GetDiablo().SetConfig(dlg.m_sDiabloPath);
	pBot->GetDemonBuddy().SetConfig(dlg.m_sDemonBuddyPath, dlg.m_sDemonBuddyKey, dlg.m_sProfilePath, dlg.m_sUserAccount, dlg.m_sUserPassword, dlg.m_bUseBNetAuth, dlg.m_sBNetSerial, dlg.m_sBNetRestoreCode);

	int nIndex = m_wndBotList.AddItem(NULL, (DWORD)pBot);
	UpdateBotInfo(UPDATE_BOT_SETTINGS, pBot, nIndex);
	m_wndBotList.SelectItem(nIndex);
	m_log.Append(_LANG(LANG_LOG_TASK_CREATED));
}

void AReloggerDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL)
		return;

	CheckBotEditable(pBot);	

	CBotDlg dlg(pBot, this);
	if (dlg.DoModal() != IDOK)
		return;

	pBot->SetName(dlg.m_sName);
	pBot->GetDiablo().SetConfig(dlg.m_sDiabloPath);
	pBot->GetDemonBuddy().SetConfig(dlg.m_sDemonBuddyPath, dlg.m_sDemonBuddyKey, dlg.m_sProfilePath, dlg.m_sUserAccount, dlg.m_sUserPassword, dlg.m_bUseBNetAuth, dlg.m_sBNetSerial, dlg.m_sBNetRestoreCode);

	UpdateBotInfo(UPDATE_BOT_SETTINGS, pBot, m_wndBotList.GetSelection());
	m_log.Append(_LANG(LANG_LOG_TASK_MODIFIED));
}

void AReloggerDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL)
		return;

	CheckBotEditable(pBot);	

	CString sMsg;
	sMsg.Format(_LANG(LANG_MSG_DELETE_TASK_TEXT), (LPCTSTR)pBot->GetName());
	if (MessageBox(sMsg, _LANG(LANG_MSG_DELETE_TASK_TITLE), MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON2) != IDOK)
		return;	

	int nIndex = m_wndBotList.GetSelection();
	m_wndBotList.DeleteItem(nIndex);
	m_wndBotList.SelectItem(nIndex);
	
	AfxGetManager().Delete(nIndex);
	
	m_log.Append(_LANG(LANG_LOG_TASK_DELETED));
}

void AReloggerDlg::OnClone() 
{
	// TODO: Add your control notification handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL)
		return;

	CBotDlg dlg(pBot, this);
	if (dlg.DoModal() != IDOK)
		return;

	CBot* pNewBot = AfxGetManager().Add();
	pNewBot->SetName(dlg.m_sName);
	pNewBot->GetDiablo().SetConfig(dlg.m_sDiabloPath);
	pNewBot->GetDemonBuddy().SetConfig(dlg.m_sDemonBuddyPath, dlg.m_sDemonBuddyKey, dlg.m_sProfilePath, dlg.m_sUserAccount, dlg.m_sUserPassword, dlg.m_bUseBNetAuth, dlg.m_sBNetSerial, dlg.m_sBNetRestoreCode);

	int nIndex = m_wndBotList.AddItem(NULL, (DWORD)pNewBot);
	UpdateBotInfo(UPDATE_BOT_SETTINGS, pNewBot, nIndex);
	m_wndBotList.SelectItem(nIndex);
	m_log.Append(_LANG(LANG_LOG_TASK_CREATED));
}

void AReloggerDlg::OnUpdateTaskStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot && !pBot->IsAlive());
}

void AReloggerDlg::OnTaskStart() 
{
	// TODO: Add your command handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL || pBot->IsAlive())
		return;

	pBot->Start(this);
}

void AReloggerDlg::OnUpdateTaskStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot && pBot->IsAlive());
}

void AReloggerDlg::OnTaskStop() 
{
	// TODO: Add your command handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL || !pBot->IsAlive())
		return;

	pBot->Stop(FALSE);
}

void AReloggerDlg::OnUpdateTaskPauseresume(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot && pBot->IsAlive());
}

void AReloggerDlg::OnTaskPauseresume() 
{
	// TODO: Add your command handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL || !pBot->IsAlive())
		return;

	pBot->PauseResume();
}

void AReloggerDlg::OnTaskNew() 
{
	// TODO: Add your command handler code here
	OnNew();
}

void AReloggerDlg::OnUpdateTaskEdit(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot && !pBot->IsAlive());
}

void AReloggerDlg::OnTaskEdit() 
{
	// TODO: Add your command handler code here
	OnEdit();
}

void AReloggerDlg::OnUpdateTaskDelete(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot && !pBot->IsAlive());
}

void AReloggerDlg::OnTaskDelete() 
{
	// TODO: Add your command handler code here
	OnDelete();
}

void AReloggerDlg::OnUpdateTaskClone(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot != NULL);
}

void AReloggerDlg::OnTaskClone() 
{
	// TODO: Add your command handler code here
	OnClone();
}

void AReloggerDlg::OnMenuSettings() 
{
	// TODO: Add your command handler code here
	CConfigDlg dlg(m_nListOper, AfxGetManager().GetConfig(), this);
	if (dlg.DoModal() == IDOK)
		m_nListOper = dlg.m_nOper;
}

void AReloggerDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	int nRunning = AfxGetManager().GetAliveCount();	
	if (nRunning)
	{
		CString sMsg;
		sMsg.Format(_LANG(LANG_MSG_STOP_ALL_TEXT), nRunning);
		if (MessageBox(sMsg, _LANG(LANG_MSG_EXIT_APP_TITLE), MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON2) != IDOK)
			return;
	}

	m_bExiting = TRUE;
	EndDialog(IDCANCEL);
}

void AReloggerDlg::OnMenuSettingsPassword() 
{
	// TODO: Add your command handler code here
	CPwdDlg dlg(m_sPassword, this);
	if (dlg.DoModal() != IDOK)
		return;

	CNewPwdDlg dlg2(this);
	if (dlg2.DoModal() != IDOK)
		return;

	m_sPassword = dlg2.m_sPwd;
	m_log.Append(_LANG(LANG_LOG_PASSWORD_CHANGED));
}

void AReloggerDlg::OnOpenlog() 
{
	// TODO: Add your control notification handler code here
	m_log.OpenFile();
}

void AReloggerDlg::OnClearlog() 
{
	// TODO: Add your control notification handler code here
	if (MessageBox(_LANG(LANG_MSG_CLEAN_LOG_TEXT), _LANG(LANG_MSG_CLEAN_LOG_TITLE), MB_ICONQUESTION | MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		m_log.Truncate();
}


void AReloggerDlg::OnUpdateTaskHidegames(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	pCmdUI->Enable(pBot != NULL);
	pCmdUI->SetCheck(pBot && pBot->GetHideGame());
}

void AReloggerDlg::OnTaskHidegames() 
{
	// TODO: Add your command handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot)
		pBot->SetHideGame(!pBot->GetHideGame());
}

void AReloggerDlg::OnHideall() 
{
	// TODO: Add your control notification handler code here
	AfxGetManager().HideAll();
}

void AReloggerDlg::OnShowall() 
{
	// TODO: Add your control notification handler code here
	AfxGetManager().ShowAll();
}

void AReloggerDlg::OnStopall() 
{
	// TODO: Add your control notification handler code here
	int nRunning = AfxGetManager().GetAliveCount();
	if (nRunning)
	{
		CString sMsg;
		sMsg.Format(_LANG(LANG_MSG_STOP_ALL_TEXT), nRunning);
		if (MessageBox(sMsg, _LANG(LANG_MSG_STOP_ALL_TITLE), MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON2) != IDOK)
			return;
	}

	AfxGetManager().StopAll();
}

void AReloggerDlg::OnUpdateTaskDetach(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	OnUpdateTaskStop(pCmdUI);
}

void AReloggerDlg::OnTaskDetach() 
{
	// TODO: Add your command handler code here
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL || !pBot->IsAlive())
		return;

	pBot->Stop(TRUE);
}

void AReloggerDlg::OnTrayHideall() 
{
	// TODO: Add your command handler code here
	OnHideall();
}

void AReloggerDlg::OnTrayShowall() 
{
	// TODO: Add your command handler code here
	OnShowall();
}

void AReloggerDlg::OnTrayStopall() 
{
	// TODO: Add your command handler code here
	OnStopall();
}

void AReloggerDlg::UpdateBotInfo(DWORD dwFlags, const CBot* pBot, int nIndex)
{
	ASSERT(pBot);

	if (nIndex < 0)
		nIndex = m_wndBotList.FindItemByData((DWORD)pBot);

	if (nIndex == -1)
		return;

	if (dwFlags & UPDATE_BOT_SETTINGS)
	{
		m_wndBotList.SetFieldText(nIndex, LIST_FLD_NAME, pBot->GetName());
		m_wndBotList.SetFieldText(nIndex, LIST_FLD_PROFILE, pBot->GetDemonBuddy().GetProfileName());
	}

	if (dwFlags & UPDATE_BOT_RUN)
	{
		if (pBot->IsAlive())
		{
			if (pBot->IsPaused())
				m_wndBotList.SetFieldImage(nIndex, LIST_FLD_AGE, IMG_PAUSED);
			else if (pBot->IsLaunching())
				m_wndBotList.SetFieldImage(nIndex, LIST_FLD_AGE, IMG_LAUNCHING);
			else
				m_wndBotList.SetFieldImage(nIndex, LIST_FLD_AGE, IMG_RUNNING);
		}
		else
		{
			m_wndBotList.SetFieldImage(nIndex, LIST_FLD_AGE, IMG_NONE);
		}

		m_wndBotList.SetFieldImage(nIndex, LIST_FLD_DIABLO, pBot->GetHideGame() ? IMG_HIDEGAME : IMG_NONE);
	}

	if (dwFlags & UPDATE_BOT_AGE)
		m_wndBotList.SetFieldSeconds(nIndex, LIST_FLD_AGE, pBot->GetAge() / 1000, FALSE, TRUE);

	if (dwFlags & UPDATE_BOT_PROCESS)
	{
		m_wndBotList.SetFieldLong(nIndex, LIST_FLD_DIABLO, pBot->GetDiablo().GetID(), TRUE);
		m_wndBotList.SetFieldLong(nIndex, LIST_FLD_DEMONBUDDY, pBot->GetDemonBuddy().GetID(), TRUE);
	}	
}

void AReloggerDlg::OnDebug()
{
	// TODO: Add your control notification handler code here
	/*
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL)
		return;	

	pBot->GetDiablo().Terminate(FALSE);
	*/

	/*

	HWND hWnd = ::FindWindow(NULL, "Demonbuddy");
	if (hWnd)
	{
		//::ShowWindow(hWnd, SW_MINIMIZE);
		::PostMessage(hWnd, WM_CLOSE, 0, 0);
		MessageBox("post");
	}
	*/
}

void AReloggerDlg::OnListOper()
{
	CBot* pBot = (CBot*)m_wndBotList.GetSelectedData();
	if (pBot == NULL)
		return;

	switch (m_nListOper)
	{
	case LIST_OPER_EDIT:
		OnEdit();
		break;

	case LIST_OPER_START_STOP:
		if (pBot->IsAlive())
			pBot->Stop(FALSE);
		else
			pBot->Start(this);
		break;

	case LIST_OPER_START_DETACH:
		if (pBot->IsAlive())
			pBot->Stop(TRUE);
		else
			pBot->Start(this);
		break;

	case LIST_OPER_START_PAUSE_RESUME:
		if (pBot->IsAlive())
			pBot->PauseResume();
		else
			pBot->Start(this);
		break;

	default:
		break;
	}
}

BOOL AReloggerDlg::CheckBotEditable(const CBot *pBot)
{
	if (!pBot->IsAlive())
		return TRUE;

	CString sMsg;
	sMsg.Format(_LANG(LANG_MSG_TASK_RUNNING_TEXT), (LPCTSTR)pBot->GetName());
	MessageBox(sMsg, _LANG(LANG_MSG_TASK_RUNNING_TITLE));
	return FALSE;
}

LRESULT AReloggerDlg::OnDiabloConflict(WPARAM wParam, LPARAM lParam)
{
	const CBot* pBot = (const CBot*)wParam;
	const CBot* pBotRunning = (const CBot*)lParam;
	ASSERT(pBot);
	ASSERT(pBotRunning);

	CString sMsg;
	sMsg.Format(_LANG(LANG_MSG_TASK_CONFLICT_TEXT), (LPCTSTR)pBot->GetName(), (LPCTSTR)pBot->GetDiablo().GetPathName(), (LPCTSTR)pBotRunning->GetName());
	MessageBox(sMsg, _LANG(LANG_MSG_TASK_CONFLICT_TITLE), MB_ICONEXCLAMATION);
	return 0;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(_LANG(LANG_ABOUT_TITLE));
	_WLANG(IDC_COPYRIGHT, LANG_ABOUT_COPYRIGHT);
	_WLANG(IDOK, LANG_MENU_OK);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT AReloggerDlg::OnLanguageChanged(WPARAM wParam, LPARAM lParam)
{
	UpdateLanguage(TRUE);
	return 0;
}

void AReloggerDlg::UpdateLanguage(BOOL bRedraw)
{
	m_wndBotList.SetColumnText(LIST_FLD_NAME, _LANG(LANG_MAIN_LIST_COLUMN_NAME));
	m_wndBotList.SetColumnText(LIST_FLD_AGE, _LANG(LANG_MAIN_LIST_COLUMN_AGE));
	m_wndBotList.SetColumnText(LIST_FLD_PROFILE, _LANG(LANG_MAIN_LIST_COLUMN_PROFILE));

	SetDlgItemText(IDC_FRAME_OPER, _LANG(LANG_MAIN_FRAME_BATCH_OPER));
	SetDlgItemText(IDC_HIDEALL, _LANG(LANG_MENU_HIDE_ALL));
	SetDlgItemText(IDC_SHOWALL, _LANG(LANG_MENU_SHOW_ALL));
	SetDlgItemText(IDC_STOPALL, _LANG(LANG_MENU_STOP_ALL));

	SetDlgItemText(IDC_FRAME_TASKS, _LANG(LANG_MAIN_FRAME_TASK_DATA));
	SetDlgItemText(IDC_NEW, _LANG(LANG_MENU_NEW));
	SetDlgItemText(IDC_EDIT, _LANG(LANG_MENU_EDIT));
	SetDlgItemText(IDC_CLONE, _LANG(LANG_MENU_CLONE));
	SetDlgItemText(IDC_DELETE, _LANG(LANG_MENU_DELETE));

	SetDlgItemText(IDC_OPENLOG, _LANG(LANG_MAIN_OPEN_LOG));
	SetDlgItemText(IDC_CLEARLOG, _LANG(LANG_MAIN_CLEAN_LOG));
	SetDlgItemText(IDC_EXIT, _LANG(LANG_MENU_EXIT));

	m_log.UpdateSizeLabel();
	
	m_wndMainMenu.ModifyMenu(0, MF_BYPOSITION, 0, _LANG(LANG_MENU_FILE));
	m_wndMainMenu.ModifyMenu(1, MF_BYPOSITION, 0, _LANG(LANG_MENU_TASK));
	m_wndMainMenu.ModifyMenu(2, MF_BYPOSITION, 0, _LANG(LANG_MENU_OPTIONS));
	m_wndMainMenu.ModifyMenu(3, MF_BYPOSITION, 0, _LANG(LANG_MENU_HELP));

	
	BCMenu* pSubMenu = (BCMenu*)m_wndMainMenu.GetSubMenu(0);
	pSubMenu->SetMenuText(0, _LANG(LANG_MENU_EXIT));

	pSubMenu = (BCMenu*)m_wndMainMenu.GetSubMenu(1);
	pSubMenu->SetMenuText(0, _LANG(LANG_MENU_START));
	pSubMenu->SetMenuText(1, _LANG(LANG_MENU_STOP));
	pSubMenu->SetMenuText(2, _LANG(LANG_MENU_STOP_DETACH));
	pSubMenu->SetMenuText(3, _LANG(LANG_MENU_PAUSE_RESUME));
	pSubMenu->SetMenuText(5, _LANG(LANG_MENU_HIDE_GAME));
	pSubMenu->SetMenuText(7, _LANG(LANG_MENU_NEW));
	pSubMenu->SetMenuText(8, _LANG(LANG_MENU_EDIT));
	pSubMenu->SetMenuText(9, _LANG(LANG_MENU_CLONE));
	pSubMenu->SetMenuText(10, _LANG(LANG_MENU_DELETE));

	pSubMenu = (BCMenu*)m_wndMainMenu.GetSubMenu(2);
	pSubMenu->SetMenuText(0, _LANG(LANG_MENU_SETTINGS));
	pSubMenu->SetMenuText(1, _LANG(LANG_MENU_CHANGE_PASSWORD));
	pSubMenu->SetMenuText(3, _LANG(LANG_MENU_LANGUAGES));

	pSubMenu = (BCMenu*)m_wndMainMenu.GetSubMenu(3);
	pSubMenu->SetMenuText(0, _LANG(LANG_MENU_ABOUT));

	pSubMenu = (BCMenu*)m_wndTrayMenu.GetSubMenu(0);
	pSubMenu->SetMenuText(0, _LANG(LANG_MENU_TASK_LIST));
	pSubMenu->SetMenuText(1, _LANG(LANG_MENU_SETTINGS));
	pSubMenu->SetMenuText(3, _LANG(LANG_MENU_HIDE_ALL));
	pSubMenu->SetMenuText(4, _LANG(LANG_MENU_SHOW_ALL));
	pSubMenu->SetMenuText(5, _LANG(LANG_MENU_STOP_ALL));
	pSubMenu->SetMenuText(7, _LANG(LANG_MENU_ABOUT));
	pSubMenu->SetMenuText(9, _LANG(LANG_MENU_EXIT));

	if (bRedraw)
	{
		ShowWindow(SW_HIDE);
		ShowWindow(SW_SHOW);
	}
}

void AReloggerDlg::OnUpdateMenuLangEng(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(AfxSameLocale(_T("english")));
}

void AReloggerDlg::OnMenuLangEng() 
{
	// TODO: Add your command handler code here
	if (AfxSetLocale(_T("english")))
		PostMessage(WM_LANGUAGE_CHANGED);
}

void AReloggerDlg::OnUpdateMenuLangChs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(AfxSameLocale(_T("chs")));
}

void AReloggerDlg::OnMenuLangChs() 
{
	// TODO: Add your command handler code here
	if (AfxSetLocale(_T("chs")))
		PostMessage(WM_LANGUAGE_CHANGED);
}

void AReloggerDlg::OnUpdateMenuLangCht(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(AfxSameLocale(_T("cht")));
}

void AReloggerDlg::OnMenuLangCht() 
{
	// TODO: Add your command handler code here
	if (AfxSetLocale(_T("cht")))
		PostMessage(WM_LANGUAGE_CHANGED);
}
