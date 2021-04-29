// ----------------------------------------------------------------------------
// ubfile.h
// Copyright 1998 Play Incorporated
//
// Created 1998 by Stephan Schaem
// ----------------------------------------------------------------------------
#ifndef	ubfile_h
#define ubfile_h

#include <windows.h>
#include <stdio.h>

#include <toolbox.h>

typedef struct {
	HANDLE	handle;

	ulong	size;					// Size of this UBFILE
	ulong	offset;					// Current operation offset (sectorsize aligned)
	ulong	newoffset;				// Offset of next operation
	ulong	oldoffset;				// Last valid buffer read (sectorsize aligned)

	ulong	sectoroffset;
	ulong	sectorsize;

	void	*buffer;				// a block of memory of size 'sectorsize' and beying 'sectorsize' aligned

	DWORD SectorsPerCluster;		// sectors per cluster 
    DWORD BytesPerSector;			// bytes per sector 
    DWORD NumberOfFreeClusters;		// number of free clusters  
    DWORD TotalNumberOfClusters;	// total number of clusters  

	DWORD OldProtect;
} UBFILE;

enum {
	F_UBFILE_MODE_NEW,
	F_UBFILE_MODE_OLD
};

enum {
	F_UBFILE_ORIGIN_START,
	F_UBFILE_ORIGIN_END,
	F_UBFILE_ORIGIN_CURRENT
};

enum {
	F_UBFILE_UBFILE,
	F_UBFILE_NAME,
	F_UBFILE_SIZE,
	F_UBFILE_MODE,
	F_UBFILE_BUFFER,
	F_UBFILE_OFFSET,
	F_UBFILE_ORIGIN
};

typedef struct {
	ulong	field;
	UBFILE	*ubfile;
	uchar	*name;
	long	offset;
	ulong	size;
	ulong	mode;
	void	*buffer;
	ulong	origin;
} FORM_UBFILE;


extern	STATUS	UBFILE_Open(FORM_UBFILE *);
extern	STATUS	UBFILE_Close(FORM_UBFILE *);
extern	STATUS	UBFILE_Read(FORM_UBFILE *);
extern	STATUS	UBFILE_Write(FORM_UBFILE *);
extern	STATUS	UBFILE_Seek(FORM_UBFILE *);

extern	FILE *	ubfopen(const char *, const char *);
extern	int		ubfclose(FILE *);
extern	size_t	ubfread(void *, size_t, size_t, FILE *);
extern	size_t	ubfwrite(void *, size_t, size_t, FILE *);
extern	int		ubfseek(FILE *, long, int);
extern	long	ubftell(FILE *);

#endif
