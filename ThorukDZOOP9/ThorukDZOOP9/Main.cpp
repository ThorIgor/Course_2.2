#include "Array.h"

void main() {
	try {
		Array<5, double> arr1;
		for (int i = 0; i < arr1.size(); i++)
			arr1[i] = i;
		cout << arr1 << endl;
		arr1[5]; // error 
	}
	catch (BadIndex er) {
		cout << er << endl;
	}
	
}