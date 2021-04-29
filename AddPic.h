#if !defined(AFX_ADDPIC_H__D965FCD8_F405_40DD_BCBA_ABFA0518564D__INCLUDED_)
#define AFX_ADDPIC_H__D965FCD8_F405_40DD_BCBA_ABFA0518564D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddPic dialog

class CAddPic : public CDialog
{
// Construction
public:
	VOID InitPictureInfo();
	CAddPic(CWnd* pParent = NULL);   // standard constructor
	~CAddPic();

// Dialog Data
	//{{AFX_DATA(CAddPic)
	enum { IDD = IDD_PIC_LOAD_OPT };
	CEdit	m_edWinSize;
	CButton	m_rbUpperRight;
	CButton	m_rbUpperCenter;
	CButton	m_rbUpperLeft;
	CButton	m_rbMiddleRight;
	CButton	m_rbMiddleLeft;
	CButton	m_rbMiddleCenter;
	CButton	m_rbBottomRight;
	CButton	m_rbBottomCenter;
	CButton	m_rbBottomLeft;
	CButton	m_ckPreAspect;
	CButton	m_ckBlackTrim;
	CButton	m_ckAChInvert;
	CButton	m_ckAChInclude;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddPic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddPic)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDeltaposSpnEdWin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusEdEdWinSize();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	PICTURE_LOAD_OPTIONS_INFO m_ploi;
	HFONT* m_hFont;
	DWORD  m_numTxt;
	VOID   InitDlgItemText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPIC_H__D965FCD8_F405_40DD_BCBA_ABFA0518564D__INCLUDED_)
