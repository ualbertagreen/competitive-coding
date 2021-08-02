#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int n, q; cin >> n >> q;
	bitset<100000001> bits;
	bits.set(0);
	bits.set(1);
	for (int i = 2; i < bits.size(); i++) {
		if (!bits.test(i)) {
			for (int j = 2 * i; j < bits.size(); j += i) {
				bits.set(j);
			}
		}
	}

	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (!bits.test(i))
			count++;
	}
	cout << count << endl;

	for (int i = 0; i < q; i++) {
		int query; cin >> query;
		if (bits.test(query)) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}

	return 0;
}