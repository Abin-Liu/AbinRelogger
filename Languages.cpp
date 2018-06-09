#include "stdafx.h"
#include "Languages.h"
#include <locale.h>

CLanguage::CLanguage()
{
	RegisterLocale(_T("english"), _T("English"), Provider_English);
	RegisterLocale(_T("chs"), _T("简体中文"), Provider_Chinese_Simplified);
	RegisterLocale(_T("cht"), _T("繁體中文"), Provider_Chinese_Traditional);
}

CLanguage::~CLanguage()
{
}

void CLanguage::RegisterLocale(LPCTSTR lpszLocale, LPCTSTR lpszName, FN_LOCALE_PROVIDER fnProvider)
{
	ASSERT(lpszLocale && *lpszLocale);
	ASSERT(lpszName && *lpszName);
	ASSERT(fnProvider);

	LANGUAGE_ENTRY entry = { 0 };
	_tcsncpy(entry.szLocale, lpszLocale, 31);
	_tcsncpy(entry.szName, lpszName, 63);
	entry.lpFunc = fnProvider;

	m_aEntries.Add(entry);
}

BOOL CLanguage::SetLocale(LPCTSTR lpszLocale)
{
	if (lpszLocale == NULL || *lpszLocale == 0)
		return FALSE;
	
	if (m_sLocale.CompareNoCase(lpszLocale) == 0)
		return FALSE;

	int nIndex = FindDataByLocale(lpszLocale);
	if (nIndex == -1)
		return FALSE;

	LANGUAGE_ENTRY entry = m_aEntries[nIndex];
	m_sLocale = entry.szLocale;

	if (sizeof(TCHAR) > 1)
		::setlocale(LC_CTYPE, m_sLocale);	
	
	FN_LOCALE_PROVIDER fn = (FN_LOCALE_PROVIDER)entry.lpFunc;
	fn(m_aMap);	
	return TRUE;
}

CString CLanguage::GetLocale() const
{
	return m_sLocale;
}

int CLanguage::GetLocaleCount() const
{
	return m_aEntries.GetSize();
}

BOOL CLanguage::GetLocale(int nIndex, CString &rLocale, CString &rName) const
{
	if (nIndex < 0 || nIndex >= m_aEntries.GetSize())
		return FALSE;

	LANGUAGE_ENTRY entry = m_aEntries[nIndex];
	rLocale = entry.szLocale;
	rName = entry.szName;
	return TRUE;
}

int CLanguage::FindDataByLocale(LPCTSTR lpszLocale) const
{
	if (lpszLocale == NULL || *lpszLocale == 0)
		return -1;

	for (int i = 0; i < m_aEntries.GetSize(); i++)
	{
		if (_tcsicmp(m_aEntries[i].szLocale, lpszLocale) == 0)
			return i;
	}

	return -1;
}

CString CLanguage::GetDefaultLocale()
{
	CString sLocale;
	LCID lcid = ::GetSystemDefaultLCID();
	switch (lcid)
	{
	case 0x0804: // PRC
	case 0x1004: // Singapore
		sLocale = _T("chs");
		break;

	case 0x0404: // Taiwan
	case 0x0c04: // Hongkong
	case 0x1404: // Macao
		sLocale = _T("cht");
		break;

	default:
		sLocale = _T("english");
		break;
	}

	return sLocale;
}

CString CLanguage::GetText(int nID) const
{
	CString str;
	m_aMap.Lookup(nID, str);
	return str;
}
