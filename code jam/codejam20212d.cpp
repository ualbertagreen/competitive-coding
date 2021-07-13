#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		vector< vector<char> > grid;
		vector< vector<char> > final_grid;
		int r, c, f, s;
		cin >> r >> c >> f >> s;
		for (int i = 0; i < r; i++) {
			grid.push_back(vector<char>());
			for (int j = 0; j < c; j++) {
				char temp; cin >> temp;
				grid[i].push_back(temp);
			}
		}

		for (int i = 0; i < r; i++) {
			final_grid.push_back(vector<char>());
			for (int j = 0; j < c; j++) {
				char temp; cin >> temp;
				final_grid[i].push_back(temp);
			}
		}

		priority_queue<pair<int, vector< vector<char> > > > q;
		q.push(pair<int, vector< vector<char> > >(0, grid));
		int ans = -1;

		while (!q.empty()) {
			int cost = q.top().first;
			vector< vector< char > > cur = q.top().second;
			q.pop();

			if (cur == final_grid) {
				ans = cost;
				break;

			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					vector< vector< char > > temp = cur;
					if (temp[i][j] == 'M')
						temp[i][j] = 'G';
					else
						temp[i][j] = 'M';
					q.push(pair<int, vector< vector<char> > >(cost + f, temp));
				}
			}

			for (int i = 1; i < r; i++) {
				for (int j = 0; j < c; j++) {
					vector< vector< char > > temp = cur;
					char tp = temp[i][j];
					temp[i][j] = temp[i - 1][j];
					temp[i - 1][j] = tp;
					q.push(pair<int, vector< vector<char> > >(cost + s, temp));
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 1; j < c; j++) {
					vector< vector< char > > temp = cur;
					char tp = temp[i][j];
					temp[i][j] = temp[i][j-1];
					temp[i][j-1] = tp;
					q.push(pair<int, vector< vector<char> > >(cost + s, temp));
				}
			}
		}

		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}