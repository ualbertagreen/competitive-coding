#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		long long l, r;
		cin >> l >> r;
		long long i = 1;
		while (i <= l || i <= r) {
			if (r > l) {
				r -= i;
			}
			else {
				l -= i;
			}
			i++;
		}

		cout << "Case #" << cas + 1 << ": " << i-1 << " " << l << " " << r << endl;
	}
	return 0;
}