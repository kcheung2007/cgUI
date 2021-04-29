/******************************************************************************************
FileName		    : PlayConstants.h
Version         : $Revision: 19$
Vault File		  : $Archive: \\Source_server\Software\Shared\UtilConst\UtilConst.VLT\VV2.VVF$
Project  		    : $Project: Utility Constants$
Sub Project     : $Subproject: Utility Constants$
Checked in by	  : $Author: tommyo$ 
Locked by	      : $Locker: bambry$
Original Author	: Andy Preston
Purpose		      : Utility Defines for dealing with trinity and files and things !
Date Of Creation: 7/21/99
Copyright       : Play Incorporated 1999
Modification History :
$Log: 
    19  11/17/99    tommyo          Added audio eq setttings table.
    18  11/09/99    apreston        Added TimeMachineSourceTape
    17  10/13/99    apreston        Added Number format const
    16  09/19/99    apreston        Added GPS mixer and RCA Norms board
    15  09/14/99    apreston        Added GPS Expander board
    14  08/25/99    apreston        Added Norms board constant
    13  08/16/99    apreston        Fixed Merge problem
    12  08/16/99    apreston        Added New Picon stream and TFS file streams
    11  08/13/99    bambry          Added LoopCount and PlaySpeed for TimeMachine clips
    10  08/13/99    bambry          Added all the properties found in preditor. Added some 
                                    comments and type about them
    9   08/06/99    apreston        Added New and Old Picon dimensions and Const
    8   08/02/99    apreston        More Clip (LCP file) Constants
    7   07/30/99    apreston        Added PICON constants
    6   07/30/99    apreston        Added more Play Property constants
    5   07/21/99    apreston        Added Starteam Log
    4   07/09/99    apreston        Added PAL/NTSC const
    3   07/09/99    apreston        Log Test
    2   07/09/99    apreston        
    1   07/09/99    apreston        Initial Version
$
$NoKeywords$
******************************************************************************************/


#ifndef _PLAY_CONSTANTS_12345_H
#define _PLAY_CONSTANTS_12345_H

#include <windows.h>
#include <tchar.h>
namespace Props 
{

//Andy Preston 7/9/99- PlayUI structured storage 
 const LPWSTR PlayUIStorage           = L"PlayUI";
 const LPWSTR NTSC601Storage          = L"NTSC601";
 const LPWSTR NTSCALPHAStorage        = L"NTSCALPHA";
 const LPWSTR PAL601Storage           = L"PAL601";
 const LPWSTR PALALPHAStorage         = L"PALALPHA";



 const LPWSTR PlayUIStorageOldPicon   = L"Picon";
 const LPWSTR PlayUIStorage128x96Picon= L"Picon_128x96";
 const LPWSTR PlayUIStorageProperties = L"Properties";

//Andy Preston 7/9/99- Individual Properties
 // benoit : added all the props in preditor (clips, timeline, hardware, effects)
 // and commented, ordered
 // TO DO add a release info (number or date)
 // some of them are found in old files and CANNOT be removed
 // types bitmap, frame, fields mean long (unsigned)

// LONG		SIGNED Speed of the play in 24.8 (ie n/256 * 30 frames/sec)
// preditor 2.0 8/13/99
 const LPTSTR ClpPlaySpeed				 = _T("PlaySpeed");

// LONG		Number of time to play the clip
// preditor 2.0 8/13/99
 const LPTSTR ClpLoopCount				 = _T("LoopCount");

// STRING	com name of the ITrnMediaClip object
// preditor 2.0
 const LPTSTR ClpNLRClipDisplayName      = _T("NLRClipDisplayName");

// STRING	filename of the clip
 const LPTSTR ClpClipName                = _T("ClipName");

// BITMAP	the components available for that clip
 const LPTSTR ClpClipComponents          = _T("ClipComponents");

// STRING	name of the clip file on TimeMachine
 const LPTSTR ClpNLRClipName             = _T("NLRClipName");

// STRING	name of the tape 
 const LPTSTR ClpSourceTape              = _T("SourceTape");

// STRING	file name of a frame store
 const LPTSTR ClpFrameStore              = _T("Framestore");

// STRING	file name for a 601
 const LPTSTR Clp601File				 = _T("601File");

// STRING	file name of an effect
 const LPTSTR ClpTFXName                 = _T("TFXName");

// STRING	reel name of the source for a framestore (digitized)
 const LPTSTR ClpFrameSourceTape         = _T("FrameSourceTape");

// BITMAP	benoit TO BE REMOVED SOON DUPLICATE WITH ClipComponents
 const LPTSTR ClpComponents              = _T("Components");

// BITMAP	components to be inserted when assembling
 const LPTSTR ClpInsertComponents        = _T("InsertComponents");

// BITMAP	components recorded on that clip
 const LPTSTR ClpNLRClipComponents       = _T("NLRClipComponents");

// BITMAP	components recorded on that clip
 const LPTSTR ClpAnimateLevels           = _T("AnimateLevels");

// FRAME	start of the clip on it's media 
 const LPTSTR ClpSourceIn                = _T("SourceIn");

// FRAME	position (in frames) of the first frame of a clip on it's original media
 const LPTSTR ClpNLRClipSrcIn            = _T("NLRClipSrcIn");

// FRAME	length of the clip
 const LPTSTR ClpNLRClipLen              = _T("NLRClipLen");

// LONG		unused (always 0) To be removed?
// preditor 2.0
 const LPTSTR ClpNLRClipOffset           = _T("NLRClipOffset");

// LONG		length of the clip on it's media (in frame)
 const LPTSTR ClpLength                  = _T("Length");

// LONG		Compression ratio used to digitize this clip
// preditor 2.0
 const LPTSTR ClpCompressionRatio        = _T("CompressionRatio");

// LONG		Compression method used
// preditor 2.0
 const LPTSTR ClpCompressionType         = _T("CompressionType");

// LONG		YUV color
 const LPTSTR ClpMatteColor              = _T("MatteColor");

// LONG		Strobe rate
 const LPTSTR ClpStrobeRate              = _T("StrobeRate");

// BOOL		Time code type (dropframe or not)
 const LPTSTR ClpTimeCodeType            = _T("TimeCodeType");

// BOOL		Time code type (dropframe or not)
 // found in CMXEDL
 const LPTSTR ClpDropFrameSource         = _T("DropFrameSource");

// BOOL		If the audio in-point can be moved or not
 const LPTSTR ClpAudioInLocked           = _T("AudioInLocked");

// BOOL		If the audio in-point can be moved or not
 const LPTSTR ClpAudioOutLocked          = _T("AudioOutLocked");

// long		if the audio channel N is muted
 const LPTSTR ClpAudioNLevel             = _T("Audio%03ldLevel");

// BOOL		if the audio channel N is muted
 const LPTSTR ClpAudioNMute              = _T("Audio%dMute");

// LONG		if the gain for audio channel N 
 const LPTSTR ClpAudioNGain              = _T("Audio%dGain");

// LONG		if the pan for audio channel N 
 const LPTSTR ClpAudioNPan               = _T("Audio%dPan");

// LONG		if the pan for audio channel N 
 const LPTSTR ClpAudioAnimateLevels      = _T("AnimateLevels");

// Audio equalizer stuff
#define NUM_EQBAND_SETTINGS    5
const struct 
{
	int					param;			// audio eqparam to change
	LPTSTR				propFmt;		// string format
	int					maxIndex;		// maximum index for that parameter			
} settingInfos[NUM_EQBAND_SETTINGS] =
{
	// the 3 format params are channel #, EQ band #, Param #
	// sscanf format would be "Aud%03d" "Index%d" "Param%d(%s)"
	{ 9, _T("Aud%03d" "Index%d" "Param%d(FilterType)"), 3},
	{ 6, _T("Aud%03d" "Index%d" "Param%d(Gain)"      ), 3},
	{ 7, _T("Aud%03d" "Index%d" "Param%d(CenterFreq)"), 3},
	{ 8, _T("Aud%03d" "Index%d" "Param%d(QFactor)"   ), 3},
	{ 5, _T("Aud%03d" "Index%d" "Param%d"            ), 2}, //FXSend only 2 index
};

// LONG		video source number for a "live" group
 const LPTSTR  ClpLiveSource			 = _T("LiveSource");

// LONG		number of the pin to activate/deactivate
 const LPTSTR  ClpGPIPin				 = _T("GPIPin");

// LONG		action of the GPI Pin
 const LPTSTR  ClpGPIAction				 = _T("GPIAction");

// LONG		
 const LPTSTR  ClpTrackNumber			 = _T("TrackNumber");

// LONG		
 const LPTSTR  ClpExtraPriority			 = _T("Extra Priority");

// FRAME	where (on a tape) has this frame been grabbed
 const LPTSTR  ClpFrameSourceIn			 = _T("FrameSourceIn");

// EFFECTS

// LONG		Time when the effect was created/compiled
 const LPTSTR  EffFileTime				 = _T("FileTime");

// LONG		Event ID generated by a playing effect when it's ended
 const LPTSTR  EffExitEvent				 = _T("ExitEvent");

 const LPTSTR   EffScaleable			 = _T("Scaleable");
 const LPTSTR   EffFileName				 = _T("FileName");
 const LPTSTR   EffGalleryEffect		 = _T("GalleryEffect");
 const LPTSTR   EffDownstreamKey		 = _T("DownstreamKey");
 const LPTSTR   EffUpstreamKey			 = _T("UpstreamKey");
 const LPTSTR   EffDuration				 = _T("Duration");
 const LPTSTR   EffFadeInDuration		 = _T("FadeInDuration");
 const LPTSTR   EffFadeOutDuration		 = _T("FadeOutDuration");
 const LPTSTR   EffSoftness				 = _T("Softness");
 const LPTSTR   EffReversed				 = _T("Reversed");
 const LPTSTR   EffFlipVertical			 = _T("FlipVertical");
 const LPTSTR   EffGradient				 = _T("Gradient");

// STRING
 const LPTSTR   EffBorderType			 = _T("BorderType");
// valid values for Border Type
 const LPTSTR   EffBTOff				 = _T("Off");
 const LPTSTR   EffBTSolidColor			 = _T("Solid Color");
 const LPTSTR   EffBTGraphics			 = _T("Graphics");
 const LPTSTR   EffBTAuxiliarySource	 = _T("Auxiliary Source");

 const LPTSTR   EffBorderColor			 = _T("BorderColor");
 const LPTSTR   EffTransition			 = _T("Transition");
 const LPTSTR   EffAttributes			 = _T("Attributes");
 const LPTSTR   EffObjectId				 = _T("ObjectId");
 const LPTSTR   EffLoopCount			 = _T("LoopCount");
 const LPTSTR   EffLoop1Length			 = _T("Loop1Length");
 const LPTSTR   EffLeaderLength			 = _T("LeaderLength");
 const LPTSTR   EffTrailerLength		 = _T("TrailerLength");

// STRING
 const LPTSTR   EffVideoTrackA			 = _T("Video Track A");
 const LPTSTR   EffVideoTrackB			 = _T("Video Track B");
 const LPTSTR   EffVideoTrackAux		 = _T("Video Track Aux");
// valid values for Tracks
 const LPTSTR   EffVTVideo1				 = _T("Video 1");
 const LPTSTR   EffVTVideo2				 = _T("Video 2");
 const LPTSTR   EffVTVideo3				 = _T("Video 3");

 const LPTSTR   EffBussesWarped			 = _T("BussesWarped");

 
// Hardware 

// VTRS
// FIELDS	number of fields a VTR takes to activate record 
 const LPTSTR  VtrEditDelay				 = _T("EditDelay");

// FIELDS	number of fields a VTR takes to deactivate record 		
 const LPTSTR  VtrEditDelayEnd           = _T("EditDelayEnd");

// FIELDS	minimun preroll of a vtr MinimumPreroll
 const LPTSTR  VtrMinimumPreroll         = _T("MinimumPreroll");

// BOOL		true if no Bumping needed when assembling
 const LPTSTR  VtrDisableBumps			 = _T("DisableBumps");
 
// BOOL		Time code type (dropframe or not)
 const LPTSTR VtrTimeCodeType            = _T("TimeCodeType");

 const LPTSTR TimeMachineSourceTape     =_T("TM Clip");


// Hardware - Audio Device Types
 const DWORD  aeXLRAudioExpanderBoard =2;   // Norms board
 const DWORD  aeRCAAudioExpanderBoard =3;   // Norms RCA board
 const DWORD  aeGPSExpanderBoard =5;   // Pauls GPS Expander board
 const DWORD  aeGPSMixerBoard =6;      // Pauls GPS Expander board - Mixer part

 //Andy Preston 7/9/99-Frame Constants
 const DWORD NTSC_Frame_W=720;
 const DWORD NTSC_Frame_H=486;

 const DWORD PAL_Frame_W=720;
 const DWORD PAL_Frame_H=576;

 const DWORD NEW_PICON_W = 128;
 const DWORD NEW_PICON_H = 96;

 const DWORD OLD_PICON_W = 64;
 const DWORD OLD_PICON_H = 48;




//Andy Preston 10/13/99-Number Format extensions
 const LPTSTR Meg=_T("M");
 const LPTSTR K=_T("K");
 const LPTSTR Bytes=_T("Bytes");
};

#endif