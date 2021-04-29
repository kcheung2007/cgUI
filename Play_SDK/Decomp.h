#ifndef decomp_h
#define decomp_h

#define NOMINMAX
#include <windows.h>
#include <list.h>
#include "tracegen.h"

#include "alucomp.h"
#include "dvecutil.h"

// -- :: Debugging defines :: ---------------------------------------
//#define DebuggingAnything
// Define this if you're going to debug anything.


//#define ShowingScans
//  Causes the routines involved in pixel processing to show
//  which pixels are under evalutation.

//#define ShowingDifferences
//  Causes a colormap to be plotted.  This colormap corresonds to
//  the classification of areas of the coordinate surfaces with
//  respect to their relationship with the target surfaces.

//#define ShowingBounds
//  If enabled, the bouding boxes for regions will be plotted just
//  prior to the error evaluation stage.

//#define ShowingTexture
//  If ShowingTexture is defined, the current region under evaluation
//  will be used as the texture map, and a (supplied) texture will
//  be applied to pixels under evaluation.

//#define ShowingFinalMap
//  When defined, the program will plot the derived texture map
//  directly from the segments passed to the dve kernel compilation
//  stage.

//#define PrintingProgress
//  Causes some of the routines to print (via printf) vaguely
//  interesting information about what's going on.

// ---- End of debugging defines ----
// Maximum distance away from target surface.

#define TOLERANCE 2.0






//--- :: Debugging Functions :: --------------------------------------
#ifdef DebuggingAnything

#include "safedc.h"

#endif



// :: Template Image :: ----------------------------------------

// Template for generalizing 2D images as used in this module.
// This way we can get (contiguous) buffers of any size, passed to us
// as pointers, references, or globals, and treat them in a
// consistant arraylike fashion.

// All Image buffers have range [(0,0), (MaxX, MaxY)).

extern int MaxX;
extern int MaxY;

template <class T>
class Image2D
{
public:


  T* base;

  Image2D() {
	  base=NULL;
	//	MaxX = MaxY = 0;
  }
  Image2D(T* _T) : base(_T) {}

  T& operator()(int x, int y)
  {
    return *(base+(y*MaxX)+x);
  }

  BOOL inrange(int x, int y)
  {
    return x>=0 && x<MaxX && y>=0 && y<MaxY;
  }

  T* lineaddr(int y)
  {
    return base+y*MaxX;
  }

  void zero()
  {
    memset( base, 0, sizeof(T)*MaxX*MaxY);
  }

  DWORD size()
  {
    return MaxX*MaxY*sizeof(T);
  }

};


class Decomp
{
public:


// :: Debug Support :: ----------------------------------------

#if (defined ShowingScans) || (defined ShowingFinalMap) || (defined ShowingTexture)

SafeDC* DebugDC;

#endif

#if (defined ShowingTexture) || (defined ShowingFinalMap)
//  #include "cdib.h"
//  CDIB texture;
#endif



// ---:: Module Globals :: ------------------------------------------------ //

// A series of 2D accessor objects for buffers:  For each pixel (x,y) in the
// the output image,
Image2D<double> image_v;           // u surface value at this pixel
Image2D<double> image_u;           // v surface value at this pixel
Image2D<BYTE>   alpha;             // alpha value for this pixel

double uScale;                   //The output traces are scaled by
double vScale;                   //by these variables at emission.
double uOffset;
double vOffset;
POINT	VideoOffset;	// the offset for the DVE in memory

list<Trace>*  FieldList;    // pointer to list containing traces for current field

ALUFIFO* OurFieldFIFO;           // We build our programs into this FIFO.
ControlFrameGenerator* CtlProgram; //A pointer to the control program
BYTE**   ALUBufAddrOutputPtr;	   // Ptr to ptr to FIFO buffer (we fill in the ptr)
int*     ALUBufLenOutputPtr;	   // ptr to length of buffer (we fill this in too)
BYTE**   ControlBufAddrOutputPtr; // same as above but for control buffer
int      start_line;             // Field scanline start value (...0 or 1)
double   max_u_error;            // maximum acceptible error in the u direction
double   max_v_error;            // same but for v.
FitMethod method;                // fitting method

HANDLE decomp_input_file;
HANDLE decomp_output_file;

DWORD Grid(double u, double v)
{
  return (((int)u % 20)<5) || (((int)v % 20)<5) ?
    RGB(((BYTE)(u*255/MaxX)), ((BYTE)(v*255/MaxY)), 100): RGB(50,50,50);
}

void ReviseSegments(list<Trace>& tl)
{
  list<Trace>::iterator first=tl.begin();
  if (first==tl.end()) return;    //null list

  int currentY=(*first).ydest;

  list<Trace>::iterator second=++first;
  if (second==tl.end()) return;   //not enough segments

  // Tranverse through the list of segments, FORCING
  // adjacent Traces to be C0 continuous.
  while (second != tl.end())
  {
    if ((*first).IsAdjacentTo(*second))
      (*first).GlueTo(*second);
    first=second++;
  }
}

#ifdef ShowingFinalMap
void ShowFinalMap()
{
  int x, y;
  double u, v;

  for(list<Trace>::iterator t=FieldList->begin(); t!=FieldList->end(); t++)
  {
    if((*t).Next(x,y,u,v))
      DebugDC->SetPixel(x,y,RGB(255,255,0));
    while((*t).Next(x,y,u,v))
      if( alpha.inrange((int)u,(int)v) )
        //DebugDC->SetPixel(x, y,texture.GetColor((int)u,(int)v));
        DebugDC->SetPixel(x, y, Grid((int)u, (int)v));
      else
        DebugDC->SetPixel(x, y, RGB(255,0,255));
  }
}
#endif


public:

Decomp();

#ifdef DebuggingAnything

// Allows some graphical debuggin information to be plotted.
BOOL DVECompilerDebugStart(SafeDC* outDC);

// Performs a mapping of TEXTURE.BMP in the current directory,
// to outDC.
void ShowInitialTexture(double* u_buffer, double* v_buffer, BYTE* a_buffer);



#endif

// Changes the default acctible error bounds.
void SetErrorBounds(double max_u, double max_v);


// Dumps the Traces generated in a human readable form to the file
// name.
void DumpTraces(char* name);
//--- :: Client Functions :: -----------------------------------------

BOOL DVECompilerStart(
    int ImageSizeX,             //number of pixels per line in buffer
    int ImageSizeY,				//number of lines in buffer
	POINT _VideoOffset,		// the offset for the DVE in memory
	int _Start_Line=1,			// Start on even or odd line?
    BYTE** ALUBufPtr=NULL,      //pointer to where we put ALU buffer address
    int* Length=NULL,           //pointer to where we put the ALU bu length
    BYTE** ControlBufPtr=NULL   //pointer to control Image 
);

BOOL DVECompilerDone();

void ScaleImage(double* Ubuffer,              //U coordinate buffer for this image
				double* Vbuffer              //V coordinate buffer for this image
				);

void AdvanceImage(void);

void DecomposeImage(
    double* Ubuffer,              //U coordinate buffer for this image
    double* Vbuffer,              //V coordinate buffer for this image
    BYTE*   Abuffer,              //Alpha buffer for this image
    int     interlinedistance=2   //vertical displacement between active lines in the buffers
);

void RenderFrame (int maxcost=0, HANDLE outfile=INVALID_HANDLE_VALUE);

void OverrideMethod(FitMethod _method);

void SetTextureScale(double _uScale=1.0, double _vScale=1.0);

void SetTextureOffset(double _uOffset=0.0, double _vOffset=0.0);

BOOL OpenInputDecompFile(char* infilename);

BOOL CloseInputDecompFile();

BOOL ReadDecompImage();

BOOL OpenOutputDecompFile(char* outfilename);

BOOL CloseOutputDecompFile();

BOOL WriteDecompImage();
};
#endif