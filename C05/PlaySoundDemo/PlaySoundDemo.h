// PlaySoundDemo.h : main header file for the PLAYSOUNDDEMO application
//

#if !defined(AFX_PLAYSOUNDDEMO_H__7C53D79B_061B_438B_A10F_B151F599316D__INCLUDED_)
#define AFX_PLAYSOUNDDEMO_H__7C53D79B_061B_438B_A10F_B151F599316D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlaySoundDemoApp:
// See PlaySoundDemo.cpp for the implementation of this class
//

class CPlaySoundDemoApp : public CWinApp
{
public:
	CPlaySoundDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaySoundDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlaySoundDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYSOUNDDEMO_H__7C53D79B_061B_438B_A10F_B151F599316D__INCLUDED_)
