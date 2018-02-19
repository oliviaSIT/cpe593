//created by Jiabin.Li

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

vector<int> loadFile(const char filename[]) {
	vector<int> data;
	
	fstream fs(filename);
	
	int n;
	int line = 0;
        while(!fs.eof()) {
		fs >> n;
		if (line == 0) {
			line++;			
		} else {
                	data.push_back(n);
		}
        }
        fs.close();
	data.pop_back();

	return data;
}

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


int main(int argc, char* argv[]) {
	vector<int> data = loadFile(argv[1]);
	quickSort(data, 0, (int)data.size() - 1);

	for (size_t i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}

	cout << endl;
	
	return 0;
}
