// DynamicPicDemo.h : main header file for the DYNAMICPICDEMO application
//

#if !defined(AFX_DYNAMICPICDEMO_H__C9393CF9_7B15_41A5_8B9A_F64D2FC32477__INCLUDED_)
#define AFX_DYNAMICPICDEMO_H__C9393CF9_7B15_41A5_8B9A_F64D2FC32477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynamicPicDemoApp:
// See DynamicPicDemo.cpp for the implementation of this class
//

class CDynamicPicDemoApp : public CWinApp
{
public:
	CDynamicPicDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicPicDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDynamicPicDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICPICDEMO_H__C9393CF9_7B15_41A5_8B9A_F64D2FC32477__INCLUDED_)
