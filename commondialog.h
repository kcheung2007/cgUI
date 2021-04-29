#if !defined(AFX_COMMONDIALOG_H__42AEBC66_179D_40C2_BE20_6ED3B1A96ADB__INCLUDED_)
#define AFX_COMMONDIALOG_H__42AEBC66_179D_40C2_BE20_6ED3B1A96ADB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CCommonDialog1 wrapper class

class CCommonDialog1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCommonDialog1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xf9043c85, 0xf6f2, 0x101a, { 0xa3, 0xc9, 0x8, 0x0, 0x2b, 0x2f, 0x49, 0xfb } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	CString GetFileName();
	void SetFileName(LPCTSTR lpszNewValue);
	CString GetDialogTitle();
	void SetDialogTitle(LPCTSTR lpszNewValue);
	CString GetFilter();
	void SetFilter(LPCTSTR lpszNewValue);
	CString GetDefaultExt();
	void SetDefaultExt(LPCTSTR lpszNewValue);
	CString GetInitDir();
	void SetInitDir(LPCTSTR lpszNewValue);
	unsigned long GetColor();
	void SetColor(unsigned long newValue);
	long GetFlags();
	void SetFlags(long nNewValue);
	CString GetFontName();
	void SetFontName(LPCTSTR lpszNewValue);
	BOOL GetFontBold();
	void SetFontBold(BOOL bNewValue);
	BOOL GetFontItalic();
	void SetFontItalic(BOOL bNewValue);
	BOOL GetFontStrikeThru();
	void SetFontStrikeThru(BOOL bNewValue);
	BOOL GetFontUnderLine();
	void SetFontUnderLine(BOOL bNewValue);
	short GetFromPage();
	void SetFromPage(short nNewValue);
	short GetToPage();
	void SetToPage(short nNewValue);
	short GetMin();
	void SetMin(short nNewValue);
	short GetMax();
	void SetMax(short nNewValue);
	short GetCopies();
	void SetCopies(short nNewValue);
	BOOL GetCancelError();
	void SetCancelError(BOOL bNewValue);
	CString GetHelpFile();
	void SetHelpFile(LPCTSTR lpszNewValue);
	short GetHelpCommand();
	void SetHelpCommand(short nNewValue);
	CString GetHelpKey();
	void SetHelpKey(LPCTSTR lpszNewValue);
	BOOL GetPrinterDefault();
	void SetPrinterDefault(BOOL bNewValue);
	short GetFilterIndex();
	void SetFilterIndex(short nNewValue);
	long GetHelpContext();
	void SetHelpContext(long nNewValue);
	float GetFontSize();
	void SetFontSize(float newValue);
	short GetAction();
	void SetAction(short nNewValue);
	short GetMaxFileSize();
	void SetMaxFileSize(short nNewValue);
	long GetHDC();
	void SetHDC(long nNewValue);
	CString GetFileTitle();
	void SetFileTitle(LPCTSTR lpszNewValue);
	void ShowOpen();
	void ShowSave();
	void ShowColor();
	void ShowFont();
	void ShowPrinter();
	void ShowHelp();
	long GetOrientation();
	void SetOrientation(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMONDIALOG_H__42AEBC66_179D_40C2_BE20_6ED3B1A96ADB__INCLUDED_)
