// DlgTypeFace.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "DlgTypeFace.h"
#include "Global.h"
#include "PalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTypeFace dialog
extern _TCHAR	UILang_UIFont[256];
extern int		UILang_UIFontSize;

CDlgTypeFace::CDlgTypeFace(CWnd* pParent /*=NULL*/)	: CDialog(CDlgTypeFace::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTypeFace)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_edItalicAngle	= 0;
	m_edSmallCapHi	= 0;
	m_edSupSize		= 0;
	m_edSupOffset	= 0;
	m_edSubSize		= 0;
	m_edSubOffset	= 0;
	m_edUdlSize		= 0;
	m_edUdlOffset	= 0;
	m_hFont			= NULL;
}

CDlgTypeFace::~CDlgTypeFace()
{
	for( DWORD i = 0; i < m_numTxt; i++ )
	{
		if( m_hFont[i] != NULL )
			DeleteObject( (HGDIOBJ)m_hFont[i] );
	}
	if( m_hFont != NULL )
		delete [] m_hFont;
}
void CDlgTypeFace::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTypeFace)
	DDX_Control(pDX, IDC_ED_UNDERLNE_SIZE, m_ctlEdUdlSize);
	DDX_Control(pDX, IDC_ED_UNDERLNE_OFFSET, m_ctlEdUdlOffset);
	DDX_Control(pDX, IDC_ED_SUPER_SIZE, m_ctlEdSupSize);
	DDX_Control(pDX, IDC_ED_SUPER_OFFSET, m_ctlEdSupOffset);
	DDX_Control(pDX, IDC_ED_SUB_SIZE, m_ctlEdSubSize);
	DDX_Control(pDX, IDC_ED_SUB_OFFSET, m_ctlEdSubOffset);
	DDX_Control(pDX, IDC_ED_SMALL_CAP_HEIGHT, m_ctlEdSmallCapHi);
	DDX_Control(pDX, IDC_ED_ITALIC_ANGLE, m_ctlEdItalicAngle);
	DDX_Control(pDX, IDC_BT_PALETTE, m_btPal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTypeFace, CDialog)
	//{{AFX_MSG_MAP(CDlgTypeFace)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_ITALIC_ANGLE, OnDeltaposSpnItalicAngle)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SMALL_CAP_HEIGHT, OnDeltaposSpnSmallCapHeight)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SUB_OFFSET, OnDeltaposSpnSubOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SUB_SIZE, OnDeltaposSpnSubSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SUPER_OFFSET, OnDeltaposSpnSuperOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_SUPER_SIZE, OnDeltaposSpnSuperSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_UNDERLNE_OFFSET, OnDeltaposSpnUnderlneOffset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPN_UNDERLNE_SIZE, OnDeltaposSpnUnderlneSize)
	ON_BN_CLICKED(IDC_BT_PALETTE, OnBtPalette)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTypeFace message handlers
BOOL CDlgTypeFace::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//+++++++++++++++++++++++++++++++++++++ Initial icon
	HINSTANCE hInst = AfxGetApp()->m_hInstance;
	m_btPal.SetIcon( (HICON)::LoadImage( hInst,MAKEINTRESOURCE(IDI_PALETTE), IMAGE_ICON, 16, 16, 0) );
	
	//+++++++++++++++++++++++++++++++++++++ Initial spin control
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_ITALIC_ANGLE );
	pSpin->SetRange32( -45, 45 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SMALL_CAP_HEIGHT );
	pSpin->SetRange32( 10, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SUPER_SIZE );
	pSpin->SetRange32( 10, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SUPER_OFFSET );
	pSpin->SetRange32( -100, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SUB_SIZE );
	pSpin->SetRange32( 10, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_SUB_OFFSET );
	pSpin->SetRange32( -100, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_UNDERLNE_SIZE );
	pSpin->SetRange32( 1, 100 );
	pSpin = (CSpinButtonCtrl*)GetDlgItem( IDC_SPN_UNDERLNE_OFFSET );
	pSpin->SetRange32( -100, 100 );

	// +++++++++++++++++++++++++++++++++++++++++++++++ Initial Edit control
	CEdit* pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_ITALIC_ANGLE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of -45 .. 45
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SMALL_CAP_HEIGHT );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 10 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SUPER_SIZE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 10 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SUPER_OFFSET );
	pEdCtrl->SetLimitText( 4 ); // 4 characters of -100 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SUB_SIZE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 10 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_SUB_OFFSET );
	pEdCtrl->SetLimitText( 4 ); // 3 characters of -100 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_UNDERLNE_SIZE );
	pEdCtrl->SetLimitText( 3 ); // 3 characters of 1 .. 100
	pEdCtrl = (CEdit*)GetDlgItem( IDC_ED_UNDERLNE_OFFSET );
	pEdCtrl->SetLimitText( 4 ); // 3 characters of -100 .. 100

	InitDlgItemText();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}//end of CDlgTypeFace::OnInitDialog
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnItalicAngle(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnItalicAngle
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnSmallCapHeight(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnSmallCapHeight
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnSubOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnSubOffset
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnSubSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnSubSize
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnSuperOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnSuperOffset
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnSuperSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnSuperSize
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnUnderlneOffset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnUnderlneOffset
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnDeltaposSpnUnderlneSize(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	AfxGetMainWnd()->SetFocus();
	*pResult = 0;
}//end of CDlgTypeFace::OnDeltaposSpnUnderlneSize
/////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnOK() 
{
	INT	edValue = GetDlgItemInt( IDC_ED_ITALIC_ANGLE, NULL, 1 );
	if( edValue != m_edItalicAngle )
	{
		m_edItalicAngle = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edItalicAngle );
	}

	edValue = GetDlgItemInt( IDC_ED_SMALL_CAP_HEIGHT, NULL, 0 );
	if( edValue != m_edSmallCapHi )
	{
		m_edSmallCapHi = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSmallCapHi );
	}

	edValue = GetDlgItemInt( IDC_ED_SUPER_SIZE, NULL, 0 );
	if( edValue != m_edSupSize )
	{
		m_edSupSize = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSupSize );
	}

	edValue = GetDlgItemInt( IDC_ED_SUPER_OFFSET, NULL, 1 );
	if( edValue != m_edSupOffset )
	{
		m_edSupOffset = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSupOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_SUB_SIZE, NULL, 0 );
	if( edValue != m_edSubSize )
	{
		m_edSubSize = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSubSize );
	}

	edValue = GetDlgItemInt( IDC_ED_SUB_OFFSET, NULL, 1 );
	if( edValue != m_edSubOffset )
	{
		m_edSubOffset = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edSubOffset );
	}

	edValue = GetDlgItemInt( IDC_ED_UNDERLNE_SIZE, NULL, 0 );
	if( edValue != m_edUdlSize )
	{
		m_edUdlSize = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edUdlSize );
	}

	edValue = GetDlgItemInt( IDC_ED_UNDERLNE_OFFSET, NULL, 1 );
	if( edValue != m_edUdlOffset )
	{
		m_edUdlOffset = edValue;
//		CGS_SetValDbl( EDIT_OBJ_SIZE, (double)m_edUdlOffset );
	}
	
	CDialog::OnOK();
}//end of CDlgTypeFace::OnOK
//////////////////////////////////////////////////////////////////////////////////////////////
VOID CDlgTypeFace::InitDlgItemText()
{
	IN_TEXT_DATA* txtData = NULL;
	TCHAR	sep[] = _T("\"");
	TCHAR*	ptID;
	TCHAR*	ptTT;
	TCHAR*	ptEnd;
	DWORD	i;

	m_numTxt = LoadTextFromCtl( "\\Util\\DlgTypeFace.ctl", "[Text String]", &txtData );
	if( m_numTxt == 0 )
		return;

	m_hFont = new HFONT[m_numTxt];
	for( i = 0; i < m_numTxt; i++ )
	{
		m_hFont[i] = NULL; // initial m_hFont
		ptID   = _tcstok( txtData[i].szTT, sep );
		ptTT   = _tcstok( NULL, sep );
		ptEnd  = _tcstok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		if( NULL != _tcsstr( txtData[i].szTT, _T("IDD_TYPE_FACE_OPT") ) )
		{
			txtData[i].idTT = IDD_TYPE_FACE_OPT;			
			m_hFont[i] = ChangeControlFont( m_hWnd, /*m_hFont[i]*/NULL, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
			SetWindowText( (LPCTSTR)ptTT );
			goto SkipText;
		}
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_ITALIC_ANGLE") ) )
				txtData[i].idTT = IDC_STC_ITALIC_ANGLE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SMALL_CAP_HEIGHT") ) )
				txtData[i].idTT = IDC_STC_SMALL_CAP_HEIGHT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUPER_SIZE") ) )
				txtData[i].idTT = IDC_STC_SUPER_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUPER_OFFSET") ) )
				txtData[i].idTT = IDC_STC_SUPER_OFFSET;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDOK") ) )
				txtData[i].idTT = IDOK;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDCANCEL") ) )
				txtData[i].idTT = IDCANCEL;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUB_SIZE") ) )
				txtData[i].idTT = IDC_STC_SUB_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUB_OFFSET") ) )
				txtData[i].idTT = IDC_STC_SUB_OFFSET;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_UNDERLN_SIZE") ) )
				txtData[i].idTT = IDC_STC_UNDERLN_SIZE;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_UNDERLNE_OFFSET") ) )
				txtData[i].idTT = IDC_STC_UNDERLNE_OFFSET;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_COLOR") ) )
				txtData[i].idTT = IDC_STC_COLOR;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUPERSCRIPT") ) )
				txtData[i].idTT = IDC_STC_SUPERSCRIPT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_SUBSCRIPT") ) )
				txtData[i].idTT = IDC_STC_SUBSCRIPT;
		else
			if( NULL != _tcsstr( txtData[i].szTT, _T("IDC_STC_UNDERLINE") ) )
				txtData[i].idTT = IDC_STC_UNDERLINE;

		SetDlgItemText( (INT)txtData[i].idTT, (LPCTSTR)ptTT );

SkipText:
		if( txtData[i].idTT != IDD_TYPE_FACE_OPT )
			m_hFont[i] = ChangeControlFont( GetDlgItem(txtData[i].idTT)->m_hWnd, NULL/*m_hFont[i]*/, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);			
	}//end of for

	free( txtData );
}//end of CDlgTypeFace::InitDlgItemText()
////////////////////////////////////////////////////////////////////////////////////////////////
void CDlgTypeFace::OnBtPalette() 
{
	int nRet = -1;
	CPalDlg dlgPal;

    // Create and show the dialog box   
    nRet = dlgPal.DoModal();   
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
}//end of CDlgTypeFace::OnBtPalette() 
