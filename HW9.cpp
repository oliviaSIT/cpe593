// created by Jiabin Li

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TridiagonalMatrix {
public:
	int rows;
	vector<double> m;

	TridiagonalMatrix(int rows): rows(rows) {
		size_t size = rows * 3 - 2;
		m.reserve(size);
		m.push_back(2);
		m.push_back(1);
		for (int i = 2; i < (int)size - 2; i++) {
			if (i % 3 == 0)
				m.push_back(4);
			else m.push_back(1);
		}

		m.push_back(1);
		m.push_back(2);
	}

	double& operator()(int i, int j) {
		return m[i * 2 + j];
	}

};

int main() {
	TridiagonalMatrix m(5);
	cout << m(0, 0) << ' ' << m(0, 1) << ' ';

	for (int i = 1; i < 4; i++)
		cout << m(i, i - 1) << ' ' << m(i, i) << ' ' << m(i, i + 1) << ' ';

	cout << m(4, 3) << ' ' << m(4, 4) << endl;
	return 0;  	

}
