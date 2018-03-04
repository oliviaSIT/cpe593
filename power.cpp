#include <iostream>

using namespace std;

int power(int x, int n) {
	int prod = 1;

	while (n != 0) {
		if (n % 2 == 1)
			prod = x * prod;

		x *= x;
		n = n / 2;
	}

	return prod;
}

int main() {
	cout << power(2, 11) << endl;
	return 0;
}
