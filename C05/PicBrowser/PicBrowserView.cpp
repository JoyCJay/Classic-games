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
	{//���·��Ϊ��,������
		tmp.Format("<html>"\
					"<head>"\
					"<TITLE>ͼƬ�����</TITLE>"\
					"</head>"\
					"<body>"\
					"<DIV id=\"image\" class=\"slides\"><IMG src=\"%s\"></DIV>"\
					"</body>"\
					"</html>", lpFileName);
		m_TempFile = GetExeFilePath();
		m_TempFile+="\\temp.html";
	 //���ļ�,����ļ�����,��ɾ��,���򴴽�
		fp = fopen(m_TempFile, "w+");
	 //д���ļ�
		int nSize = fprintf(fp, "%s", tmp);
	 //�ر��ļ�
		fclose(fp);
	}
}

void CPicBrowserView::OnBrowerBtn() 
{
	CString strFileName;
	CString tmpFilePath;
	//�ļ����͹���
	CString strFilter("JPEG�ļ� (*.jpg)|*.JPG| �����ļ�(*.gif)|*.GIF||");
	//���ɴ򿪶Ի���
    CFileDialog  OpenDlg(TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		strFilter);
	//ͨ���򿪶Ի���ѡ��ͼƬ�ļ�
	int nFlags = OpenDlg.DoModal();
	if(nFlags==IDOK)
	{//�û���������"��"��ť,���ļ�·����������Ա����m_strFileName����
		strFileName=OpenDlg.GetPathName();
	 //�����ļ�·��,�������ļ�
		SetFile(strFileName);
	 //�õ���Ҫ�������ʱHTML�ļ�
		strFileName = GetExeFilePath();
		strFileName += "\\temp.html";
		tmpFilePath.Format("file:///%s", strFileName);
	//�����ʱHTML�ļ�
		Navigate2(tmpFilePath, NULL, NULL);
	//������ʾ
		Refresh();
	}	
}

CString CPicBrowserView::GetExeFilePath()
{
	char exeFullPath[MAX_PATH];
	CString m_TempFile;
	GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	//�����ʽ��Ϊ�ַ���
	m_TempFile.Format("%s",exeFullPath);
	//ȥ��Ӧ�ó����ȫ����15ΪӦ�ó����ļ�ȫ���ĳ��ȣ�
	exeFullPath[m_TempFile.GetLength()-15]='\0';
	//�õ�Ӧ�ó�������·��
	m_TempFile.Format("%s",exeFullPath);
	//�õ���ʱ�ļ���ȫ·��
	return m_TempFile;
}
