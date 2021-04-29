//CG_Palette.h
#ifndef _CG_PALETTE_H
#define _CG_PALETTE_H

#include "CG_ColorBox.h"

/*************************************/
BOOL CG_PaletteSaveFile(char *FileName, ALPHA_COLOR_BOX* pCboxData, int ColorBoxCount);

//NOTE: returns a pointer to a pool of colorboxes that CALLER MUST FREE
ALPHA_COLOR_BOX* CG_PaletteLoadFile(char *FileName, int *NumItemsLoaded);
/*************************************/
/*************************************/
/*************************************/
/*************************************/
#endif // _CG_PALETTE_H