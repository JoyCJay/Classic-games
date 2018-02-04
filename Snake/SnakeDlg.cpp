// SnakeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeDlg.h"

#include "HelpDlg.h"
#include "HeroDlg.h"

#include <mmsystem.h>

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
// CSnakeDlg dialog

CSnakeDlg::CSnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnakeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSnakeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnakeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSnakeDlg, CDialog)
	//{{AFX_MSG_MAP(CSnakeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_UPDATE_COMMAND_UI(IDR_PLAY_MUSIC, OnUpdatePlayMusic)
	ON_UPDATE_COMMAND_UI(IDR_HIGH, OnUpdateHigh)
	ON_UPDATE_COMMAND_UI(IDR_LOW, OnUpdateLow)
	ON_UPDATE_COMMAND_UI(IDR_NOR, OnUpdateNor)
	ON_UPDATE_COMMAND_UI(IDR_HELP, OnUpdateHelp)
	ON_UPDATE_COMMAND_UI(IDR_HERO_LIST, OnUpdateHeroList)
	ON_UPDATE_COMMAND_UI(IDR_EXIT_GAME, OnUpdateExitGame)
	ON_UPDATE_COMMAND_UI(IDR_ABOUT, OnUpdateAbout)
	ON_UPDATE_COMMAND_UI(IDR_START_GAME, OnUpdateStartGame)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeDlg message handlers

BOOL CSnakeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();			//�Ի����ʼ��

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


	SetIcon(m_hIcon, TRUE);			//���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		//����Сͼ��

	m_main_menu.LoadMenu(IDR_MAIN_MENU);
	
	SetMenu(&m_main_menu);

	InitMenu();

	m_snake.CreateEx( WS_EX_CLIENTEDGE, _T("SNAKEMAP"), NULL, WS_VISIBLE | WS_BORDER | WS_CHILD,
        CRect( 0, 0, 325, 425 ), this, SNAKEMAP );
	
	GetDlgItem( SNAKEMAP )->SetFocus();
	
	return TRUE; 
}

void CSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSnakeDlg::OnPaint() 
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
}

HCURSOR CSnakeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSnakeDlg::InitMenu()
{//��ʼ���˵�
	m_main_menu.CheckMenuItem(IDR_LOW, MF_BYCOMMAND | MF_CHECKED);
	m_main_menu.CheckMenuItem(IDR_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
	m_main_menu.CheckMenuItem(IDR_NOR, MF_BYCOMMAND | MF_UNCHECKED);
	m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_UNCHECKED);
	m_bStart = FALSE;
	m_snake.SetGameLevel(GAME_LEVEL_LOW);
}
//�������� �˵�����Ӧ����
void CSnakeDlg::OnUpdatePlayMusic(CCmdUI* pCmdUI) 
{//�жϲ������ֲ˵���ǰ״̬
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_PLAY_MUSIC, MF_CHECKED);

	if(m_bStart)
	{
		if(bCheck)
		{
			m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_UNCHECKED);
		}
		else
		{
			m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, MF_BYCOMMAND | MF_CHECKED);
		}
		
		PlayBackMusic(!bCheck);			//���ò��ű������ֹ��ܺ���
	}

}
//"��Ϸ�ȼ�"|"��"�˵�����Ӧ����
void CSnakeDlg::OnUpdateHigh(CCmdUI* pCmdUI) 
{//�жϵ�ǰ�˵�״̬
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_HIGH, MF_CHECKED);
    
	if(!m_bStart)
	{
		if( !bCheck )
		{
			m_snake.SetGameLevel(GAME_LEVEL_HIGH);
			m_main_menu.CheckMenuItem(IDR_HIGH, MF_BYCOMMAND | MF_CHECKED);
			m_main_menu.CheckMenuItem(IDR_LOW,  MF_BYCOMMAND | MF_UNCHECKED);
			m_main_menu.CheckMenuItem(IDR_NOR,  MF_BYCOMMAND | MF_UNCHECKED);
		}
	}

	Invalidate();
}
//"��Ϸ�ȼ�"|"��"�˵�����Ӧ����
void CSnakeDlg::OnUpdateLow(CCmdUI* pCmdUI) 
{//�жϵ�ǰ�˵�״̬
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_LOW, MF_CHECKED);
    if(!m_bStart)
	{
		if( !bCheck )
		{
			m_snake.SetGameLevel(GAME_LEVEL_LOW);
			m_main_menu.CheckMenuItem(IDR_LOW,  MF_BYCOMMAND | MF_CHECKED);
			m_main_menu.CheckMenuItem(IDR_NOR,  MF_BYCOMMAND | MF_UNCHECKED);
			m_main_menu.CheckMenuItem(IDR_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
		}
	}

	Invalidate();
		
}
//"��Ϸ�ȼ�"|"��"�˵�����Ӧ����
void CSnakeDlg::OnUpdateNor(CCmdUI* pCmdUI) 
{//�жϵ�ǰ�˵�״̬
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_NOR, MF_CHECKED);
    
	if(!m_bStart)
	{
		if( !bCheck )
		{
			m_snake.SetGameLevel(GAME_LEVEL_NOR);
			m_main_menu.CheckMenuItem(IDR_NOR,  MF_BYCOMMAND | MF_CHECKED);
			m_main_menu.CheckMenuItem(IDR_LOW,  MF_BYCOMMAND | MF_UNCHECKED);
			m_main_menu.CheckMenuItem(IDR_HIGH, MF_BYCOMMAND | MF_UNCHECKED);
		}
	}
	Invalidate();
}
//"��Ϸ����"�˵�����Ӧ����
void CSnakeDlg::OnUpdateHelp(CCmdUI* pCmdUI) 
{
	Help();				//���ð������ܺ���
}
//"����"�˵�����Ӧ����
void CSnakeDlg::OnUpdateAbout(CCmdUI* pCmdUI) 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();//�������ڶԻ���
}
//"Ӣ�۰�"�˵�����Ӧ����
void CSnakeDlg::OnUpdateHeroList(CCmdUI* pCmdUI) 
{
	HeroList();			//����Ӣ�۰��ܺ���
}
//"�˳�"�˵�����Ӧ����
void CSnakeDlg::OnUpdateExitGame(CCmdUI* pCmdUI) 
{
	CDialog::OnCancel();//�˳��Ի����ܺ���	
}
//"��ʼ��Ϸ"�˵�����Ӧ����
void CSnakeDlg::OnUpdateStartGame(CCmdUI* pCmdUI) 
{
	m_snake.GameStart();		//���ÿ�ʼ����Ϸ���ܺ���
}

void CSnakeDlg::PlayBackMusic(BOOL bflg)
{
	//ָ���ļ�������
	if(bflg)
	{
		sndPlaySound("music.wav",SND_ASYNC);//��������
	}
	else
	{
		sndPlaySound(NULL,SND_PURGE);//ֹͣ����
	}
}

void CSnakeDlg::HeroList()
{
	CHeroDlg dlg;
	dlg.DoModal();
}

void CSnakeDlg::Help()
{
	CHelpDlg dlg;
	dlg.DoModal();
}

void CSnakeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}

void CSnakeDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
