// PicBrowserDoc.h : interface of the CPicBrowserDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICBROWSERDOC_H__191350A2_4FBE_480D_B029_FAF1A54C98D4__INCLUDED_)
#define AFX_PICBROWSERDOC_H__191350A2_4FBE_480D_B029_FAF1A54C98D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPicBrowserDoc : public CDocument
{
protected: // create from serialization only
	CPicBrowserDoc();
	DECLARE_DYNCREATE(CPicBrowserDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicBrowserDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicBrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicBrowserDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICBROWSERDOC_H__191350A2_4FBE_480D_B029_FAF1A54C98D4__INCLUDED_)
