#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	string line;
	int rows;
	ifstream fs("hw9.dat");
	istringstream iss;


//	vector<double> x(rows + 1, 0);
//	vector<double> y(rows + 1, 0);

//	double x_t, y_t;
	vector<double> x; 
	vector<double> y;

	int i = 0;
	iss.clear();	
	while(i <= rows + 1) {
		getline(fs, line);
		iss.clear();
		iss.str(line);
		if (i == 0) {
			iss >> rows;
			cout << "rows=" << rows << endl;
			i++;

			continue;
		}

		double x_t, y_t;
		iss >> x_t;
		iss >> y_t;
		x.push_back(x_t);
		//cout << x_t << endl;
		y.push_back(y_t);
		//cout << y_t << endl;

		i++;
	}

	fs.close();

	for (int i = 0; i < (int)x.size(); i++) {
		cout << x[i] <<  ' ' << y[i] << endl;
	}

	return 0;
}
