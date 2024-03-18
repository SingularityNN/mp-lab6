//#include <iostream>
//#include "TList.h"
//#include "TPolinom.h"
//#include "TArithmeticExpression.h"
//using namespace std;
////1,0*x^1*y^1*z^1
////15,3*x^1*y^2*z^3
////5,23*x^4*y^2*z^8
//
////2,2*x^2*y^3*z^2+3,5*x^6*y^6*z^6
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Полином p1 с одним мономом a(3.22, 1, 2, 1):" << endl;
//	TPolinom p1;
//	TMonom a(3.22, 1, 2, 1);
//	TMonom b(4.5, 3, 3, 2);
//	TMonom c(2.0, 1, 1, 1);
//	p1.AddMonom(a);
//	cout << p1.ToString() << endl;
//	cout << "_________________________________________________" << endl;
//
//	p1.AddMonom(b);
//	cout << "p1.AddMonom(b(4.5, 3, 3, 2)):" << endl << p1.ToString() << endl;
//	cout << "_________________________________________________" << endl;
//
//
//	p1.MultMonom(c);
//	cout << "p1.MultMonom(c(2.0, 1, 1, 1)):" << endl << p1.ToString() << endl;
//	cout << "_________________________________________________" << endl;
//
//
//	string str;
//	cout << "Введите полином p2: ";
//	cin >> str; 
//	TPolinom p2(str);
//
//	cout << "TPolinom p2(str):" << endl << p2.ToString() << endl;
//	cout << "_________________________________________________" << endl;
//
//	p1.AddPolinom(p2);
//	cout << "p1.AddPolinom(p2):" << endl << p1.ToString() << endl; 
//	cout << "_________________________________________________" << endl;
//
//
//	p1 = p1 * 2.0;
//	cout << "p1 = p1 * 2.0:" << endl << p1.ToString() << endl;
//	cout << "_________________________________________________" << endl;
//
//	
//	TPolinom p3;
//	TPolinom p4;
//	p3.AddMonom(a);
//
//	p4.AddMonom(b);
//	p4.AddMonom(c);
//	cout << "Polinom p3: " << p3.ToString() << endl;
//	cout << "Polinom p4: " << p4.ToString() << endl;
//	p4 = p4 + p3;
//	cout << "p4 = p4 + p3: " << p4.ToString();
//
//}


#include "TArithmeticExpression.h"
int main() {
	string exprStr;
	cout << "Enter expression: ";
	cin >> exprStr;
	TArithmeticExpression expr(exprStr);
	cout << expr.GetInfix() << endl;
	cout << "Output: " << expr.GetPostfix() << endl;
	vector<char> operands = expr.GetOperands();

	map<char, double> values;
	double val;
	for (const auto& op : operands) {
		cout << "Enter value of " << op << ": ";
		cin >> val;
		values[op] = val;
	}

	cout << expr.Calculate(values) << endl;

}