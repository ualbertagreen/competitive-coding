#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		string ss; cin >> ss;
		int s = 0;
		for (int i = 0; i < ss.length(); i++) {
			s = s * 2 + (int)ss[i] - 48;
		}

		string se; cin >> se;
		int e = 0;
		for (int i = 0; i < se.length(); i++) {
			e = e * 2 + (int)se[i] - 48;
		}

		queue<pair<int, int> > q;

		q.push(pair<int, int>(s, 0));

		int ans = -1;
		while (q.front().second < 20) {
			pair<int, int> cur = q.front();
			q.pop();

//			cout << cur.first << " " << cur.second << endl;

			if (cur.first == e) {
				ans = cur.second;
				break;
			}
			else {
				int temp = cur.first << 1;
				q.push(pair<int, int>(temp, cur.second + 1));

				temp = 1;
				for (int i = cur.first; i > 1; i /= 2) {
					temp = temp * 2 + 1;
				}
				temp = temp ^ cur.first;
				q.push(pair<int, int>(temp, cur.second + 1));
			}
		}

		if (ans == -1) {
			cout << "Case #" << cas << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case #" << cas << ": " << ans << endl;
		}
	}
	return 0;
}