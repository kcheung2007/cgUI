// "cg_MappingFrame.h"
#ifndef _CG_MAPPING_FRAME_H
#define _CG_MAPPING_FRAME_H

#include <math.h>

#define MATH_ROUNDUP_FIX_10K ((double)0.0001)

enum 
{
	FACE_ALPHA_MASK,
	OUTLINE1_ALPHA_MASK,
	SHADOW1_ALPHA_MASK,
	OUTLINE2_ALPHA_MASK,
	SHADOW2_ALPHA_MASK,
	OUTLINE3_ALPHA_MASK,
	SHADOW3_ALPHA_MASK,
	CAST_ALPHA_MASK
};
enum
{
FRAME_NW,FRAME_NE,FRAME_SE,FRAME_SW,FRAME_ANCHOR
};
typedef struct
{

	double X[5];
	double Y[5];
	double Z[5];

	double XRot;
	double YRot;
	double ZRot;

	//Pivot pt for extra rotation
	double SpinPivotX;
	double SpinPivotY;
	double SpinPivotZ;

	//Pivot pt for extra rotation
	double AlignAnchorX;
	double AlignAnchorY;
	double AlignAnchorZ;

}OBJ_MAPPING_FRAME;
#endif