// created by Jiabin Li

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

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

	friend vector<double> solve(TridiagonalMatrix& m, vector<double>& B) {
		vector<double> x(m.rows);
		for (int i = 0; i < m.rows - 1; i++) {
			double s = -1 * m(i + 1, i) / m(i, i);
			m(i + 1, i) = 0;
			m(i + 1, i + 1) += s * m(i, i + 1);
			B[i + 1] += s * B[i];
		}

		for (int i = m.rows - 1; i > 0; i--) {
			x[i] = B[i] / m(i, i);
			B[i - 1] -= x[i] * m(i - 1, i);
			m(i - 1, i) = 0;
		}

		x[0] = B[0] / m(0, 0);
		
		return x;
	}
};

int main() {
	string line;
	int rows;
	ifstream fs("hw9.dat");
	istringstream iss;

	vector<double> x;
	vector<double> y;

	int i = 0;
	while (i <= rows + 1) {
		getline(fs, line);
		iss.clear();
		iss.str(line);
		if (i == 0) {
			iss >> rows;
			x.reserve(rows + 1);
			y.reserve(rows + 1);
			i++;
			continue;
		}

		double x_t, y_t;
		iss >> x_t;
		iss >> y_t;
		x.push_back(x_t);
		y.push_back(y_t);
		i++;
	}
	fs.close();

	TridiagonalMatrix m(rows);

	vector<double> a = y;
	a.pop_back();

	vector<double> t(a.size(), 0);
	for (int i = 0; i < (int)a.size(); i++) 
		t[i] = 3 * (y[i + 1] - y[i]);

	vector<double> D = solve(m, t);

	vector<double> b = D;
	b.pop_back();	

	vector<double> c(a.size(), 0);
	vector<double> d(a.size(), 0);
	for (int i = 0; i < (int)a.size(); i++) {
		c[i] = 3 * (y[i + 1] - y[i]) - 2 * D[i] - D[i + 1];
		d[i] = 2 * (y[i] - y[i + 1]) + D[i] + D[i + 1];
	}

	for (int i = 0 ; i < rows; i++) {
		for (int j = 0; j < 10; j++) {
			double z = j * 0.1;
			cout << i << ' ' << j * 0.1 << ' ' << x[i] + (x[i + 1] - x[i]) / 10 * j << ' ' << d[i] * z * z * z + c[i] * z * z + b[i] * z + a[i] << endl;
		}
	}

	return 0;  
}
