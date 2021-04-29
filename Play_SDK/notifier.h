#ifndef __notifier_h__
#define __notifier_h__
//----------------------------------------------------------------------------
//  File:   Notifier.H
//
//  Description:  Declaration of deferred notification manager class
//
//  Classes:      Notifier
//
//  History:      July 26, 1996   cpdaniel    created
//
//----------------------------------------------------------------------------

#include "trnity.h"
#include "ptrqueue.h"

class Notifier : private ITrnConnectionClient
{
  public:
    Notifier(
      ITrnVideoSystem* pVS,
      DWORD notifyTimeout,
      unsigned numBuffs,
      unsigned numWaits
      );

    ~Notifier();

    HRESULT Notify(
      STrnTimeType* pTime,
      DWORD message
      );

    HRESULT WaitNotification(
      DWORD*  pMessage
      );

    HRESULT LastError();

    unsigned  ErrorCount();

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


  private:
    PtrQueue          m_messageQueue;
    PtrQueue          m_freeQueue;

    ITrnAutomationController* m_pController;
    ITrnConnection*   m_pConnection;
    DWORD             m_targetSocket;
    DWORD             m_replySocket;
    DWORD             m_asyncSocket;
    DWORD             m_timeOut;

    HRESULT           m_lastError;
    unsigned          m_errorCount;
    BOOL              m_shutdown;
};

#endif

// End of Notifier.h
