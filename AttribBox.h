#if !defined(AFX_ATTRIBBOX_H__70016A63_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
#define AFX_ATTRIBBOX_H__70016A63_DB1D_11D3_BF67_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribBox dialog

class CAttribBox : public CDialog
{
// Construction
public:
	VOID	DoValueUpdate();
	VOID	DeleteAttribBox();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CAttribBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribBox)
	enum { IDD = IDD_ATTRIB_BOX };
	CEdit	m_ctlEdRound;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdWidth;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdHeight;
	CEdit	m_ctlEdBevel;
	CButton	m_btAdvance;
	CButton	m_btSaveStyle;
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
	double	m_edRound;
	double	m_edVPercent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribBox)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtBB();
	afx_msg void OnBtBF();
	afx_msg void OnBtBLock();
	afx_msg void OnBtBMinus();
	afx_msg void OnBtBPlus();
	afx_msg void OnDeltaposSpnBBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBWidth(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnBY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnDeltaposSpnVPercent(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBBOX_H__70016A63_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
