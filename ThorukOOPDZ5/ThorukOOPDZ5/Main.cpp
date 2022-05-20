#include"AComplex.h"
#include"TComplex.h"

void main() {
	AComplex a(2, 3), b(5, 7);
	TComplex c(2, 2), d(7, 1);
	cout << a + c << endl;
	cout << c * a << endl;
	cout << a - b << endl;
	cout << c / d << endl;
	cout << d - b << endl;
	cout << d / b << endl;
}