//ColorBox.h

#ifndef _COLORBOX_H
#define _COLORBOX_H

//for RenderColorBoxTo()
#define CGS_RENDER_FULL_COLOR 0
#define CGS_RENDER_GRAYSCALE 1

//COLOR BOX DEFINITION ====================================================
#define MAXIMUM_SPREAD_TABS 20
#define COLOR_BOX_PICTURE_NAME_BYTES 128

//Spread types:
#define LINEAR_SPREAD_TYPE 0
#define CONCENTRIC_SPREAD_TYPE 1
#define FOUR_PT_SPREAD_TYPE   2
#define RADIAL_SPREAD_TYPE    3
#define BEVEL_SPREAD_TYPE     4
#define HORIZ2_SPREAD_TYPE    5
#define VERT2_SPREAD_TYPE     6
#define SIDE4_SPREAD_TYPE     7


#define PALETTE_MENU_SHOW_COLORS 0
#define PALETTE_MENU_SHOW_PICTURES 1

#if !LINUX_PLATFORM
	#pragma pack(push,1)
#endif //LINUX_PLATFORM
// <<<<<<<<<<<<<<<<<<<< NOTICE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IF ANY CHANGE IS MADE TO THE ALPHA_COLOR_BOX STRUCTURE --
// HAVE JIM HANDLE ADDED/DELETED FIELDS IN cg_seq.c
#define CUR_COLORBOX_VERSION 0


typedef struct
{
	BYTE spread_on;
	BYTE spread_tabs_total;
	BYTE spread_type;
	BYTE current_tab_index;
	COLORREF color[MAXIMUM_SPREAD_TABS];
	float spread_tab_position[MAXIMUM_SPREAD_TABS];
	WORD spread_angle;
	float f_rel_center_x; //ranges from 0.0 (left) to 1.0(right) (0.5 default)
	float f_rel_center_y; //ranges from 0.0 (top)  to 1.0(bot)   (0.5 default)
} COLOR_SPREAD_DETAILS;

typedef struct
{
	BYTE show_mode;    // PALETTE_MENU_SHOW_COLORS ( 0 ) or PALETTE_MENU_SHOW_PICTURES ( 1 )
	union
	{
		COLOR_SPREAD_DETAILS spread;
		char picture_name[COLOR_BOX_PICTURE_NAME_BYTES + 1];
	} details;
	WORD x;
	WORD y;
	WORD width;
	WORD height;
	BYTE highlight;
	BYTE bank;
	BYTE box;
	BYTE update_done;
} ALPHA_COLOR_BOX;

#if !LINUX_PLATFORM
	#pragma pack(pop)
#endif
// =======================================================================
#endif //_A_COLOR_H
