#include <iostream>

using namespace std;

struct Node {
	int val;
	Node * next = NULL;
};
 
struct Queue {
	Node* head = NULL, * end;

	void Enqueue(int val) {
		Node* node = new Node;
		node->val = val;
		if (head == NULL) {
			head = node;
			end = node;
		} else {
			end->next = node;
			end = node;
		}
	}

	int Dequeue() {
		if (Size() == 0) throw 1;
		int val = head->val;
		if (Size() == 1) {
			head = NULL;
			end = NULL;
		}
		else {
			head = head->next;
		}
		return val;
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

	void PrintAll() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
	}
};

int main() {
	Queue* q = new Queue;

	for (int i = 0; i < 10; i++) {
		q->Enqueue(i + 1);
	}
	q->PrintAll();
	cout << q->Size();

	cout << endl << q->Dequeue();

	return 0;
}