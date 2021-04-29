#ifndef _TW_ANIM_RECT_H

#define _TW_ANIM_RECT_H

#include "Play_sdk\trnity.h"
#include "Play_sdk\pubclsid.h"
#include "Play_sdk\playlist.h"

#define MAX_TW_ANIM_RECTS 16
enum 
{ 
TW_ANIM_NONE,
TW_ANIM_POP,
TW_ANIM_SLIDE_UP,
TW_ANIM_SLIDE_LEFT,
TW_ANIM_SLIDE_RIGHT,
TW_ANIM_SLIDE_DOWN,
TW_ANIM_REVEAL_UP,
TW_ANIM_REVEAL_LEFT,
TW_ANIM_REVEAL_RIGHT,
TW_ANIM_REVEAL_DOWN,
TW_ANIM_CRAWL,
TW_ANIM_ROLL,
TW_ANIM_FLASH,
TW_ANIM_TWIST,
TW_ANIM_FLIP_V,
TW_ANIM_FLIP_H,
TW_ANIM_ZOOM_IN,
TW_ANIM_JIGGLE,
TW_ANIM_FOCUS,
TW_ANIM_EXPAND_UP,
TW_ANIM_EXPAND_RIGHT,
TW_ANIM_EXPAND_DOWN,
TW_ANIM_EXPAND_LEFT,
TW_ANIM_FADE_IN,
TW_ANIM_FADE_OUT,
TW_ANIM_VS_FLIPBOOK, //variable frame rate flip book
TW_ANIM_TELETYPE,
TW_ANIM_NUM_EFFECTS
};

typedef struct
{
	int Effect;
	char *Name;
	BOOL Enabled; //else excluded from list
	BOOL UnGhosted; //if FALSE include but just make dark
	BOOL HasCheckMark;
	BOOL HasDividerBar;
}TW_ANIM_SINGLE_EFFECT_POPUP_INFO;

#ifdef ENABLE_VAR_INITS
TW_ANIM_SINGLE_EFFECT_POPUP_INFO TW_AnimEffectPopupInfo[TW_ANIM_NUM_EFFECTS]=
{
TW_ANIM_NONE,			"(No effect)",			TRUE,TRUE, FALSE, TRUE, //DIVIDER
TW_ANIM_POP,			"Pop On",			TRUE,TRUE, FALSE, FALSE,
TW_ANIM_TELETYPE,		"Teletype",		TRUE,TRUE, FALSE, FALSE,
TW_ANIM_SLIDE_UP,		"Slide Up",		TRUE,TRUE, TRUE, FALSE,
TW_ANIM_SLIDE_LEFT,		"Slide Left",	TRUE,TRUE, TRUE, FALSE,
TW_ANIM_SLIDE_RIGHT,	"Slide Right",	TRUE,TRUE, TRUE, FALSE,
TW_ANIM_SLIDE_DOWN,		"Slide Down",	TRUE,TRUE, TRUE, FALSE,
TW_ANIM_REVEAL_UP,		"Reveal Top",	0,TRUE, FALSE, FALSE,
TW_ANIM_REVEAL_LEFT,	"Reveal Left",	0,TRUE, FALSE, FALSE,
TW_ANIM_REVEAL_RIGHT,	"Reveal Right",	0,TRUE, FALSE, FALSE,
TW_ANIM_REVEAL_DOWN,	"Reveal Bottom",	0,TRUE, FALSE, FALSE,
TW_ANIM_CRAWL,			"Pan Left",		FALSE,TRUE, FALSE, FALSE,
TW_ANIM_ROLL,			"Pan Right",	FALSE,TRUE, FALSE, FALSE,
TW_ANIM_FLASH,			"Flash",		FALSE,TRUE, FALSE, FALSE,
TW_ANIM_TWIST,			"Twist",		TRUE,TRUE, FALSE, TRUE, //DIVIDER
TW_ANIM_FLIP_V,			"Flip V",		TRUE,TRUE, FALSE, FALSE,
TW_ANIM_FLIP_H,			"Flip H",		TRUE,TRUE, FALSE, FALSE,
TW_ANIM_ZOOM_IN,		"Zoom",			TRUE,TRUE, FALSE, FALSE,
TW_ANIM_JIGGLE,			"Jiggle",		FALSE,TRUE, FALSE, FALSE,
TW_ANIM_FOCUS,			"Focus",		FALSE,TRUE, FALSE, FALSE,
TW_ANIM_EXPAND_UP,		"Expand Up",	0,TRUE, FALSE, FALSE,
TW_ANIM_EXPAND_RIGHT,	"Expand Right",0,TRUE, FALSE, FALSE,
TW_ANIM_EXPAND_DOWN,	"Expand Down",	0,TRUE, FALSE, FALSE,
TW_ANIM_EXPAND_LEFT,	"Expand Left",	0,TRUE, FALSE, FALSE,
TW_ANIM_FADE_IN,		"Fade",			FALSE,FALSE, FALSE, FALSE,
TW_ANIM_FADE_OUT,		"Fade Out",		FALSE, TRUE,FALSE, FALSE,
TW_ANIM_VS_FLIPBOOK,	"Flip Book",	FALSE, TRUE,FALSE, FALSE //i.e. master background composite
};
#else
extern TW_ANIM_SINGLE_EFFECT_POPUP_INFO TW_AnimEffectPopupInfo[TW_ANIM_NUM_EFFECTS];
#endif

#ifdef ENABLE_VAR_INITS
int TW_AnimPopupEffectsCount;
#else
extern int TW_AnimPopupEffectsCount;
#endif

enum { TW_ALPHA_VIEW,TW_D1_VIEW,NUM_VIEWTYPES};

//---------------------------------------------------------
typedef struct
{
	
	BOOL Assigned;
	int SegValStart;
	int SegValInc;
	int SegAccel;
	int SegDuration;
}TW_VIEW_ANIMATED_DATASEGMENT;
#define TW_MAX_PLAYLIST_ANIM_SEGMENTS 4

//---------------------------------------------------------
typedef struct
{
	int AnimDataSegments;
	TW_VIEW_ANIMATED_DATASEGMENT AnimDataSeg[TW_MAX_PLAYLIST_ANIM_SEGMENTS];
	PlayList *ParamPlayList;
}TW_VIEW_ANIMATED_PARAM;
#define TW_MAX_VIEW_ANIM_PARAMS 8

#define MAX_ANIM_FRAMES (15*30)
//---------------------------------------------------------
#define MAX_ANIM_VS_FLIPBOOK_STAGES 32
typedef struct
{
	DWORD ActiveStartField;	//first field to start playing
	DWORD ActiveFieldDuration; //
	int EffectType;

	//src region in CG edit screen
	int EditScreenRectLeft;
	int EditScreenRectTop;
	int EditScreenRectWidth;
	int EditScreenRectHeight;

	int CurrentEffectTimeFrame; //a TIME value
	int EffectActiveTimeFrames; //a TIME VALUE
	int CurrentEffectImageFrame; //current IMAGE frame of effect (Could have fewer images than time would suggest for var. frame rate support)
	int ViewBigBitmapDestY;	//update offset for stacked bitmaps to trinity

	int ViewBitMapTotWidth[NUM_VIEWTYPES];
	int ViewBitMapTotHeight[NUM_VIEWTYPES];
	int ViewImageFrameCount[NUM_VIEWTYPES];
	BYTE RelFrameStoresBitmap[MAX_ANIM_FRAMES];



	//Trinity resources
	DWORD ViewPort[NUM_VIEWTYPES];
	DWORD ViewBitMap[NUM_VIEWTYPES];

	TW_VIEW_ANIMATED_PARAM ViewAnimParam[NUM_VIEWTYPES][TW_MAX_VIEW_ANIM_PARAMS];
	
	int VS_FlipbookSwitchToNextVal_TimeEntries;
	int VS_FlipbookSwitchToNextVal_TimeList[MAX_ANIM_VS_FLIPBOOK_STAGES];

	//CG resources
	long MasterSrcWB; //ACG work buffer index (!=0)
	int DoFade;
	//...The one or more needed playlists will be handled in code
}TW_FLIP_ANIM_VIEW_INFO;


//---------------------------------------------------------
class TWVpAnim
{
	public:

	int CurrentAnimModifiedCount;
	int LastRenderedAnimModifiedCount;
	DWORD LastRenderDocModifiedCount;

	TWVpAnim();
	~TWVpAnim();
	void Reset(void);
	void ReleaseResources(void);
	void ReleaseSourceBitmaps(void);
	void CalcTrinDisplayBitMapAllocSize(int EffectType,int FrameImageCount,int FrameWidth,int FrameHeight,int *D1BitmapWidth,int *D1BitmapHeight,int *AlphaBitmapWidth,int *AlphaBitmapHeight);
	int CalcEffectImageFrames(int GroupInd,int EffectType,int AnimFieldDuration);

	int AddViewRect(int EditLeft,int EditTop,int EditWidth,int EditHeight,int D1BitmapWidth,int D1BitmapHeight,int AlphaBitmapWidth,int AlphaBitmapHeight);
	void SetRectEffectInfo(int ViewRectInd,int EffectType,int StartField, int FieldDuration,int FadeEnable);
	void SetActivePlayListParam(int ViewRectInd,int View,tagETrnViewPortParams ViewParamType,int ValStart,int ValInc,int FieldDuration);
	void SetActivePlayListParam(int ViewRectInd,int View,tagETrnViewPortParams ViewParamType,int *ValueList,int FieldDuration);
	void SetActivePlayListFlash(int ViewRectInd,int View,int FlashPeriodFields,int FieldDuration);

	void SetActivePlayListParamMapTable(int ViewRectInd,int View,tagETrnViewPortParams ViewParamType,int *MapTable,int TableEntries);
	void AnimSTDPanBitmap(int ViewRectInd,int Direction_0246,int StartPos,int EndPos,int FieldPreDelay,int FieldPostHold,int FieldDuration,BOOL AccelEnable,BOOL IsOnTransition);
	void AnimSTDVerticalFrameFlip(int ViewRectInd,int FlipFrameHeight,int FieldPreDelay,int FieldPostHold,int FieldDuration,BOOL ForwardDirection);
	void AnimMeteredVerticalFrameFlip(int ViewRectInd,int FlipFrameHeight,int UniqueFrameCount,int FieldPreDelay,int FieldPostHold,int ActiveFieldDuration,BOOL ForwardDirection);
	void PrependPlayListParamHold(int ViewRectInd,int View,tagETrnViewPortParams ViewParamType,int HoldValue,int FieldDuration);

	void AppendPlayListParamHold(int ViewRectInd,int View,tagETrnViewPortParams ViewParamType,int HoldValue,int FieldDuration);

	void CalcCubicAccelerationTable(float ValSpan,int Entries,float *ValTbl);
	void LoadCubicPositionTbl(float ValSpan,int Polarity,int TblEntries,float *Tbl,int FillDirection);
	void FillHorizMoveAccelPosAnd4HalfPixShiftBufferTbls(int *PositionTblFix,int *SubShiftBufferIndTbl,int ValRange,int TableEntries,int ForwardDirection);
	void AnimUseTblVerticalFrameFlipAndPos(int ViewRectInd,int FlipFrameHeight,int FlipFrameImages,int *iPositionTable,
				int *iBufferIndTable, int FieldPreDelay,int FieldPostHold,int FieldDuration,BOOL ForwardDirection);
	void AnimStaggeredVerticalFrameFlipEarlySetup(int ViewRectInd,int NumFlipImages);
	void AnimStaggeredVerticalFrameFlipLateSetup(int ViewRectInd);
	
	void AdjustEffectExtent(int EffectType,int *ExtentX0,int *ExtentY0,int *ExtentX2,int *ExtentY2);


	STrnPlayList *GenSTrnPlayListFromTbl(int *val_tbl,int tbl_elements);
	STrnPlayList *GenSTrnPlayListRamp(int StartVal,int IncVal,int Count);

	void GenProgressiveValTable(int StartVal,int IncVal,int UniqueEntries, BOOL DuplicateVals,int **ResultTbl);
	void GenStaggeredValTable(int IncVal,int *SwitchToNextVal_TimeList,int SwitchToNextVal_TimeEntries,int ResultListEntries,int **ResultTbl);


	int GetTeletypeCharCount(int ViewRectInd);
	BOOL TeletypeStageGenMasterSrcBitmap(int ViewRectInd,int MaxTeletypeCharsVisible);

	void PerspectiveMapWB(long SrcWB,
		float fXTrans,float fYTrans,float fZTrans,
		float fXRot,float fYRot,float fZRot,
		float fZoom,float fFocal,int FieldMask,
		BOOL InPlaceMode,
		long DestWB);

	void SetPlayDuration(int TotalEffectDurationFields); //including hold time

	BOOL GenAllMasterSrcBitmaps(void);
	BOOL RenderSrcUnassignedObjectsBitmap(GfxBuf *DestGfxBuf);
	BOOL RenderConvAndSendAnimEffectBitmaps(void);
	BOOL SnapshotCompositeToBackground(TW_FLIP_ANIM_VIEW_INFO *AVR,GfxBuf *CompositeBuffer,int PageAnimFrame);
	BOOL LoadPlaylists(void);
	BOOL AllocDisplay(void);
	void DoAnim(void);

	private:

	int NumViewRects;
	int TotalEffectDurationFields;
	int TotAnimBitmapCount;
	int TotAnimBitmapBytes;
	TW_FLIP_ANIM_VIEW_INFO TWAnimViewRect[MAX_TW_ANIM_RECTS];

	BOOL GenMasterSrcBitmap(int ViewRectInd);
	BOOL GenEffectFrameBitmaps(int ViewRectInd); //animation frames
	BOOL GenEffectFrameBitmap(int ViewRectInd,int ActiveField,int TotActiveFields,long *WorkBufferInd);

};

#endif
