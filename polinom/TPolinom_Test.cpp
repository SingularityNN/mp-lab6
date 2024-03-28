#include <iostream>
#include "TList.h"
#include "TPolinom.h"
#include "TArithmeticExpression.h"
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
	TPolinom p1;
	TMonom a(3.22, 1, 2, 1);
	TMonom b(4.5, 3, 3, 2);
	TMonom c(2.0, 1, 1, 1);


	p1.AddMonom(a);
	cout << "Полином p1 с одним мономом a(3.22, 1, 2, 1): " << p1.ToString() << endl;
	cout << "_________________________________________________" << endl;


	p1.AddMonom(b);
	cout << "К p1 добавили моном b(4.5, 3, 3, 2):" << p1.ToString() << endl;
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


	/*p1.AddPolinom(p2);
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

}
