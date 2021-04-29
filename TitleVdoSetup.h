#if !defined(AFX_TITLEVDOSETUP_H__67A3B9AB_8A05_4374_A81D_C7E47EEB5207__INCLUDED_)
#define AFX_TITLEVDOSETUP_H__67A3B9AB_8A05_4374_A81D_C7E47EEB5207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TitleVdoSetup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTitleVdoSetup dialog

class CTitleVdoSetup : public CDialog
{
// Construction
public:
	CTitleVdoSetup(CWnd* pParent = NULL);   // standard constructor
	~CTitleVdoSetup();

// Dialog Data
	//{{AFX_DATA(CTitleVdoSetup)
	enum { IDD = IDD_TITLE_VDO_SETUP };
	CEdit	m_ctlEdHDelay;
	CEdit	m_ctlEdContrast;
	CEdit	m_ctlEdBright;
	CSliderCtrl	m_sdrHDelay;
	CSliderCtrl	m_sdrContrast;
	CSliderCtrl	m_sdrBright;
	CComboBox	m_cbMode;
	CComboBox	m_cbGPIPort;
	CComboBox	m_cbOutFormat;
	CComboBox	m_cbInFormat;
	INT	m_edBright;
	INT	m_edContrast;
	INT	m_edHDelau;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleVdoSetup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
//	VOID InitComboString();
	VOID InitComboString( LPTSTR ptFn, LPTSTR ptSection, CComboBox* ptCombo );

	// Generated message map functions
	//{{AFX_MSG(CTitleVdoSetup)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnBright(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnConstrast(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnHdelay(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtDefault();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnChangeEdBright();
	afx_msg void OnChangeEdConstrast();
	afx_msg void OnChangeEdHdelay();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	HFONT m_hFontDelay;
	HFONT m_hFontConstrast;
	HFONT m_hFontBright;
	DWORD m_numTxt;
	VOID InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLEVDOSETUP_H__67A3B9AB_8A05_4374_A81D_C7E47EEB5207__INCLUDED_)
