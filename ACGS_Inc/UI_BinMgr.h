#ifndef _UI_BINMGR_H
#define _UI_BINMGR_H

//#include "cg_gfxbuf.h"
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>

#include "LinkList.h"
#include "CG_Gfxbuf.h"

#define DEFAULT_BIN_SPACING 0
#define DEFAULT_SHADOW_DEPTH 0
#define DEFAULT_HIGHLIGHT_COLOR 0x00e0e020
#define DEFAULT_BIN_BG_COLOR 0x00404040
//#define DEFAULT_BIN_BG_COLOR 0x00

#define BIN_PAGE_PICON_WIDTH 120
#define BIN_PAGE_PICON_HEIGHT 90
#define PAGE_ANNOTATION_PICON_WIDTH BIN_PAGE_PICON_WIDTH
#define PAGE_ANNOTATION_PICON_HEIGHT 18

#define BIN_FONT_PRESET_PICON_WIDTH 36
#define BIN_FONT_PRESET_PICON_HEIGHT 30

#define BIN_EFFECT_PICON_WIDTH 64
#define BIN_EFFECT_PICON_HEIGHT 48

enum UIBIN_TYPE
{
	UIBIN_PAGE,
	UIBIN_LAYER,	//now
	UIBIN_FILTER,	//future
	UIBIN_STYLE,	//future
	UIBIN_FONT_PRESET,
	UIBIN_PALETTE,//main interface palette
	UIBIN_PALETTE_MENU, //palette menu pool
	UIBIN_MULTI_CAPTURE_BUFFER,
	UIBIN_TEMPLATE,
	UIBIN_EFFECT
};


class UIBinMgr
{
	
	public:
	friend class GfxBuf;

//	LinkList <CLS_GfxServerBufferAndSpec*> CacheColorBoxList;
//			CLS_GfxServerBufferAndSpec* ListNode;
//			ListNode = new CLS_GfxServerBufferAndSpec(&TemplateBaseItemSpec,BaseGfxBuf);
//			CacheColorBoxList.Prepend(ListNode,ListNode->GfxItemBuffer->BufferBytes);

	UIBIN_TYPE BinType;
	double ScrollPos;
	int MaxCacheItems;
	int ItemCount;
	int CurrentSelectedItem;
	int PreviousSelectedItem;
	HWND DisplayHwnd;
	//DWORD DebugLastHDC;


	int BinScrollY;
	int BinScrollX;
	int BinEdgeMargin;//extra spacing added to upper left corner of picon display location

	int PiconWidth; //width of the picture
	int PiconHeight;
	int PiconHighlightEdgeSize; //width of the extra border surrounding picture
	int PiconShadowDepth;
	//int HighlightEdgeSize;
	int CellSpacing;
	int MaxHCells;
	int	PiconSubWidth;
	int PiconSubHeight;

	int CellWidth; //width of the cell (excludes CellSpacing)
	int CellHeight;//height of the cell (excludes CellSpacing)
	int CellDeltaH; //horizontal distance from left edge of cell to next cell on right
	int CellDeltaV; //vertical distance from top edge of cell to next cell below

	int BinViewWidth;
	int BinViewHeight;
	int CellsPerViewRow;

	int BinTotOccupiedHeight;

	COLORREF BinBackgroundColor;
	COLORREF CellHighlightColor;

	GfxBuf* ViewGfxBuf;	//dest buffer for drawing the view

	GfxBuf* CurrentItemMasterGfxBuf;//optional external source i.e. page picon rendering

	//Primary picon
	GfxBuf* (*PiconRendererCallback)(int ItemIndex, int Width, int Height); //Function to render a picon
	void (*PiconSelectCallback)(int MenuContext,int ViewX,int ViewY);//function to handle a select operation

	//Sub picon (i.e. 
	GfxBuf*  (*PiconSubRendererCallback)(int ItemIndex, int Width, int Height,GfxBuf* inpPiconGfxBuf); //Function to render a picon
	void (*PiconSubSelectCallback)(int MenuContext,int ViewX,int ViewY);//function to handle a select operation

	//Get String dialog callback for 
	void (*GetStringDlgCallback)(char* pStringVal);

	void (*CoreNotifyUItoSetScrollPosCallback)(double ScrollPos_01);
	
	void SetCurrentItemMasterGfxBuf(GfxBuf* inCurrentItemMasterGfxBuf);

//-------------------------------------
//-------------------------------------
//constructor
UIBinMgr(
	UIBIN_TYPE BinItemType,
	HWND DispHwnd, //determines size of bin view
	int HorizCellCountLimit, //max number of cells allowed per row i.e. page list = 1, palette = 22
	int PiconWidth,
	int PiconHeight,
	int HighlightEdgeSize,
	int Spacing,
	int ExtraEdgeMargin,
	GfxBuf*  (*pPiconRendererCallback)(int ItemIndex, int Width, int Height), //Function to render a picon
	void (*pPiconSelectCallback)(int MenuContext,int ViewX,int ViewY),//function to handle a select operation
	void (*inpCoreNotifyUItoSetScrollPosCallback)(double ScrollPos_01)//function core can call to tell UI to set visual thumh track scroll pos 0.0->1.0f
	);
~UIBinMgr();

void AppendItem(BOOL RedisplayFlag);

void AddPiconSubSection(
	int PiconSubW,
	int PiconSubH,
	GfxBuf*  (*pPiconSubRendererCallback)(int ItemIndex, int Width, int Height,GfxBuf* inpPiconGfxBuf), //Function to render a picon
	void (*pPiconSubSelectCallback)(int MenuContext,int ViewX,int ViewY)//function to handle a select operation
	);

void SetPiconParams(int PicW,int PicH,int HighlightEdgeSize,int ShadowDepth);
void SetBinParams(int HorizCellCountLimit,int Spacing);
void RecalcCellPlacementParams(void);
void SetColorParams(COLORREF HighlightColor,COLORREF BackgroundColor);
void SetBinViewSize(int Width,int Height);
void SetCacheItemLimit(int ItemLimit);
void UI_Clear(void);
void UI_RefreshBinWindow(void);
//void UI_NotifySelect(int BinItemType,int ViewX,int ViewY)
void UI_NotifySetScrollPos(double ScrollPos);//ui tells core to set pos based on user action in UI
void UI_NotifyScrollLineDown(void);//UI calls when user clicks in thum track controls
void UI_NotifyScrollLineUp(void);//UI calls when user clicks in thum track controls
void UI_NotifyScrollPageDown(void);//UI calls when user clicks in thum track controls
void UI_NotifyScrollPageUp(void);//UI calls when user clicks in thum track controls

void NotifyUItoRedrawThumbTrack(void);//core tells ui to draw (only to draw it!) the thumb track indicator
double UI_NotifyScrollRelease(void);
double UI_QueryScrollPos(void);
int UI_HandleMouseSelect(int ClientX, int ClientY);
void SelectItem(int Item);
void SelectItemQuiet(int Item);
void SetItemPiconAsSelected(int Item);
void PlotBinCell(int ItemIndex);
void DisplayViewBuffer(void);

void RegenerateSingleItem(int ItemIndex); //content has changed (i.e. for page picon, palette color box changes
GfxBuf* GetPiconGfxBuf(int ItemIndex ); //content has changed (i.e. for page picon, palette color box changes
GfxBuf* GetPiconSubGfxBuf(int ItemIndex,GfxBuf* inpPiconGfxBuf);//this is a sub section label as in page bin picon annotation
GfxBuf* GetCellGfxBuf(int ItemIndex);
void CalcCellXYFullBin(int ItemIndex,int *XPos, int *YPos);
int GetItemIndexAtViewXY(int ViewX, int ViewY, int *PiconSubSection);
void GetItemViewXYfromIndex(int ItemIndex,int* RetViewX, int* RetViewY);
int CalcBinYScrollFromScrollPos01(double inScrollPos);
double CalcScrollPos01FromBinYScroll(int inYScrollVal);

void GetVisibleItemRange(int* outFirstVisibleItem,int* outLastVisibleItem);
void EnsureItemVisible(int inItemIndex);


private:

/*		// Pointer to global functions
		void (*m_SelectFunction)(short);
		int  (*m_CountFunction)(void);
		void (*m_CopyAttribFunction)(short);

		BOOL (*m_GenPiconFunction)(DWORD *, int, int, int);

		void Bin_SetGenPiconFunction(	BOOL (*GenPicon)(DWORD *Buffer,
										int ID, int Width, int Height) )
		{ 
			m_GenPiconFunction = GenPicon; 
		}


		void (*m_NumberedLabelFunction)(short, char *);
		void (*m_UnNumberedLabelFunction)(short, char *);
*/


};


void TestUIBinMgr(void);
BOOL UI_BinMgr_BinOpen(int BinItemType,HWND Wnd,char *FullFileName, void (*inpCoreNotifyUItoSetScrollPosCallback)(double ScrollPos_01));
void UI_BinMgr_BinRefresh(int BinItemType);
void UI_BinMgr_NotifySetScrollPos(int BinItemType, double ScrollPos);
void UI_BinMgr_NotifySelect(int BinItemType,int MenuContext,int ViewX,int ViewY);
void UI_BinMgr_NotifySelectItem(int BinItemType,int MenuContext,int ItemIndex);
void UI_BinMgr_NotifyScrollLineUp(int BinItemType);
void UI_BinMgr_NotifyScrollLineDown(int BinItemType);
void UI_BinMgr_NotifyScrollPageUp(int BinItemType);
void UI_BinMgr_NotifyScrollPageDown(int BinItemType);

void UI_BinMgr_BinRegisterDlgCallback(int BinItemType,void (*pGetStringDlgCallback)(char* pStringVal));
void* UI_BinMgr_GetDataItemDataPtr(int BinItemType,int ItemIndex);
int UI_BinMgr_GetSelectedIndex(int BinItemType);
int UI_BinMgr_GetIndexAt(int BinItemType,int ViewX,int ViewY);
BOOL UI_BinMgr_GetDataItemData(int BinItemType,int ItemIndex,void *CopyPtr);
BOOL UI_BinMgr_SetDataItemData(int BinItemType,int ItemIndex,void *CopyPtr);
int UI_BinMgr_DumpStats(UIBinMgr* pBin);
double UI_BinMgr_GetScrollPos(int BinItemType);

//extra public help functions ----------------
GfxBuf* GetEffectPiconGfxBuf(int ItemIndex);

#endif _UI_BINMGR_H
