#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <stdio.h>
#include <conio.h>
#include "file_IO.h"
#include "window.h"
#include "Rhombus.h"
#include "Stack.h"


void clearScreen()
{
	InvalidateRect(window::getContext().getHwnd(), 0, true);
	UpdateWindow(window::getContext().getHwnd());
	system("cls");
}

void move(Rhombus &r)
{	
	r.incX();
	r.draw(window::getContext().getHdc());
}

void popAllStack(Stack &stack, HDC hdc)
{
	do {
		clearScreen();
		Rhombus rmb(stack.pop());
		stack.printAll(hdc);
		rmb.draw(hdc);

	} while (_getch() != 27 && stack.size() != 0);
}

void drawAll(Stack &stack, HDC hdc) 
{	
	for (size_t i = 0; i < stack.size(); i++)
	{	
		stack[i].draw(hdc);
	}	
	_getch();
}

void dialogWithUser() {

	HDC hdc = window::getContext().getHdc();
	HWND hwnd = window::getContext().getHwnd();
	RECT rt = window::getContext().getRt();

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 0, 0));

	HPEN hBluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectPen(hdc, hBluePen);

	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectBrush(hdc, hBlackBrush);

	Stack stack(10);
	
	//POINT ppt1[4] = { { 10, 55 },{ 40, 40 },{ 70, 55 },{ 40,70 } };
	//POINT ppt2[4] = { { 10, 255 },{ 40, 240 },{ 70, 255 },{ 40, 270 } };
	//POINT ppt3[4] = { { 500, 55 },{ 530, 40 },{ 560, 55 },{ 530,70 } };
	//POINT ppt4[4] = { { 500, 255 },{ 530, 240 },{ 560, 255 },{ 530,270 } };	
	//stack.push(Rhombus(ppt1));
	//stack.push(Rhombus(ppt2));	
	//stack.push(Rhombus(ppt3));	
	//stack.push(Rhombus(ppt4));
	loadSteckFromFile("stack.dat", stack);

	char c;
	bool quit = false;

	while (quit != true) {
		clearScreen();
		std::cout << "Select action (d-draw, p-print all, s-pop all, l - load, w - save, q-exit) > ";
		
		std::cin >> c;
		clearScreen();
		
		switch (c) {		
			case 'p':			
				stack.printAll(hdc);
				_getch();
				break;		
			case 'd':				
				drawAll(stack, hdc);
				break;
			case 's':				
				popAllStack(stack, hdc);
				break;
			case 'l':
				loadSteckFromFile("stack.dat", stack);
				break;
			case 'w':				
				saveStackToFile("stack1.dat", stack);
				break;
			case 'q':
				quit = true;
				break;
			default:
				printf("Invalid command!");
		}		
	}
}

void main() {

	dialogWithUser();	
	_getch();
	system("PAUSE");
}
