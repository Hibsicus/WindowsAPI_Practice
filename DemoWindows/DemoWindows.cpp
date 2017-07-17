// DemoWindows.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <Windows.h>

HINSTANCE hinst;

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//主函式 
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//定義窗口類別
	WNDCLASSEX wcx;
	HWND hwnd;

	MSG msg;
	BOOL fGotMessage;

	hinst = hinstance;

	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = MainWndProc; //!!!!
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hinstance;
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.lpszMenuName = NULL;
	wcx.hIconSm = (HICON)LoadImage(hinstance,
		MAKEINTRESOURCE(5), IMAGE_ICON,
		GetSystemMetrics(SM_CXSMICON),
		GetSystemMetrics(SM_CYSMICON),
		LR_DEFAULTCOLOR);
	wcx.lpszClassName = "MainWClass";
   
	//註冊窗口
	if (!RegisterClassEx(&wcx))
	{
		return 1;
	}
	


	//在這邊創建窗口
	hwnd = CreateWindow("MainWClass", "Hello",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(HWND)NULL,
		(HMENU)NULL,
		hinst,
		(LPVOID)NULL
	);

	if (!hwnd)
	{
		return 1;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	//循環消息
	while (fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0) != 0)
	{
		//翻譯消息
		TranslateMessage(&msg);
		//轉發消息
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//窗口過程 用來處理窗口消息
	switch (uMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
