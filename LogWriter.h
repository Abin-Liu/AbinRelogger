// LogWriter.h: interface for the CLogWriter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGWRITER_H__E3C3ED55_7168_4E8A_834C_08932C36F3E8__INCLUDED_)
#define AFX_LOGWRITER_H__E3C3ED55_7168_4E8A_834C_08932C36F3E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogWriter  
{
public:	
	static void SetLocale(LPCTSTR lpszLocale);

	CLogWriter();
	virtual ~CLogWriter();

	BOOL Initialize(LPCTSTR lpszFilePath, BOOL bTruncate, CEdit* pwndEdit, CStatic* pwndSizeLabel = NULL);
	void Append(LPCTSTR lpszText, LPCTSTR lpszPrefix = NULL, BOOL bTimestamp = TRUE);
	DWORD GetFileSize() const;
	void OpenFile() const;
	void Truncate();
	void UpdateSizeLabel();

protected:
	
	CEdit* m_pwndEdit;
	CStatic* m_pwndSizeLabel;
	CStdioFile m_file;
	CString m_sLastLine;
	CString m_sFilePath;
	BOOL m_bFileOK;
};

#endif // !defined(AFX_LOGWRITER_H__E3C3ED55_7168_4E8A_834C_08932C36F3E8__INCLUDED_)
