#include<iostream>


using namespace std;

class AComplex;

class TComplex {
	double _r, _fi;
public:
	TComplex(const double& r, const double& fi);
	TComplex(const TComplex& that);

	~TComplex();

	operator AComplex() const;

	TComplex& operator=(const TComplex&);

	double& mod() { return _r; }
	double& arg() { return _fi; }

	const double& mod() const { return _r; }
	const double& arg() const { return _fi; }

	double re() const { return _r * cos(_fi); }
	double im() const { return _r * sin(_fi); }

	const TComplex operator+(const TComplex&) const;
	const TComplex operator-(const TComplex&) const;
	const TComplex operator*(const TComplex&) const;
	const TComplex operator/(const TComplex&) const;
	bool operator==(const TComplex&) const;
	bool operator!=(const TComplex&) const;
};

ostream& operator<<(ostream& os, const TComplex& c);