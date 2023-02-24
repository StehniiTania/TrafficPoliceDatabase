//Car.h

#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <list>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

class Polic_base;

class Car
{
private:
	string Number;   //����� ����
	string Avto;  //����� ����
	string Name;  //��� ��������
	string Phone;    //������� ��������
	list<string>* Violations; //������ ��������������
	Car* parent;
	Car* left;
	Car* right;

public:
	Car();
	~Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	void *Show();  //�������� ���������� �� ����
	void Add();
	//���������� ���������� �� ����������
	void Add_Viol();	
	Car* MakeCarRandom();

	friend class Polic_base;
};




