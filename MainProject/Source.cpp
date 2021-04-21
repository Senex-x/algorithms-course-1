#include<iostream>
#include<fstream>

using namespace std;

struct node {
	node* prev;
	node* next;
	node* child;
	node* parent;
	int key;
	int degree;
	bool marked;
};

struct FibonacciHeap {
	int size = 0;
	node* min = NULL;	

	node* insert(int key) {
		node* ret = _singleton(key);
		min = mergeTop(min, ret);
		size++;
		return ret;
	}

	void merge(FibonacciHeap& other) {
		min = mergeTop(min, other.min);
		other.min = NULL;
	}

	int getMin() {
		return min->key;
	}

	int removeMin() {
		node* old = min;
		min = _removeMinimum(min);
		int ret = old->key;
		delete old;
		size--;
		return ret;
	}

	void display(node* min) {
		node* ptr = min;
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

	node* _singleton(int key) {
		node* n = new node;
		n->key = key;
		n->prev = n->next = n;
		n->degree = 0;
		n->marked = false;
		n->child = NULL;
		n->parent = NULL;
		return n;
	}

	node* mergeTop(node* a, node* b) {
		if (a == NULL)return b;
		if (b == NULL)return a;
		if (a->key > b->key) {
			node* temp = a;
			a = b;
			b = temp;
		}
		node* an = a->next;
		node* bp = b->prev;
		a->next = b;
		b->prev = a;
		an->prev = bp;
		bp->next = an;
		return a;
	}

	void _deleteAll(node* n) {
		if (n != NULL) {
			node* c = n;
			do {
				node* d = c;
				c = c->next;
				_deleteAll(d->child);
				delete d;
			} while (c != n);
		}
	}

	void _addChild(node* parent, node* child) {
		child->prev = child->next = child;
		child->parent = parent;
		parent->degree++;
		parent->child = mergeTop(parent->child, child);
	}

	void _unMarkAndUnParentAll(node* n) {
		if (n == NULL)return;
		node* c = n;
		do {
			c->marked = false;
			c->parent = NULL;
			c = c->next;
		} while (c != n);
	}

	node* _removeMinimum(node* n) {
		_unMarkAndUnParentAll(n->child);
		if (n->next == n) {
			n = n->child;
		}
		else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
			n = mergeTop(n->next, n->child);
		}
		if (n == NULL)return n;
		node* trees[64] = { NULL };

		while (true) {
			if (trees[n->degree] != NULL) {
				node* t = trees[n->degree];
				if (t == n)break;
				trees[n->degree] = NULL;
				if (n->key < t->key) {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					_addChild(n, t);
				}
				else {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					if (n->next == n) {
						t->next = t->prev = t;
						_addChild(t, n);
						n = t;
					}
					else {
						n->prev->next = t;
						n->next->prev = t;
						t->next = n->next;
						t->prev = n->prev;
						_addChild(t, n);
						n = t;
					}
				}
				continue;
			}
			else {
				trees[n->degree] = n;
			}
			n = n->next;
		}
		node* min = n;
		node* start = n;
		do {
			if (n->key < min->key)min = n;
			n = n->next;
		} while (n != start);
		return min;
	}

	node* cut(node* min, node* n) {
		if (n->next == n) {
			n->parent->child = NULL;
		}
		else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
			n->parent->child = n->next;
		}
		n->next = n->prev = n;
		n->marked = false;
		return mergeTop(min, n);
	}

	node* decreaseKey(node* min, node* n, int key) {
		if (n->key < key)return min;
		n->key = key;
		if (n->parent) {
			if (n->key < n->parent->key) {
				min = cut(min, n);
				node* parent = n->parent;
				n->parent = NULL;
				while (parent != NULL && parent->marked) {
					min = cut(min, parent);
					n = parent;
					parent = n->parent;
					n->parent = NULL;
				}
				if (parent != NULL && parent->parent != NULL)parent->marked = true;
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

#include<string>
#include<cstring>
#include<sstream>


int main() {
	FibonacciHeap* h = new FibonacciHeap();

	

	int size = 30000000;
	int div = size / 100;

	for (int i = 12000000; i < 20000000; i += 2000000) {
		string path = "D:\\Projects\\Cpp\\tests\\seq-length-" + to_string(i) + ".txt";
		ifstream file(path);
		int s;
		
		file >> s;
		double startTime = clock();
		while (!file.eof()) {
			h->insert(s);
			file >> s;
		}
		double addTime = clock();
		cout << "add " << addTime << " ";

		h->removeMin();
		double decTime = clock();
		cout << "del " << decTime - addTime << " ";

		h->decreaseKey(h->min, h->min->child, 0);
		double endTime = clock();
		cout << "dec " << endTime - decTime << endl;

		file.close();
	}
	return 0;
}