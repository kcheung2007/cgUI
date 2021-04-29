/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Storage II
      File : IMemFilt.h
   Purpose : Used to process blocks of memory
   10/6/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IMEMFILT_H_
#define _IMEMFILT_H_

typedef unsigned long ulong;

#include <unknwn.h>

/*****************************************************************************
  IMemFilt
*****************************************************************************/

struct IMF_BUFFERS
  {
  const void* in;
  ulong icount;
  void* out;
  ulong ocount;
  };

struct IMemFilt : IUnknown
  {
  STDMETHOD(Process)(IMF_BUFFERS* buffers, bool flush) PURE;
  };

extern "C" const IID IID_IMemFilt;

/*****************************************************************************
  IMFEncodeRLE2
*****************************************************************************/

struct IMFEncodeRLE2 : IMemFilt
  {
  };

HRESULT __stdcall CreateMFEncodeRLE2(IMFEncodeRLE2**);

extern "C" const CLSID CLSID_MFEncodeRLE2;
extern "C" const IID IID_IMFEncodeRLE2;

/*****************************************************************************
  IMFDecodeRLE2
*****************************************************************************/

struct IMFDecodeRLE2 : IMemFilt
  {
  };

HRESULT __stdcall CreateMFDecodeRLE2(IMFDecodeRLE2**);

extern "C" const CLSID CLSID_MFDecodeRLE2;
extern "C" const IID IID_IMFDecodeRLE2;

/****************************************************************************/

#endif

/* EOF */
