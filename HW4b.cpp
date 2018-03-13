// created by Jiabin.Li

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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

        vector<int> getDigit(string s) {
                int x, y ,z;
                size_t sz, sz1;
                x = stoi(s, &sz);
                string s1 = s.substr(sz + 1);
                y = stoi(s1, &sz1);
                string s2 = s1.substr(sz1 + 1);
                z = stoi(s2, nullptr);
                vector<int> res;
                res.push_back(x);
                res.push_back(y);
                res.push_back(z);
                return res;
        }


	void readFile(const char fileName[]) {
		fstream file;
		file.open(fileName);
		string line, instructor, v1;
		int start, end, step;		

		while (!file.eof()) {
			getline(file, line);
			istringstream iss(line);
			iss >> instructor;

			if (instructor == "ADD_FRONT") {
				iss >> v1;
				vector<int> digit = getDigit(v1);
				start = digit[0];
				end = digit[2];
				step = digit[1];
				for (int i = 0; i <= (end - start) / step; i++) {
					addFront(start + i * step);
				}		
			}

			if (instructor == "ADD_BACK") {
				iss >> v1;
				vector<int> digit = getDigit(v1);
				start = digit[0];
				end = digit[2];
				step = digit[1];
				for (int i = 0; i <= (end - start) / step; i++)
					addBack(start + i * step);
				
			}

			if (instructor == "REMOVE_FRONT") {
				iss >> step;
				for (int i = 0; i < step; i++)
					removeFront();
			}

			if (instructor == "REMOVE_BACK") {
				iss >> step;
				for (int i = 0; i < step; i++)
					removeBack();
			}

			if (instructor == "OUTPUT")
				output();
			
			instructor = "";
			v1 = "";
		}

	}

};

int main(int argc, char* argv[]) {
	LinkedList2 list;
	list.readFile(argv[1]);
	return 0;
}
