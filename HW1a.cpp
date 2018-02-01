#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int lcs(const string& A, const string& B) {
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

int LCS(const string& file1, const string& file2) {
	int n = 0;
	string s1, s2;
//	vector<string> vA, VB;
	ifstream f1(file1);
	ifstream f2(file2);
	while(!f1.eof() and !f2.eof()){
		getline(f1, s1);
		getline(f2, s2);
		n = n + lcs(s1, s2);
	}

	return n;
}


int main() {
	int n = 0;
	n = LCS("file1.txt", "file1.txt");
	cout << n << endl;
	return 0;
}
