#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int n, d;
		cin >> n >> d;

		vector<long long> a;
		for (int i = 0; i < n; i++) {
			long long temp;
			cin >> temp;
			a.push_back(temp);
		}

		sort(a.begin(), a.end());
		
		int min_cut = d - 1;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < i; j++) {
				long long g = gcd(a[i], a[j]);

				int cut = 0;
				int dd = 0;
				for (int k = 0; dd < d && k < a.size(); k++) {
					if (a[k] % g == 0LL) {
						cut += min(a[k] / g - 1, (long long)(d - dd));
						dd += a[k] / g;
					}
				}
				cut += max(d - dd, 0);

				min_cut = min(min_cut, cut);
			}
		}

		cout << "Case #" << cas + 1 << ": " << min_cut << endl;
	}
	return 0;
}