#if !defined(__SWITCHER_SWCOMM_H)
#define __SWITCHER_SWCOMM_H
//
//      Trinity Switcher - Coordinator Commands and Data Structures
//
        #include "swtypes.h"

        swSTRUCTURE (swCommandBlock)
         swfLONG cb_Length         // Including this field
         swLONG cb_Command
         swLONG cb_DataLength
//         STRUCT cb_Data,0       // Optional Data (Always LongWord Size)
         swLABEL (cb_sizeof)

        swSTRUCTURE (swCommunicationsQueue)
         swfLONG cq_QueueStart
         swLONG cq_QueueEnd
         swLONG cq_KnownCommandOffset
         swLONG cq_LastCommandOffset
         swSTRUCT cq_Buffer[8192-16]
         swLABEL (cq_sizeof)

//
// DRAMBasePassArea resides at DRAM address 0 ($40000000 in 68E030 land)
//
        swSTRUCTURE (swDRAMBasePassArea)
         swfSTRUCT dbpa_Coordinator[8192] //sizeof swCommunicationsQueue]
         swSTRUCT dbpa_Switcher[8192] //sizeof swCommunicationsQueue]
         swLABEL (dbpa_sizeof)
//
//   Queue Communications concept
//
//       Coordinator initialization
//           cq_QueueStart is set to $10
//           cq_QueueEnd is set to $2000
//           cq_KnownCommandOffset and cq_LastCommandOffset
//           of both dbpa_Coordinator and dbpa_Switcher
//           are set to cq_QueueStart.
//
//           Switcher is then Booted.
//
//       After the Switcher is booted, the Coordinator is
//       allowed to write ONLY in its CommunicationsQueue
//       and Switcher is allowed to write ONLY to its
//       CommunicationsQueue.
//
//   Command Processing methodology
//
//       The protocol is symmetrical, thus both sides
//       can use the same access methods.  Only the
//       command requests and responses differ.
//
//   Protocol Explanation
//
//     Command Processing
//
//       do
//       {
//           while( my.cq_KnownCommandOffset != your.cq_LastCommandOffset )
//           {
//               CommandBlock *ThisCommand;
//               LONG NextCommandOffset;
//
//               NextCommandOffset = my.cq_KnownCommandOffset;
//               ThisCommand = ((void *)&your) + NextCommandOffset;
//               NextCommandOffset += ThisCommand->cb_Length;
//
//               if( ThisCommand.cb_Command == QUEUE_RESYNC )
//                   NextCommandOffset = your.cq_QueueStart;
//               else
//                   ProcessCommand(ThisCommand->cb_Command,     // The Command Processor
//                                  ThisCommand->cb_Data,
//                                  ThisCommand->cb_DataLength);
//
//               my.cq_KnownCommandOffset = NextCommandOffset;
//           }
//
//       } while( !Done );
//
//
//     Command Dispatch
//
//       DispatchAttempt(LONG Command, void *Data, LONG Length)
//       {
//           CommandBlock *NewCommand;
//           LONG KnownOffset,
//                CommandLength;
//
//           CommandLength = (Length+3)/4*4 + offsetof(CommandBlock,cb_Data);
//
//           NewCommand = ((void *)&my) + my.cq_LastCommandOffset;
//
//           KnownOffset = your.cq_KnownCommandOffset;
//           if( KnownOffset <= my.cq_LastCommandOffset )
//               KnownOffset += my.cq_QueueEnd - my.cq_QueueStart;
//
//           if( my.cq_LastCommandOffset+CommandLength >= KnownOffset )
//               return FALSE;   // Not Enough Room to dispatch
//
//           if( my.cq_LastCommandOffset+CommandLength
//               + offsetof(CommandBlock,cb_Data) >= my.cq_QueueEnd )
//           {
//               NewCommand->cb_Length = QUEUE_RESYNC_LEN;
//               NewCommand->cb_Command = QUEUE_RESYNC//
//               NewCommand->cb_DataLength = 0;
//               my.cq_LastCommandOffset = my.cq_QueueStart;
//               NewCommand = my.cq_Buffer;
//
//               if( my.cq_LastCommandOffset+CommandLength >= KnownOffset )
//                   return FALSE;
//           }
//
//           NewCommand->cb_Length = CommandLength;
//           NewCommand->cb_Command = Command;
//           NewCommand->cb_DataLength = Length;
//           "Long Copy"(NewCommand->cb_Data, Data, Length);
//
//           my.cq_LastCommandOffset += CommandLength;
//
//           return TRUE;
//       }
//
//

//LIBINIT MACRO ; <Initial Offset>
//      IFC '\1',''
//LIBOFFSET set   0
//      ENDC
//      IFNC '\1',''
//LIBOFFSET set   \1
//      ENDC
//        ENDM

#define LIBINIT(name) enum { lib ## name = -1

      swSTRUCTURE (sLibEntry)
       swfLONG  le_Address
       swLABEL (le_sizeof)

//LIBDEF  MACRO ; <FunctionName>
//\1      equ     LIBOFFSET
//LIBOFFSET set   LIBOFFSET+le_sizeof
//        ENDM

#define LIBDEF  ,
#define LIBEND  };

//
// Commands in common
//
        LIBINIT (COMMON)
        LIBDEF  QUEUE_RESYNC
        LIBDEF  COMMAND_UNKNOWN
        LIBDEF  COMMAND_ERROR
        LIBDEF  COMMAND_ECHO
        LIBEND

//
// Commands the Switcher executes from the Coordinator
//
        LIBINIT (SWITCHER)
        LIBDEF  SW_QUEUE_RESYNC
        LIBDEF  SW_COMMAND_UNKNOWN
        LIBDEF  SW_COMMAND_ERROR
        LIBDEF  SW_COMMAND_ECHO

        LIBDEF  SW_WriteBytes
        LIBDEF  SW_ReadBytes

        LIBDEF  SW_WriteWords
        LIBDEF  SW_ReadWords

        LIBDEF  SW_WriteLongs
        LIBDEF  SW_ReadLongs

        LIBDEF  SW_AtomicIO

        LIBDEF  SW_LoadKeyTable

        LIBDEF  SW_AllocChromaKeyTable
        LIBDEF  SW_FreeChromaKeyTable
        LIBDEF  SW_UseChromaKeyTable
        LIBDEF  SW_LoadChromaKeyTable

        LIBDEF  SW_AllocAnim
        LIBDEF  SW_FreeAnim
        LIBDEF  SW_LoadedAnim

        LIBDEF  SW_PlayAnimField
        LIBDEF  SW_StartAnim

        LIBDEF  SW_ResumeAnim

        LIBDEF  SW_StopAnim

        LIBDEF  SW_SelectKeyTable

        LIBDEF  SW_SetChromaKey

        LIBDEF  SW_SetMainAlpha
        LIBDEF  SW_SetGraphicsAlpha

        LIBDEF  SW_SetRecurseInfo

        LIBDEF  SW_SetPanEntry
        LIBDEF  SW_SetPanTable

        LIBDEF  SW_SetPlayList

        LIBDEF  SW_SetPreview

        LIBDEF  SW_AllocBump
        LIBDEF  SW_FreeBump
        LIBDEF  SW_LoadedBump
        LIBDEF  SW_ScrollBump
        LIBDEF  SW_DisplayBump

        LIBDEF  SW_DissolveAVideo

//-----
        LIBDEF  SW_LoadMainALUT
        LIBDEF  SW_UseMainALUT

        LIBDEF  SW_LoadMainCLUT
        LIBDEF  SW_UseMainCLUT

        LIBDEF  SW_LoadGraphicsALUT
        LIBDEF  SW_UseGraphicsALUT

        LIBDEF  SW_LoadGraphicsCLUT
        LIBDEF  SW_UseGraphicsCLUT

        LIBDEF  SW_SetPlayListPosition

        LIBDEF  SW_GetVersionName

        LIBDEF  SW_AllocRecursive
        LIBDEF  SW_FreeRecursive
        LIBDEF  SW_LoadedRecursive
        LIBDEF  SW_InstallRecursive

        LIBDEF  SW_PassThru

        LIBDEF  SW_SetMatteColor
        LIBDEF  SW_SetStrobe
        LIBDEF  SW_SetRunMode
        LIBDEF  SW_SetLumaThreshold

        LIBDEF  SW_AllocFrameStore
        LIBDEF  SW_FreeFrameStore
        LIBDEF  SW_GetFrameStore
        LIBDEF  SW_PutFrameStore
        LIBDEF  SW_ClearFrameMemory

        LIBDEF  SW_SetSimpleTransform

        LIBDEF  SW_SetALUNotify

        LIBDEF  SW_AllocPaint
        LIBDEF  SW_FreePaint
        LIBDEF  SW_UpdatePaint
        LIBDEF  SW_PositionPaint

        LIBDEF  SW_SetClock
        LIBDEF  SW_ReadClock

        LIBDEF  SW_SampleKeyColor

        LIBDEF  SW_NewView
        LIBDEF  SW_DeleteView
        LIBDEF  SW_ShowViews
        LIBDEF  SW_SetViewViewPorts

        LIBDEF  SW_NewViewPort
        LIBDEF  SW_DeleteViewPort
        LIBDEF  SW_GetViewPortData
        LIBDEF  SW_SetViewPortBitMap
        LIBDEF  SW_SetViewPortClipRect
        LIBDEF  SW_SetViewPortPlayList
        LIBDEF  SW_PlayViewPortPlayList
        LIBDEF  SW_StopViewPortPlayList
        LIBDEF  SW_PositionViewPortPlayList

        LIBDEF  SW_NewBitMap
        LIBDEF  SW_DeleteBitMap
        LIBDEF  SW_UpdateBitMap
        LIBDEF  SW_GetBitMapInfo

        LIBDEF  SW_SetViewPortData
        LIBDEF  SW_ResetViewManager

        LIBDEF  SW_AvailMem

        LIBDEF  DVE_TERMINATOR
        LIBEND


        swSTRUCTURE (sSW_WriteBytes)
         swfAPTR  swb_Address
         swWORD  swb_pad1
         swWORD  swb_NumBytes
         swLABEL (swb_sizeof)
//;
//;       Array of long words with byte to write in bits 7-0
//;
//;         BYTE  swb_pad2
//;         BYTE  swb_pad3
//;         BYTE  swb_pad4
//;         BYTE  swb_Value

        swSTRUCTURE (sSW_ReadBytes)
         swfAPTR   srb_Address
         swWORD   srb_pad
         swWORD   srb_NumBytes
         swLABEL  (srb_sizeof)

        swSTRUCTURE (sSW_WriteWords)
         swfAPTR  sww_Address
         swWORD  sww_pad1
         swWORD  sww_NumWords
         swLABEL (sww_sizeof)
//;
//;       Array of long words with word to write in bits 15-0
//;
//;         WORD  sww_pad2
//;         WORD  sww_Value

        swSTRUCTURE (sSW_ReadWords)
         swfAPTR   srw_Address
         swWORD   srw_pad
         swWORD   srw_NumWords
         swLABEL  (srw_sizeof)

        swSTRUCTURE (sSW_WriteLongs)
         swfAPTR  swl_Address
         swWORD  swl_pad1
         swWORD  swl_NumLongs
         swLABEL (swl_sizeof)
//;
//;       Array of long words
//;
//;         LONG  swl_Value

        swSTRUCTURE (sSW_ReadLongs)
         swfAPTR   srl_Address
         swWORD   srl_pad
         swWORD   srl_NumLongs
         swLABEL  (srl_sizeof)

        swSTRUCTURE (sSW_AtomicIO)
         swfWORD   sai_pad
         swWORD   sai_NumIOs
         swLABEL  (sai_sizeof)
//;
//;       Array of long IO descriptions
//;
#define ATOM_Write_B    0

#define ATOM_ReadByte   0
#define ATOM_WriteByte  1
#define ATOM_ReadWord   2
#define ATOM_WriteWord  3
#define ATOM_ReadLong   4
#define ATOM_WriteLong  5

//         LONG   sai_Opcode
//         LONG   sai_Address
//         LONG   sai_Value               ; value to Write/ignored for Read


        swSTRUCTURE (sSW_LoadKeyTable)
         swfBYTE slkt_KeyTableIndex
         swBYTE slkt_AKeyEnable
         swBYTE slkt_BKeyEnable
         swBYTE slkt_KeyTable[9]
         swSTRUCT slkt_pad[1]
         swLABEL (slkt_sizeof)

        swSTRUCTURE (sSW_AllocChromaKeyTable)
         swfBYTE sackt_pad[3]
         swBYTE sackt_Index
         swLABEL (sackt_sizeof)

        swSTRUCTURE (sSW_FreeChromaKeyTable)
         swfBYTE sfckt_pad[3]
         swBYTE sfckt_Index
         swLABEL (sfckt_sizeof)

        swSTRUCTURE (sSW_UseChromaKeyTable)
         swfBYTE suckt_pad[3]
         swBYTE suckt_Index
         swLABEL (suckt_sizeof)

        swSTRUCTURE (sSW_LoadChromaKeyTable)
         swfBYTE slckt_pad[3]
         swBYTE slckt_Index
         swLABEL (slckt_sizeof)

        swSTRUCTURE (sSW_AllocAnim)
         swfWORD saa_pad
         swWORD saa_Index
         swLONG saa_Length
         swLABEL (saa_sizeof)

        swSTRUCTURE (sSW_FreeAnim)
         swfWORD sfa_pad
         swWORD sfa_Index
         swLABEL (sfa_sizeof)

        swSTRUCTURE (sSW_LoadedAnim)
         swfWORD sla_pad
         swWORD sla_Index
         swLABEL (sla_sizeof)

        swSTRUCTURE (sSW_PlayAnimField)
         swfWORD spaf_pad1
         swWORD spaf_Index
         swWORD spaf_pad2
         swWORD spaf_Field
         swLABEL (spaf_sizeof)

        swSTRUCTURE (sSW_StartAnim)
         swfWORD ssta_pad
         swWORD ssta_Index
         swLABEL (ssta_sizeof)

        swSTRUCTURE (sSW_ResumeAnim)
         swfWORD sra_pad
         swWORD sra_Index
         swLABEL (sra_sizeof)

        swSTRUCTURE (sSW_StopAnim)
         swfWORD sspa_pad
         swWORD sspa_Index
         swLABEL (sspa_sizeof)

        swSTRUCTURE (sSW_SelectKeyTable)
         swfBYTE sskt_pad[3]
         swBYTE sskt_KeyTableIndex
         swLABEL (ssky_sizeof)

        swSTRUCTURE (sSW_SetChromaKey)
         swfBYTE ssck_pad[3]
         swBYTE ssck_KeySource    // (0=A, 1=B)
         swBYTE ssck_pad2[3]
         swBYTE ssck_KeyType      // (%00=Y (A8-15=0), %01=Y A/B, %10=U/V, %11=6-5-5 YUV)
         swBYTE ssck_pad3
         swBYTE ssck_KeyColor[3]
         swLABEL (ssck_sizeof)

        swSTRUCTURE (sSW_SetMainAlpha)
         swfBYTE ssma_pad[3]
         swBYTE ssma_AlphaValue
         swLABEL (ssma_sizeof)

        swSTRUCTURE (sSW_SetGraphicsAlpha)
         swfBYTE ssga_pad[3]
         swBYTE ssga_AlphaValue
         swLABEL (ssga_sizeof)

//        swSTRUCTURE (sSW_SetRecurseInfo)
//         swLABEL ssri_sizeof

        swSTRUCTURE (sSW_SetPanEntry)
         swfWORD sspe_AnimIndex
         swWORD sspe_PanIndex
         swLONG sspe_PanOffset
         swLABEL (sspe_sizeof)

        swSTRUCTURE (sSW_SetPanTable)
         swfWORD sspt_AnimIndex
         swWORD sspt_FirstPanIndex
         swWORD sspt_LastPanIndex
         swWORD sspt_pad
//         swSTRUCT sspt_PanOffset,0  ; Array of PanOffsets
         swLABEL (sspt_sizeof)

        swSTRUCTURE (sSW_SetPlayList)
         swfWORD sspl_pad1
         swWORD sspl_Index
         swWORD sspl_pad2
         swWORD sspl_PlayListCount

//         LABEL sspl_PlayList
         swWORD sspl_pad3         // repeated sspl_PlayListCount times
         swWORD sspl_LoopCount    // Limited to 8 entries
         swWORD sspl_pad4         // (Table can only hold 8 entries)
         swWORD sspl_FirstField
         swWORD sspl_pad5
         swWORD sspl_LastField

         swLABEL (spl_sizeof)

#define SET_PREVIEW_A       0
#define SET_PREVIEW_B       1
#define SET_PREVIEW_AB      2
#define SET_PREVIEW_CG      3
#define SET_PREVIEW_PROGRAM 4

        swSTRUCTURE (sSW_SetPreview)
         swfWORD ssp_pad
         swWORD ssp_PreviewSource
         swLABEL (ssp_sizeof)

        swSTRUCTURE (sSW_AllocBump)
         swfWORD sab_pad
         swWORD sab_Index
         swLONG sab_Length
         swLABEL (sab_sizeof)

        swSTRUCTURE (sSW_FreeBump)
         swfWORD sfb_pad
         swWORD sfb_Index
         swLABEL (sfb_sizeof)

        swSTRUCTURE (sSW_LoadedBump)
         swfWORD slb_pad1
         swWORD slb_Index
         swWORD slb_pad2
         swWORD slb_FIFOEnable
         swLABEL (slb_sizeof)

        swSTRUCTURE (sSW_ScrollBump)
         swfWORD ssb_pad1
         swWORD ssb_Index
         swWORD ssb_pad2
         swWORD ssb_RyOffset
         swWORD ssb_pad3
         swWORD ssb_RxOffset
         swWORD ssb_pad4
         swWORD ssb_DyOffset
         swWORD ssb_pad5
         swWORD ssb_DxOffset
         swLABEL (ssb_sizeof)


        swSTRUCTURE (sSW_DisplayBump)
         swfWORD sdb_pad1
         swWORD sdb_Index
         swSTRUCT sdb_pad2[3]
         swBYTE sdb_ShowBump
         swLABEL (sdb_sizeof)

        swSTRUCTURE (sSW_DissolveAVideo)
         swfWORD sdav_pad1
         swWORD sdav_Alpha                //; $0 (all video) - $100 (solid color)
         swBYTE sdav_pad2
         swBYTE sdav_CRMY                 //; (-112 to 112)
         swBYTE sdav_Y                    //; (  16 to 235)
         swBYTE sdav_CBMY                 //; (-112 to 112)
         swLABEL (sdav_sizeof)
//;
//;-----
        swSTRUCTURE (sSW_LoadMainALUT)
         swfBYTE slma_MainALUT[256]
         swLABEL (slma_sizeof)
        swSTRUCTURE (sSW_UseMainALUT)
         swfBYTE suma_pad[3]
         swBYTE suma_UseMainALUT
         swLABEL (suma_sizeof)

        swSTRUCTURE (sSW_LoadMainCLUT)
         swfBYTE slmc_MainCLUT[3*256]
         swLABEL (slmc_sizeof)
        swSTRUCTURE (sSW_UseMainCLUT)
         swfBYTE sumc_pad[3]
         swBYTE sumc_UseMainCLUT
         swLABEL (sumc_sizeof)

        swSTRUCTURE (sSW_LoadGraphicsALUT)
         swfBYTE slga_GraphicsALUT[256]
         swLABEL (slga_sizeof)
        swSTRUCTURE (sSW_UseGraphicsALUT)
         swfBYTE suga_pad[3]
         swBYTE suga_UseGraphicsALUT
         swLABEL (suga_sizeof)

        swSTRUCTURE (sSW_LoadGraphicsCLUT)
         swfBYTE slgc_GraphicsCLUT[3*256]
         swLABEL (slgc_sizeof)
        swSTRUCTURE (sSW_UseGraphicsCLUT)
         swfBYTE sugc_pad[3]
         swBYTE sugc_UseGraphicsCLUT
         swLABEL (sugc_sizeof)

//;
//; Commands the Coordinator executes from the Switcher
//;
        LIBINIT (COORDINATOR)
        LIBDEF  CO_QUEUE_RESYNC
        LIBDEF  CO_COMMAND_UNKNOWN
        LIBDEF  CO_COMMAND_ERROR
        LIBDEF  CO_COMMAND_ECHO

        LIBDEF  CO_BytesContents
        LIBDEF  CO_WordsContents
        LIBDEF  CO_LongsContents

        LIBDEF  CO_AtomicContents

        LIBDEF  CO_LoadAnim
        LIBDEF  CO_LoadChromaKeyTable
        LIBDEF  CO_LoadBump

        LIBDEF  CO_AnimEnded

        LIBDEF  CO_VersionName

        LIBDEF  CO_RequestStructure

        LIBDEF  CO_LoadRecursive

        LIBDEF  CO_LoadFrameStore

        LIBDEF  CO_GetFrameStoreEnd
        LIBDEF  CO_PutFrameStoreEnd
        LIBDEF  CO_ClearFrameMemoryEnd

        LIBDEF  CO_ALUTooLong

        LIBDEF  CO_LoadPaint

        LIBDEF  CO_ReadClock
        LIBDEF  CO_View
        LIBDEF  CO_ViewPort
        LIBDEF  CO_ViewPortData
        LIBDEF  CO_BitMap
        LIBDEF  CO_BitMapInfo

        LIBEND


        swSTRUCTURE (sCO_BytesContents)
         swfAPTR  cbc_Address
         swLABEL (cbc_sizeof)
//;
//;       Array of long words with bytes read in bits 7-0
//;
//         BYTE  cbc_pad1
//         BYTE  cbc_pad2
//         BYTE  cbc_pad3
//         BYTE  cbc_Value

        swSTRUCTURE (sCO_WordsContents)
         swfAPTR  cwc_Address
         swLABEL (cwc_sizeof)
//;
//;       Array of long words with words read in bits 15-0
//;
//         WORD  cwc_pad
//         WORD  cwc_Value

        swSTRUCTURE (sCO_LongsContents)
         swfAPTR  clc_Address
         swLABEL (clc_sizeof)
//;
//;       Array of long words read in bits 31-0
//;
//         LONG  clc_Value

        swSTRUCTURE (sCO_AtomicContents)
         swfWORD  cac_pad
         swWORD  cac_BadOpcode            // 0 success, otherwise index of bad opcode
         swLABEL (cac_sizeof)

/*
;
; for read operations
;
;       Byte Read
;         APTR   cac_Address
;         BYTE   cac_bytepad1
;         BYTE   cac_bytepad2
;         BYTE   cac_bytepad3
;         BYTE   cac_ByteValue
;
;       Word Read
;         APTR   cac_Address
;         WORD   cac_wordpad
;         WORD   cac_WordValue
;
;       Long Read
;         APTR   cac_Address
;         LONG   cac_LongValue
;
*/
        swSTRUCTURE (sCO_LoadAnim)
         swfWORD cla_pad
         swWORD cla_Index
         swLONG cla_Address               // 0 means not enough memory
         swLABEL (cla_sizeof)

        swSTRUCTURE (sCO_LoadChromaKeyTable)
         swfWORD clckt_pad
         swWORD clckt_Index
         swLONG clckt_Address
         swLABEL (clckt_sizeof)

        swSTRUCTURE (sCO_LoadBump)
         swfWORD clb_pad
         swWORD clb_Index
         swAPTR clb_Address
         swLABEL (clb_sizeof)

        swSTRUCTURE (sCO_AnimEnded)
         swfWORD cae_pad
         swWORD cae_Index
         swLABEL (cae_sizeof)

#endif // __SWITCHER_SWCOMM_H

