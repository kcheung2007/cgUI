//+---------------------------------------------------------------------------
//
//  Trinity Implementation 
//  Copyright (C) Play Incorporated, 1995
//
//  File:     EnumUnk.H       
//
//  Contents: Declaration of CEnumUnknown
//
//  History:  October 5, 1995 cpdaniel  created
//
//----------------------------------------------------------------------------
#ifndef __enumunk_H__
#define __enumunk_H__

class CEnumUnknown : public CUnknown,
                     public IEnumUnknown
{
  public:
    CEnumUnknown(IUnknown*,IUnknown**,ULONG);
    ~CEnumUnknown();

    DECLARE_IUNKNOWN;

    // INonDelegatingUnknown members
    HRESULT  __stdcall NonDelegatingQueryInterface(
      /* [in] */ REFIID riid,
      /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

    // IEnumUnknown members
    virtual /* [local] */ HRESULT __stdcall Next( 
        /* [in] */ ULONG celt,
        /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *rgelt,
        /* [out] */ ULONG __RPC_FAR *pceltFetched);
    
    virtual HRESULT __stdcall Skip( 
        /* [in] */ ULONG celt);
    
    virtual HRESULT __stdcall Reset( void);
    
    virtual HRESULT __stdcall Clone( 
        /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum);

  private:
    IUnknown*     m_pContainer;
    IUnknown**    m_pStart;
    IUnknown**    m_pCurrent;
    ULONG         m_totalCount;
    ULONG         m_currentCount;
};

#endif
// End of EnumUnk.H

