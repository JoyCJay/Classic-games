// MySocket.h: interface for the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOCKET_H__72993DAE_EE9F_4D21_9BF7_472B85ED92AF__INCLUDED_)
#define AFX_MYSOCKET_H__72993DAE_EE9F_4D21_9BF7_472B85ED92AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySocket : public CAsyncSocket  
{
public:
	void SetParent(CDialog *pDlg);
	
	CMySocket();
	
	virtual ~CMySocket();              
	
protected:
	
	virtual void OnClose(int nErrorCode);
	
	virtual void OnReceive(int nErrorCode);
	
	virtual void OnConnect(int nErrorCode);
	
	virtual void OnAccept(int nErrorCode);    
	
private:
	
	CDialog *m_pDlg;
	
};

#endif // !defined(AFX_MYSOCKET_H__72993DAE_EE9F_4D21_9BF7_472B85ED92AF__INCLUDED_)
