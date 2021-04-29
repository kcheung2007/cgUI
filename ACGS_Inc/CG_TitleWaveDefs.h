//CG_TitleWaveDefs.h
#include "TW_VpAnim.h"
#include "TW_AnimTypes.h"

#ifndef _CG_TitleWaveDefs_H
#define _CG_TitleWaveDefs_H

enum
{
	TWEM_OPEN,
	TWEM_AUTO_BUTTON,
	TWEM_EDIT_UPDATE,
	TWEM_SET_PAGE_TYPE,
	TWEM_NEW_FLASH_RATE,
	TWEM_NEW_FADE_RATE,
	TWEM_SET_AUTO_PREVIEW,
	TWEM_SAVE_EFFECT_FILE,
	TWEM_CLOSE
};

//DRAG AND DROP ====================================================
#define DD_OBJ_CUR_VERSION 0

#define DD_OBJ_NULL                 0  /* used internally when user clicks on empty part of screen, no object selected */
#define DD_OBJ_COLOR_BOX            1
#define DD_OBJ_OBJECT               2
#define DD_OBJ_PICTURE_FILE         3 /* raw picture files in bin not implemented yet */
#define DD_OBJ_PAGE                 4
#define DD_OBJ_PROJECT              5
#define DD_OBJ_PRESET				6 /* font presets added 6-24-97 */

//needed for vincent's defines
#define REGULAR_BITMAP_PICON        DD_OBJ_NULL
#define PALETTE_BITMAP_PICON		DD_OBJ_COLOR_BOX
#define CG_OBJECT_BITMAP_PICON		DD_OBJ_OBJECT
#define CG_PRESET_BITMAP_PICON		DD_OBJ_PRESET /* JRS 6-24-97 */


#endif//  _CG_TitleWaveDefs_H