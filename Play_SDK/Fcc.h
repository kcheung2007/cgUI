#ifndef	fcc_h
#define fcc_h

#include "toolbox.h"

// Play Storage -----------------------------
#define	EXT_PST		MAKE_FCC('p','s','t',0)				// "Play Storage"

// Play ImageBook ---------------------------
#define	EXT_PIB		MAKE_FCC('p','i','b',0)				// "Play Image Book"

// Stream with picon extension ---------------------
#define	EXT_TFS		MAKE_FCC('t','f','s',0)				// "Trinity Frame Store"
#define	EXT_TFX		MAKE_FCC('t','f','x',0)
#define	EXT_SAV		MAKE_FCC('s','a','v',0)
#define	EXT_PTL		MAKE_FCC('p','t','l',0)				// Play TimeLine
#define	EXT_PPF		MAKE_FCC('p','p','f',0)
#define	EXT_SRC		MAKE_FCC('s','r','c',0)
#define	EXT_TPS		MAKE_FCC('t','p','s',0)
#define	EXT_TWP		MAKE_FCC('t','w','p',0)
#define	EXT_FXO		MAKE_FCC('f','x','o',0)
#define	EXT_GPI		MAKE_FCC('g','p','i',0)
#define	EXT_PNL		MAKE_FCC('p','n','l',0)
#define	EXT_LCP		MAKE_FCC('l','c','p',0)
#define	EXT_601		MAKE_FCC('6','0','1',0)
#define EXT_CKS		MAKE_FCC('C','K','S',0)
#define EXT_CCS		MAKE_FCC('c','c','s',0)				// Color Corection Settings
#define EXT_PBL		MAKE_FCC('p','b','l',0)				// Play batch list

// Image file extension ---------------------
#define	EXT_PNG		MAKE_FCC('p','n','g',0)				// "Portable Network Graphic"
#define	EXT_BMP		MAKE_FCC('b','m','p',0)				// Windows
#define	EXT_RLE		MAKE_FCC('r','l','e',0)				// Windows
#define	EXT_DIB		MAKE_FCC('d','i','b',0)				// Windows
#define	EXT_JPG		MAKE_FCC('j','p','g',0)				// "JPEG"
#define	EXT_JPE		MAKE_FCC('j','p','e',0)				// "JPEG"
#define	EXT_JFI		MAKE_FCC('j','f','i',0)				// "JPEG"
#define	EXT_JPEG	MAKE_FCC('j','p','e','g')			// "JPEG"
#define	EXT_JFIF	MAKE_FCC('j','f','i','f')			// "JPEG"
#define	EXT_TGA		MAKE_FCC('t','g','a',0)				// "Targa"
#define	EXT_TIF		MAKE_FCC('t','i','f',0)				// "Tagged Image File"
#define	EXT_TIFF	MAKE_FCC('t','i','f','f')			// "Tagged Image File"
#define	EXT_IFF		MAKE_FCC('i','f','f',0)				// "Interchange File Format"
#define	EXT_PCX		MAKE_FCC('p','c','x',0)				// "PC Paintbrush"
#define	EXT_PCC		MAKE_FCC('p','c','c',0)				// "PC Paintbrush"
#define	EXT_PCT		MAKE_FCC('p','c','t',0)				// "MacIntosh"
#define	EXT_PICT	MAKE_FCC('p','i','c','t')			// "MacIntosh" & "SoftImage"
#define	EXT_PIC		MAKE_FCC('p','i','c',0)				// "MacIntosh" & "SoftImage" & "Pictor PC Paint"
#define	EXT_PSD		MAKE_FCC('p','s','d',0)				// "Adobe PhotoShop"
#define	EXT_SGI		MAKE_FCC('s','g','i',0)				// "Silicon Graphics Image"
#define	EXT_RGB		MAKE_FCC('r','g','b',0)				// "Silicon Graphics Image"
#define	EXT_RGBA	MAKE_FCC('r','g','b','a')			// "Silicon Graphics Image"
#define	EXT_WMF		MAKE_FCC('w','m','f',0)				// "Windows Metafile"
#define	EXT_EMF		MAKE_FCC('e','m','f',0)				// "Windows Metafile"
#define	EXT_WPG		MAKE_FCC('w','p','g',0)				// "WordPerfect Graphic"
#define	EXT_RAS		MAKE_FCC('r','a','s',0)				// "Sun Raster"
#define	EXT_GIF		MAKE_FCC('g','i','f',0)				// 
#define	EXT_IMG		MAKE_FCC('i','m','g',0)				// 

// Movie file extension ---------------------
#define	EXT_AVI		MAKE_FCC('a','v','i',0)				// "Audio Video Interleave"
#define	EXT_MPG		MAKE_FCC('m','p','g',0)
#define	EXT_MOV		MAKE_FCC('m','o','v',0)

// misc -------------------------------------
#define	EXT_PTV		MAKE_FCC('p','t','v',0)
#define	EXT_SHW		MAKE_FCC('s','h','w',0)

// Sound extension --------------------------
#define	EXT_WAV		MAKE_FCC('w','a','v',0)

// music extension --------------------------
#define	EXT_MID		MAKE_FCC('m','i','d',0)
#define	EXT_MOD		MAKE_FCC('m','o','d',0)
#define	EXT_S3M		MAKE_FCC('s','3','m',0)

// Windows extension ------------------------
#define	EXT_LNK		MAKE_FCC('l','n','k',0)
#define	EXT_EXE		MAKE_FCC('e','x','e',0)
#define	EXT_DLL		MAKE_FCC('d','l','l',0)
#define	EXT_SCR		MAKE_FCC('s','c','r',0)
#define	EXT_OCX		MAKE_FCC('o','c','x',0)
#define	EXT_HLP		MAKE_FCC('h','l','p',0)
#define	EXT_INF		MAKE_FCC('i','n','f',0)
#define	EXT_BAT		MAKE_FCC('b','a','t',0)
#define	EXT_DAT		MAKE_FCC('d','a','t',0)
#define	EXT_SYS		MAKE_FCC('s','y','s',0)

// Text document ----------------------------
#define	EXT_TXT		MAKE_FCC('t','x','t',0)
#define	EXT_RTF		MAKE_FCC('r','t','f',0)
#define	EXT_WRI		MAKE_FCC('w','r','i',0)
#define	EXT_DOC		MAKE_FCC('d','o','c',0)

// Misc extension ---------------------------
#define	EXT_ZIP		MAKE_FCC('z','i','p',0)
#define	EXT_INI		MAKE_FCC('i','n','i',0)
#define	EXT_FON		MAKE_FCC('f','o','n',0)

#endif
