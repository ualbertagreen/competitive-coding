#include <iostream>
#include <string>


using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		string y; cin >> y;
		int numy = 0;
		for (int i = 0; i < y.length(); i++) {
			numy = numy * 10 + (int)y[i] - 48;
		}

		int ans = -1;
		for (int i = numy + 1; i <= 1234567; i++) {
			int first = i;
			while (first > 9) first /= 10;
			string check = to_string(first);
			while (check.length() < to_string(i).length()) {
				first++;
				check += to_string(first);
				//				cout << i << " " << check << endl;
			}
			if (to_string(first) != to_string(i)) {
				if (check == to_string(i)) {
					ans = i;
					break;
				}
			}

			first = i;
			while (first > 99) first /= 10;
			check = to_string(first);
			while (check.length() < to_string(i).length()) {
				first++;
				check += to_string(first);
			}
			if (to_string(first) != to_string(i)) {
				if (check == to_string(i)) {
					ans = i;
					break;
				}
			}

			first = i;
			while (first > 999) first /= 10;
			check = to_string(first);
			while (check.length() < to_string(i).length()) {
				first++;
				check += to_string(first);
			}
			if (to_string(first) != to_string(i)) {
				if (check == to_string(i)) {
					ans = i;
					break;
				}
			}

		}

		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}