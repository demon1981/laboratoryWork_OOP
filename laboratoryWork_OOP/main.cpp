#include <windows.h> 
#include <windowsx.h> 
#include <stdio.h> 
#include <conio.h> 
void main ( ) { 
	// получаем идентификатор окна 
	HWND hwnd = GetConsoleWindow ( ); // получаем контекст отображения HDC hdc = GetDC (hwnd); RECT rt; char buf[100]; // устанавливаем цвет фона SetBkColor (hdc, RGB(0, 0, 0)); // устанавливаем цвет текста SetTextColor (hdc, RGB(255, 0, 0)); // создаем красное перо HPEN hRedPen = CreatePen (PS_SOLID, 5, RGB(255, 0, 0)); // и выбираем его в контекст отображения, // сохраняя предыдущее перо HPEN hOldPen = SelectPen (hdc, hRedPen); // создаем зеленую кисть HBRUSH hGreenBrush = CreateSolidBrush (RGB(0, 255, 0));