#include <iostream>
#include <Windows.h>
#include <ctime>
#include "TList.h"
#include "TPolinom.h"
#include "TArithmeticExpression.h"
#include "LinArrTable.h"
#include "HashTable1.h"
#include "ChainHashTable.h"
using namespace std;
TMonom Generate_rand_monom(time_t seed) {
	srand(seed);
	int start = 0; int end = 9;
	int degX = rand() % (end - start + 1) + start;
	int degY = rand() % (end - start + 1) + start;
	int degZ = rand() % (end - start + 1) + start;

	start = 100; end = 900;
	int tmp = rand() % (end - start + 1) + start;
	double coef = (double)tmp / 100;
	TMonom mon(coef, degX, degY, degZ);
	return mon;
}




int main() 
{
	setlocale(LC_ALL, "ru");
	//ОБЪЯВЛЯЕМ ТАБЛИЦЫ
	LinArrTable<string, TPolinom> LinArrTable;


	//HashTable1<string, TPolinom> HashTable;
	//ChainHashTable<string, TPolinom> ChainHashTable;


	time_t seed;
	bool flag = true;
	int op = 0, counter = 0;
	string str, name, key;
	string tmp = "LinArrTable";
	TPolinom* tmp_pol = nullptr;
	basetable<string, TPolinom>* active_table = &LinArrTable;

	while (flag) 
	{
		cout << "________________________________________________________________________\n";
		cout << "Меню:\n1) Добавить полином\n2) Удалить полином\n3) Найти полином по ключу\n4) Напечатать активную таблицу\n5) Назначить активную таблицу\n6) Выход\nВведите номер операции: ";
		cin >> op;
		
		switch (op)
		{
		case 1:
			system("cls");
			cout << "Введите полином в следующем формате: 1,0*x^1*y^1*z^1+2,0*x^2*y^2*z^2\n" << "Чтобы сгенерировать случайный полином введите 0\n";
			cin >> str;
			if (str == "0") {
				TPolinom tmp;
				seed = time(0);
				TMonom m1 = Generate_rand_monom(seed);
				TMonom m2 = Generate_rand_monom(seed*2);
				//cout << "\nm1 = " << m1 << "\nm2 = " << m2;//////////////

				tmp.AddMonom(m1); tmp.AddMonom(m2);
				TPolinom* pol = new TPolinom(tmp);

				//cout << "\nВведенный полином:\n" << *pol << "\n";//////////////
				counter++;
				name = "pol" + to_string(counter);

				//ДОБАВЛЯЕМ ВО ВСЕ ТАБЛИЦЫ
				LinArrTable.Insert(name, pol);
				//
				//
				//
				//
				//

			}
			else 
			{
				TPolinom* pol = new TPolinom(str);
				cout << "\nВведенный полином:\n" << pol;//////////////
				//ДОБАВЛЯЕМ ВО ВСЕ ТАБЛИЦЫ
				LinArrTable.Insert(name, pol);
				//
				//
				//
				//
				//
			}
			
			break;

		case 2:
			//ИЗМЕНИТЬ ТАБЛИЦЫ ОТКУДА УДАЛЯЕМ
			system("cls");
			cout << "По какому ключу удалить полином: ";
			cin >> key;
			tmp_pol = active_table->Find(key);
			if (tmp_pol != nullptr)
				cout << "Удаленный полином: " << *tmp_pol << "\n";
			else
				cout << "\nПолином не найден\n";

			LinArrTable.Delete(key);
			//
			//
			//
			//
			//

			break;

		case 3:
			system("cls");
			cout << "По какому ключу найти полином: ";
			cin >> key;
			tmp_pol = active_table->Find(key);
			if (tmp_pol != nullptr)
				cout << "Найденный полином: " << *tmp_pol << "\n";
			else
				cout << "\nПолином не найден\n";
			break;


		case 4:
			system("cls");
			cout << tmp << ":\n";
			if (active_table == nullptr)
				cout << "Не выбрана активная таблица";
			else
				cout << *active_table << "\n";
			break;


		case 5:
			//ИЗМЕНИТЬ ПРИСВАИВАЕМЫЕ ТАБЛИЦЫ
			system("cls");
			
			cout << "1)LinArrTable\n2)LinListTable\n3)OrderArrTable\n4)TreeTable\n5)HashTable\n6)ChainHashTable\nВыбор активной таблицы: ";
			cin >> tmp;
			if (tmp == "LinArrTable")
				active_table = &LinArrTable;
			else if (tmp == "LinListTable")
				active_table = &LinArrTable;
			else if (tmp == "OrderArrTable")
				active_table = &LinArrTable;
			else if (tmp == "TreeTable")
				active_table = &LinArrTable;
			else if (tmp == "HashTable")
				active_table = &LinArrTable;
			else if (tmp == "ChainHashTable")
				active_table = &LinArrTable;
			else cout << "Что-то не так с выбором активной таблицы\n";
			system("cls");
			break;

		case 6:
			flag = false;
			break;


		default:
			system("cls");
			cout << "Неверный номер операции\n";
			break;
		}
	}
}