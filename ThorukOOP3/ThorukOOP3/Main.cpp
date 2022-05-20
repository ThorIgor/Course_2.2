#include"Date.h"

void main() {
	Date d1(1, Date::jan, 2021);
	Date d2(31, 12, 2024);
	Date d3(d1);
	cout << d1 << endl << ++d2 << endl << d3-- << endl;
	cout << d3 << endl;
	Date::setDefault(1, Date::apr, 2021);
	Date::showDefault();
	try {
		Date d(45, 13, 2002);
	}
	catch (Date::BadDate bd) {
		cout << "Bad date: " << bd << endl;
	}
}