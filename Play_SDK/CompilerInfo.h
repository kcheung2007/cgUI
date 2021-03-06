/***********************************************************************************

	CompilerInfo.h
		Compiler Info Structure and all the Functions Needed for calling the Compiler's
		Other Functions

	Copyright 1996-1999 by Play, Inc.

	Author :	Hitesh K. Patel, Randy Jongens
	Created :	March 3rd, 1999

	Changes Made:
		User			Date			Reason

***********************************************************************************/

#define NOMINMAX

#ifndef ___CompilerInfo___
#define ___CompilerInfo___

#define MAXWARPSOURCES			3		/* max number warp engines that the compiler can use (at this time) */
#define MAXSWITCHERSOURCES		1		/* max number of switchers */

/***********************************************************************************/

typedef struct {
	unsigned char *mainAlpha;			/* this mixes video sources that are not warped */
	unsigned char *graphicAlpha;		/* this mixes graphics with the video */
	unsigned char *warpAlphaProgram;	/* these mix output of a warp and video from program, preview or aux1 */
	unsigned char *warpAlphaPreview;
	unsigned char *warpAlphaAux1;
	unsigned char RGBHasAlpha;			/* if TRUE the rgbBuffer has quads of the format argb (one byte each) */
	unsigned char *rgbBuffer;			/* this contains rgb data triples (byte b,g,r) */
	double *uBufferProgram;				/* these contains the u data from a texture map normalized from 0.0 to 1.0 for program, preview or aux1 */
	double *uBufferPreview;
	double *uBufferAux1;
	double *vBufferProgram;				/* these contains the v data from a texture map normalized from 0.0 to 1.0 for program, preview or aux1 */
	double *vBufferPreview;
	double *vBufferAux1;
} ProcessData, *ProcessDataPtr;

/***********************************************************************************/

enum {
	EFFECT_ERROR = -1,	/* 0. Effect Error */
	EFFECT_TYPE_1,		/* 1. switcher wipe */
	EFFECT_TYPE_2,		/* 2. graphic overlay with graphic alpha */
	EFFECT_TYPE_3,		/* 3. switcher wipe with graphic overlay with graphic alpha */
	EFFECT_TYPE_4,		/* 4. dve warp with warp alpha */
	EFFECT_TYPE_42,		/* 5. 2 dve warps with warp alpha with video background */
	EFFECT_TYPE_43,		/* 6. 3 dve warps with warp alpha with mat background */
	EFFECT_TYPE_5,		/* 7. hard edged dve warp with graphic overlay and graphic alpha, one video stream */
	EFFECT_TYPE_52,		/* 8. hard edged dve warp with graphic overlay and graphic alpha, two video streams */
	EFFECT_TYPE_6,		/* 9. soft edged dve warp with graphic overlay and graphic alpha with switcher mix */
	EFFECT_TYPE_7,		/* 10. soft edged dve warp with warp alpha and with uncolor corrected chromakey */
	EFFECT_TYPE_8,		/* 11. hard edged dve warp with color corrected chromakey (not currently supported) */
	EFFECT_TYPE_9		/* 12. soft edged dve warp with graphic overlay and graphic alpha with chromakey mix */
};

/***********************************************************************************
 we use this structure to pass data to the compiler via Camera
  #define MAX_PATH          260 is defined in windef.h
***********************************************************************************/
typedef struct {
	long VerInfo;								/* Will Be implemented in the Future */
	long videomode;								/* what node are we PAL or NTSC? */
	char filename [260];						/* name of the compiled effect file */
	char playliststorage[260];					/* name of the supplied storage for the playlist (convert to wide chars to use) */
												/* if the First Char is the '|' then it's the String else it's the Path for pre-compiled */
	unsigned long fields;						/* how many fields to create */
	unsigned long rows;							/* output rows high     (PAL and NTSC issue) */
	unsigned long columns;						/* output columns wide */
	unsigned char istransition;					/* is this effect a transition? */
	unsigned char chromashadowactive;			/* if the chroma keyer on? */
	unsigned char chromaoffatend;				/* should we turn it off at the end of the effect? */
	unsigned long warpsourcenum1;				/* these sources can be program, preview or aux */
	unsigned long warpsourcenum2;
	unsigned long warpsourcenum3;
	double uscale, vscale, uoffset, voffset;	/* for warps we calculate these numbers so 1 to 1 is really 1 to 1 */
	double precision;							/* how closely to we curve fit to make a warp (higher numbers are looser in fitting .0625 is default) */
	short iconw, iconh, icond;					/* the width and height and depth of the icon data (the actual data follows the playlist) */
	long effectcompiletype;						/* what type of file are we making */
	unsigned short sourceindex;					/* if we are using an effect that can use any source, this index points to the source we want to use */
	unsigned char emitWEstream1;				/* if TRUE, emit a stream for warp engine (super warp, some day it will exist for shipping) */
	unsigned char emitFEstream1;				/* if TRUE, emit a stream for FX engine (what we shipped with) */
	unsigned char emitWEstream2;
	unsigned char emitFEstream2;
	unsigned char emitWEstream3;
	unsigned char emitFEstream3;
	unsigned char emitGraphics;					/* if TRUE, emit graphics data and its alpha */
	unsigned char emitMainAlpha;				/* if TRUE, emit the main alpha */
	unsigned char emitWarp;						/* if TRUE, emit warp data and it alpha (for up to three sources) */
	short startField;							/* what field do we start on (PAL and NTSC are different */
} CompileInfo, *CompileInfoPtr;

/***********************************************************************************/




/***********************************************************************************
 These are the functions to be used when processing the fields
***********************************************************************************/

/************************************************************************************
	ProcessField Example Loop
*************************************************************************************
	InitilizeEffect ( (void *) CompileInfoPtr );

	unsigned char Abort = FALSE;
	while ( ( ! All_Fields_Processed ) && ( ! Abort ) )
	{
		while ( ( ! All_Scan_Lines_Processed ) && ( !Abort ) )
		{
			Abort = CheckAbort ();
			ProcessField ( ProcessDataPtr ScanLineData );
		}

		Get_Next_Field_Please;
	}

	- Comment : All the fields are either compiled or aborted 
	if ( Abort )
		AbortEffect ();
	else
		EffectDone ();

************************************************************************************/

/* This will Initilize the Effect */
unsigned char InitializeEffect ( void * data );

/* Process the Next Stream Line Data of the Field */
unsigned char ProcessField ( ProcessDataPtr pd );

/* Call this when the Effect gets done Processing all the fields */
void EffectDone ( void );

/* Abort effect should get called when user cancels the Field Processing - No need to call Effect Done
 this will delete the EffectFile if it was created else it will save changes to the Existing file and free up all
 the allocated memory */
void AbortEffect ();

unsigned char EmitGraphics ( void );
unsigned char EmitMainAlpha ( void );
unsigned char EmitWarp ( void );

/* call this at the end of each field */
unsigned long GetCurrentStreamLength ( int BoardID, int BoardIndex, int StreamIndex );

/***********************************************************************************/

#endif		/* ___CompilerInfo___ */