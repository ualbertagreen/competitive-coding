#include <iostream>

using namespace std;

long long dsum(long long n) {
	if (n == -1)
		return 0;

	long long ans = 0;
	long long first = n;
	long long second = 0;
	long long place = 1;
	while (first) {
		int digit = first % 10;
		first /= 10;

		for (int i = 1; i < digit; i++) {
			ans += i * (first + 1) * place;
		}
		ans += digit * (second + 1);
		for (int i = digit; i < 10; i++) {
			ans += i * first * place;
		}

		second += digit * place;
		place *= 10;
//		cout << first << " " << digit << " " << second << " " << place << " " << ans << endl;
	}
	return ans;
}

int main() {
	int n; cin >> n;
	while (n--) {
		long long a, b;
		cin >> a >> b;
		cout << dsum(b) - dsum(a - 1) << endl;
	}
	return 0;
}