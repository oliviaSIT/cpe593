// created by Jiabin.Li

#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
	class Node {
	public:
		Node* next[26];
		bool isWord;
/*
		Node() {
			next = new Node*[26];
			isWord = false;
		}

		~Node() {
			delete[] next;
		}
*/
	};

	Node root;

public:
	Trie() {
//		root = new Node();
	}

	void insert(const string& word) {
		Node* p = &root;
		for (int i = 0; i < (int)word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL)
				p->next[word[i] - 'a'] = new Node();

			p = p->next[word[i] - 'a'];
		}

		p->isWord = true;
	}

	bool contains(const string& word) {
		Node* p = &root;
		for (int i = 0; i < (int)word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL)
				return false;
	
			p = p->next[word[i] - 'a']; 
		}

		return p->isWord;
	}

	bool containsPrefix(const string& word) {
		Node* p = &root;
		for(int i = 0; i < (int)word.size(); i++) {
                        if (p->next[word[i] - 'a'] == NULL)
                                return false;

                        p = p->next[word[i] - 'a'];
                }

                return true;
	}

	
	
};

int main() {
	Trie trie;
	trie.insert("apple");
	cout << trie.contains("apple") << endl;
	cout << trie.contains("app") << endl;
	cout << trie.containsPrefix("app") << endl;
	return 0;
}
