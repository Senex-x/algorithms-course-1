#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
	Task(int num, int val, int time) {
		this->num = num;
		this->val = val;
		this->time = time;
	}

	int num;
	int val;
	int time;
};

struct comp {
	bool operator() (const Task* t1, const Task* t2) {
		return t1->val > t2->val;
	}
};

/*
3
1 3 5
2 8 3
3 5 2
*/

int main() {
	vector<Task*> tasks;
	int n, a, b, c, last = 0, p = 1, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		last = max(last, c);
		tasks.push_back(new Task(a, b, c));
	}

	sort(tasks.begin(), tasks.end(), comp());

	vector<int> sch(last + 1, -1);

	while (!tasks.empty()) {
		Task* t = tasks.front();
		tasks.erase(tasks.begin());
		if (p <= t->time) {
			sch[p++] = t->num;
		}
	}

	cout << endl;
	for (int i = 1; i < p; i++) {
		cout << sch[i] << " ";
	}
	cout << endl;
}