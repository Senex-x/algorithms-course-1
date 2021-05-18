#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, counter = 0;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	vector<bool> mark(n, false);
	vector<pair<int, int>> result(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < mark.size(); i++) {
		if (!mark[i]) { // not marked yet
			dfs(i, matrix, mark, counter, result);
		}
	}

	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << " ";
	}
	cout << endl;
}

/*
5
0 0 1 1 0
1 0 1 0 1
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
*/





