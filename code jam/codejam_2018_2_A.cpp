#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		vector<int> balls;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			balls.push_back(temp);
		}
		if (balls[0] == 0 || balls[n - 1] == 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		//cerr << "mark" << endl;
		vector<int> left(n, 0);
		vector<int> right(n, 0);
		int count = 0;
		for (int i = 0; i < n; i++) {
			//cerr << count << " ";
			if (count > 0)
				left[i] = i - count;
			else
				left[i] = i;
			count++;
			count -= balls[i];
			//cerr << count << endl;
			if (count < 0)
				right[i] = i - count;
			else right[i] = i;
		}

		//for (int i = 0; i < n; i++)
			//cerr << left[i] << " " << right[i] << endl;

		int max = 0;
		for (int i = 0; i < n; i++) {
			max = ::max(::max(max, i - left[i]), right[i] - i);
		}
		cout << max + 1 << endl;

		vector<vector<char> > grid(max + 1, vector<char>(n, '.'));

		for (int i = 0; i < max; i++) {
			for (int j = 0; j < n; j++) {
				if (left[j] + i < j)
					grid[i][left[j] + i] = '\\';
				if (right[j] - i > j)
					grid[i][right[j] - i] = '/';
			}
		}

		for (int i = 0; i < max + 1; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}