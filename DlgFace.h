#if !defined(AFX_DLGFACE_H__AA6EBB63_D383_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGFACE_H__AA6EBB63_D383_11D3_BF4E_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AlphaDlg.h"

// DlgFace.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFace dialog

class CDlgFace : public CDialog
{
// Construction
public:
	VOID HideControls();
	VOID UnCheckAlphaButton();
	BOOL GetAlphaState();
	VOID DoValueUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDlgFace(CWnd* pParent = NULL);   // standard constructor
	~CDlgFace();
// Dialog Data
	//{{AFX_DATA(CDlgFace)
	enum { IDD = IDD_PG_FACE };
	CButton	m_ckFaEnable;
	CStatic	m_stcFaceCK;
	CButton	m_ckFace;
	CSpinButtonCtrl	m_spnFeather;
	CEdit	m_ctlFeather;
	CStatic	m_stcFeather;
	CButton	m_btTranPal;
	CButton	m_btTranImp;
	CButton	m_btTranAlpha;
	CButton	m_btColPal;
	CButton	m_btColImp;
	DWORD	m_edFaTrans;
	DWORD	m_edFeather;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFace)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CDlgFace)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtTransPal();
	afx_msg void OnBtTransImport();
	afx_msg void OnBtTransAlpha();
	afx_msg void OnBtColorImport();
	afx_msg void OnBtColorPal();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpnFaFeather(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnCkFaEnable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT* m_hFont;
	DWORD m_numTxt;
	CAlphaDlg* m_pDlg;
	BOOL m_bAlpha;
	VOID InitStaticIcon();
	VOID InitEditSpinControl();
	VOID InitButtonIcon();
	VOID InitDlgItemTextNTooltip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFACE_H__AA6EBB63_D383_11D3_BF4E_005004648BC2__INCLUDED_)
