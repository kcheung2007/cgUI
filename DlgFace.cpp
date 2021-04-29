/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgFace.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgFace.h"
#include "Global.h"
#include "PalDlg.h"
#include "ACGS_Inc\\CGServerDll.h"
#include "FileReq.h"
#include "switch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFace dialog
extern	TCHAR	UILang_UIFont[256];
extern	int		UILang_UIFontSize;
extern	DWORD	g_dwAttrib;

CDlgFace::CDlgFace(CWnd* pParent /*=NULL*/)	: CDialog(CDlgFace::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFace)
	m_edFaTrans = 0;
	m_edFeather = 0;
	//}}AFX_DATA_INIT
	m_bAlpha	= 0; // non-alpha state
	g_dwAttrib	= ABMC_FACE_COLOR;
	m_pDlg		= NULL;
	m_hFont		= NULL;
}

CDlgFace::~CDlgFace()
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

void CDlgFace::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFace)
	DDX_Control(pDX, IDC_CK_FA_ENABLE, m_ckFaEnable);
	DDX_Control(pDX, IDC_SPN_FA_FEATHER, m_spnFeather);
	DDX_Control(pDX, IDC_ED_FA_FEATHER, m_ctlFeather);
	DDX_Control(pDX, IDC_STC_FA_FEATHER, m_stcFeather);
	DDX_Control(pDX, IDC_BT_TRANS_PAL_FA, m_btTranPal);
	DDX_Control(pDX, IDC_BT_TRANS_IMP_FA, m_btTranImp);
	DDX_Control(pDX, IDC_BT_TRANS_ALPHA_FA, m_btTranAlpha);
	DDX_Control(pDX, IDC_BT_COL_PAL_FA, m_btColPal);
	DDX_Control(pDX, IDC_BT_COL_IMP_FA, m_btColImp);
	DDX_Text(pDX, IDC_ED_TRANS_FA, m_edFaTrans);
	DDV_MinMaxDWord(pDX, m_edFaTrans, 0, 100);
	DDX_Text(pDX, IDC_ED_FA_FEATHER, m_edFeather);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgFace, CDialog)
	//{{AFX_MSG_MAP(CDlgFace)
	ON_BN_CLICKED(IDC_BT_TRANS_PAL_FA, OnBtTransPal)
	ON_BN_CLICKED(IDC_BT_TRANS_IMP_FA, OnBtTransImport)
	ON_BN_CLICKED(IDC_BT_TRANS_ALPHA_FA, OnBtTransAlpha)
	ON_BN_CLICKED(IDC_BT_COL_IMP_FA, OnBtColorImport)
	ON_BN_CLICKED(IDC_BT_COL_PAL_FA, OnBtColorPal)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_TRANS_FA, OnDeltaposSpnTrans)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_FA_FEATHER, OnDeltaposSpnFaFeather)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CK_FA_ENABLE, OnCkFaEnable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgFace message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnOK() 
{
	// TODO: Add extra validation here
	DWORD	edValue = GetDlgItemInt( IDC_ED_TRANS_FA, NULL, 0 );
	if( edValue != m_edFaTrans )
	{
		m_edFaTrans = edValue;
		TRACE(_T("\tm_dwEdMm = %d\n"), m_edFaTrans );
		CGS_SetValDbl(EDIT_OBJ_FACE_VISIBILITY, m_edFaTrans);
	}

	edValue = GetDlgItemInt( IDC_ED_FA_FEATHER, NULL, 0 );
	if( edValue != m_edFeather )
	{
		m_edFeather = edValue;
		TRACE(_T("\tm_edFeather = %d\n"), m_edFeather );
		CGS_SetValDbl(EDIT_OBJ_FACE_BLUR, m_edFeather);
	}

	AfxGetMainWnd()->SetFocus();

}//end of CDlgFace::OnOK() 
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnCancel() 
{
	// capture cancel message
}//end of CDlgFace::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnBtTransPal() 
{
	int nRet = -1;
	CPalDlg dlgPal;

    dlgPal.SetPaletteState( IDC_BT_TRANS_PAL_FA );
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
}//end of CDlgFace::OnBtTransPal
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnBtTransImport() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_FACE_ALPHA_MASK );

	AfxGetMainWnd()->SetFocus();}//end of CDlgFace::OnBtTransImport
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnBtTransAlpha() 
{
	m_bAlpha ^= 1;
	m_btTranAlpha.SetCheck( m_bAlpha );
	g_dwAttrib = m_bAlpha ? ABMC_FACE_ALPHA : ABMC_FACE_COLOR;

// 081600 - add a pop up message dlg
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
}//end of CDlgFace::OnBtTransAlpha
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnBtColorImport() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_FACE_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgFace::OnBtColorImport
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnBtColorPal() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_COL_PAL_FA );    
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
}//end of CDlgFace::OnBtColorPal
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgFace::OnInitDialog() 
{
	CDialog::OnInitDialog();

	g_dwAttrib = ABMC_FACE_COLOR;
	
	InitButtonIcon();
	InitEditSpinControl();
	InitStaticIcon();

	//++++++++++++++++++++++++++++++++++++++++Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	HideControls();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgFace::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	(int)CGS_SetValDbl(EDIT_OBJ_FACE_VISIBILITY, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgFace::OnDeltaposSpnTrans
/////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnDeltaposSpnFaFeather(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	(int)CGS_SetValDbl(EDIT_OBJ_FACE_BLUR, max(0, val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgFace::OnDeltaposSpnFaFeather
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgFace::PreTranslateMessage(MSG* pMsg)
{
	// Let the ToolTip process this message.
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CDlgFace::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////
VOID CDlgFace::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR		sep[] = _T("\"");
	TCHAR*		ptID;
	TCHAR*		ptTT;
	TCHAR*		ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgFace.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_FACE_COLOR") ) )
			txtData[i].idTT = IDC_STC_FACE_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_FACE_TRANS") ) )
				txtData[i].idTT = IDC_STC_FACE_TRANS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_FA_ENABLE") ) )
				txtData[i].idTT = IDC_CK_FA_ENABLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_TRANS_FA") ) )
			{
				txtData[i].idTT = IDC_ED_TRANS_FA;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_FA_FEATHER") ) )
			{
				txtData[i].idTT = IDC_ED_FA_FEATHER;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_IMP_FA") ) )
				txtData[i].idTT = IDC_BT_COL_IMP_FA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_PAL_FA") ) )
				txtData[i].idTT = IDC_BT_COL_PAL_FA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_IMP_FA") ) )
				txtData[i].idTT = IDC_BT_TRANS_IMP_FA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_PAL_FA") ) )
				txtData[i].idTT = IDC_BT_TRANS_PAL_FA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_ALPHA_FA") ) )
				txtData[i].idTT = IDC_BT_TRANS_ALPHA_FA;

		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
		SetDlgItemText( txtData[i].idTT, (TCHAR*)ptTT );

SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgFace::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////
// Initial button icon
VOID CDlgFace::InitButtonIcon()
{	
	HICON rv = m_btColPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	rv = m_btColImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranAlpha.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ALPHA), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );

	// Initial the Enable check box icon
	if( CGS_GetValDbl( EDIT_OBJ_FACE_ENABLE ) )
	{
		m_ckFaEnable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		m_ckFaEnable.SetCheck( 1 );
	}
	else
	{
		m_ckFaEnable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		m_ckFaEnable.SetCheck( 0 );
	}
}//end of CDlgFace::InitButtonIcon()
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgFace::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_TRANS_FA );
	pSpin->SetRange( 0, 255 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_FA_FEATHER );
	pSpin->SetRange( 0, 32 );

	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TRANS_FA );
	pEdCtrl->SetLimitText( 3 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_TRANS_FA, (int)CGS_GetValDbl(EDIT_OBJ_FACE_VISIBILITY), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_FA_FEATHER );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	SetDlgItemInt(IDC_ED_FA_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_FACE_BLUR), 0 );

}//end of CDlgFace::InitEditSpinControl()
///////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgFace::InitStaticIcon()
{
	m_stcFeather.ModifyStyle( 0, SS_ICON );
	m_stcFeather.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE( IDI_FEATHER ),	IMAGE_ICON, 16, 16, 0 ) );
}//end of CDlgFace::InitStaticIcon()
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgFace::DoValueUpdate()
{	
	TRACE0("DlgFace.cpp - CDlgFace::DoValueUpdate()\n" );
	SetDlgItemInt(IDC_ED_TRANS_FA, (int)CGS_GetValDbl(EDIT_OBJ_FACE_VISIBILITY), 0 );
	SetDlgItemInt(IDC_ED_FA_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_FACE_BLUR), 0 );

	// TO DO : call core to draw the boxes
	if( m_bAlpha )
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_FA)->m_hWnd,2, EDIT_OBJ_FACE_ALPHA_MASK );
	else
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_FA)->m_hWnd,2, EDIT_OBJ_FACE_COLORSCHEME );
	

	AfxGetMainWnd()->SetFocus();
}//end of CDlgFace::DoValueUpdate()
//////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CDlgFace::GetAlphaState()
{
	return( m_bAlpha );
}//end of CDlgFace::GetAlphaState()
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	g_dwAttrib = m_bAlpha ? ABMC_FACE_ALPHA : ABMC_FACE_COLOR;
	TRACE2("CDlgFace::OnPaint() - g_dwAttrib = %d, m_bAlpha = &d\n", g_dwAttrib, m_bAlpha ); 

	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_FA)->m_hWnd, 2, EDIT_OBJ_FACE_ALPHA_MASK );
	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_FA)->m_hWnd, 2, EDIT_OBJ_FACE_COLORSCHEME );
}// end of CDlgFace::OnPaint()
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgFace::UnCheckAlphaButton()
{
	m_btTranAlpha.SetCheck( m_bAlpha = 0 );
//	g_dwAttrib = ABMC_FACE_COLOR;

	if( m_pDlg != NULL ) // delete the pop up alpha dialog box
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}//end of if

}//end of CDlgFace::UnCheckAlphaButton()
///////////////////////////////////////////////////////////////////////////////////////////////
// Hide individual control on Face dialog only base on switch.h file.
VOID CDlgFace::HideControls()
{
	if( HIDE_FACE_ATTRIB ) // define the option flag here
	{
		m_ctlFeather.ShowWindow( SW_HIDE );
		m_stcFeather.ShowWindow( SW_HIDE );
		m_spnFeather.ShowWindow( SW_HIDE );
	}//end of - HIDE_FACE_ATTRIB

}//end of CDlgFace::HideControls()
///////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgFace::OnCkFaEnable() 
{
	if( m_ckFaEnable.GetCheck() )
	{
		m_ckFaEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_FACE_ENABLE, (double)1.0 );
	}
	else
	{
		m_ckFaEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));	
		CGS_SetValDbl( EDIT_OBJ_FACE_ENABLE, (double)0.0 );
	}

	AfxGetMainWnd()->SetFocus();
}//end of CDlgFace::OnCkFaEnable
