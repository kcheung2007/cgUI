/******************************************************************************************
FileName		    : PlayRegistryConst.h
Version         : $Revision: 4$
Vault File		  : $Archive: \\Source_Server\Software\Shared\UtilConst\UtilConst.VLT\VV3.VVF$
Project  		    : $Project: Utility Constants$
Sub Project     : $Subproject: Utility Constants$
Checked in by	  : $Author: apreston$ 
Locked by	      : $Locker: apreston$
Original Author	: Andy Preston
Purpose		      : Contains standard Registry entries 
Date Of Creation: 7/21/99
Copyright       : Play Incorporated 1999
Modification History :
$Log: 
    4   10/01/99    apreston        Added trinity base reg and uninstall
    3   09/21/99    apreston        Added Some Trinity and mfgtest constants
    2   07/29/99    apreston        Use Brute Force
    1   07/21/99    apreston        Initial Version
$
$NoKeywords$
******************************************************************************************/




#ifndef GXLateRegistry_h
#define GXLateRegistry_h

#include <TCHAR.h>
namespace GXLateReg 
{
/* ==================================================================
   * Description : Following are used by Trinity and Trinity Mfg test
                   programs
   
   * Author : [Andy Preston], Created : [9/21/99 11:03:42 AM]
   ==================================================================*/
const LPCTSTR TrinityBaseReg =_T("Software\\Play\\Trinity");
const LPCTSTR MfgTest = _T("MfgTest");
const LPCTSTR Mfg403 = _T("403");
const LPCTSTR DbgOut = _T("DbgOut");
const LPCTSTR WinHandle = _T("WinHandle");
const LPCTSTR Uninstall = _T("Uninstall");

/* ==================================================================
   * Description : Following are used by GXlate
   
   * Author : [Andy Preston], Created : [9/21/99 11:03:42 AM]
   ==================================================================*/
const LPCTSTR GXLATE_BASE_REG =_T("Software\\Play\\GXLate\\File Formats");
const LPCTSTR GXLATE_BASE_PANEL =_T("Software\\Play\\GXLate\\Panels");
const LPCTSTR DoesLoad = _T("Loads");
const LPCTSTR DoesSave = _T("Saves");
const LPCTSTR DoesMovies = _T("Movie");
const LPCTSTR IntLongText= _T("Int Long Text");
const LPCTSTR DefaultLongText= _T("Default Long Text");
const LPCTSTR Ext = _T("Ext");
const LPCTSTR Friend = _T("Friend");
const LPCTSTR HasFriend = _T("HasFriend");
const LPCTSTR Cache = _T("Cache");
const LPCTSTR Priority = _T("Priority");
const LPCTSTR ID = _T("ID");
const LPCTSTR UseBruteForce = _T("UseBruteForce");
const LPCTSTR OptionStr = _T("PlayGxlateOpt_AP");
const LPCTSTR DefPanelLoc= _T("Default Panel");
const LPCSTR BaseOptPanel= _T("GXLateOpt"); 
const LPCSTR BasePanelExt= _T(".pnl"); 
const LPCSTR GXlateResourceDLL = _T("Gxlate2R");

const int MAX_STRING_LENGTH=_MAX_PATH;
};
#endif
