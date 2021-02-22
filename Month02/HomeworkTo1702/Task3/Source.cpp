#include <iostream>

using namespace std;

int main() {
	int x, i = 0;
	cin >> x;
	if (x < 3) {
		cout << 0;
		return 0;
	}
	for (int p = 1; p < x; p *= 2, i++);
	cout << i - 1;
	return 0;
}