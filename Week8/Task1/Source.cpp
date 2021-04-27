#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fact(int n) {
	if (n > 1) {
		return n * fact(n - 1);
	}
	else {
		return n;
	}
}

string rotate(string& origin, int start) {
	reverse(origin.begin() + start, origin.end());
	return origin;
}

string getPermutation(string current) {
	int ind = -1;
	for (int i = current.length() - 1; i > 0; i--) {
		if (current[i] > current[i - 1]) {
			ind = i - 1;
			break;
		}
	}
	if (ind == -1) return "";
	for (int i = current.length() - 1; i >= 0; i--) {
		if (current[i] > current[ind]) {
			swap(current[i], current[ind]);
			break;
		}
	}
	rotate(current, ind + 1);

	return current;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> permutationsOfFirst;

	permutationsOfFirst.push_back(stoi(a));
	for (int i = 0; i < fact(a.length()) - 1; i++) {
		a = getPermutation(a);
		if (a.empty()) break;
		permutationsOfFirst.push_back(stoi(a));
	}

	for (int i = 0; i < fact(b.length()); i++) {
		for (int j = 0; j < permutationsOfFirst.size(); j++) {
			cout << stoi(b) << " + " << permutationsOfFirst[j] << " = " << stoi(b) + permutationsOfFirst[j] << " ?= " << stoi(c) << endl;
			if (stoi(b) + permutationsOfFirst[j] == stoi(c)) {
				cout << endl << "Yes: " << b << " + " << permutationsOfFirst[j] << " = " << c << endl;
				return 0;
			}
		}
		b = getPermutation(b);
		if (b.empty()) break;
	}

	cout << endl << "No" << endl;
}



