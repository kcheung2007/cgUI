#if !defined(AFX_DLGFILTER_H__2A53CB73_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_DLGFILTER_H__2A53CB73_C54D_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFilter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFilter dialog

class CDlgFilter : public CDialog
{
// Construction
public:
	CDlgFilter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFilter)
	enum { IDD = IDD_PAGE_FILTER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFilter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFilter)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFILTER_H__2A53CB73_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
