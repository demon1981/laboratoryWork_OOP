#pragma once
#include <windows.h>
#include <windowsx.h>

class window
{
private:
	//поля класса
	HWND hwnd;	
	HDC hdc;
	RECT rt;

	//конструкторы
	window();	
	window(window const&);
	window operator=(window const&);
	~window();		

public:
	static window& getContext()
	{
		static window w;
		return w;
	}
	HDC& getHdc();
	HWND getHwnd();
	RECT getRt();
};

