#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};
 
struct List {
	Node* head = NULL, * end;

	void Add(int val) {
		Node* node = new Node;
		node->val = val;
		node->next = NULL;
		if (head == NULL) {
			head = node;
			end = node;
		} else {
			end->next = node;
			end = node;
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
};

int main() {
	List* list = new List;

	list->Add(10);
	list->Add(20);

	cout << list->Size() << endl << list->Get(1);
	return 0;
}