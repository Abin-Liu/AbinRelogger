#if !defined(AFX_LOGINFAILDLG_H__3C6B43AC_1AC6_44EF_8F9C_753E820F0981__INCLUDED_)
#define AFX_LOGINFAILDLG_H__3C6B43AC_1AC6_44EF_8F9C_753E820F0981__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginFailDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginFailDlg dialog

class CLoginFailDlg : public CDialog
{
// Construction
public:
	CLoginFailDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginFailDlg)
	enum { IDD = IDD_LOGINFAILDLG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginFailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginFailDlg)
	afx_msg void OnDestroy();
	afx_msg void OnRetry();
	afx_msg void OnIgnore();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINFAILDLG_H__3C6B43AC_1AC6_44EF_8F9C_753E820F0981__INCLUDED_)
