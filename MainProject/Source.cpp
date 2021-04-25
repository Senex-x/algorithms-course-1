#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

struct Node {
	Node* prev;
	Node* next;
	Node* child;
	Node* parent;
	int key;
	int degree;
	bool mark;
};

struct FibonacciHeap {
	int size = 0;
	Node* min = NULL;

	void insert(int key) {
		Node* n = new Node();
		n->key = key;
		n->prev = n->next = n;
		n->degree = 0;
		n->mark = false;
		n->child = NULL;
		n->parent = NULL;
		min = mergeTop(min, n);
		size++;
	}

	void merge(FibonacciHeap& second) {
		min = mergeTop(min, second.min);
		second.min = NULL;
	}

	int getMin() {
		return min->key;
	}

	int removeMin() {
		Node* old = min;
		int res = min->key;
		if (min->child != NULL) {
			Node* c = min->child;
			do {
				c->mark = false;
				c->parent = NULL;
				c = c->next;
			} while (c != min->child);
		}


		if (min->next == min) {
			min = min->child;
		}
		else {
			min->next->prev = min->prev;
			min->prev->next = min->next;
			min = mergeTop(min->next, min->child);
		}
		if (min == NULL) return res;
		Node* trees[64] = { NULL };

		while (true) {
			if (trees[min->degree] != NULL) {
				Node* t = trees[min->degree];
				if (t == min)break;
				trees[min->degree] = NULL;
				if (min->key < t->key) {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					addChild(min, t);
				}
				else {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					if (min->next == min) {
						t->next = t->prev = t;
						addChild(t, min);
						min = t;
					}
					else {
						min->prev->next = t;
						min->next->prev = t;
						t->next = min->next;
						t->prev = min->prev;
						addChild(t, min);
						min = t;
					}
				}
				continue;
			}
			else {
				trees[min->degree] = min;
			}
			min = min->next;
		}
		Node* start = min;
		do {
			if (min->key < min->key)min = min;
			min = min->next;
		} while (min != start);


		size--;
		return res;
	}

	void display(Node* min) {
		Node* ptr = min;
		if (ptr != NULL) {
			do {
				cout << ptr->key;
				ptr = ptr->next;
				if (ptr != min) {
					cout << " ";
				}
			} while (ptr != min && ptr->prev != NULL);
			cout << endl << size << endl;
		}
	}

	Node* mergeTop(Node* a, Node* b) {
		if (a == NULL)return b;
		if (b == NULL)return a;
		if (a->key > b->key) {
			Node* temp = a;
			a = b;
			b = temp;
		}
		Node* an = a->next;
		Node* bp = b->prev;
		a->next = b;
		b->prev = a;
		an->prev = bp;
		bp->next = an;
		return a;
	}

	void addChild(Node* parent, Node* child) {
		child->prev = child->next = child;
		child->parent = parent;
		parent->degree++;
		parent->child = mergeTop(parent->child, child);
	}

	Node* cut(Node* min, Node* n) {
		if (n->next == n) {
			n->parent->child = NULL;
		}
		else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
			n->parent->child = n->next;
		}
		n->next = n->prev = n;
		n->mark = false;
		return mergeTop(min, n);
	}

	Node* decreaseKey(Node* min, Node* n, int key) {
		if (n->key < key)return min;
		n->key = key;
		if (n->parent) {
			if (n->key < n->parent->key) {
				min = cut(min, n);
				Node* parent = n->parent;
				n->parent = NULL;
				while (parent != NULL && parent->mark) {
					min = cut(min, parent);
					n = parent;
					parent = n->parent;
					n->parent = NULL;
				}
				if (parent != NULL && parent->parent != NULL)parent->mark = true;
			}
		}
		else {
			if (n->key < min->key) {
				min = n;
			}
		}
		return min;
	}
};

int main() {
	FibonacciHeap* h = new FibonacciHeap();

	int size = 20000000;
	int step = 2000000;
	int div = size / 100;

	for (int i = step; i <= size; i += step) {
		string path = "D:\\Projects\\Cpp\\tests\\seq-length-" + to_string(i) + ".txt";
		ifstream file(path);
		int s;

		file >> s;

		while (!file.eof()) {
			h->insert(s);
			file >> s;
		}
		double startTime = clock();
		h->insert(s);

		double addTime = clock();
		cout << "add " << addTime - startTime << " ";

		h->removeMin();
		double decTime = clock();
		cout << "del " << decTime - addTime << " ";

		h->decreaseKey(h->min, h->min->child, 0);
		double endTime = clock();
		cout << "decr " << endTime - decTime << endl;

		file.close();
	}
	return 0;
}