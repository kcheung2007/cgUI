/*
* File:         captest.c
* RCS:          $Header: $
* Description:  Capability negotiation for Twacker
* Author:       TWAIN Working Group
* Created:      Feb 5,92
* Modified:     "
* Language:     C
* Package:      N/A
* Status:       Test tool
*
* (c) Copyright 1992, Hewlett-Packard Company, all rights reserved.
*
*	Copyright © 1998 TWAIN Working Group: Adobe Systems Incorporated, 
*	Canon Information Systems, Eastman Kodak Company, 
*	Fujitsu Computer Products of America, Genoa Technology, 
*	Hewlett-Packard Company, Intel Corporation, Kofax Image Products, 
*	JFL Peripheral Solutions Inc., Ricoh Corporation, and Xerox Corporation.  
*	All rights reserved.
*/
//----------------------------------------------------------------------
//                            I n c l u d e s
//----------------------------------------------------------------------
#include "stdafx.h"
#include <windows.h>         // Req. for twain.h type defs and ...
#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <commdlg.h>

#include "twain.h"
//#include "twndebug.h"

#include "table.h"
#include "dca_app.h"
#include "dca_glue.h"
#include "dca_acq.h"
#include "captest.h" 
#include "special.h"
#include "resource.h"
/*
#ifdef WIN32
#include "res_32.h"
#else
#include "res_16.h"
#endif
*/
#define CAP_AUTOFINAL CAP_CUSTOMBASE+1

//----------------------------------------------------------------------
//                            V a r i a b l e s
//----------------------------------------------------------------------
static int AutoFeedBOOL = FALSE;
static int MessageLevelVAR = ERROR; //To display what is happening
//extern HWND g_hMainDlg;

//----------------------------------------------------------------------
//                            F u n c t i o n s
//----------------------------------------------------------------------

TW_UINT16 AltTWItemSize(TW_INT16 ItemType);

void GetItem (TCHAR *Text, TW_UINT16 datatype, LPTSTR pData);

/*
* Function: TWXferMech -- 
* Author: TWAIN Working Group
* Input:
*		hWnd - handle to window
* Output:
*		TW_INT16
* Comments:
*		Set the current transfer mechanism for Twain based on the menus
* that have been checked by the user.
*/
TW_INT16 TWXferMech(HWND hWnd)

{
	TW_CAPABILITY   cap;
	pTW_ONEVALUE    pval = NULL;
	TW_INT16        status = TWRC_FAILURE;  
	OPENFILENAME    ofn;
	TCHAR szDirName[256];
	TCHAR szFile[256];
	TCHAR szFileTitle[256];
	TCHAR chReplace = '|';
	TCHAR szFilter[256];
	UINT  i = 0, cbString = 0;

	/*
	*	Initialize all structures
	*/
	memset(szDirName, 0, sizeof(TCHAR[256]));
	memset(szFile, 0, sizeof(TCHAR[256]));
	memset(szFileTitle, 0, sizeof(TCHAR[256]));
	memset(szFilter, 0, sizeof(TCHAR[256]));
	memset(&cap, 0, sizeof(TW_CAPABILITY));
	memset(&ofn, 0, sizeof(OPENFILENAME));

	ASSERT(hWnd);

	cap.Cap = ICAP_XFERMECH;
	cap.ConType = TWON_ONEVALUE;

	/*
	* alloc the container
	*/
	if (cap.hContainer = GlobalAlloc(GHND, sizeof(TW_ONEVALUE)))
	{
		pval = (pTW_ONEVALUE)GlobalLock(cap.hContainer);
		pval->ItemType = TWTY_UINT16;

		if (GetMenuState (GetMenu (hWnd), TW_APP_BUFFER, MF_BYCOMMAND) & MF_CHECKED)       
		{
			/*
			* memory transfer
			*/
			pval->Item = TWSX_MEMORY;
		}
		else if (GetMenuState (GetMenu (hWnd), TW_APP_FILE, MF_BYCOMMAND) & MF_CHECKED)       
		{
			/*
			* file transfer
			*/
			pval->Item = TWSX_FILE;

			/*
			* file transfer currently fixed to bitmap format
			*
			* get the filename to save as
			* check formats supported by the source            
			*/

			/*
			*	Make sure only .bmp file extensions are possible
			*/
			GetCurrentDirectory(sizeof(szDirName), szDirName);
			szFile[0] = '\0';
			cbString = LoadString((HINSTANCE)GetModuleHandle(NULL), IDS_FILTERSTRING, szFilter, sizeof(szFilter));
			for(i = 0;szFilter[i] != '\0';i++)
			{
				if(szFilter[i] == chReplace)
				{
					szFilter[i] = '\0';
				}
			}

			memset(&ofn, 0, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.hInstance = NULL;
			ofn.lpstrFilter = szFilter;
			ofn.lpstrCustomFilter = (LPTSTR)NULL;
			ofn.nFilterIndex = 1;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFileTitle = szFileTitle;
			ofn.nMaxFileTitle = sizeof(szFileTitle);
			ofn.lpstrInitialDir = szDirName;
			ofn.lpstrTitle = (LPTSTR)NULL;
			ofn.Flags = OFN_SHOWHELP|OFN_OVERWRITEPROMPT;
			ofn.nFileOffset = 0;
			ofn.nFileExtension = 0;
			ofn.lpstrDefExt = (LPTSTR)"bmp";
			ofn.lCustData = 0L;
			ofn.lpfnHook = NULL;
			ofn.lpTemplateName = (LPTSTR)NULL;

			if (GetSaveFileName(&ofn)==FALSE)
			{
				GlobalUnlock(cap.hContainer);
				GlobalFree(cap.hContainer);
				cap.hContainer = NULL;
				return(TWRC_FAILURE);
			}
			else
			{
				_tcscpy(Filename, szFileTitle);
			}
		}
		else 
		{
			pval->Item = TWSX_NATIVE;
		}

		GlobalUnlock(cap.hContainer);

		status = CallDSMEntry(&appID,
						&dsID,
						DG_CONTROL, 
						DAT_CAPABILITY, 
						MSG_SET,
						(TW_MEMREF)&cap);

		GlobalFree((HANDLE)cap.hContainer);

		if (status != TWRC_SUCCESS)
		{
			// TO DO : Show Error
		} 
	}
	else
	{
		status = TWRC_FAILURE;

		// TO DO : SHOW Error
	}
	return status;
}  

/*
* Function: TWAutofeed -- 
* Author: TWAIN Working Group
* Input:
*		hWnd - handle to window
* Output:
*		TW_INT16
* Comments:
*		Checks if the autofeed option on the FILE menu is
* checked and if so begins a capability negotiation.  If the ADF is already
* enabled, (check this) the return value is ??? otherwise the application
* negotiates with the source to enable the capability
*
* If the ADF at the source cannot be enabled, the application should post an 
* error and not allow a transfer (ie: the Source's UI to come up).
*/
TW_INT16 TWAutofeed(HWND hWnd)
{
	TW_CAPABILITY   cap;
	pTW_ONEVALUE    pval = NULL;
	TW_INT16        status = TWRC_SUCCESS;
	TCHAR           Details[128];

	memset(&cap, 0, sizeof(TW_CAPABILITY));
	memset(Details, 0, sizeof(TCHAR[128]));

	ASSERT(hWnd);

	AutoFeedBOOL = FALSE;
	_tcscpy(Details, _T(""));

	/*
	* If Automatic Feeding > CAP_AUTOFEED On is checked
	*/
	if (!(GetMenuState (GetMenu (hWnd), TW_APP_AUTOFEED, MF_BYCOMMAND) & MF_CHECKED))
	{
		return (status);
	}

	cap.Cap = CAP_FEEDERENABLED;
	cap.ConType = TWON_ONEVALUE;

	status = CallDSMEntry(&appID,
					&dsID,
					DG_CONTROL, 
					DAT_CAPABILITY, 
					MSG_GET,
					(TW_MEMREF)&cap);

	if (status != TWRC_SUCCESS)
	{
		status = TWRC_FAILURE;
		_tcscpy(Details, _T("CAP_FEEDERENABLED"));
		GlobalFree(cap.hContainer);
	}
	else
	{   
		pval = (pTW_ONEVALUE)GlobalLock(cap.hContainer);
		if (pval->Item == TRUE)
		{   
			/*
			* Feeder is enabled no need to negotiate
			*/
			GlobalUnlock(cap.hContainer);
			GlobalFree((HANDLE)cap.hContainer); 
		}
		else     
		{
			/*
			* Negotiate with the source
			* Try to turn on CAP_FEEDERENABLED
			*/
			pval->ItemType = TWTY_BOOL;
			pval->Item = TRUE;
			GlobalUnlock(cap.hContainer);

			status = CallDSMEntry(&appID,
							&dsID,
							DG_CONTROL, 
							DAT_CAPABILITY, 
							MSG_SET,
							(TW_MEMREF)&cap);

			/*
			* free here because the GET call will allocate a new container
			*/
			GlobalFree(cap.hContainer);

			if (status == TWRC_SUCCESS)
			{   
				/*
				* Verify that CAP_FEEDERENABLED is now TRUE
				*/
				status = CallDSMEntry(&appID,
								&dsID,
								DG_CONTROL, 
								DAT_CAPABILITY, 
								MSG_GET,
								(TW_MEMREF)&cap);

				if (status == TWRC_SUCCESS)
				{
					pval = (pTW_ONEVALUE)GlobalLock(cap.hContainer);
					if (pval->Item != TRUE) 
					{
						/*
						* Verification failed -- CAP_FEEDERENABLED is FALSE even after successful set to TRUE
						*/
						status = TWRC_FAILURE;
						_tcscpy(Details, _T("CAP_FEEDERENABLED"));
					}
					GlobalUnlock(cap.hContainer);
					GlobalFree((HANDLE)cap.hContainer);    
				}
				else
				{
					status = TWRC_FAILURE;                  
					_tcscpy(Details, _T("CAP_FEEDERENABLED"));                   
				}               
			}
			else
			{    
				/*
				* MSG_SET of CAP_FEEDERENABLED to TRUE did not succeed
				*/
				_tcscpy(Details, _T("CAP_FEEDERENABLED"));
				status = TWRC_FAILURE;
			}
		}

		if (status == TWRC_SUCCESS)
		{
			/*
			* CAP_AUTOFEED
			*/
			cap.Cap = CAP_AUTOFEED;
			cap.ConType = TWON_ONEVALUE;

			status = CallDSMEntry(&appID,
							&dsID,
							DG_CONTROL, 
							DAT_CAPABILITY, 
							MSG_GET,
							(TW_MEMREF)&cap);

			if (status != TWRC_SUCCESS)
			{
				/*
				* MSG_GET on CAP_AUTOFEED did not succeed
				*/
				status = TWRC_FAILURE;
				_tcscpy(Details, _T("CAP_AUTOFEED"));            
			}

			/*
			* MSG_GET on CAP_AUTOFEED returned success
			*/
			pval = (pTW_ONEVALUE)GlobalLock(cap.hContainer);
			if (pval->Item == TRUE)
			{
				/*
				* CAP_AUTOFEED is on
				*/
				GlobalUnlock(cap.hContainer);
				GlobalFree((HANDLE)cap.hContainer);         
			}
			else
			{
				/*
				* Try to set CAP_AUTOFEED to TRUE
				*/
				pval->ItemType = TWTY_BOOL;
				pval->Item = TRUE;
				GlobalUnlock(cap.hContainer);

				status = CallDSMEntry(&appID,
									&dsID,
									DG_CONTROL, 
									DAT_CAPABILITY, 
									MSG_SET,
									(TW_MEMREF)&cap);

				GlobalFree((HANDLE)cap.hContainer);     

				if (status == TWRC_SUCCESS)
				{   
					/*
					* Verify that CAP_AUTOFEED is on
					*/
					status = CallDSMEntry(&appID,
									&dsID,
									DG_CONTROL, 
									DAT_CAPABILITY, 
									MSG_GET,
									(TW_MEMREF)&cap);

					if (status == TWRC_SUCCESS)
					{
						pval = (pTW_ONEVALUE)GlobalLock(cap.hContainer);
						if (pval->Item != TRUE)
						{
							status = TWRC_FAILURE;
							_tcscpy(Details, _T("CAP_AUTOFEED"));            
							/*
							* CAP_AUTOFEED returns FALSE even after succesful set to TRUE
							*/
						}
						GlobalUnlock(cap.hContainer);
						GlobalFree((HANDLE)cap.hContainer); 
					}
					else
					{
						status = TWRC_FAILURE;
						_tcscpy(Details, _T("CAP_AUTOFEED"));            
					}
				}
				else
				{
					/*
					* MSG_SET of CAP_AUTOFEED to TRUE did not succeed
					*/
					status = TWRC_FAILURE;
					_tcscpy(Details, _T("CAP_AUTOFEED"));
				}
			}   
		}   
	}   

	/*
	* Set Local Autofeed Variable on/off        
	*/
	if (status == TWRC_SUCCESS)
	{
		AutoFeedBOOL = TRUE;
	}
	else
	{
		AutoFeedBOOL = FALSE;
	}
	return status;
}  

///////////////////////////////////////////////////////////////////////////
// FUNCTION: AutoFeedOn
//
// ARGS:    none
//
// RETURNS: current state of Source Manager (open/closed)
//
// NOTES:   Just a way to reduce the number of global vars
//
BOOL AutoFeedOn (VOID)
{
	return (AutoFeedBOOL);
}
 
///////////////////////////////////////////////////////////////////////////
// Function: TWAutofeedMenu -- 
// Author: TWAIN Working Group
// Input:
//		hWnd - handle to window
// Output:
//		TW_INT16
// Comments:
//		Set the current Autofeed Options and Flags based on the menus
// that have been checked by the user.
//
TW_INT16 TWAutofeedMenu(HWND hWnd)
{
	TW_INT16      status = TWRC_FAILURE;

	ASSERT(hWnd);

	status = TWAutofeed(hWnd);
	return (status);    
}

/*
* Function: FloatToFIX32 -- 
* Author: TWAIN Working Group
* Input:
*		floater -
* Output:
* TW_FIX32
* Comments:
*		Convert a floating point value into a FIX32.
*/
TW_FIX32 FloatToFIX32(float floater)
{
	TW_FIX32 Fix32_value;
	TW_BOOL sign = (floater < 0)?TRUE:FALSE;
	TW_INT32 value = (TW_INT32) (floater * 65536.0 + (sign?(-0.5):0.5));

	memset(&Fix32_value, 0, sizeof(TW_FIX32));

	Fix32_value.Whole = LOWORD(value >> 16);
	Fix32_value.Frac = LOWORD(value & 0x0000ffffL);

	return (Fix32_value);
}

///////////////////////////////////////////////////////////////////////////
// Function: FIX32ToFloat -- 
// Author: TWAIN Working Group
// Input:
//		fix32
// Output:
//		float
// Comments:
//		Convert a FIX32 value into a floating point value
//
float FIX32ToFloat (TW_FIX32 fix32)
{
	float   floater = 0;

	floater = (float) fix32.Whole + (float) (fix32.Frac / 65536.0);
	return(floater);
}

////////////////////////////////////////////////////////////////////////////
// Function: ShowImageInfo --
// Author: TWAIN Working Group
// Input:
//		hWndofApp - handle to window
// Output: none
// Comments:
//
void ShowImageInfo (HWND hWndofApp)
{
	TW_UINT16       twRC = TWRC_FAILURE;
	TW_UINT16       ccRC = TWRC_FAILURE;
	TW_IMAGEINFO    twImageInfo;
	TCHAR           Details [255];
	TCHAR           Details2 [1024];
	pTW_FIX32       pTWFix32 = NULL;
	TW_UINT16       index = 0;

	memset(&twImageInfo, 0, sizeof(TW_IMAGEINFO));
	memset(Details, 0, sizeof(TCHAR[255]));
	memset(Details2, 0, sizeof(TCHAR[1024]));

	ASSERT(hWndofApp);

	// Check ImageInfo information
	twRC = CallDSMEntry(&appID,
					&dsID, 
					DG_IMAGE,
					DAT_IMAGEINFO, 
					MSG_GET, 
					(TW_MEMREF)&twImageInfo);

	//Return Code from Operation
	switch (twRC)
	{
		case TWRC_SUCCESS:
			_stprintf (Details, _T("\n%s %.2f"), "XResolution:", FIX32ToFloat(twImageInfo.XResolution));
			_tcscat(Details2, Details);

			pTWFix32 = &(twImageInfo.YResolution);
			_stprintf (Details, _T("\n%s %.2f"), "YResolution:", FIX32ToFloat(*pTWFix32));
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %ld"), "ImageWidth:", twImageInfo.ImageWidth);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %ld"), "ImageLength:", twImageInfo.ImageLength);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), "SamplesPerPixel:", twImageInfo.SamplesPerPixel);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), "BitsPerSample:", twImageInfo.BitsPerSample[0]);
			_tcscat(Details2, Details);
			for (index = 1; index < 8; index++)
			{
				wsprintf (Details, _T(", %d"), twImageInfo.BitsPerSample[index]);
				_tcscat(Details2, Details);
			}           

			wsprintf (Details, _T("\n%s %d"), "BitsPerPixel:", twImageInfo.BitsPerPixel);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), "Planar:", twImageInfo.Planar);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), _T("PixelType:"), twImageInfo.PixelType);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), _T("Compression:"), twImageInfo.Compression);
			_tcscat(Details2, Details);
			break;

		case TWRC_FAILURE:
		default:
			// determine details of failure from Source

			if (ccRC == TWRC_SUCCESS)
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);
			} 
			else 
			{
				wsprintf(Details, _T("\n%s"), _T("Condition Code Check Failed") );
				_tcscat(Details2, Details);
			}
			break;
	}

	return;
}

////////////////////////////////////////////////////////////////////////////
// Function: ShowImageLayout
// Author: TWAIN Working Group
// Input:
//		hWndofApp - handle to window
// Output: none
// Comments:
//
void ShowImageLayout (HWND hWndofApp)

{
	TW_UINT16       twRC = TWRC_FAILURE;
	TW_UINT16       ccRC = TWRC_FAILURE;
	TW_IMAGELAYOUT  twImageLayout;
	TCHAR           Details [255];
	TCHAR           Details2 [1024];

	memset(&twImageLayout, 0, sizeof(TW_IMAGELAYOUT));
	memset(Details, 0, sizeof(TCHAR[255]));
	memset(Details2, 0, sizeof(TCHAR[1024]));

	ASSERT(hWndofApp);

	// Check ImageLayout information
	twRC = CallDSMEntry(&appID,
					&dsID, 
					DG_IMAGE,
					DAT_IMAGELAYOUT, 
					MSG_GET, 
					(TW_MEMREF)&twImageLayout);

	//Return Code from Operation
	wsprintf(Details2, _T("%s %d\n"), _T("RETURN CODE:"), twRC);

	switch (twRC)
	{
		case TWRC_SUCCESS:
			_stprintf (Details, _T("\n%s %.2f"), _T("Frame.Left:"), FIX32ToFloat(twImageLayout.Frame.Left));
			_tcscat(Details2, Details);
			_stprintf (Details, _T("\n%s %.2f"), _T("Frame.Top:"), FIX32ToFloat(twImageLayout.Frame.Top));
			_tcscat(Details2, Details);
			_stprintf (Details, _T("\n%s %.2f"), _T("Frame.Right:"), FIX32ToFloat(twImageLayout.Frame.Right));
			_tcscat(Details2, Details);
			_stprintf (Details, _T("\n%s %.2f"), _T("Frame.Bottom:"), FIX32ToFloat(twImageLayout.Frame.Bottom));
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), _T("DocumentNumber:"), twImageLayout.DocumentNumber);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), _T("PageNumber:"), twImageLayout.PageNumber);
			_tcscat(Details2, Details);

			wsprintf (Details, _T("\n%s %d"), _T("FrameNumber:"), twImageLayout.FrameNumber);
			_tcscat(Details2, Details);
			break;

		case TWRC_FAILURE:
		default:
			// determine details of failure from Source

			if (ccRC == TWRC_SUCCESS)
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);
			} 
			else 
			{
				wsprintf(Details, _T("\n%s"), _T("Condition Code Check Failed") );
				_tcscat(Details2, Details);
			}                   
			break;
	}

	return;
}

///////////////////////////////////////////////////////////////////////////
// Function: ShowTW_ID --
// Author: TWAIN Working Group
// Input:
//		hWndofApp - handle to window
//		twID - 
//		text - pointer on
// Output: none
// Comments:
//
void ShowTW_ID (HWND hWndofApp, TW_IDENTITY twID, TCHAR *text)
{
	TCHAR Details [255];
	TCHAR Details2 [1024];

	memset(Details, 0, sizeof(TCHAR[255]));
	memset(Details2, 0, sizeof(TCHAR[1024]));

	ASSERT(hWndofApp);
	ASSERT(text);

	wsprintf(Details2, _T("\n%s %d"), "Id:", twID.Id);
	wsprintf (Details, _T("\n%s %d"), "TW_VERSION.MajorNum:", twID.Version.MajorNum);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "TW_VERSION.MinorNum:", twID.Version.MinorNum);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "TW_VERSION.Language:", twID.Version.Language);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "TW_VERSION.Country:", twID.Version.Country);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %s"), "TW_VERSION.Info:", twID.Version.Info);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "ProtocolMajor:", twID.ProtocolMajor);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "ProtocolMinor:", twID.ProtocolMinor);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %d"), "SupportedGroups:", twID.SupportedGroups);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %s"), "Manufacturer:", twID.Manufacturer);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %s"), "ProductFamily:", twID.ProductFamily);
	_tcscat(Details2, Details);
	wsprintf (Details, _T("\n%s %s"), "ProductName:", twID.ProductName);
	_tcscat(Details2, Details);

	return;
}

/*
* Function: MatchTwainInt
* Author: TWAIN Working Group
* Input:
*		pTable - Pointer to a Table entry that contain the value for the initialization
*		uiTableSize - Maximum of item in table 
*		uiCap -	ID for the current capability 
*		pString - 
* Output:
*		TW_BOOL -	TRUE is successful
* Comments:
*/
TW_BOOL MatchTwainInt(pTABLEENTRY pTable, TW_UINT32 uiTableSize, TW_INT32 uiCapId, LPTSTR pString)

{
	TW_BOOL result = FALSE;
	TW_UINT16 i = 0;

	ASSERT(pTable);
	ASSERT(pString);

	for(i = 0; i < uiTableSize; i++)
	{
		if (pTable[i].ItemId == uiCapId)
		{
			lstrcpy(pString, (LPTSTR)pTable[i].pszItemName);
			result = TRUE;
			break;
		}   
	}   
	return  result;
}//end of MatchTwainInt

////////////////////////////////////////////////////////////////////////////
// Function: ShowCapability --
// Author: TWAIN Working Group
// Input:
//		hWndofApp - handle to window
//		Cap - 
// Output: none
// Comments:
//
void ShowCapability (HWND hWndofApp, TW_UINT16 Cap)
{
	TW_UINT16           twRC = TWRC_FAILURE;
	TW_UINT16           ccRC = TWRC_FAILURE;
	TW_CAPABILITY       twCapability;
	TCHAR               Details [255];
	TCHAR               Details2 [1024];
	TW_UINT16           index = 0;
	pTW_ENUMERATION     pEnum = NULL;
	pTW_ONEVALUE        pOneV = NULL;
	pTW_RANGE           pRange = NULL;
	pTW_ARRAY           pArray = NULL;
	LPTSTR               pData = NULL;
	TW_INT16            datasize = 0;

	memset(&twCapability, 0, sizeof(TW_CAPABILITY));
	memset(Details, 0, sizeof(TCHAR[255]));
	memset(Details2, 0, sizeof(TCHAR[1024]));

	ASSERT(hWndofApp);

	twCapability.Cap = Cap;
	twCapability.ConType = TWON_DONTCARE16;

	// Check Capability information
	twRC = CallDSMEntry(&appID,
					&dsID, 
					DG_CONTROL,
					DAT_CAPABILITY, 
					MSG_GET, 
					(TW_MEMREF)&twCapability);

	//Return Code from Operation
	wsprintf(Details, _T("%s %d\n"), _T("RETURN CODE:"), twRC);
	_tcscpy(Details2, Details);

	//Show TW_CAPABILITY Contents
	MatchTwainInt(Capability, MAX_CAP, twCapability.Cap, 
								Details);
	_tcscat(Details2, _T("\nCap: ") );
	_tcscat(Details2, Details);

	switch (twRC)
	{
		case TWRC_SUCCESS:

			MatchTwainInt(ConType, MAX_CONTYPE, twCapability.ConType, 
										Details);
			_tcscat(Details2, _T("\nConType: "));
			_tcscat(Details2, Details);

			//Show Container Contents
			_tcscat(Details2, _T("\nhContainer."));
			switch(twCapability.ConType)
			{
				case TWON_ONEVALUE:
					pOneV = (pTW_ONEVALUE)GlobalLock(twCapability.hContainer);

					_tcscat(Details2, _T("\n     ItemType: "));
					MatchTwainInt(Types, MAX_TYPES, pOneV->ItemType, 
												Details);
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     Item: "));
					GetItem(Details, pOneV->ItemType, (LPTSTR)&(pOneV->Item));
					_tcscat(Details2, Details);

					GlobalUnlock(twCapability.hContainer);
					GlobalFree((HANDLE)twCapability.hContainer);   
					break;

				case TWON_ENUMERATION:
					pEnum = (pTW_ENUMERATION)GlobalLock(twCapability.hContainer);

					_tcscat(Details2, _T("\n     ItemType: ") );
					MatchTwainInt(Types, MAX_TYPES, pEnum->ItemType, 
												Details);

					datasize = (TW_INT16)AltTWItemSize(pEnum->ItemType);
					_tcscat(Details2, Details);

					wsprintf (Details, _T("\n     %s %d"), _T("NumItems:"), pEnum->NumItems);
					_tcscat(Details2, Details);

					wsprintf (Details, _T("\n     %s %d"), _T("CurrentIndex:"), pEnum->CurrentIndex);
					_tcscat(Details2, Details);

					wsprintf (Details, _T("\n     %s %d"), _T("DefaultIndex:"), pEnum->DefaultIndex);
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     ItemList: "));
					pData = (TCHAR*)pEnum->ItemList; // ???? NOT sure
					//index=0
					GetItem(Details, pEnum->ItemType, (LPTSTR)pData);
					_tcscat(Details2, Details);
					pData+=datasize;
					for (index=1; index < pEnum->NumItems; index++)
					{
						_tcscat(Details2, _T(", "));
						GetItem(Details, pEnum->ItemType, (LPTSTR)pData);
						_tcscat(Details2, Details);
						pData+=datasize;
					}
					GlobalFree(twCapability.hContainer);   
					break;

				case TWON_RANGE:
					pRange = (pTW_RANGE)GlobalLock(twCapability.hContainer);

					_tcscat(Details2, _T("\n     ItemType: "));
					MatchTwainInt(Types, MAX_TYPES, pRange->ItemType, 
												Details);
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     MinValue: "));
					GetItem(Details, pRange->ItemType, (LPTSTR)&(pRange->MinValue));
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     MaxValue: "));
					GetItem(Details, pRange->ItemType, (LPTSTR)&(pRange->MaxValue));
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     StepSize: "));
					GetItem(Details, pRange->ItemType, (LPTSTR)&(pRange->StepSize));
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     DefaultValue: "));
					GetItem(Details, pRange->ItemType, (LPTSTR)&(pRange->DefaultValue));
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     CurrentValue: "));
					GetItem(Details, pRange->ItemType, (LPTSTR)&(pRange->CurrentValue));
					_tcscat(Details2, Details);

					GlobalFree(twCapability.hContainer);     //bad
					break;

				case TWON_ARRAY:
					pArray = (pTW_ARRAY)GlobalLock(twCapability.hContainer);

					_tcscat(Details2, _T("\n     ItemType: "));
					MatchTwainInt(Types, MAX_TYPES, pArray->ItemType, 
												Details);
					datasize = (TW_INT16)AltTWItemSize(pArray->ItemType);
					_tcscat(Details2, Details);

					wsprintf (Details, _T("\n     %s %d"), _T("NumItems:"), pArray->NumItems);
					_tcscat(Details2, Details);

					_tcscat(Details2, _T("\n     ItemList: "));
					pData = (TCHAR*)pArray->ItemList;//not sure
					//index=0
					GetItem(Details, pArray->ItemType, pData);
					_tcscat(Details2, Details);
					pData+=datasize;
					for (index=1; index < pArray->NumItems; index++)
					{
						_tcscat(Details2, _T(", "));
						GetItem(Details, pArray->ItemType, pData);
						_tcscat(Details2, Details);
						pData+=datasize;
					}
					GlobalFree(twCapability.hContainer);    //bad
					break;

				default:
					break;
			}
			break;

		case TWRC_FAILURE:		
			// determine details of failure from Source

			if (ccRC == TWRC_SUCCESS)
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);
			} 
			else 
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);         
			}
			break;
	}

	return;
}

////////////////////////////////////////////////////////////////////////////
// Function: GetItem -- 
// Author: TWAIN Working Group
// Input:
//		test - 
//		datatype - 
//		pData - 
// Output: none
// Comments:
//
void GetItem (TCHAR * Text, TW_UINT16 datatype, LPTSTR pData)
{
	ASSERT(pData);
	ASSERT(Text);

	switch (datatype)
	{
		case 0: //TWTY_INT8
			{
				TW_INT8 value = *(pTW_INT8)pData;
				wsprintf(Text, _T("%d"), (TW_INT16)value);
			}   
			break;

		case 3: // TWTY_UINT8
			{
				TW_UINT8 value = *(pTW_UINT8)pData;
				wsprintf(Text,_T("%u"), (TW_UINT16)value);
			}   
			break;

		case 1: // TWTY_INT16
		case 44:// TWTY_HANDLE
			{
				TW_INT16 value = *(pTW_INT16)pData;
				wsprintf(Text,_T("%d"), value);
			}   
			break;

		case 4: // TWTY_UINT16
		case 6: // TWTY_BOOL
			{
				TW_UINT16 value = *(pTW_UINT16)pData;
				wsprintf(Text,_T("%u"), value);
			}   
			break;

		case 2: // TWTY_INT32
			{
				TW_INT32 value = *(pTW_INT32)pData;
				wsprintf(Text,_T("%ld"), value);
			}   
			break;

		case 5: // TWTY_UINT32
		case 43: // TWTY_MEMREF
			{
				TW_UINT32 value = *(pTW_UINT32)pData;
				wsprintf(Text,_T("%lu"), value);
			}   
			break;

		case 7: // TWTY_FIX32
			{
				float value = 0;
				TW_FIX32 fix32;

				memset(&fix32, 0, sizeof(TW_FIX32));

				fix32.Whole = ((pTW_FIX32)pData)->Whole;
				fix32.Frac = ((pTW_FIX32)pData)->Frac;
				value = FIX32ToFloat(fix32);
				_stprintf(Text, _T("%f"), value);
			}   
			break;

		case 9:  //TWTY_STR32
		case 10: //TWTY_STR64
		case 11: //TWTY_STR128
		case 12: //TWTY_STR255
		default:
			lstrcpy(Text, pData);
			break;
	}   
	return;
}

///////////////////////////////////////////////////////////////////////////
// Function: ShowPendingXfers --
// Author: TWAIN Working Group
// Input:
//		hWndofApp - handle to window
// Output: none
// Comments:
//
void ShowPendingXfers (HWND hWndofApp)

{
	TW_UINT16           twRC = TWRC_FAILURE;
	TW_UINT16           ccRC = TWRC_FAILURE;
	TW_PENDINGXFERS     twPendingXfers;
	TCHAR               Details [255];
	TCHAR               Details2 [1024];

	memset(&twPendingXfers, 0, sizeof(TW_PENDINGXFERS));
	memset(Details, 0, sizeof(TCHAR[255]));
	memset(Details2, 0, sizeof(TCHAR[1024]));

	ASSERT(hWndofApp);

	// Inquire Pending Xfers
	twRC = CallDSMEntry(&appID,
				&dsID, 
				DG_CONTROL,
				DAT_PENDINGXFERS, 
				MSG_GET, 
				(TW_MEMREF)&twPendingXfers);

	// Return Code from Operation
	wsprintf(Details2, _T("%s %d\n"), _T("RETURN CODE:"), twRC);

	switch (twRC)
	{
		case TWRC_SUCCESS:
			wsprintf (Details, _T("\n%s %d"), _T("Count:"), twPendingXfers.Count);
			_tcscat(Details2, Details);
			break;

		case TWRC_FAILURE:
		default:
			// determine details of failure from SM

			if (ccRC == TWRC_SUCCESS)
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);
			}
			else
			{
				wsprintf(Details, _T("\n%s %d"), _T("Condition Code:"), gGlobalStatus.ConditionCode);
				_tcscat(Details2, Details);
			}
			break;
	}

	return;
}   


////////////////////////////////////////////////////////////////////////////
// FUNCTION: MessageLevel
//
// ARGS:    none
//
// RETURNS: current state of Source Manager (open/closed)
//
// NOTES:   Just a way to reduce the number of global vars
//
int MessageLevel (VOID)
{
	return (MessageLevelVAR);
}

////////////////////////////////////////////////////////////////////////////
// FUNCTION: SetMessageLevel
//
// ARGS:    none
//
// RETURNS: current state of Source Manager (open/closed)
//
// NOTES:   Just a way to reduce the number of global vars
//
void SetMessageLevel (int Level)
{
	MessageLevelVAR = Level;
	return;
}

/*
* Function: MsgQuerySupport 
* Author: TWAIN Working Group
* Input:
*		cap -
*		type - 
*		ptwCapability
* Output:
*		TRUE is successful
* Comments:
*
*/
BOOL MsgQuerySupport(TW_UINT16 cap,TW_UINT16 type, pTW_CAPABILITY ptwCapability)
{
	TW_INT16 rc = TWRC_FAILURE;
	TCHAR string[50];

	memset(string, 0, sizeof(TCHAR[50]));

	ASSERT(ptwCapability);

	/*
	* Setup dsID for default Source                             
	*/
	if (!TWIsDSOpen())
	{
		dsID.Id = 0;
		dsID.ProductName[0] = 0;
		appID.Id = 0;	
	}
	/*
	* Open DSM
	*/
	if (TWOpenDSM( NULL ) != TRUE)
	{
		return(FALSE); // error
	}
	/*
	* Open DS
	*/
	if (TWOpenDS() != TRUE)
	{
		return(FALSE); // error
	}

	ptwCapability->Cap = cap;
	ptwCapability->ConType = TWON_DONTCARE16;
	ptwCapability->hContainer = NULL;

	rc = CallDSMEntry(&appID,
				&dsID,
				DG_CONTROL,
				DAT_CAPABILITY,
				type,
				(TW_MEMREF)ptwCapability);

	if (rc == TWRC_SUCCESS)
	{
		return(TRUE);    
	}
	else
	{      
		memset(string,'\0',sizeof(string));
		lstrcat(string,_T("DG_CONTROL/DAT_CAPABILITY/"));
		if(type == MSG_QUERYSUPPORT)
		{
			lstrcat(string, _T("MSG_QUERYSUPPORT"));
		}    

		return(FALSE);
	}
}

//////////////////////////////////////////////////////////////////////////
// Function: MsgGetCapability --  
// Author: TWAIN Working Group
// Input:
//		cap -
//		type - 
//		ptwCapability
// Output:
//		TRUE is successful
// Comments:
//		Sends one of the three GET triplets to the 
// source and returns the TW_CAPABILITY structure to the caller as a 
// parameter.  If the DSM_Entry call fails, FALSE is returned 
//
BOOL MsgGetCapability(TW_UINT16 cap,TW_UINT16 type, pTW_CAPABILITY ptwCapability)
{
	TW_INT16 rc = TWRC_FAILURE;
	TCHAR string[50];

	memset(string, 0, sizeof(TCHAR[50]));

	ASSERT(ptwCapability);

	//	Setup dsID for default Source                             
	if (!TWIsDSOpen())
	{
		dsID.Id = 0;
		dsID.ProductName[0] = 0;
		appID.Id = 0;	
	}
	//	Open DSM
	if (TWOpenDSM(NULL) != TRUE)
	{
		return(FALSE);
	}
	//	Open DS
	if (TWOpenDS() != TRUE)
	{
		return(FALSE);
	}

	ptwCapability->Cap = cap;
	ptwCapability->ConType = TWON_DONTCARE16;
	ptwCapability->hContainer = NULL;


	rc = CallDSMEntry(&appID,
				&dsID,
				DG_CONTROL,
				DAT_CAPABILITY,
				type,
				(TW_MEMREF)ptwCapability);

	if (rc == TWRC_SUCCESS)
	{
		return(TRUE);    
	}
	else
	{      
		memset(string,'\0',sizeof(string));
		lstrcat(string,_T("DG_CONTROL/DAT_CAPABILITY/"));
		switch(type)
		{
			case MSG_GET:
				lstrcat(string,_T("MSG_GET"));
				break;
			case MSG_GETDEFAULT:
				lstrcat(string,_T("MSG_GETDEFAULT"));
				break;
			case MSG_GETCURRENT:            
				lstrcat(string,_T("MSG_GETCURRENT"));
				break;
			default:
				break;
		}    

		// Error message using condition state of the Source
		return(FALSE);
	}
}

//////////////////////////////////////////////////////////////////////////
// Function: MsgSetCapability --  
// Author: TWAIN Working Group
// Input:
//		cap -
//		type - 
//		ptwCapability
// Output:
//		TRUE is successful
// Comments:
//		Sends one of the two SET triplets to the 
// source and returns the TW_CAPABILITY structure to the caller as a 
// parameter.  If the DSM_Entry call fails, FALSE is returned. 
//
BOOL MsgSetCapability(TW_UINT16 cap,TW_UINT16 type, pTW_CAPABILITY ptwCapability)
{
	TW_INT16 rc = TWRC_FAILURE;
	TCHAR string[50];

	memset(string, 0, sizeof(TCHAR[50]));

	ASSERT(ptwCapability);

	//	Setup dsID for default Source                             
	if (!TWIsDSOpen())
	{
		dsID.Id = 0;
		dsID.ProductName[0] = 0;
		appID.Id = 0;	//Why do this?
	}
	//	Open DSM
	if (TWOpenDSM(NULL) != TRUE)
	{
		return(FALSE);
	}
	//	Open DS
	if (TWOpenDS() != TRUE)
	{
		return(FALSE);
	}

	if (type == MSG_RESET)
	{
		ptwCapability->Cap = cap;
		ptwCapability->ConType = TWON_DONTCARE16;
		ptwCapability->hContainer = NULL;
	}

	rc = CallDSMEntry(&appID,
				&dsID,
				DG_CONTROL,
				DAT_CAPABILITY,
				type,
				(TW_MEMREF)ptwCapability);

	if (rc == TWRC_SUCCESS)
	{
		return(TRUE);    
	}
	else
	{      
		memset(string,'\0',sizeof(string));
		lstrcat(string,_T("DG_CONTROL/DAT_CAPABILITY/"));
		switch(type)
		{
			case MSG_SET:
				lstrcat(string,_T("MSG_SET"));
				break;
			case MSG_RESET:
				lstrcat(string,_T("MSG_RESET"));
				break;
			default:
				break;
		}    

		return(FALSE);
	}
}