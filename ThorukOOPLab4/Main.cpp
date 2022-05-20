#include "Triangle.h"

void main() {
	Triangle t(Point(0, 0), Point(0, 5), Point(5, 0));
	Triangle copyT(t);
	cout << t.ab() << endl;
	cout << t.bc() << endl;
	cout << t.ca() << endl;
	t.a().x() = -5;
	cout << t.ab() << endl;
	cout << copyT.ab() << endl;
}