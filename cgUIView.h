// cgUIView.h : interface of the CCgUIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGUIVIEW_H__F12BAE2E_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_CGUIVIEW_H__F12BAE2E_C546_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Imm.h"

struct POP_MENU_DATA
{
	TCHAR szSearch[50];
	TCHAR szDisplay[50];
};

class CCgUIView : public CView
{
protected: // create from serialization only
	CCgUIView();
	DECLARE_DYNCREATE(CCgUIView)

// Attributes
public:
	CCgUIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCgUIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnInitialUpdate();
	protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	VOID ImeUIEndComposition( WPARAM wParam, LPARAM lParam );
	VOID ImeUIComposition( WPARAM wParam, LPARAM lParam );
	VOID ImeUIStartComposition( WPARAM wParam, LPARAM lParam );
	VOID ImeCandidateNotify( UINT msg, WPARAM wParam, LPARAM lParam );
	VOID HandleKeyIn( DWORD wParam );
	VOID ImeUICloseCandidate( HWND hWnd, LPARAM lParam );
	VOID ImeUIOpenCandidate( HWND hWnd, LPARAM lParam );
	VOID CGUI_SendImeFinalResultStrToCore( HIMC hImc );
	VOID CGUI_SendImeCompStrToCore( HIMC hImc );
	virtual ~CCgUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCgUIView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnOptOne();
	afx_msg void OnOptTwo();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_nItem;
	VOID LoadPopMenuText();
	POP_MENU_DATA* m_pPopMenu;
	VOID PopUpMenu( DWORD popMenuID, CPoint point );
	UINT m_dbClickTimer;
	BOOL m_bDbClick;
	BOOL  m_spaceFlag;
	BOOL  m_bHitEnter;
	DWORD m_ImeCurPos;
	DWORD m_IMEState;
};

#ifndef _DEBUG  // debug version in cgUIView.cpp
inline CCgUIDoc* CCgUIView::GetDocument()
   { return (CCgUIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGUIVIEW_H__F12BAE2E_C546_11D3_BFDB_005004648BC2__INCLUDED_)
