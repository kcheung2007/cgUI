//	C601file.h
//
//
//	Describes a raw 601 Image stream file. File extension will be ".601"
//
//
#ifndef _C601File_
#define _C601File_

#include	"gxlate.h"
#include	"nlridl.h"

#define C601PadSize 512
#define C601PadMask 0xfffffe00

typedef enum tagC601Type{
	C601_VersionOne=0
} C601Type;

#define C601FLG_PICON_INCLUDED  0x0001

//	This was defined in nlridl.h in version 1.0-1.2 Has been moved here.  
typedef struct  tagSTrnClipInfoOld
    {
    DWORD length;
    LARGE_INTEGER storageSize;
    DWORD components;
    EPlayFrameType format;
    FILETIME mTime;
    FILETIME cTime;
    STrnRect maxRect;
    STrnRect safeRect;
    }	STrnClipInfoOld;

#define	FileID_601 '106C'
typedef struct TagC601Header {
	long				lFileID;
	long				lHeaderSize;
	C601Type			eVersion;
	short               wPadSize; // these were formerly one field... if older code reads a newer file, we've got trouble.
	short               wFlags;
	long				lFrameRate;
	STrnClipInfoOld		sClipInfo;
} C601Header;


#endif //_C601File_