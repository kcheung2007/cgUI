#if !defined(AFX_DLGCAST1_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGCAST1_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCast1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCast1 dialog

class CDlgCast1 : public CDialog
{
// Construction
public:
	CDlgCast1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCast1)
	enum { IDD = IDD_PG_CAST_1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCast1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCast1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCAST1_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_)
