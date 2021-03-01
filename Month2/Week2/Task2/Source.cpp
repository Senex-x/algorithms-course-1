#include <iostream>

using namespace std;

int main() {
	int n, m, inp;
	cin >> n;
	int* np = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> inp;
		*(np + i) = inp;
	}
	cin >> m;
	int* mp = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> inp;
		*(mp + i) = inp;
	}

	int* res = new int[n + m];
	for (int i = 0; i < n; i++) {
		*(res + i) = *(np + i);
	}
	for (int i = 0; i < m; i++) {
		*(res + n + i) = *(mp + i);
	}

	for (int i = 0; i < n + m; i++) {
		cout << *(res + i) << " ";
	}
	return 0;
}