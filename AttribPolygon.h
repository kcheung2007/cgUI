#if !defined(AFX_ATTRIBPOLYGON_H__5E399340_2350_417B_BE59_F325C2E5C84E__INCLUDED_)
#define AFX_ATTRIBPOLYGON_H__5E399340_2350_417B_BE59_F325C2E5C84E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribPolygon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribPolygon dialog

class CAttribPolygon : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID DoValueUpdate();
	VOID DeleteAttribPoly();
	CAttribPolygon(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAttribPolygon)
	enum { IDD = IDD_ATTRIB_POLYGON };
	CEdit	m_ctlEdRoundness;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CEdit	m_ctlEdVertex;
	CEdit	m_ctlEdThick;
	CEdit	m_ctlEdRotate;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdLength;
	CEdit	m_ctlEdBevel;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcVertices;
	CStatic	m_stcThick;
	CStatic	m_stcRoundness;
	CStatic	m_stcRotate;
	CStatic	m_stcLength;
	CStatic	m_stcBevel;
	CButton	m_ckPolyFill;
	CButton	m_btSaveStyle;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btF;
	CButton	m_btB;
	CButton	m_btAdvance;
	double	m_edBevel;
	double	m_edLength;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edRoundness;
	double	m_edThick;
	double	m_edVertices;
	double	m_edX;
	double	m_edY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribPolygon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	virtual BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(CAttribPolygon)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtSaveStyle();
	afx_msg void OnBtAdvance();
	afx_msg void OnBtPLock();
	afx_msg void OnBtPF();
	afx_msg void OnBtPPlus();
	afx_msg void OnBtPMinus();
	afx_msg void OnBtPB();
	afx_msg void OnDeltaposSpnPBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPLength(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPRoundness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPThick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPVertices(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnPY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	BOOL m_LockState;
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBPOLYGON_H__5E399340_2350_417B_BE59_F325C2E5C84E__INCLUDED_)
