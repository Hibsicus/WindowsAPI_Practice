// DemoWindows.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <Windows.h>

HINSTANCE hinst;

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//�D�禡 
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�w�q���f���O
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
   
	//���U���f
	if (!RegisterClassEx(&wcx))
	{
		return 1;
	}
	


	//�b�o��Ыص��f
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
	
	//�`������
	while (fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0) != 0)
	{
		//½Ķ����
		TranslateMessage(&msg);
		//��o����
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//���f�L�{ �ΨӳB�z���f����
	switch (uMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
