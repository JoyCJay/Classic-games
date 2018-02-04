#ifndef __SNAKE_GAME_H__
#define __SNAKE_GAME_H__
//����Ϸ��

#include "Afxtempl.h"		//����ģ��ͷ�ļ�

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

	BOOL GameStart();		//��Ϸ��ʼ����
	void InitFoods();		//��ʼ����ʵ����
	void SetGameLevel(int level);

private:

	CPoint	m_psFood;		//��ǰʳ������
	int		m_nDirect;		//��ǰ���Ƚ�����
	int		m_nScore;		//��ǰ��Ϸ����
	int		m_nlevel;		//��ǰ��Ϸ�ȼ�
	int     m_nHighScore;	//��ǰ��Ϸ��߷�

	CArray<CPoint,CPoint> m_body;	//��������
protected:
    afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    DECLARE_MESSAGE_MAP()
};

#endif