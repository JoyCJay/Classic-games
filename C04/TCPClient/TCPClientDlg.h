// TCPClientDlg.h : header file
//

#if !defined(AFX_TCPCLIENTDLG_H__C06F0E76_5468_4B01_87A8_E64A21ADEEE4__INCLUDED_)
#define AFX_TCPCLIENTDLG_H__C06F0E76_5468_4B01_87A8_E64A21ADEEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

#include "MySocket.h"

class CTCPClientDlg : public CDialog
{
// Construction
public:
	void OnConnect();
	void OnClose();
	void OnReceive();
	
	CTCPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPClientDlg)
	enum { IDD = IDD_TCPCLIENT_DIALOG };
	CString	m_szRecv;
	CString	m_szSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
private:
	CMySocket m_sockConnect;
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnectBtn();
	afx_msg void OnSend();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENTDLG_H__C06F0E76_5468_4B01_87A8_E64A21ADEEE4__INCLUDED_)
