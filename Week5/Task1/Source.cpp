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
		while (temp != NULL) { // 1 3 (4) 5 7 9
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
	SortedList* list = new SortedList();

	list->add(0);
	list->add(44);
	list->add(10);
	list->add(9);
	list->display();

	return 0;
}