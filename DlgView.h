#if !defined(AFX_DLGVIEW_H__BD14F1B4_CE60_4EC7_BADF_6B4A030CCCE4__INCLUDED_)
#define AFX_DLGVIEW_H__BD14F1B4_CE60_4EC7_BADF_6B4A030CCCE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgView dialog

class CDlgView : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CDlgView(CWnd* pParent = NULL);   // standard constructor
	~CDlgView();

// Dialog Data
	//{{AFX_DATA(CDlgView)
	enum { IDD = IDD_PAGE_VIEW };
	CSpinButtonCtrl	m_spnGamma;
	CEdit	m_ctlEdGamma;
	CButton	m_ckTab;
	CButton	m_ckShowAChannel;
	CButton	m_ckSelBox;
	CButton	m_ckSafeTtile;
	CButton	m_ckSafeAct;
	CButton	m_ckMonGamma;
	CButton	m_ckLneMargin;
	CButton	m_ckGrid;
	CButton	m_ckCenterPoint;
	CButton	m_ckBaseline;
	CButton	m_ckAspectCorrect;
	CButton	m_btTab;
	CButton	m_btSetting;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgView)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtTab();
	afx_msg void OnBtSetting();
	afx_msg void OnDeltaposSpnMonGamma(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnCkSafeTitle();
	afx_msg void OnCkSafeAction();
	afx_msg void OnCkCenterPoint();
	afx_msg void OnCkTab();
	afx_msg void OnCkGrids();
	afx_msg void OnCkSelBox();
	afx_msg void OnCkLneMargin();
	afx_msg void OnCkBaseline();
	afx_msg void OnCkAspectCorrection();
	afx_msg void OnCkShowAChannel();
	afx_msg void OnCkMonitorGamma();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD  m_numTxt;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVIEW_H__BD14F1B4_CE60_4EC7_BADF_6B4A030CCCE4__INCLUDED_)
