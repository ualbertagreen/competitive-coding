#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		char in;
		while (iss >> in) {
			int T = 0;
			if (in == '!') {
				cout << endl;
				continue;
			}
			while (in >= '0' && in <= '9') {
				T += in - '0';
				iss >> in;
			}
			for (int i = 0; i < T; i++)
				cout << (in == 'b' ? ' ' : in);
		}
		cout << endl;
	}
	return 0;
}