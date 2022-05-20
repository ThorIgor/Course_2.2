#include"String.h"

void main() {
	try {
		String str1, str2('H'), str3(str2);
		cout << str1 << str2 << str3 << endl;
		str1 = str2 + str3;
		if (str1 != str2)
			cout << str1 << " not equal " << str2 << endl;
	}
	catch (const char* er) {
		cout << er << endl;
	}
}