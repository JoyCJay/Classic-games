// OthelloDlg.h : header file
//

#if !defined(AFX_OTHELLODLG_H__DAC0C8C2_DDB6_4DA7_A56E_440CDF9A626B__INCLUDED_)
#define AFX_OTHELLODLG_H__DAC0C8C2_DDB6_4DA7_A56E_440CDF9A626B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COthelloDlg dialog

#include "ChessBoard.h"

class COthelloDlg : public CDialog
{
// Construction
public:
	void GameStart();
	void PlayBackMusic(BOOL bCheck);
	void InitMenu();
	COthelloDlg(CWnd* pParent = NULL);	// standard constructor

	int  m_nBlackCount;	//黑子个数
	int  m_nWhiteCount;	//白子个数
	CChessBoard  m_chess;//棋盘对象

// Dialog Data
	//{{AFX_DATA(COthelloDlg)
	enum { IDD = IDD_OTHELLO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COthelloDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COthelloDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnExitGame();
	afx_msg void OnGameStart();
	afx_msg void OnHelp();
	afx_msg void OnLevelHigh();
	afx_msg void OnLevelLow();
	afx_msg void OnLevelNor();
	afx_msg void OnPlayMusic();
	afx_msg void OnBackBtn();
	//}}AFX_MSG
	afx_msg void OnRecalc(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHELLODLG_H__DAC0C8C2_DDB6_4DA7_A56E_440CDF9A626B__INCLUDED_)
