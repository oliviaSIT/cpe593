// create by Jiabin Li

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Trie {
private:
        class Node {
        public:
                Node** next;
                bool isWord;
                
                Node() {
                        isWord = false;
			next = new Node*[26];
                }

                ~Node() {
                        for (int i = 0; i < 26; i++) {
                                if (next[i] != NULL) {
                                        delete next[i];
                                        next[i] = NULL;
                                }
                        }
                }
        };

        Node root;

public:
        Trie() {
		root = Node();	
	}

        void insert(const string& word) {
                Node* p = &root;
                for (int i = 0; i < (int)word.size(); i++) {
                        if (p->next[word[i] - 'a'] == NULL) {
                                p->next[word[i] - 'a'] = new Node();
                        }

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

	void createDictionary (const string& filename) {
		fstream file(filename);
		//file.open();
		string line;

		while (getline(file, line)) {
			insert(line);
			line = "";
		}

		file.close();
	}
};

int main() {
        Trie trie;
	trie.createDictionary("dict.txt");

	fstream f("hw5.txt");
	string str;
	//f.open();

	while (getline(f, str)) {
/*
		if(trie.containsPrefix(str))
			cout << 1 << ' ' << str << " is prefix" << endl;
		else cout << 0 << ' ' << str << " is NOT prefix" << endl;
*/
		if(trie.contains(str))
                        cout << 1 << ' ' << str << " is in the dictionary" << endl;
                else cout << 0 << ' ' << str << " is NOT in the dictionary" << endl;

		str = "";
	}

	f.close();
}
