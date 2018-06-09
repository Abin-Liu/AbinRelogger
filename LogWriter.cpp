// LogWriter.cpp: implementation of the CLogWriter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ARelogger.h"
#include "LogWriter.h"
#include <locale.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogWriter::CLogWriter()
{
	m_pwndEdit = NULL;
	m_pwndSizeLabel = NULL;
	m_bFileOK = FALSE;
}

CLogWriter::~CLogWriter()
{
	m_file.Close();
}

BOOL CLogWriter::Initialize(LPCTSTR lpszFilePath, BOOL bTruncate, CEdit *pwndEdit, CStatic *pwndSizeLabel)
{
	m_pwndEdit = pwndEdit;
	m_pwndSizeLabel = pwndSizeLabel;
	m_sFilePath = lpszFilePath;
	m_sLastLine.Empty();

	if (m_bFileOK)
		m_file.Close();

	DWORD dwFlags = CFile::modeReadWrite | CFile::modeCreate | CFile::shareDenyWrite;
	if (!bTruncate)
		dwFlags |= CFile::modeNoTruncate;
	
	m_bFileOK = m_file.Open(lpszFilePath, dwFlags);
	if (m_bFileOK)
	{
		if (pwndEdit && ::IsWindow(m_pwndEdit->m_hWnd))
		{
			CString sContents, sLine;
			while (m_file.ReadString(sLine))
				sContents += sLine + _T("\r\n");		
			m_pwndEdit->SetWindowText(sContents);		
		}
		else
		{
			m_file.SeekToEnd();
		}
	}

	UpdateSizeLabel();
	return m_bFileOK;
}

void CLogWriter::Append(LPCTSTR lpszText, LPCTSTR lpszPrefix, BOOL bTimestamp)
{
	CString sLine;
	if (lpszText && *lpszText)
	{
		if (lpszPrefix)
			sLine.Format(_T("[%s] %s"), lpszPrefix, lpszText);
		else
			sLine = lpszText;
	}	

	if (m_sLastLine == sLine)
		return;

	m_sLastLine = sLine;

	if (bTimestamp && !sLine.IsEmpty())
	{
		COleDateTime now = COleDateTime::GetCurrentTime();
		CString sTimestamp;
		sTimestamp.Format(_T("%02d-%02d %02d:%02d:%02d "), now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
		sLine = sTimestamp + sLine;
	}

	if (m_bFileOK)
		m_file.WriteString(sLine + _T('\n'));	

	if (m_pwndEdit && ::IsWindow(m_pwndEdit->m_hWnd))
	{
		CString sText;
		m_pwndEdit->GetWindowText(sText);
		m_pwndEdit->SetWindowText(sText + (sLine + _T("\r\n")));
		m_pwndEdit->LineScroll(m_pwndEdit->GetLineCount(), 0);
	}	

	UpdateSizeLabel();
}

DWORD CLogWriter::GetFileSize() const
{
	return m_file.GetLength();
}

void CLogWriter::Truncate()
{
	m_file.SetLength(0);

	if (m_pwndEdit && ::IsWindow(m_pwndEdit->m_hWnd))
		m_pwndEdit->SetWindowText(_T(""));

	UpdateSizeLabel();
}

void CLogWriter::OpenFile() const
{
	::ShellExecute(NULL, _T("open"), m_sFilePath, NULL, NULL, SW_SHOW);
}

static const DWORD KB = 1024;
static const DWORD MB = KB * KB;
static const DWORD GB = MB * KB;
static const DWORD CLEAR_RECOMMEND = 100 * KB;

void CLogWriter::UpdateSizeLabel()
{
	if (m_pwndSizeLabel && ::IsWindow(m_pwndSizeLabel->m_hWnd))
	{
		CString sLog = _LANG(LANG_MAIN_LOG);
		CString sText;
		DWORD dwLogSize = m_file.GetLength();
		if (dwLogSize >= GB)
			sText.Format(_T("%s: %.1fGB"), (LPCTSTR)sLog, (double)dwLogSize / (double)GB);
		else if (dwLogSize >= MB)
			sText.Format(_T("%s: %.1fMB"), (LPCTSTR)sLog, (double)dwLogSize / (double)MB);
		else if (dwLogSize >= KB)
			sText.Format(_T("%s: %.1fKB"), (LPCTSTR)sLog, (double)dwLogSize / (double)KB);
		else
			sText.Format(_T("%s: %d Bytes"), (LPCTSTR)sLog, dwLogSize);

		if (dwLogSize >= CLEAR_RECOMMEND)
			sText += _LANG(LANG_MAIN_SUGGEST_CLEAN);			

		m_pwndSizeLabel->SetWindowText(sText);
	}	
}

void CLogWriter::SetLocale(LPCTSTR lpszLocale)
{
	_tsetlocale(LC_CTYPE, lpszLocale);
}
