#ifndef _ACG_OPTS_H
#define _ACG_OPTS_H

//HARDWARE CODES --------------------------------------------------
#define HARDWARE_TYPE_MASK (0x00ff<<8)

#define FAST_VM_HARDWARE		(0x1<<8)
#define FAST_BLUE_HARDWARE		(0x2<<8)
#define PINNACLE_HARDWARE		(0x3<<8)
#define PERMEDIA2_HARDWARE		(0x4<<8)
#define PIXELOCK_HARDWARE		(0x5<<8)
#define PLAY_HARDWARE			(0x6<<8)
#define STAND_ALONE_HARDWARE	(0x7<<8)
#define PREMIERE_HARDWARE		(0x8<<8)
#define SPEED_RAZOR_HARDWARE	(0x9<<8)
#define DPS_VIDEO_ACTION_HARDWARE (0xA<<8)
#define DPS_FUSION_HARDWARE		(0xB<<8)
#define CANOPUS_HARDWARE		(0xC<<8)
#define TOASTER_NT_HARDWARE		(0xD<<8)
#define SCREEN_PLAY_HARDWARE	(0xE<<8)

//*****************************************************************
//*****************************************************************
//SOFTWARE CODES (with built in hardware code) ----------------------
#define VIDEO_MACHINE_VERSION    (0x10 | FAST_VM_HARDWARE)
#define BLUE_VERSION			 (0x20 | FAST_BLUE_HARDWARE)
#define ES3_VERSION				 (0x30 | FAST_BLUE_HARDWARE)
#define FAST_601_VERSION		 (0x40 | FAST_BLUE_HARDWARE)
#define GENIE_VERSION			 (0x50 | PINNACLE_HARDWARE)
#define PIXELOCK_2000_VERSION	 (0x61 | PERMEDIA2_HARDWARE)
#define TITLE_MACHINE_VERSION	 (0x68 | PERMEDIA2_HARDWARE)
#define TITLEWAVE_VERSION		 (0x70 | PLAY_HARDWARE)
#define TITLEWAVE_LT_VERSION	 (0x78 | PLAY_HARDWARE)
#define STAND_ALONE_VERSION		 (0x80 | STAND_ALONE_HARDWARE)
#define PREMIERE_VERSION		 (0x90 | PREMIERE_HARDWARE)
#define SPEED_RAZOR_VERSION		 (0x92 | SPEED_RAZOR_HARDWARE)
#define DPS_VIDEO_ACTION_VERSION (0xA0 | DPS_VIDEO_ACTION_HARDWARE)
#define DPS_FUSION_VERSION		 (0xA1 | DPS_FUSION_HARDWARE)
#define TOASTER_AURA_VERSION     (0x00 | TOASTER_NT_HARDWARE)
#define TOASTER_DIRECT_VERSION   (0x10 | TOASTER_NT_HARDWARE)
#define CANOPUS_VERSION			 (0x01 | CANOPUS_HARDWARE)
#define SCREEN_PLAY_VERSION		 (0x01 | SCREEN_PLAY_HARDWARE)

//*****************************************************************
//*****************************************************************
#define SOFTWARE_VERSION ES3_VERSION
//VERSION SWITCH IS HERE ^^^^^^^^^^^^^^^^^^^^

#define PROGRAM_VERSION_NUMBER "1.94"
#define APP_TITLE "Alpha CG"
#define _ENABLE_DONGLE_CHECK 0
#define LITE_VERSION 0

#if _DEBUG
	#undef _ENABLE_DONGLE_CHECK
	#define _ENABLE_DONGLE_CHECK 0
#endif//_DEBUG

#endif//_ACG_OPTS_H
