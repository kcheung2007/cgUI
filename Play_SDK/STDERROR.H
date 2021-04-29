//+---------------------------------------------------------------------------
//
//  Trinity Implementation 
//  Copyright (C) Play Incorporated, 1995
//
//  File:       StdError.H
//
//  Contents:   Declaration of routines for accessing standard error texts
//
//  History:    January 7, 1998 cpdaniel created 
//
//----------------------------------------------------------------------------
#ifndef __stderror_h__
#define __stderror_h__

void    PrintErrorMessage(HRESULT hr);

HRESULT AddErrorLibrary(HINSTANCE hInst);
HRESULT RemoveErrorLibrary(HINSTANCE hInst);
BOOL GetStandardErrorString( DWORD error, LPSTR buffer, DWORD dwBufSize );

#endif

// End of StdError.h
