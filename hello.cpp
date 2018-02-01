#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream file("hello.txt");
	string s;
	while(!file.eof()){
		getline(file, s);
		cout << s << endl;
	}
	//file.close();
	return 0;
}
