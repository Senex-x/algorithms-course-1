#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int index, vector<vector<int>>& matrix, vector<bool>& mark, int& counter, vector<pair<int, int>>& result) {
	mark[index] = true;
	for (int i = 0; i < matrix[index].size(); i++) {
		if (matrix[index][i] != 0 && !mark[i]) { // edge found
			dfs(i, matrix, mark, counter, result);
		}
	}
	result[index].second = counter++;
	result[index].first = index;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second > p2.second) return true;
	else return false;
}


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





