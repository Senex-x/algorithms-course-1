#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > v(n + 1, vector<int>(m + 1, 0));
	v[n][1] = 1;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= m; j++) {
			v[i][j] = v[i + 1][j] + v[i][j - 1];
		}
	}

	cout << v[0][m];
}



