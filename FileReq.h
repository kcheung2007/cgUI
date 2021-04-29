#ifndef _FILEREQ_H_
#define _FILEREQ_H_

#include <windows.h>
#include <commdlg.h>    // includes common dialog functionality
#include <dlgs.h>       // includes common dialog template defines
#include <cderr.h>      // includes the common dialog error codes
#include <stdlib.h>		// standard lib for _MAX_PATH...
#include "ACGS_Inc\\CGServerDll.h"

#define		PROJECT		100
#define		PICTURE		102
#define		VIDEOCL		104
#define		TEXTDOC		106
#define		PALETTE		108
#define		BITMAPS		110

#define		OPEN_OP		0
#define		SAVE_OP		1

#define		LINELEN		100

// ----------------------------------------------------------------------------------
/*
struct FILE_DATA
{
	_TCHAR	DlgTitle[MAX_PATH];		// dialog title for open file or save file as

	_TCHAR	CompleteFileName[MAX_PATH];//(RESULT)drive + path name + file name + file ext "c:\projects\test.acg"
	_TCHAR	FolderPath[MAX_PATH];	//(INITIAL VALUE AND RESULT) drive + path name "c:\projects"
	_TCHAR	FileName[MAX_PATH];		//(INITIAL VALUE AND RESULT) file name + file ext "test.acg"
	_TCHAR	fileExt[MAX_PATH];		//(RESULT) file extension only "acg"

	void*	ExtFilter;				// pointer to strings of extension
	_TCHAR*	extIndex[30];			// array of pointer to each extension sub string
	DWORD	nFileExt;				// default file ext index - input for OPENFILENAME
	DWORD	nFileType;				// indicate the file type : PICTURE, PROJECT...

	BOOL	opt;					// specify operation function: 1 - save, 0 - open 
};
*/

BOOL FileRequestDlg( FILE_REQ_FOLDER_INFO* frd, FILE_CATEGORY_ENUM fileType );

#endif // _FILEREQ_H_
