#ifndef __SNAKE_GAME_H__
#define __SNAKE_GAME_H__
//主游戏类

#include "Afxtempl.h"		//插入模板头文件

#define GAME_LEVEL_LOW  2
#define GAME_LEVEL_NOR  4
#define GAME_LEVEL_HIGH 8

#define DIREC_UP	1
#define DIREC_DOWN	2
#define DIREC_RIGHT 3
#define DIREC_LEFT	4

#define LOW_LEVEL_SLEEP		100
#define NOR_LEVEL_SLEEP		50
#define HIGH_LEVEL_SLEEP	30

class CSnakeGame:public CWnd
{
public:
	void HeroWrite();
	void ReDrawBody(CPoint pt);
	void InitGame();
	CSnakeGame();
	virtual ~CSnakeGame();

	BOOL GameStart();		//游戏开始函数
	void InitFoods();		//初始化果实函数
	void SetGameLevel(int level);

private:

	CPoint	m_psFood;		//当前食物坐标
	int		m_nDirect;		//当前蛇先进方向
	int		m_nScore;		//当前游戏分数
	int		m_nlevel;		//当前游戏等级
	int     m_nHighScore;	//当前游戏最高分

	CArray<CPoint,CPoint> m_body;	//蛇身向量
protected:
    afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    DECLARE_MESSAGE_MAP()
};

#endif