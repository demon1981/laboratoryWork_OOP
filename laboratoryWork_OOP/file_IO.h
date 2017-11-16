#pragma once
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>

void loadFromFile(std::string, POINT*);
void saveToFile(std::string, POINT*);
