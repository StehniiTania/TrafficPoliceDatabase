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
	void del_three(Car* rt); //�������� ����� ������
	void Add(Car* obj); //���������� ������ ����������
	void Insert(Car* obj, Car* rt);
	void Print();
	void Print_all(Car* rt);
	void Print_car(Car* rt);
	Car* Search_car(string num);//����� �� ������
	Car* Search(string num, Car* rt);//����� �� ���� rt
	void PrintRange();//������ ������ �� ���������
	void PrintRange(Car* rt, string rng1, string rng2);
	void Print_file();
	void Print_all_file(Car* rt);
	void Add_file();//���������� ���������� �� �����
};




