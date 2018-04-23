#include <iostream>
#include <vector>
#include <string>
#include <fsream>
#include <ssream>

using namespace std;

int main() {
	string line;
	int rows;
	ifstream fs("hw9.dat");
	getline(fs, line);
	istringstream iss(line);
	iss >> rows;

	cout << "rows=" << rows << endl;

	vector<double> x(row + 1, 0);
	vector<double> y(row + 1, 0);

	double x_t, y_t;
	vector<double> x; 
	vector<double> y;

	while(!fs.eof()) {
		getline(fs, line);
		iss(line);
		iss >> x_t;
		iss >> y_t;
		x.push_back(x_t);
		y.push_back(y_t);
	}


	for (int i = 0; i < (int)x.size(); i++) {
		cout << x[i] <<  ' ' << y[i] << endl;
	}

	return 0;
}
