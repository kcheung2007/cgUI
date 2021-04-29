#if !defined(AFX_DLGCAST_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGCAST_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCast1.h : header file
//
#include "AlphaDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CDlgCast1 dialog

class CDlgCast : public CDialog
{
// Construction
public:
	VOID UnCheckAlphaButton();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgCast(CWnd* pParent = NULL);   // standard constructor
	~CDlgCast();

// Dialog Data
	//{{AFX_DATA(CDlgCast)
	enum { IDD = IDD_PG_CAST };
	CButton	m_ckCaEnable;
//	CStatic	m_stcCastCK;
	CButton	m_rbUpRight;
	CButton	m_rbUpLeft;
	CButton	m_rbUp;
	CButton	m_rbRight;
	CButton	m_rbLeft;
	CButton	m_rbDownRight;
	CButton	m_rbDownLeft;
	CButton	m_rbDown;
	CButton	m_rbCenter;
	CStatic	m_stcYOffset;
	CStatic	m_stcXOffset;
	CStatic	m_stcSize;
	CStatic	m_stcFeather;
	CButton	m_btTranPal;
	CButton	m_btTranImp;
	CButton	m_btTranAlpha;
	CButton	m_btColPal;
	CButton	m_btColImp;
	DWORD	m_edCaTrans;
	DWORD	m_edFeather;
	DWORD	m_edSize;
	DWORD	m_edXOffset;
	DWORD	m_edYOffset;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCast)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CDlgCast)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtColorImport();
	afx_msg void OnBtColorPal();
	afx_msg void OnBtTransImport();
	afx_msg void OnBtTransAlpha();
	afx_msg void OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnCaFeather(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCaSize(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCaXOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnCaYOffset(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtTransPalCa();
	afx_msg void OnRbCaDirectUL();
	afx_msg void OnRbCaDirectU();
	afx_msg void OnRbCaDirectUR();
	afx_msg void OnRbCaDirectL();
	afx_msg void OnRbCaDirectC();
	afx_msg void OnRbCaDirectR();
	afx_msg void OnRbCaDirectDL();
	afx_msg void OnRbCaDirectD();
	afx_msg void OnRbCaDirectDR();
	afx_msg void OnPaint();
	afx_msg void OnCkCaEnable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	VOID SetDirectionButton( int );
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

#endif // !defined(AFX_DLGCAST_H__AA6EBB61_D383_11D3_BF4E_005004648BC2__INCLUDED_)
