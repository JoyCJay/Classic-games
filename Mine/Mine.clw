; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHeroDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mine.h"
LastPage=0

ClassCount=5
Class1=CHelpDlg
Class2=CHeroDlg
Class3=CMineApp
Class4=CAboutDlg
Class5=CMineDlg

ResourceCount=5
Resource1=IDD_MINE_DIALOG
Resource2=IDD_HELP_DLG
Resource3=IDD_HERO_LIST
Resource4=IDD_ABOUTBOX
Resource5=IDR_MAIN_MENU

[CLS:CHelpDlg]
Type=0
BaseClass=CDialog
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp

[CLS:CHeroDlg]
Type=0
BaseClass=CDialog
HeaderFile=HeroDlg.h
ImplementationFile=HeroDlg.cpp

[CLS:CMineApp]
Type=0
BaseClass=CWinApp
HeaderFile=Mine.h
ImplementationFile=Mine.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MineDlg.cpp
ImplementationFile=MineDlg.cpp
LastObject=CAboutDlg

[CLS:CMineDlg]
Type=0
BaseClass=CDialog
HeaderFile=MineDlg.h
ImplementationFile=MineDlg.cpp

[DLG:IDD_HELP_DLG]
Type=1
Class=CHelpDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=65535,button,1342177287
Control3=65535,static,1342308352

[DLG:IDD_HERO_LIST]
Type=1
Class=CHeroDlg
ControlCount=6
Control1=IDOK_BTN,button,1342242817
Control2=65535,static,1342308864
Control3=IDC_NAME_EDIT,edit,1350631553
Control4=65535,static,1342308864
Control5=IDC_TIME_EDIT,edit,1350633601
Control6=65535,button,1342177287

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MINE_DIALOG]
Type=1
Class=CMineDlg
ControlCount=0

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=IDR_START_GAME
Command2=IDR_EXIT_GAME
Command3=IDR_PLAY_MUSIC
Command4=IDR_HELP
Command5=IDR_ABOUT
CommandCount=5

