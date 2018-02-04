#if !defined(AFX_LINESTATIC_H__74C91B5C_8A0C_4E09_A84C_CA27A9339C19__INCLUDED_)
#define AFX_LINESTATIC_H__74C91B5C_8A0C_4E09_A84C_CA27A9339C19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineStatic window

class CLineStatic : public CStatic
{
// Construction
public:
	CLineStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	POINT m_crossP2;
	POINT m_crossP1;
	POINT m_src2;
	POINT m_src1;
	int m_lineNum;
	void DrawLine(CDC *pDC);
	virtual ~CLineStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLineStatic)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINESTATIC_H__74C91B5C_8A0C_4E09_A84C_CA27A9339C19__INCLUDED_)
