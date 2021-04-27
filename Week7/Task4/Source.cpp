#include <iostream>
#include <vector>

using namespace std;

int n, m, matrixMin, matrixMax, keyCount = 0;
vector< vector<int> > matrix;

int binarySearch(int ind, int l, int r, int key) {
	int mid = (l + r) / 2;

	if (matrix[ind][mid] == key) {
		return mid;
	}
	else if (l > r) {
		keyCount--;
		return l;
	}
	else if (matrix[ind][mid] > key) {
		return binarySearch(ind, l, mid - 1, key);
	}
	else {
		return binarySearch(ind, mid + 1, r, key);
	}
}

int getMin() {
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		res = min(res, matrix[i][0]);
	}
	return res;
}

int getMax() {
	int res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, matrix[i][m - 1]);
	}
	return res;
}

int getLessCount(int key) {
	keyCount = n;
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int res = binarySearch(i, 0, m - 1, key);
		counter += res;
	}
	return counter;
}

int getLargerCount(int lessCount) {
	return n * m - lessCount - keyCount;
}

int getDelta(int key) {
	int count = getLessCount(key);
	return abs(count - getLargerCount(count));
}

int minDelta = INT_MAX;
int median = -1;

void search(int l, int r) {
	int mid = (l + r) / 2;

	int delta = getDelta(mid);
	if (delta < minDelta) {
		minDelta = delta;
		median = mid;
	}

	if (delta == 0 || l > r) {
		return;
	}
	else if (getLessCount(mid) > getLargerCount(mid)) {
		return search(l, mid - 1);
	}
	else {
		return search(mid + 1, r);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		matrix.push_back(vector<int>());
		for (int j = 0; j < m; j++) {
			matrix[i].push_back(0);
			cin >> matrix[i][j];
		}
	}
	cout << endl;

	matrixMin = getMin();
	matrixMax = getMax();

	search(matrixMin, matrixMax);
	cout << "Median value: " << median << endl << endl;

	for (int i = matrixMin; i <= matrixMax; i++) {
		cout << "Delta of element " << i << ": " << getDelta(i) << endl;
	}
}

/*
4 4
3 5 7 9
2 3 5 9
1 2 3 5
2 5 7 10
*/