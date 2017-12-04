#include "Rhombus.h"


Rhombus::Rhombus() {}

Rhombus::Rhombus(POINT *p) : _data(p) { }

Rhombus::Rhombus(Rhombus & rmb): _data(rmb.getPoints()) { }

Rhombus::~Rhombus() 
{
	//delete[] _data;
}

void Rhombus::setPoints(POINT *p)
{
	_data = p;
}

void Rhombus::draw(const HDC &hdc)
{
	Polygon(hdc, _data, 4);
}

POINT * Rhombus::getPoints()
{
	return _data;
}

void Rhombus::incX()
{

	for (size_t i = 0; i < 4; i++)
	{
		_data[i].x += 20;
	}

}

