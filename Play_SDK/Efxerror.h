#define EFX_OK										0
// All is well

#define EFX_ERR_ALREADY_OPEN						1
// The effect compiler already has a file open, and the client
// opened it again.

#define EFX_ERR_FILE_NOT_OPEN						2
// The client tried to do something that requires that the effect
// file be open.

#define EFX_ERR_NO_MORE_FIELDS						3
// The client attempted to process more fields that has been declared
// when the file was opened.  Further field information will not fit into
// some preallocated buffers.

#define EFX_ERR_NOT_IMPLEMENTED_YET					4
// A call was made to a function which is declared for future use, but
// has no usable implemention...yet..

#define EFX_ERR_ODD_FIELDCOUNT						5
// The user attempted to create an effect with an odd number of fields.
// We do not allow this.

#define EFX_ERR_FRAME_DIMENSIONS					6
// We got very strange frame dimensions.

#define EFX_ERR_CREATE_SWITCHER_MIXING				7
// Call to TFX->CreateMixing Failed

#define EFX_ERR_CREATE_SWITCHER_ISTREAM				8
// Call to Mixing->SetAnimData Failed

#define EFX_ERR_SET_SWITCHER_TIMING_DATA			9
// Call to Mixing->SetTimingData Failed

#define EFX_ERR_CREATE_SEMSTREAM_OBJECT				10
// Could not create a SEMStream Object

#define EFX_ERR_ALLOCATE_YUV_BUFFER					11
// Could not allocate Switcher Graphic YUV data buffer!

#define EFX_ERR_FINISH_SEMSTREAM					12
// Error finishing the Switcher data stream!

#define EFX_ERR_CREATE_TRANSFORM					13
// Couldn't create the WarpEngine Transform!

#define EFX_ERR_CREATE_WARP_ISTREAM					14
// Couldn't set up the WarpEngine stream!

#define EFX_ERR_SET_WARP_TIMING_DATA				15
// Couldn't set the WarpEngine Timing Data!

#define EFX_ERR_CREATE_WEMSTREAM_OBJECT				16
// Could not create a WEM stream object!

#define EFX_ERR_FINISH_WEMSTREAM					17
// Error finishing the Warp Engine data stream!

#define EFX_ERR_CREATE_LAYERING						18
// Couldn't create the WarpEngine Layering!

#define EFX_ERR_SET_LAYER_ENTRY						19
// Call to Layering->SetLayerEntry failed!
// Couldn't set a WarpEngine Layer!

#define EFX_ERR_CREATE_INPUT_SECTION				20
// Call to TFX->CreateInputsSection Failed!

#define EFX_ERR_CLOSE_TFX_FILE						21
// Cannot close TFX file

#define EFX_ERR_CREATE_PICON						22
// Call to TFX->CreatePicon Failed!


//****************	SEMSTREAM ERRORS ******************

#define EFX_ERR_SEMSTATUS_OK						30
// everything is OK

#define EFX_ERR_SEMSTATUS_TYPE						31
// invalid 'SEMtype'

#define EFX_ERR_SEMSTATUS_RAM						32
// couldn't alloc RAM

#define EFX_ERR_SEMSTATUS_NUMFRAMES					33
// invalid 'numFields'

#define EFX_ERR_SEMSTATUS_NOSTART					34
// Finish() called without Start()

#define EFX_ERR_SEMSTATUS_REWRITE_HEADER			35
// error rewriting SEM stream header

#define EFX_ERR_SEMSTATUS_SEMSTREAMCREATE			37
// error creating SEM stream ISTream

#define EFX_ERR_SEMSTATUS_SHORTFRAMES				38
// not enough frames compiled

#define EFX_ERR_SEMSTATUS_LONGFRAMES				39
// too many frames compiled

#define EFX_ERR_SEMSTATUS_BLOCKWRITE				40
// error writing block to SEMstream IStream

#define EFX_ERR_SEMSTATUS_BLOCKREWRITE				41
// error rewriting block in SEMstream IStream

#define EFX_ERR_SEMSTATUS_SEEK						42
// error seeking in SEMstream IStream


//****************	WEMSTREAM ERRORS ******************

#define EFX_ERR_WEMSTATUS_OK						50
// everything is OK

#define EFX_ERR_WEMSTATUS_TYPE						51
// invalid 'WEMtype'

#define EFX_ERR_WEMSTATUS_RAM						52
// couldn't alloc RAM

#define EFX_ERR_WEMSTATUS_NUMFRAMES					53	
// invalid 'numFields'

#define EFX_ERR_WEMSTATUS_NOSTART					54
// Finish() called without Start()

#define EFX_ERR_WEMSTATUS_REWRITE_HEADER			55
// error rewriting WEM stream header

#define EFX_ERR_WEMSTATUS_SHORTFRAMES				58
// not enough frames compiled

#define EFX_ERR_EMSTATUS_LONGFRAMES					59
// too many frames compiled

#define EFX_ERR_WEMSTATUS_BLOCKWRITE				60
// error writing block to WEMstream IStream

#define EFX_ERR_WEMSTATUS_BLOCKREWRITE				61
// error rewriting block in WEMstream IStream

#define EFX_ERR_WEMSTATUS_SEEK						62
// error seeking in WEMstream IStream

#define EFX_ERR_WEMSTATUS_DVE_FACEINIT				65
// error calling Greg's DVEFaceInit()

#define EFX_ERR_WEMSTATUS_DVE_DECOMPOSE				66
// error calling Greg's DecomposeImage()

#define EFX_ERR_WEMSTATUS_DVE_RENDERFRAME			67
// error calling Greg's RenderFrame()

#define EFX_ERR_WEMSTATUS_DVE_COMPILERDONE			68
// error calling Greg's DVECompilerDone()



