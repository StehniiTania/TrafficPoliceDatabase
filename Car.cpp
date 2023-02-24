//Car.cpp

#include "Car.h"

Car::Car()
{
	Number = "";
	Name = "";
	Avto = "";
	Phone = "";
	Violations = new list<string>;
}

Car::~Car()
{
	if (Violations) delete Violations;	
}

Car::Car(const Car& other)  
{
	Number = other.Number;
	Name = other.Name;
	Avto = other.Avto;
	Phone = other.Phone;
	Violations = new list<string>;
	*Violations = *other.Violations;
	left = NULL;
	right = NULL;
}

Car& Car::operator=(const Car& other) 
{
	if (&other == this) return *this;
	Number = other.Number;
	Name = other.Name;
	Avto = other.Avto;
	Phone = other.Phone;
	*Violations = *other.Violations;
	return *this;
}

void *Car::Show()
{
	if (Number == "") { cout << "\n\tError!"; exit; }
	cout << "\n\t����� ����������: " << Number;
	cout << "\n\t������ ����: " << Avto;
	cout << "\n\t��� ���������: " << Name;
	cout << "\n\t����� ��������: " << Phone;
	cout << "\n\tC����� ��������������:\n\t";
	copy(Violations->begin(), Violations->end(), ostream_iterator<string>(cout, "\n\t"));
	return 0;
}

void Car::Add()
{	

	cout << "\n\t����� ����������: ";
	cin.ignore();
	getline(cin, Number);	
	cout << "\n\t������ ����: ";
	cin.ignore();
	getline(cin, Avto);	
	cout << "\n\t��� ���������: ";
	cin.ignore();
	getline(cin, Name);	
	cout << "\n\t����� ��������: ";
	cin.ignore();
	getline(cin, Phone);	
	Add_Viol();
}

void Car::Add_Viol()
{
	string temp;
	int key;
	cout << "\n\t�������� ������ � ��������������: ";
	cin.ignore();
	getline(cin, temp);	
	Violations->push_back(temp);
	cout << "\n\t������ �������� ��� ���� ��������������? �� - 1, ��� - 0 ";
	cin >> key;
	if (key == 1) return Add_Viol();
	else return;
}

Car* Car::MakeCarRandom()
{
	Car* a1 = new Car;
	string letter{ "WRTIOPASDFGHKJLZCVBNM" };
	string letter_ru{ "����������������������" };
	string num{ "0123456789" };
	//�������� ���������� ������
	for (int i = 0; i < 2; i++)
		a1->Number = a1->Number + letter[rand() % 21];
	for (int i = 0; i < 4; i++)
		a1->Number = a1->Number + num[rand() % 10];
	
	//����� ��������� ������� � ���������
	string surn[10]{ "����������", "������", "�����������", "���������",
		"������������", "�������","�����","����������","����������","����������" };
	a1->Name = surn[rand() % 10] + " " + letter_ru[rand() % 22] + ". " + letter_ru[rand() % 22] + ".";
	
	//����� ��������� ������
	string avto[10]{ "Opel", "Renault", "BMW", "Toyota", "Mersedes",
		"Volvo", "Mazda", "Nissan", "Audi", "Ford" };	
	a1->Avto = avto[rand() % 10] + " " + letter[rand() % 21] + letter[rand() % 21]
		+ num[rand() % 10] + num[rand() % 10] + num[rand() % 10];
	
	//������������ ���������� ��������
	string tel[11]{ "067","096","097","098","068","050","095","099","066","063","093" };
	a1->Phone = tel[rand() % 11];
	for (int i = 3; i < 13; i++)
		a1->Phone = a1->Phone + num[rand() % 10];
	a1->Phone[3] = '-';
	a1->Phone[7] = '-';
	a1->Phone[10] = '-';
	
	//������������ ��������������
	string viol[6]{ "���������� �������� �� 20 ��","���������� �������� ����� 20 ��",
		"�������� � ��������� ����", "�������� � ������������ �����",
		"��������� ��� ������������� ����� ������������",
		"��������� ��� ��������������� �����" };
	string fine[6]{ "510", "1700","10500", "350", "510", "510" };
	string month[12]{ "01","02","03","04","05","06","07","08","09","10","11","12" };
	string year[3]{ "2019", "2020","2021" };
	int n = rand() % 3 + 1; //���������� ���������
	for (int i = 0; i < n; i++)
	{
		string Viol;
		int y, m;
		y = rand() % 2;
		if (y == 2)
			m = rand() % 6;
		else m = rand() % 12;
		string d;
		d = num[rand() % 3];
		if (d == "0") d += num[rand() % 9 + 1];
		else d += num[rand() % 10];
		Viol = d + "." + month[m] + "." + year[y] + " ";
		int v = rand() % 6;
		Viol = Viol + viol[v] + ", ����� - " + fine[v] + " ���.";
		a1->Violations->push_back(Viol);		
	}
	
	return a1;
}




