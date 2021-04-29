#ifndef __EFXCOMP__
#define __EFXCOMP__
/*****************************************************

  EFXcomp.h

		Header file for EffectCompiler derived classes
	including EffectTypes 1-8

******************************************************/

#include	"FXcomp.h"


//	Type1ffectCompiler	Declaration
// a type I FX is a simple Switcher alpha wipe
class   Type1EffectCompiler : public EffectCompiler
{
private:

public:
	Type1EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
		ITrnEffectFile *	_TFX,
		int			fields,
		int			rows,
		int			columns,
		BOOL		IsTransition,
		PlayList*	playlist,
		HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(    BYTE* MainAlpha);

	// Handles any post-effect processing.
//	HRESULT	Finish();
	// --Things that can be called after Init(), but before Start()--
};


//	Type2EffectCompiler	Declaration
// a type II FX is a simple soft Switcher graphics overlay
class   Type2EffectCompiler : public EffectCompiler
{
private:

public:
	Type2EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
		ITrnEffectFile *	_TFX,
		int			fields,
		int			rows,
		int			columns,
		BOOL		IsTransition,
		PlayList*	playlist,
		HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();

	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* GraphicAlpha,
						 BYTE* WindowsDIBbuffer);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type3EffectCompiler	Declaration
// a type III FX is a Switcher alpha wipe with colored content
class	Type3EffectCompiler : public EffectCompiler
{
private:

public:
	Type3EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
		ITrnEffectFile *	_TFX,
		int			fields,
		int			rows,
		int			columns,
		BOOL		IsTransition,
		PlayList*	playlist,
		HBITMAP hbmp);

	
	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* MainAlpha,
						 BYTE* GraphicAlpha,
						 BYTE* WindowsDIBbuffer);

	// Handles any post-effect processing.
//	HRESULT	Finish();


	// --Things that can be called after Init(), but before Start()--
};


//	Type4EffectCompiler	Declaration
// a type IV FX is a soft Warp
class	Type4EffectCompiler : public EffectCompiler
{
private:

public:
	Type4EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
HRESULT	Init(
			ITrnEffectFile *	_TFX,
			int			fields,
			int			rows,
			int			columns,
			BOOL		IsTransition,
			int			WarpSourceNum,
			PlayList*	playlist,
			double		Uscale,
			double		Vscale,
			double		Uoffset,
			double		Voffset,
			HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField( BYTE* WarpAlpha,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type5EffectCompiler	Declaration
// a type V FX is a hard Warp (one video source) with colored Switcher content
class	Type5EffectCompiler : public EffectCompiler
{
private:

public:
	Type5EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().

	HRESULT	Init(
			ITrnEffectFile *	_TFX,
			int			fields,
			int			rows,
			int			columns,
			BOOL		IsTransition,
			int			WarpSourceNum,
			PlayList*	playlist,
			double		Uscale,
			double		Vscale,
			double		Uoffset,
			double		Voffset,
			HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT	ProcessField(BYTE* WarpAlpha,
						BYTE* GraphicAlpha,
						BYTE* WindowsDIBbuffer,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();


	// --Things that can be called after Init(), but before Start()--
};



//	Type6EffectCompiler	Declaration
// a type VI FX is a soft Warp (two video sources) with colored Switcher content
class	Type6EffectCompiler : public EffectCompiler
{
private:


public:
	Type6EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				int			WarpSourceNum,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* MainAlpha,
						BYTE* GraphicAlpha,
						BYTE* WindowsDIBbuffer,
						BYTE* WarpAlpha,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type7EffectCompiler	Declaration
// a type VII FX is a soft Warp (one video source) with (inverted) downstream alpha
// (from a video file), set up to do cheap ChromaKeying
class	Type7EffectCompiler : public EffectCompiler
{
private:


public:
	Type7EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				BOOL		ChromaOffAtEnd,
				int			WarpSourceNum,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* WarpAlpha,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.	
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type8EffectCompiler	Declaration
// a type VIII FX is a soft Warp (one video source) with Key Priority Layering
// to hide the area outside of the warp, set up to do correct ChromaKeying
class	Type8EffectCompiler : public EffectCompiler
{
private:

public:
	Type8EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
		ITrnEffectFile *	_TFX,
		int			fields,
		int			rows,
		int			columns,
		BOOL		IsTransition,
		BOOL		ChromaOffAtEnd,
		BOOL		ChromaShadowActive,
		int			WarpSourceNum,
		PlayList*	playlist,
		double		Uscale,
		double		Vscale,
		double		Uoffset,
		double		Voffset,
		HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* WarpAlpha,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type9EffectCompiler	Declaration
// a type VIV FX is a soft Warp (two video sources) with Graphic content
class	Type9EffectCompiler : public EffectCompiler
{
private:


public:
	Type9EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				BOOL		ChromaOffAtEnd,
				int			WarpSourceNum,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT	ProcessField(BYTE* WarpAlpha,
						BYTE* GraphicAlpha,
						BYTE* WindowsDIBbuffer,
						double* Ubuffer,
						double* Vbuffer
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};

//	Type52EffectCompiler	Declaration
// a type 52 FX is a TWO source soft Warp (two video sources) with colored Switcher content
class	Type52EffectCompiler : public EffectCompiler
{
private:


public:
	Type52EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				int			WarpSourceNum1,
				int			WarpSourceNum2,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* GraphicAlpha,
						BYTE* WindowsDIBbuffer,
						BYTE* WarpAlpha1,
						double* Ubuffer1,
						double* Vbuffer1,
						BYTE* WarpAlpha2,
						double* Ubuffer2,
						double* Vbuffer2
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};


//	Type42EffectCompiler	Declaration
// a type 52 FX is a TWO source soft Warp (two video sources) with colored Switcher content
class	Type42EffectCompiler : public EffectCompiler
{
private:


public:
	Type42EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				int			WarpSourceNum1,
				int			WarpSourceNum2,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* WarpAlpha1,
						double* Ubuffer1,
						double* Vbuffer1,
						BYTE* WarpAlpha2,
						double* Ubuffer2,
						double* Vbuffer2
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};

//	Type43EffectCompiler	Declaration
// a type 43 FX is a THREE source HARD EDGE Warp (two video sources) over Matte.
class	Type43EffectCompiler : public EffectCompiler
{
private:


public:
	Type43EffectCompiler();

	// Function:	Init
	// Sets up working parameters for the duration of the effect.
	// There is an opportunity for changing some of the parameters
	// prior to actually processing the effect.  To do this though,
	// the client must set them up prior to calling Start().
	HRESULT	Init(
				ITrnEffectFile *	_TFX,
				int			fields,
				int			rows,
				int			columns,
				BOOL		IsTransition,
				int			WarpSourceNum1,
				int			WarpSourceNum2,
				int			WarpSourceNum3,
				PlayList*	playlist,
				double		Uscale,
				double		Vscale,
				double		Uoffset,
				double		Voffset,
				HBITMAP hbmp);

	// Function:	Start
	// Actually begins the processing of effect.  All internal initialization
	// is handled in this routine.
//	HRESULT	Start();	
	
	// Function:	ProcessField
	// Processes the input frame buffers an places them into the TFX file.
	HRESULT ProcessField(BYTE* WarpAlpha1,
						double* Ubuffer1,
						double* Vbuffer1,
						BYTE* WarpAlpha2,
						double* Ubuffer2,
						double* Vbuffer2,
						BYTE* WarpAlpha3,
						double* Ubuffer3,
						double* Vbuffer3
						);

	// Handles any post-effect processing.
//	HRESULT	Finish();

	// --Things that can be called after Init(), but before Start()--
};

#endif //__EFXCOMP__