#if !defined(AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarTxt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBarTxt dialog

class CDlgBarTxt : public CDialogBar
{
// Construction
public:
	CDlgBarTxt();   // standard constructor
	virtual ~CDlgBarTxt();

// Dialog Data
	//{{AFX_DATA(CDlgBarTxt)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarTxt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBarTxt)
	virtual BOOL OnInitDialogBar();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void InitDialogBarHandler( WORD wParam , DWORD  lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARTXT_H__EEF9B631_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
