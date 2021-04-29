/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// PalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "PalDlg.h"
#include "Global.h"
#include "ACGS_Inc\\CG_ColorBox.h"
#include "FileReq.h"
#include "ACGS_Inc\\UI_BinMgr.h" //JRS 00-03-08
/* 00-03-08
BIN SUPPORT FUNCTIONS YOU CAN CALL:
CGS_FUNC void CGS_BinRefresh(int BinItemType);// call for bin window's OnPaint (else,only when really needed)
CGS_FUNC void CGS_BinSelect(int BinItemType,int ViewX,int ViewY); //for OnMouseDown
CGS_FUNC void CGS_BinSelectItem(int BinItemType,int ItemIndex); //Logically  select an item (if you need too)
CGS_FUNC int CGS_BinGetSelectedIndex(int BinItemType);//get the index 0..n of the currently selected item in the bin (i.e. the current colorbox)
CGS_FUNC BOOL CGS_BinGetItemData(int BinItemType,int ItemIndex,void *CopyPtr);//Copy a palette color box ALPHA_COLOR_BOX structure from bin to modify locally
CGS_FUNC BOOL CGS_BinSetItemData(int BinItemType,int ItemIndex,void *CopyPtr)//Copy your ALPHA_COLOR_BOX structure to REPLACE an item in the bin (also redisplays affected item in bin)
CGS_FUNC int CGS_BinGetIndexAt(int BinItemType,int ViewX,int ViewY); //esp for copy colorbox from/to operations

Mainly These:
CGS_FUNC int CGS_BinGetSelectedIndex(int BinItemType);//get the index 0..n of the currently selected item in the bin (i.e. the current colorbox)
CGS_FUNC BOOL CGS_BinGetItemData(int BinItemType,int ItemIndex,void *CopyPtr);//Copy a palette color box ALPHA_COLOR_BOX structure from bin to modify locally
CGS_FUNC BOOL CGS_BinSetItemData(int BinItemType,int ItemIndex,void *CopyPtr)//Copy your ALPHA_COLOR_BOX structure to REPLACE an item in the bin (also redisplays affected item in bin)

for color preview windows:
CGS_FUNC void CGS_RenderColorboxToWindow(void *ColorBox,DWORD Hwnd) //for large square color box
CGS_FUNC void CGS_RenderColorboxAsSpreadBarToWindow(void *ColorBox,DWORD Hwnd)//draw the rectangular spread bar in spread tab control
*/

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CPalDlg dialog
#define		TAG_HEIGHT			9	// height of tag
#define		TAG_HALF_WIDTH		4	// 1/2 width of tag, equal side triangle

extern	TCHAR	UILang_UIFont[256];
extern	int		UILang_UIFontSize;

CPalDlg::CPalDlg(CWnd* pParent /*=NULL*/) : CDialog(CPalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPalDlg)
	m_Action = 0;
	m_edB = 0;
	m_edG = 0;
	m_edR = 0;
	m_edRotate = 0;
	//}}AFX_DATA_INIT
	m_hFont = NULL;
}

CPalDlg::~CPalDlg()
{
	if( m_hFont != NULL )
	{
		for( DWORD i = 0; i < m_numTxt; i++ )
		{
			if( m_hFont[i] != NULL )
				DeleteObject( (HGDIOBJ)m_hFont[i] );

			m_hFont[i] = NULL;
		}
		if( m_hFont != NULL )
		{
			delete [] m_hFont;
			m_hFont = NULL;
		}
	}//end of if - m_hFont
}

void CPalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPalDlg)
	DDX_Control(pDX, IDC_ED_R, m_ctlEdR);
	DDX_Control(pDX, IDC_ED_G, m_ctlEdG);
	DDX_Control(pDX, IDC_ED_B, m_ctlEdB);
	DDX_Control(pDX, IDC_ED_ROTATE, m_ctlEdRotate);
	DDX_Control(pDX, IDC_RB_RGB, m_rbRGB);
	DDX_Control(pDX, IDC_RB_HSV, m_rbHSV);
	DDX_Control(pDX, IDC_HSB_ROTATE, m_hsbRotate);
	DDX_Control(pDX, IDC_HSB_R, m_hsbR);
	DDX_Control(pDX, IDC_HSB_G, m_hsbG);
	DDX_Control(pDX, IDC_HSB_B, m_hsbB);
	DDX_Control(pDX, IDC_BT_PAL_UNDO, m_btUndo);
	DDX_Control(pDX, IDC_BT_PAL_SWAP, m_btSwap);
	DDX_Control(pDX, IDC_BT_PAL_SPACE, m_btSpace);
	DDX_Control(pDX, IDC_BT_PAL_SOLID, m_btSolid);
	DDX_Control(pDX, IDC_BT_PAL_SHIFT, m_btShift);
	DDX_Control(pDX, IDC_BT_PAL_SAVE, m_btSave);
	DDX_Control(pDX, IDC_BT_PAL_REDO, m_btRedo);
	DDX_Control(pDX, IDC_BT_PAL_OPEN, m_btOpen);
	DDX_Control(pDX, IDC_BT_PAL_LINEAR, m_btLinear);
	DDX_Control(pDX, IDC_BT_PAL_INVERT, m_btInvert);
	DDX_Control(pDX, IDC_BT_PAL_DELETE, m_btDelete);
	DDX_Control(pDX, IDC_BT_PAL_COPY, m_btCopy);
	DDX_Control(pDX, IDC_BT_PAL_CLEAR, m_btClear);
	DDX_Control(pDX, IDC_BT_PAL_CIRCULAR, m_btCircular);
	DDX_Control(pDX, IDC_BT_PAL_ADD, m_btAdd);
	DDX_Control(pDX, IDC_BT_PAL_4POINT, m_bt4Point);
	DDX_Text(pDX, IDC_ED_B, m_edB);
	DDV_MinMaxDWord(pDX, m_edB, 0, 255);
	DDX_Text(pDX, IDC_ED_G, m_edG);
	DDV_MinMaxDWord(pDX, m_edG, 0, 255);
	DDX_Text(pDX, IDC_ED_R, m_edR);
	DDV_MinMaxDWord(pDX, m_edR, 0, 359);
	DDX_Text(pDX, IDC_ED_ROTATE, m_edRotate);
	DDV_MinMaxDWord(pDX, m_edRotate, 0, 359);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPalDlg, CDialog)
	//{{AFX_MSG_MAP(CPalDlg)
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BT_PAL_ADD, OnBtPalAdd)
	ON_BN_CLICKED(IDC_BT_PAL_DELETE, OnBtPalDelete)
	ON_BN_CLICKED(IDC_BT_PAL_COPY, OnBtPalCopy)
	ON_BN_CLICKED(IDC_BT_PAL_CLEAR, OnBtPalClear)
	ON_BN_CLICKED(IDC_BT_PAL_INVERT, OnBtPalInvert)
	ON_BN_CLICKED(IDC_BT_PAL_SHIFT, OnBtPalShift)
	ON_BN_CLICKED(IDC_BT_PAL_SPACE, OnBtPalSpace)
	ON_BN_CLICKED(IDC_BT_PAL_SWAP, OnBtPalSwap)
	ON_BN_CLICKED(IDC_BT_PAL_UNDO, OnBtPalUndo)
	ON_BN_CLICKED(IDC_BT_PAL_REDO, OnBtPalRedo)
	ON_BN_CLICKED(IDC_BT_PAL_LINEAR, OnBtPalLinear)
	ON_BN_CLICKED(IDC_BT_PAL_4POINT, OnBtPal4point)
	ON_BN_CLICKED(IDC_BT_PAL_CIRCULAR, OnBtPalCircular)
	ON_BN_CLICKED(IDC_BT_PAL_SOLID, OnBtPalSolid)
	ON_BN_CLICKED(IDC_BT_PAL_SAVE, OnBtPalSave)
	ON_BN_CLICKED(IDC_BT_PAL_OPEN, OnBtPalOpen)
	ON_BN_CLICKED(IDC_RB_RGB, OnRbRgb)
	ON_BN_CLICKED(IDC_RB_HSV, OnRbHsv)
	ON_BN_CLICKED(IDC_OK, OnClickOk)
//	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPalDlg message handlers
BOOL CPalDlg::OnInitDialog() 
{
	TRACE0("PalDlg.cpp : CPalDlg::OnInitDialog\n");
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// ++++++++++++++++++++++++++++++++++++++ SubClass the Pal bin
	m_ctlPalBin.SubclassDlgItem( IDC_LIST_PAL_BIN, this );
	m_ctlPalSld.SubclassDlgItem( IDC_LIST_TAG, this );

	// +++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	InitDlgItemTextNTooltip(); // seting both tooltip and dialog item text

	// ++++++++++++++++++++++++++++++++++++++++++++++ Open Bin
	//01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
	CGS_BinOpen(
				UIBIN_PALETTE_MENU,
				m_ctlPalBin.m_hWnd,
				NULL,
				NULL 
			);

	GetStyleColorBoxInfo();

/*** 01-06-10 save for reference - del after 3 months without problem
	int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
	CGS_BinGetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box to local
	HWND hCtrl = GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;			
	CGS_RenderColorboxToWindow( &m_aColorBox, (DWORD)hCtrl,0);		// draw color box info
	hCtrl = GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
	CGS_RenderColorboxAsSpreadBarToWindow( &m_aColorBox, (DWORD)hCtrl );
**** save forreference - del after 3 months ***/

	// after copy the color box to local do:
	InitButtonIcon();
	InitButtonState();
	InitHorizScrollBar();
	DrawBaseColorBox();
	DrawTagFromDib();

	BackupColorBoxes();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CPalDlg::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
//JRS 00-03-08 Added the following OnPaint() function
void CPalDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	TRACE0("CPalDlg::OnPaint()\n");

	DrawTagFromDib();
	DrawBaseColorBox( );

	HWND hCtrl = GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;
	CGS_RenderColorboxToWindow( &m_aColorBox, (DWORD)hCtrl,0);
	hCtrl = GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
	CGS_RenderColorboxAsSpreadBarToWindow( &m_aColorBox, (DWORD)hCtrl );

	// Do not call CEdit::OnPaint() for painting messages
}//end of CPalDlg::OnPaint()
/////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnOK() 
{
	DWORD	edValue = GetDlgItemInt( IDC_ED_ROTATE, NULL, 0 );
	if( CheckEditInputValue(IDC_ED_ROTATE, edValue) )
		return;
	if( edValue != m_edRotate )
	{
		m_edRotate = edValue;
		m_hsbRotate.SetScrollPos( m_edRotate );
		OnHRotation( m_edRotate );
		TRACE( _T("\t m_dwEdRotate = %d\n"), m_edRotate );
	}
	edValue = GetDlgItemInt( IDC_ED_R, NULL, 0 );
	if( CheckEditInputValue(IDC_ED_R, edValue) )
		return;
	if( edValue != m_edR )
	{
		m_edR = edValue;
		m_hsbR.SetScrollPos( m_edR );
		OnHRed( m_edR );
		TRACE( _T("\t m_edR = %d\n"), m_edR );
	}
	edValue = GetDlgItemInt( IDC_ED_G, NULL, 0 );
	if( CheckEditInputValue(IDC_ED_G, edValue) )
		return;
	if( edValue != m_edG )
	{
		m_edG = edValue;
		m_hsbG.SetScrollPos( m_edG );
		OnHGreen( m_edG );
		TRACE( _T("\t m_edG = %d\n"), m_edG );
	}
	edValue = GetDlgItemInt( IDC_ED_B, NULL, 0 );
	if( CheckEditInputValue(IDC_ED_B, edValue) )
		return;
	if( edValue != m_edB )
	{
		m_edB = edValue;
		m_hsbB.SetScrollPos( m_edB );
		OnHBlue( m_edB );
		TRACE( _T("\t m_edB = %d\n"), m_edB );
	}

	CWnd* pEdWnd = GetFocus(); //++++++++++++++= Handle the focus
	if( *pEdWnd == m_ctlEdRotate )
		m_ctlEdR.SetFocus();
	else
		if( *pEdWnd == m_ctlEdR )
			m_ctlEdG.SetFocus();
	else
		if( *pEdWnd == m_ctlEdG )
			m_ctlEdB.SetFocus();
	else
		if( *pEdWnd == m_ctlEdB )
		{					
			if( m_ctlEdRotate.IsWindowEnabled() )
				m_ctlEdRotate.SetFocus();
			else
				m_ctlEdR.SetFocus();
		}//end of if 

	DrawTagFromDib();	// +++++++ Update drawing
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
	{
		CGS_SetDataItem( m_idxPal, &m_aColorBox );
	}

	CDialog::OnOK();
}//end of CDialog::OnOK()
/////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnCancel() 
{
	CDialog::OnCancel();
	RestoreColorBoxes();
}//end of CPalDlg::OnCancel
/////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	ASSERT(pScrollBar != NULL);

	int nMaxBot = 255;
	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_ROTATE) ||
		pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_R) )
		nMaxBot = 359;

	int nCurPos = pScrollBar->GetScrollPos();
	switch( nSBCode )
	{
	case SB_TOP:			// Scroll to far top.
		nCurPos = 1;
		break;
	case SB_LINEUP:			// Scroll one line up.
		nCurPos--;
		break;
	case SB_LINEDOWN:		// Scroll one line down.
		nCurPos++;
		break;
	case SB_PAGEUP:			// Scroll one page up.
		nCurPos -= 10;
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		nCurPos += 10;
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = nMaxBot;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll		
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 0 ) ? 0 : nCurPos;
	nCurPos = ( nMaxBot < nCurPos ) ? nMaxBot : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

	TRACE1( "PalDlg.cpp : OnHScroll - nPos = %d\n", nCurPos );
	if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_ROTATE) )
		OnHRotation( nCurPos );
	else
		if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_R) )
			OnHRed( nCurPos );
	else
		if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_G) )
			OnHGreen( nCurPos );
	else
		if( pScrollBar == (CScrollBar*)GetDlgItem(IDC_HSB_B) )
			OnHBlue( nCurPos );
	
	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}//end of CPalDlg::OnHScroll
/////////////////////////////////////////////////////////////////////////////
BOOL CPalDlg::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CPalDlg::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::InitDlgItemTextNTooltip()
{	
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	HFONT		hFont = NULL;

	m_numTxt = LoadTextFromCtl( "\\Util\\PalDlg.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		m_hFont[i] = NULL;
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_OPEN") ) )
			txtData[i].idTT = IDC_BT_PAL_OPEN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_SAVE") ) )
				txtData[i].idTT = IDC_BT_PAL_SAVE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_UNDO") ) )
				txtData[i].idTT = IDC_BT_PAL_UNDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_REDO") ) )
				txtData[i].idTT = IDC_BT_PAL_REDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_SOLID") ) )
				txtData[i].idTT = IDC_BT_PAL_SOLID;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_LINEAR") ) )
				txtData[i].idTT = IDC_BT_PAL_LINEAR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_CIRCULAR") ) )
				txtData[i].idTT = IDC_BT_PAL_CIRCULAR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_4POINT") ) )
				txtData[i].idTT = IDC_BT_PAL_4POINT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_COPY") ) )
				txtData[i].idTT = IDC_BT_PAL_COPY;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_SWAP") ) )
				txtData[i].idTT = IDC_BT_PAL_SWAP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_ADD") ) )
				txtData[i].idTT = IDC_BT_PAL_ADD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_DELETE") ) )
				txtData[i].idTT = IDC_BT_PAL_DELETE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_CLEAR") ) )
				txtData[i].idTT = IDC_BT_PAL_CLEAR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_SPACE") ) )
				txtData[i].idTT = IDC_BT_PAL_SPACE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_SHIFT") ) )
				txtData[i].idTT = IDC_BT_PAL_SHIFT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_INVERT") ) )
				txtData[i].idTT = IDC_BT_PAL_INVERT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_UNDO") ) )
				txtData[i].idTT = IDC_BT_PAL_UNDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PAL_REDO") ) )
				txtData[i].idTT = IDC_BT_PAL_REDO;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_HSB_ROTATE") ) )
				txtData[i].idTT = IDC_HSB_ROTATE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_HSB_R") ) )
				txtData[i].idTT = IDC_HSB_R;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_HSB_G") ) )
				txtData[i].idTT = IDC_HSB_G;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_HSB_B") ) )
				txtData[i].idTT = IDC_HSB_B;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_VDO_SAFE") ) )
				txtData[i].idTT = IDC_VDO_SAFE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CUR_COLOR") ) )
				txtData[i].idTT = IDC_STC_CUR_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ROTATE") ) )
				txtData[i].idTT = IDC_STC_ROTATE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_BASE_COLOR") ) )
				txtData[i].idTT = IDC_STC_BASE_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_ROTATE") ) )
			{
				txtData[i].idTT = IDC_ED_ROTATE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_R") ) )
			{
				txtData[i].idTT = IDC_ED_R;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_G") ) )
			{
				txtData[i].idTT = IDC_ED_G;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_B") ) )
			{
				txtData[i].idTT = IDC_ED_B;
				goto SKIP_TEXT;
			}

		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );

SKIP_TEXT:
		_tcscpy( txtData[i].szTT, txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (TCHAR*)ptTT);
	}//end of for

//	delete txtData;
	free( txtData );

}//end of CPalDlg::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////////
// 1) Get the index of color box
// 2) Copy the color box info to local memory variable
// 3) Draw to color box, spread bar and base color box
void CPalDlg::OnLButtonUp(UINT nFlags, CPoint pt) 
{	
	TRACE2("PalDlg.cpp : CPalDlg::OnLButtonUp - x = %d, y = %d\n", pt.x, pt.y );

	CDialog::OnLButtonUp(nFlags, pt);
}//end of CPalDlg::OnLButtonUp
///////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::DrawBaseColorBox( )
{
	BOOL		rv;
	HBITMAP		hBmp;
	HBITMAP		hOldBmp;
	HDC			hDC;
	HDC			hMemDC;
	HWND		hBaseBox = GetDlgItem( IDC_FRM_BASE_COLOR )->m_hWnd;
	RECT		rcBaseBox;

	::GetWindowRect( hBaseBox, &rcBaseBox );
	int g_PalDibWidth  = rcBaseBox.right - rcBaseBox.left;
	int g_PalDibHeight = rcBaseBox.bottom - rcBaseBox.top;
	rcBaseBox.left = 0;
	rcBaseBox.top  = 0;

	BITMAPINFOHEADER		bmpHeader;

	bmpHeader.biSize        = sizeof( BITMAPINFOHEADER );
	bmpHeader.biWidth       = g_PalDibWidth;
	bmpHeader.biHeight      = -g_PalDibHeight;
	bmpHeader.biPlanes      = 1;
	bmpHeader.biBitCount    = 32;
	bmpHeader.biCompression = BI_RGB;
	bmpHeader.biSizeImage   = g_PalDibWidth * g_PalDibHeight * sizeof(DWORD);


	hDC     = ::GetDC( hBaseBox );	// DC of base color box reference to screen memory
	hMemDC  = CreateCompatibleDC( hDC ); // DC of base color box reference to offscreen memory
	hBmp    = CreateDIBSection( hMemDC,
								(BITMAPINFO *)&(bmpHeader),
								DIB_RGB_COLORS,
								(void **)&(m_PalDibSectionPtr),
								NULL, 0 );

	hOldBmp = (HBITMAP)::SelectObject( hMemDC, hBmp );
	PalDibFillRect( g_PalDibWidth, g_PalDibHeight, m_aColorBox.details.spread.color[m_aColorBox.details.spread.current_tab_index] );	
	rv = BitBlt( hDC, 0, 0, g_PalDibWidth, g_PalDibHeight, hMemDC, 0, 0, SRCCOPY );

	hBmp = (HBITMAP)SelectObject( hMemDC, hOldBmp );

	DeleteObject( hBmp );
	DeleteDC( hMemDC );
	::ReleaseDC( hBaseBox, hDC );
}//end of CPalDlg::DrawBaseColorBox()
///////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::PalDibFillRect(INT w, INT h, DWORD Color32)
{
	DWORD	color32 = ConvertToARGB( Color32 );
	for( int y = 0; y < h; y++ )
		for( int x = 0; x < w; x++ )
			PalDibSetPixel(x, y, w, h, color32 );

}//end of CPalDlg::PalDibFillRect
/////////////////////////////////////////////////////////////////////////////////////////////////////
DWORD CPalDlg::ConvertToARGB(COLORREF Color32)
{
 	DWORD color;
 	DWORD red  = Color32 & 0x000000FF;
 	DWORD blue = Color32 & 0x00FF0000;
 
 	color = Color32 & 0xFF00FF00; //clear red and blue
 	color = color | (red << 16) | (blue >> 16);
 
 	return( color );
}//end of CPalDlg::ConvertToARGB
///////////////////////////////////////////////////////////////////////////////////////////////////
// Directly assign a 32 bits pixel info in format of 0xaArRgGbB which is different
// to MS's COLORREF (0x00bbggrr).
// INPUT : int X - x coordinate
// INPUT : int Y - y coordinate
// INPUT : int w - horizontal length or ending point of x
// INPUT : int h - verticle length or ending point of y
// INPUT : DWORD Color32 - 32 bits pixel (Different to COLORREF)
VOID CPalDlg::PalDibSetPixel(int X, int Y, int w, int h, DWORD Color32)
{
	//Clip pixel to valid bitmap addressing
	if( (X < 0) || (w <= X) )
		return;

	if( (Y < 0) || (h <= Y) )
		return;

	//calc DWORD offset of pixel (byte address would be DWORD offset * 4L
	DWORD DwordAddrOffset = ( Y * w ) + X;
	*(m_PalDibSectionPtr + DwordAddrOffset) = Color32;
}//end of VOID PalDibSetPixel
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::InitButtonIcon()
{
	m_btOpen.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OPEN),      IMAGE_ICON, 16, 16, 0) );
	m_btSave.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_SAVE),      IMAGE_ICON, 16, 16, 0) );
	m_btRedo.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_REDO),      IMAGE_ICON, 16, 16, 0) );
	m_btUndo.SetIcon(     (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_UNDO),      IMAGE_ICON, 16, 16, 0) );
	m_btAdd.SetIcon(      (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_ADD),   IMAGE_ICON, 16, 16, 0) );
	m_btShift.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_SHIFT), IMAGE_ICON, 16, 16, 0) );
	m_btInvert.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_INVERT),IMAGE_ICON, 16, 16, 0) );
	m_btDelete.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_SUB),   IMAGE_ICON, 16, 16, 0) );
	m_btClear.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_CLEAR), IMAGE_ICON, 16, 16, 0) );
	m_btSpace.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_TAG_SPACE), IMAGE_ICON, 16, 16, 0) );
	m_bt4Point.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_4POINT),    IMAGE_ICON, 16, 16, 0) );
	m_btCircular.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_CIRCULAR),  IMAGE_ICON, 16, 16, 0) );
	m_btSolid.SetIcon(    (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_SOLID),     IMAGE_ICON, 16, 16, 0) );
	m_btLinear.SetIcon(   (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_LINEAR),    IMAGE_ICON, 16, 16, 0) );
}//end of CPalDlg::InitButtonIcon()
////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::InitHorizScrollBar()
{

	BYTE		curTag = m_aColorBox.details.spread.current_tab_index;
	COLORREF	color  = m_aColorBox.details.spread.color[curTag];
	UINT		minHSV = 0;		// min. range of H scroll bar of HSV
	UINT		maxHSV = 359;	// max. range of H scroll bar of HSV
	UINT		minRGB = 0;		// min. range of scroll bar for RGB
	UINT		maxRGB = 255;	// max. range of scroll bar for RGB
	HWND		hPALPanel = this->m_hWnd;

	INT rPos = color & 0x000000FF;
	INT gPos = (color & 0x0000FF00) >> 8;
	INT bPos = (color & 0x00FF0000) >> 16;

	m_hsbRotate.SetScrollRange( 0, 359 );
	m_hsbRotate.SetScrollPos( 180 );

	if( 1 == m_rbHSV.GetCheck() )
	{
		ColorConversion( RGB_MODE, HSV_MODE, &rPos, &gPos, &bPos );

		m_hsbR.SetScrollRange( minHSV, maxHSV ); // default range for HSV
		m_hsbR.SetScrollPos( rPos );
		::SetDlgItemInt( hPALPanel, IDC_ED_R, rPos, 0 );
	}
	else
	{	
		m_hsbR.SetScrollRange( minRGB, maxRGB ); // default range for RGB
		m_hsbR.SetScrollPos( rPos );
		::SetDlgItemInt( hPALPanel, IDC_ED_R, rPos, 0 );
	}

	m_hsbG.SetScrollRange( minRGB, maxRGB ); // default range for HSV
	m_hsbG.SetScrollPos( gPos );
	::SetDlgItemInt( hPALPanel, IDC_ED_G, gPos, 0 );

	m_hsbB.SetScrollRange( minRGB, maxRGB ); // default range for HSV
	m_hsbB.SetScrollPos( bPos );
	::SetDlgItemInt( hPALPanel, IDC_ED_B, bPos, 0 );

	switch( m_aColorBox.details.spread.spread_type )
	{
	case LINEAR_SPREAD_TYPE:
		if( BST_CHECKED == m_btSolid.GetCheck() )
			DisableRotationScrollBar();
		else
		{
			SetPALRotationHScroll();
			EnableRotationScrollBar();
		}	
		break;
	case CONCENTRIC_SPREAD_TYPE:
		DisableRotationScrollBar();
		break;
	case FOUR_PT_SPREAD_TYPE:
		DisableRotationScrollBar();
		break;
	}//end of switch

}//end of CPalDlg::InitHorizScrollBar()
//////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::DisableRotationScrollBar()
{
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_STC_ROTATE), 0 );
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_HSB_ROTATE), 0 );
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_ED_ROTATE),  0 );

}//end of CPalDlg::DisableRotationScrollBar()
//////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::EnableRotationScrollBar()
{
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_STC_ROTATE), 1 );
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_HSB_ROTATE), 1 );
	::EnableWindow( ::GetDlgItem(this->m_hWnd, IDC_ED_ROTATE),  1 );

}//end of CPalDlg::EnableRotationScrollBar()
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Initial the third part of base color group
// 1) Read the initial vales form data structure??? or file ???
// 2) Set the scroll bar range
// 3) Set the scroll bar thumb position
// 4) Set the edit boxes
VOID CPalDlg::SetPALRotationHScroll()
{
	HWND	hDlg = this->m_hWnd;
	UINT	nMin = 0;	// min. range of scroll bar
	UINT	nMax = 359; // max. range of scroll bar
	UINT	nPos = 0;	// position of scroll box 

//	g_GrdPos = m_aColor.details.spread.spread_angle;
//	nPos = g_GrdPos;

	nPos = m_aColorBox.details.spread.spread_angle;
//	SetScrollRange( GetDlgItem(hDlg, IDC_HSB_ROTATE), SB_CTL, nMin, nMax, 1 );	
	::SetScrollPos( ::GetDlgItem(hDlg, IDC_HSB_ROTATE), SB_CTL, nPos, 1 );
	::SetDlgItemInt( hDlg, IDC_ED_ROTATE, nPos, 1 );
}//end of CPalDlg::SetPALRotationHScroll()
///////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::InitButtonState()
{
	// +++++++++ Init solid, 4 point, linear and circular button
	switch( m_aColorBox.details.spread.spread_type )
	{
	case LINEAR_SPREAD_TYPE:
		if( m_aColorBox.details.spread.spread_on )
			CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_LINEAR ); // linear
		else
			CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_SOLID ); // solid
		break;
	case CONCENTRIC_SPREAD_TYPE:
		CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_CIRCULAR ); // circular
		break;
	case FOUR_PT_SPREAD_TYPE:
		CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_4POINT ); // circular
		break;
	case BEVEL_SPREAD_TYPE:
		break;
	case HORIZ2_SPREAD_TYPE:
		break;
	case VERT2_SPREAD_TYPE:
		break;
	case SIDE4_SPREAD_TYPE:
		break;
	}//end of switch

	// Init radio button - RGB & HSV
	CheckRadioButton( IDC_RB_RGB, IDC_RB_HSV, IDC_RB_RGB ); // default
	
	// Init the video safe check box
//	if( cg_edit_status.NTSC_safe_colors == 1 )
//		::CheckDlgButton( hDlg, IDC_VDO_SAFE, 1 );
//	else
//		::CheckDlgButton( hDlg, IDC_VDO_SAFE, 0 );

}//end of CPalDlg::InitButtonState()
////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::DrawTagFromDib()
{
	double		n;
	HDC			hDC;
	HDC			hMemDC;
	HBITMAP		hBmp;
	HBITMAP		hOldBmp;
	RECT		rcSlider;
	UINT		numTag;
	HWND		hPALPanel = this->m_hWnd;
	HWND		hSlider = ::GetDlgItem( hPALPanel, IDC_LIST_TAG );
	UINT		rv;
	INT			dX = TAG_HALF_WIDTH;
	INT			dY = TAG_HEIGHT;
	UINT		i;
	COLORREF	color32;
	

	::GetWindowRect( hSlider, &rcSlider );
	m_PalDibWidth  = rcSlider.right - rcSlider.left;
	m_PalDibHeight = rcSlider.bottom - rcSlider.top;

	m_SpreadWidth = m_PalDibWidth - 1; // for scaling and mouse position convertion

	BITMAPINFOHEADER		bmpHeader;

	bmpHeader.biSize        = sizeof( BITMAPINFOHEADER );
	bmpHeader.biWidth       = m_PalDibWidth;
	bmpHeader.biHeight      = -m_PalDibHeight;
	bmpHeader.biPlanes      = 1;
	bmpHeader.biBitCount    = 32;
	bmpHeader.biCompression = BI_RGB;
	bmpHeader.biSizeImage   = m_PalDibWidth * m_PalDibHeight * sizeof(DWORD);

	hDC		= ::GetDC( hSlider );
	hMemDC	= CreateCompatibleDC( hDC );
	hBmp    = CreateDIBSection( hMemDC,
								(BITMAPINFO *)&(bmpHeader),
								DIB_RGB_COLORS,
								(void **)&(m_PalDibSectionPtr),
								NULL, 0 );
	if( hBmp == NULL )
	{
		_ASSERT(0);
		#if _DEBUG
		::MessageBox( NULL, _T("System Unstable"), _T("Warning"), MB_OK|MB_ICONWARNING );
		//exit( 1 );
		#endif
	}

	hOldBmp = (HBITMAP)SelectObject( hMemDC, hBmp );
	PalDibFillRect( m_PalDibWidth, m_PalDibHeight, GetSysColor(COLOR_BTNFACE) );

	numTag = m_aColorBox.details.spread.spread_tabs_total;

	for( i = 0; i < numTag; i++ )
	{	
		n = m_SpreadWidth * m_aColorBox.details.spread.spread_tab_position[i];
		color32 = m_aColorBox.details.spread.color[i];
		if( i == m_aColorBox.details.spread.current_tab_index ) 
		{
			dY += 3; // set tag height
			PalDibDrawSelectedTriangle( (int)n, dY, color32 );
		}
		else	
			PalDibDrawTriangle( (int)n, dY, color32 );		

		if( i == m_aColorBox.details.spread.current_tab_index ) 
			dY -= 3; // restore normal tag boundary color and tag heigh
	}//end of for

	rv = BitBlt( hDC, 0, 0, bmpHeader.biWidth, rcSlider.bottom - rcSlider.top, hMemDC, 0, 0, SRCCOPY );

	SelectObject( hMemDC, hOldBmp ); 
	DeleteObject( hBmp );

	::ReleaseDC( hSlider, hDC );
	DeleteDC( hMemDC );
}//end of CPalDlg::DrawTagFromDib()
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Draw a selected triangle tag with 2 black pixels higher than other tags.
// INPUT : int xPos - x position of tag (corresponding to x mouse position)
// INPUT : int height - height of tag (the selected tag is 3 pixels higher)
// INPUT : COLORREF Color32 - 32 bits pixel 0x00bbggrr
VOID CPalDlg::PalDibDrawSelectedTriangle(int xPos, int height, COLORREF Color32)
{
	int x, y;
	DWORD	color32 = ConvertToARGB( Color32 );
	for( x = 0; x < 5; x++ )
		for( y = 0; y < height-(2*x); y++ )
		{			
//save		if( y == 0 )
//save		{
//save			PalDibSetPixel(xPos-x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, 0x0);
//save			PalDibSetPixel(xPos+x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, 0x0);
//save		}
//save		else
//save		{
			PalDibSetPixel(xPos-x, (2*x)+y, m_PalDibWidth, m_PalDibHeight, color32);
			PalDibSetPixel(xPos+x, (2*x)+y, m_PalDibWidth, m_PalDibHeight, color32);
//save		}
		}

	for( x = 0; x < 5; x++ )
	{
		PalDibSetPixel(xPos-x, height,   m_PalDibWidth, m_PalDibHeight, 0x0);
		PalDibSetPixel(xPos-x, height-1, m_PalDibWidth, m_PalDibHeight, 0x0);
		PalDibSetPixel(xPos+x, height,   m_PalDibWidth, m_PalDibHeight, 0x0);
		PalDibSetPixel(xPos+x, height-1, m_PalDibWidth, m_PalDibHeight, 0x0);
	}
}//end of CPalDlg::PalDibDrawSelectedTriangle()
/////////////////////////////////////////////////////////////////////////////////////////////
// Draw a triangle tag
// INPUT : int xPos - x position of tag (corresponding to x mouse position)
// INPUT : int height - height of tag (the selected tag is 3 pixels higher)
// INPUT : COLORREF Color32 - 32 bits pixel 0x00bbggrr
VOID CPalDlg::PalDibDrawTriangle(int xPos, int height, COLORREF Color32)
{
	DWORD	color32 = ConvertToARGB( Color32 );
	for( int x = 0; x < 5; x++ )
		for( int y = 0; y < height-(2*x); y++ )
		{
			PalDibSetPixel(xPos-x, (2*x)+y, m_PalDibWidth, m_PalDibHeight, color32);
			PalDibSetPixel(xPos+x, (2*x)+y, m_PalDibWidth, m_PalDibHeight, color32);
		}

}//end of CPalDlg::PalDibDrawTriangle()
/////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::DrawSpreadColorBox()
{
	HWND hCtrl = GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
	CGS_RenderColorboxAsSpreadBarToWindow( &m_aColorBox, (DWORD)hCtrl );
}//end of CPalDlg::DrawSpreadColorBox()
/////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::DrawColorBoxWnd()
{
	HWND hCtrl = GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;			
	CGS_RenderColorboxToWindow( &m_aColorBox, (DWORD)hCtrl,0);		// draw color box info

}//end of CPalDlg::DrawColorBoxWnd()
/////////////////////////////////////////////////////////////////////////////////////////////////////
// If the last tag is not set on position 1, add the new tag to position 1.
// Otherwise, add the new tag in a biggest gap between 2 tags.
// Check the max number of tag. At least one tag exit.
// Find empty spot - find the biggest empty gap and then put the tag in the middle of gap.
// Select the base color, then render the base color on the tag and render the base color 
// on the base color box. Set the added tag as the current selected state. Sort data
void CPalDlg::OnBtPalAdd() 
{
	INT	  numTag = m_aColorBox.details.spread.spread_tabs_total;	
	BYTE  curTag = m_aColorBox.details.spread.current_tab_index;
	UINT  iTag   = 0;

	if( MAXIMUM_SPREAD_TABS <= numTag )
		return;

	// Change the solid to linear
	if( m_aColorBox.details.spread.spread_type == LINEAR_SPREAD_TYPE 
		&& !m_aColorBox.details.spread.spread_on )
	{
		m_aColorBox.details.spread.spread_on = 1; // ??? is 1 represent linear
		CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_LINEAR );
		SetPALRotationHScroll();
		EnableRotationScrollBar();
	}

	if( m_aColorBox.details.spread.spread_tab_position[0] != 0 )
	{
		m_aColorBox.details.spread.spread_tab_position[numTag] = 0;
		m_aColorBox.details.spread.current_tab_index = 0;
	}
	else
		if( m_aColorBox.details.spread.spread_tab_position[numTag-1] != 1 )
		{
			m_aColorBox.details.spread.spread_tab_position[numTag] = 1;
			m_aColorBox.details.spread.current_tab_index = 1;
		}
		else
		{
			iTag = GetBiggestGapTagIndex( );
			m_aColorBox.details.spread.spread_tab_position[numTag] 
				= ( m_aColorBox.details.spread.spread_tab_position[iTag]
				+   m_aColorBox.details.spread.spread_tab_position[iTag-1] )/(float)2.0;
			m_aColorBox.details.spread.current_tab_index = iTag;
		}//end of else

	m_aColorBox.details.spread.color[numTag] = m_aColorBox.details.spread.color[curTag];
	++m_aColorBox.details.spread.spread_tabs_total;	

	CPalSliderCtrl* pPalSlider = (CPalSliderCtrl*)GetDlgItem( IDC_LIST_TAG );
	pPalSlider->SortTag();
		
	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalAdd
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Delete the current selected tag.
// Set the current selected tag position to 1.5 which is greater than 1. Then sort data. 
// After sorting the data, sel the last element (1.5) to zero for calculate gap.
// Reduce number of total tab by 1. Set the current selection to the last tag.
void CPalDlg::OnBtPalDelete() 
{
	INT	tagIndex = m_aColorBox.details.spread.current_tab_index;

	if( m_aColorBox.details.spread.spread_tabs_total == 1 )
		return;

	m_aColorBox.details.spread.spread_tab_position[tagIndex] = 1.5;

	CPalSliderCtrl* pPalSlider = (CPalSliderCtrl*)GetDlgItem( IDC_LIST_TAG );
	pPalSlider->SortTag();

	m_aColorBox.details.spread.current_tab_index = --m_aColorBox.details.spread.spread_tabs_total - 1;
	m_aColorBox.details.spread.spread_tab_position[m_aColorBox.details.spread.spread_tabs_total] = 0;

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox();

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	InitHorizScrollBar();

	AfxGetMainWnd()->SetFocus();	
}//end of CPalDlg::OnBtPalDelete
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalCopy() 
{
	memcpy( &m_tmpColorBox, &m_aColorBox, sizeof( ALPHA_COLOR_BOX ) );
	m_Action = IDC_BT_PAL_COPY;
	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalCopy
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Set the current selected tag to the first record. (Zero position).
// Delete all tag and clear the data structure. At least one tag left.
void CPalDlg::OnBtPalClear() 
{
	INT		 tagIndex = m_aColorBox.details.spread.current_tab_index;
	COLORREF tmpColor = m_aColorBox.details.spread.color[tagIndex];

	// ** double check the sizeof **
	ZeroMemory( &m_aColorBox.details.spread.color, sizeof(COLORREF)*MAXIMUM_SPREAD_TABS );
	ZeroMemory( &m_aColorBox.details.spread.spread_tab_position, sizeof(float)*MAXIMUM_SPREAD_TABS );

	m_aColorBox.details.spread.spread_tabs_total = 1;
	m_aColorBox.details.spread.current_tab_index = 0;
	m_aColorBox.details.spread.color[0] = tmpColor;
	m_aColorBox.details.spread.spread_tab_position[0] = 0;

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox();

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_SOLID ); // solid

	AfxGetMainWnd()->SetFocus();	
}//end of CPalDlg::OnBtPalClear
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Swap the between (first + n) and (last - n), Then run sorting.
// Mirror the spread box (set 0.5 as the base line, 0.5 - tag position + 0.5)
void CPalDlg::OnBtPalInvert() 
{
	INT	 numTag   = m_aColorBox.details.spread.spread_tabs_total;

	for( int i = 0; i < numTag; i++ )
		m_aColorBox.details.spread.spread_tab_position[i] 
			= (float)1.0 - m_aColorBox.details.spread.spread_tab_position[i];

	CPalSliderCtrl* pPalSlider = (CPalSliderCtrl*)GetDlgItem( IDC_LIST_TAG );
	pPalSlider->SortTag();

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox();

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	InitHorizScrollBar();

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalInvert
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Shift the color only and Shift to the left (toward zero element)
void CPalDlg::OnBtPalShift() 
{
	INT		 tagIndex = m_aColorBox.details.spread.current_tab_index;
	INT		 numTag   = m_aColorBox.details.spread.spread_tabs_total;
	COLORREF tmpColor = m_aColorBox.details.spread.color[tagIndex];

	tmpColor = m_aColorBox.details.spread.color[0]; //save the first color
	for( int i = 0; i < (numTag-1); i++ )
		m_aColorBox.details.spread.color[i] = m_aColorBox.details.spread.color[i+1];

	m_aColorBox.details.spread.color[numTag-1] = tmpColor;

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox();

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	InitHorizScrollBar();

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalShift
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Displacement equal to one divided by total number of tag - 1
// Only change the tag position....
void CPalDlg::OnBtPalSpace() 
{
	INT	  numTag = m_aColorBox.details.spread.spread_tabs_total;

	if( numTag < 1 )
		return;

	float tagGap = (float)1.0/(numTag-1);

	for( int i = 0; i < (numTag-1); i++ )
		m_aColorBox.details.spread.spread_tab_position[i] = i * tagGap;

	// ensure last tag is one - it is not neccessary
	m_aColorBox.details.spread.spread_tab_position[numTag-1] = 1;

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();	
}//end of CPalDlg::OnBtPalSpace
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalSwap() 
{
	memcpy( &m_tmpColorBox, &m_aColorBox, sizeof( ALPHA_COLOR_BOX ) );
	m_Action = IDC_BT_PAL_SWAP;

	m_SwapIndex = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );
	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalSwap
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalUndo() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPalDlg::OnBtPalUndo
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalRedo() 
{
	// TODO: Add your control notification handler code here
	
}//end of CPalDlg::OnBtPalRedo
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalLinear() 
{
	CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_LINEAR );
	m_aColorBox.details.spread.spread_type = LINEAR_SPREAD_TYPE; 
	m_aColorBox.details.spread.spread_on = 1;
	EnableRotationScrollBar();

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalLinear
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPal4point() 
{		
	CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_4POINT );
	m_aColorBox.details.spread.spread_type = FOUR_PT_SPREAD_TYPE; 
	m_aColorBox.details.spread.spread_on = 1;
	DisableRotationScrollBar();

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPal4point
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalCircular() 
{	
	CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_CIRCULAR );
	m_aColorBox.details.spread.spread_type = CONCENTRIC_SPREAD_TYPE; 
	m_aColorBox.details.spread.spread_on = 1;
	DisableRotationScrollBar();

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnBtPalCircular
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Use LINEAR_SPREAD_TYPE for solid selection (0)
// MUST set spread_on to 0 here. Also, diable the rotation scroll bar.
void CPalDlg::OnBtPalSolid() 
{
	CheckRadioButton( IDC_BT_PAL_SOLID, IDC_BT_PAL_4POINT, IDC_BT_PAL_SOLID );
	m_aColorBox.details.spread.spread_type = LINEAR_SPREAD_TYPE; 
	m_aColorBox.details.spread.spread_on = 0;
	DisableRotationScrollBar();

	DrawTagFromDib();
	DrawColorBoxWnd();
	DrawBaseColorBox();
	DrawSpreadColorBox( );

	if( m_dwPalState == ID_FORMAT_PAL )	
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box back to core
	}
	else
		CGS_SetDataItem( m_idxPal, &m_aColorBox );

	AfxGetMainWnd()->SetFocus();
	
}//end of CPalDlg::OnBtPalSolid
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalSave() 
{
	FILE_REQ_FOLDER_INFO	palFRD;
	ZeroMemory( &palFRD, sizeof(palFRD) );
	palFRD.opt = SAVE_OP;
	_tcscpy( palFRD.DlgTitle, _T("Save Palette As") );
	FileRequestDlg( &palFRD, FILE_CATEGORY_PALETTE );
	
	//TO DO : get the full path froom palFRD and call core function
}//end of CPalDlg::OnBtPalSave
/////////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnBtPalOpen() 
{
	FILE_REQ_FOLDER_INFO	palFRD;
	ZeroMemory( &palFRD, sizeof(palFRD) );
	palFRD.opt = OPEN_OP;
	_tcscpy( palFRD.DlgTitle, _T("Open Palette") );
	FileRequestDlg( &palFRD, FILE_CATEGORY_PALETTE );

	//TO DO : get the full path froom palFRD and call core function
	
}//end of CPalDlg::OnBtPalOpen
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Find the biggest space between 2 tags and return the 2nd tag index.
// eg) | ^  ^           ^ ^   ^|, the 3rd tag index (2) will be returned.
// INPUT  : INT index - index of selected palette
// RETURN : UINT tag index
// NOTE   : All position values bigger than 1 should set to zero.
UINT CPalDlg::GetBiggestGapTagIndex()
{
	float bigGap = 0;
	float gap	 = 0;
	INT	  numTag = m_aColorBox.details.spread.spread_tabs_total;
	UINT  iTag;

	for( int i = 0; i < numTag; i++ )
	{
		gap = m_aColorBox.details.spread.spread_tab_position[i+1]
			- m_aColorBox.details.spread.spread_tab_position[i];

		if( bigGap < gap )
		{
			bigGap = gap;
			iTag = i + 1;
		}//end of if 
	}//end of for

	return( iTag );
}//end of CPalDlg::GetBiggestGapTagIndex()
////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnRbRgb() 
{
	BYTE		curTag = m_aColorBox.details.spread.current_tab_index;
	COLORREF	color  = m_aColorBox.details.spread.color[curTag];
	UINT		nMin = 0;	// min. range of scroll bar
	UINT		nMax = 255; // max. range of scroll bar

	UINT RPos = color & 0x000000FF;
	UINT GPos = (color & 0x0000FF00) >> 8;
	UINT BPos = (color & 0x00FF0000) >> 16;

	SetDlgItemText( IDC_STC_R, _T("R") );
	SetDlgItemText( IDC_STC_G, _T("G") );
	SetDlgItemText( IDC_STC_B, _T("B") );

	m_hsbR.SetScrollRange( nMin, nMax );	// default range
	m_hsbR.SetScrollPos( RPos );			// default position
	m_hsbG.SetScrollRange( nMin, nMax );	// default range
	m_hsbG.SetScrollPos( GPos );			// default position
	m_hsbB.SetScrollRange( nMin, nMax );	// default range
	m_hsbB.SetScrollPos( BPos );			// default position

	SetDlgItemInt( IDC_ED_R, RPos, 1 );
	SetDlgItemInt( IDC_ED_G, GPos, 1 );
	SetDlgItemInt( IDC_ED_B, BPos, 1 );

	AfxGetMainWnd()->SetFocus();
}//end of CPalDlg::OnRbRgb()
////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnRbHsv() 
{
//	INT			index  = GetSelectedPaletteIndex();
	BYTE		curTag = m_aColorBox.details.spread.current_tab_index;
	COLORREF	color  = m_aColorBox.details.spread.color[curTag];
	UINT		minH = 0;	// min. range of H scroll bar
	UINT		maxH = 359; // max. range of H scroll bar
	UINT		nMin = 0;	// min. range of S & V scroll bar
	UINT		nMax = 255; // max. range of S & V scroll bar

	UINT HPos = color  & 0x000000FF;
	UINT SPos = (color & 0x0000FF00) >> 8;
	UINT VPos = (color & 0x00FF0000) >> 16;

	ColorConversion( RGB_MODE, HSV_MODE, (INT*)&HPos, (INT*)&SPos, (INT*)&VPos );

	SetDlgItemText( IDC_STC_R, _T("H") );
	SetDlgItemText( IDC_STC_G, _T("S") );
	SetDlgItemText( IDC_STC_B, _T("V") );

	m_hsbR.SetScrollRange( minH, maxH );	// default range
	m_hsbR.SetScrollPos( HPos );			// default position
	m_hsbG.SetScrollRange( nMin, nMax );	// default range
	m_hsbG.SetScrollPos( SPos );			// default position
	m_hsbB.SetScrollRange( nMin, nMax );	// default range
	m_hsbB.SetScrollPos( VPos );			// default position

	SetDlgItemInt( IDC_ED_R, HPos, 1 );
	SetDlgItemInt( IDC_ED_G, SPos, 1 );
	SetDlgItemInt( IDC_ED_B, VPos, 1 );

	AfxGetMainWnd()->SetFocus();

}//end of CPalDlg::OnRbHsv() 
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::OnHRotation( INT nCurPos )
{
	m_aColorBox.details.spread.spread_angle = nCurPos;
	SetDlgItemInt(IDC_ED_ROTATE, nCurPos, 0 );
}//end of CPalDlg::OnHRotation()
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::OnHRed( INT nCurPos )
{	
	BYTE curTag  = m_aColorBox.details.spread.current_tab_index;
	if( BST_CHECKED == IsDlgButtonChecked( IDC_RB_HSV ) )
	{
		INT hPos = nCurPos;
		INT sPos = m_hsbG.GetScrollPos();
		INT vPos = m_hsbB.GetScrollPos();
		
		ColorConversion( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
		
		INT color = hPos | (vPos << 16) | (sPos << 8);
		m_aColorBox.details.spread.color[curTag] = color;
	}
	else
	{
		m_aColorBox.details.spread.color[curTag] &= 0xFFFFFF00;
		m_aColorBox.details.spread.color[curTag] |= nCurPos;
	}

	SetDlgItemInt(IDC_ED_R, nCurPos, 0 );
}//end of CPalDlg::OnHRed()
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::OnHGreen( INT nCurPos )
{
	BYTE curTag  = m_aColorBox.details.spread.current_tab_index;
	INT	 color;
	if( BST_CHECKED == IsDlgButtonChecked( IDC_RB_HSV ) )
	{
		INT hPos = m_hsbR.GetScrollPos();
		INT sPos = nCurPos;
		INT vPos = m_hsbB.GetScrollPos();
		
		ColorConversion( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
		
		INT color = hPos | (vPos << 16) | (sPos << 8);
		m_aColorBox.details.spread.color[curTag] = color;
	}
	else
	{
		color = nCurPos << 8;
		m_aColorBox.details.spread.color[curTag] &= 0xFFFF00FF;
		m_aColorBox.details.spread.color[curTag] |= color;
	}

	SetDlgItemInt(IDC_ED_G, nCurPos, 0 );
}//end of CPalDlg::OnHGreen()
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::OnHBlue( INT nCurPos )
{
	BYTE curTag  = m_aColorBox.details.spread.current_tab_index;
	INT	 color;
	if( BST_CHECKED == IsDlgButtonChecked( IDC_RB_HSV ) )
	{
		INT hPos = m_hsbR.GetScrollPos();
		INT sPos = m_hsbG.GetScrollPos();
		INT vPos = nCurPos;
		
		ColorConversion( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
		
		INT color = hPos | (vPos << 16) | (sPos << 8);
		m_aColorBox.details.spread.color[curTag] = color;
	}
	else
	{
		color = nCurPos << 16;
		m_aColorBox.details.spread.color[curTag] &= 0xFF00FFFF;
		m_aColorBox.details.spread.color[curTag] |= color;
	}

	SetDlgItemInt(IDC_ED_B, nCurPos, 0 );
}//end of CPalDlg::OnHBlue()
/////////////////////////////////////////////////////////////////////////////////////////////////
void CPalDlg::OnClickOk() 
{
	OnOK();	// Because of redesign of GUI....
}//end of CPalDlg::OnClickOk()
/////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CPalDlg::CheckEditInputValue(DWORD flag, DWORD edValue)
{
	BOOL rv = 0;
	switch( flag )
	{
	case IDC_ED_ROTATE:
		if( 359 < edValue )
			rv = MessageBox( _T("Please enter value between 0 and 359"), _T("Error"), MB_OK | MB_ICONINFORMATION );
		break;
	case IDC_ED_R:
		if( BST_CHECKED == IsDlgButtonChecked( IDC_RB_HSV ) )
		{
			if( 359 < edValue )
				rv = MessageBox( _T("Please enter value between 0 and 359"), _T("Error"), MB_OK | MB_ICONINFORMATION );
		}
		else
			if( 255 < edValue )
				rv = MessageBox( _T("Please enter value between 0 and 255"), _T("Error"), MB_OK | MB_ICONINFORMATION );
		break;
	case IDC_ED_G:
	case IDC_ED_B:
		if( 255 < edValue )
				rv = MessageBox( _T("Please enter value between 0 and 255"), _T("Error"), MB_OK | MB_ICONINFORMATION );
		break;
	default:
		rv = 0;
	}//end of switch

	return( rv );
}//end of CheckEditInputValue
////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::BackupColorBoxes()
{
	int i;
	for( i = 0; i < MAX_BOX; i++ )
		CGS_BinGetItemData( UIBIN_PALETTE_MENU, i, &m_ColorBox[i] );	// copy color box to local
}//end of CPalDlg::BackupColorBoxes()
////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::RestoreColorBoxes()
{
	int i;
	for( i = 0; i < MAX_BOX; i++ )
		CGS_BinSetItemData( UIBIN_PALETTE_MENU, i, &m_ColorBox[i] );
}//end of CPalDlg::RestoreColorBoxes()
////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CPalDlg::SetPaletteState(DWORD buttonID)
{
	m_dwPalState = buttonID;
}//end of CPalDlg::SetPaletteState(DWORD buttonID)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
DWORD CPalDlg::GetPaletteState()
{
	return( m_dwPalState );
}//end of CPalDlg::GetPaletteState()
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Based on users' action on which palatte button was clicked, pass the "color box info"
// to this object and core to retrieve the color box info.
// Then draw on the palatte dialog box.
VOID CPalDlg::GetStyleColorBoxInfo()
{
	switch( m_dwPalState )
	{
	case IDC_BT_COL_PAL_FA:
		m_idxPal = EDIT_OBJ_FACE_COLORSCHEME;
		break;
	case IDC_BT_TRANS_PAL_FA:
		m_idxPal = EDIT_OBJ_FACE_ALPHA_MASK;
		break;
	case IDC_BT_COL_PAL_OL:
		m_idxPal = EDIT_OBJ_OUTLINE1_COLORSCHEME;
		break;
	case IDC_BT_TRANS_PAL_OL:
		m_idxPal = EDIT_OBJ_OUTLINE1_ALPHA_MASK;
		break;
	case IDC_BT_COL_PAL_OL2:
		m_idxPal = EDIT_OBJ_OUTLINE2_COLORSCHEME;
		break;
	case IDC_BT_TRANS_PAL_OL2:
		m_idxPal = EDIT_OBJ_OUTLINE2_ALPHA_MASK;
		break;
	case IDC_BT_COL_PAL_CA:
		m_idxPal = EDIT_OBJ_SHADOW2_COLORSCHEME;
		break;
	case IDC_BT_TRANS_PAL_CA:
		m_idxPal = EDIT_OBJ_SHADOW2_ALPHA_MASK;
		break;
	case IDC_BT_COL_PAL_SD:
		m_idxPal = EDIT_OBJ_SHADOW1_COLORSCHEME;
		break;
	case IDC_BT_TRANS_PAL_SD:
		m_idxPal = EDIT_OBJ_SHADOW1_ALPHA_MASK;
		break;
	case ID_FORMAT_PAL: // the palatte button on the menu bar
		m_idxPal = 0;
		break;
	}//end of switch - m_dwPalState

	if( m_idxPal )
	{
		CGS_GetDataItem( m_idxPal, &m_aColorBox );
		HWND hCtrl = GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;			
		CGS_RenderColorboxToWindow( &m_aColorBox, (DWORD)hCtrl,0);		// draw color box info
		hCtrl = GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
		CGS_RenderColorboxAsSpreadBarToWindow( &m_aColorBox, (DWORD)hCtrl );
	}//end of if
	else
	{
		int index = CGS_BinGetSelectedIndex( UIBIN_PALETTE_MENU );		// get color box index
		CGS_BinGetItemData( UIBIN_PALETTE_MENU, index, &m_aColorBox );	// copy color box to local
		HWND hCtrl = GetDlgItem( IDC_PAL_CUR_COLOR )->m_hWnd;			
		CGS_RenderColorboxToWindow( &m_aColorBox, (DWORD)hCtrl,0);		// draw color box info
		hCtrl = GetDlgItem( IDC_SPREAD_COLOR )->m_hWnd;
		CGS_RenderColorboxAsSpreadBarToWindow( &m_aColorBox, (DWORD)hCtrl );
	}//end of else

}//end of CPalDlg::GetStyleColorBoxInfo()
//////////////////////////////////////////////////////////////////////////////////////////////
// Return the text mode color state. ie: face color or shadow color ....
INT CPalDlg::GetTextModeIndex()
{
	return( m_idxPal );
}//end of CPalDlg::GetTextModeIndex()
