#include <iostream>

using namespace std;

int gcdRecurse(int a, int b) {
	if (a == b) return a;

	if (a < b) swap(a, b);

	if (b == 0) 
		return a;
	else 
		gcdRecurse(b, a % b);

	
}

int main() {
	cout << gcdRecurse(12, 18) << ' ' << gcdRecurse(12, 19) << endl;
	return 0;
}
