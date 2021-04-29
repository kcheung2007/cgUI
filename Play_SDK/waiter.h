#ifndef __Waiter_h__
#define __Waiter_h__
//----------------------------------------------------------------------------
//  File:   Waiter.H
//
//  Description:  Declaration of deferred notification manager class
//
//  Classes:      Waiter
//
//  History:      July 26, 1996   cpdaniel    created
//
//----------------------------------------------------------------------------

#include "trnity.h"
#include "ptrqueue.h"

class Waiter : private ITrnConnectionClient
{
  public:
    Waiter(
      ITrnConnection* pVS,
      DWORD notifyTimeout,
      unsigned numBuffs,
      unsigned numWaits,
      unsigned buffsize,
      DWORD    listenSocket
      );

    ~Waiter();

    HRESULT LastError();

    unsigned  ErrorCount();

    void  MainLoop();

    void  Stop();

    virtual void HandleMessage(STrnMessageHeader* pMsg) = 0;

    //
    // IUnknown Members
    //

        virtual HRESULT __stdcall QueryInterface(
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        virtual ULONG __stdcall AddRef(void);

        virtual ULONG __stdcall Release(void);

    //
    // ITrnConnectionClient members
    //

        virtual HRESULT __stdcall OnAsyncReceive(
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,
            /* [in] */ BOOL repeated);

        virtual HRESULT __stdcall OnAsyncMessage(
            /* [in] */ PSTrnMessageHeader pBuffer,
            /* [in] */ BOOL repeated);

        virtual HRESULT __stdcall OnAsyncError(         // sets public data member
            /* [in] */ LPVOID pBuffer,
            /* [in] */ DWORD socketNumber,              // to ErrCode and Sets event
            /* [in] */ DWORD ErrCode);                  // to wake up WaitCompletion()

        virtual HRESULT __stdcall SetupSyncImageBlock(
            /* [in] */ DWORD socketNumber,
            /* [in] */ DWORD offset,
            /* [in] */ DWORD remainder,                 // return E_NOTIMPL
            /* [out] */ LPDWORD blockSize);


  protected:
    long              m_waitCount;
    unsigned          m_buffSize;
    PtrQueue          m_messageQueue;
    PtrQueue          m_freeQueue;

    ITrnConnection*   m_pConnection;
    DWORD             m_asyncSocket;
    DWORD             m_timeOut;

    HRESULT           m_lastError;
    unsigned          m_errorCount;
    BOOL              m_shutdown;
};

#endif

// End of Waiter.h
