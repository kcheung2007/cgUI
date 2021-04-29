#if !defined(AFX_DLGBARLEFT_H__C4A450D3_C77F_11D3_BFDE_005004648BC2__INCLUDED_)
#define AFX_DLGBARLEFT_H__C4A450D3_C77F_11D3_BFDE_005004648BC2__INCLUDED_

#include "IXTabCtrl.h"	// Added by ClassView
#include "DlgPage.h"
#include "DlgLayer.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarLeft.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CDlgBarLeft dialog

class CDlgBarLeft : public CDialogBar
{
// Construction
public:
	CDlgBarLeft();   // standard constructor
	CDlgPage*  m_pDlgPage;
	CDlgLayer* m_pDlgLayer;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarLeft)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:	
	virtual BOOL OnInitDialogBar();
	virtual ~CDlgBarLeft();

protected:	
	CIXTabCtrl m_ctlTab;

	// Generated message map functions
	//{{AFX_MSG(CDlgBarLeft)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT InitDialogBarHandler( WPARAM wParam , LPARAM  lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARLEFT_H__C4A450D3_C77F_11D3_BFDE_005004648BC2__INCLUDED_)
