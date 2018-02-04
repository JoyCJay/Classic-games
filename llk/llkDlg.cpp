// llkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "llk.h"
#include "llkDlg.h"

#include "HeroDlg.h"
#include "HelpDlg.h"

#include <mmsystem.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDC_BLOCK 2000 
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
// CLlkDlg dialog

CLlkDlg::CLlkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLlkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLlkDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLlkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLlkDlg)
	DDX_Control(pDX, IDC_METHOD, m_method);
	DDX_Control(pDX, IDC_LINE, m_line);
	DDX_Control(pDX, IDC_BKPIC, m_bkPic);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLlkDlg, CDialog)
	//{{AFX_MSG_MAP(CLlkDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDR_ABOUT, OnAbout)
	ON_COMMAND(IDR_EXIT_GAME, OnExitGame)
	ON_COMMAND(IDR_HELP, OnHelp)
	ON_COMMAND(IDR_HERO_LIST, OnHeroList)
	ON_COMMAND(IDR_PLAY_MUSIC, OnPlayMusic)
	ON_COMMAND(IDR_START_GAME, OnStartGame)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLlkDlg message handlers

BOOL CLlkDlg::OnInitDialog()
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
	
	m_main_menu.LoadMenu(IDR_MAIN_MENU);
	
	SetMenu(&m_main_menu);

	m_nLevel = 1;

	SetWindowPos(NULL, 100, 100, 800, 600, SWP_SHOWWINDOW|SWP_NOZORDER);
	m_method.SetWindowPos(NULL, 300, 500, 200, 25, SWP_SHOWWINDOW|SWP_NOZORDER);
	m_bkPic.SetWindowPos(NULL, 130, 70, 480, 280, SWP_SHOWWINDOW|SWP_NOZORDER);
	m_line.SetWindowPos(NULL, 90, 30, 560, 360, SWP_SHOWWINDOW|SWP_NOZORDER);
	
	m_MsgRgn.CreateRectRgn(150, 20, 550, 40);
	
	m_bStart = false;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLlkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLlkDlg::OnPaint() 
{
	CDialog::OnPaint();
}

HCURSOR CLlkDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLlkDlg::OnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CLlkDlg::OnExitGame() 
{
	CDialog::OnCancel();
}

void CLlkDlg::OnHelp() 
{
	CHelpDlg dlg;
	dlg.DoModal();
}

void CLlkDlg::OnHeroList() 
{
	CHeroDlg dlg;
	dlg.DoModal();
}

void CLlkDlg::OnPlayMusic() 
{
	
	//判断播放音乐菜单当前状态
	BOOL bCheck = (BOOL)m_main_menu.GetMenuState(IDR_PLAY_MUSIC, MF_CHECKED);
	
	if(m_bStart)
	{							//游戏如果开始才允许播放音乐
		if(bCheck)
		{
			m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC,
				MF_BYCOMMAND | MF_UNCHECKED);
		}
		else
		{
			m_main_menu.CheckMenuItem(IDR_PLAY_MUSIC, 
				MF_BYCOMMAND | MF_CHECKED);
		}
		
		PlayBackMusic(!bCheck);		//调用播放背景音乐功能函数
	}
}

void CLlkDlg::OnStartGame() 
{
	char pszTmp[128] = {0};

	m_hintNum = 3;
	m_exchangeNum = 3;
	m_line.m_lineNum = 0;

	m_method.SetWindowText("开 始 游 戏!");

	Start(1);

	GetPrivateProfileString("HERO", "level", "1", 
			pszTmp, 127, ".\\setup.ini");
	m_nHighLevel = atoi(pszTmp);
}
//////////////////////////////////////////////////////////////////////////
//播放背景音乐
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::PlayBackMusic(BOOL bflag)
{
	//指定文件并播放
	if(bflag)
	{								//播放音乐
		sndPlaySound("music.wav",SND_ASYNC); 
	}
	else
	{								//停止播放
		sndPlaySound(NULL,SND_PURGE); 
	}
}
//////////////////////////////////////////////////////////////////////////
//游戏开始
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::Start(int level)
{
	CString str;

	m_nLevel = level;
	
	m_timePoint = 130 - level * 10;	//设置每个等级的限制时间
	
	//随机设置背景图片
	srand((unsigned int)time(NULL));
	str.Format("res\\b%d.bmp", m_nLevel);
	m_bkPic.ModifyStyle(0,SS_BITMAP|SS_CENTERIMAGE);    
	HBITMAP m_bkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE); 
	m_bkPic.SetBitmap(m_bkBmp);
	
	InitMap(map);

	ShowMap(map);

	m_p = NULL;
	CRgn rgn;
	rgn.CreateRectRgn(420, 0, 560, 160);
	m_MsgRgn.CopyRgn(&rgn);

	ShowMsg(&m_MsgRgn);

	//设置计时器
	KillTimer(1);
	SetTimer(1, 1000, NULL);
	m_bStart = true;
}
//////////////////////////////////////////////////////////////////////////
//信息显示
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::ShowMsg(CRgn *rgn)
{
	CClientDC *pDC = (CClientDC *)GetDC();	

//	int nOldDC = pDC->SaveDC();
	
	CFont font; 

	CString str;
	//设置字体
	if(0==font.CreatePointFont(150,"Comic Sans MS"))
	{
		AfxMessageBox("Can't Create Font");
	}
	pDC->SelectObject(&font);
	//设置字体颜色及其背景颜色
	pDC->SetTextColor(RGB(39,244,10));
	pDC->SetBkColor(RGB(0,0,0));
    //输出数字
	str.Format("游戏等级: %d",m_nLevel);
	pDC->TextOut(650,420,str);

	str.Format("剩余时间: %03d", m_timePoint);
	pDC->TextOut(650, 450, str);

	str.Format("提示次数: %d",m_hintNum);	
	pDC->TextOut(650,480,str);
	
	str.Format("换盘次数: %d", m_exchangeNum);
	pDC->TextOut(650, 510, str);

	
}
//////////////////////////////////////////////////////////////////////////
//初始化棋盘数组
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::InitMap(int map[][MAXY])
{
	int i, j;
	int x, y;
	
	//初始化边界
	for(i=0; i<MAXX; i++)
	{
		for(j=0; j<MAXY; j++)
		{
			if((i==0) || (i==MAXX-1) || (j==0) || (j==MAXY-1))
			{
				map[i][j] = -1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}
	srand((unsigned int)time(NULL));//随机数种子
	
	//初始化地图
	for(i=0; i<SAME; i++)
	{
		for(j=1; j<=TYPENUM; j++)
		{
			x = rand()%MAXX;
			y = rand()%MAXY;
			if(map[x][y])
			{
				j--;
			}
			else
			{
				map[x][y] = j;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//转换棋盘数组的中数据为棋子并显示出来
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::ShowMap(int map[][MAXY])
{
	this->Invalidate();
	int i, j;
	POINT p;
	CString str;
	
	//清除原有按钮
	for(i=0; i<m_cmGroup.GetSize(); i++)
		delete (CChessMan *)m_cmGroup.GetAt(i);
	
	m_cmGroup.RemoveAll();
	for(i=1; i<MAXX-1; i++)
	{
		for(j=1; j<MAXY-1; j++)
		{
			p.x = i;
			p.y = j;
			m_cmGroup.Add(new CChessMan(map[i][j], p));
		}
	}
	for(i=0; i<(MAXX-2)*(MAXY-2); i++)
	{
		CChessMan *btn = (CChessMan *)m_cmGroup.GetAt(i);
		
		btn->Create(str, WS_CHILD|BS_BITMAP, //注意属性!!!
			CRect(130+(i%(MAXY-2))*40, 70+(i/(MAXY-2))*40, 170+(i%(MAXY-2))*40, 110+(i/(MAXY-2))*40), this, IDC_BLOCK+i);
		if(btn->m_id)//如果为0则不显示
		{
			str.Format("res\\%d.bmp", btn->m_id);
			HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
			if(m_fkBmp == NULL) 
			{
				if(MessageBox("缺少图片资源!", "错误", MB_ICONERROR|MB_OK) == IDOK)
				{
					CDialog::OnCancel();
					return;
				}
			}	
			btn->SetBitmap(m_fkBmp);
			btn->ShowWindow(SW_SHOW);
		}
		else
		{
			btn->ShowWindow(SW_HIDE);
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//换盘接口成员函数
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::CallExchange()
{
	if(m_exchangeNum)
	{
		do
		Exchange(map);
		while(!CChessMan::Hint(map));//至少有一个可消去
		ShowMap(map);
		m_exchangeNum--;
	}
}
//////////////////////////////////////////////////////////////////////////
//提示连接接口成员函数
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::CallHint()
{
	if(m_hintNum)
	{
		if(CChessMan::Hint(map, &m_hintP1, &m_hintP2))
		{
			CChessMan *temp;
			temp = (CChessMan *)m_cmGroup.GetAt(m_hintP1);
			temp->SetButtonStyle(BS_DEFPUSHBUTTON);
			temp = (CChessMan *)m_cmGroup.GetAt(m_hintP2);
			temp->SetButtonStyle(BS_DEFPUSHBUTTON);
			m_hintNum--;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//换盘函数
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::Exchange(int map[][MAXY])
{
	int i, j;
	int k = 0;
	int temp[(MAXX-2)*(MAXY-2)+1] = {0};//比格子数多一个，防止数组越界!!!
	for(i=1; i<MAXX-1; i++)
	{
		for(j=1; j<MAXY-1; j++)
		{
			if(map[i][j])
			{
				temp[k++] = map[i][j];
				map[i][j] = 0;
			}
		}
	}
	srand((unsigned int)time(NULL));
	k = 0;
	while(temp[k])
	{
		i = rand()%MAXX;
		j = rand()%MAXY;
		if(map[i][j])
			k--;
		else
			map[i][j] = temp[k];
		k++;
	}
}
//////////////////////////////////////////////////////////////////////////
//更新棋盘数组
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::RefreshMap()
{
	CRgn resultRgn;
	resultRgn.CreateRectRgn(90,30,690,430);
	CRgn tmpRgn;
	tmpRgn.CreateRectRgn(0,0,0,0);
	for(int i=0; i<MAXX; i++)
	{
		for(int j=0; j<MAXY; j++)
		{
			CRect rect;
			CRgn srcRgn;
			
			if(map[i][j]==-1 || map[i][j]==0)
			{
				rect.top = 30 + i*40;
				rect.bottom = 70 + i*40;
				rect.left = 90 + j*40;
				rect.right = 130 + j*40;
				
				srcRgn.CreateRectRgnIndirect(&rect);
				//把消去的区域加进来(覆盖原有区域)，以便刷新
				resultRgn.CombineRgn(&srcRgn,&tmpRgn,RGN_OR);
				tmpRgn.CopyRgn(&resultRgn);
			}
		}
	}
	//只刷新被消去的区域，防止界面闪烁
	this->InvalidateRgn(&resultRgn);
}
//////////////////////////////////////////////////////////////////////////
//定时器
//////////////////////////////////////////////////////////////////////////
void CLlkDlg::OnTimer(UINT nIDEvent) 
{
	m_timePoint -= 1;
	if(m_timePoint <= 0)
	{
		KillTimer(1);
		
		int nRet = MessageBox("限 制 时 间 到!", "闯 关 失 败", MB_YESNO|MB_ICONINFORMATION);
		
		if(IDYES == nRet)
		{
			OnStartGame();
		}
		else
		{
			isHighLevel();
			CDialog::OnCancel();
		}
		return;
	}
	
	InvalidateRgn(&m_MsgRgn);

	ShowMsg(&m_MsgRgn);
}
//////////////////////////////////////////////////////////////////////////
//截获用户消息
//////////////////////////////////////////////////////////////////////////
BOOL CLlkDlg::PreTranslateMessage(MSG* pMsg) 
{
	//键盘按下消息
	if(pMsg->message==WM_KEYDOWN)
	{
		switch((int)pMsg->wParam)
		{
		case VK_F5:			//快捷键F5
			CallHint();
			m_line.m_lineNum = 0;
			RefreshMap();
			m_line.Invalidate();
			break;
		case VK_F6:			//快捷键F6
			CallExchange();			
			m_line.m_lineNum = 0;
			RefreshMap();
			m_line.Invalidate();
			break;
		default:
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CLlkDlg::isHighLevel()
{
	if(m_nHighLevel<m_nLevel)
	{
		CHeroDlg dlg;
		dlg.m_level = m_nLevel;
		dlg.SetWriteFlg(TRUE);
		dlg.DoModal();
	}
}
