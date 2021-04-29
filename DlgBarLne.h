#if !defined(AFX_DLGBARLNE_H__EEF9B636_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARLNE_H__EEF9B636_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarLne.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBarLne dialog

class CDlgBarLne : public CDialogBar
{
// Construction
public:
	CDlgBarLne();   // standard constructor
	virtual ~CDlgBarLne();

// Dialog Data
	//{{AFX_DATA(CDlgBarLne)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarLne)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBarLne)
	virtual BOOL OnInitDialogBar();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT InitDialogBarHandler( WPARAM wParam , LPARAM  lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARLNE_H__EEF9B636_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
