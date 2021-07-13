#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		int n; cin >> n;
		double p; cin >> p;
		double sp1 = 0, lp = 0;
		double w, l;
		for (int i = 0; i < n; i++) {
			cin >> w >> l;
			sp1 += 2 * (w + l);
			lp += 2 * (w + l) + 2 * sqrt(w*w + l*l);
		}
		double sp2 = sp1 + 2 * min(w, l);

		double sp3 = sp1 + 2 * sqrt(w*w + l*l);
		double sp4 = sp2 + 2 * min(w, l);

		double sp5 = sp3 + 2 * sqrt(w*w + l*l);
		double sp6 = sp4 + 2 * min(w, l);

		cout << fixed << setprecision(7);
		if (p > lp)
			cout << lp << endl;
		else if (p < sp2)
			cout << ((abs(p - sp1) <= abs(p - sp2)) ? sp1 : sp2) << endl;
		else if (p > sp3 && p < sp4)
			cout << ((abs(p - sp3) <= abs(p - sp4)) ? sp3 : sp4) << endl;
		else if (p > sp5 && p < sp6)
			cout << ((abs(p - sp5) <= abs(p - sp6)) ? sp5 : sp6) << endl;
		else
			cout << p << endl;
	}
	return 0;
}