// ------------------------------------------------------------------------ //
// IPlayTimer.H
// Interface file for Play Timer devices
//
// Copyright @ 1999 Play Inc.
// Play Confidential
//
// Created on Aug 26, 1999 by Heman Gala
// ------------------------------------------------------------------------ //

// ------------------------------------------------------------------------ //
#ifndef __IPlayTimer_H__
#define __IPlayTimer_H__
// ------------------------------------------------------------------------ //

#include <PlayInc.H>

// ------------------------------------------------------------------------ //

extern "C" const GUID	CLSID_PlayTimerManager;
extern "C" const GUID	IID_IPlayTimerManager;

extern IUnknown* STDMETHODCALLTYPE g_CLSID_PlayTimerManager (VOID);

// --- Result codes ------------------------------------------------------- //

enum PLAYTIMERRESULT
{
	S_PLAYTIMER_OK					= S_OK,
									
	E_PLAYTIMER_FAIL				= E_FAIL,

	E_PLAYTIMER_NOINTERFACE			= E_NOINTERFACE,
	E_PLAYTIMER_OUTOFMEMORY			= E_OUTOFMEMORY,
	E_PLAYTIMER_INVALIDARGS			= E_INVALIDARG,

	E_PLAYTIMER_INVALIDARG_1,
	E_PLAYTIMER_INVALIDARG_2,
	E_PLAYTIMER_INVALIDARG_3,
};

// --- IPlayTimerManager -------------------------------------------------- //

// Forward declarations

interface IPlayTimer;
class CPlayTimerNotification;

interface IPlayTimerManager : public IUnknown
{
public:
	// Creates actual Timer objects, with passed in specs
	virtual HRESULT STDMETHODCALLTYPE CreateTimer (
		IN	ULONG					TimeOut,		// In milli-secs
		IN	CPlayTimerNotification*	pNotification,	// Ptr to notification interface
		OUT	IPlayTimer**			ppTimer) = 0;	// Receives a Timer interface ptr here
};


// --- IPlayTimerNotification --------------------------------------------- //

class CPlayTimerNotification
{
public:
	// Called by PlayTimer, every TimeOut milli-secs
	virtual VOID STDMETHODCALLTYPE TimeOut (
		IN	IPlayTimer*				pTimer) { return; };
};


// --- IPlayTimer --------------------------------------------------------- //

extern "C" const GUID	IID_IPlayTimer;

interface IPlayTimer : public IUnknown
{
public:
	// Allows us to query properties of timer object

	virtual HRESULT STDMETHODCALLTYPE GetId (
		OUT	ULONG*		pTimerId) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetTimeOut (
		OUT	ULONG*		pTimeOut) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetNotification (
		OUT	CPlayTimerNotification**	ppNotification) = 0;
};

// ------------------------------------------------------------------------ //
#endif __IPlayTimer_H__
// ------------------------------------------------------------------------ //

// End-of-file : IPlayTimer.H