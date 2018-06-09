#if !defined(AFX_PWDDLG_H__6DFD7874_BBFF_4BF2_95A7_75140A0EB3BD__INCLUDED_)
#define AFX_PWDDLG_H__6DFD7874_BBFF_4BF2_95A7_75140A0EB3BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PwdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPwdDlg dialog
#include "Includes\EditEx.h"

class CPwdDlg : public CDialog
{
// Construction
public:
	CPwdDlg(LPCTSTR lpszOldPwd, CWnd* pParent = NULL);   // standard constructor
	BOOL m_bOldPwd;
	CString m_sOldPwd;

// Dialog Data
	//{{AFX_DATA(CPwdDlg)
	enum { IDD = IDD_PWDDLG };
	CEditEx	m_wndPassword;
	CString	m_sPassword;
	CString	m_sLabel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPwdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPwdDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PWDDLG_H__6DFD7874_BBFF_4BF2_95A7_75140A0EB3BD__INCLUDED_)
