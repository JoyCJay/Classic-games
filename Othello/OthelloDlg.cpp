// OthelloDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Othello.h"
#include "OthelloDlg.h"

#include "HelpDlg.h"

#include <mmsystem.h>

#include "DataStruct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COthelloDlg dialog

COthelloDlg::COthelloDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COthelloDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nBlackCount = 0;
	m_nWhiteCount = 0;
}

void COthelloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COthelloDlg, CDialog)
	//{{AFX_MSG_MAP(COthelloDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDR_ABOUT, OnAbout)
	ON_COMMAND(IDR_EXIT_GAME, OnExitGame)
	ON_COMMAND(IDR_GAME_START, OnGameStart)
	ON_COMMAND(IDR_HELP, OnHelp)
	ON_COMMAND(IDR_LEVEL_HIGH, OnLevelHigh)
	ON_COMMAND(IDR_LEVEL_LOW, OnLevelLow)
	ON_COMMAND(IDR_LEVEL_NOR, OnLevelNor)
	ON_COMMAND(IDR_PLAY_MUSIC, OnPlayMusic)
	ON_BN_CLICKED(IDC_BACK_BTN, OnBackBtn)
	//}}AFX_MSG_MAP
	ON_MESSAGE(UM_RECALC, OnRecalc)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COthelloDlg message handlers

void COthelloDlg::OnRecalc(WPARAM wParam, LPARAM lParam)
{
	CString strStatus;
	CString strCount;
	if(wParam & 0x80000000)
	{
		strStatus.Format(" ���ҵ�һ�����壬�ָ�����!"); 
		
	}
	else
	{
		strStatus.Format("�������룬���!"); 
	}
	strCount.Format(" ����:%02d ", UINT(lParam));
	SetDlgItemText(IDC_STATUS, strStatus); 
	SetDlgItemText(IDC_BLACK_COUNT, strCount);
	strCount.Format(" ����:%02d ", (wParam&0xFFFF));
	SetDlgItemText(IDC_WHITE_COUNT, strCount);
}

BOOL COthelloDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	InitMenu();

	g_iGameLevel = LEVEL_LOW;

	SetDlgItemText(IDC_STATUS, "��ӭ����ڰ���!");

	m_chess.Create(CRect(5,5, 30,30), this, ID_CHESSBOARD);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COthelloDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COthelloDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	CString strCount;
	strCount.Format(" ����:%02d ", m_nBlackCount);
	SetDlgItemText(IDC_BLACK_COUNT, strCount);
	strCount.Format(" ����:%02d ", m_nWhiteCount);
	SetDlgItemText(IDC_WHITE_COUNT, strCount);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COthelloDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COthelloDlg::OnAbout() 
{
	CAboutDlg dlg;			//�������ڶԻ��������
	dlg.DoModal();			//�������ڶԻ���
}

void COthelloDlg::OnExitGame() 
{
	CDialog::OnCancel();	//���û����˳�����
}

void COthelloDlg::OnGameStart() 
{
	GameStart();			//������Ϸ��ʼ�ӿں���	
}

void COthelloDlg::OnHelp() 
{
	CHelpDlg dlg;			//���������Ի��������
	dlg.DoModal();			//���������Ի���
}

void COthelloDlg::OnLevelHigh() 
{
	CWnd*   pMain   =   AfxGetMainWnd();   
	CMenu*   pMenu   =   pMain->GetMenu();
	//�жϲ������ֲ˵���ǰ״̬
	BOOL bCheck = (BOOL)pMenu->GetMenuState(IDR_LEVEL_HIGH, MF_CHECKED);
	
	if( !bCheck )
    {
		pMenu->CheckMenuItem(IDR_LEVEL_HIGH, 
					MF_BYCOMMAND | MF_CHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_LOW,
					MF_BYCOMMAND | MF_UNCHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_NOR, 
					MF_BYCOMMAND | MF_UNCHECKED);
		g_iGameLevel = LEVEL_HIGH;
	}
}

void COthelloDlg::OnLevelLow() 
{
	CWnd*   pMain   =   AfxGetMainWnd();   
	CMenu*   pMenu   =   pMain->GetMenu();
	//�жϲ������ֲ˵���ǰ״̬
	BOOL bCheck = (BOOL)pMenu->GetMenuState(IDR_LEVEL_LOW, MF_CHECKED);
	
	if( !bCheck )
    {
		pMenu->CheckMenuItem(IDR_LEVEL_HIGH, 
			MF_BYCOMMAND | MF_UNCHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_LOW,
			MF_BYCOMMAND | MF_CHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_NOR, 
			MF_BYCOMMAND | MF_UNCHECKED);
		g_iGameLevel = LEVEL_LOW;
	}
}

void COthelloDlg::OnLevelNor() 
{
	CWnd*   pMain   =   AfxGetMainWnd();   
	CMenu*   pMenu   =   pMain->GetMenu();
	//�жϲ������ֲ˵���ǰ״̬
	BOOL bCheck = (BOOL)pMenu->GetMenuState(IDR_LEVEL_NOR, MF_CHECKED);
	
	if( !bCheck )
    {
		pMenu->CheckMenuItem(IDR_LEVEL_HIGH, 
			MF_BYCOMMAND | MF_UNCHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_LOW,
			MF_BYCOMMAND | MF_UNCHECKED);
		pMenu->CheckMenuItem(IDR_LEVEL_NOR, 
			MF_BYCOMMAND | MF_CHECKED);
		g_iGameLevel = LEVEL_NOR;
	}
}

void COthelloDlg::OnPlayMusic() 
{
	CWnd*   pMain   =   AfxGetMainWnd();   
	CMenu*   pMenu   =   pMain->GetMenu();
	//�жϲ������ֲ˵���ǰ״̬
	BOOL bCheck = (BOOL)pMenu->GetMenuState(IDR_PLAY_MUSIC, MF_CHECKED);
	
	if(g_bStart)
	{
		if(bCheck)
		{
			pMenu->CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_UNCHECKED);
		}
		else
		{
			pMenu->CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_CHECKED);
		}
		
		PlayBackMusic(!bCheck);			//���ò��ű������ֹ��ܺ���
	}
	
}

void COthelloDlg::InitMenu()
{
//��ʼ���˵�
	CWnd*   pMain   =   AfxGetMainWnd();   
	CMenu*   pMenu  =   pMain->GetMenu();
	pMenu->CheckMenuItem(IDR_LEVEL_LOW, MF_BYCOMMAND | MF_CHECKED);
	pMenu->CheckMenuItem(IDR_LEVEL_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
	pMenu->CheckMenuItem(IDR_LEVEL_NOR, MF_BYCOMMAND | MF_UNCHECKED);
	pMenu->CheckMenuItem(IDR_PLAY_MUSIC,MF_BYCOMMAND| MF_UNCHECKED);
}

void COthelloDlg::PlayBackMusic(BOOL bCheck)
{
	if(bCheck)
	{								//����ָ�������ļ�
		sndPlaySound("music.wav",SND_ASYNC); 
	}
	else
	{								//ֹͣ����
		sndPlaySound(NULL,SND_PURGE); 
	}
}

void COthelloDlg::GameStart()
{
	m_nBlackCount = 2;
	m_nWhiteCount = 2;
	m_chess.NewGame();
}

void COthelloDlg::OnBackBtn() 
{
	m_chess.MoveBack();
}
