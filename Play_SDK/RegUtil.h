// ----------------------------------------------------------------------------
// Play Incorporated Security Provider
// Copyright 1988, Play Incorporated, All rights Reserved
// 
// File: RegUtil.h
//
// Contents:  
//  Registry utility functions 
//
// History:
//    May 1998    cpdaniel  created      
// ----------------------------------------------------------------------------
#ifndef __regutil_h__
#define __regutil_h__

HRESULT RegisterString( HKEY hkRoot, const char* subKeyName, const char* value );
HRESULT RegisterCLSID( HKEY hkRoot, const char* subKeyName, const CLSID* pClsID );
HRESULT RegisterCLSIDString( HKEY hkRoot, const char* subKeyName, const CLSID* pClsID, const char* value );
HRESULT RemoveKey( HKEY hkRoot, const char* subKeyName );
HRESULT RemoveKeyCLSID( HKEY hkRoot, const char* subKeyName, const CLSID* pClsID );

#endif

// End of RegUtil.h
