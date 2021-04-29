
#include "dvemath.h"
#include <deque.h>
#include "fitcore.h"






// :: Class SubTraceList :: -----------------------------------------
//  A SubTraceGenerator makes lists of SubTraces based on passed
//  alpha and coordinates buffers.

class SubTraceList
{
  deque<SubTrace> sList;  //Our SubTrace FIFO.
  double*  coord_buf;     //pointer to a buffer of coordinate values
  BYTE*    alpha;         //pointer to alpha buffer for image
  int      length;        //length of scanline
  double   max_error;     //max acceptible error for this coordinate.

  SubTrace subtrace;      //last good SubTrace generated
  Seg      segment;       //working segment for quadratic fitter.
  int      run_start;     //start position of current run
  int      run_end;       //end position of last available pixel for run
  int      seg_end;       //end of current segment

  FitMethod method;       //method to use while fitting runs.

  void SubTraceList::find_biggest_seg_and_save_it(SegFitter&);

public:
  SubTraceList(
     double* _coord_buf,
     BYTE* _alpha,
     int _length,
     double _max_error,
     FitMethod _method=FREE_QUADRATIC);

  BOOL IsEmpty()
  {
    return sList.empty();
  }

  BOOL Next(SubTrace& st)
  {
    if (sList.empty()) return FALSE;
    st = sList.front();
    sList.pop_front();
    return TRUE;
  }

};

// :: Class TraceList :: --------------------------------------------
//  A TraceList constructs two SubTraceLists which are then
//  merged to construct a list of Traces which can be rendered to
//  the DVE convertion software.
class TraceList
{
  SubTraceList uSubList;
  SubTraceList vSubList;
  SubTrace u;
  SubTrace v;
  int y;

public:
  TraceList(
    double* _u_buffer, double* _v_buffer,
    BYTE* _alpha,
    double _max_u_err, double _max_v_err,
    int _length, int _y,
    FitMethod _method=FREE_QUADRATIC
    )
   :
    uSubList(_u_buffer, _alpha, _length, _max_u_err, _method),
    vSubList(_v_buffer, _alpha, _length, _max_v_err, _method),
    y(_y)
  {
  }
  BOOL IsEmpty()
  {
    return uSubList.IsEmpty() || vSubList.IsEmpty();
  }

  BOOL Next(Trace& NewTrace);

};
