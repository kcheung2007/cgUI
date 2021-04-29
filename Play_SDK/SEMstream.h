/****************************************************************************

	SEMstream.h
	Definition of Trinity 1.0 SEMstream class.

	Copyright 1996 by Play, Inc.
	Written by Tim Feldman.

	For Microsoft C++ 4.0, Windows 95/Windows NT 3.51

	Latest change : M  04/08/96 pm

	SEM stands for "Switcher Executable Module" -- a chunk of code and data
	that the Trinity Switcher hardware can execute.

	SEMstream can compile various kinds of data into a stream of SEM data
	inside a custom OLE Structured Storage file (a .TFX file: "Trinity FX").

****************************************************************************/

#include "tfxfile.h"	// Craig Daniel's Trinity Effects File class
						// NOTE: C/C++ Code Generation project settings need to be:
						// Run Time Library = "Multithreaded DLL"

#include "playlist.h"	// Carl Daniel's playlist code -- just here to get dependencies right!

#include "playclsid.h"

/****************************************************************************

		Compiler Controls

****************************************************************************/

#ifndef __SEMSTREAM_H__
#define __SEMSTREAM_H__

/****************************************************************************

		Global Constants

****************************************************************************/

// values for 'SEMtype'--
// these are the types of SEMstreams we can compile;
// only sensible combinations are allowed...



// ...FIFO_MAINALPHA only

#define SEMTYPE_WIPE			0




// ...FIFO_GRAPHICSCHROMA, FIFO_GRAPHICSLUMA

#define SEMTYPE_GRAPHICS_HARD	1




// ...FIFO_GRAPHICSCHROMA, FIFO_GRAPHICSLUMA, FIFO_GRAPHICSALPHA

#define SEMTYPE_GRAPHICS_SOFT	2




// ...FIFO_MAINALPHA, FIFO_GRAPHICSCHROMA, FIFO_GRAPHICSLUMA, FIFO_GRAPHICSALPHA

#define SEMTYPE_WIPE_COLORED	3




// return values from SEMstream::GetStatus()

#define SEMSTATUS_OK					 0	// everything is OK

#define SEMSTATUS_TYPE					 1	// invalid 'SEMtype'
#define SEMSTATUS_RAM					 2	// couldn't alloc RAM
#define SEMSTATUS_NUMFRAMES				 3	// invalid 'numFields'

#define SEMSTATUS_NOSTART				 4	// Finish() called without Start()

#define SEMSTATUS_REWRITE_HEADER		 5	// error rewriting SEM stream header

#define SEMSTATUS_SEMSTREAMCREATE		 7	// error creating SEM stream ISTream

#define SEMSTATUS_SHORTFRAMES			 8	// not enough frames compiled
#define SEMSTATUS_LONGFRAMES			 9	// too many frames compiled

#define SEMSTATUS_BLOCKWRITE			10	// error writing block to SEMstream IStream
#define SEMSTATUS_BLOCKREWRITE			11	// error rewriting block in SEMstream IStream
#define SEMSTATUS_SEEK					12	// error seeking in SEMstream IStream

/****************************************************************************

		Class Definition

****************************************************************************/

class SEMstream
{
	// private data

	int			SEMtype;		// the type of SEMstream

	int			SEMstatus;		// the status of the compiler

	IStream *	stream;			// pointer to the SEMstream's IStream

	BYTE *		SEMheader;		// an image of the start of a SEM stream,
								// with fixed-length and variable-length parts;
								// not too large; only one needed per SEMstream;
								// starts with the 'EffectSize' field;
								// ends with the 'nFieldData' field;
								// allocated and written in 'Start()';
								// updated in 'CompileField()';
								// flushed in 'Finish()'

	BYTE *	FieldData;			// image of a FieldData block
	ULONG	FieldDataLength;	// its length

	ULONG	DummyFieldData;		// a dummy FieldData blocks, used to indicate
								// the end of the group of FieldData blocks
								// in one field of the SEM stream

	ULONG	SEMstreamLength;	// current length of SEM stream  in bytes
	ULONG	SEMheaderLength;	// total length of SEM stream header in bytes

	long	NumFieldsExpected;	// 'numFields' from Init()
	long	NumFieldsCompiled;	// number of fields compiled so far

	int		FrameWidth;			// dimensions of the frames being compiled
	int		FrameHeight;
	int		FrameLineBytes;

	int		MainAlphaErrorBand;			// error band values to allow lossy compression
	int		GraphicsAlphaErrorBand;

	int		StartLine;			// Start on odd or even line?
	// public functions

public:

	// constructor, destructor

	 SEMstream(void);
	~SEMstream(void);

	// initiator

	BOOL Start(IStream * pStream, long numFields, int semtype,
				int width, int height, int MAerrorBand, int GAerrorBand,
				int _StartLine);

	// field compiler

	BOOL CompileField(void * MainAdata, void * GraphicYUVdata, void * GraphicAlphaData);

	// finisher

	BOOL	Finish(void);

	// return latest error status

	int	GetStatus(void);

	// Query Current Stream Length(s)	---- Only one supported for now

	enum {	STREAM_SWITCHER = 0,
	};

	ULONG GetCurrentStreamLength(int StreamIndex)
	{
		ULONG result = -1;

		if( StreamIndex == STREAM_SWITCHER && stream )
			result = SEMstreamLength;

		return result;
	}

	// private functions

private:

	// free up resources

	void	FreeUp(void);

	// start the SEMstream

	BOOL	StartSEMstream(void);

	// emit a dummy FieldData block

	BOOL EmitDummyFieldData(void);

	// specialized field compilers

	BOOL EmitMainAlphaField(void * MainAdata);
	BOOL EmitHardGraphicsField(void * GraphicYUVdata);
	BOOL EmitSoftGraphicsField(void * GraphicYUVdata, void * GraphicAlphaData);

	// work with SEMstream header data

	BOOL	RewriteSEMFieldEffectSize(ULONG newVal);
	BOOL	RewriteSEMFieldFieldOffset(LONG frameNum, ULONG pFieldData, ULONG FieldSize);

	//	work with OLE Structured Storage

	BOOL	RewriteStreamBlock(void * data, LONG size, LONG seek);
	BOOL	WriteStreamBlock(void * data, LONG size);
	BOOL	WriteNewStreamBlock();
};

#endif // __SEMSTREAM_H__
