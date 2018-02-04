// MySocket.cpp: implementation of the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPServer.h"
#include "MySocket.h"
#include "TCPServerDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMySocket::CMySocket()
{

}

CMySocket::~CMySocket()
{

}

void CMySocket::SetParent(CDialog *pDlg)              //����CTalkDlg���ָ��
{
	m_pDlg=(CTCPServerDlg*)pDlg;
}

void CMySocket::OnAccept(int nErrorCode)               //�¼�������
{
	if(nErrorCode==0)
	{
		((CTCPServerDlg*)m_pDlg)->OnAccept();          //����CTCPServerDlg���е�OnAccept��Ա����
	}
}

void CMySocket::OnConnect(int nErrorCode)    //�¼�������
{
	
	if(nErrorCode==0)
	{
//		((CTCPServerDlg*)m_pDlg)->OnConnect();        //����CTCPServerDlg���е�OnConnect��Ա����
	}
}

void CMySocket::OnReceive(int nErrorCode)    //�¼�������
{
	((CTCPServerDlg*)m_pDlg)->OnReceive();        //����CTCPServerDlg���е�OnReceive��Ա���� 
}

void CMySocket::OnClose(int nErrorCode)     //�¼�������
{
	((CTCPServerDlg*)m_pDlg)->OnClose();         //����CTCPServerDlg���е�OnClose��Ա����
}

