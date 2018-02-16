// created by Jiabin.Li

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> loadFile(const char filename[]) {
	vector<int> data;
	
	fstream fs(filename);
//	fs.open();
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

	return data;
}

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

int main(int argc, char* argv[]) {
	vector<int> data = loadFile(argv[1]);
	insertionSort(data);

	for (size_t i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}

	cout << endl;
	
	return 0;
}
