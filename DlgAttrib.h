#if !defined(AFX_DLGATTRIB_H__685BFBE1_D345_11D3_BF4E_005004648BC2__INCLUDED_)
#define AFX_DLGATTRIB_H__685BFBE1_D345_11D3_BF4E_005004648BC2__INCLUDED_

#include "IXTabCtrl.h"	// Added by ClassView
#include "AttribText.h"
#include "AttribBox.h"
#include "AttribLine.h"
#include "AttribCurve.h"
#include "AttribPolygon.h"
#include "AttribOval.h"
#include "AttribFill.h"
#include "DlgFace.h"
#include "DlgShadow.h"
#include "DlgCast.h"
#include "DlgOutline1.h"
#include "DlgOutline2.h"	// Added by ClassView
#include "IXFontCombo.h"	// Added by ClassView


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAttrib.h : header file
//

const UINT	ATT_NUMTAB    = 6;  // total number of tabs
const UINT	ATT_MAXTEXT	  = 20; // max. characters for tabs string

/////////////////////////////////////////////////////////////////////////////
// CDlgAttrib dialog

class CDlgAttrib : public CDialog
{
// Construction
public:
	CDlgFace*		GetFaceDlgPtr();
	CDlgCast*		GetCastDlgPtr();
	CDlgShadow*		GetShadowDlgPtr();
	CDlgOutline1*	GetOutline1DlgPtr();
	CDlgOutline2*	GetOutline2DlgPtr();

	void CreateAttribPage();
	CDlgAttrib(CWnd* pParent = NULL);   // standard constructor
	~CDlgAttrib();

// Dialog Data
	//{{AFX_DATA(CDlgAttrib)
	enum { IDD = IDD_PAGE_ATTRIB };
	CIXTabCtrl	m_ctlAttribTab;
	//}}AFX_DATA



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAttrib)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl	m_tooltip;
	CDlgCast*		m_pDlgCast;
	CDlgShadow*		m_pDlgShadow;
	CDlgOutline2*	m_pDlgOutline2;
	CDlgOutline1*	m_pDlgOutline1;
	CDlgFace*		m_pDlgFace;
	CImageList		m_imageAttribTab;
	// Generated message map functions
	//{{AFX_MSG(CDlgAttrib)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnClickTabAttrib(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickTabAttrib(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
private:	
	HFONT m_hFont;
	VOID	LoadTabString( );
	TCHAR	m_szTab[ATT_NUMTAB][ATT_MAXTEXT];	
//	CIXFontCombo m_ocbFont;	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGATTRIB_H__685BFBE1_D345_11D3_BF4E_005004648BC2__INCLUDED_)
