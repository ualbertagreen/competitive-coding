#include <iostream>

using namespace std;

int gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

pair<long long, long long> egcd(long long a, long long b) {
	long long x = 0;
	long long y = 1;
	long long u = 1;
	long long v = 0;
	while (a != 0) {
		long long q = b / a;
		long long r = b % a;
		long long m = x - q * u;
		long long n = y - v * q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}

	return pair<long long, long long>(x, y);
}

int main() {
	int t; cin >> t;
	while (t--) {
		long long R, S, Q;
		cin >> R >> S >> Q;

		long long d = gcd(R, S);
		pair<long long, long long> AB = egcd(R, S);

		long long A = AB.first * (Q / d);
		long long B = AB.second * (Q / d);


		A = A % abs(S / d);
		B = (Q - (A * R)) / S;

		while (A <= 0 || B <= 0) {
			A += abs(S / d);
			B = (Q - (A * R)) / S;
		}

		cout << A << " " << B << endl;
	}
	return 0;
}