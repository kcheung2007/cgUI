#if !defined(AFX_PGANNOT_H__ACC0C8D6_ED7B_4CD1_AA76_EFBBDF9984B3__INCLUDED_)
#define AFX_PGANNOT_H__ACC0C8D6_ED7B_4CD1_AA76_EFBBDF9984B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PgAnnot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPgAnnot dialog

class CPgAnnot : public CDialog
{
// Construction
public:
	VOID SetAnnotString( char* pStr );
	char* GetPgAnnotation();
	CPgAnnot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPgAnnot)
	enum { IDD = IDD_DLG_ANNOTATION };
	CEdit	m_edPgTxt;
	CString	m_strPgTxt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPgAnnot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPgAnnot)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGANNOT_H__ACC0C8D6_ED7B_4CD1_AA76_EFBBDF9984B3__INCLUDED_)
