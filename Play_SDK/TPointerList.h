// ----------------------------------------------------------------------------
// Play Incorporated Security Provider
// Copyright 1988, Play Incorporated, All rights Reserved
// 
// File: TPointerList.H
//
// Contents:  
//  Implements a reference counted, enumerable array of T*.  
//
// History:
//    May 1998    cpdaniel  created      
// ----------------------------------------------------------------------------
#ifndef __tpointerlist_h__
#define __tpointerlist_h__
#include "smartptr.h"
#include "combase.h"
#include "assert.h"

template<class T> class TPointerList : public CUnknown
{
  private:
    Ptr<T>*   m_pData;
    unsigned  m_size;
    unsigned  m_alloc;
        
  public:
    TPointerList(unsigned size = 0)
      : CUnknown(0,0),
        m_pData(0),
        m_size(0),
        m_alloc(size)
    {
      if (m_alloc)
        m_pData = new Ptr<T>[m_alloc];
    }

    TPointerList(const TPointerList* prhs)
      : CUnknown(0,0),
        m_pData(0),
        m_size(prhs->m_size),
        m_alloc(prhs->m_alloc)
    {
      m_pData = new Ptr<T>[m_alloc];
      for (unsigned index = 0; index < m_size; index++)
        m_pData[index] = prhs->m_pData[index];
    }

    ~TPointerList()
    {
      if (m_pData)
        delete [] m_pData;
    }

    DECLARE_IUNKNOWN;

    DWORD   Size()
    {
      return m_size;
    }

    HRESULT Insert(T* pRecord)
    {
      assert(pRecord);
      HRESULT hr = NOERROR;
      if (m_size == m_alloc)
      {
        unsigned new_alloc;
        if (m_alloc)
          new_alloc = m_alloc*2;
        else
          new_alloc = 16;

        Ptr<T>* newData = new Ptr<T>[new_alloc];
        if (newData)
        {
          for (unsigned index = 0; index < m_size; index++)
            newData[index] <<= m_pData[index];
          delete [] m_pData;
          m_pData = newData;
          m_alloc = new_alloc;
        }
        else
          hr = E_OUTOFMEMORY;
      }

      if (SUCCEEDED(hr))
        m_pData[m_size++] = pRecord;

      return hr;
    }

    HRESULT Get(
      unsigned  index,
      T**       ppRecord
      )
    {
      HRESULT hr = NOERROR;

      if (index < m_size)
        SET_PTR<T>(*ppRecord,m_pData[index]);
      else
      {
        *ppRecord = 0;
        hr = E_INVALIDARG;
      }

      return hr;
    }

    HRESULT Delete(
      unsigned  index
      )
    {
      HRESULT hr = NOERROR;

      if (index < m_size)
      {
        m_size--;
        if (m_size != index)
          m_pData[index] = m_pData[m_size];
        m_pData[m_size] = 0;
      }
      else
        hr = E_INVALIDARG;

      return hr;
    }

    void Access(Ptr<T>*& p)
    {
      p = m_pData;
    }
};

template <class T> class TEnumPointerList 
  : public CUnknown,
    public IEnumUnknown
{
  private:
    Ptr<TPointerList<T> > m_pList;
    ULONG                 m_totalCount;
    ULONG                 m_currentCount;

  public:
    TEnumPointerList(TPointerList<T>* pList)
      : CUnknown(0,0),
        m_pList(pList),
        m_totalCount(pList->Size()),
        m_currentCount(0)
    {
    }

    ~TEnumPointerList()
    {
    }

    DECLARE_IUNKNOWN;

    // INonDelegatingUnknown members
    HRESULT  __stdcall NonDelegatingQueryInterface(
      /* [in] */ REFIID riid,
      /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject)
    {
      if (IsEqualGUID( riid, IID_IEnumUnknown) )
        return GetInterface((IEnumUnknown*)this,ppvObject);
      else
        return CUnknown::NonDelegatingQueryInterface(riid,ppvObject);
    }

    // IEnumUnknown members
    HRESULT __stdcall Next( 
        /* [in] */ ULONG celt,
        /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *rgelt,
        /* [out] */ ULONG __RPC_FAR *pceltFetched)
    {
      HRESULT hr=S_OK;
      ULONG fetched=0;
      while ((fetched!=celt)&&(m_currentCount!=m_totalCount))
      {
        m_pList->Get(m_currentCount++,(T**)rgelt++);
        fetched++;
      }
      if (fetched!=celt)
        hr=S_FALSE;
      if (pceltFetched)
        *pceltFetched=fetched;
      return hr;
    }
    
    HRESULT __stdcall Skip( 
        /* [in] */ ULONG celt)
    {
      HRESULT hr=S_OK;
      ULONG skipped=0;
      while ((skipped!=celt)&&(m_currentCount!=m_totalCount))
      {
        skipped++;
        m_currentCount++;
      }
      if (skipped!=celt)
        hr=S_FALSE;
      return hr;
    }

    
    HRESULT __stdcall Reset( void)
    {
      m_currentCount=0;
      return S_OK;
    }
    
    HRESULT __stdcall Clone( 
        /* [out] */ IEnumUnknown __RPC_FAR *__RPC_FAR *ppenum)
    {
      HRESULT hr=S_OK;
      if (ppenum)
      {
        *ppenum=new TEnumPointerList<T>(m_pList);
        if (*ppenum)
        {
          (*ppenum)->AddRef();
        }
        else
          hr=E_OUTOFMEMORY;
      }
      else
        hr=E_INVALIDARG;
      return hr;
    }
};

#endif

// End of TPointerList.h
