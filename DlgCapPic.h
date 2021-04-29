#if !defined(AFX_DLGCAPPIC_H__F0CBFD43_DC42_43E1_B1EE_476F77E142B6__INCLUDED_)
#define AFX_DLGCAPPIC_H__F0CBFD43_DC42_43E1_B1EE_476F77E142B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCapPic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCapPic dialog

class CDlgCapPic : public CDialog
{
// Construction
public:
	VOID SetGrabType( BOOL type );	
	CDlgCapPic(CWnd* pParent = NULL);   // standard constructor
	~CDlgCapPic();

// Dialog Data
	//{{AFX_DATA(CDlgCapPic)
	enum { IDD = IDD_DLG_CAP_PICONS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCapPic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_GrabType;

	// Generated message map functions
	//{{AFX_MSG(CDlgCapPic)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
	VOID InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCAPPIC_H__F0CBFD43_DC42_43E1_B1EE_476F77E142B6__INCLUDED_)
