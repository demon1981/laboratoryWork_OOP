#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream>
#include "Rhombus.h"

class Stack
{
	Rhombus *_arr;
	size_t _size;	
	size_t _capacity;

public:
	Stack();
	Stack(size_t);
	~Stack();
	
	void push(Rhombus);
	Rhombus pop();

	Rhombus& operator[](size_t);

	size_t size();

	void printAll(const HDC&);

};

