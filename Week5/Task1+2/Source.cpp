#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next = NULL;
	Node* prev = NULL;
};

struct UniqueList {
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
			if (node->val == temp->val) {
				return;
			}
			if (node->val > temp->val) {
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

int main() {
	UniqueList* list = new UniqueList();

	for (int i = 0; i < 10; i++) {
		list->add(rand()%101);
	}

	list->add(0);
	list->add(44);
	list->add(10);
	list->add(9);
	list->add(9);
	list->add(9);
	list->display();
	list->remove(4);
	list->display();
	list->remove(0);
	list->display();
	list->remove(list->size()-1);
	list->display();
	list->add(1010);
	list->display();

	return 0;
}