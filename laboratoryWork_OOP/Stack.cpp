#include "Stack.h"

Stack::Stack() { }

Stack::Stack(size_t size) : _capacity(size), _arr(new Rhombus[size]), _size(0) { }


Stack::~Stack()
{
	delete[] _arr;
}

void Stack::push(Rhombus r)
{	
	_arr[_size++] = r;
}

Rhombus Stack::pop()
{
	if (_size != 0)
	{
		return _arr[--_size];
	}
	return _arr[0];
}

Rhombus& Stack::operator[](size_t n)
{
	return _arr[n];
}

size_t Stack::size()
{
	return _size;
}

void Stack::printAll(const HDC &hdc)
{
	int yText = 0;
	for (size_t i = 0; i < _size; i++)
	{
		POINT *p = _arr[i].getPoints();
		std::ostringstream ost;
		ost << "(" << p[0].x << ", " << p[0].y << ") (" << p[1].x << ", " << p[1].y << ") (" << p[2].x << ", " << p[2].y << ") (" << p[3].x << ", " << p[3].y << ")\n";
		ost.flush();
		TextOutA(hdc, 0, yText, ost.str().c_str(), ost.str().size());
		yText += 15;
	}
}

