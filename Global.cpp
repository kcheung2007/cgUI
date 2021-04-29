/* COPYRIGHT NOTICE:
*/
//////////////////////////////////////////////////////////////////////////////////
// Global.cpp 
// Put all global functions that are called from several different places here.
//

#include "stdafx.h"
#include "afxpriv.h"
#include <fstream>
#include "cgUI.h"
#include <direct.h>
#include "Global.h"
#include "DlgEffect.h"
#include "ChildFrm.h"
#include "TabSetup.h"
#include "PgAnnot.h"
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

CURSOR_HANDLE	g_hCursor;
DWORD			g_CodePage;
DWORD			g_dwTab;
DWORD			g_dwAttrib;
DWORD			g_txtGfxState;
TCHAR			g_szAppPath[_MAX_PATH];
TCHAR			UILang_UIFont[_MAX_PATH];
int				UILang_UIFontSize;
CChildFrame*	g_ChildFrame; // JIM's idea - implementation 

///////////////////////////////////////////////////////////////////////////////////////////
// Jim's style of redraw implementation - Update scroll bar
VOID IXReg_UpdateVertScrollBar( double vPos )
{
	g_ChildFrame->SetVertPos( vPos );
	g_ChildFrame->SetScrollPos( SB_VERT, (int)vPos, 1 );

}//end of IXReg_UpdateVertScrollBar
///////////////////////////////////////////////////////////////////////////////////////////
// Jim's style of redraw implementation - Update scroll bar
VOID IXReg_UpdateHorzScrollBar( double hPos )
{
	g_ChildFrame->SetHorzPos( hPos );
	g_ChildFrame->SetScrollPos( SB_HORZ, (int)hPos, 1 );

}//end of IXReg_UpdateHorzScrollBar
///////////////////////////////////////////////////////////////////////////////////////////
VOID IXReg_RedrawPageBinThumbTrack( double dummy )
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_SET_PAGE_SCROLL_POS, 0 );	
}//end of IXReg_RedrawPageBinThumbTrack
///////////////////////////////////////////////////////////////////////////////////////////
VOID IXReg_RedrawFontPresetThumbTrack( double dummy )
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_SET_BIN_TOP_SCROLL_POS, 0 );	
}//end of IXReg_RedrawPageBinTopThumbTrack
///////////////////////////////////////////////////////////////////////////////////////////
VOID IXReg_RedrawPaletteThumbTrack( double dummy )
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_SET_BIN_BOT_SCROLL_POS, 0 );	
}//end of IXReg_RedrawPageBinBotThumbTrack
/////////////////////////////////////////////////////////////////////////////////////////
// This function is special for loading tooltip to toolbar, but not dialog box.
// Read all tooltip string from tooltip section of ctl file. Section begin at [Tooltip]
// and ended at "end".
//
// INPUT : char* fn - file name
// INPUT : IN_TEXT_DATA* *g_ttData - address of pointer to TOOLTIP_DATA
// RETURN: 0 - error; number of tooltip
DWORD LoadTooltipText( CHAR* fn, IN_TEXT_DATA* *g_ttData )
{
	DWORD	numTip = 0;
	CHAR	sep[] = "\"";
	CHAR*	ptID;
	CHAR*	ptTT;
	CHAR*	ptEnd;
	CHAR	szFullName[MAX_PATH];
	CHAR	bufStr[MAX_LINE_LEN];

	FILE*	inFile;
	DWORD	i = 0;
	IN_TEXT_DATA* ttData;

	TCHAR	swBuf[MAX_PATH];
	UnicodeToMultiByte( g_CodePage, g_szAppPath, bufStr );
	strcpy( szFullName, bufStr );
	strcat( szFullName, fn );
	if( NULL == (inFile = fopen( szFullName, "r") ) )
	{
		strcat( szFullName, " - File Not Found." );
		::MessageBox( NULL, (LPTSTR)szFullName, _T("Warning"), MB_ICONSTOP|MB_OK );
		return( 0 );
	}
	while( !feof( inFile ) )
	{
		if( NULL == fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}//end of if 

		if( NULL != strstr( bufStr, "[Tooltip]" ) )
		{
			while( NULL != fgets( bufStr, MAX_LINE_LEN, inFile ) )
			{
				if( NULL == strstr( bufStr, "end") )
					numTip++;
				else
					break;
			}//end of while
		}//end of if
		break;
	}//end of while

	rewind( inFile );
	ttData = (IN_TEXT_DATA*)malloc( sizeof(IN_TEXT_DATA) * numTip );
	while( !feof( inFile ) )
	{
		if( NULL == fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}//end of if 

		if( NULL != strstr( bufStr, "[Tooltip]" ) )
			break; // move file pointer to line of [Tooltip] 
	}//end of while

	for( i = 0; i < numTip; i++ )
	{
		if( NULL == fgets( (char*)bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}

		ptID   = strtok( bufStr, sep );
		ptTT   = strtok( NULL, sep );
		ptEnd  = strtok( NULL, sep );
		if( ptEnd != 0 )
			*ptEnd = '\0';

		MultiByteToUnicode( g_CodePage, ptTT, swBuf );
		_tcscpy( ttData[i].szTT, swBuf );
	}//end of for

	fclose( inFile );

	*g_ttData = ttData;
	return( numTip );
}//end of LoadTooltipText
/////////////////////////////////////////////////////////////////////////////////////////
// Retrive the code page value from message.ctl file for setting language.
// The value was put on the first line of the file.
// RETURN : DWORD code page value in decimal format
DWORD GetCodePage()
{
	FILE*	inFile;
	char	curDir[MAX_PATH];	
	char	bufStr[MAX_PATH];

	UnicodeToMultiByte( CP_ACP, g_szAppPath, curDir );
	strcat( curDir,"\\Util\\message.ctl" );

	if( NULL == (inFile = fopen( curDir, "r" )) )
	{
		strcat( curDir, " - File not found" );
		::MessageBox( NULL, (LPCTSTR)curDir, _T("Warning"), MB_ICONINFORMATION|MB_OK );
		g_CodePage = GetACP();
		return( 0 );
	}

	if( NULL == fgets( bufStr, MAX_PATH, inFile ) )
	{
		fclose( inFile );
		return( 0 );// error
	}//end of if 

	fclose( inFile );
	return( atoi(bufStr) );
}//end of GetCodePage
/////////////////////////////////////////////////////////////////////////////////////////
// RETURN : number of loaded text. 0 - error
DWORD LoadTextFromCtl( CHAR* fn, CHAR* section, IN_TEXT_DATA* *g_txtData )
{
	DWORD	numTip = 0;	
	CHAR	sep[] = "\"";
	CHAR    szFullName[MAX_PATH];
	CHAR	bufStr[MAX_PATH];
	FILE*	inFile;
	DWORD	i = 0;
	IN_TEXT_DATA* ttData;

	TCHAR	swBuf[MAX_PATH];
	CHAR	strPath[MAX_PATH];

	UnicodeToMultiByte( g_CodePage, g_szAppPath, strPath );

	strcpy( szFullName, strPath );
	strcat( szFullName, fn );
	if( NULL == (inFile = fopen( szFullName, "r" )) )
	{
		strcat( szFullName, "- File not found" );
		::MessageBox( NULL, (LPCTSTR)szFullName, _T("Warning"), MB_ICONINFORMATION|MB_OK );
		return( 0 );
	}

	if( !feof( inFile ) )
	{
		if( NULL == fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}//end of if 
				
		while( NULL == strstr( bufStr, section ) )		
			fgets( bufStr, MAX_LINE_LEN, inFile );

		while( NULL != fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			if( NULL == strstr( bufStr, "end" ) )
				numTip++;
			else
				break;
		}//end of while
	}//end of if

	rewind( inFile );
	ttData = (IN_TEXT_DATA*)malloc( sizeof(IN_TEXT_DATA) * numTip );
	while( !feof( inFile ) )
	{
		if( NULL == fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}//end of if 

		if( NULL != strstr( bufStr, section ) )
			break; // move file pointer to line of [Tooltip] 
	}//end of while
	for( i = 0; i < numTip; i++ )
	{
		if( NULL == fgets( bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 0 );// error
		}

		MultiByteToUnicode( g_CodePage, bufStr, swBuf );
		_tcscpy( ttData[i].szTT, swBuf );
	}//end of for

	fclose( inFile );

	*g_txtData = ttData;
	return( numTip );
}//end of InitBaseLineHorizStaticText

/////////////////////////////////////////////////////////////////////////////////////////
// INPUT : HWND		Hwnd - handle of control
// INPUT : HFONT	hfont - handle of font
// INPUT : _TCHAR*	*Font_name - Name of the font, ie: "Arial"
// INPUT : long		Font_Width - Font Width
// INPUT : long		Font_Height - Font Height
// INPUT : LONG		Font_Weight - Font Weight
HFONT ChangeControlFont( HWND Hwnd, HFONT hfont, _TCHAR *Font_name, long Font_Width,	long Font_Height, LONG Font_Weight)
{
	BYTE		CharSet = (g_CodePage == JAPANESE_CP) ? SHIFTJIS_CHARSET : DEFAULT_CHARSET;

#ifdef _UNICODE
	LOGFONTW	logfont;	// For creating logical fonts.
#else
	LOGFONTA	logfont;
#endif

	// FONT STUFF -- set font to normal to get avg width
	logfont.lfWeight         = Font_Weight;

	//negative for exact size
	logfont.lfHeight         = -Font_Height;

	// 0 for width that's proportional to the height
	logfont.lfWidth          = Font_Width;

	logfont.lfItalic         = 0;
	logfont.lfUnderline      = 0;
	logfont.lfStrikeOut      = 0;
	logfont.lfCharSet        = CharSet;
	logfont.lfOutPrecision   = 0;
	logfont.lfClipPrecision  = 0;
	logfont.lfQuality        = 0;
	logfont.lfPitchAndFamily = 0;
	logfont.lfEscapement     = 0;
	logfont.lfOrientation    = 0; 
	logfont.lfEscapement     = 0;

#ifdef _UNICODE
	_tcscpy( (wchar_t*)&logfont.lfFaceName, Font_name );
#else
	_tcscpy( (char*)&logfont.lfFaceName, Font_name );	// define _MBCS
#endif

	if( hfont ) //if(hfont) REMOVED BY KHOI - ADDED BACK BY JRS 5-11-99
		::DeleteObject((HGDIOBJ)hfont);

	hfont = CreateFontIndirect(&logfont);

	SendMessage(Hwnd, WM_SETFONT, (WPARAM)hfont, MAKELPARAM(TRUE,0));

	return( hfont );
}//end of ChangeControlFont
////////////////////////////////////////////////////////////////////////////////////////////////
// Copy from the old UI code
VOID SetUILanguage()
{
	if( g_CodePage == JAPANESE_CP ) // for japanese OS platform
	{
		lstrcpy ( UILang_UIFont, (TCHAR*)JAPANESE_MS_GOTHIC_FONT_NAME );
		UILang_UIFontSize = 10; // font size
	}
	else
	{
		// English OS platform
		lstrcpy( UILang_UIFont, _T("MS Sans Serif") );
		UILang_UIFontSize = 8; // font size
	}

}//end of SetUILanguage
/////////////////////////////////////////////////////////////////////////////////////////////////
// Copy from the old UI code
VOID ColorConversion(int from_mode, int to_mode, int *value1, int *value2, int *value3)
{
	static double r, g, b, h, s, v, m, n, k, f, h2;
	int value;

	switch ( from_mode )
	{
		case RGB_MODE:  /* r = value1, g = value2, b = value3 */
			switch ( to_mode )
			{
				case HSV_MODE:
					r = ( double ) ( *value1 ) / 255.0;
					g = ( double ) ( *value2 ) / 255.0;
					b = ( double ) ( *value3 ) / 255.0;
					v = ( double ) max ( max ( *value1, *value2 ), *value3 ) / 255.0;
					m = ( double ) min ( min ( *value1, *value2 ), *value3 ) / 255.0;
					n = v - m;

					if ( v == 0.0 )
						s = 0.0;
					else
						s = n / v;

					if ( s == 0.0 )
						h = 0.0;
					else
						if ( r == v )
							h = ( g - b ) / n;
						else
							if ( g == v )
								h = 2.0 + ( b - r ) / n;
							else
								if ( b == v )
									h = 4.0 + ( r - g ) / n;

					h *= 60.0;
					if ( h < 0.0 )
						h += 360.0;

					*value1 = ( int ) max ( 0, min ( 360, floor ( h + 0.5 ) ) );
					*value2 = ( int ) max ( 0, min ( 255, floor ( s * 255.0 + 0.5 ) ) );
					*value3 = ( int ) max ( 0, min ( 255, floor ( v * 255.0 + 0.5 ) ) );
					break;
				case YIQ_MODE:
					break;
			}
			break;
		case HSV_MODE:  /* h = value1, s = value2, v = value3 */
			switch ( to_mode )
			{
				case RGB_MODE:
					h = ( double ) ( *value1 );
					s = ( double ) ( *value2 ) / 255.0;
					v = ( double ) ( *value3 ) / 255.0;
					h2 = h;
					if ( s == 0.0 )
					{
						if ( floor ( h ) <= 0.0 )
						{
							r = v;
							g = v;
							b = v;
						}
						else
							h = 0.0;
					}
					else
					{
						if ( h >= 360.0 )
						{
							h = 0.0;
							h2 = 0.0;
						}
						else
							h2 = h / 60.0;

						value = ( int ) floor ( h2 );
						f = h2 - ( double ) value;
						m = v * ( 1.0 - s );
						n = v * ( 1.0 - s * f );
						k = v * ( 1.0 - s * ( 1.0 - f ) );

						switch ( value )
						{
							case 0:
								r = v;
								g = k;
								b = m;
								break;
							case 1:
								r = n;
								g = v;
								b = m;
								break;
							case 2:
								r = m;
								g = v;
								b = k;
								break;
							case 3:
								r = m;
								g = n;
								b = v;
								break;
							case 4:
								r = k;
								g = m;
								b = v;
								break;
							case 5:
								r = v;
								g = m;
								b = n;
								break;
						}
					}
					*value1 = ( int ) max ( 0, min ( 255, floor ( r * 255.0 + 0.5 ) ) );
					*value2 = ( int ) max ( 0, min ( 255, floor ( g * 255.0 + 0.5 ) ) );
					*value3 = ( int ) max ( 0, min ( 255, floor ( b * 255.0 + 0.5 ) ) );
					break;
				case YIQ_MODE:
					break;
			}
			break;
		case YIQ_MODE:  /* y = value1, i = value2, q = value3 */
			switch ( to_mode )
			{
				case RGB_MODE:
					break;
				case HSV_MODE:
					break;
			}
			break;
	}//end of switch
}//end of ColorConversion
/////////////////////////////////////////////////////////////////////////////////////////////////
// Register call back function
VOID IXLoadPicDlg()
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PG_ADD_PIC, 0 );
}//end of IXLoadPicDlg()
/////////////////////////////////////////////////////////////////////////////////////////////////
// Register call back function - update/show the object properties
// Sending command messages for update GUI info
VOID IXReg_ShowObjPropertiesMenu( int objID )
{
	switch( objID )
	{
	case TEXT_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_TEXT, 0 );
		break;
	case LINE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_LINE, 0 );
		break;
	case CURVE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_CURV, 0 );
		break;
	case BOX_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_BOX,  0 );
		break;
	case ELLIPSE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_OVAL, 0 );
		break;
	case FULL_SCREEN_BACKGROUND_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_FILL, 0 );
		break;
	case POLYGON_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_POLY, 0 );
		break;
	case PICTURE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_PIC, 0 );
		break;
	}//end of switch - g_txtGfxState

}//end of IXReg_ShowObjPropertiesMenu
/////////////////////////////////////////////////////////////////////////////////////////////////
// Register call back function - add object and show the property
// Sending command messages for update GUI info
VOID IXReg_AddObjMenu( int objID )
{
	switch( objID )
	{
	case TEXT_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_TEXT, 0 );
		break;
	case LINE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_LINE, 0 );
		break;
	case CURVE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_CURV, 0 );
		break;
	case BOX_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_BOX,  0 );
		break;
	case ELLIPSE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_OVAL, 0 );
		break;
	case FULL_SCREEN_BACKGROUND_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_FILL, 0 );
		break;
	case POLYGON_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_POLYGON, 0 );
		break;
	case PICTURE_OBJ_SUBTYPE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_TXTGFX_IMPORT, 0 );
		break;
	}//end of switch - g_txtGfxState

}//end of IXReg_AddObjMenu
/////////////////////////////////////////////////////////////////////////////////////////////////
// Register call back function
// Sending command messages for update GUI info
//see CGS_ValDefs.h for inCoreValDefFlag values i.e. EDIT_OBJ_ROTATION,etc or EDIT_OBJECT_PROPERTIES_UPDATE_ALL_UI_VALUES for all values
VOID IXReg_UpdateIXGUI(DWORD inCoreValDefFlag)//JRS 01-05-04 added inCoreValDefFlag param
{
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_PAGE, 0 );

	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_FACE,     0 );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_OUTLINE1, 0 );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_OUTLINE2, 0 );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_SHADOW,   0 );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_CAST,     0 );
	
	switch( g_txtGfxState )
	{
	case ID_TXTGFX_TEXT:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_TEXT, 0 );
		break;
	case ID_TXTGFX_LINE:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_LINE, 0 );
		break;
	case ID_TXTGFX_CURV:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_CURV, 0 );
		break;
	case ID_TXTGFX_BOX:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_BOX,  0 );
		break;
	case ID_TXTGFX_OVAL:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_OVAL, 0 );
		break;
	case ID_TXTGFX_FILL:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_FILL, 0 );
		break;
	case ID_TXTGFX_POLYGON:
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_ATT_POLY, 0 );
		break;
	}//end of switch - g_txtGfxState

	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_EFFECT,  0 );
	AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_REFRESH_CAPTURE, 0 );
}//end of IXReg_UpdateIXGUI
/////////////////////////////////////////////////////////////////////////////
//JRS ...
/*
	Hello Kent,

	- this procedure will be called by the core bin manager for Page Bin if the user left clicks on label portion of a picon
	- on entry to this procedure pStringVal will contain the current page label string i.e. "Today's Weather"
	- we need to pop up a modal dialog "Page Annotation" with a string edit field which contains the above string
	- the user may modify the string and click OK, or Cancel which should revert to the original string value
	- the procedure returns back to the core bin manager which will update the picon label graphics, etc.
*/
void DoPageLabelDlg(char* pStringVal)
{
	CPgAnnot dlgAnnot;
	dlgAnnot.SetAnnotString( pStringVal );

	switch ( dlgAnnot.DoModal() )   
	{   
	case -1:     
		AfxMessageBox(_T("Dialog box could not be created!"));
      break;
    case IDABORT:
      // Do something
       break;
    case IDOK:
		strcpy(pStringVal,dlgAnnot.GetPgAnnotation()); 		
       break;
    case IDCANCEL:
      // Do something
       break;
    default:
      // Do something
      break;
   }//end of switch

	AfxGetMainWnd()->SetFocus();	
}//end of DoPageLabelDlg
/////////////////////////////////////////////////////////////////////////////////////////////////
VOID SearchFile( LPCTSTR pStartPath, LPCTSTR pFileName, LPTSTR pNewPath )
{
   CFileFind finder;
   CString fn( pFileName );

   // build a string with wildcards
   CString strWildcard(pStartPath);
   strWildcard += _T("\\*.*");

   // start working for files
   BOOL bWorking = finder.FindFile(strWildcard);

   while( bWorking )
   {
      bWorking = finder.FindNextFile();

      // skip . and .. files; otherwise, recur infinitely!
      CString str = finder.GetFileName();	  

	  TRACE1("\t Path = %s\n", str );

	  if( str == fn )
	  {
 		 _tcscpy( pNewPath, (LPCTSTR)finder.GetFilePath() );
		 break;
	  }

      if( finder.IsDots() )
         continue;

      // if it's a directory, recursively search it
      if( finder.IsDirectory() )
      {
		 str = finder.GetFilePath();
         SearchFile(str, fn, pNewPath);
      }
   }//end of while

   finder.Close();
}//end of SearchFile
///////////////////////////////////////////////////////////////////////////////////////////////////
// ASSUME :
// 1) origLink MUST contains the full path + file name + ext
// 2) homePath MUST exist for althernative search
// INPUT : LPSTR origLink - original link with full path + file name + ext
// INPUT : LPSTR homePath - useless
// OUTPUT: LPSTR newPath - store the found path
// RETURN: 0 - fail, 1 - path found
// USAGE : GetSuggestedPath( "C:\\SDK\\Samples\\WinBase\\Read Me.Txt", "D:\\SDK", newPath );
BOOL GetSuggestedPath( LPTSTR origLink, LPTSTR homePath, LPTSTR newPath )
{
	CFileFind	finder;
	_TCHAR		Buf[MAX_PATH];
	_TCHAR*		pDrive = Buf;
	BOOL		bFound = finder.FindFile( origLink );
	CString		szLink( origLink );

	if( bFound )
	{
		bFound = finder.FindNextFile(); // move file pointer to end
		if( !bFound )
		{
			_tcscpy( newPath, (LPCTSTR)finder.GetFilePath() );
			return( 1 );
		}
	}//end of bFound
	
	DWORD rv = GetLogicalDriveStrings( MAX_PATH, Buf );
	pDrive += 4; // skip A: drive

	if( origLink[0] == '\\' && origLink[1] == '\\' ) // network drive
	{
		szLink.Delete( 0, 2 ); // delete 2 slashs
		INT len = szLink.GetLength();
		INT	i = szLink.Find( '\\' );
		szLink = pDrive + szLink.Mid( i+1, len );
	
	}//end of if 

	while( (*pDrive != 0) && (*(pDrive+1) != 0 ) )// end of buffer - 00
	{
		szLink.SetAt( 0, *pDrive );
		bFound = finder.FindFile( szLink );
		if( bFound )
		{
			bFound = finder.FindNextFile(); // move file pointer only
			if( !bFound )
			{
				_tcscpy( (TCHAR*)newPath, (LPCTSTR)finder.GetFilePath() );
				return( 1 );
			}
		}//end of bFound
		pDrive += 4; // point to next drive
	}//end of while

	CString		FileName( origLink );
	INT index = FileName.ReverseFind( '\\' )+1; // get the file name
	SearchFile( homePath, &origLink[index], newPath );

	if( newPath[0] != 0 )
		return( 1 );
	else
		return( 0 );
}//end of GetSuggestedPath
///////////////////////////////////////////////////////////////////////////////////////////////////
// Convert double value to four 10 digit string. 
// INPUT  : double val - the double value
// INPUT  : int decDigit - number of digit after decimal point
// OUTPUT : char*  buf - pointer to buffer which contain the final text string
VOID DoubleToAlphaString( double val, int decDigit, _TCHAR* Buf )
{
	_TCHAR* p = Buf;
	_stprintf( Buf, "%lf", val );

	while( *(p++) != '.' );

	*(p + decDigit) = '\0';

}//end of DoubleToAlphaString
///////////////////////////////////////////////////////////////////////////////////////////////////
// Open an external file and parse the file line by line compare with an input string.
// INPUT  : LPCTSTR fn - constant of file name. (Assume the file in the current directory.)
// INPUT  : TCHAR* inStr - input string for line search.
// INPUT  : TCHAR* bufStr - memory location for storing the found string.
// RETURN : TCHAR* - pointer of the found string; otherwise, NULL for not found
CHAR* acgReadLine( LPCSTR fn, CHAR* inStr, CHAR* bufStr )
{
	FILE* inFile;

	if( (inFile = fopen( fn, "r" )) != NULL )   
	{
		while( NULL != fgets( bufStr, MAX_PATH, inFile ) )
		{
			if( NULL != strstr( bufStr, inStr ) )
			{
				fclose( inFile );
				int i = 0;
				while( bufStr[i] != '\n' )
					i++;
				bufStr[i] = '\0';
				return( bufStr );
			}
		}//end of while
		
		fclose( inFile );   
	}
	else
		MessageBox( NULL, _T("Message.ctl - File not find."), _T("Warning"), MB_ICONSTOP | MB_OK );

	return( NULL );
}//end of acgReadLine
///////////////////////////////////////////////////////////////////////////////////////////////////
// INPUT : HWND hWnd - handle of the window for centering
// INPUT : LPCTSTR msg - messages with '-' indicating new line
// INPUT : LPCTSTR title - title define as INFO, WARN or STOP
// INPUT : UINT flag - same as win32 MessageBox() for Icon and buttons usage
// Note - Title string is predefined as "INFO", "WARN" and "STOP"
// This function will auto ajust the size of the message box. Messages are read
// from message.ctl file, in which using Mxxxx as a search key.
// For information message, start with M0000
// For warning message, start with M3000
// For stop/error message, start with M6000
INT ACGMessageBox( HWND hWnd, LPCTSTR msg, LPCTSTR title, UINT flag )
{		
	CHAR	fn[MAX_PATH];
	CHAR	buf[MAX_PATH];	
	CHAR	strPath[MAX_PATH];

	UnicodeToMultiByte( g_CodePage, g_szAppPath, strPath );
	strcpy( fn, strPath );
	strcat( fn, "\\Util\\message.ctl" );

	UnicodeToMultiByte( g_CodePage, (LPTSTR)title, strPath );
	acgReadLine( (LPCSTR)fn, strPath, buf ); // parse title
	CString szTitle( buf );
	int index = szTitle.FindOneOf( (LPCTSTR)"\"" );
	szTitle = szTitle.Mid( index );
	szTitle.Remove( '"' );

	UnicodeToMultiByte( g_CodePage, (LPTSTR)msg, strPath );
	acgReadLine( (LPCSTR)fn, strPath, buf ); // parse message

	TCHAR	swMsg[MAX_PATH];
	MultiByteToUnicode( g_CodePage, buf, swMsg );

	CString msgStr( swMsg );
	index = msgStr.FindOneOf( _T("\"") );
	msgStr = msgStr.Mid( index+1 );
	index = msgStr.FindOneOf( _T("\"") );
	msgStr.SetAt( index, _T('\0') );
	msgStr.Replace( _T('_'), _T('\n') );

	return( MessageBox( hWnd, msgStr, szTitle, flag ) );

}//end of ACGMessageBox
///////////////////////////////////////////////////////////////////////////////////////////////////
// INPUT : DWORD iTab - Index of Tab from 0 to 7
// INPUT : DWORD iAlig - Index of radio buttom from 0 to 3
// INPUT : double pos - Tab position
VOID UpdateIXTabSetupDlg()
{
	HWND hDlg = FindWindow( NULL, _T("Tab Setup") );
	if( hDlg == NULL )
		return;

	int i = IDC_RB_TAB1;
	while( BST_CHECKED != IsDlgButtonChecked(hDlg, i++) );

	DWORD	nTab	= i - IDC_RB_TAB1 - 1;
	double	pos		= CGS_GetValDbl( nTab + PAGE_TAB_0_PERCENT );
	DWORD	iAlig	= (DWORD)CGS_GetValDbl( nTab + PAGE_TAB_0_ALIGN );

	CheckRadioButton( hDlg, IDC_RB_TAB1, IDC_RB_TAB8, nTab + IDC_RB_TAB1 );
	CheckRadioButton( hDlg, IDC_RB_ALIGN_LEFT, IDC_RB_ALIGN_DECIMAL, iAlig +IDC_RB_ALIGN_LEFT );

	_TCHAR Buf[MAX_PATH];
	DoubleToAlphaString( pos, 2, Buf );
	SetDlgItemText( hDlg, IDC_ED_POS, (LPCTSTR)Buf );

}//end of UpdateIXTabSetupDlg
///////////////////////////////////////////////////////////////////////////////////////////////////
// If UNICODE defined, do the conversion. Otherwise, do the multi byte string copy
// INPUT : UINT codePage - code Page constant
// INPUT : char* inStr - Input string of Multi Byte
// OUTPUT: TCHAR* outStr - Output string of unicode
VOID MultiByteToUnicode( UINT codePage, char* inStr, TCHAR* outStr )
{
#ifdef _UNICODE
	MultiByteToWideChar( codePage, MB_PRECOMPOSED, inStr, -1, outStr, MAX_PATH);
#else
	_mbscpy( (_TUCHAR*)outStr, (_TUCHAR*)inStr );
#endif
}//end of MultiByteToUnicode
///////////////////////////////////////////////////////////////////////////////////////////////////
// If UNICODE defined, do the conversion. Otherwise, do the ascii code string copy
// INPUT : UINT codePage - Code Page constant
// INPUT : TCHAR* inStr - Input string of unicode
// OUTPUT: char* outStr - Output String of multi byte
VOID UnicodeToMultiByte( UINT codePage, TCHAR* inStr, char* outStr )
{
#ifdef _UNICODE
	WideCharToMultiByte(codePage,    // code page
						0,		     // dwFlags
						inStr,		 // lpWideCharStr
						-1,          // cchWideCharStr
						outStr,		 // lpMultiByteStr
						MAX_PATH,	 // cchMultiByte
						NULL,        // lpDefaultChar
						NULL		 // lpUsedDefaultChar
					);        
#else
	strcpy( outStr, inStr );		// define MBCS
#endif

}//end of UnicodeToMultiByte

////////////////////////////////////////////////////////////////////////////////////////////////
VOID KentDebugLog( char* szStr, DWORD val )
{
    fstream fio( "C:\\KDebug.log", ios::in|ios::app);
	fio << szStr << " -- " << val << endl;
}//end of KentDebugLog
////////////////////////////////////////////////////////////////////////////////////////////////
VOID IXReg_ScrollBarEnableProc( BOOL horz, BOOL vert )
{
	if( !horz && !vert )
		AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_STILL, 0 );
	else
	{
		if( horz )
			AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_CRAWL, 0 );

		if( vert )
			AfxGetMainWnd()->SendMessage( WM_COMMAND, ID_PAGE_TYPE_ROLL, 0 );
	}//end of else	
}//end of IXReg_ScrollBarEnableProc
///////////////////////////////////////////////////////////////////////////////////////////////////////
// MUST return 0 - indicate the job finish
INT IXDoTripleClick()
{
	::MessageBox( NULL, "Simulate triple click", "kentest", MB_OK );
	return( 0 );
}//end of IXDoTripleClick
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Core logic will call this function to set the cursor shap.
VOID IXReg_SetMousePointerMode( int Mode )
{
	switch( Mode )
	{
	case CGS_MOUSE_PTR_ARROW:
		SetCursor( g_hCursor.Arrow );
		break;
	case CGS_MOUSE_PTR_WAIT:
		break;
	case CGS_MOUSE_PTR_NONE:
		SetCursor( NULL );
		break;
	case CGS_MOUSE_PTR_SLIDE_HORIZONTAL:
		SetCursor( g_hCursor.Horz );
		break;
	case CGS_MOUSE_PTR_SLIDE_VERTICAL:
		SetCursor( g_hCursor.Vert );
		break;
	case CGS_MOUSE_PTR_SLIDE_4WAY:
		SetCursor( g_hCursor.FourWay );
		break;
	case CGS_MOUSE_PTR_SLIDE_DIAGONAL_LL_UR:
		SetCursor( g_hCursor.RightLeft );
		break;
	case CGS_MOUSE_PTR_SLIDE_DIAGONAL_UL_LR:
		SetCursor( g_hCursor.LeftRight );
		break;
	case CGS_MOUSE_PTR_ROTATE_X:
		break;
	case CGS_MOUSE_PTR_ROTATE_Y:
		break;
	case CGS_MOUSE_PTR_ROTATE_Z:
		SetCursor( g_hCursor.RotateZ );
		break;
	default:
		SetCursor( g_hCursor.Arrow );
	}//end of switch - Mode
}//end of IXReg_SetMousePointerMode
/////////////////////////////////////////////////////////////////////////////////////////////
INT IXReg_DisplayTemplateMessageBox()
{
	return( ACGMessageBox( NULL, _T("TEMP_MSG"), _T("TEMP_TITLE"), MB_YESNOCANCEL | MB_ICONQUESTION ) );
}//end of IXReg_DisplayTemplateMessageBox()
/////////////////////////////////////////////////////////////////////////////////////////////
BOOL WindowsVersionIs(DWORD dwMajor, DWORD dwMinor, WORD dwSPMajor)
{
    OSVERSIONINFO osvi;
    
    // Initialize the OSVERSIONINFO structure.// 
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));

    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx((OSVERSIONINFO*)&osvi);
    
    // Check the major version.
    if( osvi.dwMajorVersion == dwMajor )
        return( 1 );
	else
		return( 0 );
}//end of WindowsVersionIs