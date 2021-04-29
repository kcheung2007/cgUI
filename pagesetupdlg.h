#if !defined(AFX_PAGESETUPDLG_H__3EFB7942_DFDF_11D3_BF6B_005004648BC2__INCLUDED_)
#define AFX_PAGESETUPDLG_H__3EFB7942_DFDF_11D3_BF6B_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSetupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageSetupDlg dialog

class CPageSetupDlg : public CDialog
{
// Construction
public:
	CPageSetupDlg(CWnd* pParent = NULL);   // standard constructor
	~CPageSetupDlg();

// Dialog Data
	//{{AFX_DATA(CPageSetupDlg)
	enum { IDD = IDD_PAGE_SETUP_DLG };
	CButton	m_btOK;
	CEdit	m_edVertSpace;
	CEdit	m_edVertOffset;
	CEdit	m_edVert;
	CEdit	m_edTop;
	CEdit	m_edSTA;
	CEdit	m_edSpWidth;
	CEdit	m_edSpHeight;
	CEdit	m_edRight;
	CEdit	m_edLeft;
	CEdit	m_edHoriSpace;
	CEdit	m_edHoriOffset;
	CEdit	m_edHori;
	CEdit	m_edBottom;
	CButton	m_ckSafeAction;
	CButton	m_ckCenterPt;
	CButton	m_ckVert;
	CButton	m_ckSnapGrid;
	CButton	m_ckShowGrid;
	CButton	m_ckSafeTitle;
	CButton	m_ckHoriz;
	CComboBox	m_cbPSRes;
	CComboBox	m_cbPSType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageSetupDlg)
	afx_msg void OnOk();
	afx_msg void OnCancel();
	afx_msg void OnBtSTADefault();
	afx_msg void OnBtPMDefault();
	afx_msg void OnBtSTDefault();
	afx_msg void OnBtGridDefault();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCbType();
	afx_msg void OnKillfocusEdSpHeight();
	afx_msg void OnKillfocusEdSpWidth();
	afx_msg void OnIXOk();
	afx_msg void OnSelchangeCbResolution();
	afx_msg void OnCkHori();
	afx_msg void OnCkSafeAction();
	afx_msg void OnCkSafeTitleIndicator();
	afx_msg void OnCkShowGrids();
	afx_msg void OnCkSnapGrid();
	afx_msg void OnCkVert();
	afx_msg void OnKillfocusEdBottom();
	afx_msg void OnKillfocusEdHori();
	afx_msg void OnKillfocusEdHoriOffset();
	afx_msg void OnKillfocusEdHoriSpace();
	afx_msg void OnKillfocusEdLeft();
	afx_msg void OnKillfocusEdRight();
	afx_msg void OnKillfocusEdSta();
	afx_msg void OnKillfocusEdTop();
	afx_msg void OnKillfocusEdVert();
	afx_msg void OnKillfocusEdVertOffset();
	afx_msg void OnKillfocusEdVertSpace();
	afx_msg void OnDeltaposSpnPsBottom(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsHori(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsHoriOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsHoriSpace(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsLeft(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsResHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsResWidth(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsRight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsSta(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsTop(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsVert(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsVertOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPsVertSpace(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRb43();
	afx_msg void OnRb169();
	afx_msg void OnRbSqrPixel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
	BOOL m_bSnapGrid;
	BOOL m_bShowGrid;
	BOOL m_bCenterPt;
	BOOL m_bSafeAction;
	BOOL m_bSafeTitle;
	BOOL m_bVert;
	BOOL m_bHoriz;
	VOID UpdateResItemsGroup();
	VOID InitResolutionCombo();
	VOID InitCheckBoxControl();
	VOID InitDlgItemText();
	VOID InitTypeCombo();
	VOID InitEditControl();
	VOID InitSpinControl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESETUPDLG_H__3EFB7942_DFDF_11D3_BF6B_005004648BC2__INCLUDED_)
