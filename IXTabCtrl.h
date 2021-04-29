#if !defined(AFX_IXTABCTRL_H__A11951B3_2F95_11D3_A896_00A0C9B6FB28__INCLUDED_)
#define AFX_IXTABCTRL_H__A11951B3_2F95_11D3_A896_00A0C9B6FB28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IXTabCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIXTabCtrl window
#include <afxtempl.h>
#include "Global.h"

class CIXTabCtrl : public CTabCtrl
{
// Construction
public:
	CIXTabCtrl();

// Attributes
public:

// Operations
public:
	VOID AddTab(CWnd* pWnd, LPTSTR lpszCaption, INT iImage =0);
	VOID EnableTab(INT iIndex, BOOL bEnable = TRUE);
	BOOL SelectTab(INT iIndex);
	VOID DeleteAllTabs();
	VOID DeleteTab(INT iIndex);
	VOID SetTopLeftCorner(CPoint pt);
	BOOL IsTabEnabled(INT iIndex);

	VOID SetDisabledColor(COLORREF cr);
	VOID SetSelectedColor(COLORREF cr);
	VOID SetNormalColor(COLORREF cr);
	VOID SetMouseOverColor(COLORREF cr);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIXTabCtrl)
	protected:
	virtual VOID DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual VOID PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	INT GetIndexMouseOver();
	virtual ~CIXTabCtrl();

	// Generated message map functions
protected:
	CArray<BOOL, BOOL> m_arrayStatusTab; // enabled Y\N
	INT			m_iSelectedTab;
	POINT		m_ptTabs;		// position of page dialog in tab control
	COLORREF	m_crSelected;	// tab font color
	COLORREF	m_crDisabled;
	COLORREF	m_crNormal;
	COLORREF	m_crMouseOver;

	INT			m_iIndexMouseOver;
	
	BOOL		m_bMouseOver;	
	BOOL		m_bColorMouseOver;
	BOOL		m_bColorNormal;
	BOOL		m_bColorDisabled;
	BOOL		m_bColorSelected;
	
	//{{AFX_MSG(CIXTabCtrl)
	afx_msg VOID OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg VOID OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg VOID OnMouseMove(UINT nFlags, CPoint point);
	afx_msg VOID OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XTABCTRL_H__A11951B3_2F95_11D3_A896_00A0C9B6FB28__INCLUDED_)
