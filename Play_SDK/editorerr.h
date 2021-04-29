#ifndef __EDITORERR_H__
#define __EDITORERR_H__
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_TrinityEditor           0x8ED


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: EDERR_VNPingMangled
//
// MessageText:
//
//  VideoNet ping return mangled.
//
#define EDERR_VNPingMangled              ((ULONG)0xE8ED0001L)

//
// MessageId: EDERR_TrinityMemoryFull
//
// MessageText:
//
//  Trinity memory is full.
//
#define EDERR_TrinityMemoryFull          ((ULONG)0xE8ED0002L)

//
// MessageId: EDERR_UnableToCompleteEditStage
//
// MessageText:
//
//  Unable to complete next stage of edit -- unable to simultaneously load all necessary pieces.
//
#define EDERR_UnableToCompleteEditStage  ((ULONG)0xE8ED0003L)

//
// MessageId: EDERR_RequiredFileMissing
//
// MessageText:
//
//  A required file is missing.
//
#define EDERR_RequiredFileMissing        ((ULONG)0xE8ED0004L)

//
// MessageId: EDERR_NotPreditorTimeline
//
// MessageText:
//
//  The file is not a Preditor timeline.
//
#define EDERR_NotPreditorTimeline        ((ULONG)0xE8ED0005L)

//
// MessageId: EDERR_EmptyTimeline
//
// MessageText:
//
//  The timeline is empty.
//
#define EDERR_EmptyTimeline              ((ULONG)0xE8ED0006L)

//
// MessageId: EDERR_DoesntTranslateToCMX
//
// MessageText:
//
//  The timeline contains items that don't translate to CMX EDL format.
//
#define EDERR_DoesntTranslateToCMX       ((ULONG)0xE8ED0007L)

//
// MessageId: EDERR_NonLinearClipOutOfBounds
//
// MessageText:
//
//  A non-linear clip cannot be played outside its digitized content.
//
#define EDERR_NonLinearClipOutOfBounds   ((ULONG)0xE8ED0008L)

//
// MessageId: EDERR_CannotCreateNeededClipmemSize
//
// MessageText:
//
//  Cannot create ClipMem of necessary size on Trinity.
//
#define EDERR_CannotCreateNeededClipmemSize ((ULONG)0xE8ED0009L)

//
// MessageId: EDERR_MissingRequiredTape
//
// MessageText:
//
//  A tape required for the operation is not in any deck.
//
#define EDERR_MissingRequiredTape        ((ULONG)0xE8ED000AL)

//
// MessageId: EDERR_ClipMemConflict
//
// MessageText:
//
//  Two ClipMems may not be played at the same time.
//
#define EDERR_ClipMemConflict            ((ULONG)0xE8ED000BL)

//
// MessageId: EDERR_WarpConflict
//
// MessageText:
//
//  Two Warp Effects may not be played at the same time.
//
#define EDERR_WarpConflict               ((ULONG)0xE8ED000CL)

//
// MessageId: EDERR_GfxConflict
//
// MessageText:
//
//  Two effects with downstream graphics may not be played at the same time.
//
#define EDERR_GfxConflict                ((ULONG)0xE8ED000DL)

//
// MessageId: EDERR_ViewFXConflict
//
// MessageText:
//
//  Two View Effects (surface wipes and rolls/crawls) may not be played at the same time.
//
#define EDERR_ViewFXConflict             ((ULONG)0xE8ED000EL)

//
// MessageId: EDERR_ClipMemWarpConflict
//
// MessageText:
//
//  A ClipMem cannot be played at the same time as a Warp effect.
//
#define EDERR_ClipMemWarpConflict        ((ULONG)0xE8ED000FL)

//
// MessageId: EDERR_TransitionInvalidateReasonUnknown
//
// MessageText:
//
//  An effect became invalid during operation preparation for unknown reasons.
//
#define EDERR_TransitionInvalidateReasonUnknown ((ULONG)0xE8ED0010L)

//
// MessageId: EDERR_EditRequiresMoreSourceDecks
//
// MessageText:
//
//  Operation cannot be completed without more source VTRs.
//
#define EDERR_EditRequiresMoreSourceDecks ((ULONG)0xE8ED0011L)

//
// MessageId: EDERR_CantTransitionClipsSameTape
//
// MessageText:
//
//  Cannot transition between clips from same tape.  Try A|X or A|V roll.
//
#define EDERR_CantTransitionClipsSameTape ((ULONG)0xE8ED0012L)

//
// MessageId: EDERR_CantMixAudioClipsSameTape
//
// MessageText:
//
//  Cannot mix audio from clips from same tape.  Remove audio from one or the other.
//
#define EDERR_CantMixAudioClipsSameTape  ((ULONG)0xE8ED0013L)

//
// MessageId: EDERR_RequiresAtLeastOneSourceDeck
//
// MessageText:
//
//  Operation cannot be completed without at least one source VTR.
//
#define EDERR_RequiresAtLeastOneSourceDeck ((ULONG)0xE8ED0014L)

//
// MessageId: EDERR_OperationTimedOut
//
// MessageText:
//
//  The operation timed out.  Are all decks in remote?
//
#define EDERR_OperationTimedOut          ((ULONG)0xE8ED0015L)

//
// MessageId: EDERR_AbortedInaccurateEdit
//
// MessageText:
//
//  Operation aborted due to inaccurate edit.
//
#define EDERR_AbortedInaccurateEdit      ((ULONG)0xE8ED0016L)

//
// MessageId: EDERR_MissingRecordTape
//
// MessageText:
//
//  The selected operation requires a recordable tape in the record deck.
//
#define EDERR_MissingRecordTape          ((ULONG)0xE8ED0017L)

//
// MessageId: EDERR_DecksDidntPlay
//
// MessageText:
//
//  One or more decks didn't start playing.
//
#define EDERR_DecksDidntPlay             ((ULONG)0xE8ED0018L)

//
// MessageId: EDERR_WarpEffectCantPlay
//
// MessageText:
//
//  Warp effect(s) in timeline cannot be played because there are no warp engines in your Trinity system.
//
#define EDERR_WarpEffectCantPlay         ((ULONG)0xE8ED0019L)

//
// MessageId: EDERR_CantSelectFramestoreWhileSwitcherBusy
//
// MessageText:
//
//  Cannot select framestore to output while switcher's playing a DSK (change in-point or buy a warp engine).
//
#define EDERR_CantSelectFramestoreWhileSwitcherBusy ((ULONG)0xE8ED001AL)

//
// MessageId: EDERR_CantPlayClipmemWithoutWarper
//
// MessageText:
//
//  Cannot play clipmem without a warp engine.
//
#define EDERR_CantPlayClipmemWithoutWarper ((ULONG)0xE8ED001BL)

//
// MessageId: EDERR_EAttemptedEditorLayoutInSwitcher
//
// MessageText:
//
//  Cannot load a Preditor layout while running the Switcher.
//
#define EDERR_EAttemptedEditorLayoutInSwitcher ((ULONG)0xE8ED001CL)

//
// MessageId: EDERR_EAttemptedSwitcherLayoutInEditor
//
// MessageText:
//
//  Cannot load a Switcher layout while running Preditor.
//
#define EDERR_EAttemptedSwitcherLayoutInEditor ((ULONG)0xE8ED001DL)

//
// MessageId: EDERR_ClipTooCloseToStartOfTape
//
// MessageText:
//
//  Cannot preroll clip because it starts within preroll time of the beginning of the tape.
//
#define EDERR_ClipTooCloseToStartOfTape  ((ULONG)0xE8ED001EL)

//
// MessageId: EDERR_HitEndOfTape
//
// MessageText:
//
//  Cannot preroll clip -- ran into End of Tape.
//
#define EDERR_HitEndOfTape               ((ULONG)0xE8ED001FL)

//
// MessageId: EDERR_SourceDeckNotRemote
//
// MessageText:
//
//  One or more source decks is not in remote mode -- change it and try again.
//
#define EDERR_SourceDeckNotRemote        ((ULONG)0xE8ED0020L)

//
// MessageId: EDERR_RecordDeckNotRemote
//
// MessageText:
//
//  The record deck is not in remote mode -- change it and try again.
//
#define EDERR_RecordDeckNotRemote        ((ULONG)0xE8ED0021L)

//
// MessageId: EDERR_DupCheckOKButNoObjects
//
// MessageText:
//
//  (Internal error) Duplicate tape check succeeded, but have no objects to process.
//
#define EDERR_DupCheckOKButNoObjects     ((ULONG)0xE8ED0022L)

//
// MessageId: EDERR_DeckFailedToEnterEditMode
//
// MessageText:
//
//  The recorder failed to go into edit mode.
//
#define EDERR_DeckFailedToEnterEditMode  ((ULONG)0xE8ED0023L)

//
// MessageId: EDERR_EDLContainsUnsupportedEditTypes
//
// MessageText:
//
//  Unsupported edit type -- it contains edit types that aren't yet supported in Preditor.
//
#define EDERR_EDLContainsUnsupportedEditTypes ((ULONG)0xE8ED0024L)

//
// MessageId: EDERR_EDLTypeUnknown
//
// MessageText:
//
//  Incorrect EDL format -- it must be CMX 3400 or 3600 to be imported.
//
#define EDERR_EDLTypeUnknown             ((ULONG)0xE8ED0025L)

//
// MessageId: EDERR_FoundNoVTRWithNeededTape
//
// MessageText:
//
//  Could not find a VTR containing the needed tape.
//
#define EDERR_FoundNoVTRWithNeededTape   ((ULONG)0xE8ED0026L)

//
// MessageId: EDERR_TimedOutGrabbingFramestore
//
// MessageText:
//
//  Timed out waiting for framestore to be transferred from Trinity.
//
#define EDERR_TimedOutGrabbingFramestore ((ULONG)0xE8ED0027L)

// ------------------------------------------------------------------------
//                 unused     0x8ed0028
// ------------------------------------------------------------------------
#endif     // __EDITORERR_H__
