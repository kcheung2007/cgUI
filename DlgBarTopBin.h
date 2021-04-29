#if !defined(AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#include "DlgPage.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarTxt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImgTopBin window

class CImgTopBin : public CEdit
{
// Construction
public:
	CImgTopBin();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgTopBin)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgTopBin();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImgTopBin)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();//added jrs 00-04-13
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CImgBotBin window

class CImgBotBin : public CEdit
{
// Construction
public:
	CImgBotBin();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgBotBin)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgBotBin();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImgBotBin)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
};

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinTop dialog
class CDlgBarBinTop : public CDialogBar
{
// Construction
public:
	VOID DoSetTopScrollPos();
	VOID DoSetBotScrollPos();
	CDlgBarBinTop();   // standard constructor
	virtual ~CDlgBarBinTop();

// Dialog Data
	//{{AFX_DATA(CDlgBarBinTop)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarBinTop)
	protected:
	virtual BOOL OnInitDialogBar();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CScrollBar	m_vsbTop;
	CScrollBar	m_vsbBot;
	CImgTopBin	m_ctlTopBin;
	CImgBotBin	m_ctlBotBin;

	// Generated message map functions
	//{{AFX_MSG(CDlgBarBinTop)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT InitDialogBarHandler( WPARAM wParam , LPARAM  lParam );
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID VBotBinScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	VOID VTopBinScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
