// Snake.h : main header file for the SNAKE application
//

#if !defined(AFX_SNAKE_H__ECFF98F0_5010_4939_B921_D54969E0479A__INCLUDED_)
#define AFX_SNAKE_H__ECFF98F0_5010_4939_B921_D54969E0479A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnakeApp:
// See Snake.cpp for the implementation of this class
//

class CSnakeApp : public CWinApp
{
public:
	CSnakeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSnakeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKE_H__ECFF98F0_5010_4939_B921_D54969E0479A__INCLUDED_)
