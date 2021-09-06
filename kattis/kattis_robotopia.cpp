#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int l1, l2, a1, a2, at, lt;
		cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
		int count = 0;
		int ones = 0;
		int twos = 0;
		for (int i = 1; i <= lt / l1 && count <= 1; i++) {
			if ((lt - l1 * i) % l2 == 0 && (at - a1 * i) % a2 == 0 && (lt - l1 * i) / l2 == (at - a1 * i) / a2 && (at - a1 * i) / a2 >= 1) {
				ones = i;
				twos = (lt - l1 * i) / l2;
				count++;
			}
		}

		if (count == 1)
			cout << ones << " " << twos << endl;
		else
			cout << "?" << endl;
	}
	return 0;
}