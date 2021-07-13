#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		cout << ((N / 100) ? "" : " ") << ((N / 10) ? "" : " ") << N << "! =";
		map<int, int> prime;
		for (int i = 2; i <= N; i++) {
			int f = i;
			for (int j = 2; j <= i; j++)
				while (f % j == 0) {
					f /= j;
					prime[j]++;
				}
		}

		int c = 0;
		for (auto const &it : prime) {
			if (++c == 16) {
				cout << endl << "      ";
			}
			int t = it.second;
			cout << ((t / 100) ? "" : " ") << ((t / 10) ? "" : " ") << t;
		} cout << endl;
	}
	return 0;
}