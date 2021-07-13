#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int k, q;
		cin >> k >> q;
		vector< vector< pair<int, int> > > adjl;
		stack<int> lbracket;
		char read;
		for (int i = 0; i < k; i++) {
			cin >> read;
			adjl.push_back(vector<pair<int, int>>());
			adjl[i].push_back(pair<int, int>(i - 1, -1));
			adjl[i].push_back(pair<int, int>(i + 1, -1));
			if (read == '(') {
				lbracket.push(i);
			}
			else {
				adjl[i].push_back(pair<int, int>(lbracket.top(), -1));
				adjl[lbracket.top()].push_back(pair<int, int>(i, -1));
				lbracket.pop();
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < k; j++) {
				int temp; cin >> temp;
				adjl[j][i].second = temp;
			}
		}

		vector<int> s;
		for (int i = 0; i < q; i++) {
			int temp; cin >> temp;
			s.push_back(temp - 1);
		}
		vector<int> e;
		for (int i = 0; i < q; i++) {
			int temp; cin >> temp;
			e.push_back(temp - 1);
		}

		/*
		for (int i = 0; i < k; i++) {
			cout << adjl[i][2].first << endl;
		}
		cin >> t;
		*/

		long long sum = 0;
		for (int i = 0; i < q; i++) {
			//cout << "mark" << endl;
			priority_queue<pair<long long, int>> dijk;
			dijk.push(pair<long long, int>(0, s[i]));

			vector<bool> visited(k, false);

			while (!dijk.empty()) {
				if (dijk.top().second == e[i]) {
					sum += dijk.top().first * -1;
					break;
				}
				if (!visited[dijk.top().second]) {
					//cout << dijk.top().second << " ";
					//cout << dijk.top().first << endl;
					int pos = dijk.top().second;
					long long dist = dijk.top().first;
					visited[pos] = true;

					for (int j = 0; j < 3; j++) {
						if (adjl[pos][j].first >= 0 && adjl[pos][j].first < k) {
							dijk.push(pair<long long, int>(dist + adjl[pos][j].second * -1, adjl[pos][j].first));
							//cout << "insert: " << pos <<" "<< dist << " " << adjl[pos][j].second << " " << adjl[pos][j].first << endl;
						}
					}
				}
				dijk.pop();
			}
		}
		cout << "Case #" << cas + 1 << ": " << sum << endl;
	}
	return 0;
}