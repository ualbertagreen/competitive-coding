#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		vector<int> A;
		for (int i = 0; i < m; i++) {
			int temp; cin >> temp;
			A.push_back(temp);
		}

		int max = 0;
		int behind = -1;
		bool has_min = false;

		int current = 0;
		for (int forward = 0; forward < m; forward++) {
			if (A[forward] < n) {
				current = 0;
				behind = forward;
				has_min = false;
				continue;
			}
			if (A[forward] == n) {
				if (has_min) {
					do {
						behind++;
						current -= A[behind];
					} while (A[behind] > n);
				}
				has_min = true;
			}

			current += A[forward];
			if (has_min)
				max = ::max(max, current);
//			cout << current << " " << max << endl;
		}

		cout << max << endl;
	}
	return 0;
}