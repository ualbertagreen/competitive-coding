#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int roff[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int coff[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main() {
	int r, c;
	while (cin >> r >> c && r && c) {
		vector<vector<char> > oil(r + 2, vector<char>(c + 2, '*'));

		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				cin >> oil[i][j];

		int out = 0;
		for (int i = 0; i < oil.size(); i++)
			for (int j = 0; j < oil[0].size(); j++) {
				queue<pair<int, int> > q;
				if (oil[i][j] == '@') {
					q.push(pair<int, int>(i, j));
					while (!q.empty()) {
						r = q.front().first;
						c = q.front().second;
						q.pop();
						if (oil[r][c] == '@') {
							oil[r][c] = '*';
							for (int k = 0; k < 8; k++) {
								q.push(pair<int, int>(r + roff[k], c + coff[k]));
							}
						}
					}
					out++;
				}
			}
		cout << out << endl;
	}
	return 0;
}