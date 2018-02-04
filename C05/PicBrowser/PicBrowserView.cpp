// PicBrowserView.cpp : implementation of the CPicBrowserView class
//

#include "stdafx.h"
#include "PicBrowser.h"

#include "PicBrowserDoc.h"
#include "PicBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView

IMPLEMENT_DYNCREATE(CPicBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CPicBrowserView, CHtmlView)
	//{{AFX_MSG_MAP(CPicBrowserView)
	ON_COMMAND(ID_BROWER_BTN, OnBrowerBtn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView construction/destruction

CPicBrowserView::CPicBrowserView()
{
	// TODO: add construction code here

}

CPicBrowserView::~CPicBrowserView()
{
}

BOOL CPicBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView drawing

void CPicBrowserView::OnDraw(CDC* pDC)
{
	CPicBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CPicBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView printing


/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView diagnostics

#ifdef _DEBUG
void CPicBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CPicBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CPicBrowserDoc* CPicBrowserView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicBrowserDoc)));
	return (CPicBrowserDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView message handlers

void CPicBrowserView::SetFile(LPCSTR lpFileName)
{
	CString tmp;
	FILE * fp = NULL;
	CString m_TempFile;
	if(lpFileName != NULL)
	{//如果路径为空,不设置
		tmp.Format("<html>"\
					"<head>"\
					"<TITLE>图片浏览器</TITLE>"\
					"</head>"\
					"<body>"\
					"<DIV id=\"image\" class=\"slides\"><IMG src=\"%s\"></DIV>"\
					"</body>"\
					"</html>", lpFileName);
		m_TempFile = GetExeFilePath();
		m_TempFile+="\\temp.html";
	 //打开文件,如果文件存在,则删除,否则创建
		fp = fopen(m_TempFile, "w+");
	 //写入文件
		int nSize = fprintf(fp, "%s", tmp);
	 //关闭文件
		fclose(fp);
	}
}

void CPicBrowserView::OnBrowerBtn() 
{
	CString strFileName;
	CString tmpFilePath;
	//文件类型过滤
	CString strFilter("JPEG文件 (*.jpg)|*.JPG| 动画文件(*.gif)|*.GIF||");
	//生成打开对话框
    CFileDialog  OpenDlg(TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		strFilter);
	//通过打开对话框选择图片文件
	int nFlags = OpenDlg.DoModal();
	if(nFlags==IDOK)
	{//用户单击的是"打开"按钮,将文件路径名赋给成员变量m_strFileName备用
		strFileName=OpenDlg.GetPathName();
	 //设置文件路径,并保存文件
		SetFile(strFileName);
	 //得到想要浏览的临时HTML文件
		strFileName = GetExeFilePath();
		strFileName += "\\temp.html";
		tmpFilePath.Format("file:///%s", strFileName);
	//浏览临时HTML文件
		Navigate2(tmpFilePath, NULL, NULL);
	//更新显示
		Refresh();
	}	
}

CString CPicBrowserView::GetExeFilePath()
{
	char exeFullPath[MAX_PATH];
	CString m_TempFile;
	GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	//将其格式化为字符串
	m_TempFile.Format("%s",exeFullPath);
	//去掉应用程序的全名（15为应用程序文件全名的长度）
	exeFullPath[m_TempFile.GetLength()-15]='\0';
	//得到应用程序所在路径
	m_TempFile.Format("%s",exeFullPath);
	//得到临时文件的全路径
	return m_TempFile;
}
