/*****************************************************

  FXcomp.h

		Header file for base class EffectCompiler and
	the	SwitcherCompiler and WarpCompiler classes.

******************************************************/
#ifndef __FXcomp__
#define __FXcomp__

#include    <windows.h>
#include	<stdio.h>
#include	<crtdbg.h>
#include    "playclsid.h"
#include    "efxerror.h"
#include	"Tfxfile.h"// Craig Daniel's Trinity Effects File class
						// NOTE: C/C++ Code Generation project settings need to be:
						// Run Time Library = "Multithreaded DLL"

#include	"semstream.h"	// Tim Feldman's code for Switcher data streams
#include	"wemstream.h"	// Tim Feldman's code for Warp Engine data streams
#include	"ClrCon2.h"		// Michael Helmke's RGB to YUV converter class (modified)
#include	"cdib.h"


#include	"tksdebug.h"
#ifndef __simplevid_h__
#include	"simplevid.h"
#endif

//#define VBProgram	0
#define VBPreview	VBPreset
//#define VBKey		2
//#define VBAux1		6
#define WC_WARPENGINE 1
#define WC_FXENGINE 2

#define PLAY_WE_DVE_ID 0x0000000A
#define PLAY_FE_DVE_ID 0x00000009
#define PLAY_UPAC_DVE_ID		0x00000001
#define PLAY_DNAC_DVE_ID	0x00000002
#define NONE 0x00000000

#define NTSC	0
#define PAL		1

extern int DebugSeg;



/************************************************************
		WarpCompiler Declaration
************************************************************/

class WarpCompiler
{
protected:

	HRESULT hResult;
	
	BOOL MakeFEStream;
	BOOL MakeWEStream;
	int AlphaStream;
	// Our TFX file.
	ITrnEffectFile *	TFX;

	ITrnEffectTransform * Transform;

	IStream * WEAnimDataStream;
	IStream * FEAnimDataStream;
	IStream * AlphaAnimDataStream;


    double UScale;
    double VScale;
    double Uoffset;
    double Voffset;

	int WarpPlayListOffset;


 
	// Stream compiler
	WEMstream* WEM;

	// Frame dimensions
	int FrameWidth;
	int FrameHeight;

	// Number of fields to compile
	int NumFields;

	// What hardware actually gets used
	int WEMType;

	// Runlength compression errorbands
	int AlphaErrorBand;

	// Warp engine's playlist.
	PlayList* WarpPlayList;

	// Target Warp engine type.
	int WarpType;

	// The DVE offset in memory
	POINT VideoOffset;

	// Start on the odd or even lines?
	int StartLine;

	// The max error for the fit.
	double warp_max_u_error;
	double warp_max_v_error;

public:

	ITrnEffectMixing * Mixing;

	int WarpSourceNum;

	WarpCompiler();
	~WarpCompiler();

	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	void Init(ITrnEffectFile * _TFX,
			  int _FrameWidth,
			  int _FrameHeight,
			  int _NumFields,
			  PlayList* _WarpPlayList,
			  int _WarpSourceNum,
			  int _WEMtype,
			  int _AlphaErrorBand,
			  double _Uscale,
			  double _Vscale,
			  double _Uoffset,
			  double _Voffset,
			  POINT _VideoOffset,
			  int _StartLine
			  );

	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
	HRESULT Start();

	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(
						BYTE* WarpAlpha,
						double* Ubuffer,
						double* Vbuffer,
						BYTE* Sbuffer,
						BYTE* Hbuffer,
						BYTE* InvWarpAlpha=NULL
						);

	// Handles any post-effect processing.
	HRESULT Finish();

	// Current Effect Size Information

	ULONG GetCurrentStreamLength(int StreamIndex)
	{
		ULONG result = -1;
		if( WEM )
			result = WEM->GetCurrentStreamLength(StreamIndex);

		return result;
	}

	int GetAlphaStreamType()
	{
		return AlphaStream;
	}


	// --Things that can be called after Init(), but before Start()--

	// Set up the acceptance band for continuing a run in the main
	// alpha compressor.
	void SetAlphaErrorBand(int _NewErrorBand)
	{
		AlphaErrorBand = _NewErrorBand;
	}

	// Provide a different playlist to be written to the TFX file
	// for execution by the warp engine.
	void SetPlayList(PlayList* _PlayList)
	{
		WarpPlayList = _PlayList;
	}

	void SetWarpMethod(int _WarpType)
	{
		WarpType = _WarpType;
	}

	void SetPlayListOffset(int PlayListOffset)
	{
		WarpPlayListOffset = PlayListOffset;
	}

	void	SetEmitWEStream(BOOL _MakeWEStream)		//	Controls the writing of the WEStream
	{
		MakeWEStream = _MakeWEStream;
	}

	void	SetEmitFEStream(BOOL _MakeFEStream)		//	Controls the writing of the FEStream
	{
		MakeFEStream = _MakeFEStream;
	}

	void	SetEmitAlphaStream(long _AlphaStream)	//	Controls the writing of the AlphaStream
	{
		AlphaStream = _AlphaStream;
	}

	void SetWarpErrorBounds(double max_u, double max_v)
	{
		warp_max_u_error = max_u;
		warp_max_v_error = max_v;
	}
};


/************************************************************
		SwitcherCompiler Declaration
************************************************************/


class SwitcherCompiler
{
protected:
	int	ColorSpace;		// 0= RGB 1=YUV

	HRESULT hResult;
	HGLOBAL hYUVMem;

	// Our TFX file.
	ITrnEffectFile *	TFX;


	IStream * AnimDataStream;

	int SwitcherPlayListOffset;


	// Stream compiler
	SEMstream* SEM;

	//A buffer to hold the converted color data if passed to us.
	BYTE* YUVBuffer;
    // A pointer to 1 Field of the YUV Buffer

	BYTE* TopDownGraphicAlphaBuffer; //A conversion from Bot Up Grahics Alpha
	
	
	BYTE* dstHalfPtr;
	BYTE* DIBBottomPtr;
	BYTE* BupGraphicAlpha;
	//BYTE* TdownGraphicAlpha;
	BYTE* FinalGraphicAlpha;
	

	// Used to convert from BGR to YUV
	ColorConversion	cvt;

	// Frame dimensions
	int FrameWidth;
	int FrameHeight;

	long Line;
	long Col;

	// Number of fields to compile
	int NumFields;

	// What hardware actually gets used
	int SEMType;

	// Runlength compression errorbands
	int MainAlphaErrorBand;
	int GraphicAlphaErrorBand;

	// Switcher's playlist.
	PlayList* SwitcherPlayList;

	// Start on the odd or even lines?
	int StartLine;

public:


static	ITrnEffectMixing * Mixing;

	SwitcherCompiler();
	~SwitcherCompiler();

	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	void Init(
			ITrnEffectFile *	_TFX,
			int _FrameWidth,
			int _FrameHeight,
			int _NumFields,
			PlayList* _SwitcherPlayList,
			int _SEMtype,
			int _MainAlphaErrorBand,
			int _GraphicAlphaErrorBand,
			int _StartLine
			);

    // Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
	HRESULT Start();

	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(
						BYTE* MainAlpha,
						BYTE* GraphicAlpha,
						BYTE* BGRBuffer
						);

    // Handles any post-effect processing.
    HRESULT Finish();

	// Current Effect Size Information

	ULONG GetCurrentStreamLength(int StreamIndex)
	{
		ULONG result = -1;
		if( SEM )
			result = SEM->GetCurrentStreamLength(StreamIndex);

		return result;
	}


	// --Things that can be called after Init(), but before Start()--

	// Set up the acceptance band for continuing a run in the main
	// alpha compressor.
	void SetMainAlphaErrorBand(int _NewErrorBand)
	{
		MainAlphaErrorBand = _NewErrorBand;
	}

	// Do the same as above, but for the graphics alpha.
	void SetGraphicsAlphaErrorBand(int _NewErrorBand)
	{
		GraphicAlphaErrorBand = _NewErrorBand;
	}

	// Provide a different playlist to be written to the TFX file
	// for execution by the switcher.
	void SetPlayList(PlayList* _PlayList)
	{
		SwitcherPlayList = _PlayList;
	}

	void SetPlayListOffset(int PlayListOffset)
	{
		SwitcherPlayListOffset = PlayListOffset;
	}
	void SetColorSpace(int cs){
		ColorSpace=cs;
	}
};




/************************************************************
		EffectCompiler Declaration
			Base Class for an EffectType
************************************************************/


class	EffectCompiler
{

protected:
		// Frame dimensions
	int	FrameHeight;
	int FrameWidth;

	SwitcherCompiler* Switcher;
	HRESULT hResult;
	int refcount;

	// Our TFX file.
	ITrnEffectFile *	TFX;

	ITrnEffectLayering *	Layering;


	BYTE* Sbuffer;		// NOT USED AS OF COMDEX '96
	BYTE* Hbuffer;		// NOT USED AS OF COMDEX '96


	// Number of fields to compile
	int FieldCount;
	// Number of fields already  processed
	int	FieldsProcessed;

	// Which bus contains the warp
	int WarpSourceNum;
	int WarpSourceNum2;
	int WarpSourceNum3;

	int MainAlphaErrorBand;
	int GraphicsAlphaErrorBand;
	int WarpAlphaErrorBand;
	int WarpAlphaErrorBand2;
	int WarpAlphaErrorBand3;

	// Stream compiler

	WarpCompiler* Warp;
	WarpCompiler* Warp2;
	WarpCompiler* Warp3;

	// Switcher's playlist.
	PlayList * SwitcherPlayList;
	// Warp engine's playlist.
	PlayList * WarpPlayList;
	PlayList * WarpPlayList2;
	PlayList * WarpPlayList3;

	// What hardware actually gets used
	int	SEMType;
	int WEMType;

	// What Mode: NTSC or PAL?
	int VideoMode;
	POINT VideoOffset;

	// Start on odd or even line?
	int StartLine;

	CDIB* PiconDIB;


	
	WORD	EffectAttributes;

	HRESULT	WriteStream( IStream* pStrm, void* pBuffer, ULONG BytesToWrite);
	HRESULT EffectCompiler::CreateInputsSection( ITrnEffectFile* pTFX );
	HRESULT EffectCompiler::CreatePicon( ITrnEffectFile* pTFX, HBITMAP hbmp);


    void InitEffectAttributes(BOOL _EffectIsTransition,
				BOOL	_ChromaOffAtEnd,
                BOOL    _ChromaShadowActive);


	HRESULT EffectCompiler::SetupEffectDimensions(
                        int     fields,
                        int     rows,
                        int     columns);

    HRESULT OpenEffectFile(char*    szEffectFileName);

    HRESULT CloseEffectFile();

public:
	
	EffectCompiler();

	BOOL SafeToUse;		// Indicates successful object allocation in constructor

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
	HRESULT	Start();	
	// Handles any post-effect processing.
	HRESULT	Finish();

	// Set up the acceptance band for continuing a run in the main
	// alpha compressor.
	void SetMainAlphaErrorBand(int ErrorBand);
	// Do the same as above, but for the graphics alpha.
	void SetGraphicsAlphaErrorBand(int ErrorBand);
	
	// Provide a different playlist to be written to the TFX file
	// for execution by the switcher.
	void SetSwitcherPlayList(PlayList* _PlayList);

	void SetSwitcherPlayListOffset(int PlayListOffset);

	void SetDebugSeg(int _DebugSeg);
	void SetVideoMode(int _Mode);
	void SetVideoOffset(long _x, long _y);
	void SetWarpErrorBounds(double max_u, double max_v);
	void SetAlphaErrorBand(int ErrorBand);

	// Provide a different playlist to be written to the TFX file
	// for execution by the warp engine.
	void SetWarpPlayList(PlayList* _PlayList);
	void SetWarpPlayListOffset(int PlayListOffset);
	void SetWarpMethod(int WarpType);
	void SetEmitWEStream(BOOL _MakeWEStream);
	void SetEmitFEStream(BOOL _MakeFEStream);
	// Set up the acceptance band for continuing a run in the 
	// alpha compressor.
	void SetAlphaErrorBand1(int ErrorBand);

	// Provide a different playlist to be written to the TFX file
	// for execution by the warp engine.
	void SetWarpPlayList1(PlayList* _PlayList);
	void SetWarpPlayListOffset1(int PlayListOffset);
	void SetWarpMethod1(int WarpType);
	void SetEmitWEStream1(BOOL _MakeWEStream);
	void SetEmitFEStream1(BOOL _MakeFEStream);

	// Set up the acceptance band for continuing a run in the 
	// alpha compressor.
	void	SetAlphaErrorBand2(int ErrorBand);

	// Provide a different playlist to be written to the TFX file
	// for execution by the warp engine.
	void SetWarpPlayList2(PlayList* _PlayList);
	void SetWarpPlayListOffset2(int PlayListOffset);
	void SetWarpMethod2(int WarpType);
	void SetEmitWEStream2(BOOL _MakeWEStream);
	void SetEmitFEStream2(BOOL _MakeFEStream);

		// Set up the acceptance band for continuing a run in the 
	// alpha compressor.
	void SetAlphaErrorBand3(int ErrorBand);

	// Provide a different playlist to be written to the TFX file
	// for execution by the warp engine.
	void SetWarpPlayList3(PlayList* _PlayList);
	void SetWarpPlayListOffset3(int PlayListOffset);
	void SetWarpMethod3(int WarpType);
	void SetEmitWEStream3(BOOL _MakeWEStream);
	void SetEmitFEStream3(BOOL _MakeFEStream);



	// Current Effect Size Information
	// --- this feels kludgey, I think it would be better to use Warp and Switcher object calls

	ULONG GetCurrentStreamLength(int BoardID, int BoardIndex, int StreamIndex)
	{
		ULONG result = -1;

		switch( BoardID )
		{
		case 0 :
			if( Switcher && 0 == BoardIndex )
				result = Switcher->GetCurrentStreamLength(StreamIndex);
			break;

		default :
			{
				WarpCompiler* pWarp = NULL;
				switch( BoardIndex )	// why are these not an array?
				{
				case 0 :
					pWarp = Warp;
					break;
				case 1 :
					pWarp = Warp2;
					break;
				case 2 :
					pWarp = Warp3;
					break;
				}

				if( pWarp )
				{
					switch( BoardID )
					{
					case PLAY_UPAC_DVE_ID :
					case PLAY_DNAC_DVE_ID :
						if( pWarp->GetAlphaStreamType() == BoardID )
							result = pWarp->GetCurrentStreamLength(WEMstream::STREAM_ALPHA);
						break;

					case PLAY_WE_DVE_ID :
						result = pWarp->GetCurrentStreamLength(WEMstream::STREAM_ALUWE);
						break;
					case PLAY_FE_DVE_ID :
						result = pWarp->GetCurrentStreamLength(WEMstream::STREAM_ALUFE);
						break;
					}
				}
			}
			break;
		}

		return result;
	}

	//	If you want to pass the effect compiler 444YUV instead of 444RGB you should call this
	//	function first.
	void SetColorSpace(int cs){	// 0 for RGB, 1 for YUV
		if (Switcher) Switcher->SetColorSpace(cs);
	}
};



// ATTEMPT eliminates the tedium of typing the same thing ninety percent of the time.
// If the call to 'arg' fails, leave where we are, returning the error to our
// caller.
#define ATTEMPT(arg) if ((hResult=(arg))!=EFX_OK) return hResult

#endif //__FXcomp_h__