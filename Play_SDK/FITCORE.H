/*
    This software is confidential and proprietary information of Play, Inc.
    Copyright 1996 Play, Inc.  All rights reserved.

    Greg Krekelberg

    $Workfile: FITCORE.H $
    $Header: /newdveface/FITCORE.H 1     8/23/96 11:27a Gkrekelb $

 * FITCORE provides the kernel functions for performing various types of
 * l2 norm fitting procedures.  All of the CalcSeg's automatically validate
 * the segments by using an (internal) l-infinite (max deviation) norm
 * against a supplied error bound.
*/

/*
 * $History: FITCORE.H $
 * 
 * *****************  Version 1  *****************
 * User: Gkrekelb     Date: 8/23/96    Time: 11:27a
 * Created in $/newdveface
 * Class definitions for SegFitter compatible classes.  Contains the
 * reference method name enum as well.
 */

enum FitMethod { FREE_QUADRATIC=0, FREE_LINEAR=1 };


class SegFitter
{
public:
  virtual BOOL CalcSeg(int start, int end)=0;
};

// Provides a segment which is the least squares fit of a quadratic
// on the supplied data.  No endpoint constraints are enforced on the
// results.

class FreeQuadratic : public SegFitter
{
  double* coord_buf;
  Seg& segment;
  double max_error;
  void TruncateTerms(Seg& segment);

public:
  FreeQuadratic(
    double* _coord_buf,
    Seg& _segment,
    double _max_error)
    :
    coord_buf(_coord_buf),
    segment(_segment),
    max_error(_max_error) {}

  BOOL CalcSeg(int start, int end);

};


// Provides a least square fit quadratic segment which
// has the slope constrained at the starting end.
class SlopeConstrainedQuadratic : public SegFitter
{
  double* coord_buf;      //pointer to coordinate line buffer
  Seg&    segment;           //output segment
  double  last_constant;
  double  last_slope;
  double  max_error;
  void TruncateTerms(Seg& segment);

public:
  SlopeConstrainedQuadratic(
    double* _coord_buf,
    Seg& _segment,
    double _max_error,
    double initial_constant,
    double initial_slope)
   :
    coord_buf(_coord_buf),
    segment(_segment),
    max_error(_max_error),
    last_constant(initial_constant),
    last_slope(initial_slope) {}

  BOOL CalcSeg(int start, int end);
};


class FreeLinear : public SegFitter
{
  double* coord_buf;
  Seg& segment;
  double max_error;
  void TruncateTerms(Seg& segment);

public:
  FreeLinear(
    double* _coord_buf,
    Seg& _segment,
    double _max_error)
    :
    coord_buf(_coord_buf),
    segment(_segment),
    max_error(_max_error) {}

  BOOL CalcSeg(int start, int end);
};

