// created by Jiabin.Li

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& data) {
	if (data.empty()) {
		return;
	}

	if (data.size() == 1) {
		return;
	}


	for (size_t j = 1; j < data.size(); j++) {
		int key = data[j];
		int i = j - 1;
		while (i > 0 && data[i] > key) {
			data[ i + 1] = data[i];
			i--;
		}

		data[i + 1] = key;
	}

	return;
}

int main() {
	vector<int> data{1, 3, 2, 6, 5, 2, 10, 9, 11, 8, 7};
	insertionSort(data);

	for (size_t i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}

	cout << endl;
	
	return 0;
}
