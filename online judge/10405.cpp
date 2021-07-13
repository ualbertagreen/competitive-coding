#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< vector<int> > match;

int lcs(string a, string b) {
	if (match[a.length()][b.length()] != -1)
		return match[a.length()][b.length()];
	if (a.length() == 0 || b.length() == 0)
		return 0;

	string aSub = a.substr(0, a.length() - 1);
	string bSub = b.substr(0, b.length() - 1);

	if (*--a.end() == *--b.end()) {
		match[a.length()][b.length()] = lcs(aSub, bSub) + 1;
	}
	else {
		int x = lcs(a, bSub);
		int y = lcs(aSub, b);
		match[a.length()][b.length()] = (x > y) ? x : y;
	}

	//cerr << a.length() << " " << b.length() << endl;
	return match[a.length()][b.length()];
}

int main() {
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		match.assign(str1.length() + 1, vector<int>(str2.length() + 1, -1));
		cout << lcs(str1, str2) << endl;
	}
	return 0;
}