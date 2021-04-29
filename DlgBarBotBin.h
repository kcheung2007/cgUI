#if !defined(AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
#define AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBinBot dialog

class CDlgBarBinBot : public CDialogBar
{
// Construction
public:
	CDlgBarBinBot();   // standard constructor
	virtual ~CDlgBarBinBot();
virtual void OnInitDialogBar();
// Dialog Data
	//{{AFX_DATA(CDlgBarBinBot)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarBinBot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBarBinBot)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void InitDialogBarHandler( WORD wParam , DWORD  lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARBOX_H__EEF9B632_CDC9_11D3_BF4B_005004648BC2__INCLUDED_)
