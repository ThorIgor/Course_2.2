#include <iostream>

using namespace std;

class Point {
	double _x, _y;
public:
	Point(const double& x, const double& y);
	Point(const Point&);

	~Point();

	Point& operator=(const Point&);

	double& x() { return _x; }
	double& y() { return _y; }

	const double& x()const { return _x; }
	const double& y()const { return _y; }

};

ostream& operator<<(ostream&, const Point&);
