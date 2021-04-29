#if !defined(AFX_DLGBARCIR_H__EEF9B633_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARCIR_H__EEF9B633_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarCir.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBarCir dialog

class CDlgBarCir : public CDialogBar
{
// Construction
public:
	CDlgBarCir();   // standard constructor
	virtual ~CDlgBarCir();

// Dialog Data
	//{{AFX_DATA(CDlgBarCir)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarCir)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBarCir)
	virtual BOOL OnInitDialogBar();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg LRESULT InitDialogBarHandler( WPARAM wParam , LPARAM  lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARCIR_H__EEF9B633_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
