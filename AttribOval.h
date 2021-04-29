#if !defined(AFX_ATTRIBOVAL_H__545D3B74_1D85_44A8_A4D1_B5D70CAE49AC__INCLUDED_)
#define AFX_ATTRIBOVAL_H__545D3B74_1D85_44A8_A4D1_B5D70CAE49AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribOval.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribOval dialog

class CAttribOval : public CDialog
{
// Construction
public:
	VOID	DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID	DeleteAttribOval();
	CAttribOval(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribOval)
	enum { IDD = IDD_ATTRIB_OVAL };
	CEdit	m_ctlEdVPercent;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdWidth;
	CEdit	m_ctlEdSize;
	CEdit	m_ctlEdRoundness;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdBevel;
	CButton	m_btSaveStyle;
	CButton	m_btAdvance;
	CStatic	m_stcVPercent;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcWidth;
	CStatic	m_stcRotate;
	CStatic	m_stcSize;
	CStatic	m_stcBevel;
	CStatic	m_stcRoundness;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	double	m_edRoundness;
	double	m_edBevel;
	double	m_edSize;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edWidth;
	double	m_edX;
	double	m_edY;
	double	m_edVPercent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribOval)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribOval)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtOB();
	afx_msg void OnBtOF();
	afx_msg void OnBtOLock();
	afx_msg void OnBtOMinus();
	afx_msg void OnBtOPlus();
	afx_msg void OnDeltaposSpnOBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnORotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnDeltaposSpnRoundness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnOSize(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBOVAL_H__545D3B74_1D85_44A8_A4D1_B5D70CAE49AC__INCLUDED_)
