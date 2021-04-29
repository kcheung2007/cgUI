/*===========================================================================

    Copyright (c) 1995, 1997 by Play Incorporated                                      
	PLAY CONFIDENTIAL                                                        
    All Specifications subject to change.                                    
	                                                                          
	FILE:           Client_BinAdvise.h

	MODIFICATIONS:  Nov 14, 1995	tpabon 		created
					01/27/97		R. Hooper	modified filenames for use with
												version C.0.25 ClientShell.exe
												sample program

============================================================================= */

#ifndef _CLIENT_BINADVISE_H
#define _CLIENT_BINADVISE_H

#include "PlayUI_i.h"

class CBinHandler : public CPlayUIBinHandler
{
public:
    CBinHandler() {} ;
    ~CBinHandler() {} ;

    STDMETHOD(OnSelect)(
        IPlayUIBinItem* pItem);

    STDMETHOD(OnLBtnDblClk)(
        IPlayUIBinItem* pItem);
};

#endif 

