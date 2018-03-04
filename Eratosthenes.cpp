#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool betterEratosthenes(int n) {
	vector<bool> res(n + 1, 1);
	res[0] = 0;
	res[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		if (res[i] == 1) {
			for (int j = i * i; j <= n;j += 2 * i) 
				res[j] = 0;
		}
	}

	return res[n]; 	
}

int main() {
	cout << betterEratosthenes(2) << endl;
	cout << betterEratosthenes(23) << endl;
	cout << betterEratosthenes(200) << endl;
	return 0;
}
