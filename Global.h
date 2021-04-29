/////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"

//JAPANESE LOCALE =====================================
#define JAPANESE_MS_MINCIO_FONT_NAME	"‚l‚r –¾’©"
#define JAPANESE_MS_GOTHIC_FONT_NAME	"\202\154\202\162 \202\157\203\123\203\126\203\142\203\116"

#define		WIN2000				5
#define		MAX_LINE_LEN		100
#define		D_UP				0
#define		D_UP_RIGHT			1
#define		D_RIGHT				2
#define		D_DOWN_RIGHT		3
#define		D_DOWN				4
#define		D_DOWN_LEFT			5
#define		D_LEFT				6
#define		D_UP_LEFT			7
#define		D_CENTER			8 // not implement yet
#define		MAXIMUM_SPREAD_TABS	20

#define		BORDER				2 // border size of preview window
#define		RGB_MODE			0
#define		HSV_MODE			1
#define		YIQ_MODE			2

#define		IX_THUMBTRACK		10
#define		JAPANESE_CP			932

#define		TITLE_MACHINE		0x50
#define		VIDEO_MACHINE		0x51

#define		SETUP_TYPE			TITLE_MACHINE

struct IN_TEXT_DATA
{
	DWORD	idTT;
	TCHAR	szTT[MAX_LINE_LEN];
};

struct CURSOR_HANDLE
{
	HCURSOR		Arrow;
	HCURSOR		Horz;
	HCURSOR		Vert;
	HCURSOR		FourWay;
	HCURSOR		LeftRight;
	HCURSOR		RightLeft;
	HCURSOR		RotateZ;

};//end of cursor type

// A global func to be called from several different places
extern VOID		IXReg_RedrawPageBinThumbTrack( double ); // dummy double 
extern VOID		IXReg_RedrawFontPresetThumbTrack( double ); // dummy double 
extern VOID		IXReg_RedrawPaletteThumbTrack( double ); // dummy double 
extern INT		IXDoTripleClick();
extern VOID		IXReg_UpdateVertScrollBar( double );
extern VOID		IXReg_UpdateHorzScrollBar( double );
extern BOOL		GetSuggestedPath( LPTSTR origLink, LPTSTR homePath, LPTSTR newPath );
extern DWORD	GetCodePage();
extern DWORD	LoadTooltipText( CHAR* fn, IN_TEXT_DATA** ttData );
extern DWORD	LoadTextFromCtl( CHAR* fn, CHAR* section, IN_TEXT_DATA* *g_txtData );
extern HFONT	ChangeControlFont(	HWND Hwnd, HFONT hfont,	_TCHAR *Font_name, long Font_Width,	long Font_Height, LONG Font_Weight);
extern VOID		ColorConversion(int from_mode, int to_mode, int *value1, int *value2, int *value3);
extern VOID		IXReg_UpdateIXGUI(DWORD inCoreValDefFlag);//JRS 01-05-04 added inCoreValDefFlag param
extern void		DoPageLabelDlg(char* pStringVal);
extern VOID		DoubleToAlphaString( double val, int decDigit, _TCHAR* Buf );
extern INT		ACGMessageBox( HWND hWnd, LPCTSTR msg, LPCTSTR title, UINT flag );
extern VOID		UpdateIXTabSetupDlg();
extern VOID		MultiByteToUnicode( UINT codePage, char* inStr, TCHAR* outStr );
extern VOID		UnicodeToMultiByte( UINT codePage, TCHAR* inStr, char* outStr );
extern CHAR*	acgReadLine( LPCSTR fn, CHAR* inStr, CHAR* bufStr );
extern VOID		KentDebugLog( char* szStr, DWORD val );
extern VOID		IXReg_ScrollBarEnableProc( BOOL horz, BOOL vert );
extern VOID		IXLoadPicDlg();
extern VOID		IXReg_SetMousePointerMode( int Mode );
extern VOID		IXReg_ShowObjPropertiesMenu( int objID );
extern INT		IXReg_DisplayTemplateMessageBox();
extern BOOL		WindowsVersionIs(DWORD dwMajor, DWORD dwMinor, WORD dwSPMajor);