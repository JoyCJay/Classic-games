// Mp3PlayerDlg.h : header file
//

#if !defined(AFX_MP3PLAYERDLG_H__AA6B188F_D519_4AA4_91A0_911839356876__INCLUDED_)
#define AFX_MP3PLAYERDLG_H__AA6B188F_D519_4AA4_91A0_911839356876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMp3PlayerDlg dialog

class CMp3PlayerDlg : public CDialog
{
// Construction
public:
	CMp3PlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMp3PlayerDlg)
	enum { IDD = IDD_MP3PLAYER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3PlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMp3PlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3PLAYERDLG_H__AA6B188F_D519_4AA4_91A0_911839356876__INCLUDED_)
