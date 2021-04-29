/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Storage II
      File : IGXClientPIO.h
   Purpose : Implementation of IGXClientIO on IPIO
    9/2/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IGXCLIENTPIO_H_
#define _IGXCLIENTPIO_H_

#include <IPIO.h>
#include <gxlate.h>

struct IGXClientPIO : IGXClientIO
  {
  STDMETHOD(SetPIO)(IPIO* pio) PURE;
  };

HRESULT __stdcall CreateGXClientPIO(IGXClientPIO** p_o);
HRESULT __stdcall CreateGXClientIO_PIO(IGXClientIO** p_gxcio, IPIO* pio);

#ifdef WIN32

HRESULT __stdcall CreateGXClientIO_Resource(IGXClientIO** p_gxcio,
  HMODULE hModule, LPCTSTR lpType, LPCTSTR lpName, WORD wLanguage);

#endif

extern "C" const CLSID CLSID_GXClientPIO;
extern "C" const IID IID_IGXClientPIO;

#endif

/* EOF */
