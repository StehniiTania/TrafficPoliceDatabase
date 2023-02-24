//GAI_main.cpp
//����������� ���� ������ ��� �� �������� ���������� � ������� ��������� 
// ������.������ ����� ������� ����� ����������, ��������� ���� � ������ 
// ��������������.���� ��������� ����������� � ������ ���, �� � ������ 
// ���������� ����� ����, � � ������ ������ �� ��������������; ���� ���, 
// �� ������ ��������� � ������������ ������.���������� ����� ����������� 
// ��������� �������� :
//�	������ ���������� ���� ������(�� ������� ����� � ������ ��������������, 
// ���������� �� ����);
//�	���������� ������ �� ��������� ������;
//�	���������� ������ �� ��������� �������;
//�	���������� � ���������� ���������� �� �����.


#include "Car.h"
#include "Polic_base.h"

void CreateRandom(Polic_base* bd);
void Main_Menu(Polic_base* bd);
void Search(Polic_base* bd);
void Add_car(Polic_base* bd);

int main()
{
	//setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	
	Polic_base *BD = new Polic_base;
	
    Main_Menu(BD);

	return 0;
}

void Main_Menu(Polic_base* bd)
{
    system("cls");
    int key;
    cout << "\n\t ���� ������ ��������� ���:";
    cout << "\n\t ==========================";
    cout << "\n\t��� �� ������ ������: \n";
    cout << "\n\t0 - �������� ��������� ��";
    cout << "\n\t1 - ���������� ��";
    cout << "\n\t2 - ����� ������ �� ������ ����";
    cout << "\n\t3 - ���������� ����� ������";
    cout << "\n\t4 - �������� ������ �� ��������� ���������";
    cout << "\n\t5 - �e������ ������ �� � ����";
    cout << "\n\t6 - ���������� ������ �� �����";
    cout << "\n\t7 - Exit\n\t";
    cin >> key;
    switch (key)
    {
    case 0: CreateRandom(bd);    
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;    
    case 1: bd->Print();
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;
    case 2: Search(bd);
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;
    case 3: Add_car(bd);
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break; 
    case 4: bd->PrintRange();
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;
    case 5: bd->Print_file();
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;
    case 6: bd->Add_file();
        cout << "\n\t";
        system("pause");
        Main_Menu(bd);
        break;
    case 7: return;
    default: return;
    }
}

void CreateRandom(Polic_base *bd)
{
    Car* temp = new Car;
    cout << "\n\t������� ������ ��: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        temp = temp->MakeCarRandom();
        bd->Add(temp);
    }
}

void Search(Polic_base* bd)
{ 
    Car * temp = new Car; 
    temp = bd->Search_car(""); 
    if (temp != NULL)
        bd->Print_car(temp);
    else cout << "\n\t���������� �� ������!";
}

void Add_car(Polic_base* bd)
{
    Car* temp = new Car;
    string buf;
    cout << "\n\t������� ����� ����������(��������):";
    cin >> buf;
    temp = bd->Search_car(buf);
    if (temp != NULL) //���� ����� ����������
    {
        bd->Print_car(temp);
        temp->Add_Viol();
        bd->Print_car(temp);
    }
    else //���� ����� �����, ������� ����� ������
    {
        Car* temp1 = new Car;
        temp1->Add();
        bd->Add(temp1);      
    }
}