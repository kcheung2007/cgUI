#if !defined(AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBox dialog

class CDlgBarBox : public CDialogBar
{
// Construction
public:
	CDlgBarBox();   // standard constructor
	virtual ~CDlgBarBox();
virtual void OnInitDialogBar();
// Dialog Data
	//{{AFX_DATA(CDlgBarBox)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBarBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void InitDialogBarHandler( WORD wParam , DWORD  lParam );
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
