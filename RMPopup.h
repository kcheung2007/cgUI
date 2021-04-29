#if !defined(AFX_RMPOPUP_H__C99C2333_8542_44DB_B887_EB1444AD9F71__INCLUDED_)
#define AFX_RMPOPUP_H__C99C2333_8542_44DB_B887_EB1444AD9F71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RMPopup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRMPopup dialog

class CRMPopup : public CDialog
{
// Construction
public:
	CRMPopup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRMPopup)
	enum { IDD = IDD_RM_POP_UP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMPopup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRMPopup)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMPOPUP_H__C99C2333_8542_44DB_B887_EB1444AD9F71__INCLUDED_)
