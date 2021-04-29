#if !defined(AFX_ATTRIBTEXT_H__70016A61_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
#define AFX_ATTRIBTEXT_H__70016A61_DB1D_11D3_BF67_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttribText.h : header file
//

#include "IXTabCtrl.h"	// Added by ClassView
#include "IXFontCombo.h"	// Added by ClassView


/////////////////////////////////////////////////////////////////////////////
// CAttribText dialog

class CAttribText : public CDialog
{
// Construction
public:
	VOID ControlOption();
	VOID	DoValueUpdate();
	VOID	DeleteAttribText();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CAttribText(CWnd* pParent = NULL);   // standard constructor
	~CAttribText();

// Dialog Data
	//{{AFX_DATA(CAttribText)
	enum { IDD = IDD_ATTRIB_TEXT };
	CButton	m_btSaveStyle;
	CEdit	m_ctlEdWidth;
	CEdit	m_ctlEdSpace;
	CEdit	m_ctlEdKern;
	CEdit	m_ctlEdHeight;
	CSpinButtonCtrl	m_spnBevel;
	CEdit	m_ctlEdBevel;
	CSpinButtonCtrl	m_spnPriority;
	CSpinButtonCtrl	m_spnY;
	CSpinButtonCtrl	m_spnX;
	CEdit	m_ctlEdPriority;
	CEdit	m_ctlEdY;
	CEdit	m_ctlEdX;
	CSpinButtonCtrl	m_spnRotate;
	CEdit	m_ctlEdRotate;
	CButton	m_btAdvance;
	CButton	m_btFontList;
	CButton	m_btSubScript;
	CButton	m_btSuperScript;
	CStatic	m_stcY;
	CStatic	m_stcX;
	CStatic	m_stcWidth;
	CStatic	m_stcSpace;
	CStatic	m_stcRotate;
	CStatic	m_stcKern;
	CStatic	m_stcHeight;
	CStatic	m_stcBevel;
	CButton	m_rbUnderLne;
	CButton	m_rbItalic;
	CButton	m_rbBold;
	CButton	m_rbSmallCap;
	CButton	m_btPlus;
	CButton	m_btMinus;
	CButton	m_btLock;
	CButton	m_btForeGrd;
	CButton	m_btBackGrd;
	double	m_edBevel;
	double	m_edHeight;
	double	m_edKern;
	double	m_edPriority;
	double	m_edRotate;
	double	m_edSpace;
	double	m_edWidth;
	double	m_edX;
	double	m_edY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribText)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CAttribText)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtTBackGrd();
	afx_msg void OnBtTForeGrd();
	afx_msg void OnBtTLock();
	afx_msg void OnBtTMinus();
	afx_msg void OnBtTPlus();
	afx_msg void OnRbTBold();
	afx_msg void OnRbTItalic();
	afx_msg void OnRbTUnderlne();
	afx_msg void OnDeltaposSpnTBevel(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTHeight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTKern(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTPriority(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTRotate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTSpacing(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTWidth(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnTY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRbTSmallCap();
	afx_msg void OnPaint();
	afx_msg void OnChangeEdTSpace();
	afx_msg void OnSuperscript();
	afx_msg void OnSubscript();
	afx_msg void OnBtFontList();
	afx_msg void OnBtAdvance();
	afx_msg void OnBtSaveStyle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	BOOL m_LockState;
	VOID InitStaticIcon();
	VOID InitEditSpinControl();
	VOID InitRadioButtom();
	VOID InitFontCombo();
	BOOL m_bItalicState;
	BOOL m_bULState;
	BOOL m_bBoldState;
	BOOL m_bSmallCapState;
	BOOL m_bSubScriptState;
	BOOL m_bSuperScriptState;
	VOID InitDlgItemTextNTooltip();
	BOOL m_Lock;
	CIXFontCombo m_ocbFont;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBTEXT_H__70016A61_DB1D_11D3_BF67_005004648BC2__INCLUDED_)
