#if !defined(AFX_DLGLAYER_H__B079A4A1_C850_11D3_BFDF_005004648BC2__INCLUDED_)
#define AFX_DLGLAYER_H__B079A4A1_C850_11D3_BFDF_005004648BC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLayer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLayer dialog
class CLyImgBox : public CEdit
{
// Construction
public:
	CLyImgBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyImgBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLyImgBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPgImgBox)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint(); //JRS
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class CDlgLayer : public CDialog
{
// Construction
public:
	VOID InitDlgItemTextNTooltip();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	VOID ReSizeControl( CRect rcClient );
	CDlgLayer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLayer)
	enum { IDD = IDD_PAGE_LAYER };
	CEdit	m_ctlEdNum;
	CScrollBar	m_vsbLayer;
	CStatic	m_stcTotal;
	CButton	m_btPaste;
	CButton	m_btNewLayer;
	CButton	m_btMoveUp;
	CButton	m_btMoveDown;
	CButton	m_btDelete;
	CButton	m_btCopy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLayer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	CLyImgBox	m_ctlLyDlgImg;
	// Generated message map functions
	//{{AFX_MSG(CDlgLayer)
	afx_msg void OnBtNewLayer();
	afx_msg void OnBtMoveUp();
	afx_msg void OnBtMoveDown();
	afx_msg void OnBtCopyLayer();
	afx_msg void OnBtDelLayer();
	afx_msg void OnBtPasteLayer();
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLAYER_H__B079A4A1_C850_11D3_BFDF_005004648BC2__INCLUDED_)
