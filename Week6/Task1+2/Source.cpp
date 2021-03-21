#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
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
		tree.resize(tree.size() - 1);
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
	int descender(int i) {
		if (i == -1 || tree.size() == 0) {
			return (-1);
		}

		int leftChild;
		int rightChild;
		int parent = tree[i];
		int maxNodeInd = i, maxNode = parent;

		if (getLeftChildIndOf(i) >= getSize()) return -1;
		leftChild = tree[getLeftChildIndOf(i)];
		if (getRightChildIndOf(i) >= getSize())
			rightChild = INT_MIN;
		else
			rightChild = tree[getRightChildIndOf(i)];

		if (parent < leftChild) {
			maxNode = leftChild;
			maxNodeInd = getLeftChildIndOf(i);
		}
		if (maxNode < rightChild) {
			maxNode = rightChild;
			maxNodeInd = getRightChildIndOf(i);
		}

		if (parent == maxNode) return -1;

		swap(tree[i], tree[maxNodeInd]);

		descender(maxNodeInd);

		return -1;
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

	void display() {
		for (int i = 0; i < tree.size(); i++) {
			cout << tree[i] << " ";
		}
		cout << endl;
	}
};

struct MaxHeap {
	SortedTree* tree = new SortedTree();
	void insert(int val) {
		tree->add(val);
	}

	int getMax() {
		return tree->getMax();
	}

	int extractMax() {
		return tree->extractMax();
	}
};

int* heapSort(int * array, int size) {
	MaxHeap * heap = new MaxHeap();
	for (int i = 0; i < size; i++) {
		heap->insert(array[i]);
	}
	int* res = new int[size];
	for (int i = 0; i < size; i++) {
		res[i] = heap->extractMax();
	}
	return res;
}


int main() {
	SortedTree* tree = new SortedTree();
	int a[] = {7, 2, 5, 1, 8, 9, 4 };

	for (int i = 0; i < size(a); i++) {
		tree->add(a[i]);
	}
	tree->display();

	cout << tree->extractMax() << endl;
	tree->display();
	
	int* res = heapSort(a, size(a));
	for (int i = 0; i < size(a); i++) {
		cout << res[i] << " ";
	}

	return 0;
}