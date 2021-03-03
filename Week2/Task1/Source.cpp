#include <iostream>

using namespace std;

int summarize(int* a, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(a + i);
	}
	return sum;
}

int main() {
	int n, inp;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> inp;
		*(a + i) = inp;
	}

	cout << summarize(a, n);
	return 0;
}