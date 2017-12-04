#include "window.h"


window::window()
{
	// �������� ������������� ����
	hwnd = GetConsoleWindow();
	
	// �������� �������� �����������
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
