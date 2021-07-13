#include <iostream>

using namespace std;

int main() {
	long long A, L, c = 0;
	while (cin >> A >> L && A != -1 && L != -1) {
		cout << "Case " << ++c << ": A = " << A << ", limit = " << L << ", number of terms = ";
		int term = 1;
		while (A != 1) {
			if (A > L) {
				term--;
				break;
			}
			if (A % 2)
				A = A * 3 + 1;
			else
				A /= 2;
			term++;
		}
		cout << term << endl;
	}
	return 0;
}