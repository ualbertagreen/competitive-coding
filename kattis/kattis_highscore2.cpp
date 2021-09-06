#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	while (n--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;

		vector<long long> s = { a, b, c };
		sort(s.begin(), s.end());

		long long max = (s[2] + d) * (s[2] + d) + s[1] * s[1] + s[0] * s[0] + 7 * s[0];
//		cout << max << endl;

		if (d >= s[1] - s[0]) {
			d -= s[1] - s[0];
			s[0] = s[1];
		}
		else {
			s[0] += d;
			d = 0;
		}

		if (d) {
			if (d >= 2 * (s[2] - s[1])) {
				d -= 2 * (s[2] - s[1]);
				s[0] = s[2];
				s[1] = s[2];
			}
			else {
				s[1] += d / 2;
				s[0] += d / 2;
				d = d % 2;
			}
		}

		s[0] += d / 3;
		s[1] += d / 3;
		s[2] += d / 3;
		d = d % 3;
		s[2] += d;

		cout << ::max(max, s[0] * s[0] + s[1] * s[1] + s[2] * s[2] + 7 * min(s[0], min(s[1], s[2]))) << endl;
	}
	return 0;
}