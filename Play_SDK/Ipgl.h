//=============================================================================
// IPGL.h
// Copyright 1998 Play Incorporated
//
// NOTE:
//	One of the main change for PGL2 is to make the interface destination
//	rendering independant... the implementation of the interface will implement
//	RGB24 destination surface, ARGB32 destination surface, etc...
//	Two cocreate instance will be required if a user when to work on 24/32bit
//	surface at once.
//	For all this to work, PGL2 will be split in 2 interfaces. PGL2 and PGL2_RST
//	The main interface for non surface depandent code, and a rasterizier interface.
//
//	PDS2 main change is to support nested region and a move to Interface VS handle,
//	separating global & region function into 2 interface.
//
//	PGL also need a L2 cache feature for unbufered mode... the size of the TEMP
//	rasterizer buffer should be 128x128 (16K pixel) with a <=256K L2 cache
//	But the buffer should be 256x256 (65K pixel) with a >256K L2 cache
//
// Created 1998 by Stephan Schaem
//=============================================================================
#ifndef ipgl_h
#define ipgl_h

#include <PlayInc.h>
#include <unknwn.h>
#include <toolbox.h>

// -- IPGL --------------------------------------------------------------------

typedef struct {
	union {
	ulong	rgba;
	struct {
		uchar	a, r, g, b;						// 'Intel' byte ordering
	};
	};
} COLOR32;

typedef struct {
	// 3D Space
 	long	x3d;
	long	y3d;
	long	z3d;
	// Projected
	long	x2d;
	long	y2d;
	long	z2d;
} GLVERTEX;

typedef struct	{
	GLVERTEX *vertex;
	long	u, v;
} GLPOINT;

 typedef struct	{
	uchar	type;
	char	count;
	GLPOINT	point[4];
	void	*texture;
} GLPOLYGON;

enum IPGL_DATATYPE {					// This should be a GLIMAGE datatype enumerator
	IPGL_DATATYPE_UNKNOW,
	IPGL_DATATYPE_GLIMAGE_RGB,
	IPGL_DATATYPE_GLIMAGE_ARGB,
	IPGL_DATATYPE_GLCOLOR_RGB,			// 24bit per pixel, 8:8:8  R:G:B
	IPGL_DATATYPE_GLCOLOR_ARGB,
	IPGL_DATATYPE_GLIMAGE_RGB16,		// 16bit per pixel, 5:6:5  R:G:B
	IPGL_DATATYPE_GLIMAGE_RGB15,		// 16bit per pixel, 1:5:5:5  A:R:G:B
	IPGL_DATATYPE_GLIMAGE_INDEX8,
	IPGL_DATATYPE_GLIMAGE_PPC,			// Compress in 'Play Predictive Coding ' format
	IPGL_DATATYPE_GLIMAGE_IFX,			// Compress in 'Intra Frame Xoring' format
	IPGL_DATATYPE_GLIMAGE_YUYV,			// 32bit per paired pixel, 8:8 / 8:8  Y:U / Y:V
	IPGL_DATATYPE_GLIMAGE_UYVY,			// 32bit per paired pixel, 8:8 / 8:8  U:Y / V:Y
	IPGL_DATATYPE_GLTEXT_ARGB,
	IPGL_DATATYPE_PGLDL,				// Display list
	IPGL_DATATYPE_GLIMAGE_A,
};

// ------------------------------------

enum IPGL_FLAG {
	IPGL_FLAG_FLIPV,
};

typedef struct {
	ulong	color;
	long	x,y,w,h;
} GLBOX;

typedef struct {
	ulong	color;
	long	x1,y1,x2,y2;
} GLLINE;

typedef struct {
	long	x1;
	long	y1;
	long	x2;
	long	y2;
} GLRECT;

typedef struct {
	short	x1;
	short	y1;
	short	x2;
	short	y2;
} GLRECTI;

typedef struct {
	HANDLE	font;
	char	*string;
} GLTEXT;

typedef struct {
	union {
		uchar		*byte;
		long		color;
		void		*data;
		GLTEXT		*text;
	};
	long	datatype;
	long	modulo;
	long	w;
	long	h;
} GLIMAGE;

typedef struct {
	long	alpha;
	long	red;
	long	green;
	long	blue;
} GLCOLOR;

typedef struct {
	// Destination Info
	void	*dp;					// Data Pointer
	long	drbs;					// Row Byte Size
	ulong	w;						// Width of copy (in pixel)
	ulong	h;						// Height of copy (in pixel)
	// Source Info
	void	*sp;					// Data Pointer
	long	srbs;					// Row Byte Size
} GLSBLIT;

typedef struct {
	// Destination Info
	void	*dp;					// Data Pointer
	long	drbs;					// Row Byte Size
	ulong	w;						// Width of copy (in pixel)
	ulong	h;						// Height of copy (in pixel)
	// Source Info
	void	*sp;					// Data Pointer
	long	srbs;					// Row Byte Size
	ulong	spx;					// SubPixel XPos 
	ulong	spy;					// subPixel YPos
	ulong	sdx;					// Scale X Factor (% * 65536 * 65536) (ex: .5 = 0x80000000 )
	ulong	sdy;					// Scale Y Factor (65536 * 65536 / %) (ex: 1.5 = 0xAAAAAAAA )
} GLBLIT;

typedef struct {
	long	ox, oy;					// Original		16:16 fixpoint
	long	tx, ty;					// Translated	16:16 fixpoint 
} GLTP;

typedef struct {
	uchar	*src;					// source pointer
	uchar	*dst;					// Destination pointer
	long	srbs;					// Source Row byte size
	long	drbs;					// Destination Row byte size
	GLTP	*a;						// Triangle point A
	GLTP	*b;						// Triangle point B
	GLTP	*c;						// Triangle point C
} GLTRI;

typedef struct {
	long	etx1p;					// Destination edge X pos
	long	etx2p;					// Destination edge Y pos
	long	etx1s;					// Destination edge X step
	long	etx2s;					// Destination edge Y step
	long	eox1p;					// Source edge X pos
	long	eoy1p;					// Source edge Y pos
	long	eox1s;					// Source edge X step
	long	eoy1s;					// Source edge Y step 
	uchar	*src;					// source pointer
	uchar	*dst;					// Destination pointer
	long	srbs;					// Source Row byte size
	long	drbs;					// Destination Row byte size
	long	soxs;					// Source scanline X step
	long	soys;					// Source scanline Y step
	long	count;					// height of trapezoid
} GLTRAP;							// 60 bytes

enum GL_FONT_WEIGHT {
	GL_FONT_WEIGHT_THIN = 25,
	GL_FONT_WEIGHT_NORMAL = 50,
	GL_FONT_WEIGHT_BOLD = 75,
};

// -- PGL DISPLAY LIST ----------------------------------

class PGLDL;

enum PGLDLI_DATATYPE {					// Display list item types
	PGLDLI_DATATYPE_UNKNOW,
	PGLDLI_DATATYPE_PGLDL,
	PGLDLI_DATATYPE_BOX_RGB24,
	PGLDLI_DATATYPE_BOX_ARGB32,
	PGLDLI_DATATYPE_LINE_RGB24,
	PGLDLI_DATATYPE_LINE_ARGB32,
	PGLDLI_DATATYPE_TEXT_RGB24,
	PGLDLI_DATATYPE_TEXT_ARGB32,
	PGLDLI_DATATYPE_IMAGE_RGB24,
	PGLDLI_DATATYPE_IMAGE_ARGB32,
	PGLDLI_DATATYPE_CTEXT_RGB24,
	PGLDLI_DATATYPE_CTEXT_ARGB32,
	PGLDLI_DATATYPE_CIMAGE_RGB24,
	PGLDLI_DATATYPE_CIMAGE_ARGB32,
	PGLDLI_DATATYPE_TRIA_RGB24,			// Array of 24bit RGB triangles (colored or texture mapped)
	PGLDLI_DATATYPE_TRIA_ARGB32,		// Array of 32bit ARGB triangles (colored or texture mapped)
	PGLDLI_DATATYPE_GBOX_RGB24,
	PGLDLI_DATATYPE_GBOX_ARGB32,
	PGLDLI_DATATYPE_HGRID_RGB24,
};

typedef struct {
	long	x1,y1;
	long	count;
	GLTRI*	tri;
} PGLDLI_TRIA;							// 16 bytes

typedef struct {
	long	x1,y1;
	long	w,h;
	ulong	color;
} PGLDLI_BOX;							// 24 bytes

typedef struct {
	long	x1, y1;
	long	w, h;
	long	count;
	ulong	color;
} PGLDLI_GRID;							// 24 bytes

typedef struct {
	long	x1,y1;
	long	w,h;
	COLOR32	color[4];
} PGLDLI_GBOX;							// 32 bytes

typedef struct {
	long	x1,y1;
	long	x2,y2;
	ulong	color;
} PGLDLI_LINE;							// 24 bytes

typedef struct {
	long	x1,y1;
	long	w, h;
	HANDLE	font;
	char	*string;
} PGLDLI_TEXT;							// 24 bytes

typedef struct {
	long	x1,y1;						// Position of the rectangle defined by ir
	long	w, h;						// String width & height
	HANDLE	font;
	char	*string;
	GLRECT	ir;							// Define the inside rectangle
} PGLDLI_CTEXT;							// 40 bytes

typedef struct {
	long	x1,y1;
	long	a;
	GLIMAGE	image;
} PGLDLI_IMAGE;

typedef struct {
	long	x1,y1;
	long	a;
	GLIMAGE	image;
	GLRECT	ir;							// Define the inside rectangle
} PGLDLI_CIMAGE;

typedef struct {						// Display list item 'header'
	long	type;
	union {								// The supported items types
		void*			data;
		PGLDLI_LINE*	line;
		PGLDLI_BOX*		box;
		PGLDLI_TEXT*	text;
		PGLDLI_CTEXT*	ctext;
		PGLDLI_IMAGE*	image;
		PGLDLI_CIMAGE*	cimage;
		PGLDLI_TRIA*	tria;
		PGLDLI_GBOX*	gbox;
		PGLDL*			dl;
		PGLDLI_GRID*	grid;
	};
} PGLDLI;								// 8 bytes

class PGLDL {
public:
	long			size;				// Byte in the item data section *** this should called MAX and be in entry count ***
	long			avail;				// Available byte in item data section  *** this should deseaper ***
	long			count;				// Valid Entry count in data section
	void			*data;				// *** This is not needed ***
	PGLDLI			*items;
};

// ------------------------------------

enum HR_IPGL {
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

extern "C" const GUID CLSID_PGL;
extern "C" const GUID IID_IPGL;

struct IPGL : public IUnknown {			// most function need renaming, and grouping in sub interface
	// Clipping
	virtual HRESULT __stdcall ClipRect(GLRECT *, GLRECT *)=0;
	virtual HRESULT __stdcall CleanRect(GLRECT *, long *)=0;
	virtual HRESULT __stdcall SubRect(GLRECT *, long *, GLRECT *)=0;

	// Misc
	virtual HRESULT __stdcall RGB_Init()=0;
	virtual HRESULT __stdcall RGB_PTest(uchar *,long, long,long, long, long *)=0;
	virtual HRESULT __stdcall RGB_Extract(uchar *, uchar **, long, long, long, GLRECT *, long)=0;
	virtual HRESULT	__stdcall RGB_Destroy(uchar *)=0;
	
	// PCI Blit (Should be using the GLSBLIT structure)
	virtual HRESULT __stdcall PCI_RGB_BlitRGB(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall PCI_ARGB_BlitRGB(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall PCI_RGB16_BlitRGB(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall PCI_RGB15_BlitRGB(void *, void *, long, long , long, long)=0;

	// RGB Blit
	virtual HRESULT __stdcall RGB_BlitARGBS(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBS(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitARGBSA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitARGBZA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBZA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitARGB(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGB(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitARGBZ(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBZ(GLBLIT *)=0;

	virtual HRESULT __stdcall ARGB_FillARGB(ulong, uchar *, long, long, long)=0;
	virtual HRESULT __stdcall RGB_FillRGB(ulong, uchar *, long, long, long)=0;
	virtual HRESULT __stdcall RGB_DrawLine(uchar *, long, long, long, long, long, ulong)=0;
	virtual HRESULT __stdcall RGB_DrawBox(uchar *, long, GLRECT *)=0;

	virtual HRESULT __stdcall ARGB_PTest(uchar *,long, long,long, long, long *)=0;
	virtual HRESULT __stdcall ARGB_CopyARGBSA(GLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_BlitARGB(GLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_MinMax(uchar *, long, long, GLRECT *, float)=0;
	virtual HRESULT __stdcall ARGB_Extract(uchar *, uchar **, long, long, long, GLRECT *, long)=0;
	virtual HRESULT	__stdcall ARGB_Destroy(uchar *)=0;

	virtual HRESULT	__stdcall Resample(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall RGB_DrawRGBDigit(uchar *, uchar *, long, long)=0;
	virtual HRESULT __stdcall ARGB_DrawARGBDigit(uchar *, ulong *, long, long)=0;
	virtual HRESULT	__stdcall RGB_2xRGB(uchar *, uchar *, long , ulong , ulong , ulong )=0;
	virtual HRESULT __stdcall RGB_TrapezoidRGBF(GLTRAP *)=0;
	virtual HRESULT __stdcall ARGB_TrapezoidARGBF(GLTRAP *)=0;
	virtual HRESULT __stdcall RGB_TrapezoidARGBF(GLTRAP *)=0;
	virtual HRESULT __stdcall Triangle2Trapezoid(GLTRI *, GLTRAP *, long *)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBSA(GLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBZA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_ScanlineARGB(uchar *, uchar *, long)=0;
	virtual HRESULT __stdcall RGB16_TrapezoidRGB16(GLTRAP *, long)=0;
	virtual HRESULT __stdcall ARGB_TrapezoidARGB(GLTRAP *, long)=0;
	virtual HRESULT __stdcall RGB_TrapezoidARGB(GLTRAP *, long)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBM(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGB16SA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB16_PTest(uchar *,long, long,long, long, long *)=0;
	virtual HRESULT __stdcall RGB16_Extract(uchar *, uchar **, long, long, long, GLRECT *, long)=0;
	virtual HRESULT __stdcall Triangle2TrapezoidC(GLTRI *, GLTRAP *, long *, long, GLRECT *)=0;
	virtual HRESULT __stdcall RT2(GLRECT *rect, GLTRI *p_tri, GLPOINT *aa, GLPOINT *bb, GLPOINT *cc, GLTRAP *p_trap, long *p_count)=0;
	virtual HRESULT __stdcall RGB_ScaleRGB(uchar *source, uchar **dest, long srbs, long ox, long oy, long dx, long dy, long flag)=0;
	virtual HRESULT __stdcall RGB_BlitRGB16SA2(GLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_BlitRGB(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGB16(GLBLIT *)=0;
	virtual HRESULT __stdcall ARGB_ExtractRGB_A(uchar *,uchar *, uchar **, long, long, long, long, GLRECT *, long)=0;
	virtual HRESULT __stdcall PCI_Blit(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall ARGB_BlitRGBZA(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_TrapezoidRGB(GLTRAP *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA10(GLBLIT *)=0;
	virtual HRESULT	__stdcall ARGB_ResampleRGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall RGB_BlitA_RGB(GLBLIT *p_blit, long rgb)=0;
	virtual HRESULT __stdcall ARGB_CreateFont(HANDLE *font, char *name, long height, long weight, long rgb, char *map)=0;
	virtual HRESULT __stdcall RenderText(HANDLE font, char *string, GLIMAGE *image, long x, long y)=0;
	virtual HRESULT __stdcall RGB_FillARGB(GLBLIT *blit)=0;
	virtual HRESULT __stdcall DestroyFont(HANDLE font)=0;
	virtual HRESULT __stdcall TextLenght(HANDLE p_font, char *p_string, long *size)=0;
	virtual HRESULT __stdcall RenderClipedText(HANDLE p_font, char *p_string, GLIMAGE *p_image, long x, long y, GLRECT *ir)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA6(GLBLIT *)=0;
	virtual HRESULT	__stdcall ARGB_ResampleARGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall ARGB_DrawARGB(GLBLIT *p_blit)=0;
	virtual HRESULT __stdcall CloneImage(GLIMAGE *v_s, GLIMAGE *v_d)=0;
	virtual HRESULT __stdcall FitImage(GLIMAGE *v_s, GLIMAGE *v_d)=0;
	virtual HRESULT	__stdcall RGB_ResampleARGB(uchar *, uchar *, long , long , long , long , float , float , float , float )=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA7(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA11(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSAX(GLBLIT *)=0;
	virtual	HRESULT __stdcall RGB_Flip(uchar *s, long w, long h)=0;
	virtual HRESULT __stdcall BlitImage(GLIMAGE *si, GLIMAGE *di, GLRECT *sr, GLRECT *dr)=0;
	virtual HRESULT __stdcall DefaultMap(char *map)=0;
	virtual HRESULT __stdcall SetMap(char *map, char *string)=0;
	virtual HRESULT __stdcall RGB_PatRGB(GLBLIT *, long ,long, long ,long)=0;
	virtual HRESULT __stdcall RGB_PatARGB(GLBLIT *, long ,long, long ,long)=0;
	virtual HRESULT __stdcall PCI_INDEX8_BlitRGB(void *, void *, long, long , long, long)=0;
	virtual HRESULT __stdcall RGB_Brightness(uchar *data, long rbs, GLRECT *rect, long b)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSA12(GLBLIT *)=0;

	virtual HRESULT __stdcall RGB_ClipDL(PGLDL *, PGLDL **, GLRECT *)=0;
	virtual HRESULT __stdcall RGB_FreeDL(PGLDL *)=0;
	virtual HRESULT __stdcall RGB_RenderDL(GLIMAGE *, PGLDL *)=0;

	virtual HRESULT __stdcall A_CreateFont(HANDLE *font, char *name, long height, long weight, long rgb, char *map)=0;
	virtual HRESULT __stdcall A_Extract(uchar *, uchar **, long, long, long, GLRECT *, long)=0;
	virtual HRESULT __stdcall RGB_BlitCARGB(GLBLIT *, char *)=0;

	virtual HRESULT __stdcall BlurArea24(GLIMAGE *SourceImage, GLIMAGE *DestImage, int kw, int kh)=0;
	virtual HRESULT __stdcall RenderText2(HANDLE font, char *string, GLIMAGE *image, long x, long y, long cc)=0;
	virtual HRESULT __stdcall TextCount(HANDLE p_font, char *p_string, long size, long* count)=0;
	virtual HRESULT __stdcall ARGB_ScaleARGB(uchar *source, uchar **dest, long srbs, long ox, long oy, long dx, long dy, long flag)=0;
	virtual HRESULT __stdcall ARGB_BlitARGBSAX(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_CreateFont(HANDLE *font, char *name, long height, long weight, long rgb, char *map, long p_rgb2)=0;

	virtual HRESULT __stdcall RGB_RenderDL2(GLIMAGE *, PGLDL *, GLRECT *)=0;
	virtual HRESULT __stdcall RGB_RenderDL2S(GLIMAGE *, PGLDL *, GLRECT *, float, float)=0;

	virtual HRESULT __stdcall RGB_BlitRGBSXA(GLBLIT* p_blit)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSYA(GLBLIT* p_blit)=0;

	virtual HRESULT __stdcall RGB_GBoxARGB(GLIMAGE* image, PGLDLI_GBOX* gbox, GLRECT* clip, long count)=0;
	virtual HRESULT __stdcall RGB_GBoxRGB(GLIMAGE* image, PGLDLI_GBOX* gbox, GLRECT* clip, long count)=0;

	virtual HRESULT __stdcall RGB_BlitRGBSX(GLBLIT *)=0;
	virtual HRESULT __stdcall RGB_BlitRGBSY(GLBLIT *)=0;

	virtual HRESULT __stdcall RGB_BlitRGB_A(GLBLIT* p_blit, ulong a)=0;

	virtual HRESULT __stdcall ClipRectArray(GLRECT* p_rect, long* p_count, GLRECT *p_clip)=0;

	virtual HRESULT __stdcall RGB_RenderDL_LineRGB24 (GLIMAGE* destn, PGLDLI_LINE* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_TextRGB24 (GLIMAGE* destn, PGLDLI_TEXT* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_TextARGB32 (GLIMAGE* destn, PGLDLI_TEXT* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_CTextRGB24 (GLIMAGE* destn, PGLDLI_CTEXT* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_CTextARGB32 (GLIMAGE* destn, PGLDLI_CTEXT* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_BoxRGB24 (GLIMAGE* destn, PGLDLI_BOX* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_BoxARGB32 (GLIMAGE* destn, PGLDLI_BOX* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_TriaRGB24 (GLIMAGE* destn, PGLDLI_TRIA* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_TriaARGB32 (GLIMAGE* destn, PGLDLI_TRIA* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_ImageRGB24 (GLIMAGE* destn, PGLDLI_IMAGE* src,  GLRECT* clip, float scalex, float scaley)=0;
	virtual HRESULT __stdcall RGB_RenderDL_ImageARGB32 (GLIMAGE* destn, PGLDLI_IMAGE* src,  GLRECT* clip, float scalex, float scaley)=0;


};

// -- IPDS --------------------------------------------------------------------
enum IPDS_MODE {
	IPDS_MODE_FULLSCREEN,			// Set custom video mode
	IPDS_MODE_CLIPPED,				// Only a region of the given window will represent the display
	IPDS_MODE_GDI,					// DirectDraw alternative
	IPDS_MODE_UNBUFFERED,			// No intermidiate buffering (Draw() return right away, Update() is combined with Draw())
	IPDS_MODE_NOPALETTE,			// Dont use/force a palette in 8bit mode
};

enum IPDS_FLAG_REGION {
	IPDS_FLAG_REGION_FILTERING,		// Turn on filtered resampling with scale factor != 1.0
	IPDS_FLAG_REGION_HIDEN,			// The region is not visible
	IPDS_FLAG_REGION_PATTERN,		// The image aplyed to this region is a pattern 
	IPDS_FLAG_REGION_TRANSLUCID,	// The region do not fully hide what is in its bounding rectangle
	IPDS_FLAG_REGION_NOMASKING,		// No masking check will be done
};

typedef struct {
	GLRECT	rect;
	long	w;
	long	h;
	float	scalex;
	float	scaley;
	long	datatype;
	void	*data;
	long	flag;
	void	*userdata;
} RINFO_OLD;

typedef struct {
	GLRECT	rect;
	long	w;
	long	h;
	float	scalex;
	float	scaley;
	long	flag;
	void	*userdata;
	GLIMAGE	img;
} RINFO;

enum HR_IPDS {
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

extern "C" const GUID CLSID_PDS;
extern "C" const GUID IID_IPDS;

struct IPDS : public IUnknown {
	virtual HRESULT __stdcall Initialize(HWND, long, GLRECT *, long, long, long)=0;
	virtual HRESULT __stdcall VideoMode(long, long, long, long)=0;
	virtual HRESULT __stdcall WindowMoved(void)=0;
	virtual HRESULT __stdcall WindowSized(void)=0;
	virtual HRESULT __stdcall AddDraw(GLRECT *)=0;					// Should be called AddGlobalDraw()
	virtual HRESULT __stdcall AddUpdate(GLRECT *)=0;				// Should be called AddGlobalUpdate()
	virtual HRESULT __stdcall Draw()=0;
	virtual HRESULT __stdcall Update()=0;
	virtual HRESULT __stdcall PointTest(HANDLE *, HANDLE *, long, long)=0;
	virtual HRESULT __stdcall LockSurface(void **, long *, GLRECT *)=0;
	virtual HRESULT __stdcall UnlockSurface()=0;
	virtual HRESULT __stdcall PanLayer(HANDLE, long, long)=0;
	virtual HRESULT __stdcall SetLayer(HANDLE, GLRECT *)=0;
	virtual HRESULT __stdcall AddRegion(HANDLE *, HANDLE, long, long, long, long, float, float, long, void *, long, long)=0; // This will vanish (use NewRegion())
	virtual HRESULT __stdcall Remove(HANDLE)=0;
	virtual HRESULT __stdcall Refresh(HANDLE)=0;
	virtual HRESULT __stdcall ToFront(HANDLE)=0;
	virtual HRESULT __stdcall ToBack(HANDLE)=0;
	virtual HRESULT __stdcall Push(HANDLE)=0;
	virtual HRESULT __stdcall Pop(HANDLE)=0;
	virtual HRESULT __stdcall SetData(HANDLE, long, void *, long)=0;	// This will vanish (use SetImage)
	virtual HRESULT __stdcall SetSize(HANDLE, long, long)=0;
	virtual HRESULT __stdcall SetScale(HANDLE, float, float)=0;
	virtual HRESULT __stdcall SetPosition(HANDLE, long, long)=0;		// Should be floats
	virtual HRESULT __stdcall GetInfo_OLD(HANDLE, RINFO_OLD *)=0;
	virtual HRESULT __stdcall SetFlag(HANDLE, long)=0;
	virtual HRESULT __stdcall ClearFlag(HANDLE, long)=0;
	virtual HRESULT __stdcall SetUserData(HANDLE, void *)=0;
	virtual HRESULT __stdcall GetUserData(HANDLE, void **)=0;			// This will vanish (use getinfo)
	virtual HRESULT __stdcall SetViewSize(GLRECT *)=0;
	virtual HRESULT __stdcall GetInfo(HANDLE, RINFO *)=0;
	virtual HRESULT __stdcall NewRegion(HANDLE *region, HANDLE layer, long xp, long yp, long w, long h, long flags)=0;
	virtual HRESULT __stdcall SetImage(HANDLE region, GLIMAGE *image)=0;
	virtual HRESULT __stdcall SetPalette(char *palette)=0;
	virtual HRESULT __stdcall PointTest2(HANDLE , HANDLE *, long, long)=0;
	virtual HRESULT __stdcall FlushDraw()=0;
	virtual HRESULT __stdcall FlushUpdate()=0;
	virtual HRESULT __stdcall VideoModeChanged()=0;
	virtual HRESULT __stdcall AddRDraw(HANDLE, GLRECT *)=0;					// Should be called AddDraw()
	virtual HRESULT __stdcall AddRUpdate(HANDLE, GLRECT *)=0;				// Should be called AddUpdate()
	virtual HRESULT __stdcall SetPosition2(HANDLE, float, float)=0;
	virtual HRESULT __stdcall ScrollLayer(HANDLE, long, long)=0;
	virtual HRESULT __stdcall PanDLayer(HANDLE, long, long)=0;				// PanLayer should be removed
	virtual HRESULT __stdcall GetLayerPos(HANDLE, long*, long*)=0;
};

// -- IPIB --------------------------------------------------------------------
typedef struct {
	BITA32	field;
	ulong	count;
	void	*data;
} FORM_PIB_LUT;

enum FF_PIB_IMAGE {
	FF_PIB_IMAGE_WIDTH,				// Width of image in pixel
	FF_PIB_IMAGE_HEIGHT,			// Height of image in pixel
	FF_PIB_IMAGE_PAD,
	FF_PIB_IMAGE_FORMAT,			// Descript the image data encoding (see: PIBIO_IMAGE_FORMAT)
	FF_PIB_IMAGE_DATA,				// Pointer to the image data
	FF_PIB_IMAGE_LUT,				// Pointer to a LUT
	FF_PIB_IMAGE_RBS,				// row byte size
};

typedef struct {
	BITA32	field;					// see: FF_PIB_IMAGE
	ushort	width;
	ushort	height;
	ushort	pad;
	IPGL_DATATYPE	format;
	void	*data;
	FORM_PIB_LUT	*lut;
	long	rbs;
} FORM_PIB_IMAGE;

enum FF_PIB_UINFO {
	FF_PIB_UINFO_WIDTH,				// Default Width of image book (not aplicable for all images)
	FF_PIB_UINFO_HEIGHT,			// Default Height of image book (not aplicable for all images)
	FF_PIB_UINFO_RATE,				// Default rate of the image book (not aplicable for all images)
	FF_PIB_UINFO_COUNT,				// Number of image in book
};

typedef struct {
	BITA32	field;					// see: FF_PIB_UINFO
	long	width;
	long	height;
	long	rate;
	long	count;
} FORM_PIB_UINFO;

enum HRESULT_IPIB {
	HR_IPIB_WARNING = 0x00000000,
	HR_IPIB_WARNING_SOMETHING,
	HR_IPIB_ERROR = 0xE8250000,
	HR_IPIB_ERROR_CANTALLOCPIBIO,
	HR_IPIB_ERROR_CANTOPENFILE,
	HR_IPIB_ERROR_CANTCREATEFILE,
	HR_IPIB_ERROR_CANTCREATEHEADER,
	HR_IPIB_ERROR_CANTREADHEADER,
	HR_IPIB_ERROR_NOTAPIB,
	HR_IPIB_ERROR_CANTINSERTFRAME,
	HR_IPIB_ERROR_CANTWRITEDATA,
	HR_IPIB_ERROR_CANTREADDATA,
	HR_IPIB_ERROR_READNOTALLOWED,
	HR_IPIB_ERROR_WRITENOTALLOWED,
	HR_IPIB_ERROR_RANDOMWRITE,
	HR_IPIB_ERROR_FORMATNOTSUPPORTED,
	HR_IPIB_ERROR_MODEUNSUPORTED,
	HR_IPIB_ERROR_CANTREAD,
	HR_IPIB_ERROR_CANTSEEK,
	HR_IPIB_ERROR_NOINDEX,
};

extern "C" const GUID CLSID_PIB;
extern "C" const GUID IID_IPIB;

struct IPIB : public IUnknown {
	virtual HRESULT __stdcall OverrideIOCTRL(IOCTRL *)=0;
	virtual HRESULT __stdcall FileOpen(char *)=0;
	virtual HRESULT __stdcall FileValidate(char *)=0;
	virtual HRESULT __stdcall FileClose()=0;
	virtual HRESULT __stdcall Info(FORM_PIB_UINFO *)=0;
	virtual HRESULT __stdcall ImageWrite(FORM_PIB_IMAGE *, IPGL_DATATYPE, ulong)=0;
	virtual HRESULT __stdcall ImageRead(ulong)=0;
	virtual HRESULT __stdcall ImageDecomp(ulong, FORM_PIB_IMAGE *, long)=0;
	virtual HRESULT __stdcall ImageUnload(ulong)=0;
};

#endif
