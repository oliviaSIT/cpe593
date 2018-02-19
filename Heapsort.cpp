#include <iostream>
#include <vector>

using namespace std;

void MAX_HEAPIFY(int a[], int i, int n) {
        int l, r, largest, loc;
        l = 2 * i;
        r = 2 * i + 1;

        if((l < n) && (a[l] > a[i]))
                largest = l;
        else
                largest = i;

        if((r < n) && (a[r] > a[largest]))
                largest = r;

        if(largest!=i) {
                loc = a[i];
                a[i] = a[largest];
                a[largest] = loc;
                MAX_HEAPIFY(a, largest, n);
        }
}

void buildMaxHeap(int a[], int n) {
        int i;
        for(i = n/2; i >= 0; i--)
                MAX_HEAPIFY(a, i, n);
}

void heapSort(int a[], int n) {
	buildMaxHeap(a, n);

	int i, temp;
	for (i = n - 1; i >= 1; i--) {
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		// Building max heap of remaining element.
		MAX_HEAPIFY(a, 0, i - 1);
	}
}

int main() {
	int n = 5;
	int a[] = {4, 2, 5, 1, 3};
	heapSort(a, n);
 
	// Printing the sorted data.
	cout << "\nSorted Data ";
 
	for (int i = 0; i < n; i++)
		cout << "->" << a[i];

	cout << endl;
 
	return 0;
}


