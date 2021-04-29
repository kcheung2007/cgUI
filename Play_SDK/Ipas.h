/*****************************************************************************
  Performer Audio Sequencer
  IPAS.h: Interface declaration
  5/20/99: Mark Riley - Created!
*****************************************************************************/

#ifndef _IPAS_H_INCLUDED_
#define _IPAS_H_INCLUDED_

#include <unknwn.h>
#include <IPAM.h>

/*****************************************************************************
  IPASTimeStamp - A timestamp is used to identify a specific sample within
    a playback "window".  You can think of the playback window as being
    centered around the play cursor (which is the timestamp of the sample
    being heard "now").  The play cursor timestamp increases as samples
    are played.  Timestamps are absolute in the sense that once you have
    a timestamp value, you've identified a specific point in time.  The only
    "gotcha" is that you have to be within the playback window.  This is
    generally easy to do since at a sample rate of 44.1 KHz the window
    extends about 13.5 hours to either side of the play cursor.  The
    window is a consequence of storing the timestamp as a 32-bit value.
    The play cursor will eventually wrap, but if you use the supplied
    "timestamp arithmetic" functions, you don't have to worry about it.

    Timestamps are usually calculated as being relative to some other
    timestamp, such as the play cursor.  If you wanted to schedule a
    sound to start playing 2.5 seconds from now, you'd get the current
    timestamp of the play cursor by calling IPAS::GetPlayTimeStamp().
    You'd then use the IPAS::OffsetTimeStamp() function to add 2.5
    seconds to that timestamp.  If you wanted to schedule another sound
    to play 1 second after the first, you'd offset the timestamp of
    the first sound by one second (you wouldn't make another
    call to IPAS::GetPlayTimeStamp() and add 3.5 seconds, because the
    play cursor may have advanced in the meantime).
*****************************************************************************/

typedef unsigned long IPASTimeStamp;

// Returns the number of samples between the two timestamps.  This is
// useful to determine which timestamp is earlier (you can't simply use
// the <, <=, >, or >= operators because these don't take into account
// the fact that timestamps wrap). To get the number of seconds between
// two timestamps, use IPAS::TimeStampDelta().
inline long IPASTSDelta(IPASTimeStamp x, IPASTimeStamp y)
  { return (long)(x - y); }

/*****************************************************************************
  Notification - These declarations are used with the timestamp notification
    functions.  These allow you to determine when the play cursor has reached
	a particular timestamp.
*****************************************************************************/

// Indicates the type of notification method desired
enum
  {
  IPAS_NOTIFY_HEVENT = 1,  // Call SetEvent() on the supplied event handle
  IPAS_NOTIFY_OBJECT       // Calls user supplied instance of IPASNotifyObject
  };

// This is the notification handle that gets returned by
// IPAS::AddNotification() and can be used to subsequently
// cancel the notification.
typedef unsigned long IPASNotify;

// Supply a derived instance of this class when specifying the
// IPAS_NOTIFY_OBJECT notification type in calls to IPAS::AddNotification().
// When you are notified, the arguments are:
//   notify <- Notification handle
//   code <- Either IPAS_OK or IPAS_WARNING_ABORTED
struct IPASNotifyObject
  {
  virtual void Notify(IPASNotify notify, HRESULT code) = 0;
  };

/*****************************************************************************
  IPASObject - All the COM objects here derive from this
*****************************************************************************/

struct IPASObject : IUnknown
  {
  // Provides access to internal object.  Used internally as a faster
  // alternative to QueryInterface().
  STDMETHOD(GetObject)(void** p_object) PURE;
  };

/*****************************************************************************
  Sound Flags - Flags used when calling IPASSound::SetFlags()
*****************************************************************************/

enum
  {
  // These flags identify the type of sound (pick one or none)
  IPAS_F_BACKGROUND = 0x00000001,
  IPAS_F_NARRATION  = 0x00000002,
  IPAS_F_OVERLAY    = 0x00000004,
  IPAS_F_AMBIANCE   = 0x00000008,

  // Bit mask for above type field
  IPAS_F_TYPE_MASK  = 0x000000FF,
  
  // Sound diminishes in volume when narration present
  IPAS_F_NARRATION_FADER = 0x00010000,

  // Play whole sound between events
  IPAS_F_ATOMIC = 0x00020000,

  // Fades out sound by next event (sound is continuous or looping)
  IPAS_F_FADES_OUT = 0x00040000,

  // Don't overlap sound of same type
  IPAS_F_NO_OVERLAP = 0x00080000,
  };

/*****************************************************************************
  IPASSound - All sound objects derive from this interface.
*****************************************************************************/

struct IPASSound : IPASObject
  {
  // Sets sound's volume and pan.  You can change the volume of the sound
  // while it is playing.  When the change is heard is determined by the
  // latency and volume/pan slewtime settings of the IPAS interface.
  //   volume <- (min) 0 <= volume <= 1 (max)
  //   pan <- (left) -1 <= balance <= 1 (right)
  STDMETHOD(SetVolumePan)(float volume, float pan) PURE;

  // Allows sound to be repeated.
  //   count <- How many times to play sound (-1 = forever, defaults to 1)
  //   (Call this function prior to starting the sound)
  STDMETHOD(SetLoopCount)(long count) PURE;

  // See the flag definitions in the previous section for details
  //   (Call this function prior to starting the sound)
  STDMETHOD(SetFlags)(long flags) PURE;

  // Set the fade in/out time.
  //   seconds <- How long (defaults to 0)
  //   (Call these functions prior to starting the sound)
  STDMETHOD(SetFadeIn)(float seconds) PURE;
  STDMETHOD(SetFadeOut)(float seconds) PURE;

  // Sets how long to delay after starting timestamp of sound. 
  //   seconds <- How long (can be negative, defaults to 0)
  //   (Call this function prior to starting the sound)
  STDMETHOD(SetDelay)(float seconds) PURE;

  // Sets delay prior to next event.  Negative values cause the sound
  // to fade out before the event, positive values cause it to fade out
  // after the event.
  //   seconds <- How long (can be negative, defaults to 0)
  //   (Call this function prior to starting the sound)
  STDMETHOD(SetAfterDelay)(float seconds) PURE;

  // This queues the sound up for playback.  An AddRef() is performed
  // on a sound when it is started.  When the sound stops playing, it is
  // released.
  //   when <- Timestamp for start of sound
  STDMETHOD(Start)(IPASTimeStamp when) PURE;

  // This function can be used to manually fade out a sound
  // before it has entirely played (or has been set to loop
  // continuously).  The fadeout time specified in the
  // SetFadeOut() is used for the fade.  The sound will stop
  // playing when the volume has reached zero.
  STDMETHOD(FadeOut)(IPASTimeStamp when) PURE;

  // Stops sounds playback immediately.  In cases where the render
  // cursor is well ahead of the play cursor, you may want to call
  // IPAS::Rewind() so that the audio buffer is re-rendered without
  // this sound - that way it will appear to have stopped sooner.
  STDMETHOD(Stop)() PURE;

  // Used to determine if the sound is still playing
  //   playing -> zero: no, non-zero: yes
  STDMETHOD(IsPlaying)(long* p_playing) PURE;

  // Some possible functions:
  //   ??? FadeOutBy(when)
  };

/*****************************************************************************
  IPASMusic - This represents a MIDI file.  Under Windows 95/98,
    DirectMusic is used for playback.  Since DirectMusic isn't supported
    under NT4, MIDI files will have to be played using the Win32
    midiXXX functions (this is not presently implemented so you'll
    get an error trying to play MIDI files under NT4).  NT5/2000 are
    supposed to support DirectMusic, so we're covered there.
*****************************************************************************/

struct IPASMusic : IPASSound
  {
  // Right now there are no functions specific to music, but some likely
  // candidates include:
  //   ??? Reverb settings
  //   ??? Loop point settings
  };

/*****************************************************************************
  IPASSample - This represents a WAVE file (other audio formats will 
    eventually be supported by this interface).
*****************************************************************************/

struct IPASSample : IPASSound
  {
  // Adjusts the playback rate to play the sound faster or slower
  //   rate <- Higher numbers make the sound playback faster (defaults to 1.0)
  //   (Call this function prior to starting the sound)
  STDMETHOD(SetPlaybackRate)(float rate) PURE;

  // These functions allow you to play a subset of the file.  The
  // start and loop offsets default to 0 and the end offset defaults
  // to the length of the original sample.  The start and loop
  // offsets must be less than the end offset.  The loop offset
  // can be smaller than the start offset.
  //   (Call these functions prior to starting the sound)
  STDMETHOD(SetStartOffset)(long offset) PURE;
  STDMETHOD(SetLoopOffset)(long offset) PURE;
  STDMETHOD(SetEndOffset)(long offset) PURE;
  };

/*****************************************************************************
  IPASEvent - Use events to synchronize multiple sounds.
*****************************************************************************/

struct IPASEvent : IPASObject
  {
  // Adds a sound to the event
  // (Call this function prior to committing the event to play)
  STDMETHOD(AddSound)(IPASSound* sound) PURE;

  // After an event has been queued to play with one of the CommitEvent
  // functions, use this function to get the timestamp of when it will
  // actually play.
  STDMETHOD(GetTimeStamp)(IPASTimeStamp* p_stamp) PURE;

  // Possibilities:
  //   Background crossfades
  //   OverrideFadeout(flags)
  };

/*****************************************************************************
  IPAS - This is the primary interface.  
*****************************************************************************/

struct IPAS : IUnknown
  {
  /*** Initialization ***/

  // Initialize IPAS - All of the functions (except Close(), CreatePAM(),
  // and GetDiagnoticError()) can only be called after a successful
  // call to Open().
  //   hInstance <- Calling application's instance
  //   hWnd <- Top-level window (as used by DirectSound)
  //   rate <- Output sample rate (typically 22050 or 44100)
  //   buftime <- DirectSound buffer size (in seconds)
  //   ??? Need a way to select which audio device
  STDMETHOD(Open)(HINSTANCE hInstance, HWND hWnd, long rate, float buftime) PURE;

  // Stops audio immediately and resets IPAS.  Open() can now be called again.
  // All loaded sounds must be released prior to calling this function.
  STDMETHOD(Close)() PURE;

  // Creates the Play Audio Mixer object associated with the
  // current audio output device.
  //   pam -> Play Audio Mixer object (call Release() on it when done)
  STDMETHOD(CreatePAM)(IPAM** p_pam) PURE;

  
  /*** Playback Control ***/

  // Starts audio.  Silence is played until sounds are scheduled
  // for playback.
  STDMETHOD(Play)() PURE;

  // Use to stop playback of audio.  Audio will stop once sound has
  // faded out completely.
  //   when <- When to start fading
  //   fade <- Fade time (in seconds)
  STDMETHOD(FadeOut)(IPASTimeStamp when, float fade) PURE;

  // This function indicates if sound is being played.  It can be
  // used to determine when you can call Close() without clipping
  // off sound that is still fading from a previous call to FadeOut().
  STDMETHOD(IsPlaying)(long* p_playing) PURE;

  // Releases all sounds.  You need to manually rewind if you want
  // the sounds to "disappear" earlier than the current render time.
  STDMETHOD(StopAllSounds)() PURE;


  /*** Master Volume ***/

  // Adjusts amount of time over which to smooth volume/pan transitions
  // so that no clicks or pops are heard.  Defaults to 1/50 second.
  STDMETHOD(SetVolumePanSlewTime)(float seconds) PURE;

  // Sets master rendering volume and pan
  //   volume <- (min) 0 <= volume <= 1 (max)
  //   pan <- (left) -1 <= balance <= 1 (right)
  STDMETHOD(SetVolumePan)(float volume, float pan) PURE;


  /*** Reverb ***/

  // Activates global reverb
  //   enable <- non-zero=enable, zero=disable
  STDMETHOD(SetReverbEnable)(long enable) PURE;

  // Adjusts amount of reverb
  //   volume <- (min) 0 <= volume <= 1 (max)
  STDMETHOD(SetReverbVolume)(float volume) PURE;


  /*** Narration ***/

  // Used to specify the volume level to use for background music or
  // sound (i.e. those sounds with the IPAS_F_NARRATION_FADER flag set)
  // while narration is occurring.  Narration sounds have the
  // IPAS_F_NARRATION flag set. 
  //   volume <- (min) 0 <= volume <= 1 (max)
  //   slewtime <- time (in seconds) for transition in volume to occur
  STDMETHOD(SetNarrationFading)(float volume, float slewtime) PURE;


  /*** Sounds ***/
  
  // These functions load the specified sound.  Call Release() on the
  // sound when you are finished with it.  Starting a sound automatically
  // performs an AddRef() - the sound will be released when it stops
  // playing.  The functions are synchronous and in the case of LoadMusic()
  // can take several seconds to return.
  STDMETHOD(LoadSample)(IPASSample** p_sample, const char* filename) PURE;
  STDMETHOD(LoadMusic)(IPASMusic** p_music, const char* filename) PURE;


  /*** Events ***/

  // Creates a new sound event.  Call Release() on it when you are
  // finished using it.
  STDMETHOD(NewEvent)(IPASEvent** p_event) PURE;

  // Use this function to queue up an event after sounds have been attached
  // to it (i.e. using the AddSound() function).  The event may not actually
  // start at the time specified because of interactions with sounds that
  // may currently be playing.  Use IPASEvent::GetTimeStamp() to determine
  // when the event has really been scheduled.
  STDMETHOD(CommitEvent)(IPASEvent* event, IPASTimeStamp when) PURE;

  // This is used to queue up a pair of events surrounding an interval of
  // time where the CPU is being used intensively for such things as video
  // effects.  Sound is rendered to a point past the second event so
  // that no rendering needs to be performed in the specified interval.
  //   interval <- How much time between events (in seconds)
  //   ahead <- How far to render ahead of event1 (in seconds)
  STDMETHOD(CommitEventPair)(IPASEvent* event1, IPASEvent* event2,
    IPASTimeStamp when, float interval, float ahead) PURE;


  /*** Notification ***/

  // This is the quick & dirty synchronization function.  It blocks
  // until the timestamp has been played or the timeout has expired.  This
  // function utilizes WaitForSingleObject() so you can pass INFINITE for the
  // timeout.  Calling this function with a timestamp that has already
  // played causes it to return immediately.  Returns IPAS_WARNING_TIMEOUT
  // if the timeout period expired prior to reaching the timestamp.
  // More than one thread can call this function simultaneously.
  //   when <- Timestamp to wait for
  //   timeout <- Timeout period (in milliseconds, or INFINITE)
  STDMETHOD(WaitForTimeStamp)(IPASTimeStamp when, DWORD timeout) PURE;

  // Use this function to setup a notification at a particular timestamp.
  // Multiple notifications can be scheduled from multiple threads.  Each
  // is identified by the returned notification handle.
  //   when <- Timestamp of interest
  //   type <- Specifies how to interpret the "data" argument when it comes
  //           time to notify that the play cursor has reached the timestamp
  //     IPAS_NOTIFY_HEVENT:
  //       data <- A Win32 event handle
  //         SetEvent() will be called on this handle.
  //     IPAS_NOTIFY_OBJECT:
  //       data <- An instance of IPASNotifyObject
  //         The Notify() virtual function will be called.  See the
  //         declaration of IPASNotifyObject for more info.
  //   notify -> The notification handle (you can pass NULL if you don't
  //             need the handle)
  STDMETHOD(AddNotification)(IPASTimeStamp when, int type, void* data,
    IPASNotify* p_notify) PURE;

  // This is used to cancel notifications.  It's harmless to call this
  // function with the handle of a notification that has already fired.
  //   notify <- The notification handle returned by AddNotification()
  STDMETHOD(CancelNotification)(IPASNotify notify) PURE;


  /*** Timestamps ***/

  // Retrieves the current latency time.  The default setting is dependant
  // on the current OS and sound driver.  Typical values vary from 150ms to
  // 400ms.  Latency time is the time ahead of the play cursor where it is
  // generally safe to make changes to the audio stream.
  STDMETHOD(GetLatency)(float* p_seconds) PURE;

  // Use this function to change the latency time.
  STDMETHOD(SetLatency)(float seconds) PURE;

  // This advances (or retreats) the timestamp by the time specified
  // IOW, this performs timestamp "arithmetic"
  STDMETHOD(OffsetTimeStamp)(IPASTimeStamp* p_stamp, float seconds) PURE;

  // This computes the time difference between the two timestamps
  //   seconds <- a minus b (in seconds)
  STDMETHOD(TimeStampDelta)(IPASTimeStamp a, IPASTimeStamp b, float* p_seconds) PURE;

  // Gets the timestamp of sound being heard "now".  We're pretty much
  // at the mercy of the sound drivers for an accurate figure here.
  STDMETHOD(GetPlayTimeStamp)(IPASTimeStamp* p_stamp) PURE;

  // This is the timestamp of the latency cursor, which is just the play
  // cursor advanced by the latency time.
  STDMETHOD(GetLatencyTimeStamp)(IPASTimeStamp* p_stamp) PURE;

  // Gets the timestamp of where sound will next be rendered.  Note: This
  // value can be earlier than the play timestamp in certain situations.
  STDMETHOD(GetRenderTimeStamp)(IPASTimeStamp* p_stamp) PURE;


  /*** Rendering ***/
  
  // This function blocks other threads from accessing the interface.
  // This causes background rendering to stop.  Use this function if you
  // are scheduling multiple sounds and you don't want needless rendering
  // going on between calls to IPASSound::Start().  Calls to Lock()
  // can be nested from the same thread.  Quite predictably, you are
  // admonished not to keep the interface locked for longer than
  // necessary.  ;-)
  STDMETHOD(Lock)() PURE;

  // Calls to Lock() should be paired with calls to this function.
  // When the lock count reaches zero, the render cursor is rewound
  // to the earliest sound (or volume change) that was scheduled.
  STDMETHOD(Unlock)() PURE;

  // Enables background rendering by the render thread.  This defaults
  // to enabled after a call to Open().
  //   enable <- non-zero=enable, zero=disable
  STDMETHOD(SetRenderEnable)(long enable) PURE;

  // Rewinds rendering to the point specified by the timestamp.
  // Rendering should be disabled prior to making this call.
  STDMETHOD(Rewind)(IPASTimeStamp when) PURE;

  // Sets how far to render ahead of play cursor.  0.5 seconds is about
  // the lowest value you want to use with NT4, you can get away with less
  // using Win95/98.
  //   ahead <- time (in seconds, default is 1 second)
  STDMETHOD(SetRenderAhead)(float ahead) PURE;

  // Indicates how much audio is rendered ahead of the play cursor.
  // Note: This value can be negative!
  //   ahead -> time (in seconds)
  STDMETHOD(GetRenderedAhead)(float* p_ahead) PURE;

  // Fills the audio buffer.  This function is generally called on a
  // periodic basis by the internal render thread.  It might be useful
  // to manually call this when rendering has been disabled.
  STDMETHOD(Render)() PURE;

  // Sets the rendering thread's priority (defaults to
  // THREAD_PRIORITY_ABOVE_NORMAL).
  STDMETHOD(SetRenderThreadPriority)(int nPriority) PURE;

  // Sets how frequently the render thread calls Render().
  //   interval <- milliseconds (defaults to 50)
  STDMETHOD(SetRenderInterval)(int interval) PURE;


  /*** Errors ***/

  // Returns last OS error code for diagnostic/logging purposes (or 0
  // if none).  Code gets cleared once it is read.  Warning: Presently,
  // another thread could clobber this value before you get a chance
  // to examine it.
  STDMETHOD(GetDiagnosticError)() PURE;
  };

/*****************************************************************************
  Error Codes - Most of the error codes here should translate easily to an
    appropriate message box to show the user when they occur.

  Additional codes that may be returned include:
    E_OUTOFMEMORY
*****************************************************************************/

enum
  {
  IPAS_OK = 0x00000000,
  IPAS_WARNING_ABORTED,          // Wait function aborted by another thread
  IPAS_WARNING_TIMEOUT,          // Wait function timed out
  IPAS_ERROR = 0xE8200000,       // Non-specific error
  IPAS_ERROR_OUT_OF_MEMORY,
  IPAS_ERROR_FILE_NOT_FOUND,
  IPAS_ERROR_FILE_PERMISSION,    // Access permission denied
  IPAS_ERROR_FILE_READ,          // Trouble reading file
  IPAS_ERROR_INVALID_WAVE_FILE,
  IPAS_ERROR_SOUND,              // Non-specific problem with sound device
  IPAS_ERROR_SOUND_IN_USE,       // Sound device in use
  IPAS_ERROR_SOUND_UNSUPPORTED,  // Sound capability unsupported
  IPAS_ERROR_DIRECTMUSIC,        // Non-specific problem with DirectMusic
  IPAS_ERROR_NO_DIRECTMUSIC,     // DirectMusic not available
  IPAS_ERROR_NOT_OPEN,
  IPAS_ERROR_ALREADY_OPEN
  };

/*****************************************************************************
  DLL/Lib/COM Stuff
*****************************************************************************/

// Call this function to create an instance of the IPAS interface.
HRESULT __stdcall CreatePAS(IPAS**);

extern "C" const CLSID CLSID_PAS;
extern "C" const IID IID_IPAS;

/****************************************************************************/

#endif

/* EOF */
