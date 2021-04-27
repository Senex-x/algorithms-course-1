#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int n, k, sum;
	cin >> n >> k;

	vector<int> step(k - 1, 0);
	step.push_back(1);
	sum = 1;

	for (int i = 1; i < n - 1; i++) {
		step.push_back(sum);
		sum = sum - step[0] + step[step.size() - 1];
		step.erase(step.begin());
	}

	cout << sum;
}



