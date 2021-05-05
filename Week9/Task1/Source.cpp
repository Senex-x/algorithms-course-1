#include <iostream>

using namespace std;

int main() {
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	if (n > 9) {
		c = n / 10;
		n = n - c * 10;
	}
	while (n != 0) {
		if (n > 4) {
			n -= 5;
			b++;
		}
		else {
			n -= 1;
			a++;
		}
	}

	cout << "1: " << a << " 5: " << b << " 10: " << c << endl;
}