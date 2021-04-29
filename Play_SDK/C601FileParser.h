#ifndef __INCLUDED_C601FILEPARSER_H__
#define __INCLUDED_C601FILEPARSER_H__

#include "C601File.h"
#include "cdib.h"

class C601FileParser
{
    C601Header  m_header;
    HANDLE      m_hFile;

public:
    C601FileParser();
    ~C601FileParser();

    HRESULT ReadHeader( LPSTR filename, DWORD *pdwFrames, CDIB **pPicon );

    // this will close the file if it was left open
    HRESULT OpenForLoading( LPSTR filename, DWORD *pdwFrames, DWORD *pdwPadSize, IStream **ppStm );

    HRESULT SkipFrames( long numToSkip );

    // this will close the file if it was left open
    HRESULT OpenForSaving( LPSTR filename, CDIB *pPicon, STrnClipInfo *pClipInfo, long frameRate, long actualLength, DWORD *pdwPadSize, IStream **ppStm );
    
    // will generate a picon from data in the file and save it in the header
    // will only work if the file already has space in the header for a picon.
    // EG, use this after OpenForSaving and clip::WriteToStream.
    // this will close the file if it was left open
    HRESULT InsertPicon( LPSTR filename ); 

    // this will close the file if it was left open
    HRESULT CloseFile();

};

#endif //__INCLUDED_C601FILEPARSER_H__
