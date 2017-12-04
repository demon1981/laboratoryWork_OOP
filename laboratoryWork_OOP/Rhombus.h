#pragma once
#include <windows.h>
#include <windowsx.h>
#include <utility> 

class Rhombus
{
	POINT *_data;

public:
	Rhombus();
	Rhombus(POINT*);
	Rhombus(Rhombus&);
	~Rhombus();

	void setPoints(POINT*);
	void draw(const HDC&);
	POINT* getPoints();
	void incX();
};

