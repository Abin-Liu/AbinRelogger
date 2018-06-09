// AReloggerDlg.h : header file
//

#if !defined(AFX_ARELOGGERDLG_H__2088A497_C00C_413E_B80E_66166FFB3DDB__INCLUDED_)
#define AFX_ARELOGGERDLG_H__2088A497_C00C_413E_B80E_66166FFB3DDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Includes\ListCtrlEx.h"
#include "Includes\SystemTray.h"
#include "Includes\BCMenu.h"
#include "Includes\ReadOnlyEdit.h"
#include "LogWriter.h"

/////////////////////////////////////////////////////////////////////////////
// AReloggerDlg dialog

class AReloggerDlg : public CDialog
{
// Construction
public:
	AReloggerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(AReloggerDlg)
	enum { IDD = IDD_ARELOGGER_DIALOG };
	CStatic	m_wndLogSize;
	CButton	m_wndEdit;
	CButton	m_wndDelete;
	CButton	m_wndClone;
	CReadOnlyEdit	m_wndLog;
	CListCtrlEx	m_wndBotList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AReloggerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	void UpdateLanguage(BOOL bRedraw);
	LRESULT OnLanguageChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnDiabloConflict(WPARAM wParam, LPARAM lParam);
	BOOL CheckBotEditable(const CBot* pBot);
	void OnListOper();
	void UpdateBotInfo(DWORD dwFlags, const CBot* pBot, int nIndex = -1);
	
	LRESULT OnBotState(WPARAM wParam, LPARAM lParam);
	LRESULT OnListNotify(WPARAM wParam, LPARAM lParam);
	void UpdateButtons();

	void OnTick();
	
	LRESULT OnTrayNotify(WPARAM wParam , LPARAM lParam);
	BOOL Login(LPCTSTR lpszChecksum);
	BOOL AskForNewPwd();
	void Load();
	void Save();
	LRESULT OnReqPassword(WPARAM wParam, LPARAM lParam);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(AReloggerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNew();
	afx_msg void OnDestroy();
	afx_msg void OnEdit();
	virtual void OnCancel();
	afx_msg void OnPopupExit();
	afx_msg void OnPopupShowwnd();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPopupAbout();
	afx_msg void OnDelete();
	afx_msg void OnClone();
	afx_msg void OnUpdateTaskStart(CCmdUI* pCmdUI);
	afx_msg void OnTaskStart();
	afx_msg void OnUpdateTaskStop(CCmdUI* pCmdUI);
	afx_msg void OnTaskStop();
	afx_msg void OnUpdateTaskPauseresume(CCmdUI* pCmdUI);
	afx_msg void OnTaskPauseresume();
	afx_msg void OnUpdateTaskEdit(CCmdUI* pCmdUI);
	afx_msg void OnTaskEdit();
	afx_msg void OnUpdateTaskDelete(CCmdUI* pCmdUI);
	afx_msg void OnTaskDelete();
	afx_msg void OnUpdateTaskClone(CCmdUI* pCmdUI);
	afx_msg void OnTaskClone();
	afx_msg void OnTaskNew();
	afx_msg void OnExit();
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnMenuSettingsPassword();
	afx_msg void OnOpenlog();
	afx_msg void OnClearlog();
	afx_msg void OnMenuSettings();
	afx_msg void OnUpdateTaskHidegames(CCmdUI* pCmdUI);
	afx_msg void OnTaskHidegames();
	afx_msg void OnHideall();
	afx_msg void OnShowall();
	afx_msg void OnStopall();
	afx_msg void OnUpdateTaskDetach(CCmdUI* pCmdUI);
	afx_msg void OnTaskDetach();
	afx_msg void OnTrayHideall();
	afx_msg void OnTrayShowall();
	afx_msg void OnTrayStopall();
	afx_msg void OnDebug();
	afx_msg void OnUpdateMenuLangEng(CCmdUI* pCmdUI);
	afx_msg void OnMenuLangEng();
	afx_msg void OnUpdateMenuLangChs(CCmdUI* pCmdUI);
	afx_msg void OnMenuLangChs();
	afx_msg void OnUpdateMenuLangCht(CCmdUI* pCmdUI);
	afx_msg void OnMenuLangCht();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	BCMenu m_wndMainMenu;
	BCMenu m_wndTrayMenu;
	CString m_sPassword;
	BOOL m_bLoginOK;
	CSystemTray m_wndTray;
	BOOL m_bExiting;
	CLogWriter m_log;
	int m_nListOper;
	CIni m_ini;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARELOGGERDLG_H__2088A497_C00C_413E_B80E_66166FFB3DDB__INCLUDED_)
