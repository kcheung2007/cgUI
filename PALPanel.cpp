// char b[20];
// _itoa( i, b, 10 );
// MessageBox( NULL, b, "Kentest", MB_OK );

#include "PALPanel.h"
#include "mbstring.h"
#include "Tooltip.h"
#include "FileReq.h"

#include <tchar.h>
#include <COMMCTRL.H>
#include "resource.h"
#include "stdio.h"
#include "KentDebug.h"
#include "wingdi.h"

#define XEXTERN extern
#include "OwnerDrawButton.h"
#include "Alpha.inc"
#include "ColorPanel.h"
#include "cg_edit.inc"
//#include "cg_edlow.inc"
#include "cg_seq.inc"
#include "Toolbar.h"
#include "AttribFace.h"
#include "AttribCast.h"
#include "AttribShadow.h"
#include "AttribOutline.h"
#include "AttributePanel.h"
#include "ACGS_Inc\\UI_Language.h"
#include "bin.h"
#undef XEXTERN

#define		DF					1	// 0 - disable debug info
//#define		NUM_TOOLTIP			29  // increase this number when adding tooltip
#define		TAG_HEIGHT			9	// height of tag
#define		TAG_HALF_WIDTH		4	// 1/2 width of tag, equal side triangle
//#define		ME_FACE_COLOR		101 // modify event face color
#define		MODIFY_EVENT		101 // modify event face color
#define		ME_FACE_OPACITY		102 // modify event face opacity
#define     ME_OUTLINE_COLOR	103
#define		ME_OUTLINE_OPACITY	104
#define		ME_SHADOW_COLOR		105
#define		ME_SHADOW_OPACITY	106
#define		ME_CAST_COLOR		107
#define		ME_CAST_OPACITY		108

struct		HSBAR
{
	INT		nMin;
	INT		nMax;
	INT		nPos;
};

HSBAR		g_hsb;

static		UINT			g_HPos;
static		UINT			g_SPos;
static		UINT			g_VPos;
							
static		UINT			g_RPos;
static		UINT			g_GPos;
static		UINT			g_BPos;
static		UINT			g_GrdPos;

static		INT				g_nTooltip;
static		TOOLTIP_DATA*	g_ttData;
			
WNDPROC		R_oldEdProc;
WNDPROC		G_oldEdProc;
WNDPROC		B_oldEdProc;
WNDPROC		Grd_oldEdProc;

struct PAL_VAL // inheri from Khoi
{
	HINSTANCE	hInst;
	
	HFONT		hToolTipFont;
	HHOOK		hHook;
	HWND		hWnd;
	HWND		hToolTip;
	HWND		parenthWnd, edit_hWnd;
	UINT		action;
	DWORD		modifyEvent;
};

static		PAL_VAL		g_PAL;

static		OWNDRAW		g_odCopy;	// kentest button control
static		OWNDRAW		g_odSwap;	// text for linear radio button
static		OWNDRAW		g_odAdd;	// text for circular radio button
static		OWNDRAW		g_odDel;
static		OWNDRAW		g_odClear;
static		OWNDRAW		g_odDup;
static		OWNDRAW		g_odSpace;
static		OWNDRAW		g_odShift;
static		OWNDRAW		g_odInvert;
static		OWNDRAW		g_odHues;
static		OWNDRAW		g_odLoad;
static		OWNDRAW		g_odSave;
static		OWNDRAW		g_odOk;
static		OWNDRAW		g_odCancel;

static		WNDCLASSEX	g_wndCtrlClass;

UINT		xPos;
UINT		g_SpreadWidth;
INT 		g_TagLockState = -1; // JIM's style of state machine??

//DWORD		g_counter = 0; //debug
INT			g_PalDibWidth;
INT			g_PalDibHeight;
DWORD		*PalDibSectionPtr; //pointer to actual memory array allocated by CreateDibSection()

ALPHA_COLOR_BOX SavedColorBox[TOTAL_PALETTE_BANKS * TOTAL_PALETTE_BOXES + 4]; // 224

// Local prototype function
void OnButSolid();
void PalDibFillRect( INT w, INT h, DWORD Color32);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL IsPALModifyEvent()
{
	return( g_PAL.modifyEvent );
}//end of IsPALModifyEvent
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// FACE_RGB_CB_IND is defined as zero which is conflict with "no modify button click".
// Therefore, add constant MODIFY_EVENT to increase the base value.
VOID SetPALModifyFlag()
{
	if( GetFaceColorModifyFlag() )
		 g_PAL.modifyEvent = FACE_RGB_CB_IND + MODIFY_EVENT;
	else
		if( GetOutlineColorModifyFlag() )
			g_PAL.modifyEvent = OUTLINE_RGB_CB_IND + MODIFY_EVENT;
	else
		if( GetCastColorModifyFlag() )
			g_PAL.modifyEvent = CAST_RGB_CB_IND + MODIFY_EVENT;
	else
		if( GetShadowColorModifyFlag() )
			g_PAL.modifyEvent = SHADOW_RGB_CB_IND + MODIFY_EVENT;
	else
		g_PAL.modifyEvent = 0; // no modify button click
}//end of isModifyEvent
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Convert MS's COLORREF format (0x00bbggrr) to 32 bits 0xAARRGGBB
// INPUT  : COLORREF Color32 - MS's COLORREF
// RETURN : DWORD - 32 bits pixel in 0xAARRGGBB format
DWORD ConvertToARGB( COLORREF Color32 )
{
	DWORD color;
	DWORD red  = Color32 & 0x000000FF;
	DWORD blue = Color32 & 0x00FF0000;

	color = Color32 & 0xFF00FF00; //clear red and blue
	color = color | (red << 16) | (blue >> 16);

	return( color );
}//end of ConvertToARGB
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Draw the base color box. Set the Horizontal scroll bars and edit boxes value.
VOID DrawBaseColorBox()
{
	BOOL		rv;
	HBITMAP		hBmp;
	HBITMAP		hOldBmp;
	HDC			hDC;
	HDC			hMemDC;
	HWND		hBaseBox = GetDlgItem( hPALPanel, IDC_RECT_BASE_COLOR );
	INT			index = GetSelectedPaletteIndex();
	RECT		rcBaseBox;

	GetWindowRect( hBaseBox, &rcBaseBox );
	g_PalDibWidth  = rcBaseBox.right - rcBaseBox.left;
	g_PalDibHeight = rcBaseBox.bottom - rcBaseBox.top;
	rcBaseBox.left = 0;
	rcBaseBox.top  = 0;

	BITMAPINFOHEADER		bmpHeader;

	bmpHeader.biSize        = sizeof( BITMAPINFOHEADER );
	bmpHeader.biWidth       = g_PalDibWidth;
	bmpHeader.biHeight      = -g_PalDibHeight;
	bmpHeader.biPlanes      = 1;
	bmpHeader.biBitCount    = 32;
	bmpHeader.biCompression = BI_RGB;
	bmpHeader.biSizeImage   = g_PalDibWidth * g_PalDibHeight * sizeof(DWORD);


	hDC     = GetDC( hBaseBox );	// DC of base color box reference to screen memory
	hMemDC  = CreateCompatibleDC( hDC ); // DC of base color box reference to offscreen memory
	hBmp    = CreateDIBSection( hMemDC,
								(BITMAPINFO *)&(bmpHeader),
								DIB_RGB_COLORS,
								(void **)&(PalDibSectionPtr),
								NULL, 0 );

	hOldBmp = SelectObject( hMemDC, hBmp );
	PalDibFillRect( g_PalDibWidth, g_PalDibHeight, U_Alpha_palette_box[index].details.spread.color[U_Alpha_palette_box[index].details.spread.current_tab_index] );	
	rv = BitBlt( hDC, 0, 0, g_PalDibWidth, g_PalDibHeight, hMemDC, 0, 0, SRCCOPY );

	InitPALHScrollBar( GetSelectedPaletteIndex() ); // set Hscroll bars and edit boxes value

	hBmp = SelectObject( hMemDC, hOldBmp );

	DeleteObject( hBmp );
	DeleteDC( hMemDC );
	ReleaseDC( hBaseBox, hDC );
}//end of DrawBaseColorBox()
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
INT CompTag( INT index, INT j, INT k )
{
	if(   U_Alpha_palette_box[index].details.spread.spread_tab_position[j]
		< U_Alpha_palette_box[index].details.spread.spread_tab_position[k] )
		return( -1 );
	else
		if(   U_Alpha_palette_box[index].details.spread.spread_tab_position[k]
			< U_Alpha_palette_box[index].details.spread.spread_tab_position[j] )
			return( 1 );
		else
			return( 0 );
}//end of CompTag
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID DoSwap( INT index, INT j, INT k )
{
	COLORREF	tmpColor;
	float		tmpPos;

	tmpColor = U_Alpha_palette_box[index].details.spread.color[j];
	tmpPos   = U_Alpha_palette_box[index].details.spread.spread_tab_position[j];

	U_Alpha_palette_box[index].details.spread.color[j] = U_Alpha_palette_box[index].details.spread.color[k];
	U_Alpha_palette_box[index].details.spread.spread_tab_position[j] = U_Alpha_palette_box[index].details.spread.spread_tab_position[k];

	U_Alpha_palette_box[index].details.spread.color[k] = tmpColor;
	U_Alpha_palette_box[index].details.spread.spread_tab_position[k] = tmpPos;

	//U_Alpha_palette_box[index].details.spread.current_tab_index = j; // update tag index
}//end of DoSwap
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID SortTag( INT index )
{
	INT numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;

	INT i, j, gap;

	for( gap = numTag/2; 0 < gap; gap /=2 )
		for( i = gap; i < numTag; i++ )
			for( j = i - gap; 0 <= j; j -= gap )
			{
				if( CompTag( index, j, j+gap ) <= 0 )
					break;
				DoSwap( index, j, j+gap );
			}//end of for
}//end of SortTag
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INPUT  : INT x - current x position of mouse pointer
// RETURN : INT i - selected tag index or -1 if no tag was selected.
INT GetSelectedTag( INT x ) 
{
	float	dw   = (float)TAG_HALF_WIDTH/g_SpreadWidth;
	double	xMos = (double)x/g_SpreadWidth;
	float	xTag;
	
	int		i = 0;
	int		index  = GetSelectedPaletteIndex();
	int		numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;
	int		rv = -1; // default - error

	for( i = 0; i < numTag; i++ )
	{
		xTag = U_Alpha_palette_box[index].details.spread.spread_tab_position[i];
		if( ((xTag - dw) < xMos) && (xMos < (xTag + dw)) )
			return( i );
	}//end of for

	return( -1 );
}//end of GetSelectedTag
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INPUT : INT x - current x position of mouse pointer
// INPUT : WPARAM wParam - MK_LBUTTON message
// BE CAREFUL !!! Using JIM's state machine style to lock the selected tag ... 
// WIN32 style was given up and need to be very careful on future development...
// REMEMBER : All mouse messages should check the lock state. 
// 1) Get the current selected color palette from color panel.
// 2) Get total number of tags from the selected color palette.
// 3) Lock the tag ??
// 4) Assign the current tag position of the selected color palette.
// 5) Save the current color of the selected tag. It is neccessary for the mulitple 
//    tag on the same position but different color attribute.
// 6) Drawa the whole tag data structure... Keep up the tag position.
// 7) Sort the tag positino for core function.
// 8) Re-gain the current selected tag. After sortnig, the tag position may change.
// 9) Redraw everythings...
VOID MovingTag( INT x, WPARAM wParam )
{		
	INT			index;
	INT			iTag;
	INT			numTag;
	COLORREF	tColor; // selected tag color
	float		tPos; //tag position
	
	xPos = x;
	if( wParam == MK_LBUTTON )
	{
		tPos = xPos/(float)127.0;
		if( 1 < tPos )
			tPos = 1;

		index = GetSelectedPaletteIndex();
		numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;

		if( g_TagLockState != -1 )
			iTag = g_TagLockState;
		else
			return;

		U_Alpha_palette_box[index].details.spread.spread_tab_position[iTag] = tPos;
		tColor = U_Alpha_palette_box[index].details.spread.color[iTag];

		SortTag( index );

		for( int i = 0; i < numTag; i++ ) // reset the current selected tag
		{
			if( U_Alpha_palette_box[index].details.spread.spread_tab_position[i] == tPos )
			{
				if( tColor == U_Alpha_palette_box[index].details.spread.color[i] )
					g_TagLockState = U_Alpha_palette_box[index].details.spread.current_tab_index = i;
			}

			if( U_Alpha_palette_box[index].details.spread.spread_tab_position[i] == tPos && tPos == 1 )
			{
				g_TagLockState = U_Alpha_palette_box[index].details.spread.current_tab_index = i;
				break;
			}
		}//end of for

		DrawTagFromDib();

		RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
		DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
		if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
		{
			RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
			HighLitColorCell( hColorPanel, IDC_1+index );
		}

/***debug
char buf[255];
Kdebug( "++++++++  iTag = ", iTag, DF );
for( int m = 0; m < numTag; m++ )
{
	sprintf( buf, "Tag position = %f\n", U_Alpha_palette_box[index].details.spread.spread_tab_position[m] );
	OutputDebugString( buf );
}
*** debug ***/

	}//end of if - most outer
}//end of MovingTag
////////////////////////////////////////////////////////////////////////////////////////////
// S T A R T		O F			C U S T O M		 W I N D O W S
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// START			OF		SLIDER		CONTROL			WINDOW
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LRESULT CALLBACK PALSliderCtrlProc( HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT	ps;
	HDC			hDC;
	INT			iTag;
	UINT		index;
	
    switch( iMsg )          
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		break;
	case WM_PAINT:
		hDC = BeginPaint( hWnd, &ps );		
		DrawTagFromDib();
        EndPaint( hWnd, &ps );
		return( 0 );
	case WM_KEYUP :
		 break;
	case WM_LBUTTONDOWN:		
		iTag = GetSelectedTag( xPos );
		index = GetSelectedPaletteIndex();
		if(  iTag != -1 )
		{
			g_TagLockState = iTag; // lock
			U_Alpha_palette_box[index].details.spread.current_tab_index = iTag;
		}
		//else - no change on the tag lock state

		DrawTagFromDib();
		DrawBaseColorBox();
		break;
	case WM_LBUTTONUP:			
		g_TagLockState = -1; // release lock stats - JIM's style
		break;
	case WM_RBUTTONUP:		
		break;
	case WM_MOUSEMOVE:	
		MovingTag( GET_X_LPARAM(lParam), wParam );
//		RedrawWindow( hWnd, NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW );
Kdebug("Mouse move",0,DF);
		break;
	 }//end of switch
     return DefWindowProc( hWnd, iMsg, wParam, lParam) ;
}//end of PALSliderCtrlProc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID WndClassPALSliderCtrl()
{
     g_wndCtrlClass.cbSize        = sizeof( g_wndCtrlClass );
     g_wndCtrlClass.style         = CS_HREDRAW | CS_VREDRAW | CS_SAVEBITS | CS_OWNDC;
     g_wndCtrlClass.lpfnWndProc   = PALSliderCtrlProc;
     g_wndCtrlClass.cbClsExtra    = 0;
     g_wndCtrlClass.cbWndExtra    = DLGWINDOWEXTRA;
     g_wndCtrlClass.hInstance     = U_Alpha_DLL_hInstance;
     g_wndCtrlClass.hIcon         = NULL;
     g_wndCtrlClass.hCursor       = NULL;
     g_wndCtrlClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     g_wndCtrlClass.lpszMenuName  = NULL ;
     g_wndCtrlClass.lpszClassName = "PALSliderCtrl";
     g_wndCtrlClass.hIconSm       = NULL;

     RegisterClassEx( &g_wndCtrlClass );

}//end of WndClassPALSliderCtrl()
// END			OF		SLIDER		CONTROL				WINDOW
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// START			OF		COLOR		CONTROL			WINDOW
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LRESULT CALLBACK PALColorCtrlProc( HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam )
{
    HDC			hdc;
    PAINTSTRUCT	ps;
	INT			index;
	
    switch( iMsg )          
	{        
	case WM_PAINT:
		hdc = BeginPaint( hWnd, &ps );
		index = GetSelectedPaletteIndex();
		DrawTagFromDib();
		RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
//		DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
		if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
		{
			RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
			HighLitColorCell( hColorPanel, IDC_1+index );
		}
        EndPaint( hWnd, &ps );
		return( 0 );
	case WM_KEYUP :
		 break;		 
	case WM_LBUTTONUP :
		 return( 0 );
 	case WM_MOUSEMOVE:			
		if( wParam == MK_LBUTTON )
		{
			UINT  index = GetSelectedPaletteIndex();
			double xPos = GET_X_LPARAM( lParam )/58.0;
			double yPos = GET_Y_LPARAM( lParam )/61.0;
			U_Alpha_palette_box[index].details.spread.f_rel_center_x = (float)xPos;
			U_Alpha_palette_box[index].details.spread.f_rel_center_y = (float)yPos;
			RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );

			if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
			{
				RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
				HighLitColorCell( hColorPanel, IDC_1+index );
			}
		}//end of if - wParam
	 }//end of switch
     return DefWindowProc( hWnd, iMsg, wParam, lParam) ;
}//end of PALColorCtrlProc

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID WndClassPALColorCtrl()
{
     g_wndCtrlClass.cbSize        = sizeof( g_wndCtrlClass );
     g_wndCtrlClass.style         = CS_HREDRAW | CS_VREDRAW;
     g_wndCtrlClass.lpfnWndProc   = PALColorCtrlProc;
     g_wndCtrlClass.cbClsExtra    = 0;
     g_wndCtrlClass.cbWndExtra    = 0;
     g_wndCtrlClass.hInstance     = U_Alpha_DLL_hInstance;
     g_wndCtrlClass.hIcon         = NULL;
     g_wndCtrlClass.hCursor       = NULL;
     g_wndCtrlClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     g_wndCtrlClass.lpszMenuName  = NULL ;
     g_wndCtrlClass.lpszClassName = "PALColorCtrl";
     g_wndCtrlClass.hIconSm       = NULL;

     RegisterClassEx( &g_wndCtrlClass );
}//end of WndClassPALColorCtrl()
// END			OF		COLOR		CONTROL			WINDOW
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// START		OF		BASE		COLOR		CONTROL			WINDOW
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LRESULT CALLBACK PALBaseColorProc( HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam )
{
    HDC			hdc;
    PAINTSTRUCT	ps;
	
    switch( iMsg )          
	{        
	case WM_PAINT:
		hdc = BeginPaint( hWnd, &ps );		
		DrawBaseColorBox();
        EndPaint( hWnd, &ps );
		return( 0 );
	case WM_KEYUP :
		 break;		 
	case WM_LBUTTONUP :
		 return( 0 );
	 }//end of switch
     return DefWindowProc( hWnd, iMsg, wParam, lParam) ;
}//end of PALBaseColorProc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID WndClassPALBaseColor()
{
     g_wndCtrlClass.cbSize        = sizeof( g_wndCtrlClass );
     g_wndCtrlClass.style         = CS_HREDRAW | CS_VREDRAW;
     g_wndCtrlClass.lpfnWndProc   = PALBaseColorProc;
     g_wndCtrlClass.cbClsExtra    = 0;
     g_wndCtrlClass.cbWndExtra    = 0;
     g_wndCtrlClass.hInstance     = U_Alpha_DLL_hInstance;
     g_wndCtrlClass.hIcon         = NULL;
     g_wndCtrlClass.hCursor       = NULL;
     g_wndCtrlClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     g_wndCtrlClass.lpszMenuName  = NULL ;
     g_wndCtrlClass.lpszClassName = "PALBaseColor";
     g_wndCtrlClass.hIconSm       = NULL;

     RegisterClassEx( &g_wndCtrlClass );
}//end of WndClassPALBaseColor()
// END		OF		BASE		COLOR		CONTROL			WINDOW
////////////////////////////////////////////////////////////////////////////////////////////
// START			OF		SPREAD			COLOR			WINDOW
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LRESULT CALLBACK PALSpreadBoxProc( HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT	ps;
	HDC			hDC;
	INT			index;

    switch( iMsg )          
	{
	case WM_PAINT:
		hDC = BeginPaint( hWnd, &ps );
		index = GetSelectedPaletteIndex();
		DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
        EndPaint( hWnd, &ps );
		return( 0 );
	 }//end of switch
     return DefWindowProc( hWnd, iMsg, wParam, lParam) ;
}//end of PALSpreadBoxProc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID WndClassPALSpraedBox()
{
     g_wndCtrlClass.cbSize        = sizeof( g_wndCtrlClass );
     g_wndCtrlClass.style         = CS_HREDRAW | CS_VREDRAW;
     g_wndCtrlClass.lpfnWndProc   = PALSpreadBoxProc;
     g_wndCtrlClass.cbClsExtra    = 0;
     g_wndCtrlClass.cbWndExtra    = 0;
     g_wndCtrlClass.hInstance     = U_Alpha_DLL_hInstance;
     g_wndCtrlClass.hIcon         = NULL;
     g_wndCtrlClass.hCursor       = NULL;
     g_wndCtrlClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     g_wndCtrlClass.lpszMenuName  = NULL ;
     g_wndCtrlClass.lpszClassName = "PALSpreadBox";
     g_wndCtrlClass.hIconSm       = NULL;

     RegisterClassEx( &g_wndCtrlClass );
}//end of WndClassPALSpraedBox()
// END			OF		SPREAD			COLOR			WINDOW
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// E N D		O F			C U S T O M		 W I N D O W
////////////////////////////////////////////////////////////////////////////////////////////
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Save all color palettes (whole data block of U_Alpha_palette_box) for 
// restoring operation.
VOID BackupColorBoxes()
{
	memcpy( SavedColorBox, U_Alpha_palette_box, sizeof(SavedColorBox) ); 
}//end of SaveColorBoxes
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Restore whole array of color paletta back to U_Alpha_palette_box.
VOID RestoreColorBoxes()
{
	memcpy( U_Alpha_palette_box, SavedColorBox, sizeof(SavedColorBox) );
}//end of RestoreColorBoxes
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID EnableRotationScrollBar()
{
	EnableWindow( GetDlgItem(hPALPanel, IDC_PAL_SBAR_ROTATE), 1 );
	EnableWindow( GetDlgItem(hPALPanel, IDC_PAL_ED_ROTATE),   1 );
	EnableWindow( GetDlgItem(hPALPanel, IDC_GB_ROTATE),       1 );
}//end of EnableRotationScrollBar
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID DisableRotationScrollBar()
{
	EnableWindow( GetDlgItem(hPALPanel, IDC_PAL_SBAR_ROTATE), 0 );
	EnableWindow( GetDlgItem(hPALPanel, IDC_PAL_ED_ROTATE),   0 );
	EnableWindow( GetDlgItem(hPALPanel, IDC_GB_ROTATE),       0 );
}//end of EnableRotationScrollBar
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Reset the palette panel action. At this moment mean clear the action code
// INPUT : UINT action - indicate the action - should be 0 at this momemt
VOID SetPALAction( UINT action )
{
	g_PAL.action = action;
}//end of SetPALAction
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Return the current action of Palette panel for other file use.
UINT GetPALAction()
{
	return( g_PAL.action );
}//end of GetPALAction
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static VOID SetStaticText( HWND hDlg, UCHAR* ptLn )
{
	UCHAR	sep[] = "\"";
	UCHAR*	ptID;
	UCHAR*	ptText;
	UCHAR*	ptEnd;
	
	ptID   = _mbstok( ptLn, sep );
	ptText = _mbstok( NULL, sep );
	ptEnd  = _mbstok( NULL, sep );
	if( ptEnd != NULL )
		*ptEnd = '\0';

	if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SOLID" ) )
		SetDlgItemText( hDlg, IDC_PAL_SOLID, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_LINEAR" ) )
			SetDlgItemText( hDlg, IDC_PAL_LINEAR, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_CIRCULAR" ) )
			SetDlgItemText( hDlg, IDC_PAL_CIRCULAR, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_4POINT" ) )
			SetDlgItemText( hDlg, IDC_PAL_4POINT, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_GB_PALETTE" ) )
			SetDlgItemText( hDlg, IDC_GB_PALETTE, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_BG_CUR_COLOR" ) )
			SetDlgItemText( hDlg, IDC_BG_CUR_COLOR, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_GB_BASE_COLOR" ) )
			SetDlgItemText( hDlg, IDC_GB_BASE_COLOR, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_VDO_SAFE" ) )
			SetDlgItemText( hDlg, IDC_VDO_SAFE, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_GB_INDICATOR" ) )
			SetDlgItemText( hDlg, IDC_GB_INDICATOR, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_GB_ROTATE" ) )
			SetDlgItemText( hDlg, IDC_GB_ROTATE, (LPCTSTR)ptText );
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_GB_PAL" ) )
			SetDlgItemText( hDlg, IDC_GB_PAL, (LPCTSTR)ptText );
}//end of SetStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of static text for Palette Panel dialog.
BOOL InitPalPanelStaticText( HWND hDlg )
{
	UCHAR   szFullName[MAX_PATH];
	UCHAR	bufStr[MAX_LINE_LEN];
	FILE*	inFile;

	strcpy( (LPTSTR)szFullName, U_Alpha_program_directory );
	strcat( (LPTSTR)szFullName, "\\Util\\PalPanel.ctl" );
	if( NULL == (inFile = fopen((LPTSTR)szFullName, "r")) )
	{
		MessageBox( NULL, "File not found.", "Warning", MB_ICONSTOP|MB_OK );
		return( 1 );
	}

	while( !feof( inFile ) )
	{
		if( NULL == fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _mbsstr( bufStr, (UCHAR*)"[Static Text" ) )
		{
			while( NULL != fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
			{
				if( NULL == _mbsstr( bufStr, (UCHAR*)"end") )
					SetStaticText( hDlg, bufStr );
				else
					break;
			}//end of while
		}//end of if
	}//end of while

	fclose( inFile );
	return( 0 ); // normal
}//end of InitPalPanelStaticText
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
UCHAR* GetPalPanelTooltip( UINT id )
{
	for( int i = 0; i < g_nTooltip; i++ )
	{
		if( id == g_ttData[i].idTT )
			return( (g_ttData+i)->szTT );
	}//end of for
	
	return( NULL );
}//end of GetPalPanelTooltip
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Pass a string with tooltip id and tooltip string and set the tooltip data
// base on the input string. Idea: break the input string to two part: 1) the string
// of tooltip id and string of tooltip message. Compare the tooltip id string and copy
// the cooresponding tooltip message string to TOOLTIP_DATA.
// INPUT : UCHAR* ptLn - string with tooltip id and tooltip message
// INPUT : TOOLTIP_DATA* tt - structure of TOOLTIP_DATA for storing tooltip info
static UINT SetTooltipData( UCHAR* ptLn, TOOLTIP_DATA* tt )
{
	UCHAR	sep[] = "\"";
	UCHAR*	ptID;
	UCHAR*	ptTT;
	UCHAR*	ptEnd;
	
	ptID   = _mbstok( ptLn, sep );
	ptTT   = _mbstok( NULL, sep );
	ptEnd  = _mbstok( NULL, sep );
	if( ptEnd != NULL )
		*ptEnd = '\0';

	if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_COPY" ) )
	{
		tt->idTT = IDC_PAL_COPY;
		_mbscpy( tt->szTT, ptTT );
	}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SWAP" ) )
		{
			tt->idTT = IDC_PAL_SWAP;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_ADD" ) )
		{
			tt->idTT = IDC_PAL_ADD;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_DEL" ) )
		{
			tt->idTT = IDC_PAL_DEL;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_CLEAR" ) )
		{
			tt->idTT = IDC_PAL_CLEAR;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_DUP" ) )
		{
			tt->idTT = IDC_PAL_DUP;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SPACE" ) )
		{
			tt->idTT = IDC_PAL_SPACE;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SHIFT" ) )
		{
			tt->idTT = IDC_PAL_SHIFT;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_INVERT" ) )
		{
			tt->idTT = IDC_PAL_INVERT;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_INVERT" ) )
		{
			tt->idTT = IDC_PAL_INVERT;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_HUES" ) )
		{
			tt->idTT = IDC_PAL_HUES;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_LOAD" ) )
		{
			tt->idTT = IDC_PAL_LOAD;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SAVE" ) )
		{
			tt->idTT = IDC_PAL_SAVE;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_OK" ) )
		{
			tt->idTT = IDC_PAL_OK;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_CANCEL" ) )
		{
			tt->idTT = IDC_PAL_CANCEL;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SOLID" ) )
		{
			tt->idTT = IDC_PAL_SOLID;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_LINEAR" ) )
		{
			tt->idTT = IDC_PAL_LINEAR;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_4POINT" ) )
		{
			tt->idTT = IDC_PAL_4POINT;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_CIRCULAR" ) )
		{
			tt->idTT = IDC_PAL_CIRCULAR;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_HSV" ) )
		{
			tt->idTT = IDC_PAL_HSV;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_RGB" ) )
		{
			tt->idTT = IDC_PAL_RGB;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_VDO_SAFE" ) )
		{
			tt->idTT = IDC_VDO_SAFE;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SBAR_R" ) )
		{
			tt->idTT = IDC_PAL_SBAR_R;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SBAR_G" ) )
		{
			tt->idTT = IDC_PAL_SBAR_G;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SBAR_B" ) )
		{
			tt->idTT = IDC_PAL_SBAR_B;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_SBAR_ROTATE" ) )
		{
			tt->idTT = IDC_PAL_SBAR_ROTATE;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_ED_R" ) )
		{
			tt->idTT = IDC_PAL_ED_R;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_ED_G" ) )
		{
			tt->idTT = IDC_PAL_ED_G;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_ED_B" ) )
		{
			tt->idTT = IDC_PAL_ED_B;
			_mbscpy( tt->szTT, ptTT );
		}
	else
		if( NULL != _mbsstr( ptID, (UCHAR*)"IDC_PAL_ED_ROTATE" ) )
		{
			tt->idTT = IDC_PAL_ED_ROTATE;
			_mbscpy( tt->szTT, ptTT );
		}

	return( 0 );
}//end of SetTooltipData
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Max. nubmer of tooltips for Text Panel dialog is 11.
BOOL InitPalPanelTooltip()
{
	UCHAR   szFullName[MAX_PATH];
	UCHAR	bufStr[MAX_LINE_LEN];
	FILE*	inFile;
	INT		i = 0;

	strcpy( (LPTSTR)szFullName, U_Alpha_program_directory );
	strcat( (LPTSTR)szFullName, "\\Util\\PalPanel.ctl" );
	if( NULL == (inFile = fopen((LPTSTR)szFullName, "r")) )
	{
		MessageBox( NULL, "File not found.", "Warning", MB_ICONSTOP|MB_OK );
		return( 1 );
	}
	while( !feof( inFile ) )
	{
		if( NULL == fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _mbsstr( bufStr, (UCHAR*)"[Tooltip" ) )
		{
			while( NULL != fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
			{
				if( NULL == _mbsstr( bufStr, (UCHAR*)"end") )
					g_nTooltip++;
				else
					break;
			}//end of while
		}//end of if
		break;
	}//end of while

	rewind( inFile );
	g_ttData = (TOOLTIP_DATA*)malloc( sizeof(TOOLTIP_DATA) * g_nTooltip );
	while( !feof( inFile ) )
	{
		if( NULL == fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}//end of if 

		if( NULL != _mbsstr( bufStr, (UCHAR*)"[Tooltip" ) )
			break; // move file pointer to line of [Tooltip] 
	}//end of while
	for( i = 0; i < g_nTooltip; i++ )
	{
		if( NULL == fgets( (CHAR*)bufStr, MAX_LINE_LEN, inFile ) )
		{
			fclose( inFile );
			return( 1 );// error
		}

		SetTooltipData( bufStr, &g_ttData[i] );
	}//end of for

	fclose( inFile );
	return( 0 ); // normal
}//end of InitPalPanelTooltip
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Refresh all GUI - Not use at this moment... for core change the GUI....
// May pass a gobal structure
void RedrawPalPanelGUI()
{
	INT		iCtrlID;
	UINT	index = GetSelectedPaletteIndex();	 

	// TO DO : Read the inital value and set the control id for top 4 radio buttons
	iCtrlID = U_Alpha_palette_box[index].details.spread.spread_type;
	CheckRadioButton( g_PAL.hWnd, IDC_PAL_SOLID, IDC_PAL_CIRCULAR, iCtrlID );

	// TO DO : Read the inital value and set the control id for base color radio buttons
	iCtrlID = IDC_PAL_RGB; // default
	CheckRadioButton( g_PAL.hWnd, IDC_PAL_HSV, IDC_PAL_RGB, iCtrlID );

	// TO DO : Read the inital value and set the control id to 1 for check,
	//         or 0 for unchecked for the check box
	if( cg_edit_status.NTSC_safe_colors == 1 )
		CheckDlgButton( g_PAL.hWnd, IDC_VDO_SAFE, 1 );
	else
		CheckDlgButton( g_PAL.hWnd, IDC_VDO_SAFE, 0 );

	// TO DO : Read the inital value for RGB scroll bars and the edit boxes	
	InitPALHScrollBar( GetSelectedPaletteIndex() );
}//end of RedrawPalPanelGUI

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ SetPanelPosition()
// Set the right hand side panel position. It is necessary for moving
// the main windows and then recalculate the right panel position for redraw
void SetPALPanelPosition()
{
	RECT rc;	
	int x = 0;

	GetClientRect(g_PAL.parenthWnd, &rc);
	x = (rc.right - rc.left) - PAL_PANEL_WIDTH;
	::SetWindowPos(
				g_PAL.hWnd,			// Handle to dialog window
				HWND_TOP,				// Placement-order handle
				x,					// Horizontal position
				PAL_Y_POSITION,		// Vertical position
				PAL_PANEL_WIDTH,	// Width
				PAL_PANEL_HEIGHT,	// Height
				SWP_HIDEWINDOW);	// Flags

}//end of SetPALPanelPosition

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Initial the all radio buttons.
// 1) Read the initial vales form data structure??? or file ???
// 2) Set the radio button
VOID SetPALRadioButton( UINT index )
{
	switch( U_Alpha_palette_box[index].details.spread.spread_type )
	{
	case LINEAR_SPREAD_TYPE:
		if( U_Alpha_palette_box[index].details.spread.spread_on )
			CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_LINEAR );
		else
			CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_SOLID );
		break;
	case CONCENTRIC_SPREAD_TYPE:
		CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_CIRCULAR );
		break;
	case FOUR_PT_SPREAD_TYPE:
		CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_4POINT );
		break;
	case BEVEL_SPREAD_TYPE:
		break;
	case HORIZ2_SPREAD_TYPE:
		break;
	case VERT2_SPREAD_TYPE:
		break;
	case SIDE4_SPREAD_TYPE:
		break;
	}//end of switch

	// TO DO : Read the inital value and set the control id for base color radio buttons
	CheckRadioButton( g_PAL.hWnd, IDC_PAL_HSV, IDC_PAL_RGB, IDC_PAL_RGB ); // default

}//end of SetRadioButton

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Draw on the IDC_RECT_CUR_COLOR and IDC_BAR_SLIDER
void InitCurColor( HWND hDlg )
{
//save	UINT	index = GetSelectedPaletteIndex();	// current selected cell
	UINT	index = 0; // default to the first cell, 

	if( g_PAL.modifyEvent )
		index = 223; // last cell
	else
		index = 0; // default to the first cell
		
	RenderColorCell( GetDlgItem(hDlg, IDC_PAL_CUR_COLOR), index );
}//end of InitCurColor
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Initial the third part of base color group
// 1) Read the initial vales form data structure??? or file ???
// 2) Set the scroll bar range
// 3) Set the scroll bar thumb position
// 4) Set the edit boxes
VOID SetPALRotationHScroll( UINT index )
{
	HWND	hDlg = hPALPanel;
	UINT	nMin = 0;	// min. range of scroll bar
	UINT	nMax = 359; // max. range of scroll bar
	UINT	nPos = 0;	// position of scroll box 

	g_GrdPos = U_Alpha_palette_box[index].details.spread.spread_angle;

	nPos = g_GrdPos;
	SetScrollRange( GetDlgItem(hDlg, IDC_PAL_SBAR_ROTATE), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hDlg, IDC_PAL_SBAR_ROTATE), SB_CTL, nPos, 1 );
	SetDlgItemInt( hDlg, IDC_PAL_ED_ROTATE, g_GrdPos, 1 );
}//end of SetPALRotationHScroll
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID InitPALHScrollBar( UINT index )
{	
	BYTE		curTag = U_Alpha_palette_box[index].details.spread.current_tab_index;
	COLORREF	color  = U_Alpha_palette_box[index].details.spread.color[curTag];
	UINT		minH = 0;	// min. range of H scroll bar of HSV
	UINT		maxH = 359;	// max. range of H scroll bar of HSV
	UINT		nMin = 0;	// min. range of scroll bar
	UINT		nMax = 255; // max. range of scroll bar
	UINT		rPos = 0;	// position of scroll box 
	UINT		gPos = 0;	// position of scroll box 
	UINT		bPos = 0;	// position of scroll box 

	if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
	{
		rPos = g_HPos;
		gPos = g_SPos;
		bPos = g_VPos;
		
		SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, minH, maxH, 1 );	
		SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, rPos, 1 );
		SetDlgItemInt( hPALPanel, IDC_PAL_ED_R, rPos, 1 );
	}
	else
	{
		g_RPos = rPos = color & 0x000000FF;
		g_GPos = gPos = (color & 0x0000FF00) >> 8;
		g_BPos = bPos = (color & 0x00FF0000) >> 16;
		SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, nMin, nMax, 1 );	
		SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, rPos, 1 );
		SetDlgItemInt( hPALPanel, IDC_PAL_ED_R, rPos, 1 );
	}

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, gPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_G, gPos, 1 );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, bPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_B, bPos, 1 );

	switch( U_Alpha_palette_box[index].details.spread.spread_type )
	{
	case LINEAR_SPREAD_TYPE:
		if( BST_CHECKED == IsDlgButtonChecked(hPALPanel, IDC_PAL_SOLID) )
			DisableRotationScrollBar();
		else
		{
			SetPALRotationHScroll( index );
			EnableRotationScrollBar();
		}	
		break;
	case CONCENTRIC_SPREAD_TYPE:
		DisableRotationScrollBar();
		break;
	case FOUR_PT_SPREAD_TYPE:
		DisableRotationScrollBar();
		break;
	}//end of switch
}//end of InitPALHScrollBar

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Initial the third part of base color group
// 1) Read the initial vales form data structure??? or file ???
// 2) Set the radio button
// 3) Check the video safe check box
// 4) Set the scroll bar range
// 5) Set the scroll bar thumb position
// 6) Set the edit boxes
void InitBaseColor( HWND hDlg )
{
	UINT		minH = 0;
	UINT		maxH = 359;
	UINT		nMin = 0;	// min. range of scroll bar
	UINT		nMax = 255; // max. range of scroll bar
	UINT		nPos = 0;	// position of scroll box 
	UINT		rPos;
	UINT		gPos;
	UINT		bPos;

	INT			index;

	// TO DO : Read the inital value
	if( g_PAL.modifyEvent )
		index = 223; // last box
	else
		index = GetSelectedPaletteIndex();;

	BYTE     curTag = U_Alpha_palette_box[index].details.spread.current_tab_index;
	COLORREF color  = U_Alpha_palette_box[index].details.spread.color[curTag];

	rPos = color  & 0x000000FF;
	gPos = (color & 0x0000FF00) >> 8;
	bPos = (color & 0x00FF0000) >> 16;

	CheckRadioButton( hDlg, IDC_PAL_RGB, IDC_PAL_HSV, IDC_PAL_RGB );

	if( cg_edit_status.NTSC_safe_colors == 1 )
		CheckDlgButton( hDlg, IDC_VDO_SAFE, 1 );
	else
		CheckDlgButton( hDlg, IDC_VDO_SAFE, 0 );

	if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
		SetScrollRange( GetDlgItem(hDlg, IDC_PAL_SBAR_R), SB_CTL, minH, maxH, 1 );
	else
		SetScrollRange( GetDlgItem(hDlg, IDC_PAL_SBAR_R), SB_CTL, nMin, nMax, 1 );
	
	SetScrollRange( GetDlgItem(hDlg, IDC_PAL_SBAR_G), SB_CTL, nMin, nMax, 1 );
	SetScrollRange( GetDlgItem(hDlg, IDC_PAL_SBAR_B), SB_CTL, nMin, nMax, 1 );

	SetScrollPos( GetDlgItem(hDlg, IDC_PAL_SBAR_R), SB_CTL, rPos, 0 );
	SetDlgItemInt( hDlg, IDC_PAL_ED_R, rPos, 1 );
	SetScrollPos( GetDlgItem(hDlg, IDC_PAL_SBAR_G), SB_CTL, gPos, 0 );
	SetDlgItemInt( hDlg, IDC_PAL_ED_G, gPos, 1 );
	SetScrollPos( GetDlgItem(hDlg, IDC_PAL_SBAR_B), SB_CTL, bPos, 0 );
	SetDlgItemInt( hDlg, IDC_PAL_ED_B, bPos, 1 );

}//end of InitBaseColor
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Copy the current selected color cell data to last unit of U_Alpha_palette_box
void OnButCopy()
{
	UINT	index = GetSelectedPaletteIndex();
	memcpy( &U_Alpha_palette_box[223], 
			&U_Alpha_palette_box[index],
			sizeof( ALPHA_COLOR_BOX ) );

	g_PAL.action = IDC_PAL_COPY;
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButCopy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Redefine the box field of U_Alpha_palette_box to save the current high light
// for swaping.
void OnButSwap()
{
	UINT	index = GetSelectedPaletteIndex();

	memcpy( &U_Alpha_palette_box[223], &U_Alpha_palette_box[index], sizeof( ALPHA_COLOR_BOX ) );
	U_Alpha_palette_box[223].box = index;

	g_PAL.action = IDC_PAL_SWAP;
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButSwap
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Find the biggest space between 2 tags and return the 2nd tag index.
// eg) | ^  ^           ^ ^   ^|, the 3rd tag index (2) will be returned.
// INPUT  : INT index - index of selected palette
// RETURN : UINT tag index
// NOTE   : All position values bigger than 1 should set to zero.
UINT GetBiggestGapTagIndex( INT index )
{
	float bigGap = 0;
	float gap = 0;
	INT	  numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;
	UINT  iTag;

	for( int i = 0; i < numTag; i++ )
	{
		gap = U_Alpha_palette_box[index].details.spread.spread_tab_position[i+1]
			- U_Alpha_palette_box[index].details.spread.spread_tab_position[i];

		if( bigGap < gap )
		{
			bigGap = gap;
			iTag = i + 1;
		}//end of if 
	}//end of for

	return( iTag );
}//end of GetBiggestGapTagIndex
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// If the last tag is not set on position 1, add the new tag to position 1.
// Otherwise, add the new tag in a biggest gap between 2 tags.
// Check the max number of tag. At least one tag exit.
// Find empty spot - find the biggest empty gap and then put the tag in the middle of gap.
// Select the base color, then render the base color on the tag and render the base color 
// on the base color box. Set the added tag as the current selected state. Sort data
void OnButAdd()
{
	INT   index  = GetSelectedPaletteIndex();
	INT	  numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;	
	BYTE  curTag = U_Alpha_palette_box[index].details.spread.current_tab_index;
	UINT  iTag   = 0;

	if( MAXIMUM_SPREAD_TABS <= numTag )
		return;

	if( U_Alpha_palette_box[index].details.spread.spread_tab_position[0] != 0 )
	{
		U_Alpha_palette_box[index].details.spread.spread_tab_position[numTag] = 0;
		U_Alpha_palette_box[index].details.spread.current_tab_index = 0;
	}
	else
		if( U_Alpha_palette_box[index].details.spread.spread_tab_position[numTag-1] != 1 )
		{
			U_Alpha_palette_box[index].details.spread.spread_tab_position[numTag] = 1;
			U_Alpha_palette_box[index].details.spread.current_tab_index = 1;
		}
		else
		{
			iTag = GetBiggestGapTagIndex( index );
			U_Alpha_palette_box[index].details.spread.spread_tab_position[numTag] 
				= ( U_Alpha_palette_box[index].details.spread.spread_tab_position[iTag]
				+   U_Alpha_palette_box[index].details.spread.spread_tab_position[iTag-1] )/(float)2.0;
			U_Alpha_palette_box[index].details.spread.current_tab_index = iTag;
		}//end of else

	U_Alpha_palette_box[index].details.spread.color[numTag] = U_Alpha_palette_box[index].details.spread.color[curTag];
	++U_Alpha_palette_box[index].details.spread.spread_tabs_total;	

	SortTag( index );
	
//	DrawTagFromData();	// do rendering
	DrawTagFromDib();
	DrawBaseColorBox();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{	
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButAdd
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Delete the current selected tag.
// Set the current selected tag position to 1.5 which is greater than 1. Then sort data. 
// After sorting the data, sel the last element (1.5) to zero for calculate gap.
// Reduce number of total tab by 1. Set the current selection to the last tag.
void OnButDel()
{
	INT	index    = GetSelectedPaletteIndex();
	INT	tagIndex = U_Alpha_palette_box[index].details.spread.current_tab_index;

	if( U_Alpha_palette_box[index].details.spread.spread_tabs_total == 1 )
		return;

	U_Alpha_palette_box[index].details.spread.spread_tab_position[tagIndex] = 1.5;
	SortTag( index );	

	U_Alpha_palette_box[index].details.spread.current_tab_index 
		= --U_Alpha_palette_box[index].details.spread.spread_tabs_total - 1;
	U_Alpha_palette_box[index].details.spread.spread_tab_position[U_Alpha_palette_box[index].details.spread.spread_tabs_total] = 0;

	DrawTagFromDib();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButDel
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Set the current selected tag to the first record. (Zero position).
// Delete all tag and clear the data structure. At least one tag left.
void OnButClear()
{
	INT		 index    = GetSelectedPaletteIndex();
	INT		 tagIndex = U_Alpha_palette_box[index].details.spread.current_tab_index;
	COLORREF tmpColor = U_Alpha_palette_box[index].details.spread.color[tagIndex];

	// ** double check the sizeof **
	ZeroMemory( &U_Alpha_palette_box[index].details.spread.color, sizeof(COLORREF)*MAXIMUM_SPREAD_TABS );
	ZeroMemory( &U_Alpha_palette_box[index].details.spread.spread_tab_position, sizeof(float)*MAXIMUM_SPREAD_TABS );

	U_Alpha_palette_box[index].details.spread.spread_tabs_total = 1;
	U_Alpha_palette_box[index].details.spread.current_tab_index = 0;
	U_Alpha_palette_box[index].details.spread.color[0] = tmpColor;
	U_Alpha_palette_box[index].details.spread.spread_tab_position[0] = 0;

	DrawTagFromDib();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );

	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButClear
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnButDup()
{
//for( int m = 0; m < 2000; m++ )
//	DrawTagFromDib();
	
	OnButAdd();
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButDup
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Displacement equal to one divided by total number of tag - 1
// Only change the tag position....
void OnButSpace()
{
	INT   index  = GetSelectedPaletteIndex();
	INT	  numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;

	if( numTag < 1 )
		return;

	float tagGap = (float)1.0/(numTag-1);

	for( int i = 0; i < (numTag-1); i++ )
		U_Alpha_palette_box[index].details.spread.spread_tab_position[i] = i * tagGap;

	// ensure last tag is one - it is not neccessary
	U_Alpha_palette_box[index].details.spread.spread_tab_position[numTag-1] = 1;

//	DrawTagFromData();	// do rendering
	DrawTagFromDib();
	DrawBaseColorBox();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButSpace
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Shift the color only and Shift to the left (toward zero element)
void OnButShift()
{
	INT		 index    = GetSelectedPaletteIndex();
	INT		 tagIndex = U_Alpha_palette_box[index].details.spread.current_tab_index;
	INT		 numTag   = U_Alpha_palette_box[index].details.spread.spread_tabs_total;
	COLORREF tmpColor = U_Alpha_palette_box[index].details.spread.color[tagIndex];

	tmpColor = U_Alpha_palette_box[index].details.spread.color[0]; //save the first color
	for( int i = 0; i < (numTag-1); i++ )
	{
		U_Alpha_palette_box[index].details.spread.color[i] 
			= U_Alpha_palette_box[index].details.spread.color[i+1];
	}//end of for

	U_Alpha_palette_box[index].details.spread.color[numTag-1] = tmpColor;

//	DrawTagFromData();	// do rendering
	DrawTagFromDib();
	DrawBaseColorBox();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{	
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButShift
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Even the 7 tags. Replace 255 (0xFF) to 192 (0xC0)
// R00(0,0,FF);RG0(00,FF,FF);0G0(0,FF,0);0GB(FF,FF,0);00B(FF,0,0);R0B(FF,0,FF);R00(0,0,FF)
void OnButHues()
{
	COLORREF	Rainbow[] = { 0x000000FF, 0x0000FFFF, 0x0000FF00, 0x00FFFF00, 0x00FF0000, 0x00FF00FF, 0x000000FF };
							//  R00         RG0         0G0         0GB         00B         R0B         R00
	float tagGap = (float)1.0/6; // 7 - 1
	INT	  index  = GetSelectedPaletteIndex();
	ZeroMemory( &U_Alpha_palette_box[index].details.spread, sizeof(COLOR_SPREAD_DETAILS) );

	U_Alpha_palette_box[index].details.spread.spread_on = 1;
	U_Alpha_palette_box[index].details.spread.spread_tabs_total = 7;
	U_Alpha_palette_box[index].details.spread.spread_angle = 270; // same color sequence as spread box

	if( BST_CHECKED == IsDlgButtonChecked(hPALPanel, IDC_PAL_SOLID) )
	{
		U_Alpha_palette_box[index].details.spread.spread_type = LINEAR_SPREAD_TYPE;
		U_Alpha_palette_box[index].details.spread.spread_on = 0; // set to 1 if force to linear

// save for reference - now, if solid is selected, all tags still show up
//		CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_LINEAR );
	}
	else
		if( BST_CHECKED == IsDlgButtonChecked(hPALPanel, IDC_PAL_LINEAR) )
			U_Alpha_palette_box[index].details.spread.spread_type = LINEAR_SPREAD_TYPE;
		else
			if( BST_CHECKED == IsDlgButtonChecked(hPALPanel, IDC_PAL_CIRCULAR) )
				U_Alpha_palette_box[index].details.spread.spread_type = CONCENTRIC_SPREAD_TYPE;
			else
				if( BST_CHECKED == IsDlgButtonChecked(hPALPanel, IDC_PAL_4POINT) )
					U_Alpha_palette_box[index].details.spread.spread_type = FOUR_PT_SPREAD_TYPE;

	for( int i = 0; i < 7; i++ )
	{
		U_Alpha_palette_box[index].details.spread.spread_tab_position[i] = i * tagGap;
		U_Alpha_palette_box[index].details.spread.color[i] = Rainbow[i];
	}//end of for

//	DrawTagFromData();	// do rendering
	DrawTagFromDib();
	DrawBaseColorBox();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButHues
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Swap the between (first + n) and (last - n), Then run sorting.
// Mirror the spread box (set 0.5 as the base line, 0.5 - tag position + 0.5)
void OnButInvert()
{
	INT	 index    = GetSelectedPaletteIndex();
	INT	 numTag   = U_Alpha_palette_box[index].details.spread.spread_tabs_total;

	for( int i = 0; i < numTag; i++ )
		U_Alpha_palette_box[index].details.spread.spread_tab_position[i] 
			= (float)1.0 - U_Alpha_palette_box[index].details.spread.spread_tab_position[i];

	SortTag( index );

//	DrawTagFromData();	// do rendering
	DrawTagFromDib();
	DrawBaseColorBox();
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButInvert
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Read a palette file and redraw the color panel.
// NOTE : A segment of code and some variables are copy from U_Alpha_load_palette_file 
//		  which may cause some unpredicted problems.
void OnButLoad()
{	
	FILE_DATA	palFRD;

//start of legacy variable
	char			s[MAX_PATH]; // drive + full directory + file_name.ext
	char			c;
	HFILE			file_handle;
	OFSTRUCT		file_structure;
	int				i, size;
	ALPHA_COLOR_BOX *box;
//end of legacy variable
	
	ZeroMemory( &palFRD, sizeof(FILE_DATA) );

	InitFileReqData( &palFRD, PALETTE );

	if( !OnFileRequest( hPALPanel, PALETTE, &palFRD ) )
		MessageBox( NULL, "File request operation fail", "Notification", MB_OK | MB_ICONINFORMATION );

	strcpy( s, U_Alpha_program_directory ); // check with JIM on File Request data
	strcat( s, "\\Util" );					// field CompleteFileName should include 
	strcat( s, palFRD.CompleteFileName );   // path name. 

	// start copy from U_Alpha_load_palette_file
	if( (file_handle = OpenFile(s, &file_structure, OF_READ) ) != HFILE_ERROR )
	{
		_lread ( file_handle, "01.00", 5 );
		size = 0;
		for ( i = 0; i < 3; i++ )
		{
			_lread ( file_handle, &c, 1 );
			if ( c >= '0' && c <= '9' )
			{
				size *= 10;
				size += ( int ) ( c - '0' );
			}
			else
				break;
		}
		_lread ( file_handle, box = &U_Alpha_palette_box[0], sizeof ( ALPHA_COLOR_BOX ) * size );
		_lclose ( file_handle );
		for ( i = 0; i < size; i++, box++ )
			if ( box->show_mode == PALETTE_MENU_SHOW_COLORS )
			{
				if ( box->details.spread.spread_on )
				{
					if ( box->details.spread.spread_tabs_total > 1 )
						box->details.spread.spread_on = 1;
					else
					{
						box->details.spread.spread_on = 0;
						box->details.spread.spread_tabs_total = 1;
						box->details.spread.spread_tab_position[0] = 0.0;
					}
				}
				else
				{
					box->details.spread.spread_tabs_total = 1;
					box->details.spread.spread_tab_position[0] = 0.0;
				}
				box->details.spread.current_tab_index = 0;
			}//end of if - for
	}//end of if
	//end of copy from U_Alpha_load_palette_file

	for( i = 0; i < 224; i++ ) // redraw the whole color panel
		RenderColorCell( GetDlgItem(hColorPanel, IDC_1+i), i );	

//  if ( message box : do you like it? == ok )
//		BackupColorBoxes();
//  else
//      undo

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButLoad
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Save the current attribute of palette in color panel to a palette file
// NOTE : Old function is used - U_Alpha_save_palette_file
void OnButSave()
{
	U_Alpha_save_palette_file( );
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButSave
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exit Palette panel and go back to the previous selected panel.
void OnButOk()
{
	UINT index = GetSelectedPaletteIndex();

	BackupColorBoxes();
	SendMessage( hToolbar, WM_COMMAND, GetLastPanel(), 0 );

	switch( GetSelectedAttrDlg() )
	{
		case IDC_ATTRIB_FACE:
		{
			// paint the selected color on the font preview sample
			ed_set_cur_attr_colorbox( &U_Alpha_palette_box[index], 1, FACE_RGB_CB_IND );
			cg_seq_paste_menu_change_to_sel_chars( PASTE_FACE_COLOR_ATTR );
			break;
		}
		case IDC_ATTRIB_SHADOW:
		{
			// paint the selected color on the font preview sample
			ed_set_cur_attr_colorbox( &U_Alpha_palette_box[index], 1, SHADOW_RGB_CB_IND );
			cg_seq_paste_menu_change_to_sel_chars( PASTE_SHADOW_COLOR_ATTR );
			break;
		}
		case IDC_ATTRIB_CAST:
		{
			// paint the selected color on the font preview sample
			ed_set_cur_attr_colorbox( &U_Alpha_palette_box[index], 1, CAST_RGB_CB_IND );
			cg_seq_paste_menu_change_to_sel_chars( PASTE_CAST_COLOR_ATTR );			
			break;
		}
		case IDC_ATTRIB_OUTLINE:
		{
			// paint the selected color on the font preview sample
			ed_set_cur_attr_colorbox( &U_Alpha_palette_box[index], 1, OUTLINE_RGB_CB_IND );
			cg_seq_paste_menu_change_to_sel_chars( PASTE_OUTLINE_COLOR_ATTR );
			break;
		}
	}//end of switch			
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButOk
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnButCancel()
{
	INT	  index  = GetSelectedPaletteIndex();
	//if object selected mode
	//		do object mode stuff
	//else
	//		do color box stuff

	RestoreColorBoxes();
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	DrawBaseColorBox();
	DrawTagFromDib();

	if( !g_PAL.modifyEvent )
	{
		for( int i = 0; i < 224; i++ ) // redraw the whole color panel
			RenderColorCell( GetDlgItem(hColorPanel, IDC_1+i), i );		
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButCancel
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Use LINEAR_SPREAD_TYPE for solid selection (0)
// MUST set spread_on to 0 here. Also, diable the rotation scroll bar.
void OnButSolid()
{
	INT	  index  = GetSelectedPaletteIndex();

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_SOLID );
	U_Alpha_palette_box[index].details.spread.spread_type = LINEAR_SPREAD_TYPE; 
	U_Alpha_palette_box[index].details.spread.spread_on = 0;
	DisableRotationScrollBar();

	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButSolid
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Use LINEAR_SPREAD_TYPE for Linear selection (0)
// MUST set spread_on to 1 here. Also, enable the rotation scroll bar.
void OnButLinear()
{
	INT	  index  = GetSelectedPaletteIndex();

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_LINEAR );
	U_Alpha_palette_box[index].details.spread.spread_type = LINEAR_SPREAD_TYPE; 
	U_Alpha_palette_box[index].details.spread.spread_on = 1;
	EnableRotationScrollBar();

	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButLinear
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Use FOUR_PT_SPREAD_TYPE for 4 point selection (2)
// MUST set spread_on to 1 here. Also, diable the rotation scroll bar.
void OnBut4Point()
{
	INT	  index  = GetSelectedPaletteIndex();

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_4POINT );
	U_Alpha_palette_box[index].details.spread.spread_type = FOUR_PT_SPREAD_TYPE;
	U_Alpha_palette_box[index].details.spread.spread_on = 1;
	DisableRotationScrollBar();

	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnBut4Point
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Use CONCENTRIC_SPREAD_TYPE for circular selection (1)
// MUST set spread_on to 1 here. Also, diable the rotation scroll bar.
void OnButCircular()
{
	INT	  index  = GetSelectedPaletteIndex();

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_SOLID, IDC_PAL_4POINT, IDC_PAL_CIRCULAR );
	U_Alpha_palette_box[index].details.spread.spread_type = CONCENTRIC_SPREAD_TYPE;
	U_Alpha_palette_box[index].details.spread.spread_on = 1;
	DisableRotationScrollBar();
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButCircular
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Convert the RGB value to HSV and then set the GUI.
// Set GUI : 1) set the horizontal scroll bar
//			 2) rename the RGB to HSV
void OnButHSV()
{
	INT			index  = GetSelectedPaletteIndex();
	BYTE		curTag = U_Alpha_palette_box[index].details.spread.current_tab_index;
	COLORREF	color  = U_Alpha_palette_box[index].details.spread.color[curTag];
	UINT		minH = 0;	// min. range of H scroll bar
	UINT		maxH = 359; // max. range of H scroll bar
	UINT		nMin = 0;	// min. range of S & V scroll bar
	UINT		nMax = 255; // max. range of S & V scroll bar

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_HSV, IDC_PAL_RGB, IDC_PAL_HSV );

	g_HPos = color  & 0x000000FF;
	g_SPos = (color & 0x0000FF00) >> 8;
	g_VPos = (color & 0x00FF0000) >> 16;

	U_Alpha_convert_color( RGB_MODE, HSV_MODE, (INT*)&g_HPos, (INT*)&g_SPos, (INT*)&g_VPos );

	SetDlgItemText( hPALPanel, IDC_TXT_R, "H" );
	SetDlgItemText( hPALPanel, IDC_TXT_G, "S" );
	SetDlgItemText( hPALPanel, IDC_TXT_B, "V" );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, minH, maxH, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, g_HPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_R, g_HPos, 1 );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, g_SPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_G, g_SPos, 1 );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, g_VPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_B, g_VPos, 1 );
	
	SetFocus( g_PAL.edit_hWnd );
}//end of OnButHSV
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnButRGB()
{
	INT			index  = GetSelectedPaletteIndex();
	BYTE		curTag = U_Alpha_palette_box[index].details.spread.current_tab_index;
	COLORREF	color  = U_Alpha_palette_box[index].details.spread.color[curTag];
	UINT		nMin = 0;	// min. range of scroll bar
	UINT		nMax = 255; // max. range of scroll bar

	if( !hPALPanel ) return;
	CheckRadioButton( hPALPanel, IDC_PAL_HSV, IDC_PAL_RGB, IDC_PAL_RGB );

	g_RPos = color & 0x000000FF;
	g_GPos = (color & 0x0000FF00) >> 8;
	g_BPos = (color & 0x00FF0000) >> 16;

	SetDlgItemText( hPALPanel, IDC_TXT_R, "R" );
	SetDlgItemText( hPALPanel, IDC_TXT_G, "G" );
	SetDlgItemText( hPALPanel, IDC_TXT_B, "B" );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, g_RPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_R, g_RPos, 1 );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, g_GPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_G, g_GPos, 1 );

	SetScrollRange( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, nMin, nMax, 1 );	
	SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, g_BPos, 1 );
	SetDlgItemInt( hPALPanel, IDC_PAL_ED_B, g_BPos, 1 );

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButRGB
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// if IDC_VDO_SAFE is check, turn on cg_edit_status.NTSC_safe_colors.
// Otherwise, turn off cg_edit_status.NTSC_safe_colors.
void OnButVdoSafe()
{
	cg_edit_status.NTSC_safe_colors 
		= (BST_CHECKED == IsDlgButtonChecked(hPALPanel,IDC_VDO_SAFE)) ? 1 : 0;

	UINT index = GetSelectedPaletteIndex();
	RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
	DrawBaseColorBox();
	if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
	{
		RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
		HighLitColorCell( hColorPanel, IDC_1+index );
	}

	SetFocus( g_PAL.edit_hWnd );
}//end of OnButVdoSafe
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
VOID OnPalColorCtrl()
{

}//end of OnPalColorCtrl
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle edit box control messages
void OnPALEditBox( HWND hDlg, WPARAM wParam )
{
	if( !hPALPanel )
		return;

	switch( LOWORD(wParam) )	// trap edit control
	{
	case IDC_PAL_ED_R:
		break;
	case IDC_PAL_ED_G:
		break;
	case IDC_PAL_ED_B:
		break;
	case IDC_PAL_ED_ROTATE:
		g_GrdPos = GetDlgItemInt( hDlg, IDC_PAL_ED_ROTATE, NULL, 1 );
		if( 359 < g_GrdPos )
		{
			g_GrdPos = 359;
			SetDlgItemText( hDlg, IDC_PAL_ED_ROTATE, "359" );
		}
		SetScrollPos( GetDlgItem(hDlg, IDC_PAL_SBAR_ROTATE), SB_CTL, g_GrdPos, 1 );

		//TO DO : DoTheWorkFunc();
		UINT	index = GetSelectedPaletteIndex();
		U_Alpha_palette_box[index].details.spread.spread_angle = g_GrdPos;
		RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );

		if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
		{
			RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
			HighLitColorCell( hColorPanel, IDC_1+index );
		}
		break;
	}//end of switch

}//end of OnTrapEditBoxMsg
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle all command button and radio button message
void OnComdButton( HWND hDlg, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{ // push button
	case IDC_PAL_COPY:
		OnButCopy();		
		break;
	case IDC_PAL_SWAP:
		OnButSwap();		
		break;
	case IDC_PAL_ADD:
		OnButAdd();
		break;
	case IDC_PAL_DEL:
		OnButDel();
		break;
	case IDC_PAL_CLEAR:
		OnButClear();					
		break;
	case IDC_PAL_DUP:
		OnButDup();
		break;
	case IDC_PAL_SPACE:
		OnButSpace();
		break;
	case IDC_PAL_SHIFT: 
		OnButShift();
		break;
	case IDC_PAL_INVERT:
		OnButInvert();
		break;
	case IDC_PAL_HUES:
		OnButHues();
		break;
	case IDC_PAL_LOAD:
		OnButLoad();
		break;
	case IDC_PAL_SAVE:
		OnButSave();
		break;
	case IDC_PAL_OK:
		OnButOk();
		break;
	case IDC_PAL_CANCEL:
		OnButCancel();
		break;
	// ---------------------------------- radio button
	case IDC_PAL_SOLID:
		OnButSolid();
		break;
	case IDC_PAL_LINEAR:
		OnButLinear();
		break;
	case IDC_PAL_4POINT:
		OnBut4Point();
		break;
	case IDC_PAL_CIRCULAR:		
		OnButCircular();
		break;
	case IDC_PAL_HSV:
		OnButHSV();
		break;
	case IDC_PAL_RGB:
		OnButRGB();
		break;
	case IDC_VDO_SAFE:
		OnButVdoSafe();
		break;
	case IDC_PAL_CUR_COLOR:
		OnPalColorCtrl();
		break;
	}//end of switch
}//end of OnComdButton
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle all messages of the horizontal scroll bar and send the thumb position.
// This version can handle 32 bits scroll range and position.
// INPUT  : HWND hCrtl - handle of the scroll bar (for more than one control)
// INPUT  : WPARAME wParam - message of scroll bar
// INPUT  : INT pos - the last record position
// RETURN : INT - position of the thumb
INT OnHThumbPos( HWND hCtrl, WPARAM wParam, HSBAR hsb )
{
	INT		iCtrlID = GetWindowLong( hCtrl, GWL_ID );
	INT		nPage = 10;
	INT		nPos = hsb.nPos;

	switch( LOWORD(wParam) )                    
	{                    
	case SB_PAGERIGHT :
		nPos = (nPos < g_hsb.nMax) ? (nPos + nPage) : g_hsb.nMax;
		break;
    case SB_LINERIGHT :
		nPos = (nPos+1 < g_hsb.nMax) ? (nPos+1) : g_hsb.nMax;
        break;
    case SB_PAGELEFT :
		nPos = (g_hsb.nMin < (nPos-nPage)) ? (nPos-nPage) : g_hsb.nMin;
		break;
    case SB_LINELEFT :
		nPos = (g_hsb.nMin < (nPos-1)) ? (nPos-1) : g_hsb.nMin;
        break;
    case SB_LEFT :
        break;
    case SB_RIGHT :
        break;
    case SB_THUMBPOSITION :
    case SB_THUMBTRACK :
		nPos = HIWORD( wParam );
        break;
    default:
         ;
	}//end of case WM_HSCROLL

	return( nPos );
}//end of OnHThumbPos
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Handle all horizontal scroll bar messages 
void OnPalHSBar( HWND hDlg, WPARAM wParam, LPARAM lParam )
{
	COLORREF	color;	
	HWND		hCtrl = (HWND)lParam;
	UINT		index = GetSelectedPaletteIndex();
	UINT		iCtrlID = GetWindowLong(hCtrl, GWL_ID);
	BYTE		curTag  = U_Alpha_palette_box[index].details.spread.current_tab_index;
	INT			hPos, sPos = 255,	vPos = 255;
	
	switch( iCtrlID )
	{
	case IDC_PAL_SBAR_R:
		{
			if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
			{
				g_hsb.nMin = 0;		// range for H value of HSV
				g_hsb.nMax = 359;				
				g_hsb.nPos = g_HPos;

				g_HPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_HPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_R, g_HPos, 0 );

				hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
				U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
				color = hPos | (vPos << 16) | (sPos << 8);
				U_Alpha_palette_box[index].details.spread.color[curTag] = color;
			}
			else
			{
				g_hsb.nMin = 0;		// range for R value of RGB
				g_hsb.nMax = 255;
				g_hsb.nPos = g_RPos;
				g_RPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_RPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_R, g_RPos, 0 );

				color = g_RPos;	
				U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFFFFFF00;
				U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
			}
	
			RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
			DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
			DrawBaseColorBox();
			DrawTagFromDib();
			if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
			{
				RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
				HighLitColorCell( hColorPanel, IDC_1+index );
			}
//			else // handle the selected font, index should be 223, the last element
//			{	 // g_PAL.modifyEvent must reduce the base value back to core's constant (FACE_RGB_CB_IND)
//				ed_set_cur_attr_colorbox( &U_Alpha_palette_box[index], 1, g_PAL.modifyEvent - MODIFY_EVENT );
//				cg_seq_paste_menu_change_to_sel_chars( g_PAL.modifyEvent - MODIFY_EVENT );
//			}
		}
		break;
	case IDC_PAL_SBAR_G:
		{
			if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
			{
				g_hsb.nMin = 0;
				g_hsb.nMax = 255;
				g_hsb.nPos = g_SPos;

				g_SPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_SPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_G, g_SPos, 0 );

				hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
				U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
				color = hPos | (vPos << 16) | (sPos << 8);
				U_Alpha_palette_box[index].details.spread.color[curTag] = color;
			}//end of if - HSV
			else
			{
				g_hsb.nMin = 0;
				g_hsb.nMax = 255;
				g_hsb.nPos = g_GPos;

				g_GPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_GPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_G, g_GPos, 0 );

				color = g_GPos << 8;
				U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFFFF00FF;
				U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
			}//end of else - RGB

			RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
			DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
			DrawBaseColorBox();
			DrawTagFromDib();
			if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
			{
				RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
				HighLitColorCell( hColorPanel, IDC_1+index );
			}
		}
		break;
	case IDC_PAL_SBAR_B:
		{
			if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
			{
				g_hsb.nMin = 0;
				g_hsb.nMax = 255;
				g_hsb.nPos = g_VPos;

				g_VPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_VPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_B, g_VPos, 0 );

				hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
				U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
				color = hPos | (vPos << 16) | (sPos << 8);
				U_Alpha_palette_box[index].details.spread.color[curTag] = color;
			}
			else
			{
				g_hsb.nMin = 0;
				g_hsb.nMax = 255;
				g_hsb.nPos = g_BPos;

				g_BPos = OnHThumbPos( hCtrl, wParam, g_hsb );
				SetScrollPos( hCtrl, SB_CTL, g_BPos, 1 );
				SetDlgItemInt( hDlg, IDC_PAL_ED_B, g_BPos, 0 );
				color = g_BPos << 16;
				U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFF00FFFF;
				U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
			}
			RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
			DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
			DrawBaseColorBox();
			DrawTagFromDib();

			if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
			{
				RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
				HighLitColorCell( hColorPanel, IDC_1+index );
			}
		}
		break;
	case IDC_PAL_SBAR_ROTATE:
		{
			g_hsb.nMin = 0;
			g_hsb.nMax = 359;
			g_hsb.nPos = g_GrdPos;
			g_GrdPos = OnHThumbPos( hCtrl, wParam, g_hsb );
			SetScrollPos( hCtrl, SB_CTL, g_GrdPos, 1 );
			SetDlgItemInt( hDlg, IDC_PAL_ED_ROTATE, g_GrdPos, 0 );

			//TO DO : DoTheWorkFunc();			
			U_Alpha_palette_box[index].details.spread.spread_angle = g_GrdPos;
			RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );

			if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
			{
				RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );			
				HighLitColorCell( hColorPanel, IDC_1+index );
			}
		}
		break;
	}//end of switch
	SetFocus( g_PAL.edit_hWnd );
}//end of OnPalHSBar
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnDrawButton( HWND hDlg, WPARAM wParam, LPARAM lParam )
{
	switch( UINT(wParam) )
	{
	case IDC_PAL_COPY:
		LoadOwnerBitmap( g_PAL.hInst, &g_odCopy,  MAKEINTRESOURCE(IDB_PAL_COPY_UP),   MAKEINTRESOURCE(IDB_PAL_COPY_DN)   );
		OnDrawItem( g_odCopy, lParam );
		DeleteOwnerBitmap( &g_odCopy );
		break;
	case IDC_PAL_SWAP:
		LoadOwnerBitmap( g_PAL.hInst, &g_odSwap,  MAKEINTRESOURCE(IDB_PAL_SWAP_UP),   MAKEINTRESOURCE(IDB_PAL_SWAP_DN)   );
		OnDrawItem( g_odSwap, lParam );
		DeleteOwnerBitmap( &g_odSwap );
		break;
	case IDC_PAL_ADD:
		LoadOwnerBitmap( g_PAL.hInst, &g_odAdd,   MAKEINTRESOURCE(IDB_PAL_ADD_UP),    MAKEINTRESOURCE(IDB_PAL_ADD_DN)    );
		OnDrawItem( g_odAdd, lParam );
		DeleteOwnerBitmap( &g_odAdd );
		break;
	case IDC_PAL_DEL:
		LoadOwnerBitmap( g_PAL.hInst, &g_odDel,   MAKEINTRESOURCE(IDB_PAL_DEL_UP),    MAKEINTRESOURCE(IDB_PAL_DEL_DN)    );
		OnDrawItem( g_odDel, lParam );
		DeleteOwnerBitmap( &g_odDel );
		break;
	case IDC_PAL_CLEAR:
		LoadOwnerBitmap( g_PAL.hInst, &g_odClear, MAKEINTRESOURCE(IDB_PAL_CLEAR_UP),  MAKEINTRESOURCE(IDB_PAL_CLEAR_DN)  );
		OnDrawItem( g_odClear, lParam );
		DeleteOwnerBitmap( &g_odClear );
		break;
	case IDC_PAL_DUP:
		LoadOwnerBitmap( g_PAL.hInst, &g_odDup,   MAKEINTRESOURCE(IDB_PAL_DUP_UP),    MAKEINTRESOURCE(IDB_PAL_DUP_DN)    );
		OnDrawItem( g_odDup, lParam );
		DeleteOwnerBitmap( &g_odDup );
		break;
	case IDC_PAL_SPACE:
		LoadOwnerBitmap( g_PAL.hInst, &g_odSpace, MAKEINTRESOURCE(IDB_PAL_SPACE_UP), MAKEINTRESOURCE(IDB_PAL_SPACE_DN) );
		OnDrawItem( g_odSpace, lParam );
		DeleteOwnerBitmap( &g_odSpace );
		break;
	case IDC_PAL_SHIFT: 
		LoadOwnerBitmap( g_PAL.hInst, &g_odShift, MAKEINTRESOURCE(IDB_PAL_SHIFT_UP), MAKEINTRESOURCE(IDB_PAL_SHIFT_DN) );
		OnDrawItem( g_odShift, lParam );
		DeleteOwnerBitmap( &g_odShift );
		break;
	case IDC_PAL_INVERT:
		LoadOwnerBitmap( g_PAL.hInst, &g_odInvert,MAKEINTRESOURCE(IDB_PAL_INVT_UP), MAKEINTRESOURCE(IDB_PAL_INVT_DN) );
		OnDrawItem( g_odInvert, lParam );
		break;
	case IDC_PAL_HUES:
		LoadOwnerBitmap( g_PAL.hInst, &g_odHues, MAKEINTRESOURCE(IDB_PAL_HUE_UP), MAKEINTRESOURCE(IDB_PAL_HUE_DN) );
		OnDrawItem( g_odHues, lParam );
		DeleteOwnerBitmap( &g_odHues );
		break;
	case IDC_PAL_LOAD:
		LoadOwnerBitmap( g_PAL.hInst, &g_odLoad, MAKEINTRESOURCE(IDB_PAL_LOAD_UP), MAKEINTRESOURCE(IDB_PAL_LOAD_DN) );
		OnDrawItem( g_odLoad, lParam );
		DeleteOwnerBitmap( &g_odLoad );
		break;
	case IDC_PAL_SAVE:
		LoadOwnerBitmap( g_PAL.hInst, &g_odSave, MAKEINTRESOURCE(IDB_PAL_SAVE_UP), MAKEINTRESOURCE(IDB_PAL_SAVE_DN) );
		OnDrawItem( g_odSave, lParam );
		DeleteOwnerBitmap( &g_odSave );
		break;
	case IDC_PAL_OK:
		LoadOwnerBitmap( g_PAL.hInst, &g_odOk, MAKEINTRESOURCE(IDB_PAL_OK_UP), MAKEINTRESOURCE(IDB_PAL_OK_DN) );
		OnDrawItem( g_odOk, lParam );
		DeleteOwnerBitmap( &g_odOk );
		break;
	case IDC_PAL_CANCEL:
		LoadOwnerBitmap( g_PAL.hInst, &g_odCancel,MAKEINTRESOURCE(IDB_PAL_CANCEL_UP), MAKEINTRESOURCE(IDB_PAL_CANCEL_DN) );
		OnDrawItem( g_odCancel, lParam );
		DeleteOwnerBitmap( &g_odCancel );
		break;	
	}//end of switch - wParam
}//end of OnDrawButton
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Red edit subclass callback
LRESULT APIENTRY R_EditSubProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{ 
	COLORREF	color;	
	UINT		index = GetSelectedPaletteIndex();
	BYTE		curTag  = U_Alpha_palette_box[index].details.spread.current_tab_index;
	UINT		hPos, sPos = 255,	vPos = 255;

	switch( uMsg )
	{
	case WM_KEYDOWN:
		{
			switch( wParam )
			{
			case VK_RETURN:
				{							
					if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
					{
						g_HPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_R, NULL, 1 );
						SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, g_HPos, 1 );

						hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
						U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
						color = hPos | (vPos << 16) | (sPos << 8);
						U_Alpha_palette_box[index].details.spread.color[curTag] = color;
					}//end of if - HSV
					else
					{
						g_RPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_R, NULL, 1 );
						SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_R), SB_CTL, g_RPos, 1 );

						color = g_RPos;	
						U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFFFFFF00;
						U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
					}//end of else - RGB
					//TO DO : DoTheWorkFunc();
					RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
					DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
					DrawBaseColorBox();		
					if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
					{
						RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
						HighLitColorCell( hColorPanel, IDC_1+index );
					}					
				}
				SetFocus( g_PAL.edit_hWnd );
				break;
			case VK_TAB:
				SetFocus( GetDlgItem( g_PAL.hWnd, IDC_PAL_ED_G ) );
				break;
			}//end of switch - wParam
		}
	}//end of switch - uMsg

	//TO DO : DoTheWorkFunc();

    return CallWindowProc( (FARPROC)R_oldEdProc, hWnd, uMsg, wParam, lParam ); 	
}//end of R_EditSubProc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Green edit subclass callback
LRESULT APIENTRY G_EditSubProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{ 
	COLORREF	color;	
	UINT		index = GetSelectedPaletteIndex();
	BYTE		curTag  = U_Alpha_palette_box[index].details.spread.current_tab_index;
	UINT		hPos, sPos = 255,	vPos = 255;
	
	switch( uMsg )
	{
		case WM_KEYDOWN:
		{
			switch( wParam )
			{
				case VK_RETURN:
				{							
					if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
					{
						g_SPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_G, NULL, 1 );
						SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, g_SPos, 1 );

						hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
						U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
						color = hPos | (vPos << 16) | (sPos << 8);
						U_Alpha_palette_box[index].details.spread.color[curTag] = color;
					}//end of if - HSV
					else
					{
						g_GPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_G, NULL, 1 );
						SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_G), SB_CTL, g_GPos, 1 );

						color = g_GPos << 8;
						U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFFFF00FF;
						U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
					}//end of if - RGB

					//TO DO : DoTheWorkFunc();
					RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
					DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
					DrawBaseColorBox();
					if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
					{
						RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
						HighLitColorCell( hColorPanel, IDC_1+index );
					}
				}
				SetFocus( g_PAL.edit_hWnd );			
				break;		
			case VK_TAB:				
				SetFocus( GetDlgItem( g_PAL.hWnd, IDC_PAL_ED_B ) );			
				break;			
			}//end of switch - wParam		
		}//end of swithc
	}//end of switch - uMsg

	//TO DO : DoTheWorkFunc();

    return CallWindowProc( (FARPROC)G_oldEdProc, hWnd, uMsg, wParam, lParam ); 	
}//end of G_EditSubProc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Blue edit subclass callback
LRESULT APIENTRY B_EditSubProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{ 
	COLORREF	color;	
	UINT		index = GetSelectedPaletteIndex();
	BYTE		curTag  = U_Alpha_palette_box[index].details.spread.current_tab_index;
	UINT		hPos, sPos = 255,	vPos = 255;

	switch( uMsg )
	{
	case WM_KEYDOWN:
		{
			switch( wParam )
			{
			case VK_RETURN:						
				if( BST_CHECKED == IsDlgButtonChecked( hPALPanel, IDC_PAL_HSV ) )
				{
					g_VPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_B, NULL, 1 );
					SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, g_VPos, 1 );

					hPos = g_HPos; sPos = g_SPos; vPos = g_VPos;
					U_Alpha_convert_color( HSV_MODE, RGB_MODE, (INT*)&hPos, (INT*)&sPos, (INT*)&vPos );
					color = hPos | (vPos << 16) | (sPos << 8);
					U_Alpha_palette_box[index].details.spread.color[curTag] = color;
				}//end of if - HSV
				else
				{
					g_BPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_B, NULL, 1 );
					SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_B), SB_CTL, g_BPos, 1 );

					color = g_BPos << 16;
					U_Alpha_palette_box[index].details.spread.color[curTag] &= 0xFF00FFFF;
					U_Alpha_palette_box[index].details.spread.color[curTag] |= color;
				}//end of else - RGB

				//TO DO : DoTheWorkFunc();
				RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
				DrawSpreadColorBox( GetDlgItem(hPALPanel,IDC_SPREAD_COLOR), index );
				DrawBaseColorBox();
				if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
				{
					RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
					HighLitColorCell( hColorPanel, IDC_1+index );
				}
				SetFocus( g_PAL.edit_hWnd );
				break;
			case VK_TAB:
				SetFocus( GetDlgItem( g_PAL.hWnd, IDC_PAL_ED_R ) );
				break;
			}//end of switch - wParam
		}
	}//end of switch - uMsg

	//TO DO : DoTheWorkFunc();

    return CallWindowProc( (FARPROC)B_oldEdProc, hWnd, uMsg, wParam, lParam ); 	
}//end of R_EditSubProc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Rotation radient edit subclass callback
LRESULT APIENTRY Grd_EditSubProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{ 
	UINT	index = GetSelectedPaletteIndex();
	switch( uMsg )
	{
	case WM_KEYDOWN:
		{
			switch( wParam )
			{
			case VK_RETURN:	
				g_GrdPos = GetDlgItemInt( hPALPanel, IDC_PAL_ED_ROTATE, NULL, 1 );
				if( 359 < g_GrdPos )
				{
					g_GrdPos = 359;
					SetDlgItemText( hPALPanel, IDC_PAL_ED_ROTATE, "359" );
				}
				SetScrollPos( GetDlgItem(hPALPanel, IDC_PAL_SBAR_ROTATE), SB_CTL, g_GrdPos, 1 );

				//TO DO : DoTheWorkFunc();				
				U_Alpha_palette_box[index].details.spread.spread_angle = g_GrdPos;
				RenderColorCell( GetDlgItem(hPALPanel,IDC_PAL_CUR_COLOR), index );
				if( !g_PAL.modifyEvent ) // render the palette in color panel when color change
				{
					RenderColorCell( GetDlgItem(hColorPanel,IDC_1+index), index );
					HighLitColorCell( hColorPanel, IDC_1+index );
				}
				SetFocus( g_PAL.edit_hWnd );
				break;
			case VK_TAB:
				SetFocus( GetDlgItem( g_PAL.hWnd, IDC_PAL_ED_R ) );
				break;
			}//end of switch - wParam
		}
	}//end of switch - uMsg

	//TO DO : DoTheWorkFunc();

    return CallWindowProc( (FARPROC)Grd_oldEdProc, hWnd, uMsg, wParam, lParam ); 	
}//end of R_EditSubProc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CreatePalEditCtrlSubClass( HWND hDlg )
{
	HWND	hEdit;	

	hEdit = ::GetDlgItem( hDlg, IDC_PAL_ED_R ); // Subclass of red edit control
	R_oldEdProc = (WNDPROC)SetWindowLong( hEdit, GWL_WNDPROC, (LONG)R_EditSubProc );

	hEdit = GetDlgItem( hDlg, IDC_PAL_ED_G ); // Subclass of red edit control
	G_oldEdProc = (WNDPROC)SetWindowLong( hEdit, GWL_WNDPROC, (LONG)G_EditSubProc );

	hEdit = GetDlgItem( hDlg, IDC_PAL_ED_B ); // Subclass of red edit control
	B_oldEdProc = (WNDPROC)SetWindowLong( hEdit, GWL_WNDPROC, (LONG)B_EditSubProc );

	hEdit = GetDlgItem( hDlg, IDC_PAL_ED_ROTATE ); // Subclass of red edit control
	Grd_oldEdProc = (WNDPROC)SetWindowLong( hEdit, GWL_WNDPROC, (LONG)Grd_EditSubProc );

}//end of CreatePalEditCtrlSubClass
//+++++++++++++++++++++++++++++++++++++++++++++++++++++ CreatePalPanel()
// INPUT : HWND ParentHwnd - The big window ??
// INPUT : HINSTANCE - ?????
HWND CreatePalPanel(HINSTANCE HInst, HWND ParentHwnd, HWND Edit_hWnd)
{
	int x = 0;

	WndClassPALColorCtrl();		// MUST set the custom control 
	WndClassPALBaseColor();		// before creating the dialog
	WndClassPALSliderCtrl();
	WndClassPALSpraedBox();

	g_PAL.hInst		 = HInst;
	g_PAL.parenthWnd = ParentHwnd;
	g_PAL.edit_hWnd	 = Edit_hWnd;
	g_PAL.action	 = 0;

    g_PAL.hWnd = ::CreateDialog(HInst,      // Application instance handle
								MAKEINTRESOURCE( IDD_PAL ),
								ParentHwnd, // Parent window handle
								(DLGPROC)(PalPanelProc) );
	if (g_PAL.hWnd == NULL)
		return NULL;

	SetPALPanelPosition();
//	CreatePalPanelTooltip( g_PAL.hWnd );
	CreatePalEditCtrlSubClass( g_PAL.hWnd );

	return g_PAL.hWnd;
}//end of CreatePalPanel()
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Only six control need to change the font, therefore, hard code is easier.
VOID InitPALPanelControlFont( HWND hDlg )
{
	HWND hFont = NULL;
	HWND hCtrl = GetDlgItem( hDlg, IDC_GB_PAL );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_BG_CUR_COLOR );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_GB_BASE_COLOR );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_GB_INDICATOR );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_GB_ROTATE );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_PAL_SOLID );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_PAL_LINEAR );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_PAL_CIRCULAR );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_PAL_4POINT );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);

	hCtrl = GetDlgItem( hDlg, IDC_VDO_SAFE );
	ChangeControlFont( hCtrl, hFont, UILang_UIFont,0, UILang_UIFontSize, FW_NORMAL);
}//end of InitPALPanelControlFont
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Initialize all controls and GUI on the Text Panel
// 1) Read initial vales - NOT implement yet
// 2) Initialize all owner draw buttons
void OnInitPalPanelDialog( HWND hDlg )
{					
	InitPALPanelControlFont( hDlg );

	SetPALRadioButton( GetSelectedPaletteIndex() );
	InitCurColor( hDlg ); // empty
	InitBaseColor( hDlg );
	InitPalPanelTooltip();
	InitPalPanelStaticText( hDlg );
	BackupColorBoxes();
}//end of OnInitDialog

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OnDestroyPalPanel()
{
	BOOL rv;
	if( g_PAL.hToolTipFont != NULL )
	{
		rv = DestroyWindow( g_PAL.hToolTipFont );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_PAL.hToolTipFont, error code", GetLastError(), DF);
	}
	if( g_PAL.hHook != NULL )
	{
		UnhookWindowsHookEx( g_PAL.hHook );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_PAL.hHook, error code", GetLastError(), DF );
	}
	if( g_PAL.hToolTip != NULL )
	{
		rv = DestroyWindow( g_PAL.hToolTip );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_PAL.hToolTip, error code", GetLastError(), DF );
		g_PAL.hToolTip = NULL;

		if( g_ttData != NULL )
		{
			free( g_ttData );
			g_ttData = NULL;
		}
	}
	if( g_odCopy.hButtonBitmap != NULL )
	{
		rv = DeleteObject( g_odCopy.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odCopy.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odSwap.hButtonBitmap != NULL )
	{
		rv = DeleteObject( g_odSwap.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSwap.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odSwap.hButtonDown != NULL )
	{	rv = DeleteObject( g_odSwap.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSwap.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odAdd.hButtonBitmap != NULL )
	{	rv = DeleteObject( g_odAdd.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odAdd.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odAdd.hButtonDown != NULL )
	{	rv = DeleteObject( g_odAdd.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odAdd.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odDel.hButtonBitmap != NULL )
	{	rv = DeleteObject( g_odDel.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odDel.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odDel.hButtonDown != NULL )
	{	rv = DeleteObject( g_odDel.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odDel.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odClear.hButtonBitmap != NULL )
	{	rv = DeleteObject( g_odClear.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odClear.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odClear.hButtonDown != NULL )
	{	rv = DeleteObject( g_odClear.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odClear.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odDup.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odDup.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odDup.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odDup.hButtonDown != NULL )
	{	rv = DeleteObject( g_odDup.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odDup.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odSpace.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odSpace.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSpace.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odSpace.hButtonDown != NULL )
	{	rv = DeleteObject( g_odSpace.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSpace.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odShift.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odShift.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odShift.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odShift.hButtonDown != NULL )
	{	rv = DeleteObject( g_odShift.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odShift.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odInvert.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odInvert.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odInvert.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odInvert.hButtonDown != NULL )
	{	rv = DeleteObject( g_odInvert.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odInvert.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odHues.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odHues.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odHues.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odHues.hButtonDown != NULL )
	{	rv = DeleteObject( g_odHues.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odHues.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odLoad.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odLoad.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odLoad.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odLoad.hButtonDown != NULL )
	{	rv = DeleteObject( g_odLoad.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odLoad.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odSave.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odSave.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSave.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odSave.hButtonDown != NULL )
	{	rv = DeleteObject( g_odSave.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odSave.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odOk.hButtonBitmap != NULL )	
	{	rv = DeleteObject( g_odOk.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odOk.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odOk.hButtonDown != NULL )
	{	rv = DeleteObject( g_odOk.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odOk.hButtonDown, error code", GetLastError(), DF );
	}
	if( g_odCancel.hButtonBitmap != NULL )
	{	
		rv = DeleteObject( g_odCancel.hButtonBitmap );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odCopy.hButtonBitmap, error code", GetLastError(), DF );
	}
	if( g_odCancel.hButtonDown != NULL )
	{
		rv = DeleteObject( g_odCancel.hButtonDown );
		if( !rv )//error
			Kdebug("PALPanel.cpp : Fail destroy g_odCopy.hButtonDown, error code", GetLastError(), DF );
	}	
}//end of OnDestroyPalPanel

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BOOL CALLBACK PalPanelProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	int			i = 0;
	
	switch( uMsg )
	{
	case WM_INITDIALOG:
		{			
			OnInitPalPanelDialog( hDlg );			
		}//WM_INITDIALOG
		return( 1 );
	case WM_COMMAND:
		{
			OnComdButton( hDlg, wParam );
		}
		break;
	case WM_PAINT:
		{
			SetPALModifyFlag();
			SetPALRadioButton( GetSelectedPaletteIndex() );
//			InitCurColor( hDlg ); // empty
//			InitBaseColor( hDlg );
		}
		break;
	case WM_HSCROLL:
		{
			OnPalHSBar( hDlg, wParam, lParam );
		}
		break;
	case WM_DRAWITEM:
		{
			OnDrawButton( hDlg, wParam, lParam );			
		}
		break;
	case WM_NOTIFY:
		OnPalNotify( lParam );
		break;

	case WM_DESTROY:
		OnDestroyPalPanel();
		break;
	default:
			break;

	}//end of switch - uMsg

	return FALSE;
}//end of CALLBACK PALPanelDlgProc


///////////////////////////////////////////////////////////////////////////////
// T O O L    T I P S    F O R     T E X T       P A N E L
///////////////////////////////////////////////////////////////////////////////
// Due ot the legacy issue - cannot locate the main window message loop.
// Redo the tool tips section after locate the main window message loop
// so that all tool tip message will pass to the main window.
//
// CreateTextPanelTooltip - creates a ToolTip control for a dialog box, 
//     enumerates the child control windows, and installs a hook 
//     procedure to monitor the message stream for mouse messages posted 
//     to the control windows. 
//
// INPUT  : HWND DlgHwnd - handle of the tooltip dialog
// RETURN : 1 if successful or 0 otherwise. 
BOOL CreatePalPanelTooltip(HWND DlgHwnd)
{
    // Ensure that the common control DLL is loaded, and create a ToolTip control.
    InitCommonControls();
    g_PAL.hToolTip = CreateWindowEx( 0,
									TOOLTIPS_CLASS,
									(LPSTR) NULL, 
									TTS_ALWAYSTIP,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									CW_USEDEFAULT, 
									CW_USEDEFAULT,
									DlgHwnd,
									(HMENU)NULL,
									g_PAL.hInst,
									NULL);
 
    if( g_PAL.hToolTip == NULL )
        return( 0 );

    // Enumerate the child windows to register them with the ToolTip control.
    if( !EnumChildWindows(DlgHwnd, (WNDENUMPROC)EnumPalChildProc, 0) ) 
        return( 0 );
 
    // Install a hook procedure to monitor the message stream for mouse 
    // messages intended for the controls in the dialog box. 
    g_PAL.hHook = SetWindowsHookEx(
								WH_GETMESSAGE,
								(HOOKPROC)GetPalMsgProc, 
								(HINSTANCE)NULL,
								GetCurrentThreadId()); 
 
    if( g_PAL.hHook == (HHOOK)NULL )
        return( 0 ); 
 
    return( 1 ); 
}//end of CreateAttribPanelTooltip(HWND DlgHwnd)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// EmumChildProc - registers control windows with a ToolTip control by
// using the TTM_ADDTOOL message to pass the address of a TOOLINFO structure.
//
// INPUT  : HWND hwndCtrl - handle of a control window
// INPUT  : LPARAM lParam application-defined value (not used)
// RETURN : 1 if successful or 0 otherwise.
BOOL EnumPalChildProc(HWND hwndCtrl, LPARAM lParam) 
{ 
    TOOLINFO ti; 
	char szClass[64];

	// skip static control
	GetClassName(hwndCtrl, szClass, sizeof(szClass)); 
	if( lstrcmpi(szClass, "STATIC") )
	{
		ti.cbSize   = sizeof(TOOLINFO);
		ti.uFlags   = TTF_IDISHWND;
		ti.hwnd     = g_PAL.hWnd;
		ti.uId      = (UINT) hwndCtrl;
		ti.hinst    = 0;
		ti.lpszText = LPSTR_TEXTCALLBACK;

		SendMessage( g_PAL.hToolTip, TTM_ADDTOOL, 0, (LPARAM)(LPTOOLINFO)&ti );
	}
    return( 1 );
}//end of EnumPalChildProc

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// GetPalMsgProc - monitors the message stream for mouse messages intended
//     for a control window in the dialog box.
//
// INPUT  : int nCode - hook code
// INPUT  : WPARAM wParam - message flag (not used)
// INPUT  : LPARAM lParam - address of an MSG structure
// RETURN : a message-dependent value.
LRESULT CALLBACK GetPalMsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{ 
    MSG *lpmsg;

    lpmsg = (MSG *)lParam;
    if( nCode < 0 || !(IsChild(g_PAL.hWnd, lpmsg->hwnd)) )
        return( CallNextHookEx(g_PAL.hHook, nCode, wParam, lParam) );

    switch( lpmsg->message )
	{
        case WM_MOUSEMOVE:
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP:
            if (g_PAL.hToolTip != NULL)
			{
                MSG msg;
                msg.lParam  = lpmsg->lParam;
                msg.wParam  = lpmsg->wParam;
                msg.message = lpmsg->message;
                msg.hwnd    = lpmsg->hwnd;
                SendMessage( g_PAL.hToolTip, TTM_RELAYEVENT, 0, (LPARAM)(LPMSG)&msg	);//end SendMessage
            }
            break;

        default:
            break;
    }//end of switch( lpmsg->message )

    return (CallNextHookEx(g_PAL.hHook, nCode, wParam, lParam));
}//end of GetPalMsgProc()

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// OnPalNotify - provides the ToolTip control with the appropriate text 
// to display for a control window. This function is called by 
//     the dialog box procedure in response to a WM_NOTIFY message. 
// INPUT : LPARAM lParam - second message parameter of the WM_NOTIFY message 
void OnPalNotify(LPARAM lParam)
{ 
    LPTOOLTIPTEXT lpttt;
    int idCtrl;
 
    if( (((LPNMHDR) lParam)->code) == TTN_NEEDTEXT )
	{
        idCtrl = GetDlgCtrlID((HWND)((LPNMHDR) lParam)->idFrom);
        lpttt = (LPTOOLTIPTEXT) lParam;
		lpttt->hinst = g_PAL.hInst;  

        switch( idCtrl )
		{
			case IDC_PAL_COPY:
				if( NULL != GetPalPanelTooltip(IDC_PAL_COPY) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_COPY) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_COPY);
				break;
			case IDC_PAL_SWAP:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SWAP) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SWAP) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_SWAP);
				break;
			case IDC_PAL_ADD:
				if( NULL != GetPalPanelTooltip(IDC_PAL_ADD) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_ADD) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_ADD);
				break;
			case IDC_PAL_DEL:
				if( NULL != GetPalPanelTooltip(IDC_PAL_DEL) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_DEL) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_DEL);
				break;
			case IDC_PAL_CLEAR:
				if( NULL != GetPalPanelTooltip(IDC_PAL_CLEAR) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_CLEAR) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_CLEAR);
				break;
			case IDC_PAL_DUP:
				if( NULL != GetPalPanelTooltip(IDC_PAL_DUP) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_DUP) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_DUP);
				break;
			case IDC_PAL_SPACE:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SPACE) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SPACE) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_SPACE);
				break;
			case IDC_PAL_SHIFT: 
				if( NULL != GetPalPanelTooltip(IDC_PAL_SHIFT) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SHIFT) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_SHIFT);
				break;
			case IDC_PAL_INVERT:
				if( NULL != GetPalPanelTooltip(IDC_PAL_INVERT) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_INVERT) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_INVERT);
				break;
			case IDC_PAL_HUES:
				if( NULL != GetPalPanelTooltip(IDC_PAL_HUES) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_HUES) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_HUES);
				break;
			case IDC_PAL_LOAD:
				if( NULL != GetPalPanelTooltip(IDC_PAL_LOAD) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_LOAD) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_LOAD);
				break;
			case IDC_PAL_SAVE:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SAVE) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SAVE) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_SAVE);
				break;
			case IDC_PAL_OK:
				if( NULL != GetPalPanelTooltip(IDC_PAL_OK) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_OK) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_OK);
				break;
			case IDC_PAL_CANCEL:
				if( NULL != GetPalPanelTooltip(IDC_PAL_CANCEL) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_CANCEL) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_CANCEL);
				break;
			// radio button
			case IDC_PAL_SOLID:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SOLID) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SOLID) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_SOLID);
				break;
			case IDC_PAL_LINEAR:
				if( NULL != GetPalPanelTooltip(IDC_PAL_LINEAR) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_LINEAR) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_LINEAR);
				break;
			case IDC_PAL_4POINT:
				if( NULL != GetPalPanelTooltip(IDC_PAL_4POINT) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_4POINT) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_4POINT);
				break;
			case IDC_PAL_CIRCULAR:
				if( NULL != GetPalPanelTooltip(IDC_PAL_CIRCULAR) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_CIRCULAR) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_CIRCULAR);
				break;
			case IDC_PAL_HSV:
				if( NULL != GetPalPanelTooltip(IDC_PAL_HSV) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_HSV) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_HSV);
				break;
			case IDC_PAL_RGB:
				if( NULL != GetPalPanelTooltip(IDC_PAL_RGB) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_RGB) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_RGB);
				break;
			case IDC_VDO_SAFE:
				if( NULL != GetPalPanelTooltip(IDC_VDO_SAFE) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_VDO_SAFE) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_VDO_SAFE);
				break;
			case IDC_PAL_SBAR_R:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SBAR_R) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SBAR_R) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_R_HSB);
				break;
			case IDC_PAL_SBAR_G:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SBAR_G) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SBAR_G) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_G_HSB);
				break;
			case IDC_PAL_SBAR_B:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SBAR_B) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SBAR_B) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_B_HSB);
				break;
			case IDC_PAL_SBAR_ROTATE:
				if( NULL != GetPalPanelTooltip(IDC_PAL_SBAR_ROTATE) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_SBAR_ROTATE) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_GRD_HSB);
				break;
			case IDC_PAL_ED_R:
				if( NULL != GetPalPanelTooltip(IDC_PAL_ED_R) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_ED_R) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_ED_R);
				break;
			case IDC_PAL_ED_G:
				if( NULL != GetPalPanelTooltip(IDC_PAL_ED_G) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_ED_G) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_ED_G);
				break;
			case IDC_PAL_ED_B:
				if( NULL != GetPalPanelTooltip(IDC_PAL_ED_B) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_ED_B) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_ED_B);
				break;
			case IDC_PAL_ED_ROTATE:
				if( NULL != GetPalPanelTooltip(IDC_PAL_ED_ROTATE) )
					_mbscpy( (UCHAR*)lpttt->lpszText, GetPalPanelTooltip(IDC_PAL_ED_ROTATE) );
				else
					lpttt->lpszText = MAKEINTRESOURCE(IDS_PAL_ED_GRD);
				break;
        }//end of switch - idCtrl
    }
	return;
}//end of OnPalNotify
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Directly assign a 32 bits pixel info in format of 0xaArRgGbB which is different
// to MS's COLORREF (0x00bbggrr).
// INPUT : int X - x coordinate
// INPUT : int Y - y coordinate
// INPUT : int w - horizontal length or ending point of x
// INPUT : int h - verticle length or ending point of y
// INPUT : DWORD Color32 - 32 bits pixel (Different to COLORREF)
VOID PalDibSetPixel(int X,int Y, int w, int h, DWORD Color32 )
{
	//Clip pixel to valid bitmap addressing
	if( (X < 0) || (w <= X) )
		return;

	if( (Y < 0) || (h <= Y) )
		return;

	//calc DWORD offset of pixel (byte address would be DWORD offset * 4L
	DWORD DwordAddrOffset = ( Y * w ) + X;
	*(PalDibSectionPtr + DwordAddrOffset) = Color32;
}//end of PalDibSetPixel
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Draw a triangle tag
// INPUT : int xPos - x position of tag (corresponding to x mouse position)
// INPUT : int height - height of tag (the selected tag is 3 pixels higher)
// INPUT : COLORREF Color32 - 32 bits pixel 0x00bbggrr
void PalDibDrawTriangle(int xPos, int height, COLORREF Color32)
{
	DWORD	color32 = ConvertToARGB( Color32 );
	for( int x = 0; x < 5; x++ )
		for( int y = 0; y < height-(2*x); y++ )
		{
			PalDibSetPixel(xPos-x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, color32);
			PalDibSetPixel(xPos+x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, color32);
		}
}//end of PalDibDrawTriangle
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Draw a selected triangle tag with 2 black pixels higher than other tags.
// INPUT : int xPos - x position of tag (corresponding to x mouse position)
// INPUT : int height - height of tag (the selected tag is 3 pixels higher)
// INPUT : COLORREF Color32 - 32 bits pixel 0x00bbggrr
void PalDibDrawSelectedTriangle(int xPos, int height, COLORREF Color32)
{
	int x, y;
	DWORD	color32 = ConvertToARGB( Color32 );
	for( x = 0; x < 5; x++ )
		for( y = 0; y < height-(2*x); y++ )
		{			
//save			if( y == 0 )
//save			{
//save				PalDibSetPixel(xPos-x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, 0x0);
//save				PalDibSetPixel(xPos+x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, 0x0);
//save			}
//save			else
//save			{
				PalDibSetPixel(xPos-x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, color32);
				PalDibSetPixel(xPos+x, (2*x)+y, g_PalDibWidth, g_PalDibHeight, color32);
//save			}
		}

	for( x = 0; x < 5; x++ )
	{
		PalDibSetPixel(xPos-x, height,   g_PalDibWidth, g_PalDibHeight, 0x0);
		PalDibSetPixel(xPos-x, height-1, g_PalDibWidth, g_PalDibHeight, 0x0);
		PalDibSetPixel(xPos+x, height,   g_PalDibWidth, g_PalDibHeight, 0x0);
		PalDibSetPixel(xPos+x, height-1, g_PalDibWidth, g_PalDibHeight, 0x0);
	}
}//end of PalDibDrawSelectedTriangle

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Fill a solid color rectangle region 
// INPUT : INT w - width  of the rectangle
// INPUT : INT h - height of the rectangle
// INPUT : COLORREF Color32 - 32 bits pixel 
void PalDibFillRect( INT w, INT h, COLORREF Color32)
{
	DWORD	color32 = ConvertToARGB( Color32 );
	for( int y = 0; y < h; y++ )
		for( int x = 0; x < w; x++ )
			PalDibSetPixel(x, y, w, h, color32 );
}// end of PalDibFillRect

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Draw all triangle tags to the Dib section and bitblt to the screen.
VOID DrawTagFromDib()
{
	float		n;
	HDC			hDC;
	HDC			hMemDC;
	HBITMAP		hBmp;
	HBITMAP		hOldBmp;
//	HBRUSH		hBrush[MAXIMUM_SPREAD_TABS];
//	HBRUSH		hOldBrush;
	RECT		rcSlider;
	UINT		index;
	UINT		numTag;
	HWND		hSlider = GetDlgItem( hPALPanel, IDC_SLIDER_CTRL );
	UINT		rv;
	INT			dX = TAG_HALF_WIDTH;
	INT			dY = TAG_HEIGHT;
	UINT			i;
	COLORREF	color32;

	GetWindowRect( hSlider, &rcSlider );
	g_PalDibWidth  = rcSlider.right - rcSlider.left;
	g_PalDibHeight = rcSlider.bottom - rcSlider.top;

	g_SpreadWidth = g_PalDibWidth - 1; // for scaling and mouse position convertion

	BITMAPINFOHEADER		bmpHeader;

	bmpHeader.biSize        = sizeof( BITMAPINFOHEADER );
	bmpHeader.biWidth       = g_PalDibWidth;
	bmpHeader.biHeight      = -g_PalDibHeight;
	bmpHeader.biPlanes      = 1;
	bmpHeader.biBitCount    = 32;
	bmpHeader.biCompression = BI_RGB;
	bmpHeader.biSizeImage   = g_PalDibWidth * g_PalDibHeight * sizeof(DWORD);

	hDC		= GetDC( hSlider );
	hMemDC	= CreateCompatibleDC( hDC );
	hBmp    = CreateDIBSection( hMemDC,
								(BITMAPINFO *)&(bmpHeader),
								DIB_RGB_COLORS,
								(void **)&(PalDibSectionPtr),
								NULL, 0 );
	if( hBmp == NULL )
	{
		#if _DEBUG
		_ASSERT(0);
		MessageBox( NULL, "System Unstable", "Warning", MB_OK|MB_ICONWARNING );
		//exit( 1 );
		#endif
	}

	hOldBmp = SelectObject( hMemDC, hBmp );
	PalDibFillRect( g_PalDibWidth, g_PalDibHeight, GetSysColor(COLOR_BTNFACE) );

	index  = GetSelectedPaletteIndex();
	numTag = U_Alpha_palette_box[index].details.spread.spread_tabs_total;

	for( i = 0; i < numTag; i++ )
	{	
		n = g_SpreadWidth * U_Alpha_palette_box[index].details.spread.spread_tab_position[i];
		color32 = U_Alpha_palette_box[index].details.spread.color[i];
		if( i == U_Alpha_palette_box[index].details.spread.current_tab_index ) 
		{
			dY += 3; // set tag height
			PalDibDrawSelectedTriangle( (int)n, dY, color32 );
		}
		else	
			PalDibDrawTriangle( (int)n, dY, color32 );		

		if( i == U_Alpha_palette_box[index].details.spread.current_tab_index ) 
			dY -= 3; // restore normal tag boundary color and tag heigh
	}//end of for

	rv = BitBlt( hDC, 0, 0, bmpHeader.biWidth, rcSlider.bottom - rcSlider.top, hMemDC, 0, 0, SRCCOPY );

	SelectObject( hMemDC, hOldBmp ); 
	DeleteObject( hBmp );

	ReleaseDC( hSlider, hDC );
	DeleteDC( hMemDC );
}//end of DrawTagFromDib
