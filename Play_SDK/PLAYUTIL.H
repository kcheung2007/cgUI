/* header file for playutil.cpp

    Created 1/23/96 by Todd Sprague

    Copyright 1996 by Play Incorporated.
    PLAY CONFIDENTIAL

 */


#include "gxlate.h"

IGXIntBitmap *LoadRGBA( char *pszColorName, char *pszAlphaName=NULL, HRESULT *pHr=NULL );

IGXIntBitmap *LoadAlpha( char *pszAlphaName );

IGXIntBitmap **LoadBitmapSequence( LPSTR pszRgbFmt, LPSTR pszAlphaFmt, int *nBitmaps );

void FreeBitmapSequence( IGXIntBitmap **pBitmapSeq );

IGXIntBitmap *LoadRGBAResource2( HINSTANCE hInstance, LPSTR pszResourceName, LPSTR pszType, HRESULT *pHr=NULL );

IGXIntBitmap *LoadAlphaResource( HINSTANCE hInstance, LPSTR pszResourceName, HRESULT *pHr=NULL );

IGXIntBitmap **LoadRGBASequenceResource2( HINSTANCE hInstance, LPSTR pszResourceName, LPSTR pszType, int *nBitmaps, HRESULT *pHr=NULL );
