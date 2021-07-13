#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		long long n; cin >> n;
		long long N = n;
		cout << "Case #" << cas + 1 << ":" << endl;

		vector<int> pos(min(31LL, n), 0);
		
		for (int i = min(30LL, n-1); i >= 0; i--) {
			if ((n - i) >= (1LL << i)) {
				pos[i] = 1;
				n -= (1LL << i);
				//cerr << (n - 1) << " ," << (1LL << i) << endl;
			}
			else { n--; }
		}

		long long out = 0;
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] == 1) {
				out += 1 << i;
			}
			else out++;
		}

		for (; out < N; out++) {
			pos.push_back(0);
		}

		bool left = true; 
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] == 1) {
				if (left) {
					for (int j = 0; j <= i; j++) {
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
				else {
					for (int j = i; j >= 0; j--) {
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
				left = !left;
			}
			else
			{
				if (left) {
					cout << i + 1 << " 1" << endl;
				}
				else {
					cout << i + 1 << " " << i + 1 << endl;
				}
			}
		}

	}

	return 0;
}