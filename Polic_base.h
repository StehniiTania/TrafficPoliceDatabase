//Polic_base.h

#pragma once
#include "Car.h"

class Polic_base
{
private:
	Car* root;

public:
	Polic_base() { root = NULL; }
	~Polic_base() { del_three(root); }
	void del_three(Car* rt); //удаление всего дерева
	void Add(Car* obj); //добавление нового автомобиля
	void Insert(Car* obj, Car* rt);
	void Print();
	void Print_all(Car* rt);
	void Print_car(Car* rt);
	Car* Search_car(string num);//поиск по номеру
	Car* Search(string num, Car* rt);//поиск от узла rt
	void PrintRange();//печать данных из диапазона
	void PrintRange(Car* rt, string rng1, string rng2);
	void Print_file();
	void Print_all_file(Car* rt);
	void Add_file();//извлечение информации из файла
};




