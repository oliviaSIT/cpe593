#include <iostream>

using namespace std;

int gcdLoop(int a, int b) {
	if (a == b)
		return a;

	if (a < b) 
		swap(a, b);

	while (b != 0) {
		int t = a;
		a = b;
		b = t % b;	
	}

	return a;
}

int main() {
	cout << gcdLoop(12, 18) << endl;
	cout << gcdLoop(18, 12) << endl;
	cout << gcdLoop(19, 21) << endl;
	return 0;
}

