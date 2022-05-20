#include "Segment.h"


Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _a(x1, y1), _b(x2, y2)
{
#ifdef DEBUG 
	cout << ": constract segement" << endl;
#endif
}

Segment::Segment(const Point& start, const Point& end) : _a(start), _b(end)
{
#ifdef DEBUG 
	cout << ": constract segement" << endl;
#endif
}

Segment::Segment(const Segment& s) : _a(s.start()), _b(s.end())
{
#ifdef DEBUG 
	cout << ": copy segement" << endl;
#endif
}

Segment::~Segment()
{
#ifdef DEBUG 
	cout << ": delete segement" << endl;
#endif
}

Segment& Segment::operator=(const Segment& s)
{
	_a = s._a; _b = s._b;
	return *this;
}

double Segment::length() const
{
	return sqrt(pow(_a.x()-_b.x(), 2) + pow(_a.y()-_b.y(), 2));
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
	os << "Segment: " << s.start() << " " << s.end();
	return os;
}
