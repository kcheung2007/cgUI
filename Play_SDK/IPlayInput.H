// ------------------------------------------------------------------------ //
// IPlayInput.H
// Interface file for Play Input devices
//
// Copyright @ 1999 Play Inc.
// Play Confidential
//
// Created on Aug 23, 1999 by Heman Gala
// ------------------------------------------------------------------------ //

// ------------------------------------------------------------------------ //
#ifndef __IPlayInput_H__
#define __IPlayInput_H__
// ------------------------------------------------------------------------ //

#include <PlayInc.H>

// --- Result codes ------------------------------------------------------- //

enum PLAYINPUTRESULT
{
	S_PLAYINPUT_OK					= S_OK,

	E_PLAYINPUT_FAIL				= E_FAIL,

	E_PLAYINPUT_NOINTERFACE			= E_NOINTERFACE,
	E_PLAYINPUT_OUTOFMEMORY			= E_OUTOFMEMORY,
	E_PLAYINPUT_INVALIDARGS			= E_INVALIDARG,

	E_PLAYINPUT_INVALIDARG_1,
	E_PLAYINPUT_INVALIDARG_2,
	E_PLAYINPUT_INVALIDARG_3,

	E_PLAYINPUT_NOTACQUIRED,			
	E_PLAYINPUT_ALREADYCAPTURED,
	E_PLAYINPUT_ALREADYACQUIRED,
	E_PLAYINPUT_NOTCAPTURED,
	E_PLAYINPUT_RELEASEFAIL,
	E_PLAYINPUT_BUFFERTOOSMALL,
	E_PLAYINPUT_LOOKUPFAILED,
	E_PLAYINPUT_NONASCIIKEY,
};

// --- IPlayKeyboardxxx data-types ---------------------------------------- //

enum PLAYKEYCODE
{
	// Printable ASCII Keys (with direct mapping to non-shifted state)

	PLAY_KEY_SPACE						= 0x20,		// ' ', ASCII  32 (0x20)
										
	PLAY_KEY_0							= 0x30,		// '0', ASCII  48 (0x30) (Shifted ')', ASCII  41 (0x29))
	PLAY_KEY_1							= 0x31,		// '1', ASCII  49 (0x31) (Shifted '!', ASCII  33 (0x21))
	PLAY_KEY_2							= 0x32,		// '2', ASCII  50 (0x32) (Shifted '@', ASCII  64 (0x40))
	PLAY_KEY_3							= 0x33,		// '3', ASCII  51 (0x33) (Shifted '#', ASCII  35 (0x23))
	PLAY_KEY_4							= 0x34,		// '4', ASCII  52 (0x34) (Shifted '$', ASCII  36 (0x24))
	PLAY_KEY_5							= 0x35,		// '5', ASCII  53 (0x35) (Shifted '%', ASCII  37 (0x25))
	PLAY_KEY_6							= 0x36,		// '6', ASCII  54 (0x36) (Shifted '^', ASCII  94 (0x5E))
	PLAY_KEY_7							= 0x37,		// '7', ASCII  55 (0x37) (Shifted '&', ASCII  38 (0x26))
	PLAY_KEY_8							= 0x38,		// '8', ASCII  56 (0x38) (Shifted '*', ASCII  42 (0x2A))
	PLAY_KEY_9							= 0x39,		// '9', ASCII  57 (0x39) (Shifted '(', ASCII  40 (0x28))
										
	PLAY_KEY_A							= 0x41,		// 'A', ASCII  65 (0x41) (Shifted 'A', ASCII  97 (0x61))
	PLAY_KEY_B							= 0x42,		// 'B', ASCII  66 (0x42) (Shifted 'B', ASCII  98 (0x62))
	PLAY_KEY_C							= 0x43,		// 'C', ASCII  67 (0x43) (Shifted 'C', ASCII  99 (0x63))
	PLAY_KEY_D							= 0x44,		// 'D', ASCII  68 (0x44) (Shifted 'D', ASCII 100 (0x64))
	PLAY_KEY_E							= 0x45,		// 'E', ASCII  69 (0x45) (Shifted 'E', ASCII 101 (0x65))
	PLAY_KEY_F							= 0x46,		// 'F', ASCII  70 (0x46) (Shifted 'F', ASCII 102 (0x66))
	PLAY_KEY_G							= 0x47,		// 'G', ASCII  71 (0x47) (Shifted 'G', ASCII 103 (0x67))
	PLAY_KEY_H							= 0x48,		// 'H', ASCII  72 (0x48) (Shifted 'H', ASCII 104 (0x68))
	PLAY_KEY_I							= 0x49,		// 'I', ASCII  73 (0x49) (Shifted 'I', ASCII 105 (0x69))
	PLAY_KEY_J							= 0x4A,		// 'J', ASCII  74 (0x4A) (Shifted 'J', ASCII 106 (0x6A))
	PLAY_KEY_K							= 0x4B,		// 'K', ASCII  75 (0x4B) (Shifted 'K', ASCII 107 (0x6B))
	PLAY_KEY_L							= 0x4C,		// 'L', ASCII  76 (0x4C) (Shifted 'L', ASCII 108 (0x6C))
	PLAY_KEY_M							= 0x4D,		// 'M', ASCII  77 (0x4D) (Shifted 'M', ASCII 109 (0x6D))
	PLAY_KEY_N							= 0x4E,		// 'N', ASCII  78 (0x4E) (Shifted 'N', ASCII 110 (0x6E))
	PLAY_KEY_O							= 0x4F,		// 'O', ASCII  79 (0x4F) (Shifted 'O', ASCII 111 (0x6F))
	PLAY_KEY_P							= 0x50,		// 'P', ASCII  80 (0x50) (Shifted 'P', ASCII 112 (0x70))
	PLAY_KEY_Q							= 0x51,		// 'Q', ASCII  81 (0x51) (Shifted 'Q', ASCII 113 (0x71))
	PLAY_KEY_R							= 0x52,		// 'R', ASCII  82 (0x52) (Shifted 'R', ASCII 114 (0x72))
	PLAY_KEY_S							= 0x53,		// 'S', ASCII  83 (0x53) (Shifted 'S', ASCII 115 (0x73))
	PLAY_KEY_T							= 0x54,		// 'T', ASCII  84 (0x54) (Shifted 'T', ASCII 116 (0x74))
	PLAY_KEY_U							= 0x55,		// 'U', ASCII  85 (0x55) (Shifted 'U', ASCII 117 (0x75))
	PLAY_KEY_V							= 0x56,		// 'V', ASCII  86 (0x56) (Shifted 'V', ASCII 118 (0x76))
	PLAY_KEY_W							= 0x57,		// 'W', ASCII  87 (0x57) (Shifted 'w', ASCII 119 (0x77))
	PLAY_KEY_X							= 0x58,		// 'X', ASCII  88 (0x58) (Shifted 'X', ASCII 120 (0x78))
	PLAY_KEY_Y							= 0x59,		// 'Y', ASCII  89 (0x59) (Shifted 'Y', ASCII 121 (0x79))
	PLAY_KEY_Z							= 0x5A,		// 'Z', ASCII  90 (0x5A) (Shifted 'Z', ASCII 122 (0x7A))
										
	PLAY_KEY_COMMA						= 0x2C,		// ',', ASCII  44 (0x2C) (Shifted '<', ASCII  60 (0x3C))
	PLAY_KEY_HYPHEN						= 0x2D,		// '-', ASCII  45 (0x2D) (Shifted '_', ASCII  95 (0x5F))
	PLAY_KEY_PERIOD						= 0x2E,		// '.', ASCII  46 (0x2E) (Shifted '>', ASCII  62 (0x3E))
	PLAY_KEY_EQUALS						= 0x3D,		// '=', ASCII  61 (0x3D) (Shifted '+', ASCII  43 (0x2B))
	PLAY_KEY_LEFTSQUAREBRACKET			= 0x5B,		// '[', ASCII  91 (0x5B) (Shifted '{', ASCII 123 (0x7B))
	PLAY_KEY_RIGHTSQUAREBRACKET			= 0x5D,		// ']', ASCII  93 (0x5D) (Shifted '}', ASCII 125 (0x7D))
	PLAY_KEY_SEMICOLON					= 0x3B,		// ';', ASCII  59 (0x3B) (Shifted ':', ASCII  58 (0x3A))
	PLAY_KEY_QUOTE						= 0x27,		// ''', ASCII  39 (0x27) (Shifted '"', ASCII  34 (0x22))
	PLAY_KEY_GRAVEACCENT				= 0x60,		// '`', ASCII  96 (0x60) (Shifted '~', ASCII 126 (0x7E))
	PLAY_KEY_BACKSLASH					= 0x5C,		// '\', ASCII  92 (0x5C) (Shifted '|', ASCII 124 (0x7C))
	PLAY_KEY_SLASH						= 0x2F,		// '/', ASCII  47 (0x2F) (Shifted '?', ASCII  63 (0x3F))
										
										
	// Non-Printable ASCII keys			
	// Non-ASCII keys (> 127 (0x7F))	
										
	// Arrow keys						
	PLAY_KEY_UP							= 0x80,
	PLAY_KEY_LEFT						= 0x81,
	PLAY_KEY_RIGHT						= 0x82,
	PLAY_KEY_DOWN						= 0x83,
										
	// Edit keys						
	PLAY_KEY_INSERT						= 0x84,
	PLAY_KEY_DELETE						= 0x85,
	PLAY_KEY_HOME						= 0x86,
	PLAY_KEY_END						= 0x87,
	PLAY_KEY_PAGEUP						= 0x88,
	PLAY_KEY_PAGEDOWN					= 0x89,
										
	// Numpad keys						
	PLAY_KEY_NUMPAD0					= 0x90,	
	PLAY_KEY_NUMPAD1					= 0x91,	
	PLAY_KEY_NUMPAD2					= 0x92,	
	PLAY_KEY_NUMPAD3					= 0x93,	
	PLAY_KEY_NUMPAD4					= 0x94,	
	PLAY_KEY_NUMPAD5					= 0x95,	
	PLAY_KEY_NUMPAD6					= 0x96,	
	PLAY_KEY_NUMPAD7					= 0x97,	
	PLAY_KEY_NUMPAD8					= 0x98,	
	PLAY_KEY_NUMPAD9					= 0x99,	
										
	PLAY_KEY_NUMPADCOMMA				= 0x9A,
										
	// Arithmetic keys					
	PLAY_KEY_NUMPADDIVIDE				= 0x9B,
	PLAY_KEY_NUMPADMULTIPLY				= 0x9C,
	PLAY_KEY_NUMPADSUBTRACT				= 0x9D,
	PLAY_KEY_NUMPADADD					= 0x9E,
	PLAY_KEY_NUMPADDECIMAL				= 0x9F,
	
	PLAY_KEY_NUMPADENTER				= 0xA0,
										
	// Modifiers						
	PLAY_KEY_LEFTSHIFT					= 0xA1,
	PLAY_KEY_RIGHTSHIFT					= 0xA2,
	PLAY_KEY_LEFTCONTROL				= 0xA3,
	PLAY_KEY_RIGHTCONTROL				= 0xA4,
	PLAY_KEY_LEFTALT					= 0xA5,
	PLAY_KEY_RIGHTALT					= 0xA6,
										
	PLAY_KEY_ESCAPE						= 0xA7,
										
	// Function keys					
	PLAY_KEY_F1							= 0xB0,
	PLAY_KEY_F2							= 0xB1,
	PLAY_KEY_F3							= 0xB2,
	PLAY_KEY_F4							= 0xB3,
	PLAY_KEY_F5							= 0xB4,
	PLAY_KEY_F6							= 0xB5,
	PLAY_KEY_F7							= 0xB6,
	PLAY_KEY_F8							= 0xB7,
	PLAY_KEY_F9							= 0xB8,
	PLAY_KEY_F10						= 0xB9,
	PLAY_KEY_F11						= 0xBA,
	PLAY_KEY_F12						= 0xBB,
	PLAY_KEY_F13						= 0xBC,
	PLAY_KEY_F14						= 0xBD,
	PLAY_KEY_F15						= 0xBE,
										
	// Other keys						
	PLAY_KEY_SYSRQ						= 0xC0,
	PLAY_KEY_PAUSE						= 0xC1,
										
	PLAY_KEY_TAB						= 0xC2,
	PLAY_KEY_BACKSPACE					= 0xC3,
	PLAY_KEY_ENTER						= 0xC4,
										
	// Lock keys						
	PLAY_KEY_CAPSLOCK					= 0xD0,
	PLAY_KEY_SCROLLLOCK					= 0xD1,
	PLAY_KEY_NUMLOCK					= 0xD2,
										
	// Windows extensions				
	PLAY_KEY_LEFTWINDOW					= 0xE0,
	PLAY_KEY_RIGHTWINDOW				= 0xE1,
	PLAY_KEY_APPLICATION				= 0xE2,
										
	// Unknown							
	PLAY_KEY_UNDEFINED					= 0xFF,


	// --- Alternate key mappings --------------------------------------------
	PLAY_KEY_MINUS2						= PLAY_KEY_HYPHEN,
	PLAY_KEY_PRINTSCRN					= PLAY_KEY_SYSRQ,
										
	PLAY_LEY_LMENU						= PLAY_KEY_LEFTALT,
	PLAY_KEY_RMENU						= PLAY_KEY_RIGHTALT,
										
	PLAY_KEY_NUMPADSTAR					= PLAY_KEY_NUMPADMULTIPLY,
	PLAY_KEY_NUMPADMINUS				= PLAY_KEY_NUMPADSUBTRACT,
	PLAY_KEY_NUMPADPLUS					= PLAY_KEY_NUMPADADD,
	PLAY_KEY_NUMPADPERIOD				= PLAY_KEY_NUMPADDECIMAL,
	PLAY_KEY_NUMPADSLASH				= PLAY_KEY_NUMPADDIVIDE,
										
	PLAY_KEY_PRIOR						= PLAY_KEY_PAGEUP,
	PLAY_KEY_NEXT						= PLAY_KEY_PAGEDOWN,
										
	PLAY_KEY_UPARROW					= PLAY_KEY_UP,
	PLAY_KEY_LEFTARROW					= PLAY_KEY_LEFT,
	PLAY_KEY_RIGHTARROW					= PLAY_KEY_RIGHT,
	PLAY_KEY_DOWNARROW					= PLAY_KEY_DOWN,
										
	PLAY_KEY_SUBTRACT					= PLAY_KEY_HYPHEN,
};

enum PLAYASCIIKEYCODE
{
	PLAY_ASCIIKEY_SPACE					= 0x20,		// ' ', ASCII  32 (0x20) 
	PLAY_ASCIIKEY_EXCLAMATION			= 0x21,		// '!', ASCII  33 (0x21) Shifted
	PLAY_ASCIIKEY_DOUBLEQUOTE			= 0x22,		// '"', ASCII  34 (0x22) Shifted
	PLAY_ASCIIKEY_HASH					= 0x23,		// '#', ASCII  35 (0x23) Shifted
	PLAY_ASCIIKEY_DOLLAR				= 0x24,		// '$', ASCII  36 (0x24) Shifted
	PLAY_ASCIIKEY_PERCENT				= 0x25,		// '%', ASCII  37 (0x25) Shifted
	PLAY_ASCIIKEY_AMPERSAND				= 0x26,		// '&', ASCII  38 (0x26) Shifted
	PLAY_ASCIIKEY_QUOTE					= 0x27,		// ''', ASCII  39 (0x27) Non-shifted
	PLAY_ASCIIKEY_LEFTPARENTHESIS		= 0x28,		// '(', ASCII  40 (0x28) Shifted
	PLAY_ASCIIKEY_RIGHTPARENTHESIS		= 0x29,		// ')', ASCII  41 (0x29) Shifted
	PLAY_ASCIIKEY_ASTERIK				= 0x2A,		// '*', ASCII  42 (0x2A) Shifted
	PLAY_ASCIIKEY_PLUS					= 0x2B,		// '+', ASCII  43 (0x2B) Shifted
	PLAY_ASCIIKEY_COMMA					= 0x2C,		// ',', ASCII  44 (0x2C) Non-shifted
	PLAY_ASCIIKEY_HYPHEN				= 0x2D,		// '-', ASCII  45 (0x2D) Non-shifted
	PLAY_ASCIIKEY_PERIOD				= 0x2E,		// '.', ASCII  46 (0x2E) Non-shifted
	PLAY_ASCIIKEY_SLASH					= 0x2F,		// '/', ASCII  47 (0x2F) Non-shifted
	PLAY_ASCIIKEY_0						= 0x30,		// '0', ASCII  48 (0x30) Non-shifted
	PLAY_ASCIIKEY_1						= 0x31,		// '1', ASCII  49 (0x31) Non-shifted
	PLAY_ASCIIKEY_2						= 0x32,		// '2', ASCII  50 (0x32) Non-shifted
	PLAY_ASCIIKEY_3						= 0x33,		// '3', ASCII  51 (0x33) Non-shifted
	PLAY_ASCIIKEY_4						= 0x34,		// '4', ASCII  52 (0x34) Non-shifted
	PLAY_ASCIIKEY_5						= 0x35,		// '5', ASCII  53 (0x35) Non-shifted
	PLAY_ASCIIKEY_6						= 0x36,		// '6', ASCII  54 (0x36) Non-shifted
	PLAY_ASCIIKEY_7						= 0x37,		// '7', ASCII  55 (0x37) Non-shifted
	PLAY_ASCIIKEY_8						= 0x38,		// '8', ASCII  56 (0x38) Non-shifted
	PLAY_ASCIIKEY_9						= 0x39,		// '9', ASCII  57 (0x39) Non-shifted
	PLAY_ASCIIKEY_COLON					= 0x3A,		// ':', ASCII  58 (0x3A) Shifted
	PLAY_ASCIIKEY_SEMICOLON				= 0x3B,		// ';', ASCII  59 (0x3B) Non-shifted
	PLAY_ASCIIKEY_LEFTANGULARBRACKET	= 0x3C,		// '<', ASCII  60 (0x3C) Shifted
	PLAY_ASCIIKEY_EQUALS				= 0x3D,		// '=', ASCII  61 (0x3D) Non-shifted
	PLAY_ASCIIKEY_RIGHTANGULARBRACKET	= 0x3E,		// '>', ASCII  62 (0x3E) Shifted
	PLAY_ASCIIKEY_QUESTION				= 0x3F,		// '?', ASCII  63 (0x3F) Shifted
	PLAY_ASCIIKEY_AT					= 0x40,		// '@', ASCII  64 (0x40) Shifted
	PLAY_ASCIIKEY_LOWER_A				= 0x41,		// 'A', ASCII  65 (0x41) Non-shifted
	PLAY_ASCIIKEY_LOWER_B				= 0x42,		// 'B', ASCII  66 (0x42) Non-shifted
	PLAY_ASCIIKEY_LOWER_C				= 0x43,		// 'C', ASCII  67 (0x43) Non-shifted
	PLAY_ASCIIKEY_LOWER_D				= 0x44,		// 'D', ASCII  68 (0x44) Non-shifted
	PLAY_ASCIIKEY_LOWER_E				= 0x45,		// 'E', ASCII  69 (0x45) Non-shifted
	PLAY_ASCIIKEY_LOWER_F				= 0x46,		// 'F', ASCII  70 (0x46) Non-shifted
	PLAY_ASCIIKEY_LOWER_G				= 0x47,		// 'G', ASCII  71 (0x47) Non-shifted
	PLAY_ASCIIKEY_LOWER_H				= 0x48,		// 'H', ASCII  72 (0x48) Non-shifted
	PLAY_ASCIIKEY_LOWER_I				= 0x49,		// 'I', ASCII  73 (0x49) Non-shifted
	PLAY_ASCIIKEY_LOWER_J				= 0x4A,		// 'J', ASCII  74 (0x4A) Non-shifted
	PLAY_ASCIIKEY_LOWER_K				= 0x4B,		// 'K', ASCII  75 (0x4B) Non-shifted
	PLAY_ASCIIKEY_LOWER_L				= 0x4C,		// 'L', ASCII  76 (0x4C) Non-shifted
	PLAY_ASCIIKEY_LOWER_M				= 0x4D,		// 'M', ASCII  77 (0x4D) Non-shifted
	PLAY_ASCIIKEY_LOWER_N				= 0x4E,		// 'N', ASCII  78 (0x4E) Non-shifted
	PLAY_ASCIIKEY_LOWER_O				= 0x4F,		// 'O', ASCII  79 (0x4F) Non-shifted
	PLAY_ASCIIKEY_LOWER_P				= 0x50,		// 'P', ASCII  80 (0x50) Non-shifted
	PLAY_ASCIIKEY_LOWER_Q				= 0x51,		// 'Q', ASCII  81 (0x51) Non-shifted
	PLAY_ASCIIKEY_LOWER_R				= 0x52,		// 'R', ASCII  82 (0x52) Non-shifted
	PLAY_ASCIIKEY_LOWER_S				= 0x53,		// 'S', ASCII  83 (0x53) Non-shifted
	PLAY_ASCIIKEY_LOWER_T				= 0x54,		// 'T', ASCII  84 (0x54) Non-shifted
	PLAY_ASCIIKEY_LOWER_U				= 0x55,		// 'U', ASCII  85 (0x55) Non-shifted
	PLAY_ASCIIKEY_LOWER_V				= 0x56,		// 'V', ASCII  86 (0x56) Non-shifted
	PLAY_ASCIIKEY_LOWER_W				= 0x57,		// 'W', ASCII  87 (0x57) Non-shifted
	PLAY_ASCIIKEY_LOWER_X				= 0x58,		// 'X', ASCII  88 (0x58) Non-shifted
	PLAY_ASCIIKEY_LOWER_Y				= 0x59,		// 'Y', ASCII  89 (0x59) Non-shifted
	PLAY_ASCIIKEY_LOWER_Z				= 0x5A,		// 'Z', ASCII  90 (0x5A) Non-shifted
	PLAY_ASCIIKEY_LEFTSQUAREBRACKET		= 0x5B,		// '[', ASCII  91 (0x5B) Non-shifted
	PLAY_ASCIIKEY_BACKSLASH				= 0x5C,		// '\', ASCII  92 (0x5C) Non-shifted
	PLAY_ASCIIKEY_RIGHTSQUAREBRACKET	= 0x5D,		// ']', ASCII  93 (0x5D) Non-shifted
	PLAY_ASCIIKEY_CARET					= 0x5E,		// '^', ASCII  94 (0x5E) Shifted
	PLAY_ASCIIKEY_UNDERSCORE			= 0x5F,		// '_', ASCII  95 (0x5F) Shifted
	PLAY_ASCIIKEY_GRAVEACCENT			= 0x60,		// '`', ASCII  96 (0x60) Non-shifted
	PLAY_ASCIIKEY_UPPER_A				= 0x61,		// 'a', ASCII  97 (0x61) Shifted
	PLAY_ASCIIKEY_UPPER_B				= 0x62,		// 'b', ASCII  98 (0x62) Shifted
	PLAY_ASCIIKEY_UPPER_C				= 0x63,		// 'c', ASCII  99 (0x63) Shifted
	PLAY_ASCIIKEY_UPPER_D				= 0x64,		// 'd', ASCII 100 (0x64) Shifted
	PLAY_ASCIIKEY_UPPER_E				= 0x65,		// 'e', ASCII 101 (0x65) Shifted
	PLAY_ASCIIKEY_UPPER_F				= 0x66,		// 'f', ASCII 102 (0x66) Shifted
	PLAY_ASCIIKEY_UPPER_G				= 0x67,		// 'g', ASCII 103 (0x67) Shifted
	PLAY_ASCIIKEY_UPPER_H				= 0x68,		// 'h', ASCII 104 (0x68) Shifted
	PLAY_ASCIIKEY_UPPER_I				= 0x69,		// 'i', ASCII 105 (0x69) Shifted
	PLAY_ASCIIKEY_UPPER_J				= 0x6A,		// 'j', ASCII 106 (0x6A) Shifted
	PLAY_ASCIIKEY_UPPER_K				= 0x6B,		// 'k', ASCII 107 (0x6B) Shifted
	PLAY_ASCIIKEY_UPPER_L				= 0x6C,		// 'l', ASCII 108 (0x6C) Shifted
	PLAY_ASCIIKEY_UPPER_M				= 0x6D,		// 'm', ASCII 109 (0x6D) Shifted
	PLAY_ASCIIKEY_UPPER_N				= 0x6E,		// 'n', ASCII 110 (0x6E) Shifted
	PLAY_ASCIIKEY_UPPER_O				= 0x6F,		// 'o', ASCII 111 (0x6F) Shifted
	PLAY_ASCIIKEY_UPPER_P				= 0x70,		// 'p', ASCII 112 (0x70) Shifted
	PLAY_ASCIIKEY_UPPER_Q				= 0x71,		// 'q', ASCII 113 (0x71) Shifted
	PLAY_ASCIIKEY_UPPER_R				= 0x72,		// 'r', ASCII 114 (0x72) Shifted
	PLAY_ASCIIKEY_UPPER_S				= 0x73,		// 's', ASCII 115 (0x73) Shifted
	PLAY_ASCIIKEY_UPPER_T				= 0x74,		// 't', ASCII 116 (0x74) Shifted
	PLAY_ASCIIKEY_UPPER_U				= 0x75,		// 'u', ASCII 117 (0x75) Shifted
	PLAY_ASCIIKEY_UPPER_V				= 0x76,		// 'v', ASCII 118 (0x76) Shifted
	PLAY_ASCIIKEY_UPPER_W				= 0x77,		// 'w', ASCII 119 (0x77) Shifted
	PLAY_ASCIIKEY_UPPER_X				= 0x78,		// 'x', ASCII 120 (0x78) Shifted
	PLAY_ASCIIKEY_UPPER_Y				= 0x79,		// 'y', ASCII 121 (0x79) Shifted
	PLAY_ASCIIKEY_UPPER_Z				= 0x7A,		// 'z', ASCII 122 (0x7A) Shifted
	PLAY_ASCIIKEY_LEFTBRACKET			= 0x7B,		// '{', ASCII 123 (0x7B) Shifted
	PLAY_ASCIIKEY_BAR					= 0x7C,		// '|', ASCII 124 (0x7C) Shifted
	PLAY_ASCIIKEY_RIGHTBRACKET			= 0x7D,		// '}', ASCII 125 (0x7D) Shifted
	PLAY_ASCIIKEY_TILDE					= 0x7E,		// '~', ASCII 126 (0x7E) Shifted

	// Unknown							
	PLAY_ASCIIKEY_UNDEFINED				= 0x7F,

// Remappings
	PLAY_ASCIIKEY_LESSTHAN				= PLAY_ASCIIKEY_LEFTANGULARBRACKET,
	PLAY_ASCIIKEY_GREATERTHAN			= PLAY_ASCIIKEY_RIGHTANGULARBRACKET,
	PLAY_ASCIIKEY_PIPE					= PLAY_ASCIIKEY_BAR,
	PLAY_ASCIIKEY_ROUNDABOUT			= PLAY_ASCIIKEY_AT,
	PLAY_ASCIIKEY_MINUS					= PLAY_ASCIIKEY_HYPHEN,
	PLAY_ASCIIKEY_DIVIDE				= PLAY_ASCIIKEY_SLASH,
	PLAY_ASCIIKEY_MULTIPLY				= PLAY_ASCIIKEY_ASTERIK,
	PLAY_ASCIIKEY_DECIMAL				= PLAY_ASCIIKEY_PERIOD,
	PLAY_ASCIIKEY_ADD					= PLAY_ASCIIKEY_PLUS,
	PLAY_ASCIIKEY_SUBTRACT				= PLAY_ASCIIKEY_MINUS,
};

enum PLAYKEYSTATE
{
	PLAY_KEY_RELEASED	= 0,
	PLAY_KEY_PRESSED	= 1
};

#define PLAY_KEYS_COUNT					(256)
#define PLAY_ASCII_KEYS_COUNT			(128)

struct PLAYKEYBOARDSTATE
{
	BYTE		mKeys[PLAY_KEYS_COUNT];
};

struct PLAYASCIIKEYBOARDSTATE
{
	BYTE		mKeys[PLAY_ASCII_KEYS_COUNT];
};

struct PLAYKEYBOARDMASK
{
	ULONG		mAsciiMask;		// Keys    0 - 127
	ULONG		mNonAsciiMask;	// Keys  127 - 255
};

// Default key-repeat settings
#define PLAY_DEFAULT_KEYREPEAT_FIRST_DELAY	(500)
#define PLAY_DEFAULT_KEYREPEAT_NEXT_DELAY	(50)

// Default buffer event-buffer size (true for mouse interface also)
#define PLAY_DEFAULT_EVENT_BUFFER_SIZE		(16)

// --- IPlayKeyboardNotification ------------------------------------------ //

extern "C" const GUID	IID_IPlayKeyboardNotification;

// Use these for notification mask in IPlayKeyboard::SetNotification
#define PLAY_KEYPRESS_NOTIFY				(0)
#define PLAY_KEYRELEASE_NOTIFY				(1)
#define PLAY_KEYREPEAT_NOTIFY				(2)
#define PLAY_KEYBOARDFOCUSGAINED_NOTIFY		(3)
#define PLAY_KEYBOARDFOCUSLOST_NOTIFY		(4)

interface IPlayKeyboardNotification : public IUnknown
{
public:
	// Key specified by 'KeyCode' pressed
	virtual VOID STDMETHODCALLTYPE KeyPress (
		IN	PLAYKEYCODE		KeyCode) { return; };

	// Key specified by 'KeyCode' released
	virtual VOID STDMETHODCALLTYPE KeyRelease (
		IN	PLAYKEYCODE		KeyCode) { return; };

	// Key specified by 'KeyCode' repeatedly pressed; 
	// This is affected by repeat parameters setup by user
	virtual VOID STDMETHODCALLTYPE KeyRepeat (
		IN	PLAYKEYCODE		KeyCode) { return; };

	// Keyboard focus gained - not supported yet
	virtual VOID STDMETHODCALLTYPE KeyboardFocusGain (VOID) { return; };

	// Keyboard focus lost - not supported yet
	virtual VOID STDMETHODCALLTYPE KeyboardFocusLoose (VOID) { return; };
};

// Client notification class can directly inherit from this class,
// overriding desired routines.  Ensure that the notification mask
// (used in SetNotification()), contains all the required masks.

// Note: This class is meant to be derived, and hence does not implement
//       IUnknown members, which are left for the derived class.
class CPlayKeyboardNotification : public IPlayKeyboardNotification
{
public:
	// --- IPlayKeyboardNotification -----------------------------------------
	virtual VOID STDMETHODCALLTYPE KeyPress (
		IN	PLAYKEYCODE		KeyCode) { return; };

	virtual VOID STDMETHODCALLTYPE KeyRelease (
		IN	PLAYKEYCODE		KeyCode) { return; };

	virtual VOID STDMETHODCALLTYPE KeyRepeat (
		IN	PLAYKEYCODE		KeyCode) { return; };

	virtual VOID STDMETHODCALLTYPE KeyboardFocusGain (VOID) { return; };

	virtual VOID STDMETHODCALLTYPE KeyboardFocusLoose (VOID) { return; };
};

// --- IPlayKeyboard ------------------------------------------------------ //

extern "C" const GUID	IID_IPlayKeyboard;

interface IPlayKeyboard : public IUnknown
{
public:
	// Gets the current state of passed in key
	virtual HRESULT STDMETHODCALLTYPE GetKeyState (
		IN	PLAYKEYCODE					KeyCode,
		OUT	PLAYKEYSTATE*				pKeyState) = 0;

	// Gets the entire current keystate array
	virtual HRESULT STDMETHODCALLTYPE GetState (
		OUT	const PLAYKEYBOARDSTATE**	ppKeyboardState) = 0;

	// Gets the current state of passed in ASCII key
	virtual HRESULT STDMETHODCALLTYPE GetAsciiKeyState (
		IN	PLAYASCIIKEYCODE			AsciiKeyCode,
		OUT	PLAYKEYSTATE*				pKeyState) = 0;

	// Gets the entire current ASCII keystate array
	virtual HRESULT STDMETHODCALLTYPE GetAsciiState (
		OUT	const PLAYASCIIKEYBOARDSTATE**	ppAsciiKeyboardState) = 0;

	// Gets the ASCII key corr. to passed in key
	// It checks state of SHIFT keys, and returns the corresponding
	// shifted or non-shifted ASCII keycode
	virtual HRESULT STDMETHODCALLTYPE GetAsciiCode (
		IN	PLAYKEYCODE					KeyCode,
		OUT	PLAYASCIIKEYCODE*			pAsciiKeyCode) = 0;

	// Gets current state of any non-NULL lock keys passed in.
	// At least one parameter should be non-NULL.
	virtual HRESULT STDMETHODCALLTYPE GetLockState (
		IN	BOOL*	pCapsLock,
		IN	BOOL*	pNumLock,
		IN	BOOL*	pScrollLock) = 0;

	// Gets a notification mask supported by the object
	// The user should check this to find out what is supported 
	// before setting it's own mask
	virtual HRESULT STDMETHODCALLTYPE GetNotificationCaps (
		OUT	ULONG*						pNotificationMask) = 0;

	// Used to set up a notification object with the mouse
	// Accepts NULL 'pNotification' param; results in turning off notification
	virtual HRESULT STDMETHODCALLTYPE SetNotification (
		IN	ULONG						NotificationMask,
		IN	CPlayKeyboardNotification*	pNotification) = 0;

	// Gets the current notification mask / object 
	virtual HRESULT STDMETHODCALLTYPE GetNotification (
		OUT	ULONG*						pNotificationMask,
		OUT	CPlayKeyboardNotification**	ppNotification) = 0;

	// Gains ownership the keyboard device.
	// Note that it does not gurantee this ownership.; A second call to 
	// Acquire() by another client will result in immediate loss of ownership
	virtual HRESULT STDMETHODCALLTYPE Acquire (VOID) = 0;

	// Releases ownership of the keyboard device
	virtual HRESULT STDMETHODCALLTYPE Unacquire (VOID) = 0;

	// Alternative routine (for non multi-threaded cases), to be
	// called by client on a regular interval.  Updates the internal
	// keyboard state, and sends change events to notification object (if
	// present).  Works only if the client has 'acquired' the keyboard.
	virtual HRESULT STDMETHODCALLTYPE Update (VOID) = 0;
	
	// Sets the buffer size.  Value of 0 is equivalent to non-buffered mode
	// Default is 16
	virtual HRESULT STDMETHODCALLTYPE SetBufferSize (
		IN	ULONG						BufferSize) = 0;
	
	// Gets current buffer size
	virtual HRESULT STDMETHODCALLTYPE GetBufferSize (
		OUT	ULONG*						pBufferSize) = 0;

	// Set up the repeat rate parameters for a keyboard.
	// Useful only if we've registered for KEYREPEAT notifications.
	// 'StartDelay' indicates the delay for the first time; 'RepeatDelay' indicates
	// subsequent delays (for the same key press).  All times are in Milli-Seconds.
	// Default is StartDelay = 500ms / RepeatDelay = 50ms
	virtual HRESULT STDMETHODCALLTYPE SetRepeatRate (
		IN	ULONG						StartDelay,
		IN	ULONG						RepeatDelay) = 0;

	// Gets current repeat rate parameters.  All times are in Milli-Seconds.
	virtual HRESULT STDMETHODCALLTYPE GetRepeatRate (
		OUT	ULONG*						pStartDelay,
		OUT	ULONG*						pRepeatDelay) = 0;

	// Sets either pre-defined keyboard mask, or custom keyboard masks
	// Default mask covers the entire keyboard
	virtual HRESULT STDMETHODCALLTYPE SetKeyboardMask (
		IN	PLAYKEYBOARDMASK*			pKeyboardMask) = 0;

	// Gets the currently set keyboard mask. Default mask covers the
	// entire keyboard
	virtual HRESULT STDMETHODCALLTYPE GetKeyboardMask (
		OUT	PLAYKEYBOARDMASK**			ppKeyboardMask) = 0;
};

// --- IPlayMousexxx data-types ------------------------------------------- //

struct PLAYMOUSECOORDS
{
	LONG							mX;
	LONG							mY;
	LONG							mZ;
};

enum PLAYMOUSEBUTTONSTATE
{
	PLAY_MOUSE_BUTTON_RELEASED		= 0,
	PLAY_MOUSE_BUTTON_PRESSED		= 1,
	PLAY_MOUSE_BUTTON_DBLCLICKED	= 2
};

enum PLAYMOUSEBUTTON
{
	PLAY_MOUSE_BUTTON_LEFT			= 0,
	PLAY_MOUSE_BUTTON_RIGHT			= 1,
	PLAY_MOUSE_BUTTON_MIDDLE		= 2,
	PLAY_MOUSE_BUTTON_EXTRA			= 3,
};

enum PLAYMOUSEAXIS
{
	PLAY_MOUSE_AXIS_X				= 0,
	PLAY_MOUSE_AXIS_Y				= 1,
	PLAY_MOUSE_AXIS_Z				= 2
};

struct PLAYMOUSESTATE
{
	PLAYMOUSECOORDS					mAbsoluteCoords;
	PLAYMOUSECOORDS					mRelativeCoords;
									
	PLAYMOUSEBUTTONSTATE			mLeftButton;
	PLAYMOUSEBUTTONSTATE			mMiddleButton;
	PLAYMOUSEBUTTONSTATE			mRightButton;
	PLAYMOUSEBUTTONSTATE			mExtraButton;
};

// Default dbl-click delay rate
#define PLAY_DEFAULT_DBLCLICK_DELAY			(100)

// --- CPlayMouseNotification --------------------------------------------- //

extern "C" const GUID	IID_IPlayMouseNotification;

// Use these for notification mask in IPlayMouse::SetNotification
#define PLAY_MOUSEMOVE_NOTIFY				(0)
#define PLAY_MOUSEBUTTONPRESS_NOTIFY		(1)
#define PLAY_MOUSEBUTTONRELEASE_NOTIFY		(2)
#define PLAY_MOUSEBUTTONDBLCLICK_NOTIFY		(3)
#define PLAY_MOUSEFOCUSGAINED_NOTIFY		(4)
#define PLAY_MOUSEFOCUSLOST_NOTIFY			(5)

interface IPlayMouseNotification : public IUnknown
{
public:
	// Mouse has moved, on given axis, and by given coords.
	virtual VOID STDMETHODCALLTYPE MouseMove (
		IN	PLAYMOUSEAXIS		AxisId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	// Given button has been pressed, at given location
	virtual VOID STDMETHODCALLTYPE MouseButtonPress (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	// Given button has been released, at given location
	virtual VOID STDMETHODCALLTYPE MouseButtonRelease (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	// Given button has been double-clicked, at given location
	virtual VOID STDMETHODCALLTYPE MouseButtonDblClick (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };

	// Mouse focus gained - not supported yet
	virtual VOID STDMETHODCALLTYPE MouseFocusGain (VOID) { return; };

	// Mouse focus released - not supported yet
	virtual VOID STDMETHODCALLTYPE MouseFocusLoose (VOID) { return; };
};

// Client notification class can directly inherit from this class,
// overriding desired routines.  Ensure that the notification mask
// (used in SetNotification()), contains all the required masks.

// Note: This class is meant to be derived, and hence does not implement
//       IUnknown members, which are left for the derived class.
class CPlayMouseNotification : public IPlayMouseNotification
{
public:
	// --- IPlayKeyboardNotification -----------------------------------------
	virtual VOID STDMETHODCALLTYPE MouseMove (
		IN	PLAYMOUSEAXIS		AxisId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	virtual VOID STDMETHODCALLTYPE MouseButtonPress (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	virtual VOID STDMETHODCALLTYPE MouseButtonRelease (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };
	
	virtual VOID STDMETHODCALLTYPE MouseButtonDblClick (
		IN	PLAYMOUSEBUTTON		ButtonId,
		IN	PLAYMOUSECOORDS*	pRelativeCoords,
		IN	PLAYMOUSECOORDS*	pAbsoluteCoords) { return; };

	virtual VOID STDMETHODCALLTYPE MouseFocusGain (VOID) { return; };

	virtual VOID STDMETHODCALLTYPE MouseFocusLoose (VOID) { return; };
};


// --- IPlayMouse --------------------------------------------------------- //

extern "C" const GUID	IID_IPlayMouse;

interface IPlayMouse : public IUnknown
{
public:
	// Gets the current mouse state.  Includes current absolute/relative
	// cursor positions, plus the state of all available mouse buttons.
	virtual HRESULT STDMETHODCALLTYPE GetState (
		OUT	const PLAYMOUSESTATE**		ppMouseState) = 0;

	// Gets a notification mask supported by the object
	// The user should check this to find out what is supported 
	// before setting it's own mask
	virtual HRESULT STDMETHODCALLTYPE GetNotificationCaps (
		OUT	ULONG*						pNotificationMask) = 0;

	// Used to set up a notification object with the mouse
	// Accepts NULL 'pNotification' param; results in turning off notification
	virtual HRESULT STDMETHODCALLTYPE SetNotification (
		IN	ULONG						NotificationMask,
		IN	CPlayMouseNotification*		pNotification) = 0;

	// Gets the current notification mask / object 
	virtual HRESULT STDMETHODCALLTYPE GetNotification (
		OUT	ULONG*						pNotificationMask,
		OUT	CPlayMouseNotification**	ppNotification) = 0;

	// Gains ownership the mouse device.
	// Note that it does not gurantee this ownership.; A second call to 
	// Acquire() by another client will result in immediate loss of ownership
	virtual HRESULT STDMETHODCALLTYPE Acquire (VOID) = 0;

	// Releases ownership of the mouse device.
	virtual HRESULT STDMETHODCALLTYPE Unacquire (VOID) = 0;

	// Redirects all mouse input to this object.
	// The object needs to have acquired the mouse; it will also prevent
	// anyone else from acquiring the mouse till you 'free' the capture.
	// Will not work if the mouse has already been captured by someone else.
	virtual HRESULT STDMETHODCALLTYPE Capture (VOID) = 0;

	// Frees the mouse, if previously captured.  Does not require mouse acquisition.
	virtual HRESULT STDMETHODCALLTYPE Free (VOID) = 0;

	// Alternative routine (for non multi-threaded cases), to be
	// called by client on a regular interval.  Updates the internal
	// keyboard state, and sends change events to notification object (if
	// present).  Works only if the client has 'acquired' the mouse.
	virtual HRESULT STDMETHODCALLTYPE Update (VOID) = 0;
	
	// Sets the buffer size.  Value of 0 is equivalent to non-buffered mode
	// Default is 16
	virtual HRESULT STDMETHODCALLTYPE SetBufferSize (
		IN	ULONG						BufferSize) = 0;
	
	// Gets current buffer size
	virtual HRESULT STDMETHODCALLTYPE GetBufferSize (
		OUT	ULONG*						pBufferSize) = 0;

	// Set up the double-click delat for the mouse (in Milli-Seconds).
	// Useful only if we've registered for MOUSEDBLCLICK notifications.
	virtual HRESULT STDMETHODCALLTYPE SetDblClickRate (
		IN	ULONG						Delay) = 0;

	// Gets current double-click delay  (in Milli-Seconds).
	virtual HRESULT STDMETHODCALLTYPE GetDblClickRate (
		OUT	ULONG*						pDelay) = 0;
};

// ------------------------------------------------------------------------ //
#endif __IPlayInput_H__
// ------------------------------------------------------------------------ //

// End-of-file : IPlayInput.H