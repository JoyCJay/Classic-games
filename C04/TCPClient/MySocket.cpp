// MySocket.cpp: implementation of the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPClient.h"
#include "MySocket.h"
#include "TCPClientDlg.h"

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

void CMySocket::SetParent(CDialog *pDlg)              //����CTCPClientDlg���ָ��
{
	m_pDlg=(CTCPClientDlg*)pDlg;
}

void CMySocket::OnConnect(int nErrorCode)    //�¼�������
{
	
	if(nErrorCode==0)
	{
		((CTCPClientDlg*)m_pDlg)->OnConnect();        //����CTCPClientDlg���е�OnConnect��Ա����
	}
}

void CMySocket::OnReceive(int nErrorCode)    //�¼�������
{
	((CTCPClientDlg*)m_pDlg)->OnReceive();        //����CTCPClientDlg���е�OnReceive��Ա���� 
}

void CMySocket::OnClose(int nErrorCode)     //�¼�������
{
	((CTCPClientDlg*)m_pDlg)->OnClose();         //����CTCPClientDlg���е�OnClose��Ա����
}

