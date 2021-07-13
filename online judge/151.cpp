#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		int out = 0;
		bool found = false;
		for (int i = 1;; i++) {
			vector<bool> regions(N, true);
			int m = N;
			int c = 0;
			int j = 0;
			while (m--) {
				while (c--) {
					j++;
					if (j == N)
						j -= N;
					while (!regions[j]) {
						j++;
						if (j == N)
							j -= N;
					}
				}
				if (m == 0 && j == 12) {
					out = i;
					found = true;
					break;
				}
				regions[j] = false;
				c = i;
			}
			if (found)
				break;
		}
		cout << out << endl;
	}
	return 0;
}