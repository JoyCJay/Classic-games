// DynamicPicDemoDlg.h : header file
//

#if !defined(AFX_DYNAMICPICDEMODLG_H__1475579D_9618_4CEF_86AB_378399827FFB__INCLUDED_)
#define AFX_DYNAMICPICDEMODLG_H__1475579D_9618_4CEF_86AB_378399827FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDynamicPicDemoDlg dialog

class CDynamicPicDemoDlg : public CDialog
{
// Construction
public:
	CDynamicPicDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDynamicPicDemoDlg)
	enum { IDD = IDD_DYNAMICPICDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicPicDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
private:
	CBitmap   m_bmp;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDynamicPicDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICPICDEMODLG_H__1475579D_9618_4CEF_86AB_378399827FFB__INCLUDED_)
