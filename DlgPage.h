#if !defined(AFX_DLGPAGE_H__B079A4A2_C850_11D3_BFDF_005004648BC2__INCLUDED_)
#define AFX_DLGPAGE_H__B079A4A2_C850_11D3_BFDF_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DlgPage.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CPgImgBox window

class CPgImgBox : public CEdit
{
// Construction
public:
	CPgImgBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPgImgBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPgImgBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPgImgBox)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint(); //JRS
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CPageNum window
class CPageNum : public CEdit
{
// Construction
public:
	CPageNum();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageNum)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPageNum();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPageNum)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDlgPage dialog

class CDlgPage : public CDialog
{
// Construction
public:
	BOOL ReSizeControl( CRect rcClient );
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgPage(CWnd* pParent = NULL);   // standard constructor

	VOID DoValueUpdate();
	VOID DoSetScrollPos();
// Dialog Data
	//{{AFX_DATA(CDlgPage)
	enum { IDD = IDD_PAGE_PAGE };
	CButton	m_btNewPage;
	CButton	m_btExportPage;
	CStatic		m_stcPgTotal;
	CComboBox	m_cbPgType;
	CScrollBar	m_vsbList;
	DWORD		m_edPgNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	CPageNum	m_ctlPgNumEd;
	CPgImgBox	m_ctlPgDlgImg;

	VOID	InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo );	
	// Generated message map functions
	//{{AFX_MSG(CDlgPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelchangeCbPageType();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtNewPage();
	afx_msg void OnBtExportPage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	VOID InitDlgItemTextNTooltip();
	
//	DWORD m_edPgNum;
};


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPAGE_H__B079A4A2_C850_11D3_BFDF_005004648BC2__INCLUDED_)
