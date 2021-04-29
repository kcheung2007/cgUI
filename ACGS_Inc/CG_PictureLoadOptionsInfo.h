//CG_PictureLoadOptionsInfo.h
#ifndef _CGPLOI_H
#define _CGPLOI_H

enum {
	PIC_LOAD_SIZE_ORIGINAL,
	PIC_LOAD_SIZE_FIT,
	PIC_LOAD_SIZE_PERCENT
	};

typedef struct
{
	char inFileName[256];
	char inOriginalSizeString[32];	//i.e. "640 x 480"
	double inOriginalPixelWidth;
	double inOriginalPixelHeight;
	int  inoutLoadSizeOption;		//PIC_LOAD_SIZE_ORIGINAL, etc
	double inoutPercentZoom;	//i.e. 100.0 percent
	BOOL inoutPreserveImageAspect;
	BOOL inoutIncludeAlphaChannel;
	BOOL inoutInvertAlphaChannel;
	BOOL inoutBlackTrim;
	int  inoutPositionSector_0_8;

	//-----------------------------------------------------------------
	//menu item enable flags (ghost item if false)
	BOOL inEnableControl_IncludeAlphaChannel;
	BOOL inEnableControl_InvertAlphaChannel;
	BOOL inEnableControl_BlackTrim;

}PICTURE_LOAD_OPTIONS_INFO;

#endif //_CGPLOI_H
