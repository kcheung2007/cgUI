#if !defined(AFX_ATTRIBFILL_H__70016A64_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
#define AFX_ATTRIBFILL_H__70016A64_DB1D_11D3_BF67_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribFill.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribFill dialog

class CAttribFill : public CDialog
{
// Construction
public:
	VOID	DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID	DeleteAttribFill();
	CAttribFill(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribFill)
	enum { IDD = IDD_ATTRIB_FILL };
	CEdit	m_ctlEdRound;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdWidth;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdHeight;
	CEdit	m_ctlEdBevel;
	CButton	m_btSaveStyle;
	CButton	m_btAdvance;
	CStatic	m_stcVPercent;
	CStatic	m_stcRoundness;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcWidth;
	CStatic	m_stcRotate;
	CStatic	m_stcHeight;
	CStatic	m_stcBevel;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	double	m_edBevel;
	double	m_edHeight;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edWidth;
	double	m_edX;
	double	m_edY;
	double	m_edRoundness;
	double	m_edVPercent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribFill)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribFill)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtFB();
	afx_msg void OnBtFF();
	afx_msg void OnBtFLock();
	afx_msg void OnBtFMinus();
	afx_msg void OnBtFPlus();
	afx_msg void OnDeltaposSpnFBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFWidth(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFY(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnDeltaposSpnHPercent(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnDeltaposSpnVPercent(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg void OnBtAdvance();
	afx_msg void OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBFILL_H__70016A64_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
