#ifndef _GfxBufDefined

class CG_Rotate;
class GfxBuf;

typedef struct
{
	BOOL HasPictureInfo;
	char FileName[256];
	int FileWidth;
	int FileHeight;
	int FileHasAlpha;
	float fImportScaleX;
	float fImportScaleY;
	int ImportWidth;
	float ImportHeight;
	BOOL ImportUseFileAlpha;
	BOOL ImportInvertAlpha;
	BOOL ImportBlackTrimEnable;
	float ImportBlackTrimLevel;

}PIC_BUFFER_INFO_TYPE;


typedef struct
{
	int lin_mat_entries;
	int lin_mat_i[16];
	double lin_mat_f[16];
	double pass1_lin_mat_f[16];
	double lin_mat_factor_sum_f;
	double lin_mat_factor_scale_f; //to scale horiz multiplier values to produce 0..255 result
	int pass1_src_scale_tbl[256][16];
	int matrix_width;
	int matrix_half_width;
	DWORD *pass1_padded_src_line_ptr;
	int pass1_src_addr_inc;
	int *pass1_accum_buffer_ptr;
	int pass1_accum_right_side_offset;
	int pass1_dest_columns;
	int pass1_dest_rows;
	//long pass1_accum_work_buffer;
	GfxBuf* pass1_AccumGfxBuf;
	int accum_buffer_width;
	int accum_buffer_height;

	DWORD *pass2_accum_src_ptr;
	DWORD *pass2_accum_dest_ptr;
	int pass2_src_addr_inc;
	int pass2_dest_addr_inc;
	int pass2_accum_bottom_side_offset;
	int pass2_dest_columns;
	int pass2_dest_rows;

	int pass2_src_y;
	int pass2_dest_y;
}CG_FILTER_INFO;

//KEEP THESE AS BYTE OFFSETS: i.e. BGRA LSByte=0 (BLUE)
#define CHAN_BASE_ID			0
#define CHAN_BLUE_ID			0
#define CHAN_GREEN_ID			1
#define CHAN_RED_ID				2
#define CHAN_VIDEO_ID			3

#define MAX_GFXBUF_AUX_NAME_WIDECHARS 64

typedef DWORD CLIP_OUTCODE;
enum {CLIPTOP=0x1,CLIPBOTTOM=0x2,CLIPRIGHT=0x4,CLIPLEFT=0x8};

#define MAKE_BGRA32(b,g,r,a) ( (DWORD)b | ((DWORD)g<<8) | ((DWORD)r<<16) | ((DWORD)a<<24) )

#define DEG_TO_RAD	((double) 0.01745329277778)

#include "ACGS_Inc//CG_ColorBox.h"
#include "ACGS_Inc//CG_MappingFrame.h"

class GfxBuf
{

public:

#if !LINUX_PLATFORM
	friend class CG_Rotate;
#endif
	static int GfxBufBytesAllocated; //keep track of tot allocated size
	static int GfxBufBytesAllocatedMax; //keep track of tot allocated size
	static int GfxBufCount; //keep track of tot allocated
	//-------------------------------------
	HBITMAP DIBHBitmap;
	BITMAPINFOHEADER DIBBitmapInfoHeader;

	BYTE *BufferPtr;
	int BufferBytes;

	int PixelWidth;
	int PixelHeight;
	int ByteMod; //bytes between scanlines
	int BytesPerPix; //all 8bit or 32bit for now
	int BitsPerPix; //all 8bit or 32bit for now
	int ClipRegionLeft;	//inclusive clipping region 
	int ClipRegionRight;
	int ClipRegionTop;
	int ClipRegionBottom;

	double HandleX;//i.e. center point handle
	double HandleY;//i.e. center point handle
	BOOL HasUserManagedMemory;	//

	//-------------------------------------
	DWORD AllocatedFlag;
	
	DWORD UniqueID;//for link list reference


	//-------------------------------------
	DWORD ReferenceCount;

	OBJ_MAPPING_FRAME ContentIntAlignedMappingFrame;//OPTIONAL, i.e. 3D perspective frame enclosed within the GfxBuf, used for face and edge texture buffer generation (values compared in style cache)

	PIC_BUFFER_INFO_TYPE PictureBufferInfo;
	COLOR_SPREAD_DETAILS ContentColorSpreadDef;//OPTIONAL, used for face and edge texture buffer generation (values compared in style cache)

	//-------------------------------------
	//optional buffer (used for view cursor drawing) for pixel save/restore opterations with line draw 
//	//(memory saving alternative to using a separate full-size master buffer)
	int PixelSaveBufferDwordCount;
	int PixelSaveBufferMaxDwords;
	DWORD* pPixelSaveBuffer;

	BOOL bHasCriticalSection;
	CRITICAL_SECTION Buffer_CriticalSection;
	BOOL bMutexWatch;

	//FILTER functions
	//CG_FILTER_INFO* pFilterInfo;

	DWORD Padding[2];//NOTE Microsoft bug, this must be here, else will crash after writing to ContentIntAlignedMappingFrame
	//-------------------------------------
//	CG_Rotate *RotFn; //rotation function access

	//-------------------------------------
	//create a GfxBuf, allocate memory, copy graphics from graphics from memory SrcBuffer
	GfxBuf(BYTE *SrcBuffer,int PPixelWidth,int PPixelHeight,int PBitsPerPix, char *MsgString);
	//-------------------------------------
	//create GfxBuf, allocate memory
	GfxBuf(int PixelWidth,int PixelHeight,int BitsPerPix,char *MsgString);
	//-------------------------------------
	//same as above but init with a fill value
	GfxBuf(int PPixelWidth,int PPixelHeight,int PBitsPerPix, DWORD FillValue,char *MsgString);
	//-------------------------------------
	//SPECIAL: create GfxBuf, do not alloc memory, assign BufferPtr to UserManagedMemoryBuffer
	GfxBuf(int PPixelWidth,int PPixelHeight,int PBitsPerPix,BYTE *UserManagedMemoryBuffer);
	//-------------------------------------
	~GfxBuf();
	//-------------------------------------
	void AllocPixelSaveBuffer(DWORD inPixelCapacity);//optional for line draw pixel save restore buffering (i.e. for cursor drawing)
	void RestoreSavedPixelsFromBuffer(void);//function to restore pixels from save buffer
	void ResetSavedPixelsBuffer(void);//resets the store count to 0 ,empties pixel info buffer
	//-------------------------------------
	void AllocBufferMutex(void);
	void BufferMutexOwn(void);
	void BufferMutexRelease(void);

	//-------------------------------------
	BYTE *GetPixelAddr(int X,int Y);
	//-------------------------------------
	BYTE *GetChannelAddr(int X,int Y,int Channel); //i.e. get byte address of GREEN_CHAN_ID component of pixel (x,y)
	//-------------------------------------
	void SetClipRegion(int XLeft,int YTop,int XRight,int YBottom);
	//-------------------------------------
	void SetDefaultHandle(void);
	//-------------------------------------
	void CheckAllocLimits(void);
	//-------------------------------------
	//-------------------------------------

	//-------------------------------------
	//Graphics Copy/Move/Fill functions
	//-------------------------------------
	void CopyGfxBufTo(GfxBuf *pDestGfx);
	//-------------------------------------
	BOOL CopyChannelPatch(GfxBuf *pSrcGfxBuf,int SrcChannelID,int SrcRectX,int SrcRectY,
		int CopyWidth,int CopyHeight,GfxBuf *pDestGfxBuf,int DestChannelID,int DestX,int DestY);
	//-------------------------------------
	BOOL CopyPatch(GfxBuf *pSrcGfxBuf,int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,
		GfxBuf *pDestGfxBuf,int DestX,int DestY);
	//-------------------------------------
	BOOL CopyPatchWithMask32(GfxBuf *pSrcGfxBuf,int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,
		GfxBuf *pDestGfxBuf,int DestX,int DestY,DWORD SrcBGRAMask32);
	//-------------------------------------
	void Clear(DWORD Color);
	//-------------------------------------
	void FillPatch(int DestX,int DestY,int FillWidth,int FillHeight,DWORD Color);
	//-------------------------------------
	BOOL FillPatchWithMask32(int DestRectX,int DestRectY,int CopyWidth,int CopyHeight,DWORD ColorBGRA32, DWORD Mask32);
	//-------------------------------------
	void FillChannelPatch(int ChannelID,int DestX,int DestY,int FillWidth,int FillHeight,BYTE Color);
	//-------------------------------------
	void CopyPicComponentToChannel(
		BYTE *SrcPtr,
		int SrcBytesPerPix,
		int ChannelID,
		int DestY,
		int FillWidth);
	//-------------------------------------
	void FillCheckerboard(
		DWORD Blue1,
		DWORD Green1,
		DWORD Red1,
		DWORD Blue2,
		DWORD Green2,
		DWORD Red2,
		int CheckerWidth,
		int CheckerHeight);
	//-------------------------------------

	//-------------------------------------
	//Graphics OP functions
	//-------------------------------------
	void ChannelOP_Invert(int ChannelID);
	//-------------------------------------
	void ChannelOP_StampHole32(
		GfxBuf *pSrcGfxBuf,int SrcStencilChanID,
		int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,
		GfxBuf *pDestGfxBuf,int DestChanID,
		int DestX,int DestY);
	//-------------------------------------
	BOOL StampInvertedHoleInChan(GfxBuf *pSrcGfxBuf,int SrcChannelID,int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,
		GfxBuf *pDestGfxBuf,int DestChannelID,int DestX,int DestY);
	//-------------------------------------

	BOOL PlotMaxPatch(GfxBuf *pSrcGfxBuf,int SrcChannelID,int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,
		GfxBuf *pDestGfxBuf,int DestChannelID,int DestX,int DestY);
	//-------------------------------------
	BOOL ProcessFlickerFilter(int ProcessTopY,int ProcessHeight);
	//-------------------------------------
	BOOL FindActiveAlphaRect(int *ActiveX,int *ActiveY,int *ActiveWidth,int *ActiveHeight);
	//-------------------------------------
	BOOL CheckSolidKey32(void);
	
	BOOL CheckPatchForColor(
		int DestX,int DestY,
		int FillWidth,int FillHeight,DWORD Color);//Scan buffer region, check for all pixels match Color (used for mask in priority based selection )
	//-------------------------------------
	void DoEdgeAntiAlias(int x0,int y0,int width,int height);
	//-------------------------------------
	void AntiAliasChannel(int chan_id);
	//-------------------------------------
	void DoBlackTrim(unsigned char bg_red,unsigned char bg_green,unsigned char bg_blue,int tolerance_255);
	//-------------------------------------
	void ApplyRGBGamma(int X,int Y,int Width,int Height,double Gamma);

	//Buffer analysis ---------------------
	BOOL IsBlankBGRA(void);
	//-------------------------------------
	
	//SHIFTING FUNCTIONS ------------------
	void VScroll(int Delta);
	void HScroll(int Delta);
	void RenderSubPixelScanline(DWORD *line0_ptr,DWORD *line1_ptr,DWORD *dest_ptr,double f_sub_shift,int pixel_count,int src_mod,int dest_mod);
	void CopyWithVertSubPixelShift(int region_x,int region_y,int region_width,int region_height,double dOffset,GfxBuf* DestGfxBuf,DWORD dest_lines_mask);
	void CopyWithHorizSubPixelShift(int SrcRegionX,int SrcRegionY,int region_width,int region_height,double dOffset,GfxBuf* DestGfxBuf,DWORD dest_lines_mask);


	//BLENDING FUNCTIONS ------------------
	void BlendBGRA32_To_BGR32Mem(int SrcX,int SrcY,int CopyWidth,int CopyHeight,int SrcByteAdvance,BYTE *DestMem,int DestByteAdvance);
	void BlendBGRA32(int SrcX,int SrcY,int CopyWidth,int CopyHeight,GfxBuf *DestGfxBuf,int DestX, int DestY);
	void ReplaceOrBlendBGRA32(int SrcRectX,int SrcRectY,int CopyWidth,int CopyHeight,GfxBuf *pDestGfxBuf,int DestX,int DestY);
	void MultiplyAlphaByVal(int Value255);
	void MultiplyAlphaByMask(GfxBuf* SrcMaskGfxBuf,int DestX,int DestY);

	//YUV FUNCTIONS -----------------------
	void ConvCbYCrYMemToBGRA(BYTE *ComponentBuffer,int DestTopScanline,int Width,int Height,int SrcByteMod,int DestAdvanceByteMod);
	void DoCbYCrY_ConversionTbl_Setup(void);

	void BlendCbYACrYA_To_CYMem(int SrcX,int SrcY,int CopyWidth,int CopyHeight,int SrcByteAdvance,BYTE *DestMemYC,int DestByteAdvance);
	void CopyConvBGRAToOverlayCbYACrYA(int SrcX,int SrcY,GfxBuf *GfxBufYC,int DestX,int DestY,int ConvWidth,int ConvHeight);
	void BGR2YCx256DoSetup(void);
	void GenFastReducedCbYCrY_288(BYTE *SrcCYPtr,int SrcHeight);
	void FastReduceLineCbYCrY_288(BYTE *SrcCYPtr,int SrcByteStride,BYTE *DestCYPtr,int DestByteStride,DWORD DestWidth,DWORD DestHeight);

	//0ne bit per pixel image reducion (anti-aliasing) functions
	void ReduceBitplane8to1Alpha(BYTE* pBitplane,int inBitplaneByteWidth,int inDestPixelWidth,int inDestPixelHeight,BOOL inbVerticalInvert);

	//-------------------------------------
	//Font Utility functions for UI text plotting
	//-------------------------------------
	GfxBuf* GetTextBuffer(WCHAR* inWCStr,char* inFontName,int inBitmapWidth,int inBitmapHeight);

	BOOL GetBigFontBMP(WCHAR* WCStr,		// String to be displayed in control
						 char *Font_name,	// Name of font, i.e. "Arial"
						 double inFontHeightScale,
						 HDC     FontHDC,	// Device context containing selected font
						 long    Bmp_width,	// Desired width of bitmap
						 long    Bmp_height,// Desired height of bitmap
						 void  **DibBits,   // Pointer to the DIB bits (return to caller).
						 BITMAPINFO **P_BMI);// Pointer to the DIB header (return to caller).
	
	void CreateLogicalFont(
								WCHAR* WCStr,		// String to display in control
								char *Font_name,	// Name of a font, i.e. "Arial"
								double inFontHeightScale,
								long    Control_Width,
								long    Control_Height,
								BOOL    AutoScaling,// TRUE for automatic font width scaling
								HDC    *Hdc,		// Device context to create font for
								HFONT  *Hfont);		// HFONT to be returned to caller

	//-------------------------------------
	//Utility functions
	//-------------------------------------
	BOOL CalcClippedSrcDestRect(
		GfxBuf *SrcGfxBuf,
		int SrcRectX0,int SrcRectY0,
		GfxBuf *DestGfxBuf,
		int PlotDestX,int PlotDestY,
		int PlotWidth,int PlotHeight,
		int *ClippedSrcX0,int *ClippedSrcY0,
		int *ClippedDestX0,int *ClippedDestY0,
		int *ClippedWidth,int *ClippedHeight,
		BOOL ApplyDestClipRect);


	//-------------------------------------
	//Line Primitive Functions
	//-------------------------------------
	void SetPixel32(int DestX,int DestY,DWORD Color);//assumes clipped coords
	//-------------------------------------
	void MoveTo(int DestX,int DestY);
	//-------------------------------------
	void LineTo(int DestX,int DestY,DWORD Color);
	//-------------------------------------
	void DrawLine(double X0,double Y0,double X1,double Y1,DWORD Color);
	void DrawLine(int X0,int Y0,int X1,int Y1,DWORD Color);
	void DrawZigZagLine(double X0,double Y0,double X1,double Y1, DWORD Color,double Amplitude);
	void DrawLineBlend(int X0,int Y0,int X1,int Y1,DWORD Color,GfxBuf* BackgroundSrcBuf);//draw a line by reading pixels from BackgroundSrcBuf, blending with color, and writing to this

	//-------------------------------------
	//special functions to draw eraseable cursor segments onto view buffer
	void DrawLineSavePixels(int X0,int Y0,int X1,int Y1,DWORD Color);
	void DrawZigZagLineSavePixels(double X0,double Y0,double X1,double Y1, DWORD Color,double Amplitude);

	//-------------------------------------

	//-------------------------------------
	//Cloning/Scaling functions
	//-------------------------------------
	GfxBuf* MakeClone(void);
	GfxBuf* MakeUpsideDownClone(void);
	GfxBuf* MakeScaledClone(float HScale,float VScale);
	GfxBuf* GfxBuf::MakeFactorOfTwoReducedClone(int inFactorOfTwoReductions);

	//-------------------------------------
	//-------------------------------------
	GfxBuf* MakeGrayScaleClone8(void);
	//-------------------------------------
	void ConvertToGrayScale(void);
	//-------------------------------------
	void FlipVertical(void);
	//-------------------------------------
	//-------------------------------------
	//-------------------------------------
	//Display functions for UI or diagnostics
	void Display(HWND inDestHwnd,int DestX,int DestY);
	void DisplayAlpha(DWORD inDW_DestHwnd,int DestX,int DestY);

	//-------------------------------------
	//Warping Functions
	void BookPerspective(int cols, int rows,
			double x0, double y0, double x1, double y1,
			double x2, double y2, double x3, double y3);

	
	//-------------------------------------
	//Math functions
	void RotatePoint(double *xr,double *yr,double rotation_degrees);
	void RotatePointCenter(double *xr,double *yr,double center_x,double center_y,double rotation_degrees);
	void CalcSegExtendOutEndpoint(double x0,double y0,double x1,double y1, double extend_length,double *end_x,double *end_y);
	void CalcColinearVector(double x0,double y0,double x1,double y1, double new_length,double *end_x,double *end_y);
	void CalcSegExtendInEndpoint(double x0,double y0,double x1,double y1, double extend_length,double *end_x,double *end_y);
	double CalcSegLength(double x0,double y0,double x1,double y1);
	void CalcSegOppositeCorner(double x0,double y0,double x1,double y1,double x2,double y2,double *end_x,double *end_y);
	void CalcRightTangentSeg(double x0,double y0,double x1,double y1, double tangent_length,double *end_x,double *end_y);
	void CalcLeftTangentSeg(double x0,double y0,double x1,double y1, double tangent_length,double *end_x,double *end_y);

	//-------------------------------------
	//Testing functions 
	//-------------------------------------
	//Area refresh management functions, used for document thread write,  Controlled by mutex
	void AddPendingRefreshArea(int inLeft,int inTop,int inRight,int inBottom);
	BOOL GetPendingRefreshArea(int* pLeft,int* pTop,int* pRight,int* pBottom);//returns true if there is a region to plot
	//-------------------------------------
	//FILTER PROCESSING FUNCTIONS
	void FILTER_ModeInit(void);
	void FILTER_MatrixSet(int *lin_sym_mat_tbl,int mat_entries);
	void FILTER_MatrixScale(int *lin_sym_mat_tbl,int mat_entries,int scale_255);
	void FILTER_MatrixProcessHorizLine(void);
	void FILTER_MatrixProcessHorizPass(GfxBuf* SrcGfxBuf,int src_x,int src_y,int src_width,int src_height);
	void FILTER_AlphaBlurFromAlphaShape(GfxBuf* SrcGfxBuf,GfxBuf** ReturnGfxBuf,int *linear_filter_ptr,int linear_filter_width,int pass2_weight_255);
	void FILTER_MatrixProcessVertPass(void);
	void FILTER_MatrixProcessVertLine(void);


	//-------------------------------------
	//Special pattern functions
	void GfxBuf::FillTestPatterColorBars75(void);
	void GfxBuf::TestPatternLumaBars(void);

	//-------------------------------------
	//EXTRA info (i.e. picon header)
	void SetPrivateData(void* inpPrivateData);
	void* GetPrivateData(void);
	//-------------------------------------
	//-------------------------------------

private:
	//for multi thread
	BOOL bPendingRefreshAreaValid;
	int PendingRefreshAreaTop;
	int PendingRefreshAreaBottom;
	int PendingRefreshAreaLeft;
	int PendingRefreshAreaRight;

	//-------------------------------------
	//EXTRA info (i.e. picon header)
	void *pPrivateData;

	//-------------------------------------
	void CommonInit(void);
	//-------------------------------------
	BOOL AllocDIB(int PPixelWidth,int PPixelHeight,int PBytesPerPix,DWORD ClearValue);
	//-------------------------------------
	void FreeDIB(void);
	//-------------------------------------
	void FastMemCopySrcDest(void *SrcPtr,void *DestPtr,int TotBytes);
	//-------------------------------------
	void FastDwordClear(DWORD ClearValue);
	//-------------------------------------
	//-------------------------------------
	//-------------------------------------
	//ANTIALIAS FUNCTION SUPPORT
	void TrimBg(
		int bg_red,
		int bg_green,
		int bg_blue,
		int tolerance_255);
	void WritePixA(short x,short y,long val);
	void AntaliHFillIn(int run_end_x,int y,int xinc);
	void AntaliHLine(int y,int x0,int width,int direction);
	void AntaliVFillIn(int run_end_y,int x,int yinc);
	void AntaliVLine(int x,int y0,int height,int direction);
	void AntaliVert(int x0,int y0,int width,int height);
	void AntaliHoriz(int x0,int y0,int width,int height);

	//LINE DRAWING SUPPORT (Line,LineTo, etc support)
	int PenX,PenY;
	BOOL ClipLine(
		double *x0,
		double *y0,
		double *x1,
		double *y1,
		double xmin,
		double xmax,
		double ymin,
		double ymax);
	CLIP_OUTCODE CompClipOutCode(double x,double y,double xmin,double xmax,double ymin,double ymax);

	//Table to control rgb weighting during plot alpha blending when (esp 2 or more) semi-transp pixels overlap, RGB blend must be proportionally weighted
	void Initialize_PlotWeightRGB_DivToMulTbl(void);

};


//#include "cg_rotate.h"

GfxBuf* GetBitplaneReducedTextBuffer(WCHAR* inWCStr,char* inFontName,int inBitmapWidth,int inBitmapHeight, double inFontHeightScale);

#define _GfxBufDefined
#endif
