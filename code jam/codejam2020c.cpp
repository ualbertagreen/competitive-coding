#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int n; cin >> n;
		vector< vector<int> > times;
		for (int i = 0; i < n; i++) {
			int s, e; cin >> s >> e;
			vector<int> temp;
			temp.push_back(s);
			temp.push_back(e);
			temp.push_back(i);
			times.push_back(temp);
		}

		sort(times.begin(), times.end());

		int C = 0, J = 0;
		bool possible = true;
		vector<char> output(n, 'C');
		for (int i = 0; i < times.size(); i++) {
			if (times[i][0] >= C) {
				C = times[i][1];
				output[times[i][2]] = 'C';
			}
			else if (times[i][0] >= J) {
				J = times[i][1];
				output[times[i][2]] = 'J';
			}
			else {
				possible = false;
				break;
			}
		}

		cout << "Case #" << cas + 1 << ": ";
		if (possible) { 
			for (int i = 0; i < output.size(); i++) {
				cout << output[i];
			}
			cout << endl; 
		}
		else { cout << "IMPOSSIBLE" << endl; }
	}
	return 0;
}