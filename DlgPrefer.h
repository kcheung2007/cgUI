#if !defined(AFX_DLGPREFER_H__AAD4EFBF_1F16_4DAA_86AF_A1684313C6D3__INCLUDED_)
#define AFX_DLGPREFER_H__AAD4EFBF_1F16_4DAA_86AF_A1684313C6D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPrefer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPrefer dialog

class CDlgPrefer : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CDlgPrefer(CWnd* pParent = NULL);   // standard constructor
	~CDlgPrefer();

// Dialog Data
	//{{AFX_DATA(CDlgPrefer)
	enum { IDD = IDD_DLG_PREFER };
	CButton	m_btBrowse3;
	CButton	m_btBrowse2;
	CButton	m_btBrowse1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPrefer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPrefer)
	afx_msg void OnBtBrowse1();
	afx_msg void OnBtBrowse2();
	afx_msg void OnBtBrowse3();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPREFER_H__AAD4EFBF_1F16_4DAA_86AF_A1684313C6D3__INCLUDED_)
