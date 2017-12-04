#pragma once
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Stack.h"

void loadFromFile(std::string, POINT*);
void saveToFile(std::string, POINT*);
void loadSteckFromFile(std::string, Stack&);
void saveStackToFile(std::string, Stack&);
