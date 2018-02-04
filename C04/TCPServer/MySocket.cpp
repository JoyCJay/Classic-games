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

void CMySocket::SetParent(CDialog *pDlg)              //设置CTalkDlg类的指针
{
	m_pDlg=(CTCPServerDlg*)pDlg;
}

void CMySocket::OnAccept(int nErrorCode)               //事件处理函数
{
	if(nErrorCode==0)
	{
		((CTCPServerDlg*)m_pDlg)->OnAccept();          //调用CTCPServerDlg类中的OnAccept成员函数
	}
}

void CMySocket::OnConnect(int nErrorCode)    //事件处理函数
{
	
	if(nErrorCode==0)
	{
//		((CTCPServerDlg*)m_pDlg)->OnConnect();        //调用CTCPServerDlg类中的OnConnect成员函数
	}
}

void CMySocket::OnReceive(int nErrorCode)    //事件处理函数
{
	((CTCPServerDlg*)m_pDlg)->OnReceive();        //调用CTCPServerDlg类中的OnReceive成员函数 
}

void CMySocket::OnClose(int nErrorCode)     //事件处理函数
{
	((CTCPServerDlg*)m_pDlg)->OnClose();         //调用CTCPServerDlg类中的OnClose成员函数
}

