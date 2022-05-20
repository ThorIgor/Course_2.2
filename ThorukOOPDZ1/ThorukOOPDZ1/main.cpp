#include "Point.h"

int main() {
	Point one(2, 5);
	Point two(-7, 0);
	Point three(one);
	cout << "one + two = " << one + two << endl;
	if (one == two)
		cout << one << "==" << two << endl;
	else
		cout << one << "!=" << two << endl;
	if(one != three) 
		cout << one << "!=" << three << endl;
	else
		cout << one << "==" << three << endl;
	one += two;
	cout << "one += two =" << one << endl;

	return 0;
}