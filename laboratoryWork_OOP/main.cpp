#include <windows.h> 
#include <windowsx.h> 
#include <stdio.h> 
#include <conio.h> 
void main ( ) { 
	// �������� ������������� ���� 
	HWND hwnd = GetConsoleWindow ( ); // �������� �������� ����������� HDC hdc = GetDC (hwnd); RECT rt; char buf[100]; // ������������� ���� ���� SetBkColor (hdc, RGB(0, 0, 0)); // ������������� ���� ������ SetTextColor (hdc, RGB(255, 0, 0)); // ������� ������� ���� HPEN hRedPen = CreatePen (PS_SOLID, 5, RGB(255, 0, 0)); // � �������� ��� � �������� �����������, // �������� ���������� ���� HPEN hOldPen = SelectPen (hdc, hRedPen); // ������� ������� ����� HBRUSH hGreenBrush = CreateSolidBrush (RGB(0, 255, 0));