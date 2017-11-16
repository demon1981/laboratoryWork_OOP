#include "Rhombus.h"


Rhombus::Rhombus() {}

Rhombus::Rhombus(POINT *p) : _data(p) { }

Rhombus::~Rhombus() {}

void Rhombus::setPoints(POINT *p)
{
	_data = p;
}

void Rhombus::drow(HDC &hdc)
{
	/*POINT ppt[4] = { { 10, 140 },
					{ 300, 10 },
					{ 600, 140 },
					{ 300, 290 } };*/
	Polygon(hdc, _data, 4);
}

POINT * Rhombus::getPoints()
{
	return _data;
}

