#include <iostream>
#include <ctime>
#include "Point.h"
#include "Segment.h"

using namespace std;

class HTetragon abstract {
protected:
	Point _point;
public:
	HTetragon(const Point& p) : _point(p) {}
	~HTetragon() {}

	virtual HTetragon* clone() const = 0;

	virtual Point apexA() const = 0;
	virtual Point apexB() const = 0;
	virtual Point apexC() const = 0;
	virtual Point apexD() const = 0;

	virtual void setA(const Point& a) = 0;
	virtual void setB(const Point& b) = 0;
	virtual void setC(const Point& c) = 0;
	virtual void setD(const Point& d) = 0;

	Segment side_a() const { return Segment(_point, apexB()); }
	Segment side_b() const { return Segment(apexB(), apexC()); }
	Segment side_c() const { return Segment(apexD(), apexC()); }
	Segment side_d() const { return Segment(apexD(), _point); }

	virtual double area() const = 0;

	bool operator<(const HTetragon& that) {
		return area() < that.area();
	}
};

ostream& operator<<(ostream& os, const HTetragon& tetr) {
	os << typeid(tetr).name() << " with points: (" << 
		tetr.apexA() << ", " << tetr.apexB() << ", " << 
		tetr.apexC() << ", " << tetr.apexD() << ")";
	return os;
}
