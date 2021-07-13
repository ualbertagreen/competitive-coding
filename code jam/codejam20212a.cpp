#include <iostream>

using namespace std;

int main() {
	int t, n;
	cin >> t >> n;
	for (; t > 0; t--) {
		int temp = 1;
		for (int i = 1; i < n; i++) {
			cout << "M " << i << " " << n << endl;
			int m; cin >> m;
			if (m != i) {
				cout << "S " << i << " " << m << endl;
				cin >> temp;
				if (temp != 1) break;
			}
		}
		cout << "D" << endl;
		cin >> temp;
		if (temp != 1) break;
	}
	return 0;
}