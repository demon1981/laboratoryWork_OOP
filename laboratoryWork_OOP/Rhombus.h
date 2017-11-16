#pragma once
#include <windows.h>
#include <windowsx.h>
#include <utility> 

class Rhombus
{
	//long *_data[];
	POINT *_data;

public:
	Rhombus();
	Rhombus(POINT[]);
	~Rhombus();
	void setPoints(POINT*);
	void drow(HDC&);
	POINT* getPoints();
};

