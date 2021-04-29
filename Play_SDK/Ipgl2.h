//=============================================================================
// IPGL2.h
// Copyright 1998 Play Incorporated
//
// NOTE:
//
//	PDS2 main change is to support nested region
//
//	PGL also need a L2 cache feature for unbufered mode... the size of the TEMP
//	rasterizer buffer should be 128x128 (16K pixel) with a <=256K L2 cache
//	But the buffer should be 256x256 (65K pixel) with a >256K L2 cache.
//	for an RGB16 rasterizer only <=128K L2 cache system will
//	fall back to a 128x128 render cache.
//
// Created 1998 by Stephan Schaem
//=============================================================================
#ifndef IPGL2_H
#define IPGL2_H

#include <PlayInc.h>
#include <toolbox.h>

// PGL server implementation (See corresponding interface)
extern "C" const GUID CLSID_PGL2;
extern "C" const GUID CLSID_PIMG2;
extern "C" const GUID CLSID_PDS2;
extern "C" const GUID CLSID_PGLR2_RGB24;
extern "C" const GUID CLSID_PGLR2_RGB16;
extern "C" const GUID CLSID_PGLR2_RGBx32;
extern "C" const GUID CLSID_PGLR2_RGBA32;

extern IUnknown* __stdcall g_CLSID_PGL2();
extern IUnknown* __stdcall g_CLSID_PIMG2();
extern IUnknown* __stdcall g_CLSID_PDS2();
extern IUnknown* __stdcall g_CLSID_PGLR2_RGB24();
extern IUnknown* __stdcall g_CLSID_PGLR2_RGBx32();

// ------------------------------------------------------------------------------

typedef struct {
	long	ox, oy;								// Original		16:16 fixpoint
	long	tx, ty;								// Translated	16:16 fixpoint 
} PGLTP;

typedef struct {
	long	x1, y1;
	long	x2, y2;
} PGLRECT;

typedef struct {
	short	x1, y1;
	short	x2, y2;
} PGLRECTI;

typedef struct {
	union {
	ulong	rgba;
	struct {
		uchar	a, b, g, r;						// 'Intel' byte ordering
	} c;
	};
} PGLCOLOR;

typedef struct {
	long	x, y;								// 32:0
	PGLCOLOR	c;								// alpha valid
} PGLCP;

enum PGLBITMAP_TYPE {
	PGLBITMAP_TYPE_UNKNOW,
	PGLBITMAP_TYPE_RGB24,
	PGLBITMAP_TYPE_RGBA32,
	PGLBITMAP_TYPE_RGB16,						// 16bit per pixel, 5:6:5	R:G:B
	PGLBITMAP_TYPE_RGB15,						// 16bit per pixel, 1:5:5:5	A:R:G:B
	PGLBITMAP_TYPE_RGBx32,						// x is undefined.
	PGLBITMAP_TYPE_A8,							// 8bit Transparency level
	PGLBITMAP_TYPE_INDEX8,						// 8bit palette index
	PGLBITMAP_TYPE_SIZE,
};

typedef struct {
	PGLBITMAP_TYPE type;						// See: PGLBITMAP_TYPE
	short	w, h;								// Pixel size
	uchar	*byte;								// Pointer to pixel array
	long	rbs;								// Row Byte Size
} PGLBITMAP;									// 16 bytes

			
// -- IPGLR2 --------------------------------------------------------------------
extern "C" const GUID IID_IPGLR2;

typedef struct {								// Color Fill
	// Destination Info						
	uchar	*dp;								// Data Pointer
	long	rbs;								// Row Byte Size
	ulong	w;									// Width of copy (in pixel)
	ulong	h;									// Height of copy (in pixel)
	// Source Info							
	PGLCOLOR color;								// See: PGLCOLOR
} PGLBOX;										// 20 bytes
											
typedef struct {								// Integer positioning, no scaling (Simple Blit)
	// Destination Info						
	uchar*	dp;									// Data Pointer
	long	drbs;								// Row Byte Size
	ulong	w;									// Width of copy (in pixel)
	ulong	h;									// Height of copy (in pixel)
	// Source Info							
	uchar*	sp;									// Data Pointer
	long	srbs;								// Row Byte Size
} PGLSBLIT;										// 24 bytes							

typedef struct {								// Pattern Blit (Based on Simple Blit)
	// Destination Info						
	uchar*	dp;									// Data Pointer
	long	drbs;								// Row Byte Size
	ulong	w;									// Width of copy (in pixel)
	ulong	h;									// Height of copy (in pixel)
	// Source Info							
	uchar*	sp;									// Data Pointer
	long	srbs;								// Row Byte Size
	// Pattern Info
	long	sx, sy;								// Start X & Y offset in source
	long	sw, sh;								// Source Width & Height
} PGLPBLIT;										// 40 bytes								
											
typedef struct {								// Subpixel positioning with scaling (Based on Simple Blit)
	// Destination Info						
	uchar*	dp;									// Data Pointer
	long	drbs;								// Row Byte Size
	ulong	w;									// Width of copy (in pixel)
	ulong	h;									// Height of copy (in pixel)
	// Source Info							
	uchar*	sp;									// Data Pointer
	long	srbs;								// Row Byte Size
	// Scaling Info
	ulong	spx;								// SubPixel XPos
	ulong	spy;								// subPixel YPos
	ulong	sdx;								// Scale X Factor (% * 65536 * 65536) (ex: .5 = 0x80000000 )
	ulong	sdy;								// Scale Y Factor (65536 * 65536 / %) (ex: 1.5 = 0xAAAAAAAA )
} PGLBLIT;										// 40 bytes

typedef struct {								// 4 corner linear RGBA color box shading
	long	w, h;								// width, height of box
	long	av, rv, gv, bv;
	long	dah, drh, dgh, dbh;
	long	dav, drv, dgv, dbv;
	long	ddah, ddrh, ddgh, ddbh;
} PGLGBOX;										// 72 bytes

typedef struct {
	long	etx1p;								// Destination edge X pos
	long	etx2p;								// Destination edge Y pos
	long	etx1s;								// Destination edge X step
	long	etx2s;								// Destination edge Y step
	long	eox1p;								// Source edge X pos
	long	eoy1p;								// Source edge Y pos
	long	eox1s;								// Source edge X step
	long	eoy1s;								// Source edge Y step 
	uchar*	src;								// source pointer
	uchar*	dst;								// Destination pointer
	long	srbs;								// Source Row byte size
	long	drbs;								// Destination Row byte size
	long	soxs;								// Source scanline X step
	long	soys;								// Source scanline Y step
	long	count;								// height of trapezoid
} PGLTRAP;										// 60 bytes

struct IPGLR2 : public IUnknown {

	// Managment
	virtual void __stdcall GetBPP(long*)=0;

	// Pattern Blit
	virtual void __stdcall Pat_RGB(PGLPBLIT*)=0;
	virtual void __stdcall Pat_ARGB(PGLPBLIT*)=0;

	// Color Blit
	virtual void __stdcall Box_ARGB(PGLBOX*)=0;
	virtual void __stdcall Box_RGB(PGLBOX*)=0;
	virtual void __stdcall GBox_RGB24(uchar* dst, long rbs, PGLGBOX*)=0;
	virtual void __stdcall GBox_RGBA32(uchar* dst, long rbs,PGLGBOX*)=0;
	virtual void __stdcall GBox_A8(uchar* dst, long rbs, PGLGBOX*)=0;

	// Bitmap Blit
	virtual void __stdcall Blit_RGB_S(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SA(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_ZA(PGLBLIT*)=0;
	virtual void __stdcall Blit_ARGB(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_Z(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SAX(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SXA(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SYA(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SX(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_SY(PGLBLIT*)=0;
	virtual void __stdcall Blit_RGB_A(PGLBLIT* , ulong a)=0;
	virtual void __stdcall Blit_A(PGLBLIT*)=0;
	virtual void __stdcall Blit_A_C(PGLBLIT* p_blit, PGLCOLOR color) =0;

	// Misc Rendering
	virtual void __stdcall Line(uchar* buffer, long rbs, long x1, long y1, long x2, long y2, PGLCOLOR c)=0;
	virtual void __stdcall Rect(uchar* buffer, long rbs, PGLRECT* rect)=0;
	virtual void __stdcall Trapezoid_RGB24_A(PGLTRAP*)=0;




	// Misc
	virtual HRESULT	__stdcall Resample(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall BlurArea24(PGLBITMAP *src, PGLBITMAP *dst, int kw, int kh)=0;
	virtual HRESULT __stdcall PCI_INDEX8_BlitRGB(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall PCI_Blit(void *p_src, void *p_dst, long p_w, long p_h, long p_modulos, long p_modulod)=0;
	virtual HRESULT __stdcall RGB_PTest(uchar *,long, long,long, long, long *)=0;
	virtual HRESULT __stdcall RGB_ScaleRGB(uchar *source, uchar **dest, long srbs, long ox, long oy, long dx, long dy, long flag)=0;
	virtual HRESULT	__stdcall RGB_ResampleARGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;


	// ARGB32 Raterizer
	virtual HRESULT __stdcall ARGB_FillARGB(ulong, uchar *, long, long, long)=0;
	virtual HRESULT __stdcall ARGB_ScaleARGB(uchar *source, uchar **dest, long srbs, long ox, long oy, long dx, long dy, long flag)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBSAX(PGLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBSA(PGLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBZA(PGLBLIT *)=0;
	virtual HRESULT	__stdcall ARGB_ResampleARGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall ARGB_BlitRGBZA(PGLBLIT *)=0;
	virtual HRESULT	__stdcall ARGB_ResampleRGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall ARGB_BlitRGB(PGLBLIT *)=0;

};

// -- IPGL2 --------------------------------------------------------------------
extern "C" const GUID IID_IPGL2;

// -- PGL DISPLAY LIST ----------------------------------

enum PGLDLI_TYPE {								// Display list item types
	PGLDLI_TYPE_UNKNOW,							// Unknowed types result in NOP for that DLI
	PGLDLI_TYPE_CUSTOM,							// Custom rendering
	PGLDLI_TYPE_DL,								// Display list (array of items)
	PGLDLI_TYPE_CDL,							// Display list (array of items) with clipping rectangle
	PGLDLI_TYPE_BOX,							// Color box
	PGLDLI_TYPE_LINE,							// Rename to PGLDLI_TYPE_LINE
	PGLDLI_TYPE_TEXT,							// Rename to PGLDLI_TYPE_TEXT
	PGLDLI_TYPE_CTEXT,							// Clipped Text, See: PGLDLI_CTEXT  ... Rename to PGLDLI_TYPE_CTEXT
	PGLDLI_TYPE_WTEXT,							// Wrapped text, See: PGLDLI_WTEXT
	PGLDLI_TYPE_BITMAP,							// Plain bitmap
	PGLDLI_TYPE_CBITMAP,						// clipped/patterned bitmap
	PGLDLI_TYPE_TBITMAP,						// Tiled bitmap
	PGLDLI_TYPE_GBOX,							// linear shaded box
	PGLDLI_TYPE_HGRID,							// Horizontal lines
	PGLDLI_TYPE_SBITMAP,						// Scaled bitmap
	PGLDLI_TYPE_SFBITMAP,						// Scaled bitmap with filtering
	PGLDLI_TYPE_TRIANGLE,						// Texture mapped triangle
	PGLDLI_TYPE_POLYGON,						// Polygon
};											
			
class PGLDLI_CUSTOM {
public:
	virtual void Render(PGLBITMAP* surface, PGLRECT* clip)=0;
};
											
typedef struct {							
	uchar*	src;								// Source pointer
	long	srbs;								// Source Row byte size
	PGLTP*	a;									// Triangle point A
	PGLTP*	b;									// Triangle point B
	PGLTP*	c;									// Triangle point C
} PGLDLI_TRIANGLE;
											
typedef struct {							
	long	x1,y1;							
	long	w,h;							
	PGLCOLOR	color;							
} PGLDLI_BOX;									// 24 bytes
											
typedef struct {							
	long	x1, y1;							
	long	w, h;							
	long	count;							
	PGLCOLOR	color;							
} PGLDLI_GRID;									// 24 bytes
											
typedef struct {							
	long	x1,y1;							
	long	w,h;							
	PGLCOLOR	color[4];						
} PGLDLI_GBOX;									// 32 bytes
											
typedef struct {							
	long	x1,y1;								// 16:16 Fixpoint
	long	x2,y2;								// 16:16 Fixpoint
	PGLCOLOR	color;							
} PGLDLI_LINE;									// 20 bytes
											
typedef struct {							
	long	x1,y1;							
	long	w, h;							
	HANDLE	font;							
	char	*string;						
} PGLDLI_TEXT;									// 24 bytes
											
typedef struct {							
	long	x1,y1;
	long	w, h;								// String width & height
	HANDLE	font;							
	char	*string;						
	PGLRECT	ir;									// Define the inside rectangle
} PGLDLI_CTEXT;									// 40 bytes
											
typedef struct {							
	long	x1,y1;								// Position of the rectangle defined by ir
	long	w, h;								// String width & height
	HANDLE	font;							
	char	*string;						
	PGLRECT	ir;									// Define the inside rectangle (valid area)
	long	wx1, wx2;							// Left & right edge of text wrapping
} PGLDLI_WTEXT;									// 48 bytes
											
typedef struct {							
	long	x1,y1;							
	PGLBITMAP	bitmap;						
} PGLDLI_BITMAP;								
				
typedef struct {							
	long	x1,y1;							
	PGLBITMAP	bitmap;						
	long	w, h;								
} PGLDLI_TBITMAP;	
							
typedef struct {							
	long	x1,y1;							
	PGLBITMAP	bitmap;						
	PGLRECT	ir;									// Define the inside rectangle, Patterning is acheived when ir > bitmap size
} PGLDLI_CBITMAP;							

typedef struct {							
	long	x1,y1;							
	PGLBITMAP	bitmap;						
	float	hs, vs;								// horizontal & Vertical scaling.
} PGLDLI_SBITMAP;								
											
struct PGLDLI;								

typedef struct {
	long	x1,y1;
	long	w, h;
	long	max;								// Number of possible entry in the items aray
	long	count;								// Valid Entry count in item array
	PGLDLI*	items;							
} PGLDL;										// (7*4) bytes

typedef struct {
	long	x1,y1;
	long	w, h;
	long	max;								// Number of possible entry in the items aray
	long	count;								// Valid Entry count in item array
	PGLDLI*	items;							
	PGLRECT	clip;								// Clipping rectangle
} PGLCDL;										// (11*4) bytes
											
typedef struct PGLDLI {							// Display list item 'header'
	short	type;							
	short	count;							
	union {										// The supported items types
		void*			data;
		PGLDLI_CUSTOM**	custom;
		PGLDL*			dl;
		PGLCDL*			cdl;
		PGLDLI_BOX*		box;
		PGLDLI_LINE*	line;
		PGLDLI_TEXT*	text;
		PGLDLI_CTEXT*	ctext;
		PGLDLI_BITMAP*	bitmap;
		PGLDLI_CBITMAP*	cbitmap;
		PGLDLI_TBITMAP*	tbitmap;
		PGLDLI_GBOX*	gbox;
		PGLDLI_GRID*	hgrid;
		PGLDLI_SBITMAP*	sbitmap;
		PGLDLI_SBITMAP*	sfbitmap;
		PGLDLI_TRIANGLE* triangle;
	};
} PGLDLI;										// 8 bytes

// ------------------------------------
enum PGL_FONT_WEIGHT {							// Font 'thickness'
	PGL_FONT_WEIGHT_THIN = 25,
	PGL_FONT_WEIGHT_NORMAL = 50,	
	PGL_FONT_WEIGHT_BOLD = 75,
};

// ------------------------------------

enum HR_IPGL2 {
	HR_IPGL_WARNING = 0x00000000,
	HR_IPGL_WARNING_SOMETHING,
	HR_IPGL_ERROR = 0xE8210000,
	HR_IPGL_ERROR_ALOCATING_FONT,
	HR_IPGL_ERROR_CREATING_DC,
	HR_IPGL_ERROR_CREATING_FONT,
	HR_IPGL_ERROR_SELECTING_OBJECT,
	HR_IPGL_ERROR_ALOCATING_BUFFER,
	HR_IPGL_ERROR_UNSUPORTED_DATATYPE,
};

struct IPGL2 : public IUnknown {

	// Management
	virtual HRESULT __stdcall SetRasterizer(IPGLR2* rasterizer)=0;
	virtual HRESULT __stdcall AllocBuffer(long w, long h, long bbp, long* rbs, uchar** buffer)=0;
	virtual HRESULT __stdcall FreeBuffer(uchar* buffer)=0;

	// Clipping
	virtual HRESULT __stdcall ClipRect(PGLRECT*, PGLRECT*)=0;
	virtual HRESULT __stdcall CleanRect(PGLRECT*, long* count)=0;
	virtual HRESULT __stdcall SubRect(PGLRECT*, long*, PGLRECT *)=0;
	virtual HRESULT __stdcall ClipRectArray(PGLRECT* rect, long* count, PGLRECT* clip)=0;

	// Font & Text
	virtual HRESULT __stdcall CreateFont(HANDLE* font, char* name, long height, long weight, PGLCOLOR rgb, char *map)=0;
	virtual HRESULT __stdcall DestroyFont(HANDLE font)=0;
	virtual void	__stdcall DefaultMap(char* map)=0;
	virtual void	__stdcall SetMap(char* map, char* string)=0;
	virtual void	__stdcall TextCount(HANDLE font, char* string, long width, long* count)=0;
	virtual void	__stdcall TextLenght(HANDLE font, char* string, long* width)=0;
	virtual void	__stdcall TextLenght(HANDLE font, char* string, long* width, long count)=0;
	virtual void	__stdcall RenderText(HANDLE font, char* string, PGLBITMAP* bitmap, long x, long y)=0;
	virtual void	__stdcall RenderText(HANDLE font, char* string, PGLBITMAP* bitmap, long x, long y, long count)=0;
	virtual void	__stdcall RenderClipedText(HANDLE font, char *string, PGLBITMAP* bitmap, long x, long y, PGLRECT *ir)=0;
	virtual void	__stdcall RenderWrappedText(HANDLE hfont, char* string, PGLBITMAP* bitmap, long x, long y, PGLRECT *ir, long wx1, long wx2)=0;

	// DLI
	virtual void __stdcall DLI(PGLDLI*, PGLBITMAP*, PGLRECT*)=0;
	virtual void __stdcall DLI_CUSTOM(PGLDLI_CUSTOM**, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_DL(PGLDL*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_CDL(PGLCDL*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_GBox(PGLDLI_GBOX*, PGLBITMAP*,  PGLRECT*, long)=0;
	virtual void __stdcall DLI_BITMAP(PGLDLI_BITMAP*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_CBITMAP(PGLDLI_CBITMAP*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_TBITMAP(PGLDLI_TBITMAP*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_CTEXT(PGLDLI_CTEXT*, PGLBITMAP*,  PGLRECT*, long)=0;
	virtual void __stdcall DLI_WTEXT(PGLDLI_WTEXT*, PGLBITMAP*,  PGLRECT*, long)=0;
	virtual void __stdcall DLI_TEXT(PGLDLI_TEXT*, PGLBITMAP*,  PGLRECT*, long)=0;
	virtual void __stdcall DLI_LINE(PGLDLI_LINE*, PGLBITMAP*,  PGLRECT*, long)=0;
	virtual	void __stdcall DLI_BOX(PGLDLI_BOX*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_HGRID(PGLDLI_GRID*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_SBITMAP(PGLDLI_SBITMAP*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_SFBITMAP(PGLDLI_SBITMAP*, PGLBITMAP*, PGLRECT*, long)=0;
	virtual void __stdcall DLI_TRIANGLE(PGLDLI_TRIANGLE*, PGLBITMAP*, PGLRECT*, long)=0;

	// To be removed...
	virtual HRESULT __stdcall FitBitmap(PGLBITMAP *v_s, PGLBITMAP *v_d)=0;
	virtual	HRESULT __stdcall RGB_Flip(uchar *s, long w, long h)=0;
	virtual HRESULT __stdcall CloneBitmap(PGLBITMAP *v_s, PGLBITMAP *v_d)=0;
};


// -- IPIMG2 --------------------------------------------------------------------
extern "C" const GUID IID_IPIMG2;

struct IPIMG2 : public IUnknown {
	virtual HRESULT __stdcall Size(long width, long height)=0;
	virtual HRESULT __stdcall Type(PGLBITMAP_TYPE type)=0;
	virtual HRESULT __stdcall Clone(IPIMG2**)=0;
};

// -- IPDS2 --------------------------------------------------------------------
extern "C" const GUID IID_IPDS2;

enum F_IPDS_MODE {
	F_IPDS_MODE_CLIPPED,						// Only a region of the given window will represent the display
	F_IPDS_MODE_UNBUFFERED,						// No intermidiate buffering (Draw() return right away, Update() is combined with Draw())
};										
enum IPDS_MODE {
	IPDS_MODE_CLIPPED		= BIT(F_IPDS_MODE_CLIPPED),		
	IPDS_MODE_UNBUFFERED	= BIT(F_IPDS_MODE_UNBUFFERED),	
};										
										
enum F_IPDS_FLAG_REGION {					
	F_IPDS_FLAG_REGION_HIDEN,					// The region DLI will not be rendered
	F_IPDS_FLAG_REGION_OPAQUE,					// The region do not fully hide what is in its bounding rectangle
	F_IPDS_FLAG_REGION_NOMASKING,				// No masking check will be done
	F_IPDS_FLAG_REGION_VISIBLE,					// SYSTEM ONLY: This object is fully or partialy visible
};
enum IPDS_FLAG_REGION {					
	IPDS_FLAG_REGION_HIDEN		= BIT(F_IPDS_FLAG_REGION_HIDEN),	
	IPDS_FLAG_REGION_OPAQUE		= BIT(F_IPDS_FLAG_REGION_OPAQUE),	
	IPDS_FLAG_REGION_NOMASKING	= BIT(F_IPDS_FLAG_REGION_NOMASKING),
	IPDS_FLAG_REGION_VISIBLE	= BIT(F_IPDS_FLAG_REGION_VISIBLE),	
};

typedef struct {
	PGLRECT	rect;
	long	flag;
	void	*userdata;
	PGLDLI	dli;
} PDSR2_INFO;

enum HR_IPDS2 {
	HR_IPDS_WARNING = 0x00000000,
	HR_IPDS_WARNING_SOMETHING,
	HR_IPDS_ERROR = 0xE8230000,
	HR_IPDS_ERROR_RESTORING_SURFACE,
	HR_IPDS_ERROR_LOCKING_SURFACE,
	HR_IPDS_ERROR_GETTING_DC,
	HR_IPDS_ERROR_ALLOCATING_REGION,
	HR_IPDS_ERROR_PIXELFORMAT_UNKNOWN,
	HR_IPDS_ERROR_PIXELFORMAT_UNSUPPORTED,
	HR_IPDS_ERROR_CREATING_SURFACE,
	HR_IPDS_ERROR_GETTING_PIXELTYPE,
	HR_IPDS_ERROR_CREATING_DDRAW,
	HR_IPDS_ERROR_CREATING_DDRAW2,
	HR_IPDS_ERROR_SETTING_COOPLEVEL,
	HR_IPDS_ERROR_SETTING_FULLSCREEN,
	HR_IPDS_ERROR_SETTING_DISPLAYMODE,
	HR_IPDS_ERROR_RESTORING_DISPLAYMODE,
	HR_IPDS_ERROR_CREATING_WREGIONSTRUCT,
	HR_IPDS_ERROR_CREATING_PGL,
	HR_IPDS_ERROR_MISSING_HWND,
	HR_IPDS_ERROR_INITIALAZING_PGL,
	HR_IPDS_ERROR_INVALID_CLIPAREA,
	HR_IPDS_ERROR_SETTING_VIDEOMODE,
	HR_IPDS_ERROR_UNSUPPORTED,
};

struct IPDSR2 : public IUnknown {
	virtual void	__stdcall Info(PDSR2_INFO* info)=0;
	virtual void	__stdcall GetPosition(PDSR2_INFO* info)=0;
	virtual void	__stdcall SetUserData(void* data)=0;
	virtual void	__stdcall GetUserData(void** data)=0;

	virtual void	__stdcall AddDraw(PGLRECT* rect)=0;
	virtual void	__stdcall AddUpdate(PGLRECT* rect)=0;			
	virtual void	__stdcall Refresh()=0;
	
	virtual void	__stdcall Size(long w, long h)=0;
	virtual void	__stdcall Flags(long on, long off)=0;
	virtual void	__stdcall DLI(PGLDLI* dli)=0;
	virtual void	__stdcall Position(long x, long y)=0;

	// Z Ordering
	virtual void	__stdcall ToFront()=0;
	virtual void	__stdcall ToBack()=0;
	virtual void	__stdcall Push()=0;
	virtual void	__stdcall Pop()=0;

	virtual void	__stdcall Lock()=0;
	virtual void	__stdcall Unlock()=0;

	virtual HRESULT __stdcall NewRegion(void* userdata, IPDSR2** region, long xp, long yp, long w, long h, long flags)=0;
};

struct PDS2_NOTIFY {
	virtual void	__stdcall NowVisible(IPDSR2* region){return;};
	virtual void	__stdcall NowInVisible(IPDSR2* region){return;};
};

struct IPDS2 : public IUnknown {
	virtual HRESULT __stdcall SetNotification(PDS2_NOTIFY* notify)=0;

	virtual HRESULT __stdcall NewRegion(void* userdata, IPDSR2** region, HANDLE layer, long xp, long yp, long w, long h, long flags)=0;

	virtual void	__stdcall AddDraw(PGLRECT* rect)=0;		// Should be called AddGlobalDraw()
	virtual void	__stdcall AddUpdate(PGLRECT* rect)=0;	// Should be called AddGlobalUpdate()
	virtual void	__stdcall Draw()=0;
	virtual void	__stdcall Update()=0;
	virtual void	__stdcall Sync()=0;						// Synchronize display state (execute Draw()/Update())

	virtual HRESULT __stdcall PanLayer(HANDLE layer, long xpos, long ypos)=0;
	virtual HRESULT __stdcall SetLayer(HANDLE layer, PGLRECT* rect)=0;
	virtual HRESULT __stdcall PanDLayer(HANDLE layer, long xdelta, long ydelta)=0;		// PanLayer should be removed
	virtual HRESULT __stdcall GetLayerPos(HANDLE layer, long* xpos, long* ypos)=0;
	virtual HRESULT __stdcall ScrollLayer(HANDLE layer, long xdelta, long ydelta)=0;

	virtual HRESULT __stdcall PointTest(HANDLE* layer, IPDSR2** region, long x, long y)=0;
	virtual HRESULT __stdcall PointTest2(HANDLE layer, IPDSR2** region, long x, long y)=0;

	// Should be part of the frame buffer interface
	virtual HRESULT __stdcall SetViewSize(PGLRECT* rect)=0;
};

// == SUPPORT FUNCTIONS & MACROS ==============================================
#define IReserve(a, b) (a*)ireserve; ireserve += sizeof(a)*b;

extern void DLIShadow(PGLDLI_GBOX* gbox, long dx, long dy, long w, long h, long sw, long sh);

#endif
