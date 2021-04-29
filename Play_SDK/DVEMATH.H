#ifndef dvemath_h
#define dvemath_h

#define NOMINMAX
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// ----Debug defines:
//#define DebuggingSolver
//  Causes the solver to print out all intermediate steps in
//  system solving stage as well as Mathematica compatible input
//  which can be used to verify the solution to the system.


// :: Class Seg :: --------------------------------------------------
class Seg
/*
  A segment is a polynomial (now a quadratic) describing a fetch path
  along one (of at least two) of the surfaces which describe an image.
*/
{
  double s, l, c;      // squared, linear, and constant terms.

  public:
  double t, dt, ddt;
  void Init(void);
    // Initialize the forward difference version of the quadratic.

  double Next(void);
    // Return the next (pre-increment) value from the forward diff quadratic.

  Seg () : s(0), l(0), c(0) {};
  Seg (double sq, double ln, double cn) : s(sq), l(ln), c(cn) { Init(); }
    // Construct and initialize a forward difference quadratic.

  void Set (double x1, double y1,
            double x2, double y2,
            double x3, double y3);
    //Set the segment using the three-point form.

  void Set (double sq, double ln, double cn);

  double Value(double x)
  {
    return s*x*x + l*x + c;
  }

  double Slope(double x)
  {
    return 2*s*x+l;
  }

  void Translate(int offset);
  // Translates the origin of the current seg by offset.

  void Scale(double scale);
  // Scale the polynomial form of the segment and reinit the forward diff.

  void Offset(double offset);
  // Add an offset to the polynomial form of the segment and update
  // the forward difference.

	void Dump (HANDLE outfile);
};

// :: Class AreaPoly :: ---------------------------------------------
class AreaPoly
/*
  This class supports evaluation of the polynomials used throughout the
  the gadget.
*/
{

  double coeff[9];

  public:
  AreaPoly ();

  double Value(double x, double y);
    // Return the value of the areapoly evaluated at (x,y).

  Seg XTrace(double y, double x);
    // Return the seg of the areapoly translated to (0,y).

  double& operator[](int n)
    // Return the nth coefficient of the areapoly.
  {
    return coeff[n];
  }

  double cost();
    // Return an estimation of the time required to render this areapoly.

	void Dump(HANDLE outfile);
	  // Dumps the coefficients of the areapoly to a file (for a report).

  void Accumulate(AreaPoly &x);
    // Does a polynomial addition of the passed areapoly to ourselves.

  void SetZero();
    // Set our value to the zero polynomial.

};

// :: Class SubTrace :: ---------------------------------------------
//  SubTraces are one coordinate's worth of information for a
//  renderable Trace.  SubTraces are now used directly.  They are
//  paired with other subtraces to make a Trace.

class SubTrace
{
public:
  Seg segment;        //The segment describing the path
  int length;         //Number of pixels remaining in this SubTrace
  int position;       //This scanline's origin

  SubTrace()
  {
    length=0;
    position=0;
  }

  BOOL IsEmpty()
  {
    return length==0;
  }

  int Reduce(int ByLength)
  {
    segment.Translate(ByLength);      //Move our segment's origin
    position += ByLength;       //Move our origin
    return (length-=ByLength);  //report the number of pixel we have.
  }

  double NextPosition()
  {
    //value of the segment at one pixel PAST the end of the segment.
    return segment.Value(length);
  }

  double NextSlope()
  {
    //slope of the segment at one pixel PAST the end of the segment.
    return segment.Slope(length);
  }

  void Set(double sq, double ln, double cn, int len, int pos)
  {
    segment.Set(sq,ln,cn);
    length=len;
    position=pos;
  }

  void Set(Seg _s, int len, int pos)
  {
    segment=_s;      //naive copy
    segment.Init();  //reset it for use
    length=len;      //initialize the forward differencer
    position=pos;
  }

};

// :: Class Trace :: ------------------------------------------------
class Trace
/*
  Trace describes the fetch path in parametric space, along with the
  destination for the fetched colors.
*/
{
  public:

  int xdest, ydest;     //Next pixel destination.
  int xstrt, ystrt;     //First pixel destination.  Used when First() called.
  int stop;             //Last pixel destination. A convenience variable.
  int len;              //Length of trace.

  Seg uSeg, vSeg;

  Trace();
  Trace(AreaPoly &uPoly, AreaPoly &vPoly, int x1, int x2, int y);
  void PartialInitialize(int x1, int x2, int y);
  void First();
  int Next(int& xd, int& yd, double&xr, double& yr);
  void GlueTo(Trace& other);

  BOOL IsAdjacentTo(Trace& other)
  {
    return ( (ydest==other.ydest) && (xstrt+len==other.xstrt) );
  }

  void Set(Seg u, Seg v, int x, int y, int len);

  // Scale the trace components.
  void Scale(double uScale, double vScale);

  // Offset the trace components.
  void Offset(double uOffset, double vOffset);

	void dump(HANDLE outfile);
};

// :: Class Solver :: -----------------------------------------------

class Solver
{
  private:
    double sys[9][10];
    void swaprow (double *a, double *b);

  public:

    Solver();
    #ifdef DebuggingSolver
      void PrintSystem(double sys[][10]);
			void PrintSystemForMathematica(double sys[][10]);
    #endif
    void AddPoint(int xi, int yi, double z, double w=1.0);
    void SolveSystem(AreaPoly &ap);
};

#endif