// KeyMessageDemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
/************************************************************************/
#include <windows.h>
//һ��windowsӦ�ó���Ӧ�ð�����ͷ�ļ�
#include <stdio.h>
//��׼����������ļ�
LRESULT CALLBACK WinSunProc
/*LRESULTһ�����ݽṹ typedef LONG LRESULT a 32-bit value returned from a 
window procedure or a callback functionһ��32λ�Ĵ��ڴ�����������һ���ص������ķ���ֵ*/
(                                  
 HWND hwnd,      
 // handle to window 
 UINT uMsg,      
 // message identifier /UINT a 32-bit unsigned integar on Win32 ���嶨�壺typedef unsigned int UINT
 WPARAM wParam, 
 // first message parameter/WPARAM ��һ����Ϣ���� typedef UINT WPARAM Ҳ��һ��32Ϊ���޷�������
 LPARAM lParam   
 // second message parameter/LPARAM �ڶ�����Ϣ���� typedef LONG LPARAM �����LRESULT ���
 );
 /************************************************************************
 WinMain:Windows�������ں���
 WINAPI :��Ӧ�ó���ص���������Ϊһ������ֵ����ʽ      
 ��Windows����ǣ�Windows9X����Դ����������⵽ʹ��������ִ��һ��Windows����
 ���ǵ��ü������Ѹó�����أ�Ȼ�����C startup code,�����ٵ���WinMain,��ʼ
 ִ�г���WinMain���ĸ������ɲ���ϵͳ���ݽ���
************************************************************************/
int WINAPI WinMain
(
 HINSTANCE hInstance,     
 //HINSTANCE Handle To an Instance   ʵ����� ��ǰӦ�ó����ʵ�����
 HINSTANCE hPrevInstance, 
 //HINSTANCE ǰһ��Ӧ�ó���ʵ�����,����һ������Win32��Ӧ�ó�����˵���������ΪNULL
 LPSTR lpCmdLine,          
 // ����һ�������в���
 int nCmdShow             
 // show state
 )
{
	/************************************************************************/
	/* ����һ�������Ĵ�����Ҫ���������ĸ��������裺
	���һ�������ࣻ
	ע�ᴰ���ࣻ
	�������ڣ�
	��ʾ�����´���                                                          */
	/************************************************************************/
	WNDCLASS wndcls;
	wndcls.cbClsExtra=0;
	//ָ�������ڴ�ռ�
	wndcls.cbWndExtra=0;
	//ָ�������ڴ�ռ�
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	//ָ�����ڱ���ɫ
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	//���ù����ʽ
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	//����ͼ����ʽ
	wndcls.hInstance=hInstance;
	//ָ������ʵ�����
	wndcls.lpfnWndProc=WinSunProc;
	//wndcls.lpfnWndProc��ָ���ĺ������Ǵ��ڵ���Ϊ����Ҳ������ν�Ĵ��ں���
	wndcls.lpszClassName="KeyMessageDemo";
	//���������ƣ���ͬʱҲ����CreateWindow()�����ĵ�һ������
	wndcls.lpszMenuName=NULL;
	//�˵�
	wndcls.style= CS_HREDRAW|CS_VREDRAW;
	/*���ڵ���ʾ����CS_HREDRAW����ˮƽ�ػ���ClassStyle_horizontal(ˮƽ�ģ����ƽ��ƽ�е�) redraw 
	CS_VREDRAW����ˮƽ�ػ�ClassStyle_vertical(��ֱ�ģ�����) redraw   ���ѡ��ˮƽ�ػ����ֱ�ػ�
	������϶����ں���������ʧ�������������ΪNULL,���϶��任��С���ֻ�������ʾ*/
	
	
	RegisterClass(&wndcls);
	//RegisterClass��Ҫһ�����͵����ݽṹWNDCLASS��Ϊ����,CreatWindow ������Ҫ11������
	
	HWND hwnd;
	/***************************************************
	CreateWindowֻ�������ڣ�������ʾ���ڣ������Ժ����Ǳ���������ShowWindow������ʾ����Ļ��,�֣�����ϣ����
	��һ��WM_PAINT�����ڣ����������ڵĻ�ͼ���������Ե���UpdateWindow
	***************************************************/
	hwnd=CreateWindow
		(
		"KeyMessageDemo",               
		//��ע�ᴰ���������
		"KeyMessageDemo", 
		//���ڱ���
		WS_OVERLAPPEDWINDOW,        
		//���ڷ��
		200,                        
		//����λ�õĺ�����
		200,                        
		//����λ�õ�������
		600,                        
		//���ڵĿ��
		400,                        
		//���ڵĸ߶�
		NULL,                       
		//
		NULL,                       
		//
		hInstance,                  
		//
		NULL                        
		//
		);
	
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	/************************************************************************/
	/* ��ʼ��������ɺ�WinMain������ν����Ϣѭ��                                                                     */
	/************************************************************************/ 
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);//ת��������Ϣ
		DispatchMessage(&msg);//������Ϣ
		/************************************************************************/
		/* DispatchMessage�Ὣ��Ϣ�������ں���ȥ������Ϣ����֮ʱ������ϵͳ����
		��ʱ��״̬��Ϊ���������������ڶ����������Ĵ��������Ѿ����ױ�ʶ�˴��ں���
		��Ҳ����wndcls.lpfnWndProc��,����DispatchMessage���������Ѱ*/
		/************************************************************************/
		
		
	}
	return 0;
}
/************************************************************************/
/* ���ڵ���������:���ں��������ں���ͨ������switch/case��ʽ�ж���Ϣ�����࣬
�Ծ������÷�ʽ���������Ǳ�Windowsϵͳ�����õģ���������һ��call back ������
��˼��ָ����ĳ����У���Windowsϵͳ���õĺ�������Щ������Ȼ��������ƣ�
 ������Զ����Ҳ���ñ�����ã�������ΪWindowsϵͳ׼����                                         */
 /************************************************************************/
 LRESULT CALLBACK WinSunProc(
	 HWND hwnd,      
	 // handle to window
	 UINT uMsg,      
	 // message identifier
	 WPARAM wParam, 
	 // first message parameter
	 LPARAM lParam   
	 // second message parameter
	 )
 {
	 /************************************************************************/
	 /*typedet struct tagMsg
	 {HWMD��hwnd;
	 UINT message;
	 WPARAM wParam;
	 LPARAM lParam;
	 DWORD time;
	 POINT pt;
 }*/
	 /************************************************************************/
	 char szStr[64] = {0};
	 HDC hdc;
	 switch(uMsg)
	 {
	 case WM_KEYUP:	 //�������ͷ�ʱ����WM_KEYUP��Ϣ
		 hdc=GetDC(hwnd);
		 sprintf(szStr, "%c�������ͷ�\r", wParam);
		 TextOut(hdc,100,50,szStr,strlen(szStr));
		 ReleaseDC(hwnd,hdc);
		 break;
	 case WM_KEYDOWN: //�����̰���ʱ����WM_KEYDOWN��Ϣ 
		 hdc=GetDC(hwnd);
		 sprintf(szStr, "%c����������\r", wParam);
		 TextOut(hdc,100,0,szStr,strlen(szStr));
		 ReleaseDC(hwnd,hdc);
		 break;
	 case WM_CLOSE:
		 if(IDYES==MessageBox(hwnd,"�Ƿ���Ľ���?","KeyMessageDemo",MB_YESNO))
		 {
			 DestroyWindow(hwnd);
		 }
		 break;
	 case WM_DESTROY:
		 PostQuitMessage(0);
		 break;
	 default:
		 return DefWindowProc(hwnd,uMsg,wParam,lParam);
		 //������ʲô��Ϣ�����봦������switch/caseָ���е�default:���������DefWindowProc,����Windows�ڲ�Ĭ�ϵ���Ϣ������
	 }
	 return 0;
 }


