; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTetrisView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Tetris.h"
LastPage=0

ClassCount=8
Class1=CTetrisApp
Class2=CTetrisDoc
Class3=CTetrisView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_HELP
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CHelpDlg
Resource3=IDR_MAINFRAME
Class7=CHeroDlg
Resource4=IDD_HERO_LIST
Class8=CLevelDlg
Resource5=IDD_LEVEL_DLG

[CLS:CTetrisApp]
Type=0
HeaderFile=Tetris.h
ImplementationFile=Tetris.cpp
Filter=N

[CLS:CTetrisDoc]
Type=0
HeaderFile=TetrisDoc.h
ImplementationFile=TetrisDoc.cpp
Filter=N

[CLS:CTetrisView]
Type=0
HeaderFile=TetrisView.h
ImplementationFile=TetrisView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CTetrisView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Tetris.cpp
ImplementationFile=Tetris.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDR_START_GAME
Command2=ID_APP_EXIT
Command3=IDR_LEVEL_SETUP
Command4=IDR_PLAY_MUSIC
Command5=IDR_HERO_LIST
Command6=IDR_HELP
Command7=IDR_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_HELP]
Type=1
Class=CHelpDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDOK,button,1342242816
Control5=IDC_STATIC,static,1342308352

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHelpDlg
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
HeaderFile=HeroDlg.h
ImplementationFile=HeroDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHeroDlg

[DLG:IDD_LEVEL_DLG]
Type=1
Class=CLevelDlg
ControlCount=4
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_LEVEL_EDIT,edit,1350631552

[CLS:CLevelDlg]
Type=0
HeaderFile=LevelDlg.h
ImplementationFile=LevelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLevelDlg
VirtualFilter=dWC

