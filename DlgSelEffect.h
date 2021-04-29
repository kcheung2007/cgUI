#if !defined(AFX_DLGSELEFFECT_H__875C16F4_2003_4ED6_81E4_867DF1D0AC1A__INCLUDED_)
#define AFX_DLGSELEFFECT_H__875C16F4_2003_4ED6_81E4_867DF1D0AC1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelEffect.h : header file
//

#include "EffectBin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgSelEffect dialog

class CDlgSelEffect : public CDialog
{
// Construction
public:
	VOID InitDlgItemText();
	CDlgSelEffect(CWnd* pParent = NULL);   // standard constructor
	~CDlgSelEffect();

// Dialog Data
	//{{AFX_DATA(CDlgSelEffect)
	enum { IDD = IDD_SEL_EFFECT };
	CScrollBar	m_vsbEffectBin;
	CStatic	m_bmpTest;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelEffect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEffectBin m_ctlEffectBin;

	// Generated message map functions
	//{{AFX_MSG(CDlgSelEffect)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT*	m_hFont;
	DWORD	m_numTxt;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELEFFECT_H__875C16F4_2003_4ED6_81E4_867DF1D0AC1A__INCLUDED_)
