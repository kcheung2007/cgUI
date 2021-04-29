/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Nov 23 05:28:37 1999
 */
/* Compiler settings for tminternal.idl:
    Oi (OptLev=i0), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __tminternal_h__
#define __tminternal_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITrnTimeMachineInternal_FWD_DEFINED__
#define __ITrnTimeMachineInternal_FWD_DEFINED__
typedef interface ITrnTimeMachineInternal ITrnTimeMachineInternal;
#endif 	/* __ITrnTimeMachineInternal_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "objidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL_itf_tminternal_0000
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#undef GetCurrentTime


extern RPC_IF_HANDLE __MIDL_itf_tminternal_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tminternal_0000_v0_0_s_ifspec;

#ifndef __ITrnTimeMachineInternal_INTERFACE_DEFINED__
#define __ITrnTimeMachineInternal_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITrnTimeMachineInternal
 * at Tue Nov 23 05:28:37 1999
 * using MIDL 3.01.75
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef unsigned char ubyte;

typedef unsigned short uword;

typedef unsigned long uquad;

typedef DWORD tTIME;

typedef DWORD tCHANNEL;

typedef DWORD tLBA;

typedef struct tagClipInfo TMS_ClipInfo;

typedef struct tagDriveInfo TMS_DriveInfo;

typedef struct  tagsense_data
    {
    ubyte sensekey;
    ubyte sensecode;
    ubyte sensecodequalifier;
    ubyte senseFRUcode;
    }	TMS_SD;

typedef struct  tagSCSIInfo
    {
    ubyte status;
    ubyte device_type;
    uword blocklength;
    uquad lastblock;
    ubyte offperiod;
    ubyte sync_clk;
    ubyte version;
    ubyte msg_in;
    TMS_SD sense;
    }	TMS_SCSIInfo;

#define DRIVE_INFO_SIZE 36
#define REQUEST_SENSE_SIZE  18
#define TERMINATOR_SIZE 0xFFFFFFFF
typedef struct  tagSCSIDriveInfo
    {
    uquad sdi_SCSIInfoSize;
    TMS_SCSIInfo sdi_SCSIInfo;
    uquad sdi_DriveInfoSize;
    unsigned char sdi_DriveInfo[ 36 ];
    uquad sdi_RequestSenseSize;
    unsigned char sdi_RequestSense[ 20 ];
    uquad sdi_TerminatorSize;
    }	TMS_SCSIDriveInfo;

#define CLIPNAME_SIZE 80
#define DRIVENAME_SIZE 80
#define DRIVE_MODE_SIZE 256
#define BLOCK_SIZE  512
typedef struct  tagDirEntry
    {
    uword de_Hash;
    uword de_Flags;
    tTIME de_Time;
    uquad de_Size[ 2 ];
    tLBA de_FirstLBA;
    tLBA de_HeaderLBA;
    tLBA de_Indirect2LBA;
    tLBA de_Indirect3LBA;
    uquad de_LargestFieldSize;
    uquad de_NameTag;
    unsigned char de_Name[ 80 ];
    }	TMS_DirEntry;


enum __MIDL_ITrnTimeMachineInternal_0001
    {	WAVELET_INDEX	= 0,
	AUDIO32_INDEX	= 1,
	CLIPINFO_INDEX	= 2,
	FILE_INDEX	= 3,
	DIRECTORY_INDEX	= 4
    };

enum TARDIS_CHANNELS
    {	VIDEO1_CHANNEL	= 0x10001,
	VIDEO2_CHANNEL	= 0x10002,
	AUDIO1_CHANNEL	= 0x20001,
	AUDIO2_CHANNEL	= 0x20002,
	AUDIO3_CHANNEL	= 0x20003,
	AUDIO4_CHANNEL	= 0x20004,
	UNUSED_CHANNEL	= 0
    };
#define de_ClipFields  de_FirstLBA         // valid for Video clips only!
#define de_DiskId      de_LargestFieldSize // valid for disk labels only!
typedef struct  tagPlayList
    {
    LONG tpca_Duration;
    LONG tpca_StartPosition;
    LONG tpca_LinearDelta;
    LONG tpca_SecondDelta;
    LONG tpca_ThirdDelta;
    }	TMS_PlayList;

typedef struct  tagStripingInfo
    {
    int si_Striping_Factor;
    int si_DriveIndex[ 4 ];
    }	TMS_StripingInfo;

typedef struct  tagClipIO
    {
    struct tagClipIO __RPC_FAR *Next;
    LONG Cookie;
    LONG Command;
    LONG BufferOffset;
    LONG BufferSize;
    LONG Flags;
    LONG LastFlags;
    TMS_ClipInfo __RPC_FAR *cInfo;
    ULONG ClipPosition;
    ULONG TransferAmount;
    ULONG CurrentTransferred;
    ULONG FieldNumber;
    ULONG FieldSize;
    }	TMS_ClipIO;

#define CLIPIOFLAGS_COMPLETE    0x00000001    // bitmask
typedef struct  tagClipBufferStatus
    {
    TMS_ClipInfo __RPC_FAR *cbs_ClipInfo;
    ULONG cbs_Command;
    ULONG cbs_CurrentTransferred;
    ULONG cbs_TransferAmount;
    ULONG cbs_FieldSize;
    ULONG cbs_FieldNumber;
    }	TMS_ClipBufferStatus;

// Flags values for GetDriveStatus
#define	ONLY_KNOWN_DRIVES		0x10
#define	INQUIRE_DRIVE_INFO	0x08
#define	SPIN_UP_DRIVES		0x04
#define	BLOCK_UNTIL_READY		0x02
#define	BYPASS_DRIVE_CACHE	0x01
typedef struct  tagDriveStatus
    {
    ULONG Status;
    ULONG Detected;
    ULONG Ready;
    }	TMS_DriveStatus;


EXTERN_C const IID IID_ITrnTimeMachineInternal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8335e7e7-ab3b-11ce-8468-0000b468276b")
    ITrnTimeMachineInternal : public IUnknown
    {
    public:
        virtual int STDMETHODCALLTYPE SCSI_Lock( 
            int iDrive) = 0;
        
        virtual int STDMETHODCALLTYPE SCSI_Unlock( 
            int iDrive) = 0;
        
        virtual int STDMETHODCALLTYPE GetSCSIDriveInfo( 
            int iDrive,
            TMS_SCSIDriveInfo __RPC_FAR *pSDI) = 0;
        
        virtual int STDMETHODCALLTYPE GetSCSIInfo( 
            int iDrive,
            TMS_SCSIInfo __RPC_FAR *pSI) = 0;
        
        virtual int STDMETHODCALLTYPE GetDriveInfo( 
            int iDrive,
            int query_drive,
            ubyte __RPC_FAR *pDI) = 0;
        
        virtual int STDMETHODCALLTYPE GetRequestSense( 
            int iDrive,
            int query_sense,
            ubyte __RPC_FAR *pRS) = 0;
        
        virtual int STDMETHODCALLTYPE format_unit( 
            int drive) = 0;
        
        virtual int STDMETHODCALLTYPE reserve_unit( 
            int drive) = 0;
        
        virtual int STDMETHODCALLTYPE release_unit( 
            int drive) = 0;
        
        virtual int STDMETHODCALLTYPE d_mode_select( 
            int drive,
            int page,
            int length,
            ubyte __RPC_FAR *buffer) = 0;
        
        virtual int STDMETHODCALLTYPE d_mode_sense( 
            int drive,
            int page,
            int length,
            ubyte __RPC_FAR *buffer) = 0;
        
        virtual int STDMETHODCALLTYPE start_drive( 
            int drive,
            int start) = 0;
        
        virtual int STDMETHODCALLTYPE read_block( 
            int drive,
            uquad blocknum,
            ubyte __RPC_FAR *buffer) = 0;
        
        virtual int STDMETHODCALLTYPE write_block( 
            int drive,
            uquad blocknum,
            ubyte __RPC_FAR *buffer) = 0;
        
        virtual TMS_ClipInfo __RPC_FAR *STDMETHODCALLTYPE ClipAlloc( 
            int ClipType) = 0;
        
        virtual void STDMETHODCALLTYPE ClipFree( 
            TMS_ClipInfo __RPC_FAR *cInfo) = 0;
        
        virtual void STDMETHODCALLTYPE ClipFlush( 
            TMS_ClipInfo __RPC_FAR *cInfo) = 0;
        
        virtual int STDMETHODCALLTYPE PlayClip( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            tCHANNEL target,
            tTIME StartTime,
            TMS_PlayList __RPC_FAR *pList) = 0;
        
        virtual int STDMETHODCALLTYPE RecordClip( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            tCHANNEL target,
            tTIME StartTime) = 0;
        
        virtual int STDMETHODCALLTYPE SetClipDrives( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            TMS_StripingInfo __RPC_FAR *sInfo) = 0;
        
        virtual int STDMETHODCALLTYPE ClipDestroy( 
            TMS_ClipInfo __RPC_FAR *cInfo) = 0;
        
        virtual int STDMETHODCALLTYPE ClipCreate( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName) = 0;
        
        virtual int STDMETHODCALLTYPE ClipExists( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName) = 0;
        
        virtual int STDMETHODCALLTYPE ClipRename( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *newClipName) = 0;
        
        virtual int STDMETHODCALLTYPE ClipOpen( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName) = 0;
        
        virtual int STDMETHODCALLTYPE ClipClose( 
            TMS_ClipInfo __RPC_FAR *cInfo) = 0;
        
        virtual void STDMETHODCALLTYPE GetClipInfo( 
            TMS_ClipInfo __RPC_FAR *cInfo,
            int EntryMask,
            TMS_DirEntry __RPC_FAR *dEntry) = 0;
        
        virtual TMS_DriveInfo __RPC_FAR *STDMETHODCALLTYPE AllocDriveInfo( 
            int iDrive,
            uquad nLBAs) = 0;
        
        virtual void STDMETHODCALLTYPE FreeDriveInfo( 
            int iDrive) = 0;
        
        virtual void STDMETHODCALLTYPE FlushDriveInfo( 
            int iDrive) = 0;
        
        virtual int STDMETHODCALLTYPE FormatDriveInfo( 
            int iDrive,
            uquad ID,
            unsigned char __RPC_FAR *DriveName) = 0;
        
        virtual int STDMETHODCALLTYPE ListDirAlloc( 
            int iDrive,
            uquad Directory,
            TMS_DirEntry __RPC_FAR *dEntry) = 0;
        
        virtual int STDMETHODCALLTYPE ListDirFree( 
            int iDrive,
            uquad ListDirAllocResult) = 0;
        
        virtual int STDMETHODCALLTYPE ListDirEntry( 
            int iDrive,
            uquad PreviousResult,
            TMS_DirEntry __RPC_FAR *dEntry) = 0;
        
        virtual int STDMETHODCALLTYPE ListDirEntryType( 
            int iDrive,
            ULONG Directory,
            ULONG TypeValue,
            ULONG TypeMask,
            TMS_DirEntry __RPC_FAR *dEntry) = 0;
        
        virtual void STDMETHODCALLTYPE SetCurrentTime( 
            tTIME Seconds,
            uquad Fraction) = 0;
        
        virtual void STDMETHODCALLTYPE GetCurrentTime( 
            tTIME __RPC_FAR *pSeconds,
            tTIME __RPC_FAR *pFraction) = 0;
        
        virtual int STDMETHODCALLTYPE SetTDMInstanceID( 
            int TDMInstanceID) = 0;
        
        virtual int STDMETHODCALLTYPE SetAudioChannelSlots( 
            int AudioSlot,
            int TDMSlot) = 0;
        
        virtual TMS_ClipIO __RPC_FAR *STDMETHODCALLTYPE ClipBufferAlloc( 
            int MaxBufferSize,
            int Flags) = 0;
        
        virtual int STDMETHODCALLTYPE ClipBufferFree( 
            TMS_ClipIO __RPC_FAR *__MIDL_0008) = 0;
        
        virtual int STDMETHODCALLTYPE ClipBufferWrite( 
            TMS_ClipIO __RPC_FAR *__MIDL_0009,
            TMS_ClipInfo __RPC_FAR *__MIDL_0010,
            int FieldNumber,
            int Position,
            int Size) = 0;
        
        virtual int STDMETHODCALLTYPE ClipBufferRead( 
            TMS_ClipIO __RPC_FAR *__MIDL_0011,
            TMS_ClipInfo __RPC_FAR *__MIDL_0012,
            int FieldNumber,
            int Position,
            int Size) = 0;
        
        virtual int STDMETHODCALLTYPE QueryFieldSize( 
            TMS_ClipInfo __RPC_FAR *__MIDL_0013,
            int Field) = 0;
        
        virtual int STDMETHODCALLTYPE ClipBufferStatus( 
            TMS_ClipIO __RPC_FAR *pClipIO,
            TMS_ClipBufferStatus __RPC_FAR *pCBS) = 0;
        
        virtual int STDMETHODCALLTYPE ClipBufferAbort( 
            TMS_ClipIO __RPC_FAR *pClipIO) = 0;
        
        virtual int STDMETHODCALLTYPE GetDriveStatus( 
            ULONG flags,
            TMS_DriveStatus __RPC_FAR *pStatus) = 0;
        
        virtual int STDMETHODCALLTYPE SetDriveLabel( 
            int iDrive,
            TMS_DirEntry __RPC_FAR *dEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransactMessage( 
            DWORD commandId,
            unsigned int paramSize,
            void __RPC_FAR *pParamsBuff,
            unsigned int resultSize,
            void __RPC_FAR *pResultBuff) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITrnTimeMachineInternalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITrnTimeMachineInternal __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITrnTimeMachineInternal __RPC_FAR * This);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SCSI_Lock )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SCSI_Unlock )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *GetSCSIDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            TMS_SCSIDriveInfo __RPC_FAR *pSDI);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *GetSCSIInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            TMS_SCSIInfo __RPC_FAR *pSI);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            int query_drive,
            ubyte __RPC_FAR *pDI);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *GetRequestSense )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            int query_sense,
            ubyte __RPC_FAR *pRS);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *format_unit )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *reserve_unit )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *release_unit )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *d_mode_select )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive,
            int page,
            int length,
            ubyte __RPC_FAR *buffer);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *d_mode_sense )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive,
            int page,
            int length,
            ubyte __RPC_FAR *buffer);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *start_drive )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive,
            int start);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *read_block )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive,
            uquad blocknum,
            ubyte __RPC_FAR *buffer);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *write_block )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int drive,
            uquad blocknum,
            ubyte __RPC_FAR *buffer);
        
        TMS_ClipInfo __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *ClipAlloc )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int ClipType);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ClipFree )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *ClipFlush )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *PlayClip )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            tCHANNEL target,
            tTIME StartTime,
            TMS_PlayList __RPC_FAR *pList);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *RecordClip )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            tCHANNEL target,
            tTIME StartTime);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SetClipDrives )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            TMS_StripingInfo __RPC_FAR *sInfo);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipDestroy )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipCreate )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipExists )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipRename )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *newClipName);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipOpen )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            unsigned char __RPC_FAR *ClipName);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipClose )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetClipInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *cInfo,
            int EntryMask,
            TMS_DirEntry __RPC_FAR *dEntry);
        
        TMS_DriveInfo __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *AllocDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            uquad nLBAs);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *FreeDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *FlushDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *FormatDriveInfo )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            uquad ID,
            unsigned char __RPC_FAR *DriveName);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ListDirAlloc )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            uquad Directory,
            TMS_DirEntry __RPC_FAR *dEntry);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ListDirFree )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            uquad ListDirAllocResult);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ListDirEntry )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            uquad PreviousResult,
            TMS_DirEntry __RPC_FAR *dEntry);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ListDirEntryType )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            ULONG Directory,
            ULONG TypeValue,
            ULONG TypeMask,
            TMS_DirEntry __RPC_FAR *dEntry);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentTime )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            tTIME Seconds,
            uquad Fraction);
        
        void ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentTime )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            tTIME __RPC_FAR *pSeconds,
            tTIME __RPC_FAR *pFraction);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SetTDMInstanceID )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int TDMInstanceID);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SetAudioChannelSlots )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int AudioSlot,
            int TDMSlot);
        
        TMS_ClipIO __RPC_FAR *( STDMETHODCALLTYPE __RPC_FAR *ClipBufferAlloc )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int MaxBufferSize,
            int Flags);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipBufferFree )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipIO __RPC_FAR *__MIDL_0008);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipBufferWrite )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipIO __RPC_FAR *__MIDL_0009,
            TMS_ClipInfo __RPC_FAR *__MIDL_0010,
            int FieldNumber,
            int Position,
            int Size);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipBufferRead )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipIO __RPC_FAR *__MIDL_0011,
            TMS_ClipInfo __RPC_FAR *__MIDL_0012,
            int FieldNumber,
            int Position,
            int Size);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *QueryFieldSize )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipInfo __RPC_FAR *__MIDL_0013,
            int Field);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipBufferStatus )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipIO __RPC_FAR *pClipIO,
            TMS_ClipBufferStatus __RPC_FAR *pCBS);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *ClipBufferAbort )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            TMS_ClipIO __RPC_FAR *pClipIO);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *GetDriveStatus )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            ULONG flags,
            TMS_DriveStatus __RPC_FAR *pStatus);
        
        int ( STDMETHODCALLTYPE __RPC_FAR *SetDriveLabel )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            int iDrive,
            TMS_DirEntry __RPC_FAR *dEntry);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TransactMessage )( 
            ITrnTimeMachineInternal __RPC_FAR * This,
            DWORD commandId,
            unsigned int paramSize,
            void __RPC_FAR *pParamsBuff,
            unsigned int resultSize,
            void __RPC_FAR *pResultBuff);
        
        END_INTERFACE
    } ITrnTimeMachineInternalVtbl;

    interface ITrnTimeMachineInternal
    {
        CONST_VTBL struct ITrnTimeMachineInternalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITrnTimeMachineInternal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITrnTimeMachineInternal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITrnTimeMachineInternal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITrnTimeMachineInternal_SCSI_Lock(This,iDrive)	\
    (This)->lpVtbl -> SCSI_Lock(This,iDrive)

#define ITrnTimeMachineInternal_SCSI_Unlock(This,iDrive)	\
    (This)->lpVtbl -> SCSI_Unlock(This,iDrive)

#define ITrnTimeMachineInternal_GetSCSIDriveInfo(This,iDrive,pSDI)	\
    (This)->lpVtbl -> GetSCSIDriveInfo(This,iDrive,pSDI)

#define ITrnTimeMachineInternal_GetSCSIInfo(This,iDrive,pSI)	\
    (This)->lpVtbl -> GetSCSIInfo(This,iDrive,pSI)

#define ITrnTimeMachineInternal_GetDriveInfo(This,iDrive,query_drive,pDI)	\
    (This)->lpVtbl -> GetDriveInfo(This,iDrive,query_drive,pDI)

#define ITrnTimeMachineInternal_GetRequestSense(This,iDrive,query_sense,pRS)	\
    (This)->lpVtbl -> GetRequestSense(This,iDrive,query_sense,pRS)

#define ITrnTimeMachineInternal_format_unit(This,drive)	\
    (This)->lpVtbl -> format_unit(This,drive)

#define ITrnTimeMachineInternal_reserve_unit(This,drive)	\
    (This)->lpVtbl -> reserve_unit(This,drive)

#define ITrnTimeMachineInternal_release_unit(This,drive)	\
    (This)->lpVtbl -> release_unit(This,drive)

#define ITrnTimeMachineInternal_d_mode_select(This,drive,page,length,buffer)	\
    (This)->lpVtbl -> d_mode_select(This,drive,page,length,buffer)

#define ITrnTimeMachineInternal_d_mode_sense(This,drive,page,length,buffer)	\
    (This)->lpVtbl -> d_mode_sense(This,drive,page,length,buffer)

#define ITrnTimeMachineInternal_start_drive(This,drive,start)	\
    (This)->lpVtbl -> start_drive(This,drive,start)

#define ITrnTimeMachineInternal_read_block(This,drive,blocknum,buffer)	\
    (This)->lpVtbl -> read_block(This,drive,blocknum,buffer)

#define ITrnTimeMachineInternal_write_block(This,drive,blocknum,buffer)	\
    (This)->lpVtbl -> write_block(This,drive,blocknum,buffer)

#define ITrnTimeMachineInternal_ClipAlloc(This,ClipType)	\
    (This)->lpVtbl -> ClipAlloc(This,ClipType)

#define ITrnTimeMachineInternal_ClipFree(This,cInfo)	\
    (This)->lpVtbl -> ClipFree(This,cInfo)

#define ITrnTimeMachineInternal_ClipFlush(This,cInfo)	\
    (This)->lpVtbl -> ClipFlush(This,cInfo)

#define ITrnTimeMachineInternal_PlayClip(This,cInfo,target,StartTime,pList)	\
    (This)->lpVtbl -> PlayClip(This,cInfo,target,StartTime,pList)

#define ITrnTimeMachineInternal_RecordClip(This,cInfo,target,StartTime)	\
    (This)->lpVtbl -> RecordClip(This,cInfo,target,StartTime)

#define ITrnTimeMachineInternal_SetClipDrives(This,cInfo,sInfo)	\
    (This)->lpVtbl -> SetClipDrives(This,cInfo,sInfo)

#define ITrnTimeMachineInternal_ClipDestroy(This,cInfo)	\
    (This)->lpVtbl -> ClipDestroy(This,cInfo)

#define ITrnTimeMachineInternal_ClipCreate(This,cInfo,ClipName)	\
    (This)->lpVtbl -> ClipCreate(This,cInfo,ClipName)

#define ITrnTimeMachineInternal_ClipExists(This,cInfo,ClipName)	\
    (This)->lpVtbl -> ClipExists(This,cInfo,ClipName)

#define ITrnTimeMachineInternal_ClipRename(This,cInfo,newClipName)	\
    (This)->lpVtbl -> ClipRename(This,cInfo,newClipName)

#define ITrnTimeMachineInternal_ClipOpen(This,cInfo,ClipName)	\
    (This)->lpVtbl -> ClipOpen(This,cInfo,ClipName)

#define ITrnTimeMachineInternal_ClipClose(This,cInfo)	\
    (This)->lpVtbl -> ClipClose(This,cInfo)

#define ITrnTimeMachineInternal_GetClipInfo(This,cInfo,EntryMask,dEntry)	\
    (This)->lpVtbl -> GetClipInfo(This,cInfo,EntryMask,dEntry)

#define ITrnTimeMachineInternal_AllocDriveInfo(This,iDrive,nLBAs)	\
    (This)->lpVtbl -> AllocDriveInfo(This,iDrive,nLBAs)

#define ITrnTimeMachineInternal_FreeDriveInfo(This,iDrive)	\
    (This)->lpVtbl -> FreeDriveInfo(This,iDrive)

#define ITrnTimeMachineInternal_FlushDriveInfo(This,iDrive)	\
    (This)->lpVtbl -> FlushDriveInfo(This,iDrive)

#define ITrnTimeMachineInternal_FormatDriveInfo(This,iDrive,ID,DriveName)	\
    (This)->lpVtbl -> FormatDriveInfo(This,iDrive,ID,DriveName)

#define ITrnTimeMachineInternal_ListDirAlloc(This,iDrive,Directory,dEntry)	\
    (This)->lpVtbl -> ListDirAlloc(This,iDrive,Directory,dEntry)

#define ITrnTimeMachineInternal_ListDirFree(This,iDrive,ListDirAllocResult)	\
    (This)->lpVtbl -> ListDirFree(This,iDrive,ListDirAllocResult)

#define ITrnTimeMachineInternal_ListDirEntry(This,iDrive,PreviousResult,dEntry)	\
    (This)->lpVtbl -> ListDirEntry(This,iDrive,PreviousResult,dEntry)

#define ITrnTimeMachineInternal_ListDirEntryType(This,iDrive,Directory,TypeValue,TypeMask,dEntry)	\
    (This)->lpVtbl -> ListDirEntryType(This,iDrive,Directory,TypeValue,TypeMask,dEntry)

#define ITrnTimeMachineInternal_SetCurrentTime(This,Seconds,Fraction)	\
    (This)->lpVtbl -> SetCurrentTime(This,Seconds,Fraction)

#define ITrnTimeMachineInternal_GetCurrentTime(This,pSeconds,pFraction)	\
    (This)->lpVtbl -> GetCurrentTime(This,pSeconds,pFraction)

#define ITrnTimeMachineInternal_SetTDMInstanceID(This,TDMInstanceID)	\
    (This)->lpVtbl -> SetTDMInstanceID(This,TDMInstanceID)

#define ITrnTimeMachineInternal_SetAudioChannelSlots(This,AudioSlot,TDMSlot)	\
    (This)->lpVtbl -> SetAudioChannelSlots(This,AudioSlot,TDMSlot)

#define ITrnTimeMachineInternal_ClipBufferAlloc(This,MaxBufferSize,Flags)	\
    (This)->lpVtbl -> ClipBufferAlloc(This,MaxBufferSize,Flags)

#define ITrnTimeMachineInternal_ClipBufferFree(This,__MIDL_0008)	\
    (This)->lpVtbl -> ClipBufferFree(This,__MIDL_0008)

#define ITrnTimeMachineInternal_ClipBufferWrite(This,__MIDL_0009,__MIDL_0010,FieldNumber,Position,Size)	\
    (This)->lpVtbl -> ClipBufferWrite(This,__MIDL_0009,__MIDL_0010,FieldNumber,Position,Size)

#define ITrnTimeMachineInternal_ClipBufferRead(This,__MIDL_0011,__MIDL_0012,FieldNumber,Position,Size)	\
    (This)->lpVtbl -> ClipBufferRead(This,__MIDL_0011,__MIDL_0012,FieldNumber,Position,Size)

#define ITrnTimeMachineInternal_QueryFieldSize(This,__MIDL_0013,Field)	\
    (This)->lpVtbl -> QueryFieldSize(This,__MIDL_0013,Field)

#define ITrnTimeMachineInternal_ClipBufferStatus(This,pClipIO,pCBS)	\
    (This)->lpVtbl -> ClipBufferStatus(This,pClipIO,pCBS)

#define ITrnTimeMachineInternal_ClipBufferAbort(This,pClipIO)	\
    (This)->lpVtbl -> ClipBufferAbort(This,pClipIO)

#define ITrnTimeMachineInternal_GetDriveStatus(This,flags,pStatus)	\
    (This)->lpVtbl -> GetDriveStatus(This,flags,pStatus)

#define ITrnTimeMachineInternal_SetDriveLabel(This,iDrive,dEntry)	\
    (This)->lpVtbl -> SetDriveLabel(This,iDrive,dEntry)

#define ITrnTimeMachineInternal_TransactMessage(This,commandId,paramSize,pParamsBuff,resultSize,pResultBuff)	\
    (This)->lpVtbl -> TransactMessage(This,commandId,paramSize,pParamsBuff,resultSize,pResultBuff)

#endif /* COBJMACROS */


#endif 	/* C style interface */



int STDMETHODCALLTYPE ITrnTimeMachineInternal_SCSI_Lock_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive);


void __RPC_STUB ITrnTimeMachineInternal_SCSI_Lock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_SCSI_Unlock_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive);


void __RPC_STUB ITrnTimeMachineInternal_SCSI_Unlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_GetSCSIDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    TMS_SCSIDriveInfo __RPC_FAR *pSDI);


void __RPC_STUB ITrnTimeMachineInternal_GetSCSIDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_GetSCSIInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    TMS_SCSIInfo __RPC_FAR *pSI);


void __RPC_STUB ITrnTimeMachineInternal_GetSCSIInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_GetDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    int query_drive,
    ubyte __RPC_FAR *pDI);


void __RPC_STUB ITrnTimeMachineInternal_GetDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_GetRequestSense_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    int query_sense,
    ubyte __RPC_FAR *pRS);


void __RPC_STUB ITrnTimeMachineInternal_GetRequestSense_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_format_unit_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive);


void __RPC_STUB ITrnTimeMachineInternal_format_unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_reserve_unit_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive);


void __RPC_STUB ITrnTimeMachineInternal_reserve_unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_release_unit_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive);


void __RPC_STUB ITrnTimeMachineInternal_release_unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_d_mode_select_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive,
    int page,
    int length,
    ubyte __RPC_FAR *buffer);


void __RPC_STUB ITrnTimeMachineInternal_d_mode_select_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_d_mode_sense_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive,
    int page,
    int length,
    ubyte __RPC_FAR *buffer);


void __RPC_STUB ITrnTimeMachineInternal_d_mode_sense_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_start_drive_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive,
    int start);


void __RPC_STUB ITrnTimeMachineInternal_start_drive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_read_block_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive,
    uquad blocknum,
    ubyte __RPC_FAR *buffer);


void __RPC_STUB ITrnTimeMachineInternal_read_block_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_write_block_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int drive,
    uquad blocknum,
    ubyte __RPC_FAR *buffer);


void __RPC_STUB ITrnTimeMachineInternal_write_block_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


TMS_ClipInfo __RPC_FAR *STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipAlloc_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int ClipType);


void __RPC_STUB ITrnTimeMachineInternal_ClipAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipFree_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo);


void __RPC_STUB ITrnTimeMachineInternal_ClipFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipFlush_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo);


void __RPC_STUB ITrnTimeMachineInternal_ClipFlush_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_PlayClip_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    tCHANNEL target,
    tTIME StartTime,
    TMS_PlayList __RPC_FAR *pList);


void __RPC_STUB ITrnTimeMachineInternal_PlayClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_RecordClip_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    tCHANNEL target,
    tTIME StartTime);


void __RPC_STUB ITrnTimeMachineInternal_RecordClip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_SetClipDrives_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    TMS_StripingInfo __RPC_FAR *sInfo);


void __RPC_STUB ITrnTimeMachineInternal_SetClipDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipDestroy_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo);


void __RPC_STUB ITrnTimeMachineInternal_ClipDestroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipCreate_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    unsigned char __RPC_FAR *ClipName);


void __RPC_STUB ITrnTimeMachineInternal_ClipCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipExists_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    unsigned char __RPC_FAR *ClipName);


void __RPC_STUB ITrnTimeMachineInternal_ClipExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipRename_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    unsigned char __RPC_FAR *newClipName);


void __RPC_STUB ITrnTimeMachineInternal_ClipRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipOpen_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    unsigned char __RPC_FAR *ClipName);


void __RPC_STUB ITrnTimeMachineInternal_ClipOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipClose_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo);


void __RPC_STUB ITrnTimeMachineInternal_ClipClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_GetClipInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *cInfo,
    int EntryMask,
    TMS_DirEntry __RPC_FAR *dEntry);


void __RPC_STUB ITrnTimeMachineInternal_GetClipInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


TMS_DriveInfo __RPC_FAR *STDMETHODCALLTYPE ITrnTimeMachineInternal_AllocDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    uquad nLBAs);


void __RPC_STUB ITrnTimeMachineInternal_AllocDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_FreeDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive);


void __RPC_STUB ITrnTimeMachineInternal_FreeDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_FlushDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive);


void __RPC_STUB ITrnTimeMachineInternal_FlushDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_FormatDriveInfo_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    uquad ID,
    unsigned char __RPC_FAR *DriveName);


void __RPC_STUB ITrnTimeMachineInternal_FormatDriveInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ListDirAlloc_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    uquad Directory,
    TMS_DirEntry __RPC_FAR *dEntry);


void __RPC_STUB ITrnTimeMachineInternal_ListDirAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ListDirFree_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    uquad ListDirAllocResult);


void __RPC_STUB ITrnTimeMachineInternal_ListDirFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ListDirEntry_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    uquad PreviousResult,
    TMS_DirEntry __RPC_FAR *dEntry);


void __RPC_STUB ITrnTimeMachineInternal_ListDirEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ListDirEntryType_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    ULONG Directory,
    ULONG TypeValue,
    ULONG TypeMask,
    TMS_DirEntry __RPC_FAR *dEntry);


void __RPC_STUB ITrnTimeMachineInternal_ListDirEntryType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_SetCurrentTime_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    tTIME Seconds,
    uquad Fraction);


void __RPC_STUB ITrnTimeMachineInternal_SetCurrentTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


void STDMETHODCALLTYPE ITrnTimeMachineInternal_GetCurrentTime_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    tTIME __RPC_FAR *pSeconds,
    tTIME __RPC_FAR *pFraction);


void __RPC_STUB ITrnTimeMachineInternal_GetCurrentTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_SetTDMInstanceID_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int TDMInstanceID);


void __RPC_STUB ITrnTimeMachineInternal_SetTDMInstanceID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_SetAudioChannelSlots_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int AudioSlot,
    int TDMSlot);


void __RPC_STUB ITrnTimeMachineInternal_SetAudioChannelSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


TMS_ClipIO __RPC_FAR *STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferAlloc_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int MaxBufferSize,
    int Flags);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferFree_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipIO __RPC_FAR *__MIDL_0008);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferWrite_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipIO __RPC_FAR *__MIDL_0009,
    TMS_ClipInfo __RPC_FAR *__MIDL_0010,
    int FieldNumber,
    int Position,
    int Size);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferRead_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipIO __RPC_FAR *__MIDL_0011,
    TMS_ClipInfo __RPC_FAR *__MIDL_0012,
    int FieldNumber,
    int Position,
    int Size);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_QueryFieldSize_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipInfo __RPC_FAR *__MIDL_0013,
    int Field);


void __RPC_STUB ITrnTimeMachineInternal_QueryFieldSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferStatus_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipIO __RPC_FAR *pClipIO,
    TMS_ClipBufferStatus __RPC_FAR *pCBS);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_ClipBufferAbort_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    TMS_ClipIO __RPC_FAR *pClipIO);


void __RPC_STUB ITrnTimeMachineInternal_ClipBufferAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_GetDriveStatus_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    ULONG flags,
    TMS_DriveStatus __RPC_FAR *pStatus);


void __RPC_STUB ITrnTimeMachineInternal_GetDriveStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


int STDMETHODCALLTYPE ITrnTimeMachineInternal_SetDriveLabel_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    int iDrive,
    TMS_DirEntry __RPC_FAR *dEntry);


void __RPC_STUB ITrnTimeMachineInternal_SetDriveLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITrnTimeMachineInternal_TransactMessage_Proxy( 
    ITrnTimeMachineInternal __RPC_FAR * This,
    DWORD commandId,
    unsigned int paramSize,
    void __RPC_FAR *pParamsBuff,
    unsigned int resultSize,
    void __RPC_FAR *pResultBuff);


void __RPC_STUB ITrnTimeMachineInternal_TransactMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITrnTimeMachineInternal_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
