#if !defined(AFX_PALDLG_H__D8E54D61_E3D0_11D3_BF6E_005004648BC2__INCLUDED_)
#define AFX_PALDLG_H__D8E54D61_E3D0_11D3_BF6E_005004648BC2__INCLUDED_

#include "PalSliderCtrl.h"	// Added by ClassView
#include "ImgPalBin.h"		// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PalDlg.h : header file
//

#define		MAX_BOX		220	// max number of color box

/////////////////////////////////////////////////////////////////////////////
// CPalDlg dialog

class CPalDlg : public CDialog
{
// Construction
public:
	INT GetTextModeIndex();
	VOID GetStyleColorBoxInfo();
	DWORD GetPaletteState();
	VOID SetPaletteState( DWORD buttonID );
	INT		m_SwapIndex;
	DWORD	m_Action;
	VOID	InitHorizScrollBar();
	VOID	InitButtonState();
	VOID	DrawColorBoxWnd();
	VOID	DrawSpreadColorBox();
	VOID	PalDibDrawTriangle(int xPos, int height, COLORREF Color32);
	VOID	PalDibDrawSelectedTriangle(int xPos, int height, COLORREF Color32);
	VOID	DrawTagFromDib();
	VOID	DrawBaseColorBox( );

	ALPHA_COLOR_BOX m_aColorBox;
	ALPHA_COLOR_BOX m_tmpColorBox;
	ALPHA_COLOR_BOX m_ColorBox[MAX_BOX];
	UINT			m_SpreadWidth;
	INT				m_PalDibHeight;
	INT				m_PalDibWidth;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CPalDlg(CWnd* pParent = NULL);   // standard constructor
	~CPalDlg();


// Dialog Data
	//{{AFX_DATA(CPalDlg)
	enum { IDD = IDD_DLG_PALETTE };
	CEdit	m_ctlEdR;
	CEdit	m_ctlEdG;
	CEdit	m_ctlEdB;
	CEdit	m_ctlEdRotate;
	CButton		m_rbRGB;
	CButton		m_rbHSV;
	CScrollBar	m_hsbRotate;
	CScrollBar	m_hsbR;
	CScrollBar	m_hsbG;
	CScrollBar	m_hsbB;
	CButton		m_btUndo;
	CButton		m_btSwap;
	CButton		m_btSpace;
	CButton		m_btSolid;
	CButton		m_btShift;
	CButton		m_btSave;
	CButton		m_btRedo;
	CButton		m_btOpen;
	CButton		m_btLinear;
	CButton		m_btInvert;
	CButton		m_btDelete;
	CButton		m_btCopy;
	CButton		m_btClear;
	CButton		m_btCircular;
	CButton		m_btAdd;
	CButton		m_bt4Point;
	DWORD		m_edB;
	DWORD		m_edG;
	DWORD		m_edR;
	DWORD		m_edRotate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPalSliderCtrl	m_ctlPalSld;
	CImgPalBin		m_ctlPalBin;
	CToolTipCtrl	m_tooltip;

	// Generated message map functions
	//{{AFX_MSG(CPalDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint(); //JRS 00-03-08
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBtPalAdd();
	afx_msg void OnBtPalDelete();
	afx_msg void OnBtPalCopy();
	afx_msg void OnBtPalClear();
	afx_msg void OnBtPalInvert();
	afx_msg void OnBtPalShift();
	afx_msg void OnBtPalSpace();
	afx_msg void OnBtPalSwap();
	afx_msg void OnBtPalUndo();
	afx_msg void OnBtPalRedo();
	afx_msg void OnBtPalLinear();
	afx_msg void OnBtPal4point();
	afx_msg void OnBtPalCircular();
	afx_msg void OnBtPalSolid();
	afx_msg void OnBtPalSave();
	afx_msg void OnBtPalOpen();
	afx_msg void OnRbRgb();
	afx_msg void OnRbHsv();
	afx_msg void OnClickOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	int m_idxPal;
	DWORD m_dwPalState;
	HFONT* m_hFont;
	DWORD m_numTxt;
	VOID RestoreColorBoxes();
	VOID BackupColorBoxes();
	BOOL CheckEditInputValue( DWORD flag, DWORD edValue);
	VOID OnHBlue( INT );
	VOID OnHGreen( INT );
	VOID OnHRed( INT );
	VOID OnHRotation( INT );
	DWORD	ConvertToARGB(COLORREF Color32);
	UINT	GetBiggestGapTagIndex( );	
	VOID	SetPALRotationHScroll();
	VOID	EnableRotationScrollBar();
	VOID	DisableRotationScrollBar();
	UINT	m_BPos;
	UINT	m_GPos;
	UINT	m_RPos;
	UINT	m_VPos;
	UINT	m_SPos;
	UINT	m_HPos;	
	VOID	InitButtonIcon();
	VOID	PalDibSetPixel(int X,int Y, int w, int h, DWORD Color32 );
	VOID	PalDibFillRect( INT w, INT h, DWORD Color32);
	VOID	InitDlgItemTextNTooltip();

	DWORD *m_PalDibSectionPtr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALDLG_H__D8E54D61_E3D0_11D3_BF6E_005004648BC2__INCLUDED_)
