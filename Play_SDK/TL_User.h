#ifndef __TL_USER_H__
#define __TL_USER_H__

#include "TimeLine.h"
#include "uiclib.h"

#define MINIMUM_TRACK_HEIGHT	25
#define DEFAULT_TRACK_HEIGHT	54

#define TIMELINE_STREAM_NAME	"timeline"
#define DURATION_TRACK			1
#define VALUE_TRACK				2
#define DURATION_EVENT			1
#define VALUE_EVENT				2

#define INTERPOLATE_LINE		1
#define INTERPOLATE_SPLINE		2
#define INTERPOLATE_HOLD		3

#define ADD_AFTER		0
#define ADD_BEFORE		1

class CPlayTLManagerAdviser	:	public IPlayTLManagerAdviser
{
public:
	HRESULT __stdcall	OnPreLoad(IPlayTimeLine *pOldTimeLine, LPSTR pFilename, IStorage *pStg){ return E_NOTIMPL; };
	HRESULT __stdcall	OnPostLoad(IPlayTimeLine *pNewTimeLine, LPSTR pFilename, IStorage *pStg){ return E_NOTIMPL; };

	HRESULT __stdcall	OnPreSave(IPlayTimeLine *pOldTimeLine, IStorage *pStg){ return E_NOTIMPL; };
	HRESULT __stdcall	OnPostSave(IPlayTimeLine *pOldTimeLine, IStorage *pStg){ return E_NOTIMPL; };

	HRESULT __stdcall	OnPreViewRemoval(IPlayTimeLine *pTimeLine){ return E_NOTIMPL; };
	HRESULT __stdcall	OnPostViewRemoval(IPlayTimeLine *pTimeLine){ return E_NOTIMPL; };
};

class CPlayTLAdviser :	public IPlayTLAdviser
{
public:
	CPlayTLAdviser(){ m_cRef = 1;};
	virtual ~CPlayTLAdviser(){};

	virtual HRESULT __stdcall	QueryInterface(REFIID iid, void **ppv)
	{
		HRESULT hr = S_OK;
		if(IsEqualGUID(iid, IID_IUnknown))
		{
			*ppv = (IUnknown *)this;
			AddRef();
			hr = S_OK;
		}
		else if(IsEqualGUID(iid, IID_IPlayTLAdviser))
		{
			*ppv = (IPlayTLManagerAdviser *)this;
			AddRef();
			hr = S_OK;
		}
		else
		{
			*ppv = NULL;
			hr = E_NOINTERFACE;
		}
		return hr;
	};

	long m_cRef;
	virtual ULONG	__stdcall	AddRef() { return(InterlockedIncrement(&m_cRef)); };
	virtual ULONG	__stdcall	Release()
	{
		int c = InterlockedDecrement(&m_cRef);
		if(!c)
			delete this;
		return c;
	};

	// Event selection/de-selection advise sinks.
	virtual HRESULT __stdcall	OnEventSelect(IPlayTimeLine *pTimeLine, IPlayTLEvent *pEvent){ return E_NOTIMPL;};
	virtual HRESULT __stdcall	OnEventDeSelect(IPlayTimeLine *pTimeLine, IPlayTLEvent *pEvent){ return E_NOTIMPL;};

	// Event addition advise sinks.
	virtual HRESULT __stdcall	OnPreEventAdd(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostEventAdd(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent)
	{ return E_NOTIMPL; };

	// Event removal advise sinks.
	virtual HRESULT __stdcall	OnPreEventRemove(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostEventRemove(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent)
	{ return E_NOTIMPL; };

	// Event moving advise sinks.
	virtual HRESULT __stdcall	OnPreEventMove(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, 
												DWORD dwNewStartTime, BOOL bRipple, DWORD dwFirstTime)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnEventMoving(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, 
												DWORD dwNewStartTime, BOOL bRipple, DWORD dwFirstTime)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostEventMove(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, 
												DWORD dwNewStartTime, BOOL bRipple, DWORD dwFirstTime)
	{ return E_NOTIMPL; };

	// File being dropped on us advise sink.
	virtual HRESULT __stdcall	OnFileDrop(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, DWORD dwTime, LPSTR pFileName)
	{ return E_NOTIMPL; };

	// Position bar moving advise sinks.
	virtual HRESULT __stdcall	OnPrePositionBarMove(IPlayTimeLine *pTimeLine, DWORD dwCurrentTime)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPositionBarMoving(IPlayTimeLine *pTimeLine, DWORD dwCurrentTIme)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostPositionBarMove(IPlayTimeLine *pTimeLine, DWORD dwCurrentTime)
	{ return E_NOTIMPL; };

	// Resizing event advise sinks.
	virtual HRESULT __stdcall	OnPreEventSizeStart(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, DWORD dwNewStartTime)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPreEventSizeEnd(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, DWORD dwNewEndTime)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostEventSize(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, DWORD dwNewLength)
	{ return E_NOTIMPL; };

	// Popup advise sink.
	virtual HRESULT __stdcall	OnPopupMenu(IPlayPopup *pPopup, IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent, DWORD dwTime)
	{ return E_NOTIMPL; };

	virtual IPlayTLTrack __RPC_FAR *__stdcall	OnEventSwitchTrack(IPlayTimeLine *pTimeLine, IPlayTLTrack *pNewTrack, IPlayTLEvent *pEvent)
	{ return NULL; };

	// Set source in advise sink.
	virtual HRESULT __stdcall	OnPreSetSourceIn(IPlayTimeLine *pTimeLine, IPlayTLEvent *pEvent, DWORD dwNewSourceIn)
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostSetSourceIn(IPlayTimeLine *pTimeLine, IPlayTLEvent *pEvent, DWORD dwNewSourceIn)
	{ return E_NOTIMPL; };

	// Advises for value events changing value.
	virtual HRESULT __stdcall	OnPreEventValueChange(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent,
								  double dNewValue )
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnEventValueChanging(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent,
								 double dNewValue )
	{ return E_NOTIMPL; };
	virtual HRESULT __stdcall	OnPostEventValueChange(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent,
								   double dNewValue )
	{ return E_NOTIMPL; };

	virtual HRESULT __stdcall	OnEventValueDisplay(IPlayTimeLine *pTimeLine, IPlayTLTrack *pTrack, IPlayTLEvent *pEvent,
								 double dNewValue, LPSTR pszOutput, long numBytes)
	{ return E_NOTIMPL; };

	virtual HRESULT __stdcall	OnPaste ( IPlayTimeLine * pTimeLine, IPlayTLTrack * pTrack, IPlayTLEvent * pEvent )
	{ return E_NOTIMPL; };

};


class CPlayTLAdviser2 :	public IPlayTLAdviser2
{
public:
	CPlayTLAdviser2(){ m_cRef = 1;};
	virtual ~CPlayTLAdviser2(){};

	virtual HRESULT __stdcall	QueryInterface(REFIID iid, void **ppv)
	{
		HRESULT hr = S_OK;
		if(IsEqualGUID(iid, IID_IUnknown))
		{
			*ppv = (IUnknown *)this;
			AddRef();
			hr = S_OK;
		}
		else if(IsEqualGUID(iid, IID_IPlayTLAdviser2))
		{
			*ppv = (IPlayTLManagerAdviser *)this;
			AddRef();
			hr = S_OK;
		}
		else
		{
			*ppv = NULL;
			hr = E_NOINTERFACE;
		}
		return hr;
	};

	long m_cRef;
	virtual ULONG	__stdcall	AddRef() { return(InterlockedIncrement(&m_cRef)); };
	virtual ULONG	__stdcall	Release()
	{
		int c = InterlockedDecrement(&m_cRef);
		if(!c)
			delete this;
		return c;
	};

	virtual HRESULT __stdcall OnPostEventSwitchTrack (  IPlayTimeLine * pTimeLine,
														IPlayTLTrack * pNewTrack,
														IPlayTLTrack * pOldTrack,
														IPlayTLEvent * pEvent)
	{
		return (E_NOTIMPL);
	};

};

#endif
// End of TL_User.h
