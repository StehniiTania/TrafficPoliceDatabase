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
	string Number;   //номер авто
	string Avto;  //марка авто
	string Name;  //ФИО водителя
	string Phone;    //телефон водителя
	list<string>* Violations; //список правонарушений
	Car* parent;
	Car* left;
	Car* right;

public:
	Car();
	~Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	void *Show();  //просмотр информации по авто
	void Add();
	//добавление информации по нарушениям
	void Add_Viol();	
	Car* MakeCarRandom();

	friend class Polic_base;
};




