#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<pair<int, int>, int> maxp;

int sol(int n, int m) {
	if (m == 0)
		return 0;

	if (maxp[pair<int, int>(n, m)] != 0)
		return maxp[pair<int, int>(n, m)];

	if (m < n)
		return -1;
	
	int mx = -2;
	for (int i = 2; i <= m / n; i++) {
		mx = max(mx, sol(n*i, m - n*i));
	}
	if (mx != -1)
		maxp[pair<int, int>(n, m)] = mx + 1;
	else
		maxp[pair<int, int>(n, m)] = -1;

	return maxp[pair<int, int>(n, m)];
}

int main() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		int n; cin >> n;

		int mx = -1;
		for (int i = 3; i <= n; i++) {
			if (n % i == 0) {
				mx = max(mx, sol(i, n - i));
			}
		}
		cout << "Case #" << cas << ": " << mx + 1 << endl;
	}
	return 0;
}