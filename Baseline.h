#if !defined(AFX_BASELINE_H__43BBF46F_91FC_4434_AFA1_5A3BCDCD7EB6__INCLUDED_)
#define AFX_BASELINE_H__43BBF46F_91FC_4434_AFA1_5A3BCDCD7EB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Baseline.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBaselne dialog

class CDlgBaselne : public CDialog
{
// Construction
public:
	VOID InitDlgItemTextNTooltip();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID DoValueUpdate();
	VOID DisableBaselineCircleGroup();
	VOID EnableBaselineCircleGroup();
	VOID DisableBaselineCurveGroup();
	VOID EnableBaselineCurveGroup();
	CDlgBaselne(CWnd* pParent = NULL);   // standard constructor
	~CDlgBaselne();

// Dialog Data
	//{{AFX_DATA(CDlgBaselne)
	enum { IDD = IDD_PAGE_BASELINE };
	CSpinButtonCtrl	m_spnY;
	CSpinButtonCtrl	m_spnX;
	CSpinButtonCtrl	m_spnCurvCtrl;
	CButton	m_rbTopRight;
	CButton	m_rbTopDown;
	CButton	m_rbRight;
	CButton	m_rbLine;
	CButton	m_rbLeft;
	CButton	m_rbJustify;
	CButton	m_rbCurve;
	CButton	m_rbCircle;
	CButton	m_rbCenter;
	CButton	m_rbBottomUp;
	CButton	m_rbAuto;
	CSpinButtonCtrl	m_spnCirRadius;
	CSpinButtonCtrl	m_spnCirAspect;
	CButton	m_rbIn;
	CButton	m_rbOut;
	CStatic	m_stcAlignCir;
	CStatic	m_stcCirAspect;
	CStatic	m_stcCirRadius;
	CStatic	m_stcCurvPoint;
	CButton	m_gpCurvCtrl;
	CButton	m_gpCirCtrl;
	CEdit	m_edY;
	CEdit	m_edX;
	CEdit	m_edRotation;
	CEdit	m_edMarginRight;
	CEdit	m_edMarginLeft;
	CEdit	m_edLneSpace;
	CEdit	m_edCurvCtrl;
	CEdit	m_edCirRadius;
	CEdit	m_edCirAspect;
	double	m_dbCirAspect;
	double	m_dbCirRadius;
	double	m_dbCurvCtrl;
	double	m_dbLineSpace;
	double	m_dbLeftMargin;
	double	m_dbRightMargin;
	double	m_dbRotate;
	long	m_edlX;
	long	m_edlY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBaselne)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
  	//{{AFX_MSG(CDlgBaselne)
	virtual BOOL OnInitDialog();
	afx_msg void OnRbLine();
	afx_msg void OnRbCurve();
	afx_msg void OnRbCircle();
	afx_msg void OnRbLeft();
	afx_msg void OnRbCenter();
	afx_msg void OnRbRight();
	afx_msg void OnRbJustify();
	afx_msg void OnRbAuto();
	afx_msg void OnRbTopRight();
	afx_msg void OnRbBottomUp();
	afx_msg void OnRbTopDown();
	afx_msg void OnBtCharPlus();
	afx_msg void OnBtCharMinus();
	afx_msg void OnRbOut();
	afx_msg void OnRbIn();
	afx_msg void OnBtDefault();
	afx_msg void OnDeltaposSpnAspect(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCurveCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnLneSpace(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnMarginLeft(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnMarginRight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnRadius(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnRotation(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnY(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID ControlOption();
	DWORD m_numTxt;
	HFONT* m_hFont;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASELINE_H__43BBF46F_91FC_4434_AFA1_5A3BCDCD7EB6__INCLUDED_)
