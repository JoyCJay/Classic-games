// BackPicDemo.h : main header file for the BACKPICDEMO application
//

#if !defined(AFX_BACKPICDEMO_H__26B31B62_44BD_477D_93AB_FE903EBB0BBE__INCLUDED_)
#define AFX_BACKPICDEMO_H__26B31B62_44BD_477D_93AB_FE903EBB0BBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBackPicDemoApp:
// See BackPicDemo.cpp for the implementation of this class
//

class CBackPicDemoApp : public CWinApp
{
public:
	CBackPicDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackPicDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBackPicDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKPICDEMO_H__26B31B62_44BD_477D_93AB_FE903EBB0BBE__INCLUDED_)
