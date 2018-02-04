#include "stdafx.h"
#include "SnakeGame.h"
#include "Resource.h"
#include "Rule.h"
#include "HeroDlg.h"

CSnakeGame::CSnakeGame()
{
	m_nScore = 0;
	m_psFood.x = 30;
	m_psFood.y = 30;
	m_nHighScore = 0;
}

CSnakeGame::~CSnakeGame()
{
}

// 消息映射表
BEGIN_MESSAGE_MAP( CSnakeGame, CWnd )
//{{AFX_MSG_MAP(CSnakeGame)
ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_KEYUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////
// 初始化果实
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::InitFoods()
{	
	int m_ysX,m_ysY;
	while(1)
	{
		m_ysX=rand()%28;          //随机生成横坐标使其与贪吃蛇的身体可以接上
		m_ysY=rand()%28;          //随机生成纵坐标使其与贪吃蛇的身体可以接上
		for(int i=0;i<=m_body.GetUpperBound();i++)
		{
			CPoint ysPoint1=m_body.GetAt(i);      //获取贪吃蛇的身体坐标
			if(ysPoint1.x!=m_ysX||ysPoint1.y!=m_ysY)//如果身体的横坐标或纵坐标与果实的横纵坐标相同
			{
				m_psFood = CPoint(m_ysX, m_ysY);//将随机出现的坐标记录为果实坐标
				return;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
// 设置游戏等级
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::SetGameLevel(int level)
{
	m_nlevel = level;
}
//////////////////////////////////////////////////////////////////////////
// 开始游戏函数
//////////////////////////////////////////////////////////////////////////
BOOL CSnakeGame::GameStart()
{
	int nSleep = LOW_LEVEL_SLEEP;

	char pszTmp[128] = {0};

	switch(m_nlevel)
	{
	case GAME_LEVEL_HIGH:
		nSleep = HIGH_LEVEL_SLEEP;
		break;
	case GAME_LEVEL_NOR:
		nSleep = NOR_LEVEL_SLEEP;
		break;
	}

	GetPrivateProfileString("HERO", "score", "0", 
		pszTmp, 127, ".\\hero.ini");
	m_nHighScore = atoi(pszTmp);

	SetTimer(1, nSleep, NULL);

	InitGame();

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// 处理WM_PAINT消息
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnPaint()
{
    CPaintDC dc( this );
    CDC MemDC;
    MemDC.CreateCompatibleDC( &dc );
    // 装载背景
    CBitmap bmp;
    CPen pen;
    bmp.LoadBitmap( IDB_BMP_BJ );
    pen.CreatePen( PS_SOLID, 1, 0xff );
    MemDC.SelectObject( &bmp );
    MemDC.SelectObject( &pen );
    MemDC.SetROP2( R2_NOTXORPEN );

	CString ysStr;                            //定义字符串用于显示游戏时间得分等字
	MemDC.SetBkMode(TRANSPARENT);             //设置字体背景
	MemDC.SetTextColor(67);                   //设置字体颜色
	ysStr.Format("当前得分:%d",m_nScore);     //初始化字符串
	MemDC.TextOut(30,50,ysStr);               //输出文本
	switch(m_nlevel)                     //根据等级判断
	{
	case GAME_LEVEL_LOW:                                   //如果是初级
		ysStr.Format("当前等级:  初 级");
		break;
	case GAME_LEVEL_NOR:                                   //如果是中级
		ysStr.Format("当前等级:  中 级");
		break;
	case GAME_LEVEL_HIGH:                                   //如果是高级
		ysStr.Format("当前等级:  高 级");
		break;
	}
	MemDC.TextOut(30,30,ysStr);

	//绘制蛇的样式
	CPen yspen;                          
	yspen.CreatePen(1,1,RGB(255,255,255));   //定义白色画笔绘制蛇的边框
	MemDC.SelectObject(&yspen);                
	CBrush ysbrush;
	//
	int k=m_body.GetUpperBound()+2;         //设置一个变量存储贪吃蛇的身体长度
	if(k<=10)                                 //如果小于10，那么就为绿色
	{
		ysbrush.CreateSolidBrush(RGB(0,255,0)); 
		MemDC.SelectObject(&ysbrush);
		//绘制果实
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else if(k>10&&k<=20)                      //如果在10和20之间，那么就为绿色
	{
		ysbrush.CreateSolidBrush(RGB(0,0,255)); 
		MemDC.SelectObject(&ysbrush);
		//绘制果实
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else if(k>20&&k<=30)                      //如果在20和30之间，那么就为绿色
	{
		ysbrush.CreateSolidBrush(RGB(255,255,0)); 
		MemDC.SelectObject(&ysbrush);
		//绘制果实
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else                                       //其余情况均为红色
	{
		ysbrush.CreateSolidBrush(RGB(255,0,0)); 
		MemDC.SelectObject(&ysbrush);
		//绘制果实
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	//初始化点数组
	for(int i=0;i<=m_body.GetUpperBound();i++)
	{
		CPoint ysPoint=m_body.GetAt(i);		
        MemDC.Rectangle(
			CRect(10+ysPoint.y*10,
			120+ysPoint.x*10,
			10+(ysPoint.y+1)*10,
			120+(ysPoint.x+1)*10)
			);
	}
	
    dc.BitBlt( 0, 0, 325, 425, &MemDC,0, 0, SRCCOPY );

}
//////////////////////////////////////////////////////////////////////////
// 处理按键消息
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
	case VK_UP:                   //按向上键
		m_nDirect=DIREC_UP;       //控制方向变量为DIREC_UP
		break;
	case VK_DOWN:                 //按向下键
		m_nDirect=DIREC_DOWN;     //控制方向变量为DIREC_DOWN
		break;
	case VK_LEFT:                 //按向左键
		m_nDirect=DIREC_LEFT;     //控制方向变量为DIREC_LEFT
		break;
	case VK_RIGHT:                //按向右键
		m_nDirect=DIREC_RIGHT;    //控制方向变量为DIREC_RIGHT
		break;
	default:
		break;
	}
}
//////////////////////////////////////////////////////////////////////////
// 定时器响应函数
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnTimer(UINT nIDEvent) 
{
	CPoint ysPoint=m_body.GetAt(0);     //获取蛇身的第一个点坐标
	BOOL bTag = FALSE;                   //定义判断死亡的变量
	CRule rule;							 //游戏规则类

	switch(m_nDirect)                     //根据键盘按下键来选择蛇移动的方向
	{
	case DIREC_DOWN:                       //方向变量向下
		ysPoint.x++;                      //点纵坐标自加

		break;
	case DIREC_UP:                         //方向变量向上
		ysPoint.x--;                      //点纵坐标自减
		break;
	case DIREC_RIGHT:                      //方向变量向右
		ysPoint.y++;                      //点横坐标自加
		break;
	case DIREC_LEFT:                       //方向变量向左
		ysPoint.y--;                      //点横坐标自减
		break;
	}
	
	if(rule.IsOver(ysPoint, m_body))		//游戏结束
	{
		KillTimer(1);						//关闭定时器

		if(m_nScore > m_nHighScore)			//超过最高分
		{
			HeroWrite();					//写英雄榜
		}
		else
		{
			AfxMessageBox("游戏结束,你的分数太低了,没有能进入英雄榜");
		}
	}
	else
	{
		m_body.InsertAt(0,ysPoint);    //将新点添加到蛇的身体中
		ReDrawBody(ysPoint);           //重绘蛇的身体
		if(ysPoint.x==m_psFood.x&&ysPoint.y==m_psFood.y) //如果蛇的身体与果实坐标重合
		{
			
			int nlen=m_body.GetUpperBound();//获取蛇身体的长度
					
			m_nScore = m_nlevel * (nlen-3);//统计分数
			
			InitFoods();                 //再出现下一个果实
			
			Invalidate();                 //窗口重绘
		}
		else
		{
			CPoint pt=m_body.GetAt(m_body.GetUpperBound());//将最后一个赋给pt
			m_body.RemoveAt(m_body.GetUpperBound());       //将移出最后一个
			ReDrawBody(pt);                                //重新绘制pt这点
		}
	}
}
//////////////////////////////////////////////////////////////////////////
// 初始化游戏
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::InitGame()
{
	m_body.RemoveAll();

	m_body.Add(CPoint(3, 8));
	m_body.Add(CPoint(3, 7));
	m_body.Add(CPoint(3, 6));
	m_body.Add(CPoint(3, 5));

	srand((unsigned)time(NULL)); //初始化随机数生成器
	
	m_nDirect = DIREC_RIGHT;	 //初始时向右
	m_nScore  = 0;				 //初始化分数

	InitFoods();				 //初始化果实函数

	Invalidate();                //重绘窗口
}
//////////////////////////////////////////////////////////////////
//重绘指定点
//////////////////////////////////////////////////////////////////
void CSnakeGame::ReDrawBody(CPoint pt)
{
	InvalidateRect(
		CRect(10+pt.y*10,
		120+pt.x*10,
		10+(pt.y+1)*10,
		120+(pt.x+1)*10)
		);
}
//////////////////////////////////////////////////////////////////////////
// 英雄榜写入及弹出
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::HeroWrite()
{
	CHeroDlg dlg;

	dlg.SetWriteFlg(TRUE);		//设置可标志
	
	dlg.m_level = m_nlevel;		//设置等级
	
	dlg.m_score = m_nScore;		//设置分数
	
	dlg.DoModal();				//弹出对话框
}
