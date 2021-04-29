/*===========================================================================

    Copyright (c) 1997 by Play Incorporated                                      
	PLAY CONFIDENTIAL                                                        
                                                                             
    All Specifications subject to change.                                    
	                                                                          
	FILE:           GHelp.h
	                
	SUMMARY:		CLSIDs and IIDs for COHelpServer and COHelpWindow.
	
	NOTE:			The CLSID_COHelpWindow is not required by the client
					application, since the client never directly instantiates
					this object.  (COHelpServer aggregates COHelpWindow.)
					

	SEE ALSO		For more information about the supported interfaces, see the
					idl file: IHelp.idl
	                                                                         
	                                                                         
	MODIFICATIONS:  12/29/96    R.Hooper        Created.
					01/27/97	R.Hooper		Refined for first pre-alpha 
												release.   
	VERSION:		C.0.25
	  
============================================================================= */
#if !defined(G_HELP_H)
#define G_HELP_H

/* 3bcbba30-6bdc-11cf-ac06-00201831411f */
#define DECLARE_CLSID_COHELPWINDOW \
	const CLSID CLSID_COHelpWindow = { \
    0x3bcbba30,\
    0x6bdc,\
    0x11cf,\
    {0xac, 0x06, 0x00, 0x20, 0x18, 0x31, 0x41, 0x1f}\
	};

/* 3bcbba31-6bdc-11cf-ac06-00201831411f */
#define DECLARE_IID_IHELPWINDOW \
	const IID IID_IHelpWindow = { \
    0x3bcbba31,\
    0x6bdc,\
    0x11cf,\
    {0xac, 0x06, 0x00, 0x20, 0x18, 0x31, 0x41, 0x1f}\
};

/* 3bcbba34-6bdc-11cf-ac06-00201831411f */
#define DECLARE_CLSID_COHELPSERVER \
	const CLSID CLSID_COHelpServer = { \
    0x3bcbba34,\
    0x6bdc,\
    0x11cf,\
    {0xac, 0x06, 0x00, 0x20, 0x18, 0x31, 0x41, 0x1f}\
};

/* 3bcbba35-6bdc-11cf-ac06-00201831411f */
#define DECLARE_IID_IHELPSERVER \
	const IID IID_IHelpServer = { \
    0x3bcbba35,\
    0x6bdc,\
    0x11cf,\
    {0xac, 0x06, 0x00, 0x20, 0x18, 0x31, 0x41, 0x1f}\
};

#endif