# Microsoft Developer Studio Project File - Name="ARelogger" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ARelogger - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ARelogger.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ARelogger.mak" CFG="ARelogger - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ARelogger - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ARelogger - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ARelogger - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Distributes/ARelogger.exe"
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=.\IncBuild.exe
# End Special Build Tool

!ELSEIF  "$(CFG)" == "ARelogger - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Distributes/ARelogger.exe" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=.\IncBuild.exe
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "ARelogger - Win32 Release"
# Name "ARelogger - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ARelogger.cpp
# End Source File
# Begin Source File

SOURCE=.\ARelogger.rc
# End Source File
# Begin Source File

SOURCE=.\AReloggerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Bot.cpp
# End Source File
# Begin Source File

SOURCE=.\BotDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BotManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ConfigDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Demonbuddy.cpp
# End Source File
# Begin Source File

SOURCE=.\Diablo3.cpp
# End Source File
# Begin Source File

SOURCE=.\Languages.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginFailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogWriter.cpp
# End Source File
# Begin Source File

SOURCE=.\NewPwdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PwdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Version.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ARelogger.h
# End Source File
# Begin Source File

SOURCE=.\AReloggerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Bot.h
# End Source File
# Begin Source File

SOURCE=.\BotDlg.h
# End Source File
# Begin Source File

SOURCE=.\BotManager.h
# End Source File
# Begin Source File

SOURCE=.\ConfigDlg.h
# End Source File
# Begin Source File

SOURCE=.\Constants.h
# End Source File
# Begin Source File

SOURCE=.\Demonbuddy.h
# End Source File
# Begin Source File

SOURCE=.\Diablo3.h
# End Source File
# Begin Source File

SOURCE=.\Languages.h
# End Source File
# Begin Source File

SOURCE=.\LoginFailDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogWriter.h
# End Source File
# Begin Source File

SOURCE=.\NewPwdDlg.h
# End Source File
# Begin Source File

SOURCE=.\PwdDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ARelogger.ico
# End Source File
# Begin Source File

SOURCE=.\res\ARelogger.rc2
# End Source File
# Begin Source File

SOURCE=.\res\bot_img.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hdr_img.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pause.ico
# End Source File
# Begin Source File

SOURCE=.\res\start.ico
# End Source File
# Begin Source File

SOURCE=.\res\stop.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# End Group
# Begin Group "Includes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Includes\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\Includes\BrowseCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\BrowseCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Includes\EditEx.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\EditEx.h
# End Source File
# Begin Source File

SOURCE=.\Includes\Ini.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\Ini.h
# End Source File
# Begin Source File

SOURCE=.\Includes\ListCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\ListCtrlEx.h
# End Source File
# Begin Source File

SOURCE=.\Includes\MD5.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\MD5.h
# End Source File
# Begin Source File

SOURCE=.\Includes\PopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\PopupMenu.h
# End Source File
# Begin Source File

SOURCE=.\Includes\Process.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\Process.h
# End Source File
# Begin Source File

SOURCE=.\Includes\ReadOnlyEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\ReadOnlyEdit.h
# End Source File
# Begin Source File

SOURCE=.\Includes\SystemTray.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\SystemTray.h
# End Source File
# Begin Source File

SOURCE=.\Includes\TextCrypto.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\TextCrypto.h
# End Source File
# Begin Source File

SOURCE=.\Includes\Thread.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\Thread.h
# End Source File
# Begin Source File

SOURCE=.\Includes\TickThread.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\TickThread.h
# End Source File
# Begin Source File

SOURCE=.\Includes\UTF8File.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\UTF8File.h
# End Source File
# Begin Source File

SOURCE=.\Includes\WinAppEx.cpp
# End Source File
# Begin Source File

SOURCE=.\Includes\WinAppEx.h
# End Source File
# End Group
# Begin Group "Locales"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Locales\Chinese_Simplified.cpp
# End Source File
# Begin Source File

SOURCE=.\Locales\Chinese_Traditional.cpp
# End Source File
# Begin Source File

SOURCE=.\Locales\English.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\Admin.manifest
# End Source File
# Begin Source File

SOURCE=.\res\ARelogger.exe.manifest
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
