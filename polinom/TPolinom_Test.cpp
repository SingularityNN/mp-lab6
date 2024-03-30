#include <iostream>
#include "TList.h"
#include "TPolinom.h"
#include "TArithmeticExpression.h"
#include "LinArrTable.h"
#include "HashTable1.h"
#include "ChainHashTable.h"
using namespace std;
//1,0*x^1*y^1*z^1
//15,3*x^1*y^2*z^3
//5,23*x^4*y^2*z^8

//2,2*x^2*y^3*z^2+3,5*x^6*y^6*z^6

int main()
{
	setlocale(LC_ALL, "ru");

	//Тест вычисления полинома в точке
	/*double* point = new double[3]; point[0] = 2; point[1] = 3; point[2] = 4;
	TMonom a(3.22, 1, 2, 1);
	TMonom b(4.5, 3, 3, 2);
	TPolinom ab("3,22*x^1*y^2*z^1+4,5*x^3*y^3*z^2");

	ab.Set_point();

	cout << "a = " << a.Calculate_monom(point) << endl;
	cout << "b = " << b.Calculate_monom(point) << endl;
	
	ab.Calculate_polinom();
	cout << "ab = " << ab.Get_Calculation_res();*/


	//Тест возможностей полинома (создание, умножение на константу, добавление монома к полиному, сложение и вычитание полиномов
    /*TPolinom p1;
	TMonom a(3.22, 1, 2, 1);
	TMonom b(4.5, 3, 3, 2);
	TMonom c(2.0, 1, 1, 1);


    p1.AddMonom(a);
	cout << "Полином p1 с одним мономом a(3.22, 1, 2, 1): " << p1 << endl;
	cout << "_________________________________________________" << endl;


    p1.AddMonom(b);
	cout << "К p1 добавили моном b(4.5, 3, 3, 2):" << p1 << endl;
	cout << "_________________________________________________" << endl;


	p1.MultMonom(c);
	cout << "Умножили p1 на моном c(2.0, 1, 1, 1): " << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;


	string str;
	cout << "Введите полином p2: ";
	cin >> str; 
	TPolinom p2(str);


	cout << "Полином p2 введенный с клавиатуры: " << p2.ToString() << endl;
	cout << "_________________________________________________" << endl;


	p1 = p1 - p2;
	cout << "Вычитаем p2 из p1: " << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;


	p1.AddPolinom(p2);
	cout << "p1.AddPolinom(p2):" << endl << p1.ToString() << endl; 
	cout << "_________________________________________________" << endl;


	p1 = p1 * 2.0;
	cout << "p1 = p1 * 2.0:" << endl << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;

	
	TPolinom p3;
	TPolinom p4;
	p3.AddMonom(a);

	p4.AddMonom(b);
	p4.AddMonom(c);
	cout << "Polinom p3: " << p3.ToString() << endl;
	cout << "Polinom p4: " << p4.ToString() << endl;
	p4 = p4 + p3;
	cout << "p4 = p4 + p3: " << p4.ToString();*/
	
	
	
	
	
	
	//Тест таблиц
	cout << "Линейная упорядоченная таблица на массиве.\n";
    LinArrTable<string, TPolinom> table;
    TPolinom a("1,0*x^1*y^1*z^1");
    TPolinom b("15,3*x^1*y^2*z^3-5,23*x^4*y^2*z^8");
    TPolinom c("2,2*x^2*y^3*z^2+3,5*x^6*y^6*z^6");

    /*TMonom a(3.22, 1, 2, 1);
    TMonom b(4.5, 3, 3, 2);*/


    table.Insert("pol1", a);
    table.Insert("pol2", b);
    table.Insert("pol3", c);

    cout << "После вставки: " << endl;
    cout << table;
    TPolinom* found = table.Find("pol1");
    if (found != nullptr) {
        cout << "Найден ключ 2 со значением: " << *found << endl;
    }

    table.Delete("pol1");
    cout << "После удаления: " << endl;
    cout << table << endl;

    //cout << "Хеш-таблица с открытым перемешиванием.\n";

    //HashTable1<int, string> hashTable;

    //// Добавление элементов в хеш-таблицу
    //hashTable.Insert(1, "One");
    //hashTable.Insert(2, "Two");
    //hashTable.Insert(3, "Three");
    //hashTable.Insert(4, "Four");

    //// Вывод хеш-таблицы до удаления элемента
    //cout << "Хэш-таблица до удаления элемента:" << endl;
    //cout << hashTable << endl;

    //// Поиск элемента
    //auto value = hashTable.Find(3);
    //if (value != nullptr) {
    //    cout << "Ключ: 3, найден, Значение: " << *value << endl;
    //}
    //else {
    //    cout << "Ключ 3 не найден." << endl;
    //}

    //// Удаление элемента
    //cout << "Удаление ключа 2." << endl;
    //hashTable.Delete(2);

    //// Вывод хеш-таблицы после удаления элемента
    //cout << "Хэш-таблица после удаления элемента:" << endl;
    //cout << hashTable << endl;

    //cout << "Хеш-таблица со списками.\n";
    //
    //ChainHashTable<int, string> hashTable2;

    //// Добавление элементов
    //hashTable2.Insert(1, "One");
    //hashTable2.Insert(2, "Two");
    //hashTable2.Insert(3, "Three");
    //hashTable2.Insert(4, "Four");
    //hashTable2.Insert(5, "Five");

    //cout << "Хэш-таблица до удаления элемента:" << endl;
    //cout << hashTable2 << endl;

    //// Поиск элемента
    //cout << "Поиск ключа 3 в таблице" << endl;
    //auto value1 = hashTable2.Find(3);
    //if (value1 != nullptr) {
    //    cout << "Ключ: 3, найден, Значение: " << *value1 << endl;
    //}
    //else {
    //    cout << "Ключ 3 не найден." << endl;
    //}

    //// Удаление элемента
    //cout << "Удаление ключа 2." << endl;
    //hashTable2.Delete(2);

    //cout << "Хэш-таблица после удаления элемента:" << endl;
    //cout << hashTable2;

}
