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

// ��Ϣӳ���
BEGIN_MESSAGE_MAP( CSnakeGame, CWnd )
//{{AFX_MSG_MAP(CSnakeGame)
ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_KEYUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////
// ��ʼ����ʵ
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::InitFoods()
{	
	int m_ysX,m_ysY;
	while(1)
	{
		m_ysX=rand()%28;          //������ɺ�����ʹ����̰���ߵ�������Խ���
		m_ysY=rand()%28;          //�������������ʹ����̰���ߵ�������Խ���
		for(int i=0;i<=m_body.GetUpperBound();i++)
		{
			CPoint ysPoint1=m_body.GetAt(i);      //��ȡ̰���ߵ���������
			if(ysPoint1.x!=m_ysX||ysPoint1.y!=m_ysY)//�������ĺ���������������ʵ�ĺ���������ͬ
			{
				m_psFood = CPoint(m_ysX, m_ysY);//��������ֵ������¼Ϊ��ʵ����
				return;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
// ������Ϸ�ȼ�
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::SetGameLevel(int level)
{
	m_nlevel = level;
}
//////////////////////////////////////////////////////////////////////////
// ��ʼ��Ϸ����
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
// ����WM_PAINT��Ϣ
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnPaint()
{
    CPaintDC dc( this );
    CDC MemDC;
    MemDC.CreateCompatibleDC( &dc );
    // װ�ر���
    CBitmap bmp;
    CPen pen;
    bmp.LoadBitmap( IDB_BMP_BJ );
    pen.CreatePen( PS_SOLID, 1, 0xff );
    MemDC.SelectObject( &bmp );
    MemDC.SelectObject( &pen );
    MemDC.SetROP2( R2_NOTXORPEN );

	CString ysStr;                            //�����ַ���������ʾ��Ϸʱ��÷ֵ���
	MemDC.SetBkMode(TRANSPARENT);             //�������屳��
	MemDC.SetTextColor(67);                   //����������ɫ
	ysStr.Format("��ǰ�÷�:%d",m_nScore);     //��ʼ���ַ���
	MemDC.TextOut(30,50,ysStr);               //����ı�
	switch(m_nlevel)                     //���ݵȼ��ж�
	{
	case GAME_LEVEL_LOW:                                   //����ǳ���
		ysStr.Format("��ǰ�ȼ�:  �� ��");
		break;
	case GAME_LEVEL_NOR:                                   //������м�
		ysStr.Format("��ǰ�ȼ�:  �� ��");
		break;
	case GAME_LEVEL_HIGH:                                   //����Ǹ߼�
		ysStr.Format("��ǰ�ȼ�:  �� ��");
		break;
	}
	MemDC.TextOut(30,30,ysStr);

	//�����ߵ���ʽ
	CPen yspen;                          
	yspen.CreatePen(1,1,RGB(255,255,255));   //�����ɫ���ʻ����ߵı߿�
	MemDC.SelectObject(&yspen);                
	CBrush ysbrush;
	//
	int k=m_body.GetUpperBound()+2;         //����һ�������洢̰���ߵ����峤��
	if(k<=10)                                 //���С��10����ô��Ϊ��ɫ
	{
		ysbrush.CreateSolidBrush(RGB(0,255,0)); 
		MemDC.SelectObject(&ysbrush);
		//���ƹ�ʵ
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else if(k>10&&k<=20)                      //�����10��20֮�䣬��ô��Ϊ��ɫ
	{
		ysbrush.CreateSolidBrush(RGB(0,0,255)); 
		MemDC.SelectObject(&ysbrush);
		//���ƹ�ʵ
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else if(k>20&&k<=30)                      //�����20��30֮�䣬��ô��Ϊ��ɫ
	{
		ysbrush.CreateSolidBrush(RGB(255,255,0)); 
		MemDC.SelectObject(&ysbrush);
		//���ƹ�ʵ
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	else                                       //���������Ϊ��ɫ
	{
		ysbrush.CreateSolidBrush(RGB(255,0,0)); 
		MemDC.SelectObject(&ysbrush);
		//���ƹ�ʵ
		MemDC.Rectangle(
			CRect(10+m_psFood.y*10,
			120+m_psFood.x*10,
			10+(m_psFood.y+1)*10,
			120+(m_psFood.x+1)*10)
			);
	}
	//��ʼ��������
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
// ��������Ϣ
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
	case VK_UP:                   //�����ϼ�
		m_nDirect=DIREC_UP;       //���Ʒ������ΪDIREC_UP
		break;
	case VK_DOWN:                 //�����¼�
		m_nDirect=DIREC_DOWN;     //���Ʒ������ΪDIREC_DOWN
		break;
	case VK_LEFT:                 //�������
		m_nDirect=DIREC_LEFT;     //���Ʒ������ΪDIREC_LEFT
		break;
	case VK_RIGHT:                //�����Ҽ�
		m_nDirect=DIREC_RIGHT;    //���Ʒ������ΪDIREC_RIGHT
		break;
	default:
		break;
	}
}
//////////////////////////////////////////////////////////////////////////
// ��ʱ����Ӧ����
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::OnTimer(UINT nIDEvent) 
{
	CPoint ysPoint=m_body.GetAt(0);     //��ȡ����ĵ�һ��������
	BOOL bTag = FALSE;                   //�����ж������ı���
	CRule rule;							 //��Ϸ������

	switch(m_nDirect)                     //���ݼ��̰��¼���ѡ�����ƶ��ķ���
	{
	case DIREC_DOWN:                       //�����������
		ysPoint.x++;                      //���������Լ�

		break;
	case DIREC_UP:                         //�����������
		ysPoint.x--;                      //���������Լ�
		break;
	case DIREC_RIGHT:                      //�����������
		ysPoint.y++;                      //��������Լ�
		break;
	case DIREC_LEFT:                       //�����������
		ysPoint.y--;                      //��������Լ�
		break;
	}
	
	if(rule.IsOver(ysPoint, m_body))		//��Ϸ����
	{
		KillTimer(1);						//�رն�ʱ��

		if(m_nScore > m_nHighScore)			//������߷�
		{
			HeroWrite();					//дӢ�۰�
		}
		else
		{
			AfxMessageBox("��Ϸ����,��ķ���̫����,û���ܽ���Ӣ�۰�");
		}
	}
	else
	{
		m_body.InsertAt(0,ysPoint);    //���µ���ӵ��ߵ�������
		ReDrawBody(ysPoint);           //�ػ��ߵ�����
		if(ysPoint.x==m_psFood.x&&ysPoint.y==m_psFood.y) //����ߵ��������ʵ�����غ�
		{
			
			int nlen=m_body.GetUpperBound();//��ȡ������ĳ���
					
			m_nScore = m_nlevel * (nlen-3);//ͳ�Ʒ���
			
			InitFoods();                 //�ٳ�����һ����ʵ
			
			Invalidate();                 //�����ػ�
		}
		else
		{
			CPoint pt=m_body.GetAt(m_body.GetUpperBound());//�����һ������pt
			m_body.RemoveAt(m_body.GetUpperBound());       //���Ƴ����һ��
			ReDrawBody(pt);                                //���»���pt���
		}
	}
}
//////////////////////////////////////////////////////////////////////////
// ��ʼ����Ϸ
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::InitGame()
{
	m_body.RemoveAll();

	m_body.Add(CPoint(3, 8));
	m_body.Add(CPoint(3, 7));
	m_body.Add(CPoint(3, 6));
	m_body.Add(CPoint(3, 5));

	srand((unsigned)time(NULL)); //��ʼ�������������
	
	m_nDirect = DIREC_RIGHT;	 //��ʼʱ����
	m_nScore  = 0;				 //��ʼ������

	InitFoods();				 //��ʼ����ʵ����

	Invalidate();                //�ػ洰��
}
//////////////////////////////////////////////////////////////////
//�ػ�ָ����
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
// Ӣ�۰�д�뼰����
//////////////////////////////////////////////////////////////////////////
void CSnakeGame::HeroWrite()
{
	CHeroDlg dlg;

	dlg.SetWriteFlg(TRUE);		//���ÿɱ�־
	
	dlg.m_level = m_nlevel;		//���õȼ�
	
	dlg.m_score = m_nScore;		//���÷���
	
	dlg.DoModal();				//�����Ի���
}
