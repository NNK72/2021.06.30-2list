#include <iostream>
#include <ctime>
using namespace std;

class DoubleList {
	class Node {
	public:
		Node* pPrev;		int data;		Node* pNext;
		Node(Node* pPrev = nullptr, int data = 0, Node* pNext = nullptr) :pPrev{ pPrev }, data{ data }, pNext{ pNext }{cout << "constructor Node "<<this << endl; }
		~Node() { cout << "distructor Node " << endl; }
	};
	Node* head;		Node* tail;		int size;
public:
	DoubleList():size{0} {
		cout << "constructor DoubleList " << this << endl;
		head = tail = nullptr;		
	}
	~DoubleList() { cout<<"distructor DoubleList " << this <<endl; }
	int getSize() { return size; }
	void push_front(int data) {
		if (head == nullptr) {
			head = new Node(nullptr, data, nullptr);
			tail = head;	size++;
		}
		else {
			Node* newNode = new Node(nullptr, data, head);
			head->pPrev = newNode;
			head = newNode;
		}
		size++;
	}
	void push_back(int data) {
		if (tail == nullptr) { tail = new Node(nullptr, data, nullptr);  head = tail; }
		else {
			Node* newNode = new Node(tail, data, nullptr);
			tail->pNext = newNode;
			tail = newNode;
		}
		size++;
	}
	int operator[](const int index) {
		int counter = 0;
		if (index < size / 2) {
			Node* current = head;
			while (current != nullptr) {
				if (index == counter) return current->data;
				else current = current->pNext;
				counter++;
			}
		}
		else {
			Node* current = tail;
			while (current != nullptr) {
				if (index == size - counter - 1) { return current->data; }
				else current = current->pPrev;
				counter++;
			}
		}
	}
	void output() {
		cout << "output: " ;
		for (int i = 0; i < size; i++) {
			cout << (*this)[i] << " ";
		}
		cout << endl;
	}
	void input(int size) {	srand(time(NULL));
		for (int i = 0; i < size; i++)		{
			push_back((rand() % 100));
		}
	}
	void pop_front() {
		Node* temp = head->pNext;
		delete head;	head = temp;	size--;
	}
	void clear() {	for (int i = size; i > 0; i--)	pop_front();	}
	void insert(int data, int index){
		if (index == 0) push_front(50);
		else if (index == size) push_back(data);
		else if (index < size / 2) {
			Node* previous = head;//f0
			for (int i = 0; i < index-1; i++){  //index1
				previous = previous->pNext;//  fo = f1 ----->  f1
			}
			Node* newNode = new Node(previous, data, previous->pNext);
			previous->pNext->pPrev = newNode;
			previous->pNext= newNode;
			size++;
		}
		else {
			Node* previous = tail;
			for (int i = 0; i < size; i++){
				previous = previous->pPrev;
			}
			Node* newNode = new Node(previous, data, previous->pNext);
			previous->pNext->pPrev = newNode;
			previous->pNext = newNode;
			size++;
		}
	}
	//void removeAt(int index) {
	//	if (index == 0) {
	//		pop_front();
	//	}
	//	if (index < size / 2) {

	//	}
	//}
};

int main() {
	DoubleList list;
	list.input(7);
	list.output();
	list.insert(50, 1);
	list.output();
	return 0;
}
