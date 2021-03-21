#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MaxHeap {
	SortedTree* tree = new SortedTree();
	void insert(int val) {

	}

	int getMax() {

	}

	int extractMax() {

	}
};
 
struct SortedTree {
	vector<int> tree;

	int getSize() {
		return tree.size();
	}

	void add(int val) {
		tree.push_back(val);
		raiser(tree.size() - 1);
	}

	int extractMax() {
		int res = tree[0];
		tree[0] = tree[getSize() - 1];
		descender(0);
		return res;
	}

	void raiser(int i) {
		while (i > 0 && tree[i] > tree[getParentIndOf(i)]) {
			swap(tree[i], tree[getParentIndOf(i)]);
			i = getParentIndOf(i);
		}
	}

	void swapNodes(int first, int second) {
		return swap(tree[first], tree[second]);
	}

	// WTF
	void descender(int i) {
		if (getLeftChildIndOf(i) < getSize() && getRightChildIndOf(i) < getSize()) {
			int leftInd = getLeftChildIndOf(i);
			int rightInd = getRightChildIndOf(i);
			int minimum = min(tree[leftInd], tree[rightInd]);

			if (tree[i] < tree[leftInd] && tree[i] < tree[rightInd]) {
				if (tree[leftInd] < tree[rightInd]) {
					
				}
				else {

				}
			}
			else if (tree[i] < tree[leftInd])
			{
			
			}
			else if (tree[i] < tree[rightInd]) {

			}
		}
		int maxI, left;
		if (tree[left] > tree[i]) {
			maxI = left;
		}
		if (maxI != i) {
			swap(tree[maxI], tree[i]);
			descender(maxI);
		}
	}

	int getMax() {
		return tree[0];
	}

	int getParentIndOf(int i) {
		return (i-1)/2;
	}

	int getLeftChildIndOf(int i) {
		return 2* i + 1;
	}

	int getRightChildIndOf(int i) {
		return 2 * i + 2;
	}
};


int main() {
	

	return 0;
}