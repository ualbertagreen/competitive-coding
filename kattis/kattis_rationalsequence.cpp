#include <iostream>

using namespace std;

int main() {
	int p; cin >> p;
	while (p--) {
		int K; cin >> K;

		long long a, b;
		char slash;
		cin >> a >> slash >> b;

		if (b == 1) {
			cout << K << " 1/" << a + 1 << endl;
			continue;
		}

		long long hieght = a / b;
		a = a % b;
		b = b - a;

		a = a + b;
		b = b + a * hieght;

		cout << K << " " << a << "/" << b << endl;
	}
	return 0;
}