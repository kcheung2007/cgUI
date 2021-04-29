#if !defined(AFX_ATTRIBLINE_H__70016A62_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
#define AFX_ATTRIBLINE_H__70016A62_DB1D_11D3_BF67_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribLine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribLine dialog

class CAttribLine : public CDialog
{
// Construction
public:
	VOID	DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID	DeleteAttribLine();
	CAttribLine(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribLine)
	enum { IDD = IDD_ATTRIB_LINE };
	CEdit	m_ctlEdRoundness;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdThick;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdLength;
	CEdit	m_ctlEdBevel;
	CButton	m_btSaveStyle;
	CButton	m_btAdvance;
	CStatic	m_stcVPercent;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcThick;
	CStatic	m_stcRotate;
	CStatic	m_stcLength;
	CStatic	m_stcBevel;
	CStatic	m_stcRoundness;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	double	m_edBevel;
	double	m_edLength;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edThick;
	double	m_edX;
	double	m_edY;
	double	m_edVPercent;
	double	m_edRoundness;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribLine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribLine)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtLB();
	afx_msg void OnBtLF();
	afx_msg void OnBtLLock();
	afx_msg void OnBtLMinus();
	afx_msg void OnBtLPlus();
	afx_msg void OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLLength(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLThick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLY(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnDeltaposSpnVPercent(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBLINE_H__70016A62_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
