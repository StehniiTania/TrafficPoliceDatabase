//GAI_main.cpp
//Реализовать базу данных ГАИ по штрафным квитанциям с помощью бинарного 
// дерева.Ключом будет служить номер автомашины, значением узла — список 
// правонарушений.Если квитанция добавляется в первый раз, то в дереве 
// появляется новый узел, а в списке данные по правонарушению; если нет, 
// то данные заносятся в существующий список.Необходимо также реализовать 
// следующие операции :
//•	Полная распечатка базы данных(по номерам машин и списку правонарушений, 
// числящихся за ними);
//•	Распечатка данных по заданному номеру;
//•	Распечатка данных по диапазону номеров;
//•	Сохраняйте и загружайте информацию из файла.


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
    cout << "\n\t БАЗА ДАННЫХ НАРУШЕНИЙ ГАИ:";
    cout << "\n\t ==========================";
    cout << "\n\tЧто вы хотите делать: \n";
    cout << "\n\t0 - Создание рандомной БД";
    cout << "\n\t1 - Посмотреть БД";
    cout << "\n\t2 - Найти запись по номеру авто";
    cout << "\n\t3 - Добавление новой записи";
    cout << "\n\t4 - Просмотр данных по заданному диапазону";
    cout << "\n\t5 - Пeредача данных БД в файл";
    cout << "\n\t6 - Извлечение данных из файла";
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
    cout << "\n\tВведите размер БД: ";
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
    else cout << "\n\tАвтомобиль не найден!";
}

void Add_car(Polic_base* bd)
{
    Car* temp = new Car;
    string buf;
    cout << "\n\tВведите номер автомобиля(ААххххАА):";
    cin >> buf;
    temp = bd->Search_car(buf);
    if (temp != NULL) //если номер существует
    {
        bd->Print_car(temp);
        temp->Add_Viol();
        bd->Print_car(temp);
    }
    else //если номер новый, создаем новую запись
    {
        Car* temp1 = new Car;
        temp1->Add();
        bd->Add(temp1);      
    }
}