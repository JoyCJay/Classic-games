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

void CMySocket::SetParent(CDialog *pDlg)              //设置CTCPClientDlg类的指针
{
	m_pDlg=(CTCPClientDlg*)pDlg;
}

void CMySocket::OnConnect(int nErrorCode)    //事件处理函数
{
	
	if(nErrorCode==0)
	{
		((CTCPClientDlg*)m_pDlg)->OnConnect();        //调用CTCPClientDlg类中的OnConnect成员函数
	}
}

void CMySocket::OnReceive(int nErrorCode)    //事件处理函数
{
	((CTCPClientDlg*)m_pDlg)->OnReceive();        //调用CTCPClientDlg类中的OnReceive成员函数 
}

void CMySocket::OnClose(int nErrorCode)     //事件处理函数
{
	((CTCPClientDlg*)m_pDlg)->OnClose();         //调用CTCPClientDlg类中的OnClose成员函数
}

