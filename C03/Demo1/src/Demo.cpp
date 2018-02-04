#include <windows.h>				//一个windows应用程序应该包含的头文件
#include <stdio.h>					//标准输入输出流文件
LRESULT CALLBACK WinSunProc		/*声明一个回调函数*/
(                                  
 HWND hwnd,      				/*窗口的句柄*/ 
 UINT uMsg,      					/*窗口的消息*/
 WPARAM wParam, 
 LPARAM lParam
 );

int WINAPI WinMain
(
 HINSTANCE hInstance,     			//实例句柄 当前应用程序的实例句柄
 HINSTANCE hPrevInstance, 			//默认这个参数为NULL
 LPSTR lpCmdLine,          			//储存一个命令行参数
 int nCmdShow)
{
	WNDCLASS wndcls;				//定义一个窗口对象
	wndcls.cbClsExtra=0;			//指定额外内存空间
	wndcls.cbWndExtra=0;			//指定额外内存空间
	//指定窗口背景色
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	//设置光标样式
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	//设置图标样式
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR); 
	wndcls.hInstance=hInstance;		//指定窗口实例句柄
	wndcls.lpfnWndProc=WinSunProc;	//指定窗口函数，即窗口主处理函数
	//窗口类名称
	wndcls.lpszClassName="Visual C++ Game";
	wndcls.lpszMenuName=NULL;		//菜单
	wndcls.style= CS_HREDRAW|CS_VREDRAW;	
	RegisterClass(&wndcls); 			//注册窗口类 
	HWND hwnd;					//声明窗口句柄
	hwnd=CreateWindow			/*创建窗口，但这里的窗口是不会显示的*/
		(
		"Visual C++ Game",          /*已注册窗口类的名称*/
		"Visual C++ 游戏开发", 		/*窗口标题*/
		WS_OVERLAPPEDWINDOW, /*窗口风格*/
		200,                        /*窗口位置的横坐标*/
		200,                        	/*窗口位置的纵坐标*/
		600,                        	/*窗口的宽度*/
		400,                        	/*窗口的高度*/
		NULL,
		NULL, 
		hInstance,                  	//实例句柄
		NULL);
	//在这里真正显示窗口
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);			//更新显示
	
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);	//转换键盘消息
		DispatchMessage(&msg);		//分派消息
	}
	return 0;
}

LRESULT CALLBACK WinSunProc(
							HWND hwnd,      			/*窗口句柄*/
							UINT uMsg,      				/*消息*/
							WPARAM wParam, 			/*参数1*/
							LPARAM lParam   			/*参数2*/
							)
{
	char tmsg[128] = {0};
	int num1, num2, num3, num4,num5;			//声明5个变量
	num1 = 3+8;							//加法运算
	num2 = 10-7;							//减法运算
	num3 = 100*33;						//乘法运算
	num4 = 155/5;						//除法运算
	num5 = 9%2;						//取模运算

	sprintf(tmsg, "3+8=%d 10-7=%d 100*33=%d 155/5=%d 9%%2=%d",
			num1, num2, num3, num4, num5);
	
	switch(uMsg)					/*判断消息类型*/
	{
	case WM_PAINT:				/*更新窗口消息*/
		HDC hDC;				/*定义 DC设备*/
		PAINTSTRUCT ps;
		hDC=BeginPaint(hwnd,&ps);	/*得到设备hDC*/
		TextOut(hDC,150,0,tmsg,strlen(tmsg));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:				/*当单击关闭按钮时，产生关闭消息*/
		if(IDYES==MessageBox(hwnd,"是否真的结束？","游戏开发",MB_YESNO))
		{
			DestroyWindow(hwnd);	/*单击确实，销毁窗口*/
		}
		break;
	case WM_DESTROY:			/*销毁窗口消息*/
		PostQuitMessage(0);		/*退出程序*/
		break;
	default:
		//在default:处必须调用DefWindowProc,这是Windows内部默认的消息处理函数
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	return 0;
}
