#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		double D, N; cin >> D >> N;
		double max = 0;
		while (N--) {
			double K, S; cin >> K >> S;
			max = ::max((D - K) / S, max);
		}
		cout << fixed << setprecision(6) << D / max << endl;
	}
	return 0;
}