#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cin >> ws;
		char temp;

		cout << "CASE #" << cas + 1 << ": ";

		int p = 0;
		while (cin.get(temp) && temp != '\n' && temp != ' ') {
			int q = (int)(temp - '0');

			while (p < q) {
				cout << "(";
				p++;
			}
			while (p > q) {
				cout << ")";
				p--;
			}
			cout << p;
		}
		while (p > 0) {
			cout << ")";
			p--;
		}
		cout << endl;
	}
	return 0;
}