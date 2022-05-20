#include"Segment.h"

class Triangle {
	Point _a, _b, _c;
	Segment* _ab, *_bc, *_ca;

public:
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle&);

	~Triangle();

	Triangle& operator=(const Triangle&);

	const Point& a() const { return _a; }
	const Point& b() const { return _b; }
	const Point& c() const { return _c; }

	Point& a() { return _a; }
	Point& b() { return _b; }
	Point& c() { return _c; }

	Segment& ab();
	Segment& bc();
	Segment& ca();

	//medians
	const Segment& am();
	const Segment& bm();
	const Segment& cm();
};


