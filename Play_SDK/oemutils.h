//+---------------------------------------------------------------------------
//
//  Trinity Implementation
//  Copyright (C) Play Incorporated, 1995
//
//  File:     OemUtils.H
//
//  Contents: Declarations of miscellaneous utility routines.
//
//
//  History:  January 5, 1996   cmdaniel    created
//
//----------------------------------------------------------------------------
#ifndef __oemutils_h__
#define __oemutils_h__

#ifdef __cplusplus
extern "C"
{
#endif

  void __stdcall CopySwap( LPVOID dest, LPVOID src, ULONG count );

  void __stdcall CopyWSwap( LPVOID dest, LPVOID src, ULONG count );

#ifdef __cplusplus
}
#endif


#endif

// end of oemutils.h

