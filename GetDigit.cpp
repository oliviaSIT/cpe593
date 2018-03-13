#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getDigit(string s) {
	//string s{"2:3:14"};
	int x, y ,z;
	size_t sz, sz1;
	x = stoi(s, &sz);
	string s1 = s.substr(sz + 1);
	y = stoi(s1, &sz1);
	string s2 = s1.substr(sz1 + 1);
	z = stoi(s2, nullptr);
	vector<int> res;
	res.push_back(x);
	res.push_back(y);
	res.push_back(z);
	return res;
}

int main() {
	string s{"2:3:14"};
	vector<int> v = getDigit(s);
	cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
	return 0;
}
