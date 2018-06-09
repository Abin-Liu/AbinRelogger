#if !defined(AFX_NEWPWDDLG_H__FE33ECB0_83D6_4996_9472_EC6F42FF0990__INCLUDED_)
#define AFX_NEWPWDDLG_H__FE33ECB0_83D6_4996_9472_EC6F42FF0990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewPwdDlg.h : header file
//

#include "Includes\EditEx.h"

/////////////////////////////////////////////////////////////////////////////
// CNewPwdDlg dialog

class CNewPwdDlg : public CDialog
{
// Construction
public:
	CNewPwdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewPwdDlg)
	enum { IDD = IDD_NEWPWDDLG };
	CEditEx	m_wndPwd2;
	CEditEx	m_wndPwd;
	CString	m_sPwd;
	CString	m_sPwd2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewPwdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewPwdDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWPWDDLG_H__FE33ECB0_83D6_4996_9472_EC6F42FF0990__INCLUDED_)
