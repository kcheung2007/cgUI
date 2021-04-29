/****************************************************************************

	WEMstream.h
	Definition of Trinity 1.0 WEMstream class.

	Copyright 1996 by Play, Inc.
	Written by Tim Feldman.

	For Microsoft C++ 4.0, Windows 95/Windows NT 3.51

	Latest change : F  04/05/96 pm

	WEM stands for "Warp Engine Module" -- a chunk of code and data
	that the Trinity Warp engine (DVE) hardware can execute.

	WEMstream can compile various kinds of graphic data into a stream of WEM data
	inside a custom OLE Structured Storage file (a .TFX file: "Trinity FX").

****************************************************************************/

#include "tfxfile.h"	// Craig Daniel's Trinity Effects File class
						// NOTE: C/C++ Code Generation project settings need to be:
						// Run Time Library = "Multithreaded DLL"

#include "playlist.h"	// Carl Daniel's playlist code -- just here to get dependencies right!

#include "playclsid.h"

#include	"decomp.h"

/****************************************************************************

		Compiler Controls

****************************************************************************/

#ifndef __WEMSTREAM_H__
#define __WEMSTREAM_H__

/****************************************************************************

		Global Constants

****************************************************************************/

// values for 'WEMtype'--
// these are the types of WEMstreams we can compile;
// only sensible combinations are allowed...



// ...FIFO_ALU, FIFO_CONTROL

#define WEMTYPE_HARD			0




// ...FIFO_ALU, FIFO_CONTROL, FIFO_ALPHA

#define WEMTYPE_SOFT			1



// ...FIFO_ALU, FIFO_CONTROL, FIFO_HIGHLIGHT

#define WEMTYPE_HIGHLIGHT_HARD	2




// ...FIFO_ALU, FIFO_CONTROL, FIFO_HIGHLIGHT, FIFO_ALPHA

#define WEMTYPE_HIGHLIGHT_SOFT	3








// return values from WEMstream::GetStatus()

#define WEMSTATUS_OK					 0	// everything is OK

#define WEMSTATUS_TYPE					 1	// invalid 'WEMtype'
#define WEMSTATUS_RAM					 2	// couldn't alloc RAM
#define WEMSTATUS_NUMFRAMES				 3	// invalid 'numFields'

#define WEMSTATUS_NOSTART				 4	// Finish() called without Start()

#define WEMSTATUS_REWRITE_HEADER		 5	// error rewriting WEM stream header

#define WEMSTATUS_SHORTFRAMES			 8	// not enough frames compiled
#define WEMSTATUS_LONGFRAMES			 9	// too many frames compiled

#define WEMSTATUS_BLOCKWRITE			10	// error writing block to WEMstream IStream
#define WEMSTATUS_BLOCKREWRITE			11	// error rewriting block in WEMstream IStream
#define WEMSTATUS_SEEK					12	// error seeking in WEMstream IStream

#define WEMSTATUS_DVE_FACEINIT			15	// error calling Greg's DVEFaceInit()
#define WEMSTATUS_DVE_DECOMPOSE			16	// error calling Greg's DecomposeImage()
#define WEMSTATUS_DVE_RENDERFRAME		17	// error calling Greg's RenderFrame()
#define WEMSTATUS_DVE_COMPILERDONE		18	// error calling Greg's DVECompilerDone()



#define FE_MAX_STREAMLENGTH				128*1024*1024
#define WE_MAX_STREAMLENGTH				128*1024*1024
#define Alpha_MAX_STREAMLENGTH			128*1024*1024




/****************************************************************************

		Class Definition

****************************************************************************/

class WEMstream
{
	// private data

	int			WEMtype;		// the type of WEMstream

	int			WEMstatus;		// the status of the compiler

	IStream *	WEstream;			// pointer to the WEMstream's IStream

	BYTE *		WEMWEheader;		// an image of the start of a WEM stream,
								// with fixed-length and variable-length parts;
								// not too large; only one needed per WEMstream;
								// starts with the 'EffectSize' field;
								// ends with the 'nFieldData' field;
								// allocated and written in 'Start()';
								// updated in 'CompileField()';
								// flushed in 'Finish()'
	IStream *	FEstream;			// pointer to the WEMstream's IStream

	BYTE *		WEMFEheader;		// an image of the start of a WEM stream,
								// with fixed-length and variable-length parts;
								// not too large; only one needed per WEMstream;
								// starts with the 'EffectSize' field;
								// ends with the 'nFieldData' field;
								// allocated and written in 'Start()';
								// updated in 'CompileField()';
								// flushed in 'Finish()'

	IStream *	Astream;			// pointer to the WEMAlphastream's IStream

	BYTE *		WEMAlphaheader;		// an image of the start of a WEMAlpha stream,
								// with fixed-length and variable-length parts;
								// not too large; only one needed per WEMstream;
								// starts with the 'EffectSize' field;
								// ends with the 'nFieldData' field;
								// allocated and written in 'Start()';
								// updated in 'CompileField()';
								// flushed in 'Finish()'


	BYTE *	FieldData;			// image of a FieldData block
	ULONG	FieldDataLength;	// its length

	ULONG	DummyFieldData;		// a dummy FieldData blocks, used to indicate
								// the end of the group of FieldData blocks
								// in one field of the WEM stream

	ULONG	WEMWEstreamLength;	// current length of WEM stream  in bytes
	ULONG	WEMWEheaderLength;	// total length of WEM stream header in bytes
	ULONG	WEMFEstreamLength;	// current length of WEM stream  in bytes
	ULONG	WEMFEheaderLength;	// total length of WEM stream header in bytes
	ULONG	WEMAlphastreamLength;	// current length of WEM stream  in bytes
	ULONG	WEMAlphaheaderLength;	// total length of WEM stream header in bytes


	long	NumFieldsExpected;	// 'numFields' from Init()
	long	NumFieldsCompiled;	// number of fields compiled so far

	int		FrameWidth;			// dimensions of the frames being compiled
	int		FrameHeight;
	int		FrameLineBytes;

	unsigned int	SourceNum;	// 0 for Program (an OFF transition)
								// 1 for Preview (an ON transition or an overlay)

	BYTE *	ALUbufPtr;			// Greg K.'s code allocates this buffer
	BYTE *	ControlBufPtr;		// and this one
	int		ALUbufLength;		// and tells us how long this one is

	POINT	VideoOffset;		// the offset for the DVE in memory
	
	int		StartLine;			// Start on odd or even line?

	Decomp * Decompose;
	// public functions

	double warp_max_u_error;
	double warp_max_v_error;

public:

	// constructor, destructor

	 WEMstream(void);
	~WEMstream(void);

	// initiator

	BOOLEAN Start(IStream * pWEStream,IStream * pFEStream, IStream * pAStream, long numFields, int width, int height,
				int wemtype, unsigned int sourceNum,
				double uScale, double vScale, double uOffset, double vOffset, POINT _VideoOffset,
				int _StartLine);


	// frame compiler

	BOOLEAN CompileField(void * Adata, void * Udata, void * Vdata, 
    void * Sdata, void * Hdata,
    void * AltAdata=NULL);

	// finisher

	BOOLEAN	Finish(void);

	// return latest error status

	int	GetStatus(void);

	void SetWarpErrorBounds(double max_u, double max_v)
	{
		warp_max_u_error = max_u;
		warp_max_v_error = max_v;
	}	
	
	// Query Current Stream Length

	enum {	STREAM_ALPHA = 0,
			STREAM_ALUFE = 1,
			STREAM_ALUWE = 2,
	};

	ULONG GetCurrentStreamLength(int StreamIndex)
	{
		ULONG result = -1;

		switch( StreamIndex )
		{
		case STREAM_ALPHA :
			if( Astream )
				result = WEMAlphastreamLength;
			break;
		case STREAM_ALUFE :
			if( FEstream )
				result = WEMFEstreamLength;
			break;
		case STREAM_ALUWE :
			if( WEstream )
				result = WEMWEstreamLength;
			break;
		}

		return result;
	}

	// private functions
	
private:

	// free up resources

	void	FreeUp(void);

	// start the WEMstream

	BOOLEAN	StartWEMstream(void);

	// work with WEMstream header data

	BOOLEAN	RewriteWEMFieldEffectSize(ULONG newVal);
	BOOLEAN	RewriteWEMFieldFieldOffset(LONG frameNum, ULONG pFieldData, ULONG FieldSize);

	//	work with OLE Structured Storage

	BOOLEAN	RewriteWEStreamBlock(void * data, LONG size, LONG seek);
	BOOLEAN	WriteWEStreamBlock(void * data, LONG size);
	BOOLEAN	WriteNewWEStreamBlock();

	BOOLEAN	RewriteFEStreamBlock(void * data, LONG size, LONG seek);
	BOOLEAN	WriteFEStreamBlock(void * data, LONG size);
	BOOLEAN	WriteNewFEStreamBlock();

	BOOLEAN	RewriteAlphaStreamBlock(void * data, LONG size, LONG seek);
	BOOLEAN	WriteAlphaStreamBlock(void * data, LONG size);
	BOOLEAN	WriteNewAlphaStreamBlock();


};

#endif // __WEMSTREAM_H__
