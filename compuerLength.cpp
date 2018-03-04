#include <iostream>

using namespace std;

int computerLength(char* A) {
        char* idx = A;
        int n = 0;
        while (*idx != '\0') {
                n++;
                idx++;
        }

        return n;

}

int main() {
	char A1[] = {'c', '+', '+'};
	char A2[] = {'c', '+', '+', '\0'};
	char A3[] = {'c', ' ', '+', '+'};

	cout << computerLength(A1) << ' ' <<  computerLength(A2) << ' ' <<  computerLength(A3) << endl;

	return 0;

}
