#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000001;
int f[MAXN];
int pf[MAXN];

int numf(int n, int f) {
	int ans = 0;
	while (n % f == 0) {
		ans++;
		n /= f;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < MAXN; i++) f[i] = 1;
	
	for (int i = 2; i < MAXN; i++) {
		if (pf[i] == 0) {
			for (int j = i * 2; j < MAXN; j += i) {
				pf[j]++;
				f[j] *= (1 + numf(j, i));
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int ger;
		cin >> ger;

		cout << f[ger] - pf[ger] << '\n';
	}

	return 0;
}