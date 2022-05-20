#include "Point.h"

int Point::_freeID = 0;

ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.x() << "; " << p.y() << ")";
	return os;
}

Point::Point(double x, double y) : _x(x), _y(y), _pointID(++_freeID)
{
	cout << _pointID << ": " << *this << " created" << endl;
}

Point::Point(const Point& p) : _x(p._x), _y(p._y), _pointID(++_freeID)
{
	cout << _pointID << ": " << *this << " copy" << endl;
}

Point::~Point()
{
	cout << _pointID << ": " << *this << " destructed" << endl;
}

Point& Point::operator=(const Point& p)
{
	_x = p._x; _y = p._y;
	return *this;
}

const double& Point::distance(const Point& p) const
{
	return sqrt(pow(p.x() - x(), 2) + pow(p.y() - y(), 2));
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& that, const Point& p)
{
	that.x() += p.x();
	that.y() += p.y();
	return that;
}

bool operator==(const Point& u, const Point& v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point& v)
{
	return u.x() != v.x() || u.y() != v.y();
}
