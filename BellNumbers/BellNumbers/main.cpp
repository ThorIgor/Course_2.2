#include<iostream>
#include<vector>

using namespace std;

vector<long long> BellNum;

long long factorial(const int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return factorial(n - 1) * n;
}

long long c(const int n, const int i) {
	return factorial(n) / (factorial(i) * factorial(n - i));
}

long long B(const int n) {
	if (BellNum.size()-1 >= n)
		return BellNum[n];
	long long b = 0;
	for (int i = 0; i <= n - 1; i++) {
		b += c(n-1, i) * B(n - 1);
	}
	BellNum.push_back(b);
	return b;
}

void main() {
	BellNum.push_back(1);
	cout << pow(2, 7) << endl;
	int n;
	cout << "n = ";
	cin >> n;
	cout << "B(" << n << ") = " << B(n) << endl;
	for (long long num : BellNum)
		cout << num << endl;
}