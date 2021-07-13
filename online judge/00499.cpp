#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string in;
	while (getline(cin, in)) {
		istringstream iss(in);
		char c;
		map<char, int> freq;
		while (iss >> c)
			freq[c]++;

		int max = 0;
		vector<char> maxes;
		for (int i = 0; i < 26; i++) {
			if (freq['A' + i] == max)
				maxes.push_back('A' + i);
			if (freq['A' + i] > max) {
				maxes.assign(1, 'A' + i);
				max = freq['A' + i];
			}
		}
		for (int i = 0; i < 26; i++) {
			if (freq['a' + i] == max)
				maxes.push_back('a' + i);
			if (freq['a' + i] > max) {
				maxes.assign(1, 'a' + i);
				max = freq['a' + i];
			}
		}

		for (int i = 0; i < maxes.size(); i++)
			cout << maxes[i];
		cout << " " << max << endl;
	}
	return 0;
}