#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(long long r, long long b, vector<long long> m, vector<long long> s, vector<long long> p) {
	long long lb = 0;
	long long rb = 9e18;

	while (rb - lb > 1) {
		long long mid = (lb + rb) / 2;
		vector<long long> bits;
		for (int i = 0; i < s.size(); i++) {
			bits.push_back(-1 * min((mid - p[i]) / s[i], m[i]));
		}
		sort(bits.begin(), bits.end());
		long long  tot = 0;
		for (int i = 0; i < r; i++) {
			tot += max(-1 * bits[i], 0LL);
		}

		if (tot >= b)
			rb = mid;
		else lb = mid;
		//cerr << lb << " " << rb << endl;
	}
	return rb;
}

int main() {
	int t;
	cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		long long r, b, c;
		cin >> r >> b >> c;
		vector<long long> m, s, p;

		for (int i = 0; i < c; i++) {
			long long M, S, P;
			cin >> M >> S >> P;
			m.push_back(M);
			s.push_back(S);
			p.push_back(P);
		}

		cout << solve(r, b, m, s, p) << endl;
	}
	return 0;
}