#if !defined(AFX_DLGBARBOTTOM_H__F12BAE37_C546_11D3_BFDB_005004648BC2__INCLUDED_)
#define AFX_DLGBARBOTTOM_H__F12BAE37_C546_11D3_BFDB_005004648BC2__INCLUDED_

#include "IXTabCtrl.h"	// Added by ClassView
#include "DlgFilter.h"	// Added by ClassView
#include "DlgEffect.h"	// Added by ClassView
#include "DlgCapture.h"	// Added by ClassView
#include "DlgPreset.h"
#include "DlgAttrib.h"
#include "DlgView.h"
#include "DlgOutline1.h"	// Added by ClassView
#include "Baseline.h"
#include "DlgSelect.h"
#include "PgTemplate.h"

#include "Switch.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBarBottom.h : header file
//

//+++ Set to 0 for disable tab page
/*
const BOOL	PRESET    = 1;
const BOOL	CAPTURE   = 1;
const BOOL	VIDEO	  = 1;
const BOOL	EFFECT	  = 1;
const BOOL	BASELINE  = 1;
const BOOL	ATTRIBUTE =	1;
const BOOL  SELECTION = 1;
*/

/////////////////////////////////////////////////////////////////////////////
// CDlgBarBot dialog

class CDlgBarBot : public CDialogBar 
{
// Construction
public:
	CDlgBarBot();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarBot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
public:	
	CDlgSelect*	 GetSelectDlgPtr();
	CDlgBaselne* GetBaselinePtr();
	CDlgAttrib*  GetAttribDlgPtr();
	CDlgEffect*  GetEffectDlgPtr();
	CDlgCapture* GetCaptureDlgPtr();
	virtual void OnInitDialogBar();
	virtual ~CDlgBarBot();

	// Generated message map functions
	// We have manually added entry afx_msg InitDialogBarHandler
	// as it was not done automatically by Class Wizard

protected:	
	CIXTabCtrl		m_ctlTab;
	CDlgSelect*		m_pDlgSelect;
	CDlgBaselne*	m_pDlgBaseln;
	CDlgCapture*	m_pDlgCapture;
	CDlgEffect*		m_pDlgEffect;
	CDlgFilter*		m_pDlgFilter;
	CDlgPreset*		m_pDlgPreset;
	CDlgAttrib*		m_pDlgAttrib;
	CDlgView*		m_pDlgView;
	CPgTemplate*	m_pDlgTemplate;
	CImageList		m_imageListTab;

	
	//{{AFX_MSG(CDlgBarBot)
	afx_msg LRESULT InitDialogBarHandler( WPARAM wParam , LPARAM  lParam );
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HFONT	m_hFont;
	VOID	LoadTabString( );
	TCHAR	m_szTab[BAR_NUMTAB][BAR_MAXTEXT];	
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBARBOTTOM_H__F12BAE37_C546_11D3_BFDB_005004648BC2__INCLUDED_)
