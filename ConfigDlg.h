#if !defined(AFX_CONFIGDLG_H__B08AE6EC_B7DF_4D1A_8868_ED601D4746B9__INCLUDED_)
#define AFX_CONFIGDLG_H__B08AE6EC_B7DF_4D1A_8868_ED601D4746B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigDlg.h : header file
//

#include "Includes\EditEx.h"
#include "Bot.h"

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog

class CConfigDlg : public CDialog
{
// Construction
public:
	CConfigDlg(int nOper, LPCONFIGDATA pData, CWnd* pParent = NULL);   // standard constructor
	LPCONFIGDATA m_pData;

// Dialog Data
	//{{AFX_DATA(CConfigDlg)
	enum { IDD = IDD_CONFIGDLG };
	CEditEx	m_wndLogin;
	CEditEx	m_wndLeave;
	CEditEx	m_wndDiabloLaunch;
	CEditEx	m_wndJoin;
	CEditEx	m_wndDiabloHung;
	CEditEx	m_wndDisconnect;
	CEditEx	m_wndDemonbuddyHung;
	BOOL	m_bDB2x;
	BOOL	m_bNoMin;
	BOOL	m_bTripWire;
	UINT	m_nDemonbuddyHung;
	UINT	m_nDisconnect;
	UINT	m_nDiabloHung;
	UINT	m_nJoin;
	UINT	m_nDiabloLaunch;
	UINT	m_nLeave;
	BOOL	m_bReuseWnd;
	UINT	m_nLogin;
	int		m_nOper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	//COXToolTipCtrl m_wndTooltip;
	CToolTipCtrl m_wndTooltip;

	// Generated message map functions
	//{{AFX_MSG(CConfigDlg)
	virtual void OnOK();
	afx_msg void OnDefault();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGDLG_H__B08AE6EC_B7DF_4D1A_8868_ED601D4746B9__INCLUDED_)
