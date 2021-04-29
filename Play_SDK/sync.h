#ifndef __sync_h__
#define __sync_h__

class Synchronizer : public ITrnConnectionClient
{
  public:
        Synchronizer();
        ~Synchronizer();

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

    //
    // Synchronizer members.
    //

        BOOL __stdcall WaitCompletion();

        DWORD       ErrCode;            // error code from overlapped wait
        HANDLE      hEvent;
};


#endif

// End of Sync.H
