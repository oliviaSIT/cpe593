#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; i++) {
		if (n != 2 && n % i == 0)
			return false;
	}

	return true;
}

int main() {
	cout << isPrime(2) << ' ' << isPrime(23) << ' ' << isPrime(100) << endl;
	return 0;
}
