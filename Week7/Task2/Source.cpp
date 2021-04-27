#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > matrix;

int binarySearch(int ind, int l, int r, int key) {
	int mid = (l + r) / 2;

	if (matrix[ind][mid] == key) {
		return mid;
	}
	else if (l > r) {
		return -1;
	}
	else if (matrix[ind][mid] > key) {
		return binarySearch(ind, l, mid - 1, key);
	}
	else {
		return binarySearch(ind, mid + 1, r, key);
	}
}

int main() {
	int key, n, m;
	cin >> key >> n >> m;

	for (int i = 0; i < n; i++) {
		matrix.push_back(vector<int>());
		for (int j = 0; j < m; j++) {
			matrix[i].push_back(0);
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (matrix[i][matrix[i].size() - 1] >= key) {
			int res = binarySearch(i, 0, matrix[i].size(), key);
			if (res == -1) {
				cout << "Key not present";
			}
			else {
				cout << "key: " << key
					<< " i: " << i
					<< " j: " << res
					<< endl;
			}
			break;
		}
	}
}


/*
98 2 5
1 3 4 6 9
10 23 26 27 29
55 67 78 98 100
*/