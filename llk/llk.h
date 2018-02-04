// llk.h : main header file for the LLK application
//

#if !defined(AFX_LLK_H__89197D7F_849C_40B2_8201_F84BC8CEC189__INCLUDED_)
#define AFX_LLK_H__89197D7F_849C_40B2_8201_F84BC8CEC189__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLlkApp:
// See llk.cpp for the implementation of this class
//

#define MAXX 9		//行数
#define MAXY 14		//列数
#define SAME 4		//同种类型相同个数
#define TYPENUM 21	//类型数

class CLlkApp : public CWinApp
{
public:
	CLlkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLlkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLlkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LLK_H__89197D7F_849C_40B2_8201_F84BC8CEC189__INCLUDED_)
