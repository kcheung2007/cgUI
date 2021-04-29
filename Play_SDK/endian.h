#ifndef __endian_h__
#define __endian_h__
//+---------------------------------------------------------------------------
//
//  Trinity Implementation
//  Copyright (C) Play Incorporated, 1995
//
//  File:     Endian.H
//
//  Contents: Declarations of miscellaneous utility routines.
//----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Converts a GUID from a Trinity message into a Microsoft GUID.
// ----------------------------------------------------------------------------
inline void 
TrnClassIdToCLSID( const LPDWORD TrnClassId, CLSID* pClsId )
{
   __asm
   {
        pushad
        cld
        mov     esi, TrnClassId     // ESI points to Trinity GUID
        mov     edi, pClsId         // EDI points to Microsoft GUID
        lodsd
        mov     GUID.Data1[edi], eax
        lodsd
        mov     GUID.Data3[edi], ax
        shr     eax, 16
        mov     GUID.Data2[edi], ax
        lea     edi, GUID.Data4[edi]
        lodsd
        bswap   eax
        stosd
        lodsd
        bswap   eax
        stosd
        popad
   }
 }

// ----------------------------------------------------------------------------
//  Converts a Microsoft GUIDinto a GUID from a Trinity message .
// ----------------------------------------------------------------------------
inline void        
CLSIDToTrnClassId( const CLSID* pClsId, LPDWORD TrnClassId )
{
  __asm
  {
        pushad
        cld
        mov     esi, pClsId         // ESI points to Microsoft GUID
        mov     edi, TrnClassId     // EDI points to Trinity GUID
        mov     eax, GUID.Data1[esi]
        stosd
        mov     ax, GUID.Data2[esi]
        shl     eax,16
        mov     ax, GUID.Data3[esi]
        stosd
        lea     esi, GUID.Data4[esi]
        lodsd
        bswap   eax
        stosd
        lodsd
        bswap   eax
        stosd
        popad
  }
}

// ----------------------------------------------------------------------------
// Swap the bytes in a DWORD
// ----------------------------------------------------------------------------
#pragma warning (disable:4035)
inline DWORD
DWSwap(DWORD value)
{
  __asm
  {
        mov   eax,value
        bswap eax
  }
}
#pragma warning (default:4035)

#endif
// End of endian.h
