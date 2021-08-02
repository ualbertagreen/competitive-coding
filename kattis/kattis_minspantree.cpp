#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int a, vector<int> &UF) {
	if (UF[a] == a)
		return a;
	else {
		UF[a] = find(UF[a], UF);
		return UF[a];
	}
}

bool merge(int a, int b, vector<int> &UF) {
	int n = find(a, UF);
	int m = find(b, UF);
	if (n == m)
		return false;
	UF[n] = m;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0) {
		vector<int> UF;
		for (int i = 0; i < n; i++) {
			UF.push_back(i);
		}

		vector<pair<int, pair<int, int> > > E;
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			E.push_back(pair<int, pair<int, int> >(w, pair<int, int>(u, v)));
		}

		sort(E.begin(), E.end());

		int cost = 0;
		vector<pair<int, int> > out;
		for (int i = 0; i < E.size(); i++) {
			if (merge(E[i].second.first, E[i].second.second, UF)) {
				cost += E[i].first;
				out.push_back(pair<int, int>(min(E[i].second.first, E[i].second.second), max(E[i].second.first, E[i].second.second)));
			}
		}
		sort(out.begin(), out.end());

		bool tree = true;
		for (int i = 1; i < UF.size(); i++) {
			if (find(i - 1, UF) != find(i, UF))
				tree = false;
		}

		if (tree) {
			cout << cost << endl;
			for (int i = 0; i < out.size(); i++) {
				cout << out[i].first << " " << out[i].second << endl;
			}
		}
		else {
			cout << "Impossible" << endl;
		}
		cin >> n >> m;
	}

	return 0;
}