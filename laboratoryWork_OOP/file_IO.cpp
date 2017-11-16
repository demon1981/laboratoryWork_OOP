#include "file_IO.h"
#include <iostream>

void saveToFile(std::string file, POINT *pnt){
	
	std::ofstream fout; 
	fout.open(file);	

	for (size_t n = 0; n < 4; ++n) {
		fout << pnt[n].x << " " << pnt[n].y << "\n";
	};	
	fout.close(); 	
}

void loadFromFile(std::string file, POINT *pnt){
	
	std::ifstream fin;
	fin.open(file);

	char buff[10];	
	//POINT p[4];
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

	//return p;

	//FILE *input = NULL;
 //   input = fopen(file.data, "rb");
 //   if (input == NULL) {
 //       printf("Error opening file\n");
 //       return -1;
 //   }
 //   
	//int id = 0;
 //   fread(&id, sizeof(int), 1, input);
 //   if(id != 42){	
	//	printf("Data file is damaged\n");
	//	return -1;
	//}
 //   
	//fread(tripsSize, sizeof(int), 1, input);//считываем размер данных в файле  
	//
	//if(*tripsSize == 0){//если размер данных в файле 0, вернем ошибку			
	//	return -1;
	//}	
	//
	//*tripsSize *= 2;//выделим в два раза больеш места под данные     	
 //   *trips = (trip*) malloc((*tripsSize)*sizeof(trip));
 //   
	//for(int i = 0; i < *tripsSize; i++)//очистим выделеную область
 //   	(*trips)[i].num = 0;
 //   
	//fread(*trips, sizeof(trip), *tripsSize, input);//считываем данные массива структур	
	//
	//for(int i = 0; i < *tripsSize; i++)//очистим выделеную область
 //   	int a = 0;
	
	//fclose(input);
}
