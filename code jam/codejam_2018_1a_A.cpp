#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(vector< vector<int> > &waffle, int R, int C, int h, int v) {
	if (waffle[R][C] % ((h + 1)*(v + 1)) != 0)
		return "IMPOSSIBLE";

	vector<int> hc(1,0);
	vector<int> vc(1,0);

	for (int i = 0, chips = 0; i < R; i++) {
		chips += waffle[i][C];
		if (chips == waffle[R][C] / (h + 1)) {
			chips = 0;
			hc.push_back(i + 1);
		}
		else if (chips > waffle[R][C] / (h + 1))
			return "IMPOSSIBLE";
		cerr << chips << endl;
	}

	for (int i = 0, chips = 0; i < C; i++) {
		chips += waffle[R][i];
		if (chips == waffle[R][C] / (v + 1)) {
			chips = 0;
			vc.push_back(i + 1);
		}
		else if (chips > waffle[R][C] / (v + 1))
			return "IMPOSSIBLE";
		cerr << chips << endl;
	}

	for (int i = 1; i < hc.size(); i++) {
		for (int j = 1; j < vc.size(); j++) {
			int chips = 0;
			for (int k = hc[i - 1]; k < hc[i]; k++) {
				for (int l = vc[j - 1]; l < vc[j]; l++) {
					chips += waffle[k][l];
				}
			}
			if (chips != waffle[R][C] / ((h + 1)*(v + 1)))
				return "IMPOSSIBLE";
		}
	}

	cerr << endl;
	return "POSSIBLE";
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		int R, C, h, v;
		cin >> R >> C >> h >> v;
		vector< vector<int> > waffle(R + 1, vector<int>(C + 1, 0));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char in; cin >> in;
				waffle[i][j] = (in == '@') ? 1 : 0;
				waffle[i][C] += waffle[i][j];
				waffle[R][j] += waffle[i][j];
				waffle[R][C] += waffle[i][j];
			}
		}

		cout << solve(waffle, R, C, h, v) << endl;
	}
	return 0;
}