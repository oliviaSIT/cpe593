// created by Jiabin Li

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedList {
private:
	class Node {
	public:
		Node* next;
		string word;
		
		Node() {
			word = "";
			next = nullptr;
		}

		Node(string w, Node* p): word(w), next(p) {}
	};

	Node* head;
	uint32_t used;

public:
	LinkedList(): head(nullptr), used(0) {}

	~LinkedList() {
		Node* temp = head;
		while (temp != nullptr) {
			head = temp->next;
			delete temp;
			temp = head;
		}
	}

	uint32_t addStart(const string& str) {
		Node* temp = new Node(str, head);
		head = temp;
		used++;
		return used;
	}

	string removeStart() {
		if (head == nullptr)
			return "";

		Node* temp = head;
		string str = temp->word;
		head = temp->next;
		delete temp;

		used--;
		return str;
	}

	bool findWord(const string& str) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->word == str)
				return true;

			temp = temp->next;
		}

		return false;
	}
};

class HashMapLinearChaining {
private:
	LinkedList* bin;
	uint32_t size;
	uint32_t used;
	uint32_t histogram[51] = {0};
	
	uint32_t hash(const string& str) {
		uint32_t len = str.size();

		for (int i = 0; i < (int)str.size(); i++) 
			len = ((len << 5) + (len >> 17) + str[i]) ^ len;

		return len & (size - 1);
	}

	void grow() {
		uint32_t size_old = size;
		LinkedList* old = bin;
		size *= 2;
		bin= new LinkedList[size];
		used = 0;
		
		for (int i = 0; i < (int)size_old; i++) {
			string str = old[i].removeStart();
			
			while (!str.empty()) {
				addHash(str);
				str = old[i].removeStart();
			}
		}

		delete old;
		histogram[0] = size - used;
	}
	
public:
	HashMapLinearChaining(uint32_t initialSize = 1024): size(initialSize), used(0) {
		uint32_t i = 1, n = 0;

		while (i < size && n < 32) {
			i *= 2;
			n++;
		}

		size = i;

		bin = new LinkedList[size];
		histogram[0] = size - used;

	}	

/*
	HashMapLinearChaining(const HashMapLinearChaining& orig): size(orig.size), used(orig.used) {
		bin = new LinkedList[size];

		for (int i = 0; i < size; i++)
			bin[i] = orig.bin[i];

		histogram[0] = size - used;

		for (int i = 1; i < 11; i++)
			histogram[i] = 0;
	}
*/
	
	~HashMapLinearChaining() {
		delete[] bin;
	}

	void addHash(const string& str) {
		uint32_t index = hash(str);
		int count = bin[index].addStart(str);
		used++;
		if (count >= 50)
			count = 50;
		histogram[count]++;
		histogram[0]--;
		if (used * 4 > size)
			grow();
	}

	bool findHash(const string& str) {
		if (str.empty())
			return false;

		uint32_t index = hash(str);
		return bin[index].findWord(str);
	}

	void displayHistogram() {
		for (int i = 0; i < 50; i++)
			cout << i << ": " << histogram[i] << endl;
		cout << ">= 50: " << histogram[50] << endl;
	}		

};

void loadDictionary(HashMapLinearChaining& hash, string filename) {
	ifstream f(filename);
	string str; 
	while (f >> str) {
		hash.addHash(str);
	}

	hash.displayHistogram();
	f.close();
}

void checkWord(HashMapLinearChaining& hash, string filename) {
	ifstream f(filename);
	string str;

	while (f >> str) {
		cout << str << ": ";
		if (hash.findHash(str))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	f.close();
}

int main() {
	HashMapLinearChaining hash(1024);
	loadDictionary(hash, "hw8.dat");
	checkWord(hash, "hw8.dat");
	return 0;
}
