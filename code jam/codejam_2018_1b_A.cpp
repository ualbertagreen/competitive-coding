#include <iostream>
#include <queue>

using namespace std;

void solve_q(priority_queue<pair<double, int > > &q, int &n, int &num) {
	for (int prev = num; num < n; prev = num) {
		if ((int)((double)(q.top().second + 1) / n * 100 + 0.5) - (int)((double)q.top().second / n * 100 + 0.5) > (int)(1.0 / n * 100 + 0.5)) {
			int temp = q.top().second + 1;
			q.pop();
			q.push(pair<double, int>(temp * 100.0 / n - (int)(temp * 100.0 / n + 0.5), temp));
			num++;
		}
		else if ((int)((double)(q.top().second + 1) / n * 100 + 0.5) - (int)((double)q.top().second / n * 100 + 0.5) == (int)(1.0 / n * 100 + 0.5)) {
			double percent_group = (q.top().second + 1) * 100.0 / n - (int)((q.top().second + 1) * 100.0 / n + 0.5);
			double percent_solo = 100.0 / n - (int)(100.0 / n + 0.5);
			if (percent_group > percent_solo) {
				int temp = q.top().second + 1;
				q.pop();
				q.push(pair<double, int>(temp * 100.0 / n - (int)(temp * 100.0 / n + 0.5), temp));
			}
			else {
				q.push(pair<double, int>(100.0 / n - (int)(100.0 / n + 0.5), 1));
			}
			num++;
		}
		if (prev == num)
			return;
		//cerr << n << " " << num << endl;
	}
	return;
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		int l, n;
		cin >> n >> l;
		int num = 0;
		priority_queue<pair<double, int> > q;
		while (l--) {
			int temp; cin >> temp; num += temp;
			q.push(pair<double, int>( temp * 100.0 / n  - (int) (temp * 100.0 / n + 0.5), temp));
		}

		solve_q(q, n, num);

		int ans = 0;
		while (!q.empty()) {
			ans += (int)((double)(q.top().second) / n * 100 + 0.5);
			//cerr << q.top().second << " " << ans << endl;
			q.pop();
		}
		//cerr << ((n - 1) / 200 + 1) << endl;

		ans += (n - num) / ((n - 1) / 200 + 1) * (int)((double)((n - 1) / 200 + 1) / n * 100 + 0.5);
		cout << ans << endl;
	}
}