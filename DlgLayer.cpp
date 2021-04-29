/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// DlgLayer.cpp : implementation file
//



#include "stdafx.h"
#include "cgUI.h"
#include "Global.h"
#include "DlgLayer.h"
#include "ACGS_Inc\\UI_BinMgr.h" //in ACGS_Inc folder (JRS)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void		DoPageLabelDlg(char* pStringVal);

/////////////////////////////////////////////////////////////////////////////
// CLyImgBox
CLyImgBox::CLyImgBox()
{
}

CLyImgBox::~CLyImgBox()
{
}

BEGIN_MESSAGE_MAP(CLyImgBox, CEdit)
	//{{AFX_MSG_MAP(CLyImgBox)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT() //JRS
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//OnPaint added by JRS
void CLyImgBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	//JRS ADD
	CGS_BinRefresh(UIBIN_LAYER);
	AfxGetMainWnd()->SetFocus();
	// Do not call CEdit::OnPaint() for painting messages
}
/////////////////////////////////////////////////////////////////////////////
void CLyImgBox::OnMouseMove(UINT nFlags, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	TRACE2( "DlgLayer.cpp : CLyImgBox::OnMouseMove - x = %d, y = %d\n", pt.x, pt.y );
	CEdit::OnMouseMove(nFlags, pt);
	
}//end of OnMouseMove
/////////////////////////////////////////////////////////////////////////////
void CLyImgBox::OnLButtonDown(UINT nFlags, CPoint pt) 
{	
	TRACE2( "DlgLayer.cpp : CLyImgBox::OnLButtonDown - x = %d, y = %d\n", pt.x, pt.y );
	CGS_BinSelect(UIBIN_LAYER, ABMC_DEFAULT, pt.x, pt.y); //JRS - CHECK: problem here
//	CEdit::OnLButtonDown(nFlags, pt);
	TRACE0( "DlgLayer.cpp : Before set focus\n" );
	AfxGetMainWnd()->SetFocus();
}//end of OnLButtonDown
// CPgImgBox message handlers
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDlgLayer dialog
CDlgLayer::CDlgLayer(CWnd* pParent /*=NULL*/) : CDialog(CDlgLayer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLayer)
	//}}AFX_DATA_INIT
}


void CDlgLayer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLayer)
	DDX_Control(pDX, IDC_ED_LAYER_NUM, m_ctlEdNum);
	DDX_Control(pDX, IDC_VSB_LAYER_BOX, m_vsbLayer);
	DDX_Control(pDX, IDC_STC_LAYER_TOTAL, m_stcTotal);
	DDX_Control(pDX, IDC_BT_PASTE_LAYER, m_btPaste);
	DDX_Control(pDX, IDC_BT_NEW_LAYER, m_btNewLayer);
	DDX_Control(pDX, IDC_BT_MOVE_UP, m_btMoveUp);
	DDX_Control(pDX, IDC_BT_MOVE_DOWN, m_btMoveDown);
	DDX_Control(pDX, IDC_BT_DEL_LAYER, m_btDelete);
	DDX_Control(pDX, IDC_BT_COPY_LAYER, m_btCopy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLayer, CDialog)
	//{{AFX_MSG_MAP(CDlgLayer)
	ON_BN_CLICKED(IDC_BT_NEW_LAYER, OnBtNewLayer)
	ON_BN_CLICKED(IDC_BT_MOVE_UP, OnBtMoveUp)
	ON_BN_CLICKED(IDC_BT_MOVE_DOWN, OnBtMoveDown)
	ON_BN_CLICKED(IDC_BT_COPY_LAYER, OnBtCopyLayer)
	ON_BN_CLICKED(IDC_BT_DEL_LAYER, OnBtDelLayer)
	ON_BN_CLICKED(IDC_BT_PASTE_LAYER, OnBtPasteLayer)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLayer message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtNewLayer() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtMoveUp() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::OnBtMoveUp
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtMoveDown() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::OnBtMoveDown
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtCopyLayer() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::OnBtCopyLayer
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtDelLayer() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::OnBtDelLayer
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnBtPasteLayer() 
{
	// TODO: Add your control notification handler code here
	
}//end of CDlgLayer::OnBtPasteLayer
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgLayer::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemInt( IDC_STC_LAYER_TOTAL, (int)CGS_GetValDbl(EDIT_PROJECT_TOT_PAGES), 0 );
	m_vsbLayer.SetScrollRange( 1, 1000 );	// default range

	// Initial page number edit box
	SetDlgItemInt( IDC_ED_LAYER_NUM, 10, 0 );
	m_ctlLyDlgImg.SubclassDlgItem( IDC_LAYER_LIST_BOX, this );

	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_btNewLayer.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_NEW_PAGE), IMAGE_ICON, 16, 16, 0) );
	m_btMoveUp.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_EXPORT_PAGE), IMAGE_ICON, 16, 16, 0) );
	
	CGS_BinOpen(
		UIBIN_LAYER,
		m_ctlLyDlgImg.m_hWnd,
		NULL,
		NULL //01-04-13 i.e. UI_RedrawPageBinThumbTrack function for core to call to tell UI to redraw thumb track position e.g. void UI_RedrawPageBinThumbTrack(double ScrollPos_01);
		);
	
	CGS_BinRegisterGetStringDlgCallback(UIBIN_LAYER, DoPageLabelDlg); //JRS

	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgLayer::OnInitDialog() 
/////////////////////////////////////////////////////////////////////////////
void CDlgLayer::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	ASSERT(pScrollBar != NULL);

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
		nCurPos -= 100;
		break;
	case SB_PAGEDOWN:		// Scroll one page down.
		nCurPos += 10;
		break;
	case SB_BOTTOM:			// Scroll to far bottom.
		nCurPos = 1000;
		break;
	case SB_THUMBPOSITION:	// Scroll to absolute position. 
	case SB_THUMBTRACK:		// Drag scroll box to specified position. 
		nCurPos = nPos;
		break;
	case SB_ENDSCROLL:		// End scroll
		TRACE0( "DlgLayer.cpp : OnVScroll - End scroll\n" );
		break;
	}//end of switch - nSBCode

	nCurPos = ( nCurPos < 1 ) ? 1 : nCurPos;
	nCurPos = ( 1000 < nCurPos ) ? 1000 : nCurPos;

	pScrollBar->SetScrollPos(nCurPos);

	CGS_BinSetScroll(UIBIN_LAYER,(double) ((double)nCurPos) / (1000.0f) ); //JRS
	// End of adding your message handler code here and/or call default	
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}//end of CDlgLayer::OnVScroll
/////////////////////////////////////////////////////////////////////////////
// Resize the scroll bar control and list control when users resize the whole app
VOID CDlgLayer::ReSizeControl( CRect rcClient )
{
	const int dCXBox  = 8;	 // delta adjustment
	const int dCYBox  = 135; 
	const int dCYPage = 30;	

	CRect rcLayer;
	GetClientRect( rcLayer );
	SetWindowPos( NULL, 0, 0, rcLayer.Width(), rcClient.Height() - dCYPage,
					SWP_NOMOVE |  SWP_NOZORDER );

	CRect rcVSBar; // scroll bar control on page dialog
	CScrollBar* pVSBar = (CScrollBar*)GetDlgItem(IDC_VSB_LAYER_BOX);
	if( pVSBar == NULL )
		return; // error
	pVSBar->GetClientRect( rcVSBar );
	pVSBar->SetWindowPos( NULL, 0, 0, rcVSBar.Width(), rcClient.Height() - dCYBox,
							SWP_NOMOVE |  SWP_NOZORDER );

	CRect rcStcBox; // list control on page dialog
	CStatic* pStcBox = (CStatic*)GetDlgItem(IDC_LAYER_LIST_BOX);
	if( pStcBox == NULL )
		return; // error
	pStcBox->GetClientRect( rcStcBox );
	pStcBox->SetWindowPos( NULL, 0, 0, rcLayer.Width() - rcVSBar.Width() - dCXBox, rcClient.Height() - dCYBox,
							SWP_NOMOVE |  SWP_NOZORDER );

}//end of CDlgLayer::ReSizeControl()
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgLayer::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CDlgLayer::PreTranslateMessage(MSG* pMsg)
/////////////////////////////////////////////////////////////////////////////
VOID CDlgLayer::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	DWORD numTxt = LoadTextFromCtl( "\\Util\\DlgLayer.ctl", "[Tooltip]", &txtData );
	if( numTxt == 0 )
		return;

	for( DWORD i = 0; i < numTxt; i++ )
	{
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';
			
		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_NEW_LAYER") ) )
			txtData[i].idTT = IDC_BT_NEW_LAYER;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_MOVE_UP") ) )
				txtData[i].idTT = IDC_BT_MOVE_UP;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_MOVE_DOWN") ) )
				txtData[i].idTT = IDC_BT_MOVE_DOWN;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COPY_LAYER") ) )
				txtData[i].idTT = IDC_BT_COPY_LAYER;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_DEL_LAYER") ) )
				txtData[i].idTT = IDC_BT_DEL_LAYER;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_PASTE_LAYER") ) )
				txtData[i].idTT = IDC_BT_PASTE_LAYER;

		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );

}//end of CDlgLayer::InitDlgItemTextNTooltip()
