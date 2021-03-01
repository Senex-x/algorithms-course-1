#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

struct Stack {
	Node* head = NULL;

	void Push(int val) {
		Node* node = new Node;
		node->val = val;
		node->next = head;
		head = node;
	}

	int Pop() {
		if (!head) throw 1;
		Node* temp = head;
		int val = temp->val;
		head = temp->next;
		delete temp;
		return val;
	}

	int Peek() {
		if (!head) throw 1;
		return head->val;
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
	Stack* stack = new Stack;
	for (int i = 0; i < 5; i++) {
		stack->Push(i + 1);
	}

	stack->PrintAll();
	return 0;
}