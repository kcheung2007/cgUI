//=============================================================================
// ToolBox.h
// Copyright 1998 Play Incorporated
//
// Created 1998 by Stephan Schaem
//=============================================================================
#ifndef	TOOLBOX_H
#define	TOOLBOX_H

#pragma warning(disable : 4102 )

// -- CONSTANTS ---------------------------------------------------------------
#define	NULL			0
#define	FALSE			0
#define	TRUE			1

// -- EXTENDED TYPES ----------------------------------------------------------
typedef	unsigned char	uchar;
typedef	unsigned short	ushort;
typedef	unsigned long	ulong;
typedef	long			STATUS;
typedef	long			fcc;
typedef	unsigned char	LOCKKEY;
typedef	const char *	CSTRING;
typedef	double			TIME;						// Time in seconds
typedef	long			STIME;						// Time in sample (TIME = STIME / rate)
typedef	unsigned long	PSAMPLE;					// (Multiple of sample size: eg: /2, /4)
typedef unsigned long	BITA32;
typedef	unsigned char	UID[16];

typedef struct {
	char			guid[16];						//
	unsigned long	size;							// The size is a multiple of 4???? 16gig limit?
} FHEADER;

// -- MACROS ------------------------------------------------------------------
#define MAKE_FCC(a,b,c,d) (((d)<<24)+((c)<<16)+((b)<<8)+(a))
#define	SWAP_WBYTE(a) (ushort)((((a)<<8)&0xFF00) + (((a)>>8)&0x00FF))
#define	FCC_NULL		MAKE_FCC('N','U','L','L')
#define	BIT(a) (1<<a)

// -- IOCTRL ------------------------------------------------------------------
// WARNING: DO NOT USE THIS.... IT WILL DESEAPER ASAP. (ONLY USED BY OLD VIDEO IO CODE)

// IO CONTROL (OS/METHODE INDEPANDENT IO)
typedef	ulong (IOFUNC)(void *, ulong);

class IOCTRL {
// IOCTRL
private:
public:
	IOFUNC  IOCTRL::* RW;							// Pointer to a Read/Write function member
	
	virtual int		Open(char *, int)=0;
	virtual void	Close()=0;
	virtual ulong	Seek(ulong, ulong)=0;

	virtual IOFUNC	Read=0;
	virtual IOFUNC	Write=0;
};



// -- TEMPLATES ---------------------------------------------------------------
template <class ttype> class ARRAY {
public:
	ARRAY();
	~ARRAY();

	void Add(ttype);
	void Remove();
	ttype *array;
	long	count;
private:
	ttype	*last;
	long	max;
};

template <class ttype> ARRAY<ttype>::ARRAY() {
	max = 16;
	count = 0;
	array = (ttype *)malloc(max*sizeof(void *));
	last = array;
}

template <class ttype> ARRAY<ttype>::~ARRAY() {
	free(array);
}

template <class ttype> void ARRAY<ttype>::Add(ttype p_new) {
	*last++ = p_new;
	count++;
	if(count == max) {
		max += 16;
		array = (ttype *)realloc(array, max*sizeof(void *));
		last = &array[count];
	}
	return;
}

template <class ttype> void ARRAY<ttype>::Remove() {
	max--;
	return;
}

//template <class ttype> void ARRAY<ttype>::Remove(int index) {
//	array[index] = array[max-1];
//	max--;
//	return;
//}

enum RC_SEEK {
	RC_SEEK_S,		//Beginning of file
	RC_SEEK_C,		//Current position of file pointer
	RC_SEEK_E,		//End of file
};

typedef struct {
	uchar	*data;
	ulong	width;
	ulong	height;
	long	rbs;
} TKBITMAP;

typedef struct {
	long	x,y,w,h;
} nrect;

#define STATUS_OK 0
#define STATUS_FAIL -1

// -- FUNCTIONS ---------------------------------------------------------------
extern STATUS __stdcall GenerateUID(UID *);
extern STATUS __stdcall RegisterCOMClass(UID *, char *);
extern STATUS __stdcall UnregisterCOMClass(UID *);
extern STATUS __stdcall BinToString(uchar *, uchar **, long *);
extern STATUS __stdcall StringToBin(uchar *, uchar **, long *);
extern STATUS __stdcall BinToAsci(uchar *, uchar *, long );
extern STATUS __stdcall AsciToBin(uchar *, uchar *, long );
extern STATUS __stdcall cpuid(char *);

extern STATUS __stdcall rcOpen(void **, char *);
extern STATUS __stdcall rcRead(void *, char *, ulong *);
extern STATUS __stdcall rcSeek(void *, long, long);
extern STATUS __stdcall rcClose(void *);

extern STATUS __stdcall Unload(void *);
extern STATUS __stdcall LoadJPEG(void **, TKBITMAP **, char *, long);

extern STATUS __stdcall MaskWindow(void* wnd, nrect *wrect, long w, long h, uchar *alpha, long srbs, long ix);

extern long __stdcall DupString(char **ns, char *str);

extern long __stdcall DeletePath(char *path, bool recursive, bool prompt, bool DelPath);
extern long SearchFiles(char *path,char *dest,char *ext[], int extCount, bool callback());

extern "C" void __fastcall IsMMX(long *);

























#endif
