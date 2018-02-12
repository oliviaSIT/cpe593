// created by Jiabin.Li

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string loadFile(const char filename[]) {
	vector<char> res;

        ifstream f(filename);
        char c;
        while(f.get(c)) {
                res.push_back(c);
        }
        f.close();
        return string(res.begin(), res.end());
}

int editDistance(const string A, const string B) {
	int a_len = A.length();
	int b_len = B.length();	

	if (a_len == 0)
		return b_len;

	if (b_len == 0)
		return a_len;
	
	vector<vector<int> > dp;
        for(int i = 0; i < a_len + 1; i++) {
            vector<int> one(b_len + 1, 0);
            dp.push_back(one);
        }
		

	for(int i = 0; i < a_len + 1; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j < b_len + 1; j++) {
            dp[0][j] = j;
        }


	for (int i = 1; i < a_len + 1; i++) {
		for (int j = 1; j < b_len + 1; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}
	
        
        return dp[a_len][b_len];

}

int main(int argc, char* argv[]) {
	string a = loadFile(argv[1]);
	string b = loadFile(argv[2]);
	cout << "file1:" << '\n' << a << endl;
	cout << "file2:" << '\n' << b << endl;
	cout << "the result is: " << editDistance(a, b) << endl;
	return 0;
}
