; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLlkDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "llk.h"
LastPage=0

ClassCount=6
Class1=CHelpDlg
Class2=CHeroDlg
Class3=CLineStatic
Class4=CLlkApp
Class5=CAboutDlg
Class6=CLlkDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_HERO_LIST
Resource3=IDD_HELP
Resource4=IDD_LLK_DIALOG
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

[CLS:CLineStatic]
Type=0
BaseClass=CStatic
HeaderFile=LineStatic.h
ImplementationFile=LineStatic.cpp

[CLS:CLlkApp]
Type=0
BaseClass=CWinApp
HeaderFile=llk.h
ImplementationFile=llk.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=llkDlg.cpp
ImplementationFile=llkDlg.cpp

[CLS:CLlkDlg]
Type=0
BaseClass=CDialog
HeaderFile=llkDlg.h
ImplementationFile=llkDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDR_PLAY_MUSIC

[DLG:IDD_HELP]
Type=1
Class=CHelpDlg
ControlCount=3
Control1=65535,button,1342177287
Control2=65535,static,1342308352
Control3=IDOK,button,1342242816

[DLG:IDD_HERO_LIST]
Type=1
Class=CHeroDlg
ControlCount=6
Control1=IDOK_BTN,button,1342242817
Control2=65535,static,1342308864
Control3=IDC_NAME_EDIT,edit,1350631553
Control4=65535,static,1342308864
Control5=IDC_LEVEL_EDIT,edit,1350633601
Control6=65535,button,1342177287

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LLK_DIALOG]
Type=1
Class=CLlkDlg
ControlCount=3
Control1=IDC_BKPIC,static,1342308352
Control2=IDC_LINE,static,1342308352
Control3=IDC_METHOD,static,1342308352

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=IDR_START_GAME
Command2=IDR_EXIT_GAME
Command3=IDR_PLAY_MUSIC
Command4=IDR_HELP
Command5=IDR_ABOUT
Command6=IDR_HERO_LIST
CommandCount=6

