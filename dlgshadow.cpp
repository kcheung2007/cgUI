/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// DlgShadow1.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgShadow.h"
#include "Global.h"
#include "PalDlg.h"
#include "FileReq.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow dialog

extern TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;
extern DWORD	g_dwAttrib;

CDlgShadow::CDlgShadow(CWnd* pParent /*=NULL*/)	: CDialog(CDlgShadow::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShadow)
	m_edSdTrans = 0;
	m_edXOffset = 0;
	m_edYOffset = 0;
	m_edFeather = 0;
	m_edSize	= 0;
	//}}AFX_DATA_INIT
	m_bAlpha	= 0;
	g_dwAttrib	= ABMC_SHADOW1_COLOR;
	m_pDlg		= NULL;
}
CDlgShadow::~CDlgShadow()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;

	if( m_pDlg != NULL )
		delete m_pDlg;
}
void CDlgShadow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShadow)
	DDX_Control(pDX, IDC_CK_SD_ENABLE, m_ckSdEnable);
	DDX_Control(pDX, IDC_RB_DIRECT_UR, m_rbUpRight);
	DDX_Control(pDX, IDC_RB_DIRECT_U, m_rbUp);
	DDX_Control(pDX, IDC_RB_DIRECT_L, m_rbLeft);
	DDX_Control(pDX, IDC_RB_DIRECT_UL, m_rbUpLeft);
	DDX_Control(pDX, IDC_RB_DIRECT_R, m_rbRight);
	DDX_Control(pDX, IDC_RB_DIRECT_DR, m_rbDownRight);
	DDX_Control(pDX, IDC_RB_DIRECT_DL, m_rbDownLeft);
	DDX_Control(pDX, IDC_RB_DIRECT_D, m_rbDown);
	DDX_Control(pDX, IDC_RB_DIRECT_C, m_rbCenter);
	DDX_Control(pDX, IDC_STC_SD_FEATHER, m_stcFeather);
	DDX_Control(pDX, IDC_STC_SD_YOFFSET, m_stcYOffset);
	DDX_Control(pDX, IDC_STC_SD_XOFFSET, m_stcXOffset);
	DDX_Control(pDX, IDC_STC_SD_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_BT_TRANS_PAL_SD, m_btTranPal);
	DDX_Control(pDX, IDC_BT_TRANS_IMP_SD, m_btTranImp);
	DDX_Control(pDX, IDC_BT_TRANS_ALPHA_SD, m_btTranAlpha);
	DDX_Control(pDX, IDC_BT_COL_PAL_SD, m_btColPal);
	DDX_Control(pDX, IDC_BT_COL_IMP_SD, m_btColImp);
	DDX_Text(pDX, IDC_ED_TRANS_SD, m_edSdTrans);
	DDV_MinMaxDWord(pDX, m_edSdTrans, 0, 100);
	DDX_Text(pDX, IDC_ED_SD_XOFFSET, m_edXOffset);
	DDX_Text(pDX, IDC_ED_SD_YOFFSET, m_edYOffset);
	DDX_Text(pDX, IDC_ED_SD_FEATHER, m_edFeather);
	DDV_MinMaxDWord(pDX, m_edFeather, 0, 32);
	DDX_Text(pDX, IDC_ED_SD_SIZE, m_edSize);
	DDV_MinMaxDWord(pDX, m_edSize, 0, 99);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShadow, CDialog)
	//{{AFX_MSG_MAP(CDlgShadow)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_TRANS_SD, OnDeltaposSpnTrans)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_FEATHER, OnDeltaposSpnFeather)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SIZE, OnDeltaposSpnSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_X_OFFSET, OnDeltaposSpnXOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_Y_OFFSET, OnDeltaposSpnYOffset)
	ON_BN_CLICKED(IDC_BT_COL_IMP_SD, OnBtColImpSd)
	ON_BN_CLICKED(IDC_BT_COL_PAL_SD, OnBtColPalSd)
	ON_BN_CLICKED(IDC_BT_TRANS_ALPHA_SD, OnBtTransAlphaSd)
	ON_BN_CLICKED(IDC_BT_TRANS_IMP_SD, OnBtTransImpSd)
	ON_BN_CLICKED(IDC_BT_TRANS_PAL_SD, OnBtTransPalSd)
	ON_BN_CLICKED(IDC_RB_DIRECT_UL, OnRbDirectUL)
	ON_BN_CLICKED(IDC_RB_DIRECT_U, OnRbDirectU)
	ON_BN_CLICKED(IDC_RB_DIRECT_UR, OnRbDirectUR)
	ON_BN_CLICKED(IDC_RB_DIRECT_L, OnRbDirectL)
	ON_BN_CLICKED(IDC_RB_DIRECT_C, OnRbDirectC)
	ON_BN_CLICKED(IDC_RB_DIRECT_R, OnRbDirectR)
	ON_BN_CLICKED(IDC_RB_DIRECT_DL, OnRbDirectDL)
	ON_BN_CLICKED(IDC_RB_DIRECT_D, OnRbDirectD)
	ON_BN_CLICKED(IDC_RB_DIRECT_DR, OnRbDirectDR)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CK_SD_ENABLE, OnCkSdEnable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShadow message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnCancel() 
{
	AfxGetMainWnd()->SetFocus();

}//end of CDlgShadow::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnOK() 
{
	// TODO: Add extra validation here
	DWORD	edValue = GetDlgItemInt( IDC_ED_TRANS_SD, NULL, 0 );
	if( edValue != m_edSdTrans )
	{
		m_edSdTrans = edValue;
		TRACE( _T("\t m_dwEdMm = %d\n"), m_edSdTrans );
		CGS_SetValDbl(EDIT_OBJ_SHADOW1_VISIBILITY, m_edSdTrans);
	}

	edValue = GetDlgItemInt( IDC_ED_SD_SIZE, NULL, 0 );
	if( edValue != m_edSize )
	{
		m_edSize = edValue;
		TRACE( _T("\t m_edSize = %d\n"), m_edSize );
		CGS_SetValDbl(EDIT_OBJ_SHADOW1_SIZE, m_edSize);
	}

	edValue = GetDlgItemInt( IDC_ED_SD_FEATHER, NULL, 0 );
	if( edValue != m_edFeather )
	{
		m_edFeather = edValue;
		TRACE( _T("\t m_edFeather = %d\n"), m_edFeather );
		CGS_SetValDbl(EDIT_OBJ_SHADOW1_BLUR, m_edFeather);
	}

	edValue = GetDlgItemInt( IDC_ED_SD_XOFFSET, NULL, 0 );
	if( edValue != m_edXOffset )
	{
		m_edXOffset = edValue;
		TRACE( _T("\t m_edXOffset = %d\n"), m_edXOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_SD_YOFFSET, NULL, 0 );
	if( edValue != m_edYOffset )
	{
		m_edYOffset = edValue;
		TRACE( _T("\t m_edYOffset = %d\n"), m_edYOffset );
	}
	AfxGetMainWnd()->SetFocus();	
}//end of CDlgShadow::OnOK() 
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgShadow::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	g_dwAttrib = ABMC_SHADOW1_COLOR;

	InitButtonIcon();
	InitEditSpinControl();
	InitStaticIcon();
	InitRadioButton();

	//+++++++++++++++++++++++++++++++++++++++++++++ Create the ToolTip control.
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	InitDlgItemTextNTooltip();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CDlgShadow::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW1_VISIBILITY, max(0, val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgShadow::OnDeltaposSpnTrans
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnDeltaposSpnFeather(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW1_BLUR, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgShadow::OnDeltaposSpnFeather
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnDeltaposSpnSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW1_SIZE, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgShadow::OnDeltaposSpnSize
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnDeltaposSpnXOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgShadow::OnDeltaposSpnXOffset
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnDeltaposSpnYOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgShadow::OnDeltaposSpnYOffset
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnBtColImpSd() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_SHADOW1_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnBtColImpSd
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnBtColPalSd() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_COL_PAL_SD );    
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
}//end of CDlgShadow::OnBtColPalSd
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnBtTransAlphaSd() 
{
	m_bAlpha ^= 1;
	m_btTranAlpha.SetCheck( m_bAlpha );
	g_dwAttrib = m_bAlpha ? ABMC_SHADOW1_ALPHA : ABMC_SHADOW1_COLOR;

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
}//end of CDlgShadow::
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnBtTransImpSd() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_SHADOW1_ALPHA_MASK );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnBtTransImpSd
/////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnBtTransPalSd() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_TRANS_PAL_SD );    
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
}//end of CDlgShadow::OnBtTransPalSd
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgShadow::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);	
}//end of CDlgShadow::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::InitDlgItemTextNTooltip()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgShadow.ctl", "[Tooltip]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		m_hFont[i] = NULL;
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SHADOW_COLOR") ) )
			txtData[i].idTT = IDC_STC_SHADOW_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SHADOW_TRANS") ) )
				txtData[i].idTT = IDC_STC_SHADOW_TRANS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_TRANS_SD") ) )
			{
				txtData[i].idTT = IDC_ED_TRANS_SD;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SD_SIZE") ) )
			{
				txtData[i].idTT = IDC_ED_SD_SIZE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SD_XOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_SD_XOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SD_YOFFSET") ) )
			{
				txtData[i].idTT = IDC_ED_SD_YOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_SD_FEATHER") ) )
			{
				txtData[i].idTT = IDC_ED_SD_FEATHER;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_IMP_SD") ) )
				txtData[i].idTT = IDC_BT_COL_IMP_SD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_PAL_SD") ) )
				txtData[i].idTT = IDC_BT_COL_PAL_SD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_IMP_SD") ) )
				txtData[i].idTT = IDC_BT_TRANS_IMP_SD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_PAL_SD") ) )
				txtData[i].idTT = IDC_BT_TRANS_PAL_SD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_ALPHA_SD") ) )
				txtData[i].idTT = IDC_BT_TRANS_ALPHA_SD;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_SD_ENABLE") ) )
				txtData[i].idTT = IDC_CK_SD_ENABLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_UL") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_UL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_UR") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_UR;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_U") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_U;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_L") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_L;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_C") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_C;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_R") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_R;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_DR") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_DR;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_DL") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_DL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_DIRECT_D") ) )
			{
				txtData[i].idTT = IDC_RB_DIRECT_D;
				goto SKIP_TEXT;
			}

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (_TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgShadow::InitDlgItemTextNTooltip()
///////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::InitButtonIcon()
{
	HICON rv = m_btColPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	rv = m_btColImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranAlpha.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ALPHA), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );

}//end of CDlgShadow::InitButtonIcon()
///////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_TRANS_SD );
	pSpin->SetRange( 0, 255 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SIZE );
	pSpin->SetRange( 0, 99 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_FEATHER );
	pSpin->SetRange( 0, 32 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_X_OFFSET );
	pSpin->SetRange( -128, 128 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_Y_OFFSET );
	pSpin->SetRange( -128, 128 );

	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TRANS_SD );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 100
	SetDlgItemInt(IDC_ED_TRANS_SD, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_VISIBILITY), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SD_SIZE );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_SD_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_SIZE), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SD_FEATHER );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	SetDlgItemInt(IDC_ED_SD_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_BLUR), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SD_XOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SD_YOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
}//end of CDlgShadow::InitEditSpinControl()
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::InitStaticIcon()
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
}//end of CDlgShadow::InitStaticIcon()
//////////////////////////////////////////////////////////////////////////////////////////////
// Read info from CORE and set the button state
VOID CDlgShadow::InitRadioButton()
{
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_rbUpLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP_LEFT),IMAGE_ICON,8,8,0));
	m_rbUpRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP_RIGHT),IMAGE_ICON,8,8,0));
	m_rbRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_RIGHT),IMAGE_ICON,8,8,0));
	m_rbDownRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN_RIGHT),IMAGE_ICON,8,8,0));
	m_rbDown.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN),IMAGE_ICON,8,8,0));
	m_rbLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_LEFT),IMAGE_ICON,8,8,0));
	m_rbDownLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN_LEFT),IMAGE_ICON,8,8,0));
	m_rbUp.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP),IMAGE_ICON,8,8,0));

	SetDirection((int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_DIRECTION));

	if( CGS_GetValDbl( EDIT_OBJ_SHADOW1_ENABLE ) )
	{
		m_ckSdEnable.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		m_ckSdEnable.SetCheck( 1 );
	}
	else
	{
		m_ckSdEnable.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		m_ckSdEnable.SetCheck( 0 );
	}

}//end of CDlgShadow::InitRadioButton()
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectUL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_UP_LEFT );	
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectUL() 
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectU() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_UP );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectU()
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectUR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_UP_RIGHT );		
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectUR()
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_LEFT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectL
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectC() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_CENTER );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectC
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_RIGHT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectR
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectDL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_DOWN_LEFT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectDL
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectD() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_DOWN );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectD
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnRbDirectDR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW1_DIRECTION, (double)D_DOWN_RIGHT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnRbDirectDR
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::DoValueUpdate()
{
	SetDlgItemInt(IDC_ED_TRANS_SD,   (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_VISIBILITY), 0 );
	SetDlgItemInt(IDC_ED_SD_SIZE,    (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_SIZE), 0 );
	SetDlgItemInt(IDC_ED_SD_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_BLUR), 0 );

	if( m_bAlpha )
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_SD)->m_hWnd, 2,EDIT_OBJ_SHADOW1_ALPHA_MASK );
	else
		CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_SD)->m_hWnd, 2,EDIT_OBJ_SHADOW1_COLORSCHEME );

// Not implement yet
	SetDirection((int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_DIRECTION));

	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::DoValueUpdate()
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgShadow::UnCheckAlphaButton()
{
	m_btTranAlpha.SetCheck( m_bAlpha = 0 );
//	g_dwAttrib = ABMC_SHADOW1_COLOR;

	if( m_pDlg != NULL ) // delete the pop up alpha dialog box
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}//end of if

}//end of CDlgShadow::UnCheckAlphaButton()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pass in 0 - 8 that represent 9 different state of push state of radio button
// INPUT - int direction
VOID CDlgShadow::SetDirection(int direction)
{
	switch( (int)CGS_GetValDbl(EDIT_OBJ_SHADOW1_DIRECTION) )
	{
		case D_UP:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_U );
			break;
		case D_UP_RIGHT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_UR );
			break;
		case D_RIGHT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_R );
			break;
		case D_DOWN_RIGHT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_DR );
			break;
		case D_DOWN:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_D );
			break;
		case D_DOWN_LEFT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_DL );
			break;
		case D_LEFT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_L );
			break;
		case D_UP_LEFT:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_UL );
			break;
		case D_CENTER:
			CheckRadioButton( IDC_RB_DIRECT_U, IDC_RB_DIRECT_UL, IDC_RB_DIRECT_C );
			break;
	}//end of switch
}//end of CDlgShadow::SetDirection(int direction)
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
 	g_dwAttrib = m_bAlpha ? ABMC_SHADOW1_ALPHA : ABMC_SHADOW1_COLOR;
 	TRACE1("CDlgShadow::OnPaint() - g_dwAttrib = %d\n", g_dwAttrib ); 
 	
 	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_SD)->m_hWnd, 2, EDIT_OBJ_SHADOW1_ALPHA_MASK );
 	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_SD)->m_hWnd, 2,EDIT_OBJ_SHADOW1_COLORSCHEME );
}//end of CDlgShadow::OnPaint() 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnCkShadow() 
{
	
}//end of CDlgShadow::OnCkShadow() 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgShadow::OnCkSdEnable() 
{
	if( m_ckSdEnable.GetCheck() )
	{
		m_ckSdEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_SHADOW1_ENABLE, (double)1.0 );
	}
	else
	{
		m_ckSdEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_SHADOW1_ENABLE, (double)0.0 );
	}

	AfxGetMainWnd()->SetFocus();
}//end of CDlgShadow::OnCkSdEnable
