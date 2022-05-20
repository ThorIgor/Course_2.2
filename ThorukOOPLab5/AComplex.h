#include<iostream>


using namespace std;

class TComplex;

class AComplex {
	double _re, _im;
public:
	AComplex(const double& re = 0, const double& im = 0);
	AComplex(const AComplex& that);

	~AComplex();

	operator TComplex() const;

	AComplex& operator=(const AComplex&);


	const double& re() const { return _re; }
	const double& im() const { return _im; }

	double& re() { return _re; }
	double& im() { return _im; }

	double mod() const { return sqrt(_re * _re + _im * _im); }
	double arg() const { return atan2(_im, _re); }

	const AComplex operator+(const AComplex&) const;
	const AComplex operator-(const AComplex&) const;
	const AComplex operator*(const AComplex&) const;
	const AComplex operator/(const AComplex&) const;
	bool operator==(const AComplex&) const;
	bool operator!=(const AComplex&) const;

};

ostream& operator<<(ostream& os, const AComplex& c);