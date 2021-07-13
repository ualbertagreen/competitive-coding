#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		bool cur = false;
		int row = 0;
		int col = 0;
		vector<int> Col(N, 0);
		for (int i = 0; i < N; i++) {
			int r = 0;
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				if (temp) {
					r++;
					Col[j]++;
				}
			}
			if (r % 2 == 1) {
				if (!row)
					row = i;
				else cur = true;
			}
		}

		for (int i = 0; i < N; i++) {
			if (Col[i] % 2 == 1) {
				if (!col)
					col = i;
				else cur = true;
			}
		}

		cout << (cur ? "Corrupt" : (row ? ("Change bit (" + to_string(row + 1) + "," + to_string(col + 1) + ")") : "OK")) << endl;
	}
	return 0;
}