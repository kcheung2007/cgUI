//CGServerDll.h

/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/

#ifndef _CGSERVERDLL_H
#define _CGSERVERDLL_H

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <process.h>
#include <dos.h>
#include <memory.h>
#include <math.h>

#include "acg_opts.h"


//#include "KeyHelp.h"
#include "CGS_ValDefs.h"

#include "CG_ColorBox.h"
#include "CG_GfxBuf.h"
#include "CG_TitleWaveDefs.h"
#include "CG_AttrFlags.h" //paste attribute bit flags

#include "UI_BinMgrContextFlags.h"
#include "CG_PictureLoadOptionsInfo.h"
#include "FileReq_InfoStruct.h"


//------------------------------------------------------------------------------
//For non MS Windows versions:
#define CGS_FUNC 

//For MS Windows versions:
#if _WINDOWS
	
	#undef CGS_FUNC 
	
	#ifdef _CGSERVERDLL_SOURCE
		#define CGS_FUNC __declspec(dllexport)
	#else
		#define CGS_FUNC __declspec(dllimport)
	#endif //_CGSERVERDLL_SOURCE

#endif //_WINDOWS
//------------------------------------------------------------------------------


//===============================================================================
//DLL Initialization calls ======================================================
//===============================================================================

//First stage of CG initialization, performs external hardware interrogation, etc.
CGS_FUNC void CGS_EarlyInit(DWORD SoftwareVersionCode,DWORD ProgHinst,DWORD ProgHwnd,char *lpCmdLine);

//Second stage of CG initialization, UI layer supplies CG workspace Edit Window, 
//set OptionalEditBackgroundHwnd = NULL
CGS_FUNC void CGS_LateInit(DWORD EditHwnd, DWORD OptionalEditBackgroundHwnd);

//Closes the CG core during program exit, releases all core owned resources
CGS_FUNC void CGS_Close(void);

CGS_FUNC void CGS_GetSystemFontList(int *FontNameCount,char ***FontNameList);
CGS_FUNC void CGS_GetSystemFontList2(int *FontNameCount);
CGS_FUNC void CGS_GetSystemFontList3(void);
CGS_FUNC void CGS_GetSystemFontList4(DWORD ValID,LPVOID pValue);


//Calls made from UI on initialization  ==================
/*
in kents code:
void KentsScrollPosNotify(double dScrollPos0_1)
{
	dTrackPos=dTrackPixelSize*dScrollPos0_1;
	
}
*/
//UI registers a function that Core will call when core needs to change the Edit Window scrollbar position (i.e. due to word wrap cursor positioning, cursor & bounding box moves, box auto scroll, jump to top (Home key), etc...
CGS_FUNC void CGS_RegisterCGSetsEditWindowHorizScrollPosProc(void (*pScrollBarNotifyProc)(double ScrollPos));
CGS_FUNC void CGS_RegisterCGSetsEditWindowVertScrollPosProc(void (*pScrollBarNotifyProc)(double ScrollPos));
//UI registers a function that Core will call when core needs enable/disable the Edit Window scrollbar (i.e. changing page types) (needed for TitleWave case)
CGS_FUNC void CGS_RegisterUIScrollBarEnableProc(void (*pScrollBarEnableProc)(int HEnableFlag,int VEnableFlag));
CGS_FUNC void CGS_RegisterMousePointerModeProc(void (*pSetMousePointerModeProc)(int inMode));//for inMode see CGS_MOUSE_POINTER_MODE enum in cgs_valdefs.h

//--------------------------------------------------
//UI calls this to provide function for Core to call when core requests a particular object properties menu to be displayed
//int parameter is one of: {TEXT_OBJ_SUBTYPE,BOX_OBJ_SUBTYPE,FULL_SCREEN_BACKGROUND,PICTURE_OBJ_SUBTYPE,ELLIPSE_OBJ_SUBTYPE,LINE_OBJ_SUBTYPE,UNDERLINE_OBJ_SUBTYPE,MAX_EDIT_OBJECT_SUBTYPES};
//UI should display this menu, and re-read, refresh all values
CGS_FUNC void CGS_UIRegisterShowObjectProperitesMenu(void (*pNotifyCallback)(int));
//--------------------------------------------------


//Calls made from UI =====================================
//value changes signaled to/from core
CGS_FUNC void CGS_RegisterNotifyUIAttributeChange(void (*pNotifyCallback)(DWORD inValDefTag));//see cg_valdefs.h
CGS_FUNC void CGS_CurAttrSample_OnPaint(DWORD PreviewHwnd);

CGS_FUNC void CGS_RegisterUICurPagePreviewUpdate(void (*pNotifyCallback)(void)); //core calls callback to UI, UI then calls CGS_DrawPagePreview(DWORD Hwnd)
CGS_FUNC void CGS_DrawPagePreview(DWORD Hwnd); //UI calls this to draw page preview

//CGS_FUNC LRESULT CALLBACK CGS_IME_MSGHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL *is_composite_char);
CGS_FUNC LRESULT CGS_IME_MSGHandler(DWORD hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL *is_composite_char);

//value get and set:
CGS_FUNC void CGS_EnableCurAttrRefreshFromVals(BOOL Enable);


//===============================================================================
//Mouse interface ===============================================================
//===============================================================================

//UI layer notification of left mouse button down events in Edit Window
//MouseButtonFlags are CGS_MOUSE_LBUTTON_DOWN, etc, (0 if no buttons down)
//KeyModifierFlags are CGS_SHIFT_KEY_DOWN for Shift-Click, etc,
CGS_FUNC void CGS_NotifyEditMouseDown(int ClientX, int ClientY, DWORD KBFlags);
CGS_FUNC void CGS_NotifyEditMouseUp(int ClientX, int ClientY, DWORD KBFlags);
CGS_FUNC void CGS_NotifyEditMouseMove(int ClientX, int ClientY, DWORD KBFlags);
CGS_FUNC void CGS_NotifyEditMouseDrag(int ClientX, int ClientY, DWORD KBFlags);
//this is more generic for ScreenPlay:
CGS_FUNC void CGS_NotifyEditWindowMouseEvent(int ClientX, int ClientY, DWORD MouseButtonFlags, DWORD KeyModifierFlags);

//===============================================================================
//Keyboard interface ============================================================
//===============================================================================

//UI layer notification of Edit Window keyboard scancode or raw character. 
//This is for alphanumeric text intended for entry into document. 
//All other keys should use CGS_NotifyKeyDownSpecial().
CGS_FUNC void CGS_NotifyKBChar(DWORD hWnd, DWORD ScanCode, DWORD KeyModifierFlags);

//Unicode version of CGS_NotifyKBChar() for Unicode environment
CGS_FUNC void CGS_NotifyKBCharUnicode(DWORD hWnd, DWORD UnicodeScanCode, DWORD KeyModifierFlags);

//Keydown notification for non-alphanumeric special control keys such as 
//Backspace, Delete, Insert, Page Up, Function Keys, Arrowkeys, etc.
CGS_FUNC void CGS_NotifyKeyDownSpecial(DWORD hWnd, DWORD VirtualKeyCode, DWORD KeyModifierFlags);

CGS_FUNC void CGS_CursorAdvanceOneShotDisable(void); //for special ime in-place char replacement

CGS_FUNC void CGS_NotifyEditTypeChar(DWORD MultibyteScanCode); //..UI DOESN'T call this
CGS_FUNC void CGS_NotifyEditTypeUnicodeChar(DWORD UnicodeVal); //..UI DOESN'T call this


CGS_FUNC void CGS_TW_BinSetsContent(unsigned short bin_obj_type,void *bin_obj_data,long obj_data_size,unsigned short fosc_flag);
CGS_FUNC void CGS_TW_BinItemClickFilter(unsigned short bin_obj_type,void *bin_obj_data,long obj_data_size,unsigned short fosc_flag,short double_click_flag);
CGS_FUNC void CGS_TW_BinToScreenDropFilter(unsigned short dd_obj_type,void *bin_obj_data,long obj_data_size,short drop_x,short drop_y,unsigned short fosc_flag,int force_paste_to_bounded_items_if_any);
CGS_FUNC void CGS_TW_DropBinToSampleWindow(unsigned short bin_obj_type,void *bin_obj_data,long obj_data_size,unsigned short fosc_flag);
CGS_FUNC void CGS_TW_DropSampleToScreen(short drop_x,short drop_y);
CGS_FUNC BOOL CGS_TW_PageHasEffect(void);
CGS_FUNC unsigned char *CGS_TW_SavePageToRam(long *page_bytes_in_ram,int clean_up_flag);
CGS_FUNC void CGS_TW_LoadPageFromRam(unsigned char *src_ram_buffer,long page_bytes_in_ram,int clear_document);
CGS_FUNC unsigned char *CGS_TW_SavePresetToRam(long *page_bytes_in_ram,int clean_up_flag);
CGS_FUNC void CGS_TW_LoadPresetFromRam(unsigned char *src_ram_buffer,long page_bytes_in_ram);


//=========================================================
//File Requester
CGS_FUNC void CGS_GetFileCategoryPathInfo(FILE_REQ_FOLDER_INFO* pFd);
CGS_FUNC void CGS_SetFileCategoryPathInfo(FILE_REQ_FOLDER_INFO* pFd);
CGS_FUNC void CGS_GetComponentsFromFileName(char* inFullFileName,char* outpFolder,char* outpFile,char* outpExt);//utility func

//=========================================================
//edit window:
CGS_FUNC void CGS_EditWindowPaint(void);
CGS_FUNC void CGS_NotifyEditWindowResize(void);
CGS_FUNC void CGS_SetNleBgImageFile(char *Filename);
CGS_FUNC void CGS_SetNleBgImageData(BYTE *pImageBGRA,int ImageWidth,int ImageHeight,int DataFormat);

//=========================================================
//CG Core data value IO
CGS_FUNC void CGS_SetVal(DWORD ValID,LPVOID pValue);
CGS_FUNC void CGS_GetVal(DWORD ValID,LPVOID pValue);
CGS_FUNC int CGS_SetValInt(DWORD ValID,int Value);
CGS_FUNC int CGS_GetValInt(DWORD ValID);
CGS_FUNC double CGS_SetValDbl(DWORD ValID,double Value);
CGS_FUNC double CGS_GetValDbl(DWORD ValID);
CGS_FUNC void CGS_SetValStr(DWORD ValID,char *pStr);
CGS_FUNC void CGS_GetValStr(DWORD ValID,char *pStr);
CGS_FUNC void CGS_GetDataItem(int ItemID,void *DestPtr);
CGS_FUNC void CGS_SetDataItem(int ItemID,void *SrcPtr);
CGS_FUNC void CGS_GetSpinControlNextValue(DWORD ValID,int Increment,double *pValue);

CGS_FUNC void CGS_Action(DWORD ActionCode);

CGS_FUNC void CGS_EditPasteMenuChangeToSelChars(void *pAttrMasks);
CGS_FUNC void CGS_ResizeMenuSetAbsSize( double Width,double Height);

//=========================================================
//IME KEYBOARD INPUT
CGS_FUNC void CGS_ImeStartComposition(void);//signal start state
CGS_FUNC void CGS_ImeUpdateString( DWORD indwImeUnicodeString, int inImeUnicodeStringLength,DWORD indwAttributeArray, int inImeCursorPos );
CGS_FUNC void CGS_ImeEndComposition(void);//signal end state
CGS_FUNC void CGS_NotifyInputLanguageChange(DWORD LocaleID,DWORD Charset);//signal start state

CGS_FUNC void CGS_ImeGetCandidateEditWindowAnchorXY(DWORD outdwpXPos, DWORD outdwpYPos, DWORD inCandidateWindowWidth, DWORD inCandidateWindowHeight);
//call format is CGS_ImeGetCandidateEditWindowAnchorXY((DWORD)&outdwpXPos,(DWORD)&outdwpYPos,(DWORD)inCandidateWindowWidth,(DWORD)inCandidateWindowHeight);

//=========================================================
//PROJECT CONTROL
CGS_FUNC void CGS_NewProject(void);
CGS_FUNC void CGS_LoadProject(char *FullFilePathAndName);
CGS_FUNC void CGS_SaveProjectAs(char *inFullFileName);// "c:\alpha_cg\Projects\KentsProj.acg");
CGS_FUNC void CGS_SaveProject(void);

//=========================================================
//PICTURE LOAD FILE DIALOG SUPPORT

//displays picture preview in hwnd, fills outPictureSizeString with size string
//returns false if picture format is inavlid
CGS_FUNC BOOL CGS_GetPictureInfo(char *inFullFilePath, HWND inPreviewHWND, int inPreviewHwndBorderSize, char *outPictureSizeString);

//=========================================================
//PICTURE LOAD OPTIONS MENU (for loading pictures
CGS_FUNC void CGS_GetPictureLoadOptions(char *inFullFilePath, PICTURE_LOAD_OPTIONS_INFO* inoutpPictureLoadOptionsInfo);
CGS_FUNC void CGS_AcceptLoadPictureOptions(char *inFullFilePath, PICTURE_LOAD_OPTIONS_INFO* inPictureLoadOptionsInfo);


//=========================================================
//DIRECT PICTURE IMPORT (for texture mapping)
CGS_FUNC void CGS_ApplyPictureTextureMap(char *inFullFilePath, DWORD EditContext);//edit context is	EDIT_OBJ_SHADOW1_ALPHA_MASK,EDIT_OBJ_SHADOW1_COLORSCHEME, etc

//=========================================================
//PICTURE EXPORT
CGS_FUNC void CGS_PreviewPageOnExtHardware(void);
CGS_FUNC void CGS_ExportPage(char *inFullFilePath,char *inFolder,char *inFilenamePlusExt,CGS_IMAGE_FILE_FORMAT inFileType,BOOL inUseNumberedFilenames,BOOL inUsePageAnnotationNames);
CGS_FUNC void CGS_ExportProjectBegin(char *inFullFilePath,char *inFolder,char *inFilenamePlusExt,CGS_IMAGE_FILE_FORMAT inFileType,BOOL inUseNumberedFilenames, BOOL inUsePageAnnotationNames);
CGS_FUNC DWORD CGS_ExportProjectNextPage(void);//returns false when last page has been processed (i.e.bContinue=CGS_ExportProjectEnd())
CGS_FUNC void CGS_ExportProjectEnd(void);//restores prior edit page

//=========================================================
//RESOLUTION MENU
CGS_FUNC void CGS_ResolutionMgrMenuEntryInit(void);
CGS_FUNC void CGS_ResolutionMgrGetMenuVals(int *pModeListIndex,char *pModeName,int *ModeWidth,int *ModeHeight);
CGS_FUNC void CGS_ResolutionMgrGetModeListItemCount(int *ListItemCount);
CGS_FUNC void CGS_ResolutionMgrGetModeListItemName(int ListItem,char *ItemName);
CGS_FUNC void CGS_ResolutionMgrSetNewWidth(int Width);//call CGS_ResolutionMgrGetMenuVals() after this to get updated values
CGS_FUNC void CGS_ResolutionMgrSetNewHeight(int Height);//call CGS_ResolutionMgrGetMenuVals() after this to get updated values
CGS_FUNC void CGS_ResolutionMgrSetNewMode(int ModeIndex);//after UI calls this, UI should call CGS_ResolutionMgrGetMenuVals() to get class managed updated settings
CGS_FUNC void CGS_ResolutionMgrAcceptNewMode(void);//call when user selects OK

//=========================================================
//Spell checker
CGS_FUNC void CGS_SpellBeginCheck(void);
CGS_FUNC void CGS_SpellGetSuggestionWord(char* outpSuggestionWord);
CGS_FUNC BOOL CGS_SpellGetNextMisspelledWord(char* outpNextWord);
CGS_FUNC void CGS_SpellReplaceCurrentWord(char *inNewWord);
CGS_FUNC void CGS_SpellAddWordToDictionary(char* inpNewWord);
CGS_FUNC int  CGS_SpellGetAlternativeSpellingCount(void);
CGS_FUNC void CGS_SpellGetAlternativeSpellingWord(int inWordIndex,char* outpAlternativeWord);
CGS_FUNC void CGS_SpellEndCheck(void);

//=========================================================
//Tab menu
CGS_FUNC void CGS_TabMenuEnter(void (*pNotifyCallback)(void));//call on dlg entry
CGS_FUNC void CGS_TabMenuExit(void);//call on dlg exit
CGS_FUNC void CGS_TabMenuRefreshWorkspace(void);//after each menu change UI calls this to update workspace display
CGS_FUNC void CGS_TabMenuResetAll(void);//reset all tabs to program defaults
CGS_FUNC void CGS_TabMenuSetCurrentTab(int TabIndex);//allow highlighting of current tab


//=========================================================
//Margins,grids
CGS_FUNC void CGS_ResetMargins(void);
CGS_FUNC void CGS_ResetGrids(void);


//=========================================================
//Edit Commands

CGS_FUNC void CGS_EditKeyUpArrow(int);
CGS_FUNC void CGS_EditKeyDownArrow(int);
CGS_FUNC void CGS_EditKeyLeftArrow(int);
CGS_FUNC void CGS_EditKeyRightArrow(int);
CGS_FUNC void CGS_SetDocHScrollPos(double ScrollPos_0_1);
CGS_FUNC void CGS_SetDocVScrollPos(double ScrollPos_0_1);
CGS_FUNC void CGS_DocScrollPrevLine(BOOL bVerticalScrollBar);
CGS_FUNC void CGS_DocScrollNextLine(BOOL bVerticalScrollBar);
CGS_FUNC void CGS_DocScrollPrevPage(BOOL bVerticalScrollBar);
CGS_FUNC void CGS_DocScrollNextPage(BOOL bVerticalScrollBar);

CGS_FUNC void CGS_PickUpAttrAtCursor(void);
CGS_FUNC void CGS_PickUpAttrAt(int x,int y);
CGS_FUNC void CGS_EditUndo(void);
CGS_FUNC void CGS_EditRedo(void);
CGS_FUNC void CGS_EditRecordUndo(DWORD UndoType,char *SourceIdMsg);
CGS_FUNC void CGS_EditResetUndo(void);
CGS_FUNC void CGS_AutoPageSave(void);
CGS_FUNC void CGS_TwOneToOneButton(void);
CGS_FUNC void CGS_TwEffectManager(DWORD operation, DWORD data0, DWORD data1, char *filename);
CGS_FUNC void CGS_EditCursorEOP(void);
CGS_FUNC void CGS_EditApplyLineSpacing(void);
CGS_FUNC void CGS_EditCharSpacingPlusMinus(int Delta);
CGS_FUNC void CGS_EditInitNewPage(int PageNum);
CGS_FUNC void CGS_CreateNewPage(DWORD InsertMode);//1 = append a new page after current page
CGS_FUNC void CGS_PageVertCenter(int flag);
CGS_FUNC void CGS_SetUnderlineRGB(int R,int G,int B,int RefreshFlag);

CGS_FUNC void CGS_TW_ResetCharDefaults(void);
CGS_FUNC void CGS_EditDuplicateSelectedText(void);
CGS_FUNC void CGS_EditSelectText(void);
CGS_FUNC void CGS_EditSelectGraphics(void);
CGS_FUNC void CGS_EditSelectAll(void);
CGS_FUNC void CGS_EditSaveSelectionToPicFile(char *n);

CGS_FUNC void CGS_EditRedisplayRegion(int document,int region_x0,int region_y0,int region_width,int region_height,BOOL do_external_fb_update);

CGS_FUNC BOOL CGS_EditCheckObjectAt(int x,int y);
CGS_FUNC int CGS_EditGetObjectTypeAt(int x,int y);

CGS_FUNC BOOL CGS_EditCheckCursorIsBox(void);

CGS_FUNC DWORD CGS_TwCheckForTrinityHardware(void);
CGS_FUNC void CGS_TwEditAssignEffectToSelection(int Effect);
CGS_FUNC void CGS_TwEditAssignFadingToggleToSelection(int FadeState);
CGS_FUNC void CGS_TwEditClearAllAnimEffects(void);
CGS_FUNC void CGS_TwEditGetEffectFromSelection(TW_CHAR_ANIM_INFO *ObjAnimInfo);


CGS_FUNC void CGS_WriteIniFile(void);
CGS_FUNC void CGS_EditRefreshCursor(void);
CGS_FUNC void CGS_RefreshEditCursorSize(void);

CGS_FUNC void CGS_EditSetDefaultTabs(void);
CGS_FUNC void CGS_EditSetDefaultGrids(void);
CGS_FUNC void CGS_EditSpaceCharsAtCursor(void);
CGS_FUNC void CGS_EditTuckCharsAtCursor(void);

CGS_FUNC void CGS_EditSetProjectFolder(char *Folder);
CGS_FUNC int CGS_GetCurrentPageNumber(void);
CGS_FUNC void CGS_EditPageRenderAndDisplay(void);
CGS_FUNC void CGS_EditRenderPage(void);

CGS_FUNC void CGS_EditPasteCurAttrToSelChars(
	CGObjAttrMasks* PasteMask,
	int enable_F4_ripple,
	int enable_paste_from_mab_current/*paste from the real current attr not the one just showing in menu(which is sized to fit curent sample window)*/);


CGS_FUNC void CGS_EditDeleteUnusedLines(int Flag);
CGS_FUNC void CGS_EditAddBox(BOOL bFullScreen);
CGS_FUNC void CGS_EditAddEllipse(void);
CGS_FUNC void CGS_EditAddPicture(char *pathname,float param_x,float param_y);
CGS_FUNC void CGS_AllocConvEditWBToDib( short src_x,short src_y,short width,short height,short store_alpha,short rightside_up_dest,short do_bg_subst);

CGS_FUNC void CGS_EditRenderPageToBitBuffer(unsigned char *dest_buffer_ptr,int plot_width,int plot_height,int dest_buffer_pix_width,int dest_buffer_pix_height);
CGS_FUNC void CGS_EditRenderCurAttrSampleToBitBuffer(unsigned char *dest_buffer_ptr,int plot_width,int plot_height);

CGS_FUNC void CGS_EditRenderColorboxToBitBuffer(void *ColorBox,unsigned char *dest_buffer_ptr,int plot_width,int plot_height);
CGS_FUNC void CGS_RenderColorboxToWindow(void *ColorBox,DWORD Hwnd,int BorderSize);
CGS_FUNC void CGS_RenderColorboxAsSpreadBarToWindow(void *ColorBox,DWORD Hwnd);

CGS_FUNC void CGS_FreeWBToDib(void);
CGS_FUNC void CGS_EditPreviewPage(void);
CGS_FUNC void CGS_EditCut(void);
CGS_FUNC void CGS_EditCopy(void);
CGS_FUNC void CGS_EditPaste(void);
CGS_FUNC void CGS_EditClearPageText(void);
CGS_FUNC void CGS_EditClearPageGraphics(void);
CGS_FUNC void CGS_EditLoadWordDocAtCursor(char *Filename);
CGS_FUNC void CGS_EditPanicResetAttr(void);

CGS_FUNC void CGS_EditCursorSol(void);
CGS_FUNC void CGS_EditCursorEol(void);
CGS_FUNC void CGS_EditCursorHome(void);

CGS_FUNC BOOL CGS_ImportTextFileAtCursor(char* inFileName);


//=========================================================
//UI Support
CGS_FUNC void CGS_EditUpdateCurColorSample(DWORD Hwnd, int BorderSize, int ColorContext);//color context=	EDIT_OBJ_FACE_ALPHA_MASK, EDIT_OBJ_FACE_COLORSCHEME, etc
CGS_FUNC void CGS_EditUpdateCurEffectPicon(DWORD Hwnd, int BorderSize);//for effect tab picon
CGS_FUNC DWORD CGS_RenderColorboxToHBitmap(ALPHA_COLOR_BOX *colorbox,short clean_up);
CGS_FUNC DWORD CGS_RenderCurObjToHBitmap( char **data_ptr, long *data_size, short clean_up );
CGS_FUNC DWORD CGS_TW_CreatePresetHbitmap(int Width,int Height);
CGS_FUNC DWORD CGS_RenderPageToHBitmap(int Width,int Height);

CGS_FUNC DWORD CGS_GetWbToDibBitmapInfoPtr(void);
CGS_FUNC DWORD CGS_GetWbToDibPtr(void);
CGS_FUNC void CGS_EditRedisplayPage(void);


//=========================================================
//UI Bin Support
CGS_FUNC void CGS_BinOpen(int BinItemType,HWND Wnd, char* FileName ,void (*inpCoreNotifyUItoSetScrollPosCallback)(double ScrollPos_01));
CGS_FUNC void CGS_BinSetScroll(int BinItemType,double ScrollPos);//UI calls this to set scroll position of bin to 0.0 to 1.0
CGS_FUNC double CGS_BinGetScroll(int BinItemType);//UI calls this to get scroll position of bin to 0.0 to 1.0
CGS_FUNC void CGS_BinRefresh(int BinItemType);
CGS_FUNC void CGS_BinSelect(int BinItemType,int MenuContext,int ViewX,int ViewY);
CGS_FUNC void CGS_BinSelectItem(int BinItemType,int MenuContext,int ItemIndex);
CGS_FUNC void *CGS_BinGetItemDataPtr(int BinItemType,int ItemIndex);
CGS_FUNC int CGS_BinGetSelectedIndex(int BinItemType);
CGS_FUNC void CGS_BinRegisterGetStringDlgCallback(int BinItemType,void (*pGetStringDlgCallback)(char* pStringVal));
CGS_FUNC int CGS_BinGetSelectedIndex(int BinItemType);
CGS_FUNC int CGS_BinGetIndexAt(int BinItemType,int ViewX,int ViewY);
CGS_FUNC BOOL CGS_BinGetItemData(int BinItemType,int ItemIndex,void *CopyPtr);
CGS_FUNC BOOL CGS_BinSetItemData(int BinItemType,int ItemIndex,void *CopyPtr);
CGS_FUNC void CGS_BinScrollLineUp(int BinItemType);
CGS_FUNC void CGS_BinScrollLineDown(int BinItemType);
CGS_FUNC void CGS_BinScrollPageUp(int BinItemType);
CGS_FUNC void CGS_BinScrollPageDown(int BinItemType);

//=========================================================
//Trinity Control
CGS_FUNC BOOL CGS_TW_InitSimpleVideo(void);
CGS_FUNC void CGS_TW_ReleaseSimpleVideo(void);
CGS_FUNC void CGS_TW_VerifyVideoSystem(void);
CGS_FUNC void CGS_TrinityEffectEnd(BOOL bFlag);
CGS_FUNC unsigned char *CGS_TW_EffectGenTFSPropInfo( int *data_byte_count );



//=========================================================
//DEFINES FOR KEY CODES - not sure why we have to define these...
#define KEY_SPACE 32 // Use original ASCII value
#define KEY_TAB '\t' // Use original ASCII value
#define KEY_BACKSPACE '\b' // Use original ASCII value
#define KEY_F1 270
#define KEY_F2 271
#define KEY_F3 272
#define KEY_F4 273
#define KEY_F5 274
#define KEY_F6 275
#define KEY_F7 276
#define KEY_F8 277
#define KEY_F9 278
#define KEY_F10 279
#define KEY_F11 280
#define KEY_F12 281
#define KEY_F13 282
#define KEY_F14 283
#define KEY_F15 284
#define KEY_F16 285
#define KEY_F17 286
#define KEY_F18 287
#define KEY_F19 288
#define KEY_F20 289
#define KEY_F21 290
#define KEY_F22 291
#define KEY_F23 292
#define KEY_F24 293
#define KEY_KPMULT 295
#define KEY_KPDIV 296
#define KEY_KPADD 297
#define KEY_KPSUB 298
#define KEY_KPDECIMAL 299
#define KEY_KP0 300
#define KEY_KP1 301
#define KEY_KP2 302
#define KEY_KP3 303
#define KEY_KP4 304
#define KEY_KP5 305
#define KEY_KP6 306
#define KEY_KP7 307
#define KEY_KP8 308
#define KEY_KP9 309
#define KEY_UP 310
#define KEY_DOWN 311
#define KEY_LEFT 312
#define KEY_RIGHT 313
#define KEY_PAGEUP 314
#define KEY_PAGEDOWN 315
#define KEY_HOME 316
#define KEY_END 317
#define KEY_INSERT 318
#define KEY_DELETE 319
#define KEY_CLEAR 320
#define KEY_SHIFT 321
#define KEY_CAPITAL 322
#define KEY_CONTROL 323
#define KEY_ALT 324
#define KEY_RETURN 325
#define KEY_ESCAPE 326
#define KEY_NUMLOCK 327
#define KEY_SCROLLLOCK 328
#define KEY_PRINTSCREEN 329
#define KEY_PAUSE 330
#define KEY_CANCEL 331



#endif _CGSERVERDLL_H
