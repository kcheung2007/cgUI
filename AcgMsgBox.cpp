/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/

// AcgMsgBox.cpp : implementation file
//

#include "stdafx.h"
#include "cgui.h"
#include "AcgMsgBox.h"
#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define TIMER	0x101

extern	TCHAR   g_szAppPath[_MAX_PATH];
extern  DWORD	g_CodePage;
/////////////////////////////////////////////////////////////////////////////
// CAcgMsgBox dialog
//////////////////////////////////////////////////////////////////////////////
// This is a custom dialog box for export page and project only.
//////////////////////////////////////////////////////////////////////////////

CAcgMsgBox::CAcgMsgBox(CWnd* pParent /*=NULL*/)	: CDialog(CAcgMsgBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAcgMsgBox)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_funcID = 0; // general message box
	m_bContinue = 1;
}

void CAcgMsgBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAcgMsgBox)
	DDX_Control(pDX, IDC_STC_MSG1, m_ctlMsg1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAcgMsgBox, CDialog)
	//{{AFX_MSG_MAP(CAcgMsgBox)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////////
// CAcgMsgBox message handlers
/////////////////////////////////////////////////////////////////////////////////
void CAcgMsgBox::OnCancel() 
{
	TRACE0("++ CAcgMsgBox::OnCancel() ++\n");
	KillTimer( m_ctlTimer );
	m_bContinue = 0;
	CDialog::OnCancel();
}//end of CAcgMsgBox::OnCancel
/////////////////////////////////////////////////////////////////////////////////
BOOL CAcgMsgBox::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CHAR	fn[MAX_PATH];
	CHAR	buf[MAX_PATH];	
	CHAR	strPath[MAX_PATH];

	UnicodeToMultiByte( g_CodePage, g_szAppPath, strPath );
	strcpy( fn, strPath );
	strcat( fn, "\\Util\\message.ctl" );

	UnicodeToMultiByte( g_CodePage, (LPTSTR)(LPCTSTR)m_strTitle, strPath );
	acgReadLine( (LPCSTR)fn, strPath, buf ); // parse title
	CString szTitle( buf );
	int index = szTitle.FindOneOf( (LPCTSTR)"\"" );
	szTitle = szTitle.Mid( index );
	szTitle.Remove( '"' );

	UnicodeToMultiByte( g_CodePage, (LPTSTR)(LPCTSTR)m_strButText, strPath );
	acgReadLine( (LPCSTR)fn, strPath, buf ); // parse title
	CString szText( buf );
	index = szText.FindOneOf( (LPCTSTR)"\"" );
	szText = szText.Mid( index );
	szText.Remove( '"' );

	UnicodeToMultiByte( g_CodePage, (LPTSTR)(LPCTSTR)m_strMsg, strPath );
	acgReadLine( (LPCSTR)fn, strPath, buf ); // parse message
	TCHAR	swMsg[MAX_PATH];
	MultiByteToUnicode( g_CodePage, buf, swMsg );

	CString msgStr( swMsg );
	index = msgStr.FindOneOf( _T("\"") );
	msgStr = msgStr.Mid( index+1 );
	index = msgStr.FindOneOf( _T("\"") );
	msgStr.SetAt( index, _T('\0') );
		
	SetWindowText( szTitle );
	SetDlgItemText( IDC_STC_MSG1, msgStr );
	SetDlgItemText( IDCANCEL, szText );

	if( m_funcID == FN_EXPORT_PAGE )
		m_ctlTimer = SetTimer( TIMER, 100, 0 );
	else
		if( m_funcID == FN_EXPORT_PROJ )
		{
			TRACE0("\n AcgMsgBox.cpp - OnInitDialog() - FN_EXPORT_PROJ");
			CGS_ExportProjectBegin( (char*)(LPCTSTR)m_expPath, 0, 0, (CGS_IMAGE_FILE_FORMAT)m_expFormat, 1, 0 );
			m_ctlTimer = SetTimer( TIMER, 100, 0 );
		}
		else
			SendMessage( WM_COMMAND, IDCANCEL, 0 );	// error - Close the dialog box

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}//end of CAcgMsgBox::OnInitDialog() 
////////////////////////////////////////////////////////////////////////////////////////////////
void CAcgMsgBox::OnTimer(UINT nIDEvent) 
{
	TRACE0("\n ++ On Timer ++");
	CString	strMsg;
	CString strNum;
	CString strOut;
	GetDlgItemText( IDC_STC_MSG1, strMsg );

	if( m_funcID == FN_EXPORT_PAGE )
	{
		TRACE0("\n AcgMsgBox.cpp - OnTimer() - FN_EXPORT_PAGE, KillTimer, Export Page, Do cancel");
		KillTimer( m_ctlTimer );
		CGS_ExportPage( (char*)(LPCTSTR)m_expPath, 0, 0, (CGS_IMAGE_FILE_FORMAT)m_expFormat, 1, 0 );
		SendMessage( WM_COMMAND, IDCANCEL, 0 );	// Close the waiting dialog box
	}//end of FN_EXPORT_PAGE
	else
		if( m_funcID == FN_EXPORT_PROJ )
		{
			TRACE0("\n AcgMsgBox.cpp - OnTimer() - FN_EXPORT_PROJ");
			if( !m_bContinue )
			{
				TRACE0("\n AcgMsgBox.cpp - OnTimer() - !continue, KillTimer, End export project, do cancel");
				KillTimer( m_ctlTimer );
				CGS_ExportProjectEnd();
				SendMessage( WM_COMMAND, IDCANCEL, 0 );	// Close the waiting dialog box
			}//end of !m_bContinue
			else
				m_bContinue = CGS_ExportProjectNextPage();			
		}//end of FN_EXPORT_PROJ

	CDialog::OnTimer(nIDEvent);
}//end of CAcgMsgBox::OnTimer
////////////////////////////////////////////////////////////////////////////////////////////////
VOID CAcgMsgBox::GetStrIndex(CString title, CString msg, CString butText)
{
	m_strTitle   = title;
	m_strMsg     = msg;
	m_strButText = butText;
}//end of CAcgMsgBox::GetStrIndex
////////////////////////////////////////////////////////////////////////////////////////////////
// INPUT : CString path		  - inFullFilePath
// INPUT : DWORD   fileFormat - inFileType from CGS_IMAGE_FILE_FORMAT
// Two more parameters that will add later
// CGS_ExportPage(char *inFullFilePath,char *inFolder,char *inFilenamePlusExt,CGS_IMAGE_FILE_FORMAT inFileType,int inExportOptions); 
VOID CAcgMsgBox::GetCGSExportPageParam(CString path, DWORD fileFormat)
{
	m_expPath   = path;
	m_expFormat = fileFormat;
}//end of GetCGSExportPageParam
////////////////////////////////////////////////////////////////////////////////////////////////
// Set the function state to indication the functionality of the message box.
VOID CAcgMsgBox::SetFunctionState(DWORD funcID)
{
	m_funcID = funcID;
}//end of CAcgMsgBox::SetFunctionState
////////////////////////////////////////////////////////////////////////////////////////////////
// Return function ID to indicate the current functionality of this messagebox
// RETURN : DWORD m_funcID - 0 means general message box
DWORD CAcgMsgBox::GetFunctionState()
{
	return( m_funcID );
}//end of CAcgMsgBox::GetFunctionState()
