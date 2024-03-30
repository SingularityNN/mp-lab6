#pragma once
struct TMonom
{
	double coef; // коэффициент монома
	int index; // индекс (свертка степеней)

	TMonom() { 
		this->coef = 1.0;
		this->index = 0;
	}

	TMonom(double _coef, int degX, int degY, int degZ) {
		if (degX > 9 || degY > 9 || degZ > 9)
			throw exception("deg > 9");
		SetCoef(_coef);
		index = (degX * 10 + degY) * 10 + degZ;
	}

	void SetCoef(double cval) { coef = cval; }
	double GetCoef(void) { return coef; }

	void SetIndex(int ival) { index = ival; }
	int GetIndex(void) { return index; }

	bool operator==(const TMonom& other) { return (coef == other.coef) && (index == other.index); }
	
	bool operator>(const TMonom& other) { 
		int degX, degY, degZ, o_degX, o_degY, o_degZ;
		degX = this->index / 100;
		degY = (this->index / 10) % 10;
		degZ = this->index % 10;

		o_degX = other.index / 100;
		o_degY = (other.index / 10) % 10;
		o_degZ = other.index % 10;

		if (degX == o_degX) {
			if (degY == o_degY) {
				if (degZ == o_degZ) return false;
				else return degZ > o_degZ;
			}
			else return degY > o_degY;
		}
		else return degX > o_degX;
	}

	bool operator<(const TMonom& other) { return !(this->operator>(other) && (this->operator==(other))); }

	double Calculate_monom(double* _point) {
		if (index == 0) return 1.0;

		double res = 1.0;
		int degX = this->index / 100;
		int degY = (this->index / 10) % 10;
		int degZ = this->index % 10;
		
		res *= pow(_point[0], degX);
		res *= pow(_point[1], degY);
		res *= pow(_point[2], degZ);
		res *= coef;

		return res;

	}

	friend ostream& operator<<(ostream& os, TMonom& mon) {
		os << mon.GetCoef() << "*x^" << mon.GetIndex() / 100 << "y^" << (mon.GetIndex() / 10) % 10 << "z^" << mon.GetIndex() % 10;
		return os;
	}
};