// created by Jiabin.Li

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string loadFile(const char filename[]) {
	ifstream f(filename);
	string contents;
	string temp;
	while (!f.eof()) {
		f >> temp;
		cout << temp;
		contents += temp;
	}
	return contents;
}

int LCS(const string& A, const string& B) {
	int len_a = A.size();
	int len_b = B.size();
	if (len_a == 0 || len_b == 0) {
		return 0;
	}
	
	vector<vector<int> > dp;
	for (int i = 0; i < len_a + 1; i++) {
		vector<int> one(len_b + 1, 0);
		dp.push_back(one);
	}

	for (int i = 0; i < len_a + 1; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j < len_b + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i < len_a + 1; i++) {
		for (int j = 1; j < len_b + 1; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[len_a][len_b];
}

int main(int argc, char* argv[]) {
	string a = loadFile(argv[1]);
	string b = loadFile(argv[2]);
	cout << a << " " << b << endl;
	cout << LCS(a, b) << endl;
	return 0;
}
