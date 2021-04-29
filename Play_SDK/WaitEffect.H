#include "simplevid.h"

class EffectWaiter : public IVidAdviseSink2
{
  DWORD             m_objectId;
  EVidEffectAction  m_action;
  HANDLE            m_hEvent;

  public:
        EffectWaiter();
        ~EffectWaiter();

        HRESULT WaitForNotification(DWORD objectId, EVidEffectAction action, unsigned timeout);

    //
    // IUnknown Members
    //

        virtual HRESULT __stdcall QueryInterface(
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);

        virtual ULONG __stdcall AddRef(void);

        virtual ULONG __stdcall Release(void);

    //
    // IVidAdviseSink2 members
    //
        virtual HRESULT STDMETHODCALLTYPE OnRoutingChange( 
            /* [in] */ unsigned int numUpdates,
            /* [in] */ SVidRouteInfo __RPC_FAR *pUpdates);
        
        virtual HRESULT STDMETHODCALLTYPE OnModeChange(
            /* [in] */ EVidMixerMode mode);

        virtual HRESULT STDMETHODCALLTYPE OnEffectLoad( 
            /* [in] */ DWORD objectId);
        
        virtual HRESULT STDMETHODCALLTYPE OnInputEffectLoad( 
            /* [in] */ DWORD objectId,
            /* [in] */ ITrnEffectFile __RPC_FAR *pTfxFile,
            /* [in] */ ITrnEffectInput __RPC_FAR *pTfxInput);
        
        virtual HRESULT STDMETHODCALLTYPE OnEffectUnload( 
            /* [in] */ DWORD objectId);
        
        virtual HRESULT STDMETHODCALLTYPE OnFramestoreComplete( 
            /* [in] */ EVidSource whichSource,
            /* [in] */ DWORD objectId,
            /* [in] */ EVidOperation whatOp);
        
        virtual HRESULT STDMETHODCALLTYPE OnAsyncError( 
            /* [in] */ DWORD objectId,
            /* [in] */ HRESULT loadResult);
        
        virtual HRESULT STDMETHODCALLTYPE OnEffectAction(
            /* [in]  */ DWORD           objectId,
            /* [in]  */ EVidEffectAction  action);

        virtual HRESULT STDMETHODCALLTYPE OnLoadConflict( 
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken);
        
        virtual HRESULT STDMETHODCALLTYPE OnPlayConflict( 
            /* [in] */ DWORD newObjectId,
            /* [in] */ DWORD oldObjectId,
            /* [in] */ BOOL resourceWasTaken);
        
    //
    // EffectWaiter members.
    //

};

// End of WaitEffect.H

