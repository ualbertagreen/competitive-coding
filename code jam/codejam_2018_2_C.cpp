#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &adjl, vector<bool> &vis, vector<bool> &select, int node) {
	if (vis[node])
		return;
	vis[node] = true;
	vector<int> child;
	for (int i = 0; i < adjl[node].size(); i++) {
		if (!vis[adjl[node][i]]) {
			child.push_back(adjl[node][i]);
			dfs(adjl, vis, select, adjl[node][i]);
		}
	}

	if (child.empty())
		return;

	for (int i = 0; i < adjl[node].size(); i++) {
		if (!select[adjl[node][i]]) {
			select[node] = true;
			return;
		}
	}
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		int n; cin >> n;
		vector<vector<int> > dancers(n, vector<int>(n, 0));
		vector<vector<int> > adjl(n*n, vector<int>());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp; cin >> temp;
				dancers[i][j] = temp;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (k != i)
						if (dancers[i][j] == dancers[k][j])
							adjl[n*i + j].push_back(n*k + j);
					if (k != j)
						if (dancers[i][j] == dancers[i][k])
							adjl[n*i + j].push_back(n*i + k);
				}
			}
		}

		vector<bool> vis(n*n, false);
		vector<bool> select(n*n, false);

		int out = 16;

		for (int j = 0; j < 65536; j++)
		{
			vis = vector<bool>(n*n, false);
			select = vector<bool>(n*n, false);
			for (int i = 0; i < n * n; i++) {
				if (j & (1 << i))
					select[i] = true;
			}

			for (int i = 0; i < vis.size(); i++) {
				if (!vis[i])
					dfs(adjl, vis, select, i);
			}
			int tout = 0;
			for (int i = 0; i < n * n; i++) {
				if (select[i])
				{
					tout++;
					if (!(j & (1 << i)))
						tout += 20;
				}
			}

			out = min(out, tout);
		}
		/*
		int out = 0;
		for (int i = 0; i < select.size(); i++) {
			if (select[i]) out++;
			//for (int j = 0; j < adjl[i].size(); j++)
			//	cerr << adjl[i][j] << " ";
			//cerr << endl;
			cerr << ((select[i]) ? "TRUE" : "FALSE") << endl;
		}
		*/

		cout << out << endl;
	}
	return 0;
}