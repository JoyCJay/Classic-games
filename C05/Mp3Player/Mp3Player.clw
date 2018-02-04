; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMp3PlayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Mp3Player.h"

ClassCount=4
Class1=CMp3PlayerApp
Class2=CMp3PlayerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MP3PLAYER_DIALOG

[CLS:CMp3PlayerApp]
Type=0
HeaderFile=Mp3Player.h
ImplementationFile=Mp3Player.cpp
Filter=N

[CLS:CMp3PlayerDlg]
Type=0
HeaderFile=Mp3PlayerDlg.h
ImplementationFile=Mp3PlayerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Mp3PlayerDlg.h
ImplementationFile=Mp3PlayerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MP3PLAYER_DIALOG]
Type=1
Class=CMp3PlayerDlg
ControlCount=6
Control1=IDC_PROCESS,msctls_trackbar32,1342242840
Control2=IDC_STATIC,static,1342308864
Control3=IDC_PLAY_BTN,button,1342242816
Control4=IDC_PAUSE_BTN,button,1342242816
Control5=IDC_STOP_BTN,button,1342242816
Control6=IDC_OPEN_BTN,button,1342242816

