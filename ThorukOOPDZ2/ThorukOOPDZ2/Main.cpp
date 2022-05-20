#include"Segment.h"

void main() {
	Point p1(4, 0);
	Point p2(-3, -1);
	Segment s1(0, 0, 7, 0);
	Segment s2(p1, p2);
	Segment s3(s1);
	cout << s1 << " l: " << s1.length() << endl;
	cout << "d: " << s1.distance(*new Point(4, 5)) << endl;
}