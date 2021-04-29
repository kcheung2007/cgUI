/*****************************************************************************
  PLAY CONFIDENTIAL - Copyright 1999 Play Inc., All Rights Reserved.
   Project : Play Audio Mixer
      File : IPAM.h
   Purpose : Interface declaration (see pam.html for the docs)
    6/3/99 : Created (Mark Riley)
*****************************************************************************/

#ifndef _IPAM_H_
#define _IPAM_H_

#include <unknwn.h>

enum
  {
  IPAM_DEST_SPEAKERS = 0,
  IPAM_DEST_WAVEIN,
  IPAM_DEST_MAX
  };

enum
  {
  IPAM_SRC_MASTER = 0,
  IPAM_SRC_WAVEOUT,
  IPAM_SRC_MIDI,
  IPAM_SRC_CDAUDIO,
  IPAM_SRC_LINEIN,
  IPAM_SRC_MIC,
  IPAM_SRC_PCSPEAKER,
  IPAM_SRC_MAX
  };

enum
  {
  IPAM_SUPPORTS_VOLUME = 1,
  IPAM_SUPPORTS_PAN = 2,
  IPAM_SUPPORTS_ENABLE = 4,
  IPAM_SUPPORTS_TREBLE = 8,
  IPAM_SUPPORTS_BASS = 16,
  IPAM_SUPPORTS_PEAK = 32,
  IPAM_SUPPORTS_ONESOURCE = 64,
  IPAM_SUPPORTS_STEREO = 128
  };

enum
  {
  IPAM_CHANGE_VOLUMEPAN = 1,
  IPAM_CHANGE_ENABLE = 2,
  IPAM_CHANGE_BASS = 4,
  IPAM_CHANGE_TREBLE = 8,
  IPAM_CHANGE_LINE = 16
  };

struct IPAMCallback
  {
  virtual void __stdcall PAMNotify(int dest, int src, long flags) = 0;
  };

struct IPAM : IUnknown
  {
  STDMETHOD(Open)(UINT uMxId, DWORD fdwOpen, HINSTANCE hInstance) PURE;
  STDMETHOD(Close)() PURE;

  STDMETHOD(SetCallback)(IPAMCallback* callback) PURE;

  STDMETHOD(GetLineSupport)(long dest, long src, long* p_flags) PURE;

  STDMETHOD(GetLineEnable)(long dest, long src, long* p_enable) PURE;
  STDMETHOD(SetLineEnable)(long dest, long src, long enable) PURE;

  STDMETHOD(GetVolumePan)(long dest, long src, float* p_volume, float* p_pan) PURE;
  STDMETHOD(SetVolumePan)(long dest, long src, float volume, float pan) PURE;

  STDMETHOD(GetPeakLevel)(long dest, long src, float* p_value) PURE;

  STDMETHOD(GetBassLevel)(long dest, long src, float* p_value) PURE;
  STDMETHOD(SetBassLevel)(long dest, long src, float value) PURE;
  STDMETHOD(GetTrebleLevel)(long dest, long src, float* p_value) PURE;
  STDMETHOD(SetTrebleLevel)(long dest, long src, float value) PURE;
  };

enum
  {
  IPAM_ERROR = 0xE8300001,
  IPAM_ERROR_NO_SUCH_LINE,
  IPAM_ERROR_NOT_SUPPORTED,
  // Not open
  };

HRESULT __stdcall CreatePAM(IPAM**);

extern "C" const CLSID CLSID_PAM;
extern "C" const IID IID_IPAM;

#endif

/* EOF */
