// class description for a DIB

#ifndef _cdib_h
#define _cdib_h


#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/


// part of the rectangle defined by the given x,y and the 
//width/height of the src is outside destination
#define OVLYERR_CLIPREQUIRED  1

// this is returned if mask and source DIBs don't have identical dimensions
#define OVLYERR_DIMENSIONSBAD 2

// this is returned if mask depth isn't 8
#define OVLYERR_MASKDEPTHBAD     3

// this is returned if src depth isn't 24
#define OVLYERR_SRCDEPTHBAD     4

// this is returned if dest depth isn't 24
#define OVLYERR_DESTDEPTHBAD     5

// this is returned if somebody gave a null mask
#define OVLYERR_GOTNULLMASK         6

// this is returned if overlay routine was given dest coord out of bounds
#define OVLYERR_OUTOFBOUNDS         7

class CDIB
{
    BITMAPINFOHEADER *  m_pDIB;
    int                 m_rowbytes;
    unsigned char  *    m_pBits;
    BOOL                m_bContig; // flag that this DIB is contiguous, m_pBits should be cleared when m_pDIB is
    HBITMAP             m_hBitmap;
    BOOL                m_bBitsMyAlloc; // flag showing whether I alloc'd the bits ptr
    BOOL                m_bDIBMyAlloc; // flag showing whether I alloc'd the DIB

    HGLOBAL             m_hBits; // in case we run out of GDI memory

    unsigned char  *    m_pOrigBits; // internal consistency...

    // Copy constructor.  made private because it doesn't seem to work correctly
    CDIB(CDIB& p);

public:    

	CDIB();
	CDIB( int x, int h ); // assumes 24bit color DIB
	CDIB( int x, int h, int bits ); // 8 or 24 bit DIBs only
    CDIB( BITMAPINFOHEADER *pBMIH, unsigned char *pBits ); // for user-set stuff

    // contstructor from HBITMAP.  This DOESN'T call DeleteObject() on it
    CDIB( HBITMAP hbmp );

	~CDIB();

    void                FromBitmap( HBITMAP hbmp );
    void                Reset( int w, int h, int bits ); // bit=8 for alpha or 24 for color
    void                FreeDIB();
    int                 SaveDIB( IStream *pStream );
    int                 LoadDIB( IStream *pStream );
    int                 LoadIFF( IStream *pStream );
    int                 SaveDIB( LPSTR pszFilename );
    int                 LoadDIB( LPSTR pszFilename );
    int                 LoadIFF( LPSTR pszFilename );
    int                 CMapSize( ); // return size in bytes of color map within DIB
    int                 RowBytes( ); // return size in bytes of one row
    void                PutToDC( HDC hDC, int dx, int dy, int sx, int sy, DWORD w, DWORD h ); // draw (part of) DIB to hDC
    void                GetFromDC( HDC hDC, int dx, int dy, DWORD w, DWORD h ); // pick up DIB from hDC
    int                 OverlayWith( int dx, int dy, CDIB *mask, CDIB *data ); // CDIB thru alpha onto *this
    int                 OverlayWithEx( int dx, int dy, CDIB *mask, CDIB *data, DWORD dwTrans ); // other version with global transparency
    int                 OverlayWithEx( int dx, int dy, int sx, int sy, int w, int h, CDIB *mask, CDIB *data, DWORD dwTrans );
    int                 DrawWith( int dx, int dy, CDIB *mask, DWORD col );

    int                 Width( void );  // get width of DIB
    int                 Height( void ); // get Height of DIB
    int                 Depth( void ); // get depth of DIB

    DWORD               GetColor( int x, int y );
    void                SetColor( int x, int y, DWORD dwClr );

    void                SetRectColor( int dx, int dy, int w, int h, DWORD color );
    void                InvertRect( int dx, int dy, int w, int h );

    void                SetColor( DWORD color ); // sets entire DIB to one color
    void                ScaleColors( double scale ); // multiply all components by scale (works for alpha too) won't overflow, it'll hit rails

        // caller of this function must delete the returned bitmap
        // this call always makes a copy of the CDIB's bitmap...
    HBITMAP             xCreateBitmap(); // creates HBITMAP to be selected into device context and drawn into w/ windows API

    signed long         FindColorIndex( DWORD color ); // find the colormap index of a given color, -1 if not found or it's 24 bit
    void                ConvertColor( DWORD chgcolor, DWORD newcolor ); // change specific color to another

    BITMAPINFOHEADER *  LockDIB(); // return pointer to DIB itself
    void                UnlockDIB();
    DWORD *             GetCMap();
    void                SetColorMap( DWORD *pdwCMap, int iClrCount );
    unsigned char *     GetBits();    // returns pointer to actual bitmap.  may lock the DIB
    void                UnlockBits();
    HGLOBAL             GetHandle();  // returns globalalloc handle of DIB
    void                SetBits( unsigned char *pBits ); // make this DIB point to bits elsewhere
    
    // this copies the pointer to keep it internally for the class.  If the DIB is 256 colors, a colortable
    // like DWORD clrtable[256] should immediately follow the BITMAPINFOHEADER.  Bits will be reallocated if
    // necessary
    void                SetDIBInfo( BITMAPINFOHEADER *bmih );
    void                SetDIBInfo( BITMAPINFOHEADER *bmih, BYTE *pBits );

    void                CopyFrom( CDIB *src, int dx, int dy ); // copy from src to *this at location dx,dy, whole source
    void                CopyFrom( CDIB *srcDIB, int dx, int dy, int sx, int sy, int w, int h ); // partial source

    // these three create new CDIBs
    CDIB *              Shrink( int wid, int hei );  // don't want to expand a DIB, that looks bad
    CDIB *              CutOut( unsigned short c, unsigned short r, unsigned short w, unsigned short h, int *err );
    CDIB *              Duplicate( void );

    void                MakeContiguous(); // force this DIB to have BMIH and bits contiguous

    int                 TransRect( int dx, int dy, int w, int h, int iTrans, DWORD dwCol  );

    void                VLine( int x1, int y1, int y2, DWORD Clr );
    void                HLine( int x1, int y1, int x2, DWORD Clr );
    void                Line( int x1, int y1, int x2, int y2, DWORD Clr );

    // this function will return the HBITMAP contained within the class.
    // the caller should NOT delete this HBITMAP.  It may return NULL if
    // for some reason the memory wasn't allocated using an HBITMAP.
    HBITMAP             GetBitmap();

    CDIB *              MakeTranspose();

    CDIB *              Make24BitCopy();

    // valid only for 32bit RGBA bitmaps, for each pixel, it 
    // multiplies each component by the alpha value.
    void                PremultiplyAlpha();

    // this bitmap must be 32bit RGBA, dest is RGB 24bit.
    // assumes this bitmap has been premultiplied by alpha at each pixel.
    void                CompositeRGBASubPixel( CDIB *pDest, 
                                               double dx, double dy,  // dest x, y
                                               double scalex, double scaley, // scale factor, .5 to 1.0
                                               long   w, long h // wxh of rect to copy (in src pixel units)
                                             );

private:
    void                ShrinkFloat( int w,int h,CDIB *newDIB,long destrowbytes,long srcrowbytes, unsigned char *pDestBits, unsigned char *pSrcBits  );
    void                IFFMakeDIB( void );
};


#endif // _cdib_h
