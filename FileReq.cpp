/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <winbase.h>
#include <stdio.h>
#include <mbstring.h>
#include "ACGS_Inc\\CGServerDll.h"
#include "resource.h"
#include "FileReq.h"
#include "Global.h"

typedef struct _KENTDATA	// Kent debug data structure, don't use it
{
	_TCHAR szTest1[80];		// a test buffer containing the file selected
	_TCHAR szTest2[80];       // a test buffer containing the file path
} KENTDATA, FAR * LPMYDATA;
KENTDATA	sMyData;		// Kent's test data

struct EXTFILTER
{
	void* pFilter;
	_TCHAR* index[30];
};

_TCHAR  g_szFile[MAX_PATH];
_TCHAR  g_szSize[MAX_PATH];

LPCTSTR pPrjExt = _T("Project Files (*.ACG)\0*.ACG\0\0");
LPCTSTR pTmpExt = _T("Template Files (*.TPG)\0*.TPG\0\0");
LPCTSTR pVdoExt = _T("RTV Video Files (*.RTV)\0*.RTV\0A Video Files (*.AVI)\0*.AVI\0\0");
LPCTSTR pTxtExt = _T("Text Files (*.TXT)\0*.TXT\0Word File (*.Doc)\0*.DOC\0Rich Text File (*.Rtf)\0*.RTF\0\0");
LPCTSTR pPicExt = _T("Any Picture Files\0*.TGA;*.BMP;*.TIF;*.PCX;*.PCT;*.PNG;*.JPG;*.IFF;*.PCD\0FAST Image with Alpha (*.VM*)\0*.VM*\0FAST Image without Alpha (*.VM*)\0*.VM*\0Targa Files (*.TGA)\0*.TGA\0Bitmap Files (*.BMP)\0*.BMP\0TIFF Files (*.TIF)\0*.TIF\0PC Paintbrush Files (*.PCX)\0*.PCX\0MAC Picture Files (*.PCT)\0*.PCT\0JPEG Files (*.JPG)\0*.JPG\0Amiga IFF Files (*.IFF)\0*.IFF\0Portable Network Graphic Files (*.PNG)\0*.GIF\0Kodak PhotoCD Files (*.PCD)\0*.PCD\0Any file type (*.*)\0*.*");
LPCTSTR pSvPExt = _T("TGA 32 bit Image (*.TGA)\0*.TGA\0TGA 24 bit Image (*.TGA)\0*.TGA\0TGA 16 bit Image(*.TGA)\0*.TGA\0Bitmap 32 bit (*.BMP)\0*.BMP\0Bitmap 24 bit (*.BMP)\0*.BMP\0JPEG Image (*.JPG)\0*.JPG\0TIF Format Image (*.TIF)\0*.TIF\0PNG Image (*.PNG)\0*.PNG\0PCX Image (*.PCX)\0*.PCX\0Trinity Framestore (*.FFS)\0*.TFS\0Trinity TFX (*.TFX)\0*.TFX\0DPS DPT Image (*.DPT)\0*.DPT\0Fast VM (*.VM;*.VMT)\0*.VM;*.VMT");
LPCTSTR pBmpExt = _T("Window Bitmap Files\0*.BMP;\0Any file type (*.*)\0*.*");
LPCTSTR pPalExt = _T("Palette Files (*.PAL)\0*.PAL\0\0");

BOOL	CALLBACK FileReqDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL	OnFileRequest( HWND hWnd, UINT flag, FILE_REQ_FOLDER_INFO* );
void	InitFileReqData( FILE_REQ_FOLDER_INFO* ptfReqData );
LPCTSTR GetFullFileName( LPTSTR lpszFileName );
void	SetupExtSubString(  FILE_REQ_FOLDER_INFO* ptfReqData, LPCTSTR extStr, UINT bufSize );

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Get the current path 
// INPUT  : LPTSTR lpszFileName - file name + file ext
// RETURN : LPTSTR drive + path + file name + file ext
LPCTSTR GetFullFileName( LPTSTR lpszFileName )
{ 
  TCHAR    ucPathBuf[MAX_PATH];
  DWORD   dwSzReturned; 
  LPTSTR  lpszLastNamePart;   
  LPTSTR  lpszFullName = ucPathBuf;
  
  dwSzReturned = GetFullPathName( lpszFileName, 
								  (DWORD)MAX_PATH,
								  (LPTSTR)&ucPathBuf,
								  (LPTSTR *)&lpszLastNamePart
								);     
  if( 0 == dwSzReturned )
  {
	  switch( GetLastError() )
	  { 
	  case ERROR_INVALID_NAME:
//		  Kdebug("\nError invalid file full-name (on GetFullPathName)", 0, DF );
		  return( 0 );       		
	  default: 			
//		  Kdebug("GetFullPathName - unexpected return code", 0, DF );
		  return( 0 );
	  }
  }//end of if - 0
        
  if( dwSzReturned > MAX_PATH )
  { 
//	  Kdebug("GetFullPathName - buffer too small", 0, DF );
	  return( 0 );
  }
  
  return( lpszFullName );
} //end of GetFullFileName

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set up the extension sub strings
void SetupExtSubString(  FILE_REQ_FOLDER_INFO* ptfReqData, LPCTSTR extStr, UINT bufSize )
{
	_TCHAR*		phead;
	_TCHAR*		ptail;
	int			n = 0;

	ptfReqData->ExtFilter = malloc( bufSize );
	memcpy( ptfReqData->ExtFilter, extStr, bufSize );

	phead = (_TCHAR*)ptfReqData->ExtFilter;
	ptfReqData->extIndex[n++] = phead;

	ptail = phead + 1;	
	while( (*phead != '\0') || (*ptail != '\0') )
	{
		if( *phead == '\0' )
			ptfReqData->extIndex[n++] = ptail;

		phead++; ptail++;
	}//end of while

}//end of SetupExtSubString

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Get the default extension index. We need to divieded by 2 beceause of the 
// pair of the filter index string. eg) "Vidoe file\0*.AVI\0" <- 2 string here
// INPUT  : FILE_REQ_FOLDER_INFO* ptfReqData - Check the initial file extension
// RETURN : index of the file extension filter
DWORD GetFileExtIndex( FILE_REQ_FOLDER_INFO* ptfReqData )
{
	int n = 0;
	BOOL done = 0;
	_TCHAR tmp[10] = _T("*.");
	

//	if( ptfReqData->fileExt[0] == 0 ) // empty string
	if( *ptfReqData->fileExt == NULL ) // empty string
		return( 0 );
	else
	{
		_tcscat( tmp, ptfReqData->fileExt );
		while( _tcscmp( tmp, ptfReqData->extIndex[n++]) );
	}

	return( n/2 );
}//end of GetFileExtIndex

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle all string initialization base on the input flag. At this moment, 
// only four selection. All strings can be read from text file ....
// INPUT : FILE_REQ_FOLDER_INFO* ptfReqData - initial the some input fields
// INPUT : UINT flag - FILE_CATEGORY_ENUM
// NOTE  : This function may be called at the begining of the program
//
// JRS 00-12-15  CGUI needs to get/set correct FILE_REQ_FOLDER_INFO by calling 
//		CGS_GetFileCategoryPathInfo(FILE_REQ_FOLDER_INFO* pFd);
//      and/or
//		CGS_SetFileCategoryPathInfo(FILE_REQ_FOLDER_INFO* pFd);
//
void InitFileReqData( FILE_REQ_FOLDER_INFO* ptfReqData )
{
	/////////////////
	// TO DO : add massage datastring fist... read from file??
	////////////////////////

	_TCHAR curDir[MAX_PATH];
//	GetCurrentDirectory( MAX_PATH, curDir );
// check point
//	CGS_GetValStr( STATUS_PROGRAM_FOLDER, (char*)curDir );

	char	szDir[MAX_PATH];

	CGS_GetValStr( STATUS_PROGRAM_FOLDER, szDir );

	MultiByteToUnicode( CP_ACP, szDir, curDir );

	CGS_GetFileCategoryPathInfo(ptfReqData);//added by jrs
	strcpy(curDir,ptfReqData->FolderPath);//added by jrs
	strcpy(szDir,ptfReqData->FolderPath);//added by jrs

	switch( ptfReqData->nFileType )
	{
	case FILE_CATEGORY_PROJECT:
		SetupExtSubString( ptfReqData, pPrjExt, MAX_PATH );
		///_tcscat( curDir, _T("\\Projects") );		
//		_tcscpy( ptfReqData->DefaultDir, curDir );		
		break;
	case FILE_CATEGORY_BITMAP: // For scanner input
		SetupExtSubString( ptfReqData, pBmpExt, (MAX_PATH*2) );
//removed by jrs		_tcscat( curDir, _T("\\Pictures") );
		break;
	case FILE_CATEGORY_PICTURE:
		SetupExtSubString( ptfReqData, pPicExt, (MAX_PATH*2) );
//removed by jrs		_tcscat( curDir, _T("\\Pictures") );
///		_tcscpy( ptfReqData->DefaultDir, curDir );	
//testing only		
//		ptfReqData->opt = 1; //testing only
//		ptfReqData->nFileExt = GetFileExtIndex( ptfReqData );
//		_tcscpy( ptfReqData->fileExt, "JPG" );
//end test		
		break;
	case FILE_CATEGORY_MEDIA_CLIP:
		SetupExtSubString( ptfReqData, pVdoExt, MAX_PATH );
		break;
	case FILE_CATEGORY_TEXT:
		SetupExtSubString( ptfReqData, pTxtExt, MAX_PATH );
		//TO DO here : sub folder _tcscat to curDir 
//		_tcscpy( ptfReqData->FolderPath, curDir );		
		break;
	case FILE_CATEGORY_PALETTE:
		SetupExtSubString( ptfReqData, pPalExt, MAX_PATH );
//		_tcscpy( ptfReqData->FolderPath, curDir );
//		_tcscat( ptfReqData->FolderPath, "\\Util" );
		break;
	case FILE_CATEGORY_EXPORT_PAGE:
		SetupExtSubString( ptfReqData, pSvPExt, MAX_PATH*2 );
		break;
	case FILE_CATEGORY_PRESET:
		MessageBox( NULL, "To Do the file category preset", "kentest", MB_OK );
		break;
	case FILE_CATEGORY_TEMPLATE:
		SetupExtSubString( ptfReqData, pTmpExt, MAX_PATH );
		break;
	case FILE_CATEGORY_ANIMATION:
		MessageBox( NULL, "To Do the file category animation", "kentest", MB_OK );
		break;

	}//end of switch - flag

	// For default extension
	ptfReqData->nFileExt = GetFileExtIndex( ptfReqData );
}//end of InitFileReqData

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//01-03-07 JRS REPLACED entire function UpdateFileReqResultStrings( FILE_REQ_FOLDER_INFO* ptfReqData )
// W2K and Win98 behave different in file operation
void UpdateFileReqResultStrings( FILE_REQ_FOLDER_INFO* ptfReqData )
{
	_TCHAR drvN[5];			
	_TCHAR fDir[MAX_PATH];	
	_TCHAR fNam[MAX_PATH];
	_TCHAR fExt[MAX_PATH];

	// W2K and Win98 behave different in file operation
	if( WindowsVersionIs( WIN2000, 0, 1 ) )
	{	
		_tcscpy( ptfReqData->CompleteFileName,ptfReqData->FileName);	 //drive + path name + file name + file ext
	}
	else
	{
		_tcscpy(ptfReqData->CompleteFileName,ptfReqData->FolderPath);
		_tcscat(ptfReqData->CompleteFileName,"\\");
		_tcscat(ptfReqData->CompleteFileName,ptfReqData->FileName);
	}//end of else
	
	_tsplitpath( ptfReqData->CompleteFileName, drvN, fDir, fNam, fExt );
 	CString newDir( fDir );
	newDir.Delete( newDir.GetLength()-1, 1 ); // take out the ending slash

	_tcscpy( ptfReqData->fileExt, fExt );
	_tcscpy( ptfReqData->FolderPath, drvN );
	_tcscat( ptfReqData->FolderPath, newDir );
	_tcscpy( ptfReqData->FileName, fNam); 


	/*call existing CGS utility to split "c:\alpha_cg\projects\test.acg" into "c:\alpha_cg\projects"  "test"  ".acg" */

	//---------------------------------------------
	//01-03-07 JRS ADDITIONS
//	CGS_GetComponentsFromFileName(ptfReqData->CompleteFileName,ptfReqData->FolderPath,ptfReqData->FileName,ptfReqData->fileExt);
	//---------------------------------------------

}//end of UpdateFileReqResultStrings

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// This function invokes common dialog function to open or save a file.
// 1) Initializes the OPENFILENAME structure
// 2) Calls the GetOpenFileName() or GetSaveFileName() for open common dialog function.
//	
// INPUT  : HWND hWnd - handle of parent window of the file open dialog
// INPUT  : FILE_REQ_FOLDER_INFO* ptfReqData - struct of data, used some fields as input param
//
// OUTPUT : FILE_REQ_FOLDER_INFO* ptfReqData - struct of data, used all fields
//
// RETURN : 1 - Operation successfully
//			0 - No file was opened
BOOL FileOperationW(  HWND hWnd, FILE_REQ_FOLDER_INFO* ptfReqData )
{

    HANDLE			hFile;
	OPENFILENAMEW	OpenFileName;
	BOOL			rv = 0; // default fail - have not do anything
	WCHAR			filter[MAX_PATH];
	WCHAR			fileExt[3];
	WCHAR			fileName[MAX_PATH];
	WCHAR			folderPath[MAX_PATH];

	HINSTANCE hInst = GetModuleHandle( NULL );

	ZeroMemory( &OpenFileName, sizeof(OPENFILENAME) );
	// Fill in the OPENFILENAME structure to support a template and hook.

	OpenFileName.lStructSize       = sizeof(OPENFILENAME);
    OpenFileName.hwndOwner         = hWnd;
    OpenFileName.hInstance         = hInst;
    OpenFileName.lpstrFilter       = filter;
    OpenFileName.lpstrCustomFilter = NULL;
    OpenFileName.nMaxCustFilter    = 0;
    OpenFileName.nFilterIndex      = 0;

	OpenFileName.lpstrFile         = fileName;//i.e. test.acg
    OpenFileName.nMaxFile          = MAX_PATH;;

    OpenFileName.lpstrFileTitle    = fileName; //i.e. test.acg
    OpenFileName.nMaxFileTitle     = MAX_PATH;

    OpenFileName.lpstrInitialDir   = folderPath;
//    OpenFileName.lpstrTitle        = "AAA";
    OpenFileName.nFileOffset       = 0;
    OpenFileName.nFileExtension    = 0;
    OpenFileName.lpstrDefExt       = fileExt;
	OpenFileName.lpfnHook 		   = NULL;
	OpenFileName.lpfnHook 		   = (LPOFNHOOKPROC)FileReqDlgProc;
    OpenFileName.lCustData         = (LPARAM)&sMyData;	
	OpenFileName.Flags             =  /*OFN_ENABLEHOOK  
									| */OFN_EXPLORER
									| OFN_OVERWRITEPROMPT									
									| OFN_HIDEREADONLY;
	
	if( ptfReqData->nFileType == FILE_CATEGORY_PICTURE )
	{	// reset the OpenFileName.Flags to enable the template
		OpenFileName.lpTemplateName  = (LPCWSTR)MAKEINTRESOURCE(IDD_PIC_FILE_DLG); 
		OpenFileName.Flags			|= OFN_ENABLETEMPLATE | OFN_ENABLEHOOK;
	}

	if( ptfReqData->opt ) // Call the common dialog function.
	{
		if( GetSaveFileNameW(&OpenFileName) )
		{
			rv = 1; // ok - good
		}
		else
   		{	// display error -- ??????? - may be not
//			ProcessCDError( CommDlgExtendedError(), hWnd );
			rv = 0;
		}		
	}// end of if - save file
	else
	{
		if( GetOpenFileNameW(&OpenFileName) ) // open file
		{
			// Open the file - is the file exist?
			char fn[MAX_PATH];

//			UnicodeToMultiByte( 932, (char*)OpenFileName.lpstrFile, fn );
			WideCharToMultiByte(932,               // code page
								0,		                // dwFlags
								OpenFileName.lpstrFile,	// lpWideCharStr
								-1,                     // cchWideCharStr
								fn,						// lpMultiByteStr
								MAX_PATH,				// cchMultiByte
								NULL,                   // lpDefaultChar
								NULL					// lpUsedDefaultChar
							);        

			if( (hFile = CreateFile(fn,
//			if( (hFile = CreateFile((LPCTSTR)OpenFileName.lpstrFile,
									GENERIC_READ,
									FILE_SHARE_READ,
									NULL,
									OPEN_EXISTING,
									FILE_ATTRIBUTE_NORMAL,
									(HANDLE)NULL)) == (HANDLE)-1)
			{
	    		rv = 0; //open fail - file doesn't exist
			}
			else
			{
				CloseHandle(hFile);
				rv = 1; // ok - good
			}			
		}// end of if - test the file exist or not
		else
   		{	// display error -- ??????? - may be not
//			ProcessCDError( CommDlgExtendedError(), hWnd );
			rv = 0;
		}
	}// end of else - open file

	return( rv );
//return( 0 );
}//end of FileOperationW()
/////////////////////////////////////////////////////////////////////////////////////////////
BOOL FileOperation(  HWND hWnd, FILE_REQ_FOLDER_INFO* ptfReqData )
{
    HANDLE			hFile;
	OPENFILENAME	OpenFileName;
	BOOL			rv = 0; // default fail - have not do anything

	HINSTANCE hInst = GetModuleHandle( NULL );

	ZeroMemory( &OpenFileName, sizeof(OPENFILENAME) );
	// Fill in the OPENFILENAME structure to support a template and hook.

	OpenFileName.lStructSize       = sizeof(OPENFILENAME);
    OpenFileName.hwndOwner         = hWnd;
    OpenFileName.hInstance         = hInst;
    OpenFileName.lpstrFilter       = (LPCTSTR)ptfReqData->ExtFilter;
    OpenFileName.lpstrCustomFilter = NULL;
    OpenFileName.nMaxCustFilter    = 0;
    OpenFileName.nFilterIndex      = ptfReqData->nFileExt;

	OpenFileName.lpstrFile         = ptfReqData->FileName;//i.e. test.acg
    OpenFileName.nMaxFile          = sizeof(ptfReqData->FileName);

    OpenFileName.lpstrFileTitle    = ptfReqData->FileName; //i.e. test.acg
    OpenFileName.nMaxFileTitle     = sizeof(ptfReqData->FileName);

    OpenFileName.lpstrInitialDir   = ptfReqData->FolderPath;
    OpenFileName.lpstrTitle        = ptfReqData->DlgTitle;
    OpenFileName.nFileOffset       = 0;
    OpenFileName.nFileExtension    = 0;
    OpenFileName.lpstrDefExt       = ptfReqData->fileExt;
	OpenFileName.lpfnHook 		   = NULL;
	OpenFileName.lpfnHook 		   = (LPOFNHOOKPROC)FileReqDlgProc;
    OpenFileName.lCustData         = (LPARAM)&sMyData;	
	OpenFileName.Flags             =  /*OFN_ENABLEHOOK  
									| */OFN_EXPLORER
									| OFN_OVERWRITEPROMPT									
									| OFN_HIDEREADONLY;
	
	if( (ptfReqData->nFileType == FILE_CATEGORY_PICTURE) && !ptfReqData->opt )
	{	// reset the OpenFileName.Flags to enable the template
		OpenFileName.lpTemplateName  = MAKEINTRESOURCE(IDD_PIC_FILE_DLG); 
		OpenFileName.Flags			|= OFN_ENABLETEMPLATE | OFN_ENABLEHOOK;
	}

	if( ptfReqData->opt ) // Call the common dialog function.
	{
		if( GetSaveFileName(&OpenFileName) )
		{
			ptfReqData->nFileExt = OpenFileName.nFilterIndex;
			rv = 1; // ok - good
		}
		else
   		{	// display error -- ??????? - may be not
//			ProcessCDError( CommDlgExtendedError(), hWnd );
			rv = 0;
		}		
	}// end of if - save file
	else
	{
		if( GetOpenFileName(&OpenFileName) ) // open file
		{
			// Open the file - is the file exist?
			if( (hFile = CreateFile((LPCTSTR)OpenFileName.lpstrFile,
									GENERIC_READ,
									FILE_SHARE_READ,
									NULL,
									OPEN_EXISTING,
									FILE_ATTRIBUTE_NORMAL,
									(HANDLE)NULL)) == (HANDLE)-1)
			{
	    		rv = 0; //open fail - file doesn't exist
			}
			else
			{
				CloseHandle(hFile);
				rv = 1; // ok - good
			}			
		}// end of if - test the file exist or not
		else
   		{	// display error -- ??????? - may be not
//			ProcessCDError( CommDlgExtendedError(), hWnd );
			rv = 0;
		}
	}// end of else - open file
	
	return( rv );
}//end of FileOperation(  )

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle win32 common dialog control for saving or opening operation.
// INPUT  : HINSTANCE hInst - Instance of app
// INPUT  : HWND hWnd - handle of the parent window of the file open dialog
// INPUT  : UINT flag - decide do open or save operation
// INPUT  : FILE_REQ_FOLDER_INFO - a global file request data struct, some fields work as 
//						input parameters
// RETURN : BOOL rv   - 1 : successful, 0 : fail
BOOL OnFileRequest( HWND hWnd, UINT flag, FILE_REQ_FOLDER_INFO* ptfReqData )
{
	BOOL rv = 0; //default fail - because of do nothing
	HINSTANCE hInst = GetModuleHandle( NULL );

	if( !SetCurrentDirectory(ptfReqData->FolderPath) ) 
	{	// Invalid Folder path; ie:set folder path point to program folder
		CGS_GetValStr( STATUS_PROGRAM_FOLDER, ptfReqData->FolderPath );
		lstrcat( ptfReqData->FolderPath, _T("\\tmp") );
		rv = CreateDirectory( ptfReqData->FolderPath, NULL );
		if( !SetCurrentDirectory(ptfReqData->FolderPath) ) // reset current directory
		{ 
			// still fail, set the folder path point to window directory
			GetWindowsDirectory( ptfReqData->FolderPath, MAX_PATH );			
		}
	}//end of if - SetCurrentDirectory fail
	if( FileOperation( hWnd, ptfReqData) )
//	if( FileOperationW( hWnd, ptfReqData) )	
	{
		UpdateFileReqResultStrings( ptfReqData );
		rv = 1;
	}
	else
		rv = 0;

	return( rv );
}//end of OnFileRequest

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SetPicDateNTime( HWND hDlg, _TCHAR* ptFileName )
{
	HANDLE hFile;
	if( (hFile = CreateFile((LPCTSTR)ptFileName, GENERIC_READ, FILE_SHARE_READ,	NULL, OPEN_EXISTING, 
							FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL)) != (HANDLE)-1)					
	{
		FILETIME	CreateTime;
		FILETIME	LastAccessTime;
		FILETIME	LastWriteTime;
		FILETIME	LocalFileTime;
		if( GetFileTime( hFile, &CreateTime, &LastAccessTime, &LastWriteTime ) == TRUE )						
		{							
			if( FileTimeToLocalFileTime( &LastWriteTime, &LocalFileTime ) == TRUE )
			{
				SYSTEMTIME	SystemTime;
				if( FileTimeToSystemTime( &LocalFileTime, &SystemTime ) == TRUE )
				{
					_TCHAR szTime[50];
					GetTimeFormat(NULL,TIME_NOSECONDS, &SystemTime, NULL, szTime, sizeof(szTime)); 

					_TCHAR szDate[50];
					GetDateFormat( NULL, DATE_LONGDATE,	&SystemTime, NULL, szDate, sizeof( szDate ) );

					ShowWindow( GetDlgItem(hDlg, IDC_STC_LAST_TIME), SW_SHOW );
					ShowWindow( GetDlgItem(hDlg, IDC_STC_LAST_DATE), SW_SHOW );
					SetDlgItemText(hDlg, IDC_STC_OUT_TIME, szTime);
					SetDlgItemText(hDlg, IDC_STC_OUT_DATE, szDate);
				}//end of if - File time to system time
			}//end of if - File time to local file time
		}//end of if - Get File Time
	}//end of if - create file

	CloseHandle( hFile );
}//end of SetPicDateNTime
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID DisplaySelectedPicInfo( HWND hDlg )
{
	// Get the file specification from the common dialog.
	if( CommDlg_OpenSave_GetSpec( GetParent(hDlg), g_szFile, sizeof(g_szFile)) <= sizeof(g_szFile) )
	{		
		if( g_szFile[0] != 0 ) // file name is here - szFile);
		{
			ShowWindow( GetDlgItem(hDlg, IDC_STC_NAME), SW_SHOW );
			SetDlgItemText(hDlg, IDC_STC_OUT_NAME, g_szFile); // set file name
		}
	}

	// Get the full path + file name of the selected file.
	if( CommDlg_OpenSave_GetFilePath(GetParent(hDlg), g_szFile, sizeof(g_szFile)) <= sizeof(g_szFile) )
	{
		// full file name here - szFile
		// window handle for picture draw on here - hWndPic
		HWND hWndPic = GetDlgItem( hDlg, IDC_PIC_FRAME );
		if( hWndPic != NULL ) // open for picture. if hWndPic == NULL, NOT open for picture
		{
			SetPicDateNTime( hDlg, g_szFile ); // set date and time		
			if( CGS_GetPictureInfo( g_szFile, hWndPic, BORDER, g_szSize) ) // 1 = ok, 0 - fail
				SetDlgItemText(hDlg, IDC_STC_OUT_RES, g_szSize); // set file name
			else
				SetDlgItemText(hDlg, IDC_STC_OUT_RES, _T("Unknown Format") ); // set file name

		}//end of hWndPic
	}//end of if
}//end of DisplaySelectedPicInfo
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// This function processes the WM_NOTIFY message notifications that is sent
//    to the hook dialog procedure for the File Open common dialog.
//BOOL NEAR PASCAL FileReqNotify(HWND hDlg, LPOFNOTIFY pofn)
BOOL FileReqNotify(HWND hDlg, LPOFNOTIFY pofn)
{	
	switch( pofn->hdr.code )
	{
		case CDN_SELCHANGE:		// The selection has changed.
			DisplaySelectedPicInfo( hDlg );
			CGS_GetPictureInfo( g_szFile, GetDlgItem( hDlg, IDC_PIC_FRAME ), BORDER, g_szSize); // 1 = ok, 0 - fail
			break;
		case CDN_TYPECHANGE:
			RedrawWindow( hDlg, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE );
			break;
		case CDN_FOLDERCHANGE:		// A new folder has been opened.
			{
				_TCHAR szFile[MAX_PATH];

				if (CommDlg_OpenSave_GetFolderPath(GetParent(hDlg),	szFile, sizeof(szFile)) <= sizeof(szFile))
				{
					// Display this new path in the appropriate box.
	// testing purpose
	//save 			SetDlgItemText(hDlg, IDC_SELECTED, szFile);
				}
			}
			break;
		
		case CDN_HELP:		// The "Help" pushbutton has been pressed.
			MessageBox(hDlg, _T("Got the Help button notify."), _T("ComDlg32 Test"), MB_OK);
			break;

		case CDN_FILEOK:	// The 'OK' pushbutton has been pressed.
			// Full file name here
			// pofn->lpOFN->lpstrFile);
			SetWindowLong(hDlg, DWL_MSGRESULT, 1L);
			break;
		
		case CDN_SHAREVIOLATION:	// Received a sharing violation.
			MessageBox(hDlg, _T("Got a sharing violation notify."), pofn->pszFile, MB_OK);
			break;
	}//end of switch - pofn->hdr.code

	
	return( 1 );
}//end of FileReqNotify

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// This function processes messages for the Custom File Open common dialog box.
//
// MESSAGES:
//	WM_INITDIALOG - save pointer to the OPENFILENAME structure in User data
//	WM_DESTROY - get the text entered and fill in the MyData structure
//	WM_NOTIFY - pass this message onto the FileReqNotify function
//	default - check for a sharing violation or the OK button & display a message box.
BOOL CALLBACK FileReqDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	TRACE0("FileReq.cpp : FileReqDlgProc\n");
	PAINTSTRUCT     ps;
	HDC             hDC = NULL, hMemDC = NULL;
	switch( uMsg )
	{
		case WM_INITDIALOG:
			// Save off the long pointer to the OPENFILENAME structure.
			TRACE0("\t FileReq.cpp : FileReqDlgProc - WM_INITDIALOG\n");
			// Clear the file name so that CGS_GetPictureInfo will not
			// draw the picture on 2nd time of loading dialog 
			ZeroMemory( g_szFile, sizeof(g_szFile) );
			ZeroMemory( g_szSize, sizeof(g_szSize) ); // not necessary
			SetWindowLong(hDlg, DWL_USER, lParam);
			break;

		case WM_DESTROY:
			{
			TRACE0("\t FileReq.cpp : FileReqDlgProc - WM_DESTROY\n");
			LPOPENFILENAME lpOFN = (LPOPENFILENAME)GetWindowLong(hDlg, DWL_USER);
			LPMYDATA psMyData = (LPMYDATA)lpOFN->lCustData;

//			GetDlgItemText(hDlg, IDC_FULL_PATH, psMyData->szTest1, sizeof(psMyData->szTest1));
//			GetDlgItemText(hDlg, IDC_SELECTED, psMyData->szTest2, sizeof(psMyData->szTest2));
			}
			break;
		case WM_PAINT:
//			hRect = GetDlgItem( hDlg, IDC_PIC_FRAME );
			CGS_GetPictureInfo( g_szFile, GetDlgItem( hDlg, IDC_PIC_FRAME ), BORDER, g_szSize); // 1 = ok, 0 - fail

			hDC = BeginPaint(hDlg, &ps);				
			EndPaint(hDlg, &ps);

			break;

		case WM_NOTIFY:
			FileReqNotify( hDlg, (LPOFNOTIFY)lParam );		

		default:
//			if( uMsg == cdmsgFileOK )
//			{
//				SetDlgItemText(hDlg, IDC_SELECTED, ((LPOPENFILENAME)lParam)->lpstrFile);
//				if( MessageBox(hDlg, "Got the OK button message.\n\nShould I open it?", "Kent Test", MB_YESNO )	== IDNO)
//				{
					SetWindowLong(hDlg, DWL_MSGRESULT, 1L);
//				}
//				break;
//			}
//			else 
//				if( uMsg == cdmsgShareViolation )
//				{
//					SetDlgItemText(hDlg, IDC_SELECTED, (LPSTR)lParam);
//					MessageBox(hDlg, "Got a sharing violation message.", "Kent Test", MB_OK);
//					break;
//				}			
			return( 0 );
	}//end of switch

	return( 1 );
}//end of FileReqDlgProc

///////////////////////////////////////////////////////////////////////////////////////////////////
// Generic File Request function - open dialog for open or save "Project Files", "RTV Video Files",
// "Text Files", "Any Picture Files", and "Palette Files"
// INPUT  : HWND hWnd - handle of the main app
// INPUT  : DWORD fileType - FILE_CATEGORY_ENUM
// INPUT  : DWORD dlgType - open caption or save as caption on dlg title
// RETURN : 1 - Normal, 0 - fail
BOOL FileRequestDlg( FILE_REQ_FOLDER_INFO* frd, FILE_CATEGORY_ENUM fileType )
{
	BOOL		rv = 1;
 	FILE_REQ_FOLDER_INFO	FRD;
 
	HWND hWnd = AfxGetMainWnd()->m_hWnd;

 	ZeroMemory( &FRD, sizeof(FILE_REQ_FOLDER_INFO) );
	_tcscpy( FRD.DlgTitle,   frd->DlgTitle );
	_tcscpy( FRD.FolderPath, frd->FolderPath );
	FRD.nFileType = fileType;
	FRD.opt = frd->opt; 
 	InitFileReqData( &FRD );

	// without message box when save/open action was canceled
 	if( !OnFileRequest( hWnd, fileType, &FRD ) )
	{
/**** Desable the message box when file open/save cancel 
		_TCHAR msg[MAX_PATH];
		_TCHAR title[MAX_PATH];

		switch( frd->opt )
		{
		case OPEN_OP:
			lstrcpy( title, _T("Open File...") );
			lstrcpy( msg, _T("Open file cancel") );
			break;
		case SAVE_OP:
			lstrcpy( title, _T("Save File As...") );
			lstrcpy( msg, _T("Save file cancel") );
			break;
		default:
			lstrcpy( title, _T("Notification") );
			lstrcpy( msg, _T("File operation") );
			break;
		}//end of switch - fileType
		MessageBox( hWnd, msg, title, MB_OK | MB_ICONINFORMATION );
**** Desable the message box when file open/save cancel ****/
		rv = 0;//fail
	}//end of if

	memcpy( frd, &FRD, sizeof(FILE_REQ_FOLDER_INFO) );
	CGS_SetFileCategoryPathInfo( frd );//jrs

	free( FRD.ExtFilter );
	return( rv );
}//end of FileRequestDlg
