#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int t; cin >> t;
	long double pi = 3.14159265358979323L;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": " << endl;
		long double a; cin >> a;

		long double theta = acos(a / sqrt(2));
		cout << fixed << setprecision(10);
		cout << cos(pi / 4 - theta) * 0.5 << " " << sin(pi / 4 - theta) * 0.5 << " 0" << endl;
		cout << -cos(pi / 4 + theta) * 0.5 << " " << sin(pi / 4 + theta) * 0.5 << " 0" << endl;
		cout << "0 0 0.5" << endl;
	}
	return 0;
}