// KeyMessageDemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
/************************************************************************/
#include <windows.h>
//一个windows应用程序应该包含的头文件
#include <stdio.h>
//标准输入输出流文件
LRESULT CALLBACK WinSunProc
/*LRESULT一种数据结构 typedef LONG LRESULT a 32-bit value returned from a 
window procedure or a callback function一个32位的窗口创建函数或者一个回调函数的返回值*/
(                                  
 HWND hwnd,      
 // handle to window 
 UINT uMsg,      
 // message identifier /UINT a 32-bit unsigned integar on Win32 具体定义：typedef unsigned int UINT
 WPARAM wParam, 
 // first message parameter/WPARAM 第一个消息参数 typedef UINT WPARAM 也是一个32为的无符号整数
 LPARAM lParam   
 // second message parameter/LPARAM 第二个消息参数 typedef LONG LPARAM 这个和LRESULT 差不多
 );
 /************************************************************************
 WinMain:Windows程序的入口函数
 WINAPI :在应用程序回调函数中作为一个返回值的样式      
 当Windows的外壳（Windows9X的资源管理器）侦测到使用者意欲执行一个Windows程序，
 于是调用加载器把该程序加载，然后调用C startup code,后者再调用WinMain,开始
 执行程序。WinMain的四个参数由操作系统传递进来
************************************************************************/
int WINAPI WinMain
(
 HINSTANCE hInstance,     
 //HINSTANCE Handle To an Instance   实例句柄 当前应用程序的实例句柄
 HINSTANCE hPrevInstance, 
 //HINSTANCE 前一个应用程序实例句柄,对于一个基于Win32的应用程序来说，这个参数为NULL
 LPSTR lpCmdLine,          
 // 储存一个命令行参数
 int nCmdShow             
 // show state
 )
{
	/************************************************************************/
	/* 创建一个完整的窗口需要经过下面四个操作步骤：
	设计一个窗口类；
	注册窗口类；
	创建窗口；
	显示及更新窗口                                                          */
	/************************************************************************/
	WNDCLASS wndcls;
	wndcls.cbClsExtra=0;
	//指定额外内存空间
	wndcls.cbWndExtra=0;
	//指定额外内存空间
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	//指定窗口背景色
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	//设置光标样式
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	//设置图标样式
	wndcls.hInstance=hInstance;
	//指定窗口实例句柄
	wndcls.lpfnWndProc=WinSunProc;
	//wndcls.lpfnWndProc所指定的函数就是窗口的行为中枢也就是所谓的窗口函数
	wndcls.lpszClassName="KeyMessageDemo";
	//窗口类名称，它同时也就是CreateWindow()函数的第一个参数
	wndcls.lpszMenuName=NULL;
	//菜单
	wndcls.style= CS_HREDRAW|CS_VREDRAW;
	/*窗口的显示类型CS_HREDRAW窗口水平重画，ClassStyle_horizontal(水平的，与地平线平行的) redraw 
	CS_VREDRAW窗口水平重画ClassStyle_vertical(垂直的，竖的) redraw   如果选择水平重绘和竖直重绘
	用鼠标拖动窗口后则文字消失，如果属性设置为NULL,则拖动变换大小文字还照样显示*/
	
	
	RegisterClass(&wndcls);
	//RegisterClass需要一个大型的数据结构WNDCLASS作为参数,CreatWindow 则另需要11个参数
	
	HWND hwnd;
	/***************************************************
	CreateWindow只产生窗口，并不显示窗口，所以稍后我们必需再利用ShowWindow将他显示在屏幕上,又，我们希望先
	送一个WM_PAINT给窗口，以驱动窗口的绘图操作，所以调用UpdateWindow
	***************************************************/
	hwnd=CreateWindow
		(
		"KeyMessageDemo",               
		//已注册窗口类的名称
		"KeyMessageDemo", 
		//窗口标题
		WS_OVERLAPPEDWINDOW,        
		//窗口风格
		200,                        
		//窗口位置的横坐标
		200,                        
		//窗口位置的纵坐标
		600,                        
		//窗口的宽度
		400,                        
		//窗口的高度
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
	/* 初始化工作完成后，WinMain进入所谓的消息循环                                                                     */
	/************************************************************************/ 
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);//转换键盘消息
		DispatchMessage(&msg);//分派消息
		/************************************************************************/
		/* DispatchMessage会将消息传给窗口函数去处理。消息发生之时，操作系统根据
		当时的状态，为它标明了所属窗口而窗口所属的窗口类又已经明白标识了窗口函数
		（也就是wndcls.lpfnWndProc）,所以DispatchMessage自有脉络可寻*/
		/************************************************************************/
		
		
	}
	return 0;
}
/************************************************************************/
/* 窗口的生命中枢:窗口函数。窗口函数通常利用switch/case方式判断消息的种类，
以决定处置方式，由于它是被Windows系统所调用的，所以这是一种call back 函数，
意思是指在你的程序中，被Windows系统调用的函数，这些函数虽然是由你设计，
 但是永远不会也不该被你调用，他们是为Windows系统准备的                                         */
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
	 {HWMD　hwnd;
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
	 case WM_KEYUP:	 //当键盘释放时产生WM_KEYUP消息
		 hdc=GetDC(hwnd);
		 sprintf(szStr, "%c按键被释放\r", wParam);
		 TextOut(hdc,100,50,szStr,strlen(szStr));
		 ReleaseDC(hwnd,hdc);
		 break;
	 case WM_KEYDOWN: //当键盘按下时产生WM_KEYDOWN消息 
		 hdc=GetDC(hwnd);
		 sprintf(szStr, "%c按键被按下\r", wParam);
		 TextOut(hdc,100,0,szStr,strlen(szStr));
		 ReleaseDC(hwnd,hdc);
		 break;
	 case WM_CLOSE:
		 if(IDYES==MessageBox(hwnd,"是否真的结束?","KeyMessageDemo",MB_YESNO))
		 {
			 DestroyWindow(hwnd);
		 }
		 break;
	 case WM_DESTROY:
		 PostQuitMessage(0);
		 break;
	 default:
		 return DefWindowProc(hwnd,uMsg,wParam,lParam);
		 //不论是什么消息都必须处理，所以switch/case指令中的default:处必须调用DefWindowProc,这是Windows内部默认的消息处理函数
	 }
	 return 0;
 }


