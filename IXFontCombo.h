#include <afxtempl.h>
#include "IXTipWnd.h"

#ifndef __FONT_COMBO__
#define __FONT_COMBO__

#define TRUETYPE_FONT		0x0001
#define PRINTER_FONT		0x0002
#define DEVICE_FONT			0x0004

/////////////////////////////////////////////////////////////////////////////////////
// CIXFontObj Class
class CIXFontObj : public CObject
{
protected:	
	BOOL	m_bInUse;	// Fonts in use 
	DWORD	m_nFlags;	// Font flags
public:
	CIXFontObj(DWORD nFlags)
	{	
		m_nFlags = nFlags;
		m_bInUse = FALSE;
	}

	CIXFontObj(CIXFontObj* pFontObj)
	{	
		m_nFlags = pFontObj->GetFlags();
		m_bInUse = pFontObj->GetFontInUse();
	}

	DWORD GetFlags() const { return m_nFlags; }
	BOOL  GetFontInUse() { return m_bInUse; }
	void  SetFontInUse(BOOL bInUse) { m_bInUse = bInUse; }
}; // end of CIXFontObj Class

/////////////////////////////////////////////////////////////////////////////
// CIXFontCombo window
class CIXFontCombo : public CComboBox
{

// Construction
public:
	CIXFontCombo();
	void Initialize();
	void AddFont(CString strName, DWORD dwFlags);
//	void AddFont(LPTSTR strName, DWORD dwFlags);

protected:	
	void SetCurrentFont();
public:


// Attributes
public:

protected:
	CIXTipWnd		m_wndTip;
	CString			m_strFontSave;
	CString			m_strDefault;
	CImageList		m_imgList;

	CTypedPtrMap<CMapStringToPtr, CString, CIXFontObj*> m_mapFonts;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIXFontCombo)
	public:
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	VOID SetNonSysFont( CString font );
	virtual ~CIXFontCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIXFontCombo)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKillfocus();
	afx_msg void OnSetfocus();
	afx_msg void OnCloseUp();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
}; //end of CIXFontCombo

#endif

