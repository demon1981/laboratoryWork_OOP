#include "file_IO.h"


void saveToFile(std::string file, POINT *pnt){
	
	std::ofstream fout; 
	fout.open(file);	

	for (size_t n = 0; n < 4; ++n) {
		fout << pnt[n].x << " " << pnt[n].y << "\n";
	};	
	fout.close(); 	
}

void loadSteckFromFile(std::string file, Stack &stack)
{
	std::ifstream fin;
	fin.open(file);

	char buff[10];

	POINT *pnt = new POINT[4];
	int i = 0;
	//for (size_t i = 0; i < 4; i+
	while(fin.getline(buff, 50))
	{
				
		//fin.getline(buff, 50);
		char *sp = strstr(buff, " ");//ищем пробел
		char num[25] = "\0";
		int n = 0;
		for (char *c = buff; c != sp; c++, n++)//выбираем цифры до пробела
		{
			num[n] = *c;
		}
		num[n] = '\0';

		pnt[i].x = atol(num);//преобразуем в число

		n = 0;
		for (char *c = ++sp; *c != '\0'; c++, n++)//выбираем цифры от пробела до \0
		{
			num[n] = *c;
		}
		num[n] = '\0';

		pnt[i].y = atol(num);//преобразуем в число

		if (i == 3)//если набрали 4 точки, сбарсываем стек
		{
			stack.push(Rhombus(pnt));
			pnt = new POINT[4];
			i = 0;
		}
		else
			i++;

	}
	fin.close();

}

void saveStackToFile(std::string fileName, Stack &stack)
{
	std::ofstream fout;
	fout.open(fileName);
	size_t stackSize = stack.size();
	for (size_t i = 0; i < stackSize; i++)
	{
		Rhombus rmb(stack.pop());
		POINT *pointPtr = rmb.getPoints();
		
		for (size_t n = 0; n < 4; ++n) {
			fout << pointPtr[n].x << " " << pointPtr[n].y << "\n";
		};
	};
	fout.close();
}

void loadFromFile(std::string file, POINT *pnt){
	
	std::ifstream fin;
	fin.open(file);

	char buff[10];	
	
	for (size_t i = 0; i < 4; i++)
	{
		fin.getline(buff, 50);				
		char *sp = strstr(buff, " ");
		char num[25] = "\0";
		int n = 0;
		for (char *c = buff; c != sp; c++, n++)
		{
			num[n] = *c;
		}
		num[n] = '\0';

		pnt[i].x = atol(num);

		n = 0;
		for (char *c = ++sp; *c != '\0'; c++, n++)
		{
			num[n] = *c;
		}
		num[n] = '\0';

		pnt[i].y = atol(num);
	}	
	fin.close();	
}
