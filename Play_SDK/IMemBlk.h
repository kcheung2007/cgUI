/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Storage II
      File : IMemBlk.h
   Purpose : Generic representation of memory block
   8/31/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IMEMBLK_H_
#define _IMEMBLK_H_

#include <unknwn.h>

typedef unsigned long ulong;

/*****************************************************************************
  IMemBlk
*****************************************************************************/

struct IMemBlk : IUnknown
  {
  STDMETHOD(GetBlock)(void** p_block, ulong* p_size) PURE;
  };

extern "C" const IID IID_IMemBlk;

/*****************************************************************************
  IMemBlkMalloc - Implementation of IMemBlk using malloc()/free()
*****************************************************************************/

struct IMemBlkMalloc : IMemBlk
  {
  STDMETHOD(Allocate)(ulong size) PURE;
  };

HRESULT __stdcall CreateMemBlkMalloc(IMemBlkMalloc** p_o);
HRESULT __stdcall CreateMemBlk_Malloc(IMemBlk** p_memblk, ulong size);

extern "C" const CLSID CLSID_MemBlkMalloc;
extern "C" const IID IID_IMemBlkMalloc;

/*****************************************************************************
  IMemBlkStatic - Implementation of IMemBlk using static buffer
*****************************************************************************/

struct IMemBlkStatic : IMemBlk
  {
  STDMETHOD(SetBlock)(void* block, ulong size) PURE;
  };

HRESULT __stdcall CreateMemBlkStatic(IMemBlkStatic** p_o);
HRESULT __stdcall CreateMemBlk_Static(IMemBlk** p_memblk, void* block,
  ulong size);

extern "C" const CLSID CLSID_MemBlkStatic;
extern "C" const IID IID_IMemBlkStatic;

/*****************************************************************************
  Helper Functions
*****************************************************************************/

#ifdef WIN32
HRESULT __stdcall CreateMemBlk_Resource(IMemBlk** p_memblk, HMODULE hModule,
  LPCTSTR lpType, LPCTSTR lpName, WORD wLanguage);
#endif

/****************************************************************************/

#endif

/* EOF */
