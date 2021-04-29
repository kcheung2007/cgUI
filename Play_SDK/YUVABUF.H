///////////////////////////////////////////////////////////////////////////////
//	YUVABuf.h
///////////////////////////////////////////////////////////////////////////////
//	Created	March 25 1996	Ken Turcotte
//
//	Copyright (c) 1996, Play Inc. All rights reserved.
///////////////////////////////////////////////////////////////////////////////
#ifndef _YVUABuf_
#define _YVUABuf_

//	C Format
//	CB1 CR1 CB3 CR3 CB5 CR5....
//	Y Format
//	Y1 Y2 Y3 ....
//	A Format
//	A1 A2 A3 ....


#define NTSC601_Width 720
#define NTSC601_Height 486

#pragma pack(push,4)

typedef struct tagYUVALine{
	unsigned char Y[NTSC601_Width];
	unsigned char C[NTSC601_Width];
	unsigned char A[NTSC601_Width];
} YUVALine;

typedef struct tagYUVABuf {
	YUVALine Line[NTSC601_Height];	

}YUVABuf, *LPYUVABuf;

#pragma pack(pop)


#endif // _YVUABuf_
