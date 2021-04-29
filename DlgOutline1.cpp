/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgOutline1.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgOutline1.h"
#include "Global.h"
#include "PalDlg.h"
#include "FileReq.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOutline1 dialog

extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_dwAttrib;

CDlgOutline1::CDlgOutline1(CWnd* pParent /*=NULL*/)	: CDialog(CDlgOutline1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOutline1)
	m_edOLTrans = 0;
	m_edFeather = 0;
	m_edSize	= 0;
	m_edXOffset = 0;
	m_edYOffset = 0;
	//}}AFX_DATA_INIT
	m_bAlpha	= 0;
	g_dwAttrib	= ABMC_OUTLINE1_COLOR;
	m_pDlg		= NULL;
	m_hFont		= NULL;

}
CDlgOutline1::~CDlgOutline1()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;

	if( m_pDlg != NULL )
		delete m_pDlg;
}
void CDlgOutline1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOutline1)
	DDX_Control(pDX, IDC_CK_OL1_ENABLE, m_ckOL1Enable);
	DDX_Control(pDX, IDC_STC_OL1_YOFFSET, m_stcYOffset);
	DDX_Control(pDX, IDC_STC_OL1_XOFFSET, m_stcXOffset);
	DDX_Control(pDX, IDC_STC_OL1_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_STC_OL1_FEATHER, m_stcFeather);
	DDX_Control(pDX, IDC_BT_TRANS_PAL_OL, m_btTranPal);
	DDX_Control(pDX, IDC_BT_TRANS_IMP_OL, m_btTranImp);
	DDX_Control(pDX, IDC_BT_TRANS_ALPHA_OL, m_btTranAlpha);
	DDX_Control(pDX, IDC_BT_COL_PAL_OL, m_btColPal);
	DDX_Control(pDX, IDC_BT_COL_IMP_OL, m_btColImp);
	DDX_Text(pDX, IDC_ED_TRANS_OL, m_edOLTrans);
	DDV_MinMaxDWord(pDX, m_edOLTrans, 0, 100);
	DDX_Text(pDX, IDC_ED_OL1_FEATHER, m_edFeather);
	DDX_Text(pDX, IDC_ED_OL1_SIZE, m_edSize);
	DDX_Text(pDX, IDC_ED_OL1_XOFFSET, m_edXOffset);
	DDX_Text(pDX, IDC_ED_OL1_YOFFSET, m_edYOffset);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOutline1, CDialog)
	//{{AFX_MSG_MAP(CDlgOutline1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_TRANS_OL, OnDeltaposSpnTrans)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL1_FEATHER, OnDeltaposSpnOl1Feather)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL1_SIZE, OnDeltaposSpnOl1Size)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL1_X_OFFSET, OnDeltaposSpnOl1XOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL1_Y_OFFSET, OnDeltaposSpnOl1YOffset)
	ON_BN_CLICKED(IDC_BT_COL_IMP_OL, OnBtColImpOl)
	ON_BN_CLICKED(IDC_BT_COL_PAL_OL, OnBtColorPal)
	ON_BN_CLICKED(IDC_BT_TRANS_ALPHA_OL, OnBtTransAlphaOl)
	ON_BN_CLICKED(IDC_BT_TRANS_IMP_OL, OnBtTransImpOl)
	ON_BN_CLICKED(IDC_BT_TRANS_PAL_OL, OnBtTransPalOl)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CK_OL1_ENABLE, OnCkOl1Enable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOutline1 message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnOK() 
{
	// TODO: Add extra validation here
	DWORD	edValue = GetDlgItemInt( IDC_ED_TRANS_OL, NULL, 0 );
	if( edValue != m_edOLTrans )
	{
		m_edOLTrans = edValue;
		TRACE( _T("\t m_dwEOLTans  = %d\n"), m_edOLTrans );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE1_VISIBILITY, m_edOLTrans);
		
	}
	edValue = GetDlgItemInt( IDC_ED_OL1_SIZE, NULL, 0 );
	if( edValue != m_edSize )
	{
		m_edSize = edValue;
		TRACE( _T("\t m_edSize  = %d\n"), m_edSize );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE1_SIZE, m_edSize);
	}
	edValue = GetDlgItemInt( IDC_ED_OL1_FEATHER, NULL, 0 );
	if( edValue != m_edFeather )
	{
		m_edFeather = edValue;
		TRACE( _T("\t m_edFeather  = %d\n"), m_edFeather );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE1_BLUR, m_edFeather);
	}

	edValue = GetDlgItemInt( IDC_ED_OL1_XOFFSET, NULL, 0 );
	if( edValue != m_edXOffset )
	{
		m_edXOffset = edValue;
		TRACE( _T("\t m_edXOffset  = %d\n"), m_edXOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_OL1_YOFFSET, NULL, 0 );
	if( edValue != m_edYOffset )
	{
		m_edYOffset = edValue;
		TRACE( _T("\t m_edYOffset  = %d\n"), m_edYOffset );
	}
	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline1::OnOK() 

/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnCancel() 
{
	// capture cancel message
}//end of CDlgOutline1::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgOutline1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	g_dwAttrib = ABMC_OUTLINE1_COLOR;
	
	InitButtonIcon();
	InitEditSpinControl();
	InitStaticIcon();

	//++++++++++++++++++++++++++++++++++++++++Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgOutline1::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE1_VISIBILITY, (max(0, val)));
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline1::OnDeltaposSpnTrans
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnDeltaposSpnOl1Feather(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE1_BLUR, (max(0, val)));
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline1::OnDeltaposSpnOl1Feather
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnDeltaposSpnOl1Size(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE1_SIZE, max(0,val) );

	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline1::OnDeltaposSpnOl1Size
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnDeltaposSpnOl1XOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline1::OnDeltaposSpnOl1XOffset
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnDeltaposSpnOl1YOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline1::OnDeltaposSpnOl1YOffset
/////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::InitDlgItemTextNTooltip()
{
	HFONT hFont = NULL;
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgOutline1.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		m_hFont[i] = NULL; // initial m_hFont
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr
			( txtData[i].szTT, _T("IDC_STC_OL_COLOR") ) )
			txtData[i].idTT = IDC_STC_OL_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_OL_TRANS") ) )
				txtData[i].idTT = IDC_STC_OL_TRANS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_TRANS_OL") ) )
			{
				txtData[i].idTT = IDC_ED_TRANS_OL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL1_SIZE") ) )
			{
				txtData[i].idTT = IDC_ED_OL1_SIZE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL1_XOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_OL1_XOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL1_YOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_OL1_YOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL1_FEATHER") ) )
			{
				txtData[i].idTT = IDC_ED_OL1_FEATHER;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_IMP_OL") ) )
				txtData[i].idTT = IDC_BT_COL_IMP_OL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_PAL_OL") ) )
				txtData[i].idTT = IDC_BT_COL_PAL_OL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_IMP_OL") ) )
				txtData[i].idTT = IDC_BT_TRANS_IMP_OL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_PAL_OL") ) )
				txtData[i].idTT = IDC_BT_TRANS_PAL_OL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_ALPHA_OL") ) )
				txtData[i].idTT = IDC_BT_TRANS_ALPHA_OL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_OL1_ENABLE") ) )
				txtData[i].idTT = IDC_CK_OL1_ENABLE;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgOutline1::InitDlgItemTextNTooltip()
/////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgOutline1::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);	
}//end of CDlgOutline1::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnBtColImpOl() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_OUTLINE1_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline1::OnBtColImpOl
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnBtColorPal() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_COL_PAL_OL );        
    nRet = dlgPal.DoModal();   // Create and show the dialog box   
    switch ( nRet )	// Handle the return value from DoModal
    {
    case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));
        break;
    case IDABORT:
        // Do something
        break;
    case IDOK:
        // Do something
        break;
    case IDCANCEL:
        // Do something
        break;
    default:
        // Do something
        break;
    };

	AfxGetMainWnd()->SetFocus();	
}//end of CDlgOutline1::OnBtColorPal
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnBtTransAlphaOl() 
{
	m_bAlpha ^= 1;
	m_btTranAlpha.SetCheck( m_bAlpha );
	g_dwAttrib = m_bAlpha ? ABMC_OUTLINE1_ALPHA : ABMC_OUTLINE1_COLOR;

// 092500 - add a pop up message dlg
	//pDialog initialized to NULL in the constructor of CMyWnd class
	if( m_pDlg != NULL )
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}

	if( m_bAlpha )
	{
		m_pDlg = new CAlphaDlg();
		//Check if new succeeded and we got a valid pointer to a dialog object
		if( m_pDlg != NULL)
		{
		   BOOL ret = m_pDlg->Create(IDD_ALPHA_BOX,this);
		   if(!ret)   //Create failed.
			  AfxMessageBox(_T("Error creating Dialog"));		   
		   m_pDlg->ShowWindow(SW_SHOW);
		}
		else
		   AfxMessageBox(_T("Error Creating Dialog Object"));
	}//end of if - m_bAlpha

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline1::
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnBtTransImpOl() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_OUTLINE1_ALPHA_MASK );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline1::OnBtTransImpOl
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnBtTransPalOl() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_TRANS_PAL_OL );
    nRet = dlgPal.DoModal();   // Create and show the dialog box   
    switch ( nRet )	// Handle the return value from DoModal
    {
    case -1: 
		AfxMessageBox(_T("Dialog box could not be created!"));
        break;
    case IDABORT:
        // Do something
        break;
    case IDOK:
        // Do something
        break;
    case IDCANCEL:
        // Do something
        break;
    default:
        // Do something
        break;
    };

	AfxGetMainWnd()->SetFocus();	
}//end of CDlgOutline1::OnBtTransPalOl
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::InitButtonIcon()
{
	HICON rv = m_btColPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	rv = m_btColImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranAlpha.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ALPHA), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );

	// Initial the Enable check box icon
	if( CGS_GetValDbl( EDIT_OBJ_FACE_ENABLE ) )
	{
		m_ckOL1Enable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		m_ckOL1Enable.SetCheck( 1 );
	}
	else
	{
		m_ckOL1Enable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		m_ckOL1Enable.SetCheck( 0 );
	}
}//end of CDlgOutline1::InitButtonIcon()
/////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_TRANS_OL );
	pSpin->SetRange( 0, 255 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL1_SIZE );
	pSpin->SetRange( 0, 99 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL1_FEATHER );
	pSpin->SetRange( 0, 32 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL1_X_OFFSET );
	pSpin->SetRange( -128, 128 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL1_Y_OFFSET );
	pSpin->SetRange( -128, 128 );

	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TRANS_OL );
	pEdCtrl->SetLimitText( 3 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_TRANS_OL, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_VISIBILITY), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL1_SIZE );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 99
	int val = (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_SIZE);
	SetDlgItemInt(IDC_ED_OL1_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_SIZE), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL1_FEATHER );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	SetDlgItemInt(IDC_ED_OL1_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_BLUR), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL1_XOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL1_YOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128

}//end of CDlgOutline1::InitEditSpinControl()
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::InitStaticIcon()
{
	m_stcSize.ModifyStyle( 0, SS_ICON );
	m_stcSize.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
									MAKEINTRESOURCE( IDI_SIZE ), IMAGE_ICON, 16, 16, 0 ) );
	m_stcFeather.ModifyStyle( 0, SS_ICON );
	m_stcFeather.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
									MAKEINTRESOURCE( IDI_FEATHER ),	IMAGE_ICON, 16, 16, 0 ) );
	m_stcXOffset.ModifyStyle( 0, SS_ICON );
	m_stcXOffset.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
									MAKEINTRESOURCE( IDI_X_OFFSET ), IMAGE_ICON, 16, 16, 0 ) );
	m_stcYOffset.ModifyStyle( 0, SS_ICON );
	m_stcYOffset.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
									MAKEINTRESOURCE( IDI_Y_OFFSET ),IMAGE_ICON, 16, 16, 0 ) );
}//end of CDlgOutline1::InitStaticIcon()
//////////////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::DoValueUpdate()
{
	SetDlgItemInt(IDC_ED_TRANS_OL, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_VISIBILITY), 0 );
	SetDlgItemInt(IDC_ED_OL1_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_SIZE), 0 );
	SetDlgItemInt(IDC_ED_OL1_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE1_BLUR), 0 );

	if( m_bAlpha )
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_OL)->m_hWnd, 2,EDIT_OBJ_OUTLINE1_ALPHA_MASK );
	else
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_OL)->m_hWnd, 2,EDIT_OBJ_OUTLINE1_COLORSCHEME );


	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline1::DoValueUpdate()
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	g_dwAttrib = m_bAlpha ? ABMC_OUTLINE1_ALPHA : ABMC_OUTLINE1_COLOR;
	TRACE1("CDlgOutline1::OnPaint() - g_dwAttrib = %d\n", g_dwAttrib ); 

	CGS_EditUpdateCurColorSample( (DWORD)GetDlgItem(IDC_FRM_TRANS_OL)->m_hWnd, 2,EDIT_OBJ_OUTLINE1_ALPHA_MASK );
	CGS_EditUpdateCurColorSample( (DWORD)GetDlgItem(IDC_FRM_COLOR_OL)->m_hWnd, 2,EDIT_OBJ_OUTLINE1_COLORSCHEME );	
}//end of CDlgOutline1::OnPaint
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline1::UnCheckAlphaButton()
{
	m_btTranAlpha.SetCheck( m_bAlpha = 0 );
//	g_dwAttrib = ABMC_OUTLINE1_COLOR;

	if( m_pDlg != NULL ) // delete the pop up alpha dialog box
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}//end of if

}//end of CDlgOutline1::UnCheckAlphaButton()
/////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline1::OnCkOl1Enable() 
{
	if( m_ckOL1Enable.GetCheck() )
	{
		m_ckOL1Enable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_OUTLINE1_ENABLE, (double)1.0 );
	}
	else
	{
		m_ckOL1Enable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_OUTLINE1_ENABLE, (double)0.0 );
	}

	AfxGetMainWnd()->SetFocus();		
}//end of CDlgOutline1::OnCkOl1Enable
