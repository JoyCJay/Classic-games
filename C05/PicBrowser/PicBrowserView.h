// PicBrowserView.h : interface of the CPicBrowserView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICBROWSERVIEW_H__A0E48F71_F497_4A49_B253_AD383873A9C8__INCLUDED_)
#define AFX_PICBROWSERVIEW_H__A0E48F71_F497_4A49_B253_AD383873A9C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPicBrowserView : public CHtmlView
{
protected: // create from serialization only
	CPicBrowserView();
	DECLARE_DYNCREATE(CPicBrowserView)

// Attributes
public:
	CPicBrowserDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicBrowserView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetExeFilePath();
	void SetFile(LPCSTR lpFileName);
	virtual ~CPicBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicBrowserView)
	afx_msg void OnBrowerBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PicBrowserView.cpp
inline CPicBrowserDoc* CPicBrowserView::GetDocument()
   { return (CPicBrowserDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICBROWSERVIEW_H__A0E48F71_F497_4A49_B253_AD383873A9C8__INCLUDED_)
