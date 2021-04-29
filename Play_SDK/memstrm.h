//+---------------------------------------------------------------------------
//
//  Trinity Implementation 
//  Copyright (C) Play Incorporated, 1995
//
//  File:     MemStrm.H      
//
//  Contents: Declaration of CMemStream
//
//  History:    March 24, 1998   tsprague   made from filestrm.h
//              December 5, 1995 cpdaniel  created
//
//----------------------------------------------------------------------------
#ifndef __memstrm_h_
#define __memstrm_h_

#include "objidl.h"

class CMemStream : public IStream
{
    private:
        BYTE *m_pMem;
        DWORD m_dwSize;
        DWORD m_dwOffset;

    public:
        CMemStream( BYTE *mem, DWORD size );
        ~CMemStream(); 

        // IUnknown Members
        virtual HRESULT __stdcall QueryInterface( 
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        virtual ULONG __stdcall AddRef( void);
        
        virtual ULONG __stdcall Release( void);
        
        // IStream Memebers
        virtual /* [local] */ HRESULT __stdcall Read( 
            /* [out] */ void __RPC_FAR *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG __RPC_FAR *pcbRead);
        
        virtual /* [local] */ HRESULT __stdcall Write( 
            /* [size_is][in] */ const void __RPC_FAR *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG __RPC_FAR *pcbWritten);
        
        virtual /* [local] */ HRESULT __stdcall Seek( 
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *plibNewPosition);
        
        virtual HRESULT __stdcall SetSize( 
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        virtual /* [local] */ HRESULT __stdcall CopyTo( 
            /* [unique][in] */ IStream __RPC_FAR *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *pcbRead,
            /* [out] */ ULARGE_INTEGER __RPC_FAR *pcbWritten);
        
        virtual HRESULT __stdcall Commit( 
            /* [in] */ DWORD grfCommitFlags);
        
        virtual HRESULT __stdcall Revert( void);
        
        virtual HRESULT __stdcall LockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        virtual HRESULT __stdcall UnlockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        virtual HRESULT __stdcall Stat( 
            /* [out] */ STATSTG __RPC_FAR *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IStream __RPC_FAR *__RPC_FAR *ppstm);
};

#endif
// End of memstrm.H 
