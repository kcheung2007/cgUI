#if !defined(AFX_TIPWND_H__D9FED000_F603_11D1_A8D9_0060970C2D45__INCLUDED_)
#define AFX_TIPWND_H__D9FED000_F603_11D1_A8D9_0060970C2D45__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TipWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIXTipWnd window

class CIXTipWnd : public CWnd
{
// Construction
public:
	CIXTipWnd();

// Attributes
public:
protected:
	CFont		m_font;
	CString		m_strFont;
	
// Operations
public:
	BOOL Create(CWnd* pParent);
	void ShowTips(CPoint pt, const CString& str);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIXTipWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIXTipWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIXTipWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPWND_H__D9FED000_F603_11D1_A8D9_0060970C2D45__INCLUDED_)
