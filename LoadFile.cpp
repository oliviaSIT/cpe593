#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char* loadFile(const char filename[]) {
        vector<char> res;

        ifstream f(filename);
        char c;
        while(f.get(c)) {
                res.push_back(c);
        }

	res.push_back('\0');

        f.close();
        
        return res.begin();
}

int main(int argc, char* argv[]) {
	char* A = loadFile(argv[1]);
	char* B = loadFile(argv[2]);

	cout << "file1:" << endl;
	
	int i = 0;
	while (*A != '\0') {
		cout << *A;
		i++;
	}
	cout << endl;

	cout << "file2:" << endl;

	int j = 0;
        while (*B != '\0') {
                cout << *B;
                j++;
        }
        cout << endl;
//	cout << "the result is: " << LCS(a, b) << endl;
	return 0;
}
