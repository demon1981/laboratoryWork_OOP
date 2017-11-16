//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "file_IO.h"
#include "window.h"
#include "Rhombus.h"

void drow()
{
	HDC hdc = window::getContext().getHdc();
	HWND hwnd = window::getContext().getHwnd();
	RECT rt = window::getContext().getRt();
		
	SetBkColor(hdc, RGB(0, 0, 0));	
	SetTextColor(hdc, RGB(255, 0, 0));
	
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));	
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));	
	SelectBrush(hdc, hGreenBrush);
			
	POINT ppt1[4];
	loadFromFile("data1.dat", ppt1);
	Rhombus rhomb1(ppt1);
	rhomb1.drow(hdc);

	//HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH hBlueCrossBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 255));
	SelectBrush(hdc, hBlueCrossBrush);
	
	POINT ppt2[4];
	loadFromFile("data2.dat", ppt2);
	Rhombus rhomb2;
	rhomb2.setPoints(ppt2);
	rhomb2.drow(hdc);

	saveToFile("data1.dat", rhomb1.getPoints());
	saveToFile("data2.dat", rhomb2.getPoints());

	/*POINT ppt3[4] = {{10, rt.bottom/2},
					{rt.right/2, 10},
					{rt.right - 10, rt.bottom / 2},
					{rt.right/2, rt.bottom - 10}};
	
	saveToFile("data1.dat", ppt3);*/
	/*POINT ppt2[4];
	loadFromFile("data.dat", ppt2);*/
	/*for (size_t n = 0; n < 4; ++n) {
		std::cout << ppt2[n].x << " " << ppt2[n].y << "\n";
	};*/

	/*Rhombus r1(ppt2);
	r1.drow(hdc);*/
	//			
	//Rhombus r;
	//POINT ppt2[4] = { { 50, rt.bottom / 2 },
	//				{ rt.right / 2, 50 },
	//				{ (rt.right - 50), rt.bottom / 2 },
	//				{ rt.right / 2, rt.bottom - 50 } };
	//	
	//r.setPoints(ppt2);
	//r.drow(hdc);
	//saveToFile("data2.dat", r.getPoints());
}

void main() {

	drow();
	_getch();
	//system("PAUSE");
}
