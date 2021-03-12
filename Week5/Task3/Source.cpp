#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next = NULL;
	Node* prev = NULL;
};

struct SortedList {
	Node* head = NULL;
	Node* end = NULL;

	void add(int v) {
		Node* node = new Node();
		node->val = v;
		if (head == NULL) {
			head = node;
			end = node;
			return;
		}
		Node* temp = end;
		Node* buf;
		while (temp != NULL) { 
			if (node->val >= temp->val) {
				if (temp == end) {
					node->prev = end;
					end->next = node;
					end = node;
					return;
				}
				buf = temp->next;
				temp->next = node;
				node->prev = temp;
				node->next = buf;
				buf->prev = node;
				return;
			}
			temp = temp->prev;
		}
		buf = head;
		head->prev = node;
		head = node;
		node->next = buf;
	}

	int get(int id) {
		int c = 0;
		Node* temp = head;
		while (c != id) {
			if (temp == NULL) {
				throw 1;
			}
			temp = temp->next;
			c++;
		}
		return temp->val;
	}

	int size() {
		int c = 0;
		Node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			c++;
		}
		return c;
	}

	void remove(int id) {
		int c = 0;
		Node* temp = head;
		if (id >= size()) throw 1;
		if (size() == 1) {
			head = NULL;
			end = NULL;
		}
		else if (id == 0) {
			head->next->prev = NULL;
			head = head->next;
		}
		else if (id == size() - 1) {
			end->prev->next = NULL;
			end = end->prev;
		}
		else {
			while (c != id) {
				if (temp == NULL) {
					throw 1;
				}
				temp = temp->next;
				c++;
			}		
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;		
		}
	}

	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

// 1 3 5 7 9
// 2 3 4 6 

SortedList* merge(SortedList* first, SortedList* second) {
	Node *t1 = first->head;
	Node *t2 = second->head;
	SortedList *res = new SortedList();

	while (t1 != NULL && t2 != NULL) {
		if (t1->val < t2->val) {
			if (res->end == NULL) {
				res->add(t1->val);
			}
			else if (t1->val != res->end->val) {
				res->add(t1->val);
			}
			t1 = t1->next;
		}
		else if (t1->val > t2->val) {
			if (res->end == NULL) {
				res->add(t2->val);
			}
			else if (t2->val != res->end->val) {
				res->add(t2->val);
			}
			t2 = t2->next;
		}
		else {
			if (res->end == NULL) {
				res->add(t1->val);
			} else if (t1->val != res->end->val) {
				res->add(t1->val);
			}
			t1 = t1->next;
			t2 = t2->next;
		}
	}

	if (t1 != NULL) {
		res->end->next = t1;
		t1->prev = res->end;
		res->end = first->end;
	} else if (t2 != NULL) {
		res->end->next = t2;
		t2->prev = res->end;
		res->end = first->end;
	}

	return res;
}

SortedList* intersect(SortedList* first, SortedList* second) {
	Node *t1 = first->head;
	Node *t2 = second->head;
	SortedList *res = new SortedList();

	while (t1 != NULL && t2 != NULL) {
		if (t1->val < t2->val) {
			t1 = t1->next;
		}
		else if (t1->val > t2->val) {
			t2 = t2->next;
		}
		else {
			res->add(t1->val);
			t1 = t1->next;
			t2 = t2->next;
		}
	}

	return res;
}

SortedList* differ(SortedList* first, SortedList* second) {
	Node *t1 = first->head;
	Node *t2 = second->head;
	SortedList *res = new SortedList();

	while (t1 != NULL && t2 != NULL) {
		if (t1->val < t2->val) {
			if (res->end == NULL) {
				res->add(t1->val);
			}
			else if (res->end->val != t1->val) {
				res->add(t1->val);
			}
			t1 = t1->next;
		}
		else if (t1->val > t2->val) {			
			t2 = t2->next;
		}
		else {
			if (t1->next != NULL && t1->next->val == t2->val) {
				t1 = t1->next;
			}
			else if (t2->next != NULL && t2->next->val == t1->val) {
				t2 = t2->next;
			}
			else {
				t1 = t1->next;
				t2 = t2->next;
			}
		}
	}

	
	if (t1 != NULL) {
		if (res->size() == 0) {
			res->head = t1;
			res->end = first->end;
			t1->prev = NULL;
		}
		else {
			res->end->next = t1;
			t1->prev = res->end;
			res->end = first->end;
		}
	}
	return res;
}


int main() {
	SortedList* list1 = new SortedList();
	SortedList* list2 = new SortedList();

	for (int i = 0; i < 10; i++) {
		list1->add(rand() % 21);
		list2->add(rand() % 21);
	}
	list1->display();
	list2->display();

	SortedList *mergedList = merge(list1, list2);
	mergedList->display();

	SortedList *intersectedList = intersect(list1, list2);
	intersectedList->display();

	SortedList *differedList = differ(list1, list2);
	differedList->display();

	return 0;
}