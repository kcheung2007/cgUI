//+---------------------------------------------------------------------------
//
//  Trinity Level 2 API
//  Copyright (C) Play Incorporated, 1995
//
//  File:       trinity.h
//
//  Contents:   Master Trinity Core API Header.  Includes MIDL generated 
//              trnity.h
//
//  History:    June 29, 1995 cpdaniel  Created
//
//----------------------------------------------------------------------------

#include <trnity.h>

//============================================================================
// API Global Functions
//============================================================================

// Initialize Trinity support - must be called in every thread after
// a call to CoInitialize or OleInitialize
extern "C" HRESULT TrnInitialize(LPVOID rmbz);

// De-initialize Trinity suport - must be called in every thread before
// a call to CoUninitialize or OleUnititialize
extern "C" void  TrnUninitialize();

// End of Trinity.H
