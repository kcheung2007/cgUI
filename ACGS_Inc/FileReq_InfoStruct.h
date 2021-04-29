//FileReq_InfoStruct.h
#ifndef _FILEREQ_FOLDER_INFO_STRUCT_H_
#define _FILEREQ_FOLDER_INFO_STRUCT_H_

#include <windows.h>
#include <tchar.h>

//this is the current set of file categories that will be handled by the program
enum FILE_CATEGORY_ENUM
{
	FILE_CATEGORY_PROJECT,		//acg sequence files
	FILE_CATEGORY_EXPORT_PAGE,	//export page, export project
	FILE_CATEGORY_PICTURE,		//all picture types
	FILE_CATEGORY_MEDIA_CLIP,	//all video media proprietary and otherwise
	FILE_CATEGORY_PALETTE,		//palette sets
	FILE_CATEGORY_PRESET,		//style presets
	FILE_CATEGORY_TEXT,			//text documents for importing text
	FILE_CATEGORY_TEMPLATE,		//page templates
	FILE_CATEGORY_ANIMATION,	//rendered animations (may be dedicated hard drive (i.e. VideoToaster )
	FILE_CATEGORY_BITMAP		//for scanner input
	//FUTURE: add others here...
};

typedef struct
{
	//=================================================================================
	//These values will be maintained exclusively by UI
	_TCHAR	DlgTitle[MAX_PATH];		// dialog title for open file or save file as
	void*	ExtFilter;				// pointer to strings of extension
	_TCHAR*	extIndex[30];			// array of pointer to each extension sub string
	DWORD	nFileExt;				// default file ext index - input for OPENFILENAME
	FILE_CATEGORY_ENUM nFileType;	// indicate the file type : FILE_CATEGORY_PROJECT, etc. <-- IMPORTANT THIS MUST BE SET CORRECTLY
	BOOL	opt;					// specify operation function: 1 - save, 0 - open 

	//=================================================================================
	//These will be shared by the UI and the Core for both read and write
	//Before opening the file requester for a file category, the UI should call CGS_
	_TCHAR	CompleteFileName[MAX_PATH];	//(JUST A REQUESTER RESULT, ONLY UI WILL SET THIS) drive + path name + file name + file ext "c:\projects\test.acg"
	_TCHAR	FolderPath[MAX_PATH];		//(CORE AND UI WILL SET THIS) drive + path name "c:\projects" 
	_TCHAR	FileName[MAX_PATH];			//(CORE AND UI WILL SET THIS) file name + file ext "test.acg"
	_TCHAR	fileExt[MAX_PATH];			//(JUST A REQUESTER RESULT, ONLY UI WILL SET THIS) file extension only "acg" 

}FILE_REQ_FOLDER_INFO;


#endif //_FILEREQ_FOLDER_INFO_STRUCT_H_
