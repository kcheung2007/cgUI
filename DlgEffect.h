#if !defined(AFX_DLGEFFECT_H__2A53CB72_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_DLGEFFECT_H__2A53CB72_C54D_11D3_BFDB_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DlgEffect.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CEffectEdMm window

/////////////////////////////////////////////////////////////////////////////
// CDlgEffect dialog

class CDlgEffect : public CDialog
{
// Construction
public:
	VOID UpdateAllValue();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgEffect(CWnd* pParent = NULL);   // standard constructor
	~CDlgEffect();
	
// Dialog Data
	//{{AFX_DATA(CDlgEffect)
	enum { IDD = IDD_PAGE_EFFECT };
	CStatic	m_stcPic;
	DWORD	m_dwEdMm;
	DWORD	m_dwEdSc;
	DWORD	m_dwEdFm;
	DWORD	m_dwEdSpeed;
	DWORD	m_dwEdStart;
	DWORD	m_dwEdEnd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEffect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	// Generated message map functions
	//{{AFX_MSG(CDlgEffect)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtPlayProj();
	afx_msg void OnBtTake();
	afx_msg void OnBtFadeToVdo();
	afx_msg void OnBtLiveVdo();
	afx_msg void OnRbAllPage();
	afx_msg void OnRbPage();
	afx_msg void OnDeltaposSpnFm(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnMm(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSc(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnStcPicClick();
	afx_msg void OnBtStopPlay();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_numTxt;
	HFONT* m_hFont;
	VOID InitDlgItemTextNTooltip( );
};


/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEFFECT_H__2A53CB72_C54D_11D3_BFDB_005004648BC2__INCLUDED_)
