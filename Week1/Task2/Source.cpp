#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d = b * b - 4 * a * c;
	if (d < 0) {
		cout << "No roots";
	}
	else
		if (d == 0) {
			cout << "Root: " << -(float)b / (2 * a);
		}
		else {
			cout << "First root: " << (-(float)b + sqrt(d)) / 2 * a << "\nSecond root: " << (-(float)b - sqrt(d)) / 2 * a;
		}

	return 0;
}