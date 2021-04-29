#if !defined(AFX_EFFECTBIN_H__E6B67002_95ED_4920_93BE_A58C660088B8__INCLUDED_)
#define AFX_EFFECTBIN_H__E6B67002_95ED_4920_93BE_A58C660088B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EffectBin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEffectBin window

class CEffectBin : public CEdit
{
// Construction
public:
	CEffectBin();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEffectBin)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEffectBin();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEffectBin)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EFFECTBIN_H__E6B67002_95ED_4920_93BE_A58C660088B8__INCLUDED_)
