#ifndef _PAL_PANEL_H
#define _PAL_PANEL_H


#include <windows.h>
#include <windowsx.h>

#define PAL_Y_POSITION		0 // fixed
#define PAL_PANEL_WIDTH		159
#define PAL_PANEL_HEIGHT	725


HWND CreatePalPanel(HINSTANCE HInst, HWND ParentHwnd, HWND);

BOOL CALLBACK PalPanelProc(	HWND	hDlg,
							UINT	uMsg,
							WPARAM	wParam,
							LPARAM	lParam );

BOOL	CreatePalPanelTooltip(HWND DlgHwnd);
BOOL	EnumPalChildProc(HWND hwndCtrl, LPARAM lParam);
LRESULT CALLBACK GetPalMsgProc(int nCode, WPARAM wParam, LPARAM lParam);
UINT	GetPALAction();
VOID	BackupColorBoxes();
VOID	DrawBaseColorBox();
VOID	DrawTagFromData();
VOID	DrawTagFromDib();
VOID	OnPalNotify(LPARAM lParam);
VOID	SetPALAction( UINT action );
VOID	SetPALRadioButton( UINT index );
VOID	InitPALHScrollBar( UINT index );
BOOL	IsPALModifyEvent();
VOID	SetPALPanelPosition();
#endif // _PAL_PANEL_H