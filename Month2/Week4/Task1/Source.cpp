#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next = NULL, * prev = NULL;
};
 
struct LinkedList {
	Node* head = NULL, * end;

	void Add(int val) {
		Node* node = new Node;
		node->val = val;
		if (head == NULL) {
			head = node;
			end = node;
		} else {
			end->next = node;
			node->prev = end;
			end = node;
		}
	}

	void Insert(int val, int ind) {
		if (ind < 0 || ind > Size()) throw 1;
		if (head == NULL) {
			Add(val);
			return;
		}
		Node* temp = head;
		Node* node = new Node;
		node->val = val;
		if (ind == 0) {
			node->next = head;
			head->prev = node;
			head = node;
		}
		else if (ind == Size()) {
			node->prev = end;
			end->next = node;
			end = node;
		}
		else {
			int c = 0;
			while (c != ind) {
				temp = temp->next;
				c++;
			}
			temp->prev->next = node;
			node->prev = temp->prev;
			node->next = temp;
			temp->prev = node;
		}
	}

	void Remove(int ind) {
		if (ind < 0 || ind >= Size()) throw 1;
		Node* temp = head, * buf;
		if (ind == 0) {
			head->next->prev = NULL;
			head = head->next;
		}
		else if (ind == Size() - 1) {
			end->prev->next = NULL;
			end = end->prev;
		}
		else {
			int c = 0;
			while (c != ind) {
				temp = temp->next;
				c++;
			}
			buf = temp->prev;
			temp->prev->next = temp->next;
			temp->next->prev = buf;
		}
	}

	int Size() {
		int c = 0;
		Node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			c++;
		}
		return c;
	}

	int Get(int ind) {
		if (ind >= Size()) throw 1;
		int c = 0;
		Node* temp = head;
		while (c != ind) {
			if (temp == NULL) {
				throw 1;	
			}
			temp = temp->next;
			c++;
		}
		return temp->val;
	}

	void PrintAll() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
	}
};

int main() {
	LinkedList* list = new LinkedList;

	for (int i = 0; i < 10; i++) {
		list->Add(i + 1);
	}
	list->PrintAll();
	cout << endl;
	list->Remove(9);
	list->Remove(3);
	list->Remove(0);
	list->PrintAll();

	return 0;
}