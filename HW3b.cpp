//created by Jiabin.Li

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int Partition(vector<int>& v, int p, int r) {
        int k = (rand() % (r - p + 1)) + p;
        swap(v[k], v[r]);

        int pivot = v[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
                if (v[j] <= pivot) {
                        i++;
                        swap(v[i], v[j]);
                }
        }

        swap(v[i + 1], v[r]);

        return i+1;
}


void quickSort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = Partition(v, p, r);
		quickSort(v, p, q - 1);
		quickSort(v, q + 1, r);
	}
} 

int main() {
	vector<int> v;
//	int n;
	for (int i = 20; i > 0; i--) {
		//n = rand() % 1001;
		v.push_back(i);
	}
	
	quickSort(v, 0, v.size() - 1);

	for (size_t i = 0; i < 20; i++) {
		cout << v[i] << ' ';
	}

	cout << endl;
	

	return 0;
}
