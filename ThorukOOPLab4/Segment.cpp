#include "Segment.h"

Segment::Segment(Point& a, Point& b) : _a(a), _b(b)
{
#ifdef DEBUG
	cout << "Construct segment" << *this << endl;
#endif
}

Segment::Segment(const Segment& s) : _a(s._a), _b(s._b)
{
#ifdef DEBUG
	cout << "Copy segment" << *this << endl;
#endif
}

Segment::~Segment()
{
#ifdef DEBUG
	cout << "Deconstruct segment" << *this << endl;
#endif
}

Segment& Segment::operator=(const Segment& s)
{
	_a = s.start();
	_b = s.end();
	return *this;
}

double Segment::length() const
{
	return sqrt(pow(_a.x() - _b.x(), 2) + pow(_a.y() - _b.y(), 2));
}

double Segment::distance(const Point& p) const {
	double L = (_a.x() - _b.x()) * (_a.x() - _b.x()) + (_a.y() - _b.y()) * (_a.y() - _b.y());
	double PR = (p.x() - _a.x()) * (_b.x() - _a.x()) + (p.y() - _a.y()) * (_b.y() - _a.y());
	bool res = true;
	double cf = PR / L;

	if (cf < 0)
		cf = 0; res = false;
	if (cf > 1)
		cf = 1; res = false;

	double xres = _a.x() + cf * (_b.x() - _a.x());
	double yres = _a.y() + cf * (_b.y() - _a.y());
	return sqrt((p.x() - xres) * (p.x() - xres) + (p.y() - yres) * (p.y() - yres));
}

ostream& operator<<(ostream& os, const Segment& s)
{
	os << "(" <<  s.start() << " " << s.end() << ")";
	return os;
}
