#include <iostream>

using namespace std;

void merge(int a[], int st, int md, int ed) {
	int n1 = md - st + 1;
	int n2 = ed - md;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = a[st + i];
	}

	for (int j = 0; j < n2; j++) {
		R[j] = a[md + j + 1];
	}

	int i = 0, j = 0, k = st;	
 	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			a[k++] = L[i++];
		} else {
			a[k++] = R[j++];
		}
	}

	while (i < n1) {
		a[k++] = L[i++];
	}

	while (j < n2) {
                a[k++] = R[j++];
        }


}

void mergeSort(int a[], int st, int ed) {
	if (st < ed ) {
		int md = st + (ed - st) / 2;

		mergeSort(a, st, md);
		mergeSort(a, md + 1, ed);
	
		merge(a, st, md, ed);
	}
}


int main() {
	int n = 5;
	int a[] = {4, 2, 5, 1, 3};
	mergeSort(a, 0, n - 1);
 
	// Printing the sorted data.
	cout << "\nSorted Data ";
 
	for (int i = 0; i < n; i++)
		cout << "->" << a[i];

	cout << endl;
 
	return 0;
}
