#ifndef __RULE_H__
#define __RULE_H__

#include <afxtempl.h>

#define MAX_POINT 29
#define MIN_POINT 0

class CRule
{
public:
	BOOL IsOver(CPoint &pt, CArray<CPoint, CPoint> &body);		//判断当前点是否为游戏结束
	
};

#endif 