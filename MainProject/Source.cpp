#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int key;      // ключ
	Node* parent;  // указатель на родительский узел
	Node* child;  // указатель на один из дочерних узлов
	Node* left;  // указатель на левый узел того же предка
	Node* right;  // указатель на правый узел того же предка
	int degree;  // степень вершины
	bool mark;// был ли удален в процессе изменения ключа ребенок этой вершины)
};

struct FibonacciHeap {
	int size = 0; // текущее количество узлов
	Node* min = NULL; // указатель на корень дерева с минимальным ключом 

	void insert(int x) {
		Node* newNode = new Node();               //  создаем новый узел 
		newNode->key = x;          //   инициализируем ключ нового узла
		if (size == 0) {             //   если куче нет элементов, то только что добавленный минимальный
			min = newNode;
			min->left = newNode;
			min->right = newNode;
		}
		else {                     // иначе аккуратно меняем указатели в списке, чтобы не перепутать указатели
			Node* prevRight = min->right;
			min->right = newNode;
			newNode->left = min;
			newNode->right = prevRight;
			prevRight->left = newNode;
		}
		if (newNode->key < min->key) {
			min = newNode;
		}// меняем указатель на минимум, если надо
				newNode->parent;
				size++;                  // не забываем увеличить переменную size 
			
		
	}

	int getMin() {
		return min->key;
	}

	void unionLists(Node* first, Node* second) {
		Node* L = first->left;             // аккуратно меняем указатели местами указатели
		Node* R = second->right;
		second->right = first;
		first->left = second;
		L->right = R;
		R->left = L;
	}

	void merge(FibonacciHeap* that) {
		if (that->size == 0)            // если вторая куча пуста, нечего добавлять
			return;
		if (size = 0) {                    // если наша куча пуста, то результатом будет вторая куча
			min = that->min;
			size = that->size;
		}
		else {
			unionLists(min, that->min); // объединяем два корневых списка
			size += that->size;
			if (min || (that->min and that->min < min)) { // если минимум кучи изменился, то надо обновить указатель
				min = that->min;
			}
		}
	}

	void consolidate() {
		Node* A[1024];
		A[min->degree] = min;               // создаем массив и инициализируем его min
		Node* current = min->right;
		while (A[current->degree] != current) {   // пока элементы массива меняются
			if (A[current->degree]) {     // если ячейка пустая, то положим в нее текущий элемент
				A[current->degree] = current;
				current = current->right;
			}
			else {                  // иначе подвесим к меньшему из текущего корня и того, который лежит в ячейке другой
				Node* conflict = A[current->degree];
				Node* addTo,* adding;

				if (conflict->key < current->key) {
					addTo = conflict;
					adding = current;
				}
				else {
					addTo = current;
					adding = conflict;
				}
				unionLists(addTo->child, adding);
				adding->parent = addTo;
				addTo->degree++;
				current = addTo;
			}
			if (min->key > current->key)      // обновляем минимум, если нужно
				min = current;
		}
	}

	int deleteMin() {
		Node* prevMin = min;
		unionLists(min, min->child);   // список детей min объединяем с корневым
		Node* L = min->left;            // аккуратно удаляем min из списка
		Node* R = min->right;
		L->right = R;
		R->left = L;
		if (prevMin->right == prevMin)  // отдельно рассмотрим случай с одним элементом
			return min->key;

		min = min->right;              // пока что перекинем указатель min на правого сына, а далее consolidate() скорректирует min в процессе выполнения
		consolidate();
		size--;
		return prevMin->key;
	}
};

int main() {
	FibonacciHeap* heap = new FibonacciHeap();
	int array[] = { 23, 54, 12, 54, 7, 3, 234, 6, 34, 90 };
	for (int i = 0; i < 10; i++) {
		heap->insert(array[i]);
	}
	heap->deleteMin();
	cout << heap->getMin();

	return 0;
}

