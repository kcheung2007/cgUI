#if !defined(AFX_PGTEMPLATE_H__2BD8BC1C_FEFB_418C_A1D8_341E8702AF76__INCLUDED_)
#define AFX_PGTEMPLATE_H__2BD8BC1C_FEFB_418C_A1D8_341E8702AF76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PgTemplate.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPgTemplate dialog

class CPgTemplate : public CDialog
{
// Construction
public:
	VOID InitDlgItemTextNTooltip();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CPgTemplate(CWnd* pParent = NULL);   // standard constructor
	~CPgTemplate();

// Dialog Data
	//{{AFX_DATA(CPgTemplate)
	enum { IDD = IDD_PAGE_TEMPLATES };
	CButton	m_btSaveTemplate;
	CScrollBar	m_vScrollBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPgTemplate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CPgTemplate)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBtSaveTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD  m_numTxt;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGTEMPLATE_H__2BD8BC1C_FEFB_418C_A1D8_341E8702AF76__INCLUDED_)
