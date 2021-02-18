#include <iostream>

using namespace std;

int main() {
	int n, sum = 0, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		sum += c;
	}
	cout << sum;
	return 0;
}