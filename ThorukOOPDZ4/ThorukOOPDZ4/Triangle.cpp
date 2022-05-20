#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c),
	_ab(nullptr), _bc(nullptr), _ca(nullptr)
{
}

Triangle::Triangle(const Triangle& t) : _a(t._a), _b(t._b), _c(t._c),
_ab(nullptr), _bc(nullptr), _ca(nullptr)
{
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
}

Triangle& Triangle::operator=(const Triangle& t)
{
	_a = t._a; _b = t._b; _c = t._c;
	return *this;
}

Segment& Triangle::ab()
{
	if (_ab == nullptr)
		_ab = new Segment(_a, _b);
	return *_ab;
}

Segment& Triangle::bc()
{
	if (_bc == nullptr)
		_bc = new Segment(_b, _c);
	return *_bc;
}

Segment& Triangle::ca()
{
	if (_ca == nullptr)
		_ca = new Segment(_c, _a);
	return *_ca;
}

const Segment& Triangle::am()
{
	Point dop((_b.x() + _c.x()) / 2, (_b.y() + _c.y()) / 2);
	return Segment(_a, dop);
}

const Segment& Triangle::bm()
{
	Point dop((_a.x() + _c.x()) / 2, (_a.y() + _c.y()) / 2);
	return Segment(_b, dop);
}

const Segment& Triangle::cm()
{
	Point dop((_b.x() + _a.x()) / 2, (_b.y() + _a.y()) / 2);
	return Segment(_c, dop);
}


