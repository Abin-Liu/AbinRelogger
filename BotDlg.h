#if !defined(AFX_BOTDLG_H__ECE09DD5_2763_4036_BD1A_351A9539C113__INCLUDED_)
#define AFX_BOTDLG_H__ECE09DD5_2763_4036_BD1A_351A9539C113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BotDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBotDlg dialog

#include "Includes\BrowseCtrl.h"
#include "Includes\EditEx.h"
#include "Bot.h"

class CBotDlg : public CDialog
{
// Construction
public:
	CBotDlg(const CBot* pBot, CWnd* pParent = NULL);   // standard constructor
	CString m_sDiabloPath;
	CString m_sDemonBuddyPath;
	CString m_sProfilePath;

// Dialog Data
	//{{AFX_DATA(CBotDlg)
	enum { IDD = IDD_BOTDLG };
	CEditEx	m_wndName;
	CEditEx	m_wndUserPassword;
	CEditEx	m_wndUserAccount;
	CEditEx	m_wndDemonBuddyKey;
	CButton	m_wndUseBNetAuth;
	CEditEx	m_wndBNetSerial;
	CEditEx	m_wndBNetRestoreCode;
	CBrowseCtrl	m_wndDemonBuddyPath;
	CBrowseCtrl	m_wndProfilePath;
	CBrowseCtrl	m_wndDiabloPath;
	BOOL	m_bUseBNetAuth;
	CString	m_sBNetRestoreCode;
	CString	m_sBNetSerial;
	CString	m_sDemonBuddyKey;
	CString	m_sUserAccount;
	CString	m_sUserPassword;
	CString	m_sName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBotDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	BOOL VerifyPath(CString& rPath, CBrowseCtrl* pCtl, LPCTSTR lpszFile, LPCTSTR lpszName);
	BOOL VerifyEdit(CString& sText, CEditEx* pEdit, LPCTSTR lpszName);

	// Generated message map functions
	//{{AFX_MSG(CBotDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnUsebnetauth();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTDLG_H__ECE09DD5_2763_4036_BD1A_351A9539C113__INCLUDED_)
