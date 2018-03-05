#include<iostream>

using namespace std;

int main() {
	int* x = new int[3];

	int j = 0;
	
	for (int i = 0; i < 3; i++) {
		x[i] = j++;
		cout << x[i] << endl;
	}

	return 0;

}
