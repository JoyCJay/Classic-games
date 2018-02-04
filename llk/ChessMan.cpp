// CChessMan.cpp : implementation file
//

#include "stdafx.h"
#include "llk.h"
#include "ChessMan.h"
#include "LlkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChessMan
CChessMan::CChessMan()
{
}

CChessMan::CChessMan(int id, POINT pos)
{
	m_id = id;
	m_pos = pos;
}

CChessMan::~CChessMan()
{
}


BEGIN_MESSAGE_MAP(CChessMan, CButton)
	//{{AFX_MSG_MAP(CChessMan)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChessMan message handlers

BOOL CChessMan::FindLine(int map[][MAXY], POINT p1, POINT p2)
{
	int max, min;
	int i;

	if(p1.x == p2.x)
	{
		max = (p1.y>p2.y)?p1.y:p2.y;
		min = (p1.y<p2.y)?p1.y:p2.y;
		if(max == min+1)
		{
			return TRUE;//相邻的两个格子
		}
		for(i=min+1; i<max; i++)
		{
			if((map[p1.x][i]!=0) && (map[p1.x][i]!=-1))
			{
				return FALSE;
			}
		}
		return TRUE;
	}

	if(p1.y == p2.y)
	{
		max = (p1.x>p2.x)?p1.x:p2.x;
		min = (p1.x<p2.x)?p1.x:p2.x;
		if(max == min+1)
		{
			return TRUE;//相邻的两个格子
		}
		for(i=min+1; i<max; i++)
		{
			if((map[i][p1.y]!=0) && (map[i][p1.y]!=-1))
			{
				return FALSE;
			}
		}
		return TRUE;
	}

	return FALSE;
}

BOOL CChessMan::FindCorner(int map[][MAXY], POINT p1, POINT p2)
{
	int maxx, maxy, minx, miny;
	POINT tempPoint = {0};

	//测试矩形格子
	maxx = (p1.x>p2.x)?p1.x:p2.x;
	maxy = (p1.y>p2.y)?p1.y:p2.y;
	minx = (p1.x<p2.x)?p1.x:p2.x;
	miny = (p1.y<p2.y)?p1.y:p2.y;

	if(map[minx][maxy] == 0)
	{
		tempPoint.x = minx;
		tempPoint.y = maxy;
		if((FindLine(map, p1, tempPoint)) 
			&&(FindLine(map, tempPoint, p2)))
		{
			return TRUE;
		}
	}
	
	if(map[maxx][miny] == 0)
	{
		tempPoint.x = maxx;
		tempPoint.y = miny;
		if((FindLine(map, p1, tempPoint))
			&& (FindLine(map, tempPoint, p2)))
		{
			return TRUE;
		}
	}

	if(map[minx][miny] == 0)
	{
		tempPoint.x = minx;
		tempPoint.y = miny;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			return TRUE;
		}
	}
	
	if(map[maxx][maxy] == 0)
	{
		tempPoint.x = maxx;
		tempPoint.y = maxy;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CChessMan::FindCorner(int map[][MAXY], POINT p1, POINT p2, POINT *cross1)
{
	int maxx, maxy, minx, miny;
	POINT tempPoint = {0};

	//测试矩形格子
	maxx = (p1.x>p2.x)?p1.x:p2.x;
	maxy = (p1.y>p2.y)?p1.y:p2.y;
	minx = (p1.x<p2.x)?p1.x:p2.x;
	miny = (p1.y<p2.y)?p1.y:p2.y;

	if(map[minx][maxy] == 0)
	{
		tempPoint.x = minx;
		tempPoint.y = maxy;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			cross1->x = tempPoint.x;
			cross1->y = tempPoint.y;
			return TRUE;
		}
	}
	
	if(map[maxx][miny] == 0)
	{
		tempPoint.x = maxx;
		tempPoint.y = miny;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			cross1->x = tempPoint.x;
			cross1->y = tempPoint.y;
			return TRUE;
		}
	}

	if(map[minx][miny] == 0)
	{
		tempPoint.x = minx;
		tempPoint.y = miny;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			cross1->x = tempPoint.x;
			cross1->y = tempPoint.y;
			return TRUE;
		}
	}
	
	if(map[maxx][maxy] == 0)
	{
		tempPoint.x = maxx;
		tempPoint.y = maxy;
		if((FindLine(map, p1, tempPoint)) 
			&& (FindLine(map, tempPoint, p2)))
		{
			cross1->x = tempPoint.x;
			cross1->y = tempPoint.y;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CChessMan::FindTwoCorner(int map[][MAXY], POINT p1, POINT p2)
{
	int i;
	POINT tempPoint = {0};
	//横向
	for(i=0; i<MAXY; i++)
	{
		if(i == p1.y)
		{
			continue;
		}
		tempPoint.x = p1.x;
		tempPoint.y = i;
		if((map[tempPoint.x][tempPoint.y]==0) 
			|| (map[tempPoint.x][tempPoint.y]==-1))
		{
			if(FindLine(map, tempPoint, p1))
			{
				tempPoint.x = p2.x;
				if((map[tempPoint.x][tempPoint.y]==0) 
					|| (map[tempPoint.x][tempPoint.y]==-1))
				{
					if(FindLine(map, tempPoint, p2))
					{
						return TRUE;
					}
				}
			}
		}
	}

	//纵向
	for(i=0; i<MAXX; i++)
	{
		if(i == p1.x)
			continue;
		tempPoint.x = i;
		tempPoint.y = p1.y;
		if((map[tempPoint.x][tempPoint.y]==0) 
			|| (map[tempPoint.x][tempPoint.y]==-1))
		{
			if(FindLine(map, tempPoint, p1))
			{
				tempPoint.y = p2.y;
				if((map[tempPoint.x][tempPoint.y]==0) 
					|| (map[tempPoint.x][tempPoint.y]==-1))
				{
					if(FindLine(map, tempPoint, p2))
					{
						return TRUE;
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL CChessMan::FindTwoCorner(int map[][MAXY], POINT p1, POINT p2, POINT *cross1, POINT *cross2)
{
	int i;
	POINT tempPoint1 = {0};
	POINT tempPoint2 = {0};
	//横向
	for(i=0; i<MAXY; i++)
	{
		if(i == p1.y)
			continue;
		tempPoint1.x = p1.x;
		tempPoint1.y = i;
		if((map[tempPoint1.x][tempPoint1.y]==0) 
			|| (map[tempPoint1.x][tempPoint1.y]==-1))
		{
			if(FindLine(map, tempPoint1, p1))
			{
				tempPoint2.x = p2.x;
				tempPoint2.y = i;
				if((map[tempPoint2.x][tempPoint2.y]==0) 
					|| (map[tempPoint2.x][tempPoint2.y]==-1))
				{
					if(FindLine(map, tempPoint2, p2))
					{	//判断两个转折点是否连通!!!
						if(FindLine(map, tempPoint1, tempPoint2))
						{
							cross1->x = p1.x;
							cross1->y = i;
							cross2->x = p2.x;
							cross2->y = i;
							return TRUE;
						}	
					}
				}
			}
		}
	}

	//纵向
	for(i=0; i<MAXX; i++)
	{
		if(i == p1.x)
			continue;
		tempPoint1.x = i;
		tempPoint1.y = p1.y;
		if((map[tempPoint1.x][tempPoint1.y]==0) 
			|| (map[tempPoint1.x][tempPoint1.y]==-1))
		{
			if(FindLine(map, tempPoint1, p1))
			{
				tempPoint2.x = i;
				tempPoint2.y = p2.y;
				if((map[tempPoint2.x][tempPoint2.y]==0) 
					|| (map[tempPoint2.x][tempPoint2.y]==-1))
				{
					if(FindLine(map, tempPoint2, p2))
					{//判断两个转折点是否连通!!!
						if(FindLine(map, tempPoint1, tempPoint2))
						{
							cross1->x = i;
							cross1->y = p1.y;
							cross2->x = i;
							cross2->y = p2.y;
							return TRUE;
						}
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL CChessMan::Find(int map[MAXX][MAXY], POINT p1, POINT p2)
{
	CLlkDlg *parent = (CLlkDlg *)GetParent();
	CString str;
	if(FindLine(map, p1, p2))
	{
		str.Format("直线：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		return TRUE;
	}
	if(FindCorner(map, p1, p2))
	{
		str.Format("一拐角：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		return TRUE;
	}
	if(FindTwoCorner(map, p1, p2))
	{
		str.Format("两拐角：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		return TRUE;
	}

	return FALSE;
}

BOOL CChessMan::Find(int map[][MAXY], 
					 POINT p1, POINT p2, 
					 POINT cross1, POINT cross2)
{
	CLlkDlg *parent = (CLlkDlg *)GetParent();
	parent->m_line.m_src1 = p1;
	parent->m_line.m_src2 = p2;

	CString str;
	if(FindLine(map, p1, p2))
	{
		str.Format("直线：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		parent->m_line.m_lineNum = 1;
		return TRUE;
	}
	if(FindCorner(map, p1, p2, &(parent->m_line.m_crossP1)))
	{
		str.Format("一拐角：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		parent->m_line.m_lineNum = 2;
		return TRUE;
	}
	if(FindTwoCorner(map, p1, p2, &(parent->m_line.m_crossP1), 
		&(parent->m_line.m_crossP2)))
	{
		str.Format("两拐角：(%d,%d)->(%d,%d)\n", 
			p1.x, p1.y, p2.x, p2.y);
		parent->m_method.SetWindowText(str);
		parent->m_line.m_lineNum = 3;
		return TRUE;
	}

	return FALSE;
}

BOOL CChessMan::IsEmpty(int map[][MAXY])
{
 	int i, j;
 	int sum = 0;
 
 	for(i=1; i<MAXX-1; i++)
 		for(j=1; j<MAXY-1; j++)
 			sum += map[i][j];
 	if(sum)
 		return FALSE;
 	else
 		return TRUE;
}


BOOL CChessMan::Hint(int map[][MAXY])
{
	int x1, y1, x2, y2;
	POINT p1 = {0};
	POINT p2 = {0};

	for(x1=1; x1<MAXX-1; x1++)
	{
		for(y1=1; y1<MAXY-1; y1++)
		{
			for(x2=1; x2<MAXX-1; x2++)
			{
				for(y2=1; y2<MAXY-1; y2++)
				{
					p1.x = x1;
					p1.y = y1;
					p2.x = x2;
					p2.y = y2;
					if((map[x1][y1]==0) || (map[x2][y2]==0))
					{//空白格子
						continue;
					}
					if(map[x1][y1] != map[x2][y2])
					{//不相等
						continue;
					}		
					if((x1==x2) && (y1==y2))
					{//同一个点
						continue;
					}
					if(FindLine(map, p1, p2))
					{
						return TRUE;
					}
					if(FindCorner(map, p1, p2))
					{
						return TRUE;
					}
					if(FindTwoCorner(map, p1, p2))
					{
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

BOOL CChessMan::Hint(int map[][MAXY], int *a1, int *a2)
{
	int x1, y1, x2, y2;
	POINT p1 = {0};
	POINT p2 = {0};

	for(x1=1; x1<MAXX-1; x1++)
	{
		for(y1=1; y1<MAXY-1; y1++)
		{
			for(x2=1; x2<MAXX-1; x2++)
			{
				for(y2=1; y2<MAXY-1; y2++)
				{
					p1.x = x1;
					p1.y = y1;
					p2.x = x2;
					p2.y = y2;
					if((map[x1][y1]==0) || (map[x2][y2]==0))
					{//空白格子
						continue;
					}
					if(map[x1][y1] != map[x2][y2])
					{//不相等
						continue;
					}
					if((x1==x2) && (y1==y2))
					{//同一个点
						continue;
					}
					if(FindLine(map, p1, p2))
					{
						*a1 = (x1-1) * (MAXY-2) + y1 - 1;
						*a2 = (x2-1) * (MAXY-2) + y2 - 1;
						return TRUE;
					}
					if(FindCorner(map, p1, p2))
					{
						*a1 = (x1-1) * (MAXY-2) + y1 - 1;
						*a2 = (x2-1) * (MAXY-2) + y2 - 1;
						return TRUE;
					}
					if(FindTwoCorner(map, p1, p2))
					{
						*a1 = (x1-1) * (MAXY-2) + y1 - 1;
						*a2 = (x2-1) * (MAXY-2) + y2 - 1;
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

void CChessMan::OnLButtonDown(UINT nFlags, CPoint point) //用此事件可以加快响应速度(不用Clicked事件)
{
	SetButtonStyle(BS_DEFPUSHBUTTON);//显示黑边框
	CLlkDlg *parent = (CLlkDlg *)GetParent();

	if((parent->m_p==NULL) || (parent->m_p->m_id!=m_id)
		|| ((parent->m_p->m_pos.x==m_pos.x)
		&&(parent->m_p->m_pos.y==m_pos.y)))
	{
		parent->m_p = this;
		if(parent->m_line.m_lineNum != 0)
		{
			parent->m_line.m_lineNum = 0;
			parent->RefreshMap();
			parent->m_line.Invalidate();
		}
	}
	else 
	{
		if(Find(parent->map, parent->m_p->m_pos, 
			m_pos, parent->m_line.m_crossP1, 
			parent->m_line.m_crossP2))
		{
			//消去
			parent->map[parent->m_p->m_pos.x][parent->m_p->m_pos.y] = 0;
			parent->map[m_pos.x][m_pos.y] = 0;
			//不能用delete!!!否则重新开始时无法清除原有按钮
			parent->m_p->ShowWindow(SW_HIDE);
			this->ShowWindow(SW_HIDE);
			
			parent->RefreshMap();
			parent->m_line.Invalidate();

			parent->m_p = NULL;
			parent->m_timePoint += 3;//增加时间点
			//画时间条
			parent->InvalidateRgn(&(parent->m_MsgRgn));

			if(IsEmpty(parent->map))//是否消完
			{
				int ret = MessageBox("过关拉!要挑战下一关吗?", 
					"恭喜你!", MB_ICONINFORMATION|MB_OKCANCEL);
				if(ret == IDOK)
				{
					parent->Start(++(parent->m_nLevel));
				}
				else
				{
					for(int i=0; i<(MAXX-2)*(MAXY-2); i++)
					{
						delete (CChessMan *)parent->m_cmGroup.GetAt(i);
					}

					parent->isHighLevel();	//结束游戏时,调用等级判断函数

					parent->DestroyWindow();
					
				}
			}

			if(!Hint(parent->map))//是否无处可消
			{
				parent->m_exchangeNum++;
				parent->CallExchange();
				parent->m_method.SetWindowText("无可用消除!自动切换!");
			}
		}
		else
		{
			parent->m_p = this;
		}
	}	

}

