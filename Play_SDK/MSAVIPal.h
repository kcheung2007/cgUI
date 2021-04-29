/* Header file for AVI palette stuff... */


extern void SetWindowPalette( HWND hWnd );

extern void CopyAVIPaletteToDIB( BITMAPINFO *pBMI );

extern unsigned char _fastcall AVIPaletteLookup( unsigned char * bgr );

extern PALETTEENTRY *GetAVIPaletteEntries();

extern HPALETTE GetAVIHPalette();

extern HPALETTE SelectHardwarePalette( HDC hDC );
