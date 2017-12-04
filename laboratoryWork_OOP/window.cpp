#include "window.h"


window::window()
{
	// получаем идентификатор окна
	hwnd = GetConsoleWindow();
	
	// получаем контекст отображения
	hdc = GetDC(hwnd);
	
	GetClientRect(hwnd, &rt);
	
}

window::~window()
{
	ReleaseDC(hwnd, hdc);
}

HDC& window::getHdc()
{
	return hdc;
}

HWND window::getHwnd()
{
	return hwnd;
}

RECT window::getRt()
{
	return rt;
}
