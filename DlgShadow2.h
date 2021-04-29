#if !defined(AFX_DLGSHADOW2_H__AA6EBB67_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGSHADOW2_H__AA6EBB67_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgShadow2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow2 dialog

class CDlgShadow2 : public CDialog
{
// Construction
public:
	CDlgShadow2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShadow2)
	enum { IDD = IDD_PG_SHADOW_2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShadow2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShadow2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHADOW2_H__AA6EBB67_D383_11D3_BF4E_005004648BC2__INCLUDED_)
