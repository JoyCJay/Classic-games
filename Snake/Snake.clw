; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHeroDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Snake.h"

ClassCount=5
Class1=CSnakeApp
Class2=CSnakeDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HELP_DLG
Resource4=IDD_HERO_LIST
Class4=CHelpDlg
Resource5=IDD_SNAKE_DIALOG
Class5=CHeroDlg
Resource6=IDR_MAIN_MENU

[CLS:CSnakeApp]
Type=0
HeaderFile=Snake.h
ImplementationFile=Snake.cpp
Filter=N

[CLS:CSnakeDlg]
Type=0
HeaderFile=SnakeDlg.h
ImplementationFile=SnakeDlg.cpp
Filter=D
LastObject=CSnakeDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SnakeDlg.h
ImplementationFile=SnakeDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SNAKE_DIALOG]
Type=1
Class=CSnakeDlg
ControlCount=0

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=IDR_START_GAME
Command2=IDR_EXIT_GAME
Command3=IDR_LOW
Command4=IDR_NOR
Command5=IDR_HIGH
Command6=IDR_PLAY_MUSIC
Command7=IDR_HELP
Command8=IDR_ABOUT
Command9=IDR_HERO_LIST
CommandCount=9

[DLG:IDD_HELP_DLG]
Type=1
Class=CHelpDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_HERO_LIST]
Type=1
Class=CHeroDlg
ControlCount=8
Control1=IDOK_BTN,button,1342242817
Control2=IDC_STATIC,static,1342308864
Control3=IDC_NAME_EDIT,edit,1350631553
Control4=IDC_STATIC,static,1342308864
Control5=IDC_SCORE_EDIT,edit,1350633601
Control6=IDC_STATIC,static,1342308864
Control7=IDC_LEVEL_EDIT,edit,1350633601
Control8=IDC_STATIC,button,1342177287

[CLS:CHeroDlg]
Type=0
HeaderFile=herodlg.h
ImplementationFile=herodlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDR_HIGH

