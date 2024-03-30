#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>
#include <vector>

const int nonDisplayedZeros = 4; // Количество неотображаемых нулей при выводе коэффициента полинома
								 // Кол-во символов после запятой = 6 - nonDisplayedZeros


class TPolinom : public THeadList<TMonom>
{
public:
	double* Point;
	double Calculation_res;
	THeadList<TMonom> monoms;
	void Parse(string str);
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(TPolinom& other); // присваивание
	TPolinom& operator+(TPolinom& q); // сложение полиномов
	TPolinom& operator-(TPolinom& q); // вычитание полиномов

	// дополнительно можно реализовать:
	void AddMonom(TMonom newMonom); // добавление монома
	TPolinom MultMonom(TMonom monom); // умножение мономов
	TPolinom AddPolinom(TPolinom& other); // добавление полинома
	TPolinom operator*(double coef); // умножение полинома на константу
	TPolinom operator* (TPolinom& other); // умножение полиномов
	bool operator==(TPolinom& other); // сравнение полиномов на равенство
	string ToString(); // перевод в строку
	bool IsEmpty();

	void Set_point();
	void Calculate_polinom();
	string Get_Calculation_res();

	friend ostream& operator<<(ostream& os, TPolinom& pol) {
		string str = pol.ToString();
		os << str;
		return os;
	};
};

bool TPolinom::IsEmpty() {
	return this->monoms.GetLength() == 0;
}

void TPolinom::Parse(string str) {
	string s_coef = "";
	double d_coef = 0;
	int degX = 0, degY = 0, degZ = 0;
	int ch = 0;
	while (ch < str.size() - 1)
	{
		while (str[ch] != '*') {
			s_coef += str[ch];
			ch++;
		}
		d_coef = std::stod(s_coef);
		ch += 3;

		degX = str[ch] - '0';
		ch += 4;

		degY = str[ch] - '0';
		ch += 4;

		degZ = str[ch] - '0';
	}
	TMonom m(d_coef, degX, degY, degZ);
	monoms.InsertLast(m);
}

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{

}

TPolinom::TPolinom(TPolinom& other)
{
	Calculation_res = NULL;
	Point = new double[3];
	monoms = other.monoms;
	Point = other.Point;
	Calculation_res = other.Calculation_res;
}

TPolinom::TPolinom(string str)
{	
	Calculation_res = NULL;
	Point = new double[3]; Point[0] = NULL; Point[1] = NULL; Point[2] = NULL;
	vector<string> monoms_to_parse;
	int i = 0;
	string monom;
	while (i < str.size())
	{
		monom = "";
		while ((str[i] != '+') && (i < str.size()))
		{
			monom.push_back(str[i]);
			i++;
		}
		monoms_to_parse.push_back(monom);
		i++;
	}
	for (int j = 0; j < monoms_to_parse.size(); j++) {
		Parse(monoms_to_parse[j]);
	}
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	this->monoms = other.monoms;
	return *this;
}

void TPolinom::AddMonom(TMonom m)
{
	bool flag = true;
	monoms.Reset();
	for (int i = 0; i < monoms.GetLength(); i++) {
		if (m.GetIndex() == monoms.GetCurrentItem().GetIndex()) {
			double coef = (this->monoms.GetCurrentItem().coef) + m.coef;
			int degX = (this->monoms.GetCurrentItem().GetIndex() / 100);
			int degY = ((this->monoms.GetCurrentItem().GetIndex() / 10) % 10);
			int degZ = (this->monoms.GetCurrentItem().GetIndex() % 10);
			TMonom tmp(coef, degX, degY, degZ);

			
			monoms.DeleteCurrent();
			if (i == monoms.GetLength() && monoms.GetLength() != 0) monoms.InsertLast(tmp);
			else {
				if (monoms.GetLength() == 0) monoms.InsertFirst(tmp);
				else monoms.InsertCurrent(tmp);
			}
			
			flag = false;
			break;
		}
		monoms.GoNext();
	}
	if(flag) monoms.InsertLast(m);
}

TPolinom TPolinom::MultMonom(TMonom monom)
{
	THeadList<TMonom> tmp;
	monoms.Reset();
	double coef;
	int degX, degY, degZ;

	int mdegX = monom.GetIndex() / 100;
	int mdegY = (monom.GetIndex() / 10) % 10;
	int mdegZ = monom.GetIndex() % 10;

	for (int i = 0; i < monoms.GetLength(); i++) {

		coef = (this->monoms.GetCurrentItem().coef) * monom.coef;
		degX = (this->monoms.GetCurrentItem().GetIndex() / 100) + mdegX;
		degY = ((this->monoms.GetCurrentItem().GetIndex() / 10) % 10) + mdegY;
		degZ = (this->monoms.GetCurrentItem().GetIndex() % 10) + mdegZ;
		if (degX > 9 || degY > 9 || degZ > 9) throw - 1;
		TMonom m(coef, degX, degY, degZ);
		tmp.InsertLast(m);

		this->monoms.GoNext();
	}
	this->monoms = tmp;
	return *this;
}

TPolinom& TPolinom::operator+(TPolinom& other)
{
	other.monoms.Reset();
	for (int i = 0; i < other.monoms.GetLength(); i++) {
		AddMonom(other.monoms.GetCurrentItem());
		other.monoms.GoNext();
	}
	return *this;
}

TPolinom& TPolinom::operator-(TPolinom& other)
{
	other.monoms.Reset();
	for (int i = 0; i < other.monoms.GetLength(); i++) {
		TMonom tmp = other.monoms.GetCurrentItem();
		double coef = tmp.GetCoef();
		tmp.SetCoef(-coef);
		AddMonom(tmp);
		other.monoms.GoNext();
	}
	return *this;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)
{
	other.monoms.Reset();
	for (int i = 0; i < other.monoms.GetLength(); i++) {
		AddMonom(other.monoms.GetCurrentItem());
		other.monoms.GoNext();
	}
	return *this;
}

TPolinom TPolinom::operator*(double _coef)
{
	THeadList<TMonom> tmp;
	monoms.Reset();
	double coef;
	int degX, degY, degZ;

	for (int i = 0; i < monoms.GetLength(); i++) {

		coef = (this->monoms.GetCurrentItem().coef) * _coef;
		degX = (this->monoms.GetCurrentItem().GetIndex() / 100);
		degY = ((this->monoms.GetCurrentItem().GetIndex() / 10) % 10);
		degZ = (this->monoms.GetCurrentItem().GetIndex() % 10);
		if (degX > 9 || degY > 9 || degZ > 9) throw - 1;
		TMonom m(coef, degX, degY, degZ);
		tmp.InsertLast(m);

		this->monoms.GoNext();
	}
	this->monoms = tmp;
	return *this;
}

TPolinom TPolinom::operator*(TPolinom& other)
{
	other.monoms.Reset();
	for (int j = 0; j < other.monoms.GetLength(); j++) {
		TMonom cur = other.monoms.GetCurrentItem();

		this->MultMonom(cur);

		other.monoms.GoNext();
	}
	
	return *this;
}

bool TPolinom::operator==(TPolinom& other)
{
	if(this->monoms.GetLength() != other.monoms.GetLength()) return false;
	else {
		monoms.Reset();
		for (int i = 0; i < monoms.GetLength(); i++) {
			if (!(this->monoms.GetCurrentItem() == other.monoms.GetCurrentItem()))
				return false;

			other.monoms.GoNext();
			monoms.GoNext();
		}
	}
	return true;
}

string TPolinom::ToString()
{
	string result = "";
	string tmp;
	string coef;
	int degX, degY, degZ, ind;
	monoms.Reset();
	for (int i = 0; i < monoms.GetLength(); i++) {
		ind = monoms.GetCurrentItem().GetIndex();
		
		degX = ind / 100;
		degY = (ind / 10) % 10;
		degZ = ind % 10;

		coef = std::to_string(monoms.GetCurrentItem().GetCoef());
		for (int j = 0; j < nonDisplayedZeros; j++) coef.pop_back();

		if(monoms.GetCurrentItem().GetCoef() < 0)
			tmp = "(" + coef + ")" + " * x^" + std::to_string(degX) + " y^" + std::to_string(degY) + " z^" + std::to_string(degZ);
		else
			tmp = coef + " * x^" + std::to_string(degX) + " y^" + std::to_string(degY) + " z^" + std::to_string(degZ);
		result += tmp;

		if(monoms.GetLength() - i > 1) result += " + ";
		monoms.GoNext();
	}

	return result;
}

void TPolinom::Set_point() {
	cout << "X = ";
	cin >> Point[0];
	cout << endl << "Y = ";
	cin >> Point[1];
	cout << endl << "Z = ";
	cin >> Point[2];
	cout << endl;
}

void TPolinom::Calculate_polinom() {
	if(Point[0] == NULL || Point[1] == NULL || Point[2] == NULL)
		throw exception("Point isn't set");

	Calculation_res = 0;
	monoms.Reset();
	int size = monoms.GetLength();

	for (int i = 0; i < size; i++) {
		TMonom tmp_monom = monoms.GetCurrentItem();
		Calculation_res += tmp_monom.Calculate_monom(this->Point);
		monoms.GoNext();
	}
	
}

string TPolinom::Get_Calculation_res() {
	return to_string(Calculation_res);
}