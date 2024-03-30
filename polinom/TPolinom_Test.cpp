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

	//���� ���������� �������� � �����
	/*double* point = new double[3]; point[0] = 2; point[1] = 3; point[2] = 4;
	TMonom a(3.22, 1, 2, 1);
	TMonom b(4.5, 3, 3, 2);
	TPolinom ab("3,22*x^1*y^2*z^1+4,5*x^3*y^3*z^2");

	ab.Set_point();

	cout << "a = " << a.Calculate_monom(point) << endl;
	cout << "b = " << b.Calculate_monom(point) << endl;
	
	ab.Calculate_polinom();
	cout << "ab = " << ab.Get_Calculation_res();*/


	//���� ������������ �������� (��������, ��������� �� ���������, ���������� ������ � ��������, �������� � ��������� ���������
    /*TPolinom p1;
	TMonom a(3.22, 1, 2, 1);
	TMonom b(4.5, 3, 3, 2);
	TMonom c(2.0, 1, 1, 1);


    p1.AddMonom(a);
	cout << "������� p1 � ����� ������� a(3.22, 1, 2, 1): " << p1 << endl;
	cout << "_________________________________________________" << endl;


    p1.AddMonom(b);
	cout << "� p1 �������� ����� b(4.5, 3, 3, 2):" << p1 << endl;
	cout << "_________________________________________________" << endl;


	p1.MultMonom(c);
	cout << "�������� p1 �� ����� c(2.0, 1, 1, 1): " << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;


	string str;
	cout << "������� ������� p2: ";
	cin >> str; 
	TPolinom p2(str);


	cout << "������� p2 ��������� � ����������: " << p2.ToString() << endl;
	cout << "_________________________________________________" << endl;


	p1 = p1 - p2;
	cout << "�������� p2 �� p1: " << p1.ToString() << endl;
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
	
	
	
	
	
	
	//���� ������
	cout << "�������� ������������� ������� �� �������.\n";
    LinArrTable<string, TPolinom> table;
    TPolinom a("1,0*x^1*y^1*z^1");
    TPolinom b("15,3*x^1*y^2*z^3-5,23*x^4*y^2*z^8");
    TPolinom c("2,2*x^2*y^3*z^2+3,5*x^6*y^6*z^6");

    /*TMonom a(3.22, 1, 2, 1);
    TMonom b(4.5, 3, 3, 2);*/


    table.Insert("pol1", a);
    table.Insert("pol2", b);
    table.Insert("pol3", c);

    cout << "����� �������: " << endl;
    cout << table;
    TPolinom* found = table.Find("pol1");
    if (found != nullptr) {
        cout << "������ ���� 2 �� ���������: " << *found << endl;
    }

    table.Delete("pol1");
    cout << "����� ��������: " << endl;
    cout << table << endl;

    //cout << "���-������� � �������� ��������������.\n";

    //HashTable1<int, string> hashTable;

    //// ���������� ��������� � ���-�������
    //hashTable.Insert(1, "One");
    //hashTable.Insert(2, "Two");
    //hashTable.Insert(3, "Three");
    //hashTable.Insert(4, "Four");

    //// ����� ���-������� �� �������� ��������
    //cout << "���-������� �� �������� ��������:" << endl;
    //cout << hashTable << endl;

    //// ����� ��������
    //auto value = hashTable.Find(3);
    //if (value != nullptr) {
    //    cout << "����: 3, ������, ��������: " << *value << endl;
    //}
    //else {
    //    cout << "���� 3 �� ������." << endl;
    //}

    //// �������� ��������
    //cout << "�������� ����� 2." << endl;
    //hashTable.Delete(2);

    //// ����� ���-������� ����� �������� ��������
    //cout << "���-������� ����� �������� ��������:" << endl;
    //cout << hashTable << endl;

    //cout << "���-������� �� ��������.\n";
    //
    //ChainHashTable<int, string> hashTable2;

    //// ���������� ���������
    //hashTable2.Insert(1, "One");
    //hashTable2.Insert(2, "Two");
    //hashTable2.Insert(3, "Three");
    //hashTable2.Insert(4, "Four");
    //hashTable2.Insert(5, "Five");

    //cout << "���-������� �� �������� ��������:" << endl;
    //cout << hashTable2 << endl;

    //// ����� ��������
    //cout << "����� ����� 3 � �������" << endl;
    //auto value1 = hashTable2.Find(3);
    //if (value1 != nullptr) {
    //    cout << "����: 3, ������, ��������: " << *value1 << endl;
    //}
    //else {
    //    cout << "���� 3 �� ������." << endl;
    //}

    //// �������� ��������
    //cout << "�������� ����� 2." << endl;
    //hashTable2.Delete(2);

    //cout << "���-������� ����� �������� ��������:" << endl;
    //cout << hashTable2;

}
