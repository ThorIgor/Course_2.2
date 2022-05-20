#include "Point.h"

//#define DEBUG

Point::Point(const double& x, const double& y) : _x(x), _y(y)
{
#ifdef DEBUG
	cout << "Construct point" << *this << endl;
#endif
}

Point::Point(const Point& p) : _x(p._x), _y(p._y)
{
#ifdef DEBUG
	cout << "Copy point" << *this << endl;
#endif
}

Point::~Point()
{
#ifdef DEBUG
	cout << "Deconstruct point" << *this << endl;
#endif
}

Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	return *this;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.x() << ";" << p.y() << ")";
	return os;
}
