// Mp3Player.h : main header file for the MP3PLAYER application
//

#if !defined(AFX_MP3PLAYER_H__B5A151D7_2CA8_4A9F_9E6A_83ABF05769C4__INCLUDED_)
#define AFX_MP3PLAYER_H__B5A151D7_2CA8_4A9F_9E6A_83ABF05769C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMp3PlayerApp:
// See Mp3Player.cpp for the implementation of this class
//

class CMp3PlayerApp : public CWinApp
{
public:
	CMp3PlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3PlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMp3PlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3PLAYER_H__B5A151D7_2CA8_4A9F_9E6A_83ABF05769C4__INCLUDED_)
