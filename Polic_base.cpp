//Polic_base.cpp

#include "Car.h"
#include "Polic_base.h"

void Polic_base::del_three(Car* rt)
{
	if (rt)
	{
		if (rt->left)del_three(rt->left);
		if (rt->right)del_three(rt->right);
		delete rt;
	}
}

void Polic_base::Add(Car* obj) 
{
	if (root == NULL) root = new Car(*obj);
	else Insert(obj, root);
}

void Polic_base::Insert(Car* obj, Car* rt)
{
	if (obj->Number == rt->Number)
	{
		string buf{ "" };
		while (!obj->Violations->empty())
		{
			buf = obj->Violations->front();
			obj->Violations->pop_front();
			rt->Violations->push_back(buf);
		}
	}
	else
		if (obj->Number < rt->Number)
			if (rt->left) Insert(obj, rt->left);
			else rt->left = new Car(*obj);
		else
			if (rt->right) Insert(obj, rt->right);
			else rt->right = new Car(*obj);
}



void Polic_base::Print() 
{
	if (root == NULL) { cout << "Tree empty!" << endl; return; }
	else Print_all(root);
}

void Polic_base::Print_all(Car* rt) 
{
	if (rt) 
	{
		if (rt->left)Print_all(rt->left);
		{ 
			rt->Show(); 
			cout << endl; 			
		}
		if (rt->right)Print_all(rt->right);
	}
	else return;
}

//печать одной записи Ѕƒ
void Polic_base::Print_car(Car* rt) 
{
	rt->Show();
}

//поиск авто по номеру
Car* Polic_base::Search_car(string num) 
{

	if (root == NULL) { cout << "\nNo car!"; return NULL; }
	if (num.empty())
	{
		string buf;
		cout << "\n\t¬ведите номер автомобил€(јјххххјј):";
		cin >> buf;
		return Search(buf, root);
	}
	else return Search(num, root);
}

Car* Polic_base::Search(string num, Car* rt) 
{
	if (num == rt->Number) { return rt; }
	else
		if (num < rt->Number)
			if (rt->left) return Search(num, rt->left);
			else return NULL; 
		else
			if (rt->right) return Search(num, rt->right);
			else   return NULL; 
}

void Polic_base::PrintRange()
{
	string range1, range2;
	cout << "\n\t¬ведите верхнюю границу дипазона: ";
	cin >> range1;
	cout << "\n\t¬ведите нижнюю границу дипазона : ";
	cin >> range2;

	if (root == NULL) { cout << "Tree empty!" << endl; return; }
	else PrintRange(root, range1, range2);
}

void Polic_base::PrintRange(Car* rt, string rng1, string rng2)
{
	if (rt)
	{
		if (rt->left)PrintRange(rt->left, rng1, rng2);
		{ 
			if (rt->Number<=rng1 && rt->Number>=rng2)
			{
				rt->Show(); cout << endl;
			}
			
		}
		if (rt->right)PrintRange(rt->right, rng1, rng2);
	}
	else return;
}

void Polic_base::Print_file()
{
	if (root == NULL) { cout << "Tree empty!" << endl; return; }
	else Print_all_file(root);
}

void Polic_base::Print_all_file(Car* rt)
{
	
	if (rt)
	{
		if (rt->left)Print_all_file(rt->left);
		{		
			fstream fileBD;
			fileBD.open("BD_GAI.txt", ios::out | ios::app);
			if (!fileBD) { perror("fileBD_error"); exit(0); }
			fileBD << rt->Number << endl;
			fileBD << rt->Avto << endl;
			fileBD << rt->Name << endl;
			fileBD << rt->Phone << endl;
			copy(rt->Violations->begin(), rt->Violations->end(), ostream_iterator<string>(fileBD, "\n"));
			fileBD << ";" << endl;
			fileBD.close();
		}
		if (rt->right)Print_all_file(rt->right);
	}
	else return;
}

void Polic_base::Add_file()
{
	Polic_base* BD1 = new Polic_base;
	fstream fileBD;
	fileBD.open("BD_GAI.txt", ios::in );
	if (!fileBD) { perror("fileBD_error"); exit(0); }
	string s;
	//getline(fileBD, s);
	while (!fileBD.eof())
	{	
		getline(fileBD, s);
		if (s == "") break;
		Car* temp = new Car;
		temp->Number = s;
		getline(fileBD, s);
		temp->Avto = s;
		getline(fileBD, s);
		temp->Name = s;
		getline(fileBD, s);
		temp->Phone = s;

		while (100)
		{
			getline(fileBD, s);
			if (s == ";") break;
			else temp->Violations->push_back(s);
			if (fileBD.eof()) break;
		}
		BD1->Add(temp);
		//if (fileBD.eof()) break;
	}
	BD1->Print();
	fileBD.close();
}


