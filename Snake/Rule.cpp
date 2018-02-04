#include "stdafx.h"
#include "Rule.h"

BOOL CRule::IsOver(CPoint &pt, CArray<CPoint, CPoint> &body)
{
	if(pt.x>=MAX_POINT || pt.x<MIN_POINT)                 //如果纵坐标多于最下端边框或者少于最上端边框
	{
		return TRUE;                      //判断死亡
	}
	else if(pt.y>=MAX_POINT || pt.y<MIN_POINT)           //横坐标多于最右端边框
	{
		return TRUE;                      //判断死亡
	}

	for(int i=0;i<=body.GetUpperBound();i++)
	{
		CPoint pt1 = body.GetAt(i);     //将蛇身体的坐标传递给新定义的点
		if(pt.x==pt1.x&&pt.y==pt1.y)	  //如果两点完全相同,说明蛇碰到身体
		{
			return TRUE;				  //判断死亡
		}
	}

	return FALSE;
}