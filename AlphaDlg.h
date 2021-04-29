#if !defined(AFX_ALPHADLG_H__C8F2664B_638C_4C4B_A5CD_14BCAB9645A0__INCLUDED_)
#define AFX_ALPHADLG_H__C8F2664B_638C_4C4B_A5CD_14BCAB9645A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlphaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlphaDlg dialog

class CAlphaDlg : public CDialog
{
// Construction
public:
	CAlphaDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlphaDlg)
	enum { IDD = IDD_ALPHA_BOX };
	CButton	m_btOK;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlphaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlphaDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALPHADLG_H__C8F2664B_638C_4C4B_A5CD_14BCAB9645A0__INCLUDED_)
