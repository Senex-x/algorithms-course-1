#include <iostream>
#include <vector>

using namespace std;

vector<int> list;

int binarySearch(int l, int r, int key) {
	int mid = (l + r + 1) / 2;

	if (list[mid] == key) {
		return mid;
	}
	else if (list[mid] > key) {			
		return binarySearch(l,  mid, key);
	}
	else {		
		return binarySearch(mid, r,  key);
	}
}

int getFirst(int ind) {
	int res = 0;
	int key = list[ind];
	if (ind == 0) {
		return 0;
	}
	for (int i = ind; i >= 0 && list[i] == key; i--) {
		res = i;
	}
	return res;
}

int main() {
	int data[] = { 0, 0, 1, 1, 1, 1, 2, 3, 3, 4 };
	for (int i = 0; i < 10; i++) {
		list.push_back(data[i]);
	}

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	int ind = binarySearch(0, list.size(), 4);
	cout << endl << getFirst(ind) << " " << ind;
}