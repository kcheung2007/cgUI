/* COPYRIGHT NOTICE:
********************************************************
********************************************************
*/
// DlgCast.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgCast.h"
#include "Global.h"
#include "PalDlg.h"
#include "FileReq.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCast dialog
extern  TCHAR	UILang_UIFont[256];
extern  int		UILang_UIFontSize;
extern	DWORD	g_dwAttrib;

CDlgCast::CDlgCast(CWnd* pParent /*=NULL*/)	: CDialog(CDlgCast::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCast)
	m_edCaTrans = 0;
	m_edFeather = 0;
	m_edSize	= 0;
	m_edXOffset = 0;
	m_edYOffset = 0;
	//}}AFX_DATA_INIT
	m_bAlpha	= 0;
	g_dwAttrib	= ABMC_SHADOW2_COLOR;
	m_pDlg		= NULL;	

}

CDlgCast::~CDlgCast()
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
void CDlgCast::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCast)
	DDX_Control(pDX, IDC_CK_CA_ENABLE, m_ckCaEnable);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_UR, m_rbUpRight);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_UL, m_rbUpLeft);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_U, m_rbUp);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_R, m_rbRight);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_L, m_rbLeft);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_DR, m_rbDownRight);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_DL, m_rbDownLeft);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_D, m_rbDown);
	DDX_Control(pDX, IDC_RB_CA_DIRECT_C, m_rbCenter);
	DDX_Control(pDX, IDC_STC_CA_YOFFSET, m_stcYOffset);
	DDX_Control(pDX, IDC_STC_CA_XOFFSET, m_stcXOffset);
	DDX_Control(pDX, IDC_STC_CA_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_STC_CA_FEATHER, m_stcFeather);
	DDX_Control(pDX, IDC_BT_TRANS_PAL_CA, m_btTranPal);
	DDX_Control(pDX, IDC_BT_TRANS_IMP_CA, m_btTranImp);
	DDX_Control(pDX, IDC_BT_TRANS_ALPHA_CA, m_btTranAlpha);
	DDX_Control(pDX, IDC_BT_COL_PAL_CA, m_btColPal);
	DDX_Control(pDX, IDC_BT_COL_IMP_CA, m_btColImp);
	DDX_Text(pDX, IDC_ED_TRANS_CA, m_edCaTrans);
	DDV_MinMaxDWord(pDX, m_edCaTrans, 0, 100);
	DDX_Text(pDX, IDC_ED_CA_FEATHER, m_edFeather);
	DDX_Text(pDX, IDC_ED_CA_SIZE, m_edSize);
	DDX_Text(pDX, IDC_ED_CA_XOFFSET, m_edXOffset);
	DDX_Text(pDX, IDC_ED_CA_YOFFSET, m_edYOffset);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCast, CDialog)
	//{{AFX_MSG_MAP(CDlgCast)
	ON_BN_CLICKED(IDC_BT_COL_IMP_CA, OnBtColorImport)
	ON_BN_CLICKED(IDC_BT_COL_PAL_CA, OnBtColorPal)
	ON_BN_CLICKED(IDC_BT_TRANS_IMP_CA, OnBtTransImport)
	ON_BN_CLICKED(IDC_BT_TRANS_ALPHA_CA, OnBtTransAlpha)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_TRANS_CA, OnDeltaposSpnTrans)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CA_FEATHER, OnDeltaposSpnCaFeather)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CA_SIZE, OnDeltaposSpnCaSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CA_X_OFFSET, OnDeltaposSpnCaXOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_CA_Y_OFFSET, OnDeltaposSpnCaYOffset)
	ON_BN_CLICKED(IDC_BT_TRANS_PAL_CA, OnBtTransPalCa)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_UL, OnRbCaDirectUL)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_U, OnRbCaDirectU)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_UR, OnRbCaDirectUR)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_L, OnRbCaDirectL)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_C, OnRbCaDirectC)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_R, OnRbCaDirectR)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_DL, OnRbCaDirectDL)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_D, OnRbCaDirectD)
	ON_BN_CLICKED(IDC_RB_CA_DIRECT_DR, OnRbCaDirectDR)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CK_CA_ENABLE, OnCkCaEnable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCast message handlers
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnOK() 
{
	// TODO: Add extra validation here
	DWORD	edValue = GetDlgItemInt( IDC_ED_TRANS_FA, NULL, 0 );
	if( edValue != m_edCaTrans )
	{
		m_edCaTrans = edValue;
		TRACE(_T("\t m_dwEdMm = %d\n"), m_edCaTrans );
		CGS_SetValDbl(EDIT_OBJ_SHADOW2_VISIBILITY, m_edCaTrans);
	}

	edValue = GetDlgItemInt( IDC_ED_CA_SIZE, NULL, 0 );
	if( edValue != m_edSize )
	{
		m_edSize = edValue;
		TRACE(_T("\t m_edSize = %d\n"), m_edSize );
		CGS_SetValDbl(EDIT_OBJ_SHADOW2_SIZE, m_edSize);
	}

	edValue = GetDlgItemInt( IDC_ED_CA_FEATHER, NULL, 0 );
	if( edValue != m_edFeather )
	{
		m_edFeather = edValue;
		TRACE(_T("\t m_edFeather = %d\n"), m_edFeather );
		CGS_SetValDbl(EDIT_OBJ_SHADOW2_BLUR, m_edFeather);
	}

	edValue = GetDlgItemInt( IDC_ED_CA_XOFFSET, NULL, 0 );
	if( edValue != m_edXOffset )
	{
		m_edXOffset = edValue;
		TRACE(_T("\t m_edXOffset = %d\n"), m_edXOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_CA_YOFFSET, NULL, 0 );
	if( edValue != m_edYOffset )
	{
		m_edYOffset = edValue;
		TRACE(_T("\t m_edYOffset = %d\n"), m_edYOffset );
	}

	AfxGetMainWnd()->SetFocus();
	
}//end of CDlgCast::OnOK() 
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnCancel() 
{
	// capture cancel message
}//end of CDlgCast::OnCancel() 
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnBtColorImport() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_SHADOW2_COLORSCHEME );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnBtColorImport
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnBtTransImport() 
{
	FILE_REQ_FOLDER_INFO	imgFRD; // Get from core
	ZeroMemory( &imgFRD, sizeof(imgFRD) );

	imgFRD.nFileType = FILE_CATEGORY_EXPORT_PAGE;
	CGS_GetFileCategoryPathInfo( &imgFRD );

	imgFRD.opt = OPEN_OP;
	_tcscpy( imgFRD.DlgTitle, _T("Open Picture") );
	if( !FileRequestDlg(&imgFRD, FILE_CATEGORY_PICTURE) )
		return;

	CGS_ApplyPictureTextureMap( imgFRD.CompleteFileName, EDIT_OBJ_SHADOW2_ALPHA_MASK );

	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnBtTransImport
/////////////////////////////////////////////////////////////////////////////
// Set the PAL state before call the PAL menu
void CDlgCast::OnBtColorPal() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_COL_PAL_CA );    
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
	
}//end of CDlgCast::OnBtColorPal

/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnBtTransAlpha() 
{
	m_bAlpha ^= 1;
	m_btTranAlpha.SetCheck( m_bAlpha );
	g_dwAttrib = m_bAlpha ? ABMC_SHADOW2_ALPHA : ABMC_SHADOW2_COLOR;

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
}//end of CDlgCast::OnBtTransAlpha
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgCast::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	g_dwAttrib = ABMC_SHADOW2_COLOR;

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
}//end of CDlgCast::OnInitDialog
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnDeltaposSpnTrans(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW2_VISIBILITY, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgCast::OnDeltaposSpnTrans
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnDeltaposSpnCaFeather(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW2_BLUR, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgCast::OnDeltaposSpnCaFeather
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnDeltaposSpnCaSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	int val = pNMUpDown->iPos+pNMUpDown->iDelta;
	CGS_SetValDbl(EDIT_OBJ_SHADOW2_SIZE, max(0,val) );
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgCast::OnDeltaposSpnCaSize
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnDeltaposSpnCaXOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgCast::OnDeltaposSpnCaXOffset
/////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnDeltaposSpnCaYOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgCast::OnDeltaposSpnCaYOffset
/////////////////////////////////////////////////////////////////////////////
BOOL CDlgCast::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);
	}
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}//end of CDlgCast::PreTranslateMessage
/////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::InitDlgItemTextNTooltip()
{
	HFONT hFont = NULL;
	IN_TEXT_DATA* txtData = NULL;
	TCHAR		sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgCast.ctl", "[Tooltip]", &txtData );
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

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CAST_COLOR") ))
			txtData[i].idTT = IDC_STC_CAST_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_CAST_TRANS") ))
				txtData[i].idTT = IDC_STC_CAST_TRANS;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_TRANS_CA") ))
			{
				txtData[i].idTT = IDC_ED_TRANS_CA;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CA_SIZE") ))
			{
				txtData[i].idTT = IDC_ED_CA_SIZE;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CA_XOFFSET") ))
			{
				txtData[i].idTT = IDC_ED_CA_XOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CA_YOFFSET") ))
			{
				txtData[i].idTT = IDC_ED_CA_YOFFSET;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_ED_CA_FEATHER") ))
			{
				txtData[i].idTT = IDC_ED_CA_FEATHER;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_IMP_CA") ))
				txtData[i].idTT = IDC_BT_COL_IMP_CA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_COL_PAL_CA") ))
				txtData[i].idTT = IDC_BT_COL_PAL_CA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_IMP_CA") ))
				txtData[i].idTT = IDC_BT_TRANS_IMP_CA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_PAL_CA") ))
				txtData[i].idTT = IDC_BT_TRANS_PAL_CA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_BT_TRANS_ALPHA_CA") ))
				txtData[i].idTT = IDC_BT_TRANS_ALPHA_CA;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_CK_CA_ENABLE") ))
				txtData[i].idTT = IDC_CK_CA_ENABLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_UL") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_UL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_UR") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_UR;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_U") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_U;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_L") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_L;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_C") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_C;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_R") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_R;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_DR") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_DR;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_DL") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_DL;
				goto SKIP_TEXT;
			}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_RB_CA_DIRECT_D") ))
			{
				txtData[i].idTT = IDC_RB_CA_DIRECT_D;
				goto SKIP_TEXT;
			}

		SetDlgItemText( txtData[i].idTT, (LPCTSTR)ptTT );
		m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

SKIP_TEXT:
		_tcscpy( txtData[i].szTT, (TCHAR*)txtData[i].szTT );
		if( NULL != GetDlgItem(txtData[i].idTT) )
			m_tooltip.AddTool( GetDlgItem(txtData[i].idTT), (TCHAR*)ptTT);
	}//end of for

	free( txtData );
}//end of CDlgCast::InitDlgItemTextNTooltip()
//////////////////////////////////////////////////////////////////////////////////////////////
// Set the PAL state before call the PAL menu.
void CDlgCast::OnBtTransPalCa() 
{
	int nRet = -1;
	CPalDlg dlgPal;
	dlgPal.SetPaletteState( IDC_BT_TRANS_PAL_CA );        
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
}//end of CDlgCast::OnBtTransPalCa
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::InitButtonIcon()
{
	HICON rv = m_btColPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	rv = m_btColImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranAlpha.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ALPHA), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranImp.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_IMPORT), IMAGE_ICON, 16, 16, 0) );
	rv = m_btTranPal.SetIcon( (HICON)::LoadImage( AfxGetApp()->m_hInstance,	MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );

}//end of CDlgCast::InitButtonIcon()
//////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::InitEditSpinControl()
{
	// ++++++++++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_TRANS_CA );
	pSpin->SetRange( 0, 255 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CA_SIZE );
	pSpin->SetRange( 0, 99 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CA_FEATHER );
	pSpin->SetRange( 0, 32 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CA_X_OFFSET );
	pSpin->SetRange( -128, 128 );

	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_CA_Y_OFFSET );
	pSpin->SetRange( -128, 128 );

	//save for ref.	pSpin->SetPos((int) (m_dSpin * 10.0));

	//+++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_TRANS_CA );
	pEdCtrl->SetLimitText( 3 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_TRANS_CA, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_VISIBILITY), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CA_SIZE );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 99
	SetDlgItemInt(IDC_ED_CA_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_SIZE), 0 );

	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CA_FEATHER );
	pEdCtrl->SetLimitText( 2 ); // 2 characters of 32
	SetDlgItemInt(IDC_ED_CA_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_BLUR), 0 );
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CA_XOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
	
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_CA_YOFFSET );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 128
}//end of CDlgCast::InitEditSpinControl()
/////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::InitStaticIcon()
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
}//end of CDlgCast::InitStaticIcon()
/////////////////////////////////////////////////////////////////////////////////////////////
// Initial the radio button (direction button) icon and set the state.
VOID CDlgCast::InitRadioButton()
{
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_rbUpLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP_LEFT),IMAGE_ICON,8,8,0));
	m_rbUpRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP_RIGHT),IMAGE_ICON,8,8,0));
	m_rbRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_RIGHT),IMAGE_ICON,8,8,0));
	m_rbDownRight.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN_RIGHT),IMAGE_ICON,8,8,0));
	m_rbDown.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN),IMAGE_ICON,8,8,0));
	m_rbLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_LEFT),IMAGE_ICON,8,8,0));
	m_rbDownLeft.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_DOWN_LEFT),IMAGE_ICON,8,8,0));
//	m_rbCenter.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP),IMAGE_ICON,8,8,0));
	m_rbUp.SetIcon((HICON)::LoadImage(hInst,MAKEINTRESOURCE(IDI_DIR_UP),IMAGE_ICON,8,8,0));

	SetDirectionButton( (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_DIRECTION) ); // set the direction button

	// Initial the Enable check box icon
	if( CGS_GetValDbl( EDIT_OBJ_SHADOW2_ENABLE ) )
	{
		m_ckCaEnable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		m_ckCaEnable.SetCheck( 1 );
	}
	else
	{
		m_ckCaEnable.SetIcon((HICON)::LoadImage( AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		m_ckCaEnable.SetCheck( 0 );
	}
}//end of CDlgCast::InitRadioButton()
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectUL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_UP_LEFT );	
	AfxGetMainWnd()->SetFocus();	
}//end of CDlgCast::OnRbCaDirectUL
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectU() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_UP );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectU
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectUR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_UP_RIGHT );		
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectUR
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_LEFT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectL
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectC() 
{
//	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_CENTER );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectC
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_RIGHT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectR
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectDL() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_DOWN_LEFT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectDL
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectD() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_DOWN );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectD
//////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnRbCaDirectDR() 
{
	CGS_SetValDbl( EDIT_OBJ_SHADOW2_DIRECTION, (double)D_DOWN_RIGHT );
	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnRbCaDirectDR
/////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::DoValueUpdate()
{
	SetDlgItemInt(IDC_ED_TRANS_CA, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_VISIBILITY), 0 );
	SetDlgItemInt(IDC_ED_CA_SIZE, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_SIZE), 0 );
	SetDlgItemInt(IDC_ED_CA_FEATHER, (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_BLUR), 0 );

	m_btTranAlpha.SetCheck( m_bAlpha = 0 );

	TRACE1("\t Cast alpha button = %d\n", m_bAlpha );

	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_CA)->m_hWnd, 2,EDIT_OBJ_SHADOW2_ALPHA_MASK );
	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_CA)->m_hWnd, 2,EDIT_OBJ_SHADOW2_COLORSCHEME );

	SetDirectionButton( (int)CGS_GetValDbl(EDIT_OBJ_SHADOW2_DIRECTION) ); // set the direction button

	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::DoValueUpdate()
/////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	g_dwAttrib = m_bAlpha ? ABMC_SHADOW2_ALPHA : ABMC_SHADOW2_COLOR;
	TRACE1("CDlgCast::OnPaint() - g_dwAttrib = %d\n", g_dwAttrib ); 

	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_TRANS_CA)->m_hWnd, 2,EDIT_OBJ_SHADOW2_ALPHA_MASK );
	CGS_EditUpdateCurColorSample( (DWORD)this->GetDlgItem(IDC_FRM_COLOR_CA)->m_hWnd, 2,EDIT_OBJ_SHADOW2_COLORSCHEME );
}//end of CDlgCast::OnPaint
////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgCast::UnCheckAlphaButton()
{
	m_btTranAlpha.SetCheck( m_bAlpha = 0 );
//	g_dwAttrib = ABMC_SHADOW2_COLOR;

	if( m_pDlg != NULL ) // delete the pop up alpha dialog box
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}//end of if

}//end of CDlgCast::UnCheckAlphaButton()
////////////////////////////////////////////////////////////////////////////////////////////
// Pass in 0 - 8 to represent 9 different direction. Set the push state of the radio button.
// INPUT - int direction 0 - 8
VOID CDlgCast::SetDirectionButton( int direction )
{
	switch( direction )
	{
		case D_UP:			
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_U );
			break;
		case D_UP_RIGHT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_UR );
			break;
		case D_RIGHT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_R );
			break;
		case D_DOWN_RIGHT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_DR );
			break;
		case D_DOWN:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_D );
			break;
		case D_DOWN_LEFT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_DL );
			break;
		case D_LEFT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_L );
			break;
		case D_UP_LEFT:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_UL );
			break;
		case D_CENTER:
			CheckRadioButton( IDC_RB_CA_DIRECT_UR, IDC_RB_CA_DIRECT_DR, IDC_RB_CA_DIRECT_C );
			break;
	}//end of switch

}//end of CDlgCast::SetDirectionButton()
////////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgCast::OnCkCaEnable() 
{
	if( m_ckCaEnable.GetCheck() )
	{
		m_ckCaEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_ON_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_SHADOW2_ENABLE, (double)1.0 );
	}
	else
	{
		m_ckCaEnable.SetIcon((HICON)::LoadImage(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDI_OFF_SWITCH),IMAGE_ICON,16,16,0));
		CGS_SetValDbl( EDIT_OBJ_SHADOW2_ENABLE, (double)0.0 );
	}

	AfxGetMainWnd()->SetFocus();
}//end of CDlgCast::OnCkCaEnable() 
