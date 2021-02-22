#include <iostream>

using namespace std;

int power(int x, unsigned int p);

int main() {
	int x, p;
	cin >> x >> p;
	cout << power(x, p);
	return 0;
}

int power(int x, unsigned int p) {
	return (int)pow(x, p);
}