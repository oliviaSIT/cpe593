#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file("hello.txt");
	string s;
	getline(file, s);
	cout << s <<endl;
	return 0;

}
