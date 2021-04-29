/***
*
*  PlayUI
*  Copyright (C) Play Incorporated, 1995 - confidential
*
*  PRELIMINARY - ALL SPECIFICATIONS SUBJECT TO CHANGE
*
*  File:       BinHand.h
*
*  Contents:   declaration for BinHand Class
*
*  History:    tpabon created
*
******************************************************************************/

#ifndef _BinHand_h
#define _BinHand_h

#include "PlayUI1_i.h"

// a litle class to handle bin events

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

#endif // _BinHand_h

