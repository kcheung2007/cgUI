#if !defined(AFX_FONTLOCATOR_H__40CCAE33_69A3_450D_B314_694FF8C5FFB5__INCLUDED_)
#define AFX_FONTLOCATOR_H__40CCAE33_69A3_450D_B314_694FF8C5FFB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontLocator.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontLocator dialog

class CFontLocator : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CFontLocator(CWnd* pParent = NULL);   // standard constructor
	~CFontLocator();

// Dialog Data
	//{{AFX_DATA(CFontLocator)
	enum { IDD = IDD_FONT_LOCATOR };
	CScrollBar	m_vsbFont;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontLocator)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFontLocator)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD  m_numTxt;
	HFONT* m_hFont;
	CRect  m_rcCell;
	CRect  m_rcDlg;
	CRect  m_rcFrm;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTLOCATOR_H__40CCAE33_69A3_450D_B314_694FF8C5FFB5__INCLUDED_)
