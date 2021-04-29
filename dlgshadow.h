#if !defined(AFX_DLGSHADOW_H__AA6EBB66_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGSHADOW_H__AA6EBB66_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgShadow.h : header file
//
#include "AlphaDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgShadow dialog

class CDlgShadow : public CDialog
{
// Construction
public:
	VOID UnCheckAlphaButton();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgShadow(CWnd* pParent = NULL);   // standard constructor
	~CDlgShadow();

// Dialog Data
	//{{AFX_DATA(CDlgShadow)
	enum { IDD = IDD_PG_SHADOW };
	CButton	m_ckSdEnable;
//	CStatic	m_stcShadowCK;
	CButton	m_rbUpRight;
	CButton	m_rbUp;
	CButton	m_rbLeft;
	CButton	m_rbUpLeft;
	CButton	m_rbRight;
	CButton	m_rbDownRight;
	CButton	m_rbDownLeft;
	CButton	m_rbDown;
	CButton	m_rbCenter;
	CStatic	m_stcFeather;
	CStatic	m_stcYOffset;
	CStatic	m_stcXOffset;
	CStatic	m_stcSize;
	CButton	m_btTranPal;
	CButton	m_btTranImp;
	CButton	m_btTranAlpha;
	CButton	m_btColPal;
	CButton	m_btColImp;
	DWORD	m_edSdTrans;
	DWORD	m_edXOffset;
	DWORD	m_edYOffset;
	DWORD	m_edFeather;
	DWORD	m_edSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShadow)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CDlgShadow)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnFeather(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnSize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnXOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnYOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtColImpSd();
	afx_msg void OnBtColPalSd();
	afx_msg void OnBtTransAlphaSd();
	afx_msg void OnBtTransImpSd();
	afx_msg void OnBtTransPalSd();
	afx_msg void OnRbDirectUL();
	afx_msg void OnRbDirectU();
	afx_msg void OnRbDirectUR();
	afx_msg void OnRbDirectL();
	afx_msg void OnRbDirectC();
	afx_msg void OnRbDirectR();
	afx_msg void OnRbDirectDL();
	afx_msg void OnRbDirectD();
	afx_msg void OnRbDirectDR();
	afx_msg void OnPaint();
	afx_msg void OnCkShadow();
	afx_msg void OnCkSdEnable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID SetDirection( int direction );
	CAlphaDlg* m_pDlg;
	HFONT* m_hFont;
	DWORD m_numTxt;
	BOOL m_bAlpha;
	VOID InitRadioButton();
	VOID InitStaticIcon();
	VOID InitEditSpinControl();
	VOID InitButtonIcon();
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHADOW_H__AA6EBB66_D383_11D3_BF4E_005004648BC2__INCLUDED_)
