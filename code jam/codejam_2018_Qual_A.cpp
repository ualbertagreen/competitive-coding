#include <iostream>
#include <string>

using namespace std;

long long damage(string s) {
	long long hit = 1;
	long long out = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C')
			hit *= 2;
		else
			out += hit;
	}
	return out;
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		long long d; cin >> d;
		string p; cin >> p;
		int out = 0;
		for (; damage(p) > d; out++) {
			for (int i = p.length() - 1; i > 0; i--) {
				if (p[i] == 'S' && p[i - 1] == 'C') {
					p[i] = 'C';
					p[i - 1] = 'S';
					break;
				}
			}
			if (out > 1000)
				break;
		}
		if (out > 1000)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << out << endl;
	}
	cin >> t;
	return 0;
}