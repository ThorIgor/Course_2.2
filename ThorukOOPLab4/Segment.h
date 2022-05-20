#include"Point.h"

class Segment {
	Point &_a, &_b;
public:
	Segment(Point& a, Point& b);
	Segment(const Segment&);

	~Segment();

	Segment& operator=(const Segment&);

	const Point& start() const { return _a; }
	const Point& end() const { return _b; }

	Point& start() { return _a; }
	Point& end() { return _b; }

	const double& startX() const { return _a.x(); }
	const double& startY() const { return _a.y(); }
	const double& endX() const { return _b.x(); }
	const double& endY() const { return _b.y(); }

	double& startX() { return _a.x(); }
	double& startY() { return _a.y(); }
	double& endX() { return _b.x(); }
	double& endY() { return _b.y(); }

	double length() const;

	double distance(const Point&) const;
};

ostream& operator<<(ostream&, const Segment&);
