/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
//////////////////////////////////////////////////////////////////////////////////
// IXDibOp.cpp 
// InnoVision defined API for Dib section operation
//

#include "stdafx.h"
#include "afxpriv.h"
#include "IXDibOp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////
VOID WriteTextToDibSection( HBITMAP hDib, char* FontName, int size, char* szStr, int x, int y)
{
/*
	if (m_pMemDC != NULL)
	{
		m_pMemDC->SelectObject(m_pOldBitmap);
		delete m_pMemDC;
		m_pMemDC = NULL;
		m_pOldBitmap = NULL;
	}

	if (m_pWinDC != NULL)
	{
		m_pWinDC->SelectObject(m_pOldPalette);
		delete m_pWinDC;
		m_pWinDC = NULL;
		m_pOldPalette = NULL;
	}

	if (m_Bitmap.m_hObject != NULL)
		m_Bitmap.DeleteObject();

	if (m_Fire != NULL)
	{
		delete m_Fire;
		m_Fire = NULL;
	}

	CRect rect;
	CSize size;

	GetClientRect(&rect);
	size = rect.Size();

	if (m_MaxBurn == 0)
		m_MaxBurn = (int)(size.cy * 0.75);

	if (m_nSize == 0)
		m_nSize = (int)(size.cx / 2);

	m_Fire = new BYTE[size.cx];

	LPBITMAPINFO lpbi;

	// Fill in the BITMAPINFOHEADER
	lpbi = (LPBITMAPINFO) new BYTE[sizeof(BITMAPINFOHEADER) + (256 * sizeof(RGBQUAD))];
	lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	lpbi->bmiHeader.biWidth = size.cx;
	lpbi->bmiHeader.biHeight = size.cy;
	lpbi->bmiHeader.biPlanes = 1;
	lpbi->bmiHeader.biBitCount = 8;
	lpbi->bmiHeader.biCompression = BI_RGB;
	lpbi->bmiHeader.biSizeImage = WIDTHBYTES((DWORD)size.cx * 8) * size.cy;
	lpbi->bmiHeader.biXPelsPerMeter = 0;
	lpbi->bmiHeader.biYPelsPerMeter = 0;
	lpbi->bmiHeader.biClrUsed = 0;
	lpbi->bmiHeader.biClrImportant = 0;

	// Fill in the color table
	UINT uUsage = DIB_RGB_COLORS;
	memcpy( lpbi->bmiColors, m_rgbPalette, sizeof(RGBQUAD) * 256 );

	m_pWinDC = new CWindowDC(this);

	HBITMAP hBitmap = CreateDIBSection( m_pWinDC->m_hDC, lpbi, uUsage, (void **)&m_pBits, NULL, 0 );

	delete [] (BYTE *)lpbi;

	ASSERT(hBitmap != NULL);

	m_Bitmap.Attach( hBitmap );

	for (int y = 0; y < size.cy; y++ )
	{
		BYTE* pRow = (m_pBits + WIDTHBYTES((DWORD)size.cx * 8) * y);
		for (int x = 0; x < size.cx; x++ )
			*pRow++ = 16;
	}

	m_pMemDC = new CDC;

	VERIFY( m_pMemDC->CreateCompatibleDC(m_pWinDC) );

	m_pOldPalette = m_pWinDC->SelectPalette( &m_Palette, FALSE );
	m_pWinDC->RealizePalette();
	m_pOldBitmap = m_pMemDC->SelectObject( &m_Bitmap );

	for (int x = 0; x < size.cx; x++ )
		m_Fire[x] = 16;
*/
}//end of WriteTextToDibSection
/////////////////////////////////////////////////////////////////////////////////////////////
// Jim will responsible to release all resouces. 08-09-2000
HBITMAP IXCreatDibSection( int w, int h, int BitDepth, unsigned char* pBitByte )
{
	BITMAPINFOHEADER		bmpHeader;

	bmpHeader.biSize        = sizeof( BITMAPINFOHEADER );
	bmpHeader.biWidth       = w;
	bmpHeader.biHeight      = -h;
	bmpHeader.biPlanes      = 1;
	bmpHeader.biBitCount    = BitDepth;
	bmpHeader.biCompression = BI_RGB;
	bmpHeader.biSizeImage   = w * h;

	HBITMAP hBmp = CreateDIBSection( NULL,
									(BITMAPINFO *)&(bmpHeader),
									DIB_RGB_COLORS,
									(void **)&(pBitByte),
									NULL, 0 );

	return( hBmp );
}//end of IXCreateDibSection