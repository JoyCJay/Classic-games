// llkDlg.h : header file
//

#if !defined(AFX_LLKDLG_H__BCB1D0A0_D08E_42B3_B138_E0F4345D7AAC__INCLUDED_)
#define AFX_LLKDLG_H__BCB1D0A0_D08E_42B3_B138_E0F4345D7AAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLlkDlg dialog

#include "LineStatic.h"
#include "ChessMan.h"

class CLlkDlg : public CDialog
{
// Construction
public:
	void RefreshMap();
	void Exchange(int map[MAXX][MAXY]);
	void CallHint();
	void CallExchange();
	void ShowMap(int map[MAXX][MAXY]);
	void InitMap(int map[MAXX][MAXY]);
	void ShowMsg(CRgn * rgn);
	void Start(int nlevel);
	void PlayBackMusic(BOOL bflag);
	void isHighLevel();
	CLlkDlg(CWnd* pParent = NULL);	// standard constructor

	CChessMan * m_p;		//����ָ��
	int map[MAXX][MAXY];	//��������
	BOOL	m_bStart;		//��Ϸ��ʼ״̬
	int		m_nLevel;		//��ǰ�ȼ�����
	int		m_timePoint;	//ʱ������
	CRgn	m_MsgRgn;		//��Ϣ����Χ
	CPtrArray m_cmGroup;	//��������
	int		m_hintNum;		//��ʾ��������
	int		m_exchangeNum;	//���̴�������
	int     m_nHighLevel;	//��ߵȼ�

// Dialog Data
	//{{AFX_DATA(CLlkDlg)
	enum { IDD = IDD_LLK_DIALOG };
	CStatic	m_method;
	CLineStatic	m_line;
	CStatic	m_bkPic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLlkDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CMenu m_main_menu;

	int m_hintP2;			//��2��ת�۵�
	int m_hintP1;			//��1��ת�۵�

	// Generated message map functions
	//{{AFX_MSG(CLlkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnExitGame();
	afx_msg void OnHelp();
	afx_msg void OnHeroList();
	afx_msg void OnPlayMusic();
	afx_msg void OnStartGame();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LLKDLG_H__BCB1D0A0_D08E_42B3_B138_E0F4345D7AAC__INCLUDED_)
