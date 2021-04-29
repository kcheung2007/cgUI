// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__F12BAE2A_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_CHILDFRM_H__F12BAE2A_C546_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	VOID SetVertPos( double vPos );
	VOID SetHorzPos( double hPos );
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	afx_msg void OnPageTypeCrawl();
	afx_msg void OnPageTypeRoll();
	afx_msg void OnPageTypeStill();
	afx_msg void OnUpdatePageTypeCrawl(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePageTypeRoll(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePageTypeStill(CCmdUI* pCmdUI);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
//	afx_msg void OnSysCommand( UINT, LONG );
	DECLARE_MESSAGE_MAP()
private:
	INT  m_hsPos;
	INT  m_vsPos;
	BOOL m_bCrawl;
	BOOL m_bRoll;
	BOOL m_bStill;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__F12BAE2A_C546_11D3_BFDB_005004648BC2__INCLUDED_)
