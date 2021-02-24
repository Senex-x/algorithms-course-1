#include <iostream>
#include <vector>

using namespace std;


int main() {
	int a, b;
	cin >> a;
	vector<int> v1(a);

	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		v1[i] = c;;
	}

	cin >> b;
	vector<int> v2(b);


	for (int i = 0; i < b; i++) {
		int c;
		cin >> c;
		v2[i] = c;;
	}

	vector<int> res(a + b);

	for (int i = 0; i < a; i++) {
		res[i] = v1[i];
	}
	for (int i = 0; i < b; i++) {
		res[a + i] = v2[i];
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}