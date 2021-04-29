//============================================================================
//  PlayList.H
//
//  Contents: Definitions and declarations for time varying parameter value
//            iterators in the Trinity Core API.  PlayLists define a
//            mapping from a time index, which is ever increasing, to a
//            parameter index.
//
//  History:  September 5,  1995  cpdaniel  created
//            February 15,  1996  cpdaniel  last modified
//            April 8,      1996  mdhelmke  added member function to give back
//                                          current iterator
//            June 28,      1996  cpdaniel  added enumerateEvents
//            August 16,    1996  cpdaniel  added cubic, ramp w/fractional start
//
//============================================================================
#ifndef __playlist_h__
#define __playlist_h__

#ifndef __ITrnAutomationController_INTERFACE_DEFINED__
typedef struct tagSTrnPlayList
{
    DWORD   schemeSize;     // size of iteration scheme data
    LPVOID  pIterationScheme;
    DWORD   tableSize;      // size of remap table in elements
    DWORD   tableEltSize;   // size of table elements in bytes (1,2,4)
    LPVOID  pMapTable;
} STrnPlayList;
#endif

#ifdef _MSC_VER
class PlayList : private tagSTrnPlayList
#else
#include "refcount.h"
class PlayList : private tagSTrnPlayList, public RefCounted
#endif
{
  public:
    //========================================================================
    // Elemental data structures
    //========================================================================
    //
    // All fields of interface structures are aligned DWORDS to avoid big-
    // little-endian difficulties and inefficiencies
    //

    //
    // All PlayList structures include space for "current" values.
    // The only context information which a client needs to store between
    // time indexes is a "current pointer" and a "start pointer".
    //

    //
    // Ramp Structure
    //
    // A Ramp defines a straight-line mapping from time index to parameter index.
    // The ramp is specified by a starting value, an increment, and a duration.
    // The increment value is divided by 65536 when producing the ramp.
    // This specification allows for ramps with an increment of 0.  A duration
    // of 0 will result in MAXLONG iterations.
    //
    typedef struct
    {
      unsigned long  start;         // value of ramp at time index 0
      long           increment;     // signed increment per time index
      unsigned long  duration;      // number of values produced by the ramp
      unsigned long  currentvalue;  // current value of ramp
      unsigned long  currentcount;  // current iteration count of ramp
    } STrnRamp;

    // Cubic Structure
    //
    // A Cubic defines a third order polynomial mapping from time index to
    // parameter index.
    //
    // At each advance(), dx is added to x, then ddx to dx, then dddx to ddx
    //
    // Equations for cubic segments:
    //  x(t)   = initx + t*initdx + t*(t-1)*initddx/2 + t*(t-1)*(t-2)*dddx/6
    //  dx(t)  = initdx + t*initddx + t*(t-1)*dddx/2
    //  ddx(t) = initddx + t*dddx
    //
    // Cannonical cubic:
    //  x(t) = at^3 + bt^2 + ct + d
    //
    // For segment starting at t=0
    //  initx   = d            d  = initx
    //  initdx  = a+b+c        c  = initdx - initddx/2 + dddx/3
    //  initddx = 6a+2b        b  = initddx/2 - dddx/2
    //  dddx    = 6a           a  = dddx/6
    //
    // To scale an existing segment by s: t' = st (i.e. take 's' times as long to
    // reach the same value)
    //  a'        = a/s^3
    //  b'        = b/s^2
    //  c'        = c/s
    //  d'        = d
    //  initx'    = initx
    //  initdx'   = (6*initdx-3*initddx+2*dddx)/(6*s) + (initddx-dddx)/(2*s^2) + dddx/s^3
    //  initddx'  = (initdx-dddx)/s^2 + dddx/s^3
    //  dddx'     = dddx/s^3
    //
    typedef struct
    {
      long            initx;        // value of cubic at time index 0
      long            initdx;       // value of first difference at time 0
      long            initddx;      // value of second different at time 0
      long            dddx;         // value of third difference (constant)
      unsigned long   duration;     // number of values produced by the ramp
      long            currx;        // current x
      long            currdx;       // current dx
      long            currddx;      // current ddx
      unsigned long   currcount;    // remaining time
    } STrnCubic;


    //
    // Iterator Structure
    //
    // An iterator repeats a nested PlayList one or more times.  The
    // nested scheme may include ramps, other iterators, or indefinite loops.
    // An iterator always has a matching Block End following the iterated
    // section.
    //
    typedef struct
    {
      unsigned long  duration;    // full iteration count
      unsigned long  current;     // current count
      unsigned long  exitevent;   // event which causes loop to terminate early
      unsigned long  totalsize;   // offset to start of matching block end struct
    } STrnIterator;

    //
    // Indefinite Loop Structure
    //
    // An indefinite loop repeats a nested PlayList indefinitely
    // until a specified system event has occurred.  The nested scheme may
    // contain ramps, iterators, or indefinite loops.  An indefinite loop
    // always has a matching block End following the looped section.
    //
    typedef struct
    {
      unsigned long  eventid;     // system event which exits this loop
      unsigned long  triggered;   // non-zero if setevent has occurred
      unsigned long  totalsize;   // offset to start of matching block end struct
    } STrnIndefiniteLoop;

    //
    // Conditional Block Structure
    //
    // A conditional block optionally skips its contents when evaluated,
    // depending on the state of an internal flag.  The flag may be set or
    // cleared using system events.  The end of the conditional block is
    // marked by a Block End structure.
    //
    typedef struct
    {
      unsigned long  seteventid;  // system event id this loop waits for
      unsigned long  clreventid;  // system event which resets this loop
      unsigned long  initial;     // initial value of enabled
      unsigned long  enabled;     // zero if contents are to be skipped
      unsigned long  totalsize;   // offset to start of matching block end struct
    } STrnConditionalBlock;

    //
    // Block End Structure
    //
    // All iterators, indefinite loops and conditional blocks end with a Block
    // End structure. This structure provides a reference back to the opening
    // block structure.
    //
    typedef struct
    {
      unsigned long  totalsize;  // offset to start of block
    } STrnBlockEnd;

    //
    // PlayList Structure
    //
    // A Play List is a series of these data structures concatenated
    // together. A stand-alone play list (i.e. one which is not nested
    // inside an iterator or loop) always ends with an element with typetag=0.
    // Nested schemes never have this final terminating marker.
    //
    typedef struct
    {
      unsigned long  typetag;
      union
      {
        STrnRamp              ramp;
        STrnCubic             cube;
        STrnIterator          iter;
        STrnIndefiniteLoop    loop;
        STrnConditionalBlock  cond;
        STrnBlockEnd          bend;
      } data;
    } STrnPlayListElement;

    //
    // PlayList typetag values
    //
    enum {SCHEMEEND=0,OLDRAMP,ITERATOR,LOOP,CONDITIONAL,BLOCKEND,RAMP,CUBIC};

    //========================================================================
    // Constructors/Destructor
    //========================================================================
    //
    // Construct a PlayList from the core data.  The remap table and the
    // iteration scheme (if present) are copied.
    //
    PlayList(
        STrnPlayList* pList
    );
    //
    // Copy constructor of a PlayList from an other one.  The remap table and the
    // iteration scheme (if present) are copied.
    //
    PlayList(
        const PlayList& pList
    );
    //
    // construct an empty PlayList
    //
    PlayList();

    //
    // construct a Playlist which yields a single value
    //
    PlayList(
      unsigned long value
      );

    //
    // construct a Playlist which contains a ramp
    //
    PlayList(
      unsigned long start,
      long          increment,
      unsigned long duration
      );

    //
    // construct a Playlist which contains a ramp with fractional start
    //
    typedef enum { RTFractionalStart } EPLRampType;
    PlayList(
      unsigned long start,
      long          increment,
      unsigned long duration,
      EPLRampType
      );

    //
    // construct a Playlist which contains a cubic, given the difference terms
    //
    PlayList(
      unsigned long initx,    // x at t=0
      long          initdx,   // dx at t=0
      long          initddx,  // d2x at t=0
      long          dddx,     // d3x (constant)
      unsigned long duration
      );

    //
    // construct a Playlist which contains a cubic, given the polynomial coefficients
    //
    PlayList(
      double        a,        // cubic term
      double        b,        // quadratic term
      double        c,        // linear term
      double        d,        // constant term
      double        scale,    // time scale
      unsigned long duration
      );

    //
    // construct a Playlist which contains an iterator
    //
    PlayList(
      const PlayList&  interior,
      unsigned long     duration,
      unsigned long     exitevent
      );

    //
    // construct a Playlist which contains a loop
    //
    PlayList(
      const PlayList&  interior,
      unsigned long     eventid
      );

    //
    // construct a Playlist which contains a conditional
    //
    PlayList(
      const PlayList&  interior,
      unsigned long     seteventid,
      unsigned long     clreventid,
      unsigned long     initialvalue
      );

    //
    // construct a Playlist which is the concatenation of two Playlists
    //
    PlayList(
      const PlayList&  firstList,
      const PlayList&  secondList
      );

    //
    // construct a Playlist with a map table
    //
    PlayList(
      const PlayList&  scheme,
      unsigned   tableSize,
      unsigned   tableEltSize,
      LPVOID     pMapTable
      );

    //
    // construct a PlayList consisting solely of a BYTE table
    //
    PlayList(
      BYTE*     pTable,
      unsigned  tableSize
      );

    //
    // construct a PlayList consisting solely of a WORD table
    //
    PlayList(
      WORD*     pTable,
      unsigned  tableSize
      );

    //
    // construct a PlayList consisting solely of a DWORD table
    //
    PlayList(
      DWORD*    pTable,
      unsigned  tableSize
      );

    //
    // Destroy a PlayList, including the core data.
    //
    ~PlayList();

    //
    // affectation operator a PlayList from an other one.  The remap table and the
    // iteration scheme (if present) are copied.
    //
	PlayList& operator=(const PlayList& pList);
	//
	// concat
	//
	PlayList& operator+=(PlayList& pList2);
	friend PlayList operator+(PlayList& pList1, PlayList& pList2);
	//
	// iterate n times
	//
	PlayList& operator*=(int n);
	friend PlayList operator*(PlayList& pList, int n);

    //
    // Return a pointer to the PlayList core data
    //
    operator STrnPlayList*();

    //========================================================================
    // Public access functions
    //========================================================================

    //
    // Prepare a play list for use.  Return the initial parameter
    // value, and update the start pointer as appropriate for a valid
    // initial state.  Optionally initialize all ramps, loops and conditionals.
    //
    long Init(
      BOOL initialize);

    //
    // Given a system event id, perform the following actions:
    //  - update the status of all downstream conditional blocks which are
    //    controlled by the event.
    //  - exit all downstream or current loops which are controlled by the
    //    event, or are nested within a loop or iterator controlled by the event.
    //  - exit all iterators controlled by the event
    //
    BOOL ProcessSystemEvent(
      unsigned long id);

    //
    // Pass the numbers of all events used by this playlist to an external
    // function.  this may be used, for example, to register events with
    // some outside agent.  Event 0 is reserved, and is never passed to the
    // callback.
    //
    // The p1 & p2 parameters are passed back to the callback function as the
    // second and third parameters.
    //
    // Returns TRUE if any events were passed to the callback.
    //
    BOOL EnumerateEvents(
      void (*pfn)(DWORD event, LPVOID p1, LPVOID p2),
      LPVOID p1,
      LPVOID p2);

    //
    // Replace all occurrances of oldEvent with newEvent.  Return TRUE if
    // any instances were replaced.
    //
    BOOL RemapEvent(const DWORD oldEvent, DWORD newEvent);

    //
    // return the total
    // running time of the scheme, assuming all indefinite loops run only
    // one time, all iterators run to their full count, and all conditional
    // blocks retain their current (enabled/disabled) state.
    //
    long SchemeLength() const;

    //
    // Set the "scrubbing length" of the effect.
    // The "scrubbing length" of the effect is used in positioning a playlist
    // to determine how many interations of an indefinite loop are to be
    // executed.  This value has no effect on PlayLists without indefinite
    // loops, and has one of several possible meanings for PlayLists with
    // several indefinite loops (specifically, all of the indefinite time
    // is allocated to the first loop encountered).
    //
    void SetScrubbingLength(long scrubLen);

    //
    // return TRUE if the actual running time of the playlist is indefinite
    // (due to indefinite loops)
    //
    BOOL IndefiniteLength() const;

    struct  LoopMetrics
    {
      DWORD   leaderLength;
      DWORD   loopCount;
      DWORD   loop1Length;
      DWORD   loopNest;
      DWORD   trailerLength;
    };

    //
    // return information about the loop structure of the playlist.
    // The leader length is the sum of the lengths of all ramps before
    // the first loop (or the entire scheme if there are no loops).
    // The trailer length is the sum of the lengths of all ramps after the
    // last loop (or 0 if there are no loops).
    //
    void GetLoopMetrics(LoopMetrics* pMet) const;

    //
    // Value returned for parameter index when the time index is beyond the
    // range of the iteration scheme
    //
    enum { NOVALUE = -1, OUTOFRANGE = -2 };

    //
    // Given a pointer into an iteration scheme, return the next parameter value.
    // Return NOVALUE if the scheme is complete.  Update the current pointer
    // (*pps) as necessary.
    //
    long Advance();

    //
    // return the parameter
    // value which corresponds to a given time index.  Return NOVALUE if the time
    // index is out of range of the iteration scheme.  Ignore all indefinite
    // loops in the calculation (i.e. calculate as one pass throgh the loop).
    // Process conditional blocks according to their present state (enabled or
    // not).  Assume that iterators run for their full count.
    // May be used on currently active iteration schemes (does not modifiy any
    // embedded counters).
    //
    long ValueAt(
      unsigned long t) const;

    //
    // Given a time index, return the
    // parameter value which corresponds to the time, adjust the play list so
    // that subsequent calls to Advance iterator will proceed from this point,
    // return an adjusted current pointer for the play list.  Return NOVALUE
    // if the time index is out of range of the play list.
    //
    long PositionIterator(
      unsigned long t);

    //
    // return the current position of the playlist directly.
    STrnPlayListElement *ReturnCurrentPosition(void)
            {return pCurrentPosition;}

#ifdef _MSC_VER
    //
    // Given a pointer to a pre-opened, pre-positioned stream, this function
    // will read a play list from the stream.  Any play list that is already
    // in this object will be erased and replace by the one in the stream.
    //
    HRESULT ReadFromStream( IStream* pStream );

    //
    // Given a pointer to a pre-opened, pre-positioned stream, this function
    // will write the object's current play list to the stream.
    //
    HRESULT WriteToStream( IStream* pStream );
#endif

  protected:
    //========================================================================
    // Internal functions
    //========================================================================
    //
    // Given a play list, return the number of bytes of memory occupied,
    // NOT including the trailing EOL marker
    //
    unsigned ImageSize() const;
	void Copy(const PlayList& pList); // used by PlayList::PlayList(const PlayList &) and operator=(const PlayList&)
    static unsigned ImageSize(STrnPlayListElement* ps);

    //
    // Return the parameter value corresponding to a given parameter index
    //
    long  ParameterValue(long parameterIndex) const;

    //
    // Given a time index, return the
    // parameter value which corresponds to the time, adjust the play list so
    // that subsequent calls to Advance iterator will proceed from this point,
    // return an adjusted current pointer for the play list.  Return NOVALUE
    // if the time index is out of range of the play list.
    //
    long PositionIteratorInternal(
      unsigned long t);

    //
    // Allocate and initialize a ramp structure
    //
    static STrnPlayListElement* MakeRamp(
      unsigned long start,
      long increment,
      unsigned long duration);

    //
    // Allocate and initialize a cubic structure
    //
    static STrnPlayListElement* MakeCubic(
      unsigned long initx,
      long initdx,
      long initddx,
      long dddx,
      unsigned long duration);

    //
    // Wrap a play list in an iterator.  Deallocate the fragment which was
    // wrapped.
    //
    static STrnPlayListElement* MakeIterator(
      STrnPlayListElement* pinterior,
      unsigned long duration,
      unsigned long exitevent);

    //
    // Wrap a play list in an indefinte loop.  Deallocate the fragment which
    // was wrapped.
    //
    static STrnPlayListElement* MakeLoop(
      STrnPlayListElement* pinterior,
      unsigned long eventid);

    //
    // Wrap a play list in a conditional block.  Deallocate the fragment
    // which was wrapped.
    //
    static STrnPlayListElement* MakeConditional(
      STrnPlayListElement* pinterior,
      unsigned long seteventid,
      unsigned long clreventid,
      unsigned long initialvalue);

    //
    // Concatenate two play lists, returning the address of the new hybrid.
    // Deallocate the fragments which were concatenated.
    //
    static STrnPlayListElement* Concatenate(
      STrnPlayListElement* phead,
      STrnPlayListElement* ptail);

    void  DefaultInit();

private:
    //
    // Given a pointer to a loop structure, return the interior length of
    // the loop (i.e. the time for one iteration).
    //
    unsigned long InteriorLength(STrnPlayListElement* pi, long basetime) const;

    //
    // Given a pointer into a play list, return the length (in time
    // indexes) of the current item,
    //
    unsigned long IteratorLength(STrnPlayListElement* pi, long basetime) const;

    //
    // Given a pointer to the start of a play list, return the parameter
    // index which corresponds to a given time index.  Return NOVALUE if the time
    // index is out of range of the iteration scheme.  Ignore all indefinite
    // loops in the calculation (i.e. calculate as one pass throgh the loop).
    // Process conditional blocks according to their present state (enabled or
    // not).  Assume that iterators run for their full count.
    // May be used on currently active iteration schemes (does not modifiy any
    // embedded counters).
    //
    long ParameterIndex(PlayList::STrnPlayListElement* ps, unsigned long t) const;

    //========================================================================
    // Data members
    //========================================================================
    STrnPlayListElement*  pCurrentPosition;   // the current position
    long                  scrubLength;
};

//============================================================================
// Utility functions for clients which need to parse the internal iteration
// scheme structures
//============================================================================
//
// Given a pointer into a play list, return a pointer to the next
// iterator.
//
PlayList::STrnPlayListElement* PlNextIterator(PlayList::STrnPlayListElement* p);

//
// Given a pointer to a block-end, return a pointer to the loop structure which
// started the block.
//
PlayList::STrnPlayListElement* PlStartOfBlock(PlayList::STrnPlayListElement* p);

//
// Given a pointer to a loop structure, return a pointer to the corresponding
// block end structure.
//
PlayList::STrnPlayListElement* PlEndOfBlock(PlayList::STrnPlayListElement* p);


//============================================================================
// Macros which make composite PlayList construction a bit more readable
//============================================================================

// PlayList which makes a single literal
#define PlayListLiteral(l) PlayList(l)

// PlayList which contains a ramp
#define PlayListRamp(s,i,d) PlayList(s,i,d)

// PlayList which contains a ramp with a fixed-point start value
#define PlayListRampFractional(s,i,d) PlayList(s,i,d,PlayList::RTFractionalStart)

// PlayList which contains a cubic
#define PlayListCubic(x,dx,ddx,dddx,dur) PlayList(x,dx,ddx,dddx,dur)

// PlayList with cubic specified in cannonical form
#define PlayListCubicCannonical(a,b,c,d,x,dur) PlayList(a,b,c,d,x,dur)

// PlayList which contains an iterator
#define PlayListIterator(i,d,e) PlayList(i,d,e)

// PlayList which contains an indefinite loop
#define PlayListLoop(i,e) PlayList(i,e)

// PlayList which contains a conditional
#define PlayListCond(i,s,c,v) PlayList(i,s,c,v)

// PlayList which is the concatenation of two lists
#define PlayListConcat(h,t) PlayList(h,t)

// PlayList with a map table
#define PlayListTable(s,ts,tes,pt) PlayList(s,ts,tes,pt)

// PlayList from a BYTE table
#define PlayListByteTable(t,s) PlayList(t,s)

// PlayList from a WORD table
#define PlayListWordTable(t,s) PlayList(t,s)

// PlayList from a DWORD table
#define PlayListDWordTable(t,s) PlayList(t,s)

//============================================================================
// The above macros may be nested to construct composite PlayLists.  For
// example:
//
//  PlayListIterator(
//    PlayListConcat(
//      PlayListRamp(0,0x1000,10),
//      PlayListLiteral(35)
//    )
//  )
//============================================================================



//============================================================================
//              Play list utility functions.
//============================================================================

// Generates an S-Curve PlayList
HRESULT MakeSCurvePlayList(
  unsigned duration,
  PlayList** ppPl,
  BYTE startvalue = 0,
  BYTE endvalue = 255,
  double cfactor = 0.3);

//
// Copies the data from a PlayList class object to the simple
// STrnPlayList.  Since there are pointers in a STrnPlayList,
// you should use FreePlayList to free the memory used by a STrnPlayList.
// For both of these functions, it is assumed that a variable
// of type STrnPlayList is passed.  Therefor, these functions do not
// allocate or free the STrnPlayList itself, only the memory it points to.
//
void ClonePlayList( PlayList* pcPlayList, STrnPlayList* psPlayList );

void FreePlayList( STrnPlayList* psPlayList );

#endif
// End of PlayList.H
