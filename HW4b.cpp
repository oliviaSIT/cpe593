// created by Jiabin.Li

#include <iostream>

using namespace std;
 
class Node {
public:
	int data;
	Node* next;

	Node(): next(nullptr) {}

	Node(int v, Node* p): data(v), next(p) {}
};

class LinkedList2 {
private:
	Node node;
	Node* head;
	Node* tail;

public:
	LinkedList2(): head(nullptr), tail(nullptr) {}

	~LinkedList2() {
		for (Node* p = head; p != nullptr;) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
	}

	void addFront(int v) {
		Node* temp = new Node(v, head);

		if (head == nullptr) {
			head = temp;
			tail = temp;
		} else	{
			head = temp;
		}
	}

	void addBack(int v) {
		Node* temp = new Node(v, nullptr);
		if (head == nullptr)
			head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void removeFront() {
		if (head == nullptr)
			return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void removeBack() {
		if (head == nullptr)
			return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}

		Node* current = head;
		while (current->next != tail)
			current = current->next;

		current->next = nullptr;
		tail = current;		
	}

	void output() {
		if (head == nullptr)
			cout << "The list is empty." << endl;

		for (Node* current = head; current != nullptr; current = current->next)
			cout << current->data << ' ';

		cout << endl;
	}
};

int main() {
	LinkedList2 list;
	list.addFront(2);
	list.output();
	list.addFront(1);
	list.output();
	list.addBack(3);
	list.output();
	list.removeFront();
	list.removeBack();
	list.output();

	return 0;
}
