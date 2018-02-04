// SnakeDlg.h : header file
//

#if !defined(AFX_SNAKEDLG_H__275E8D1B_43B7_4FE8_B6AF_4897C77E9FED__INCLUDED_)
#define AFX_SNAKEDLG_H__275E8D1B_43B7_4FE8_B6AF_4897C77E9FED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSnakeDlg dialog

#include "SnakeGame.h"

class CSnakeDlg : public CDialog
{
// Construction
public:
	void Help();
	void HeroList();
	void PlayBackMusic(BOOL bflg);
	void InitMenu();
	CSnakeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSnakeDlg)
	enum { IDD = IDD_SNAKE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;				//主图标
	CMenu m_main_menu;			//主菜单对象
	BOOL  m_bStart;				//游戏开始标志
	CSnakeGame m_snake;			//主游戏对象
	// Generated message map functions
	//{{AFX_MSG(CSnakeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdatePlayMusic(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHigh(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNor(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHelp(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHeroList(CCmdUI* pCmdUI);
	afx_msg void OnUpdateExitGame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAbout(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStartGame(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEDLG_H__275E8D1B_43B7_4FE8_B6AF_4897C77E9FED__INCLUDED_)
