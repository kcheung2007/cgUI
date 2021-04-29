/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgOutline2.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgOutline2.h"
#include "Global.h"
#include "PalDlg.h"
#include "FileReq.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOutline2 dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_dwAttrib;

CDlgOutline2::CDlgOutline2(CWnd* pParent /*=NULL*/): CDialog(CDlgOutline2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOutline2)
	m_edOL2Trans = 0;
	m_edFeather  = 0;
	m_edSize	 = 0;
	m_edXOffset  = 0;
	m_edYOffset  = 0;
	//}}AFX_DATA_INIT
	m_bAlpha	 = 0;
	g_dwAttrib	 = ABMC_OUTLINE2_COLOR;
	m_pDlg		 = NULL;
	m_hFont		 = NULL;

}
CDlgOutline2::~CDlgOutline2()
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

void CDlgOutline2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOutline2)
	DDX_Control(pDX, IDC_CK_OL2_ENABLE, m_ckOL2Enable);
	DDX_Control(pDX, IDC_STC_OL2_YOFFSET, m_stcYOffset);
	DDX_Control(pDX, IDC_STC_OL2_XOFFSET, m_stcXOffset);
	DDX_Control(pDX, IDC_STC_OL2_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_STC_OL2_FEATHER, m_stcFeather);
	DDX_Control(pDX, IDC_BT_TRANS_PAL_OL2, m_btTranPal);
	DDX_Control(pDX, IDC_BT_TRANS_IMP_OL2, m_btTranImp);
	DDX_Control(pDX, IDC_BT_TRANS_ALPHA_OL2, m_btTranAlpha);
	DDX_Control(pDX, IDC_BT_COL_PAL_OL2, m_btColPal);
	DDX_Control(pDX, IDC_BT_COL_IMP_OL2, m_btColImp);
	DDX_Text(pDX, IDC_ED_TRANS_OL2, m_edOL2Trans);
	DDV_MinMaxDWord(pDX, m_edOL2Trans, 0, 100);
	DDX_Text(pDX, IDC_ED_OL2_FEATHER, m_edFeather);
	DDX_Text(pDX, IDC_ED_OL2_SIZE, m_edSize);
	DDX_Text(pDX, IDC_ED_OL2_XOFFSET, m_edXOffset);
	DDX_Text(pDX, IDC_ED_OL2_YOFFSET, m_edYOffset);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOutline2, CDialog)
	//{{AFX_MSG_MAP(CDlgOutline2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_TRANS_OL2, OnDeltaposSpnTrans)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL2_FEATHER, OnDeltaposSpnOl2Feather)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL2_SIZE, OnDeltaposSpnOl2Size)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL2_X_OFFSET, OnDeltaposSpnOl2XOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_OL2_Y_OFFSET, OnDeltaposSpnOl2YOffset)
	ON_BN_CLICKED(IDC_BT_COL_IMP_OL2, OnBtColImpOl2)
	ON_BN_CLICKED(IDC_BT_COL_PAL_OL2, OnBtColorPal)
	ON_BN_CLICKED(IDC_BT_TRANS_ALPHA_OL2, OnBtTransAlphaOl2)
	ON_BN_CLICKED(IDC_BT_TRANS_IMP_OL2, OnBtTransImpOl2)
	ON_BN_CLICKED(IDC_BT_TRANS_PAL_OL2, OnBtTransPalOl2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CK_OL2_ENABLE, OnCkOl2Enable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOutline2 message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnOK() 
{
	// TODO: Add extra validation here
	DWORD	edValue = GetDlgItemInt( IDC_ED_TRANS_OL2, NULL, 0 );
	if( edValue != m_edOL2Trans )
	{
		m_edOL2Trans = edValue;
		TRACE( _T("\t m_edOL2Trans = %d\n"), m_edOL2Trans );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE2_VISIBILITY, m_edOL2Trans);
	}

	edValue = GetDlgItemInt( IDC_ED_OL2_SIZE, NULL, 0 );
	if( edValue != m_edSize )
	{
		m_edSize = edValue;
		TRACE( _T("\t m_edSize = %d\n"), m_edSize );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE2_SIZE, m_edSize);
	}

	edValue = GetDlgItemInt( IDC_ED_OL2_FEATHER, NULL, 0 );
	if( edValue != m_edFeather )
	{
		m_edFeather = edValue;
		TRACE( _T("\t m_edFeather = %d\n"), m_edFeather );
		CGS_SetValDbl(EDIT_OBJ_OUTLINE2_BLUR, m_edFeather);
	}

	edValue = GetDlgItemInt( IDC_ED_OL2_XOFFSET, NULL, 0 );
	if( edValue != m_edXOffset )
	{
		m_edXOffset = edValue;
		TRACE( _T("\t m_edXOffset = %d\n"), m_edXOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_OL2_YOFFSET, NULL, 0 );
	if( edValue != m_edYOffset )
	{
		m_edYOffset = edValue;
		TRACE( _T("\t m_edYOffset = %d\n"), m_edYOffset );
	}
	AfxGetMainWnd()->SetFocus();

}//end of CDlgOutline2::OnOK() 

/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnCancel() 
{
	// capture cancel message
}//end of CDlgOutline2::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgOutline2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitButtonIcon();
	InitEditSpinControl();
	InitStaticIcon();

	//++++++++++++++++++++++++++++++++++++++++Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgOutline2::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE2_VISIBILITY, max(0, val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline2::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnDeltaposSpnOl2Feather(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE2_BLUR, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline2::OnDeltaposSpnOl2Feather
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnDeltaposSpnOl2Size(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_OUTLINE2_SIZE, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline2::OnDeltaposSpnOl2Size
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnDeltaposSpnOl2XOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline2::OnDeltaposSpnOl2XOffset
/////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnDeltaposSpnOl2YOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgOutline2::OnDeltaposSpnOl2YOffset
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgOutline2::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	
}//end of CDlgOutline2::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgOutline2.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_OL2_COLOR") ) )
			txtData[i].idTT = IDC_STC_OL2_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_OL2_TRANS") ) )
				txtData[i].idTT = IDC_STC_OL2_TRANS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_TRANS_OL2") ) )
			{
				txtData[i].idTT = IDC_ED_TRANS_OL2;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL2_SIZE") ) )
			{
				txtData[i].idTT = IDC_ED_OL2_SIZE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL2_XOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_OL2_XOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL2_YOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_OL2_YOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_OL2_FEATHER") ) )
			{
				txtData[i].idTT = IDC_ED_OL2_FEATHER;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_IMP_OL2") ) )
				txtData[i].idTT = IDC_BT_COL_IMP_OL2;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_PAL_OL2") ) )
				txtData[i].idTT = IDC_BT_COL_PAL_OL2;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_IMP_OL2") ) )
				txtData[i].idTT = IDC_BT_TRANS_IMP_OL2;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_PAL_OL2") ) )
				txtData[i].idTT = IDC_BT_TRANS_PAL_OL2;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_ALPHA_OL2") ) )
				txtData[i].idTT = IDC_BT_TRANS_ALPHA_OL2;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_OL2_ENABLE") ) )
				txtData[i].idTT = IDC_CK_OL2_ENABLE;

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgOutline2::InitDlgItemTextNTooltip
///////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnBtColImpOl2() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_OUTLINE2_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline2::OnBtColImpOl2
///////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnBtColorPal() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_COL_PAL_OL2 );
    nRet = dlgPal.DoModal();     // Create and show the dialog box   
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

}//end of CDlgOutline2::OnBtColorPal
///////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnBtTransAlphaOl2() 
{
	m_bAlpha ^= 1;
	m_btTranAlpha.SetCheck( m_bAlpha );
	g_dwAttrib = m_bAlpha ? ABMC_OUTLINE2_ALPHA : ABMC_OUTLINE2_COLOR;

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
}//end of CDlgOutline2::OnBtTransAlphaOl2
///////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnBtTransImpOl2() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_OUTLINE2_ALPHA_MASK );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline2::OnBtTransImpOl2
///////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnBtTransPalOl2() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_TRANS_PAL_OL2 );       
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
}//end of CDlgOutline2::OnBtTransPalOl2
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::InitButtonIcon()
{
	HICON rv = m_btColPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	rv = m_btColImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranAlpha.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ALPHA), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );

	// Initial the Enable check box icon
	if( CGS_GetValDbl( EDIT_OBJ_OUTLINE2_ENABLE ) )
	{
		m_ckOL2Enable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		m_ckOL2Enable.SetCheck( 1 );
	}
	else
	{
		m_ckOL2Enable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		m_ckOL2Enable.SetCheck( 0 );
	}
}//end of CDlgOutline2::InitButtonIcon()
/////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_TRANS_OL2 );
	pSpin->SetRange( 0, 255 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL2_SIZE );
	pSpin->SetRange( 0, 99 );	

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL2_FEATHER );
	pSpin->SetRange( 0, 32 );
	
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL2_X_OFFSET );
	pSpin->SetRange( -128, 128 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_OL2_Y_OFFSET );
	pSpin->SetRange( -128, 128 );

	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TRANS_OL2 );
	pEdCtrl->SetLimitText( 3 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_TRANS_OL2, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_VISIBILITY), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL2_SIZE );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_OL2_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_SIZE), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL2_FEATHER );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	SetDlgItemInt(IDC_ED_OL2_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_BLUR), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL2_XOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_OL2_YOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128

}//end of CDlgOutline2::InitEditSpinControl()
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::InitStaticIcon()
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
							MAKEINTRESOURCE( IDI_Y_OFFSET ), IMAGE_ICON, 16, 16, 0 ) );
//	m_stcOutLn2CK.ModifyStyle( 0, SS_ICON );
//	m_stcOutLn2CK.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,
//							MAKEINTRESOURCE( IDI_Y_OFFSET ), IMAGE_ICON, 16, 16, 0 ) );
}//end of CDlgOutline2::InitStaticIcon()
//////////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::DoValueUpdate()
{
	SetDlgItemInt(IDC_ED_TRANS_OL2, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_VISIBILITY), 0 );
	SetDlgItemInt(IDC_ED_OL2_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_SIZE), 0 );
	SetDlgItemInt(IDC_ED_OL2_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_OUTLINE2_BLUR), 0 );

	if( m_bAlpha )
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_OL2)->m_hWnd, 2,EDIT_OBJ_OUTLINE2_ALPHA_MASK );
	else
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_OL2)->m_hWnd, 2, EDIT_OBJ_OUTLINE2_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgOutline2::DoValueUpdate()
//////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	g_dwAttrib = m_bAlpha ? ABMC_OUTLINE2_ALPHA : ABMC_OUTLINE2_COLOR;
	TRACE1("CDlgOutline2::OnPaint() - g_dwAttrib = %d\n", g_dwAttrib ); 

	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_OL2)->m_hWnd,2, EDIT_OBJ_OUTLINE2_ALPHA_MASK );
	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_OL2)->m_hWnd, 2,EDIT_OBJ_OUTLINE2_COLORSCHEME );
	
}//end of CDlgOutline2::OnPaint
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgOutline2::UnCheckAlphaButton()
{
	m_btTranAlpha.SetCheck( m_bAlpha = 0 );
//	g_dwAttrib = ABMC_OUTLINE2_COLOR;

	if( m_pDlg != NULL ) // delete the pop up alpha dialog box
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}//end of if

}//end of CDlgOutline2::UnCheckAlphaButton()
//////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgOutline2::OnCkOl2Enable() 
{
	if( m_ckOL2Enable.GetCheck() )
	{
		m_ckOL2Enable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_OUTLINE2_ENABLE, (double)1.0 );
	}
	else
	{
		m_ckOL2Enable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_OUTLINE2_ENABLE, (double)0.0 );
	}

	AfxGetMainWnd()->SetFocus();
}// end of CDlgOutline2::OnCkOl2Enable()
