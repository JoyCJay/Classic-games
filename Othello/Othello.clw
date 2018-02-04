; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COthelloDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Othello.h"

ClassCount=3
Class1=COthelloApp
Class2=COthelloDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_OTHELLO_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_HELP
Resource5=IDR_MAIN_MENU

[CLS:COthelloApp]
Type=0
HeaderFile=Othello.h
ImplementationFile=Othello.cpp
Filter=N

[CLS:COthelloDlg]
Type=0
HeaderFile=OthelloDlg.h
ImplementationFile=OthelloDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDR_EXIT_GAME

[CLS:CAboutDlg]
Type=0
HeaderFile=OthelloDlg.h
ImplementationFile=OthelloDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_OTHELLO_DIALOG]
Type=1
Class=COthelloDlg
ControlCount=5
Control1=IDC_STATUS,static,1342312961
Control2=IDC_BLACK_COUNT,static,1342308864
Control3=IDC_WHITE_COUNT,static,1342308864
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BACK_BTN,button,1342242816

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=IDR_GAME_START
Command2=IDR_EXIT_GAME
Command3=IDR_LEVEL_HIGH
Command4=IDR_LEVEL_NOR
Command5=IDR_LEVEL_LOW
Command6=IDR_PLAY_MUSIC
Command7=IDR_HELP
Command8=IDR_ABOUT
CommandCount=8

[DLG:IDD_HELP]
Type=1
Class=?
ControlCount=3
Control1=65535,button,1342177287
Control2=65535,static,1342308352
Control3=IDOK,button,1342242816

