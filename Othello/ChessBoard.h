#ifndef __CHESS_BOARD_H__
#define __CHESS_BOARD_H__

#include "DataStruct.h"

#define COL_WIDTH 45
#define ROW_WIDTH 45

class CChessBoard : public CWnd
{
private:
	CBitmap  m_bitBlackChess, m_bitWhiteChess;
	CBitmap  m_bitChessBoard;
	CBitmap  m_motive[8]; 
	int      m_iMotiveNumber;
	bool     m_bPlayMotive;
	int      m_iMotivex, m_iMotivey;
	// Construction
public:
	board_type m_oChessBoard;
	CChessBoard();
	
public:
    void NewGame();
	void MoveBack();
	void PlayMotive(int row, int col, UINT8 obcolor);

public:
	virtual BOOL Create(RECT &rect, CWnd * pParentWnd, UINT nID);

public:
	virtual ~CChessBoard();
	

protected:
	//{{AFX_MSG(CChessBoard)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg void OnComRun(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTranChess(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#endif