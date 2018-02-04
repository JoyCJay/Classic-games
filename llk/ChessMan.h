#if !defined(AFX_CHESSMAN_H__EB414A5E_D02A_4F89_ACE0_2187863ECEAD__INCLUDED_)
#define AFX_CHESSMAN_H__EB414A5E_D02A_4F89_ACE0_2187863ECEAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChessMan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChessMan window
class CChessMan : public CButton
{
	// Construction
public:
	CChessMan();
	CChessMan(int id, POINT pos);
	
public:
	static BOOL FindTwoCorner(int map[][MAXY], POINT p1, POINT p2, POINT  *cross1, POINT *cross2);
	static BOOL FindCorner(int map[][MAXY], POINT p1, POINT p2, POINT *cross1);
	static BOOL Hint(int map[][MAXY], int* a1, int *a2);
	static BOOL Hint(int map[MAXX][MAXY]);
	static BOOL FindLine(int map[][MAXY], POINT p1, POINT p2);
	BOOL IsEmpty(int map[][MAXY]);
	BOOL Find(int map[MAXX][MAXY], POINT p1, POINT p2);
	BOOL Find(int map[MAXX][MAXY], POINT p1, POINT p2, POINT cross1, POINT cross2);
	static BOOL FindTwoCorner(int map[MAXX][MAXY], POINT p1, POINT p2);
	static BOOL FindCorner(int map[MAXX][MAXY], POINT p1, POINT p2);
	POINT m_pos;
	int m_id;
	virtual ~CChessMan();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CChessMan)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LLKBUTTON_H__EB414A5E_D02A_4F89_ACE0_2187863ECEAD__INCLUDED_)


