# Microsoft Developer Studio Project File - Name="cgUI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=cgUI - Win32 Unicode NoCommDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cgUI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cgUI.mak" CFG="cgUI - Win32 Unicode NoCommDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cgUI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 NoCommRelease" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 NoCommDebug" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 Unicode NoCommDebug" (based on "Win32 (x86) Application")
!MESSAGE "cgUI - Win32 Unicode NoCommRelease" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cgUI - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 wininet.lib dplayx.lib dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe"
# SUBTRACT LINK32 /verbose /incremental:yes /nodefaultlib

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /Gi /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x411 /i "d:\sdk\include" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ws2_32.lib wininet.lib dplayx.lib dxguid.lib Imm32.lib mpr.lib shell32.lib /version:3.0 /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe" /pdbtype:sept
# SUBTRACT LINK32 /nologo /profile

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cgUI___Win32_NoCommRelease"
# PROP BASE Intermediate_Dir "cgUI___Win32_NoCommRelease"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NoCommRelease"
# PROP Intermediate_Dir "NoCommRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib dxguid.lib dplayx.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /verbose /incremental:yes /debug /nodefaultlib
# ADD LINK32 dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /subsystem:windows /machine:I386 /out:"D:\_KentWork\CGUI\NoCommRelease\alpha.exe"
# SUBTRACT LINK32 /verbose /incremental:yes /debug /nodefaultlib

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cgUI___Win32_NoCommDebug"
# PROP BASE Intermediate_Dir "cgUI___Win32_NoCommDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoCommDebug"
# PROP Intermediate_Dir "NoCommDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /i "d:\sdk\include" /d "_DEBUG"
# ADD RSC /l 0x409 /i "d:\sdk\include" /d "_DEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ws2_32.lib wininet.lib dxguid.lib dplayx.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT BASE LINK32 /profile
# ADD LINK32 dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /subsystem:windows /debug /machine:I386 /out:"D:\_KentWork\CGUI\NoCommDebug\alpha.exe" /pdbtype:sept
# SUBTRACT LINK32 /profile /incremental:no

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cgUI___Win32_Unicode_Debug"
# PROP BASE Intermediate_Dir "cgUI___Win32_Unicode_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_Debug"
# PROP Intermediate_Dir "Unicode_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /i "d:\sdk\include" /d "_DEBUG"
# ADD RSC /l 0x409 /i "d:\sdk\include" /d "_DEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ws2_32.lib wininet.lib dxguid.lib dplayx.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT BASE LINK32 /profile
# ADD LINK32 ws2_32.lib wininet.lib dplayx.lib dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe" /pdbtype:sept /libpath:"D:\_KentWork\cgUI\cgUI_Lib"
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cgUI___Win32_Unicode_Release"
# PROP BASE Intermediate_Dir "cgUI___Win32_Unicode_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_Release"
# PROP Intermediate_Dir "Unicode_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib dxguid.lib dplayx.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /verbose /incremental:yes /debug /nodefaultlib
# ADD LINK32 dplayx.lib dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe"
# SUBTRACT LINK32 /verbose /incremental:yes /nodefaultlib

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cgUI___Win32_Unicode_NoCommDebug"
# PROP BASE Intermediate_Dir "cgUI___Win32_Unicode_NoCommDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Unicode_NoCommDebug"
# PROP Intermediate_Dir "Unicode_NoCommDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "d:\sdk\include" /d "_DEBUG"
# ADD RSC /l 0x409 /i "d:\sdk\include" /d "_DEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 dxguid.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT BASE LINK32 /profile
# ADD LINK32 shell32.lib dxguid.lib Imm32.lib mpr.lib /nologo /version:2.0 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe" /pdbtype:sept
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cgUI___Win32_Unicode_NoCommRelease"
# PROP BASE Intermediate_Dir "cgUI___Win32_Unicode_NoCommRelease"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Unicode_NoCommRelease"
# PROP Intermediate_Dir "Unicode_NoCommRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# SUBTRACT BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 dxguid.lib Imm32.lib mpr.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /verbose /incremental:yes /debug /nodefaultlib
# ADD LINK32 dxguid.lib Imm32.lib mpr.lib shell32.lib /nologo /version:2.0 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"c:\acg_code\cgui\alpha.exe"
# SUBTRACT LINK32 /verbose /incremental:yes /nodefaultlib

!ENDIF 

# Begin Target

# Name "cgUI - Win32 Release"
# Name "cgUI - Win32 Debug"
# Name "cgUI - Win32 NoCommRelease"
# Name "cgUI - Win32 NoCommDebug"
# Name "cgUI - Win32 Unicode Debug"
# Name "cgUI - Win32 Unicode Release"
# Name "cgUI - Win32 Unicode NoCommDebug"
# Name "cgUI - Win32 Unicode NoCommRelease"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AcgMsgBox.cpp
# End Source File
# Begin Source File

SOURCE=.\AddPic.cpp
# End Source File
# Begin Source File

SOURCE=.\AlphaDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribBox.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribCurve.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribFill.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribImport.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribLine.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribOval.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribPolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\AttribText.cpp
# End Source File
# Begin Source File

SOURCE=.\Baseline.cpp
# End Source File
# Begin Source File

SOURCE=.\Captest.cpp
# End Source File
# Begin Source File

SOURCE=.\cgUI.cpp
# End Source File
# Begin Source File

SOURCE=.\cgUI.rc
# End Source File
# Begin Source File

SOURCE=.\cgUIDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\cgUIView.cpp
# End Source File
# Begin Source File

SOURCE=.\CharMap.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\CommDnld.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CommFinder.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CommModem.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\commondialog.cpp
# End Source File
# Begin Source File

SOURCE=.\CommReciver.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CommSender.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Communicate.cpp

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dca_acq.cpp
# End Source File
# Begin Source File

SOURCE=.\Dca_glue.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAttrib.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarBottom.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarCir.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarFbg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarGrd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarLeft.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarLne.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarPal.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBarTopBin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCapPic.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCapture.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCast.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFace.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGetPath.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLayer.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLine.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOutline1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOutline2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPage.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPrefer.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPreset.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgShadow.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTypeFace.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgView.cpp
# End Source File
# Begin Source File

SOURCE=.\EffectBin.cpp
# End Source File
# Begin Source File

SOURCE=.\FileReq.cpp
# End Source File
# Begin Source File

SOURCE=.\FontLocator.cpp
# End Source File
# Begin Source File

SOURCE=.\Global.cpp
# End Source File
# Begin Source File

SOURCE=.\ImgCharMap.cpp
# End Source File
# Begin Source File

SOURCE=.\ImgPalBin.cpp
# End Source File
# Begin Source File

SOURCE=.\IXFontCombo.cpp
# End Source File
# Begin Source File

SOURCE=.\IXMruManager.cpp
# End Source File
# Begin Source File

SOURCE=.\IXTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\IXTipWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSetupDLg.cpp
# End Source File
# Begin Source File

SOURCE=.\PalDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PalSliderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\PgAnnot.cpp
# End Source File
# Begin Source File

SOURCE=.\PgTemplate.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgSetting.cpp
# End Source File
# Begin Source File

SOURCE=.\SpellCheck.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Table.cpp
# End Source File
# Begin Source File

SOURCE=.\TabSetup.cpp
# End Source File
# Begin Source File

SOURCE=.\TabValue.cpp
# End Source File
# Begin Source File

SOURCE=.\TitleVdoSetup.cpp
# End Source File
# Begin Source File

SOURCE=.\Twd_com.cpp
# End Source File
# Begin Source File

SOURCE=.\VMVdoSetup.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AcgMsgBox.h
# End Source File
# Begin Source File

SOURCE=.\AddPic.h
# End Source File
# Begin Source File

SOURCE=.\AlphaDlg.h
# End Source File
# Begin Source File

SOURCE=.\AttribBox.h
# End Source File
# Begin Source File

SOURCE=.\AttribCurve.h
# End Source File
# Begin Source File

SOURCE=.\AttribFill.h
# End Source File
# Begin Source File

SOURCE=.\AttribImport.h
# End Source File
# Begin Source File

SOURCE=.\AttribLine.h
# End Source File
# Begin Source File

SOURCE=.\AttribOval.h
# End Source File
# Begin Source File

SOURCE=.\AttribPolygon.h
# End Source File
# Begin Source File

SOURCE=.\AttribText.h
# End Source File
# Begin Source File

SOURCE=.\Baseline.h
# End Source File
# Begin Source File

SOURCE=.\Captest.h
# End Source File
# Begin Source File

SOURCE=.\ACGS_Inc\CGS_ValDefs.h
# End Source File
# Begin Source File

SOURCE=.\ACGS_Inc\CGServerDll.h
# End Source File
# Begin Source File

SOURCE=.\cgUI.h
# End Source File
# Begin Source File

SOURCE=.\cgUIDoc.h
# End Source File
# Begin Source File

SOURCE=.\cgUIView.h
# End Source File
# Begin Source File

SOURCE=.\CharMap.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\Communicate.h

!IF  "$(CFG)" == "cgUI - Win32 Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommRelease"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 NoCommDebug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cgUI - Win32 Unicode NoCommRelease"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dca_acq.h
# End Source File
# Begin Source File

SOURCE=.\Dca_glue.h
# End Source File
# Begin Source File

SOURCE=.\DlgAttrib.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarBottom.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarCir.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarFbg.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarGrd.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarLeft.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarLne.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarPal.h
# End Source File
# Begin Source File

SOURCE=.\DlgBarTopBin.h
# End Source File
# Begin Source File

SOURCE=.\DlgCapPic.h
# End Source File
# Begin Source File

SOURCE=.\DlgCapture.h
# End Source File
# Begin Source File

SOURCE=.\DlgCast.h
# End Source File
# Begin Source File

SOURCE=.\DlgEffect.h
# End Source File
# Begin Source File

SOURCE=.\DlgFace.h
# End Source File
# Begin Source File

SOURCE=.\DlgFilter.h
# End Source File
# Begin Source File

SOURCE=.\DlgGetPath.h
# End Source File
# Begin Source File

SOURCE=.\DlgLayer.h
# End Source File
# Begin Source File

SOURCE=.\DlgLine.h
# End Source File
# Begin Source File

SOURCE=.\DlgOutline1.h
# End Source File
# Begin Source File

SOURCE=.\DlgOutline2.h
# End Source File
# Begin Source File

SOURCE=.\DlgPage.h
# End Source File
# Begin Source File

SOURCE=.\DlgPrefer.h
# End Source File
# Begin Source File

SOURCE=.\DlgPreset.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelect.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelEffect.h
# End Source File
# Begin Source File

SOURCE=.\DlgShadow.h
# End Source File
# Begin Source File

SOURCE=.\DlgTypeFace.h
# End Source File
# Begin Source File

SOURCE=.\DlgView.h
# End Source File
# Begin Source File

SOURCE=.\EffectBin.h
# End Source File
# Begin Source File

SOURCE=.\FileReq.h
# End Source File
# Begin Source File

SOURCE=.\flatsb.h
# End Source File
# Begin Source File

SOURCE=.\FontLocator.h
# End Source File
# Begin Source File

SOURCE=.\FontPicker.h
# End Source File
# Begin Source File

SOURCE=.\Global.h
# End Source File
# Begin Source File

SOURCE=.\ImgCharMap.h
# End Source File
# Begin Source File

SOURCE=.\ImgPalBin.h
# End Source File
# Begin Source File

SOURCE=.\IXFontCombo.h
# End Source File
# Begin Source File

SOURCE=.\IXMruManager.h
# End Source File
# Begin Source File

SOURCE=.\IXTabCtrl.h
# End Source File
# Begin Source File

SOURCE=.\IXTipWnd.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\PageSetupDLg.h
# End Source File
# Begin Source File

SOURCE=.\PalDlg.h
# End Source File
# Begin Source File

SOURCE=.\PalSliderCtrl.h
# End Source File
# Begin Source File

SOURCE=.\PgAnnot.h
# End Source File
# Begin Source File

SOURCE=.\ProgSetting.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Special.h
# End Source File
# Begin Source File

SOURCE=.\SpellCheck.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Switch.h
# End Source File
# Begin Source File

SOURCE=.\Table.h
# End Source File
# Begin Source File

SOURCE=.\TabSetup.h
# End Source File
# Begin Source File

SOURCE=.\TabValue.h
# End Source File
# Begin Source File

SOURCE=.\TitleVdoSetup.h
# End Source File
# Begin Source File

SOURCE=.\Triplets.h
# End Source File
# Begin Source File

SOURCE=.\Twain.h
# End Source File
# Begin Source File

SOURCE=.\Twd_com.h
# End Source File
# Begin Source File

SOURCE=.\Twd_type.h
# End Source File
# Begin Source File

SOURCE=.\VMVdoSetup.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\3dRotate.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwarro.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwmove.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwnesw.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwns.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwnwse.cur
# End Source File
# Begin Source File

SOURCE=.\res\3dwwe.cur
# End Source File
# Begin Source File

SOURCE=.\res\Alpha.ico
# End Source File
# Begin Source File

SOURCE=.\res\AlphaGRAD.ico
# End Source File
# Begin Source File

SOURCE=.\res\AttribTab.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Back.ico
# End Source File
# Begin Source File

SOURCE=.\res\BackMinus.ico
# End Source File
# Begin Source File

SOURCE=.\res\Bevel.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BLalignbot.ico
# End Source File
# Begin Source File

SOURCE=.\res\BLaligntop.ico
# End Source File
# Begin Source File

SOURCE=.\res\BLcircle.ico
# End Source File
# Begin Source File

SOURCE=.\res\BLcurve.ico
# End Source File
# Begin Source File

SOURCE=.\res\Bld.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BLdefault.ico
# End Source File
# Begin Source File

SOURCE=.\res\bmp64x48.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bold.ico
# End Source File
# Begin Source File

SOURCE=".\res\Box-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Box.ico
# End Source File
# Begin Source File

SOURCE=.\res\browse.ico
# End Source File
# Begin Source File

SOURCE=.\res\cgUI.ico
# End Source File
# Begin Source File

SOURCE=.\res\cgUI.rc2
# End Source File
# Begin Source File

SOURCE=.\res\cgUIDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClrAdd.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClrInv.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClrShft.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClrSpc.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClrSub.ico
# End Source File
# Begin Source File

SOURCE=.\res\Cnt.bmp
# End Source File
# Begin Source File

SOURCE=".\res\curve-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\curve.ico
# End Source File
# Begin Source File

SOURCE=.\res\delete.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirdn.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirdnlft.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirdnrt.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirleft.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirrt.ico
# End Source File
# Begin Source File

SOURCE=.\res\dirup.ico
# End Source File
# Begin Source File

SOURCE=.\res\diruplft.ico
# End Source File
# Begin Source File

SOURCE=.\res\diruprt.ico
# End Source File
# Begin Source File

SOURCE=".\res\ellipse-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\ellipse.ico
# End Source File
# Begin Source File

SOURCE=.\res\Export.ico
# End Source File
# Begin Source File

SOURCE=.\res\Feather.ico
# End Source File
# Begin Source File

SOURCE=.\res\Fheight.ico
# End Source File
# Begin Source File

SOURCE=.\res\filetypes.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FontHeight.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FontWidth.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Formatbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Forward.ico
# End Source File
# Begin Source File

SOURCE=.\res\ForwardPlus.ico
# End Source File
# Begin Source File

SOURCE=.\res\Fwidth.ico
# End Source File
# Begin Source File

SOURCE=.\res\Grid.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\Import.ico
# End Source File
# Begin Source File

SOURCE=.\res\italic.ico
# End Source File
# Begin Source File

SOURCE=.\res\Itl.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Jbot.ico
# End Source File
# Begin Source File

SOURCE=.\res\jctr.ico
# End Source File
# Begin Source File

SOURCE=.\res\jleft.ico
# End Source File
# Begin Source File

SOURCE=.\res\Jmid.ico
# End Source File
# Begin Source File

SOURCE=.\res\jright.ico
# End Source File
# Begin Source File

SOURCE=.\res\Jst.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Jtop.ico
# End Source File
# Begin Source File

SOURCE=.\res\JustBot.bmp
# End Source File
# Begin Source File

SOURCE=.\res\JustCtr.bmp
# End Source File
# Begin Source File

SOURCE=.\res\justify.ico
# End Source File
# Begin Source File

SOURCE=.\res\JustTop.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Kern.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lft.bmp
# End Source File
# Begin Source File

SOURCE=".\res\line-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\line.ico
# End Source File
# Begin Source File

SOURCE=.\res\lite_txt.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Lock.ico
# End Source File
# Begin Source File

SOURCE=.\res\mag.ico
# End Source File
# Begin Source File

SOURCE=.\res\MagMinus.ico
# End Source File
# Begin Source File

SOURCE=.\res\MagPlus.ico
# End Source File
# Begin Source File

SOURCE=.\res\more2.ico
# End Source File
# Begin Source File

SOURCE=.\res\newpage.ico
# End Source File
# Begin Source File

SOURCE=.\res\Offsetx.ico
# End Source File
# Begin Source File

SOURCE=.\res\Offsety.ico
# End Source File
# Begin Source File

SOURCE=.\res\OffSwitch.ico
# End Source File
# Begin Source File

SOURCE=.\res\onswitch.ico
# End Source File
# Begin Source File

SOURCE=.\res\open.ico
# End Source File
# Begin Source File

SOURCE=.\res\palette.bmp
# End Source File
# Begin Source File

SOURCE=.\res\palette.ico
# End Source File
# Begin Source File

SOURCE=.\res\panelBar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PercentH.ico
# End Source File
# Begin Source File

SOURCE=.\res\PercentW.ico
# End Source File
# Begin Source File

SOURCE=.\res\pointer.ico
# End Source File
# Begin Source File

SOURCE=".\res\polygon-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\polygon.ico
# End Source File
# Begin Source File

SOURCE=.\res\printer.bmp
# End Source File
# Begin Source File

SOURCE=.\res\redo.ico
# End Source File
# Begin Source File

SOURCE=.\res\Rotate.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Rotate.ico
# End Source File
# Begin Source File

SOURCE=.\res\Rt.bmp
# End Source File
# Begin Source File

SOURCE=.\res\save.ico
# End Source File
# Begin Source File

SOURCE=.\res\SavePreset.ico
# End Source File
# Begin Source File

SOURCE=.\res\Size.ico
# End Source File
# Begin Source File

SOURCE=.\res\smallcap.ico
# End Source File
# Begin Source File

SOURCE=.\res\Space.ico
# End Source File
# Begin Source File

SOURCE=.\res\Spr4Pt.ico
# End Source File
# Begin Source File

SOURCE=.\res\SprCirc.ico
# End Source File
# Begin Source File

SOURCE=.\res\SprLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\SprSol.ico
# End Source File
# Begin Source File

SOURCE=.\res\Sub.ico
# End Source File
# Begin Source File

SOURCE=.\res\Super.ico
# End Source File
# Begin Source File

SOURCE=.\res\tabImage.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Text-dn.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Text.ico
# End Source File
# Begin Source File

SOURCE=.\res\textgrap.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TTFlogo.ico
# End Source File
# Begin Source File

SOURCE=.\res\TxGrf.bmp
# End Source File
# Begin Source File

SOURCE=.\res\typedirauto.ico
# End Source File
# Begin Source File

SOURCE=.\res\typedirdn.ico
# End Source File
# Begin Source File

SOURCE=.\res\typedirlr.ico
# End Source File
# Begin Source File

SOURCE=.\res\typedirup.ico
# End Source File
# Begin Source File

SOURCE=.\res\underlin.ico
# End Source File
# Begin Source File

SOURCE=.\res\undo.ico
# End Source File
# Begin Source File

SOURCE=.\res\Undrln.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Unlock.ico
# End Source File
# Begin Source File

SOURCE=.\res\up_right.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\DlgAttrib.ctl
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\cgUI_Lib\ACGS.lib
# End Source File
# Begin Source File

SOURCE=.\cgUI_Lib\zlibstat.lib
# End Source File
# Begin Source File

SOURCE=.\cgUI_Lib\libpng.lib
# End Source File
# End Target
# End Project
# Section cgUI : {083039C2-13F4-11D1-8B7E-0000F8754DA1}
# 	2:5:Class:CCommonDialog1
# 	2:10:HeaderFile:commondialog.h
# 	2:8:ImplFile:commondialog.cpp
# End Section
# Section cgUI : {F9043C85-F6F2-101A-A3C9-08002B2F49FB}
# 	2:21:DefaultSinkHeaderFile:commondialog.h
# 	2:16:DefaultSinkClass:CCommonDialog1
# End Section
# Section cgUI : {BD6D5970-614A-11D2-883C-82729A77E70C}
# 	2:21:DefaultSinkHeaderFile:browsefolder.h
# 	2:16:DefaultSinkClass:CBrowseFolder
# End Section
# Section cgUI : {FE387538-44A3-11D1-B5B7-0000C09000C4}
# 	2:5:Class:CFlatSB
# 	2:10:HeaderFile:flatsb.h
# 	2:8:ImplFile:flatsb.cpp
# End Section
# Section cgUI : {FE38753A-44A3-11D1-B5B7-0000C09000C4}
# 	2:21:DefaultSinkHeaderFile:flatsb.h
# 	2:16:DefaultSinkClass:CFlatSB
# End Section
# Section cgUI : {BD6D596F-614A-11D2-883C-82729A77E70C}
# 	2:5:Class:CBrowseFolder
# 	2:10:HeaderFile:browsefolder.h
# 	2:8:ImplFile:browsefolder.cpp
# End Section
