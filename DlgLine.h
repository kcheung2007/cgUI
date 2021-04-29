#if !defined(AFX_DLGLINE_H__3EFB7943_DFDF_11D3_BF6B_005004648BC2__INCLUDED_)
#define AFX_DLGLINE_H__3EFB7943_DFDF_11D3_BF6B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLine dialog

class CDlgLine : public CDialog
{
// Construction
public:
	CDlgLine(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLine)
	enum { IDD = IDD_DLGBAR_PLNE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLine)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLINE_H__3EFB7943_DFDF_11D3_BF6B_005004648BC2__INCLUDED_)
