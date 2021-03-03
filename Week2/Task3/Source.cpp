#include <iostream>

using namespace std;

void sort(int* a, int l, int r) {
	int i = l;
	int j = r;
	int key = a[(i + j) / 2];
	int temp;

	while (i <= j) {
		while (a[i] < key) i++;
		while (a[j] > key) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (j > l) sort(a, l, j);
	if (i < r) sort(a, i, r);
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	sort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";
	}
	return 0;
}