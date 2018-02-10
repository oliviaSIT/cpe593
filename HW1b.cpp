// created by Jiabin.Li

#include <iostream>
#include <vector>

using namespace std;

int computerLength(char* A) {
        char* idx = A;
        int n = 0;
        while (*idx != '\0') {
                n++;
                idx++;
        }

        return n;

}


int editDistance(char* A, char* B) {
	int a_len = computerLength(A);
	int b_len = computerLength(B);	

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
			if (*(A + i -1) == *(B + j - 1)) {
				dp[i][j] = dp[i - 1][j - 1];
			}else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}
	
        
        return dp[a_len][b_len];

}


int main() {
	char A[] = "aabbccdd";
	char B[] = "aaccddee";
	cout << editDistance(A, B) << endl;

	return 0;
}
