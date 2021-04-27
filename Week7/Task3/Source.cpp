#include <iostream>
#include <vector>

using namespace std;

int getNearest(int l, int r, int key) {
	int mid = (l + r) / 2;

	if (key <= mid) {
		return l;
	}
	else {
		return r;
	}
}

int approxSqrt(int l, int r, int key) {
	int mid = (l + r + 1) / 2;
	int res = mid * mid;

	if (res == key) {
		return mid;
	}
	else if (l > r) {
		return getNearest(r * r, l * l, key);
	}
	else if (res > key) {
		return approxSqrt(l, mid - 1, key);
	}
	else {
		return approxSqrt(mid + 1, r, key);
	}
}

int main() {
	int key;
	cin >> key;
	int res = approxSqrt(0, key / 2, key);
	cout << res;
}