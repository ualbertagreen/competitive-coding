#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int c, d;
		cin >> c >> d;
		vector<int> cs(1,0);
		for (int i = 1; i < c; i++) {
			int temp; cin >> temp;
			cs.push_back(temp);
		}
		vector< vector< int > > adjl(c, vector<int>());

		map<pair<int, int>, int> edge;

		for (int i = 0; i < d; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			edge[pair<int, int>(a, b)] = i;
			edge[pair<int, int>(b, a)] = i;
			adjl[a].push_back(b);
			adjl[b].push_back(a);
		}

		vector<int> edgelength(d, 1000000);

		for (int i = 1; i < c; i++) {
			for (int j = 0; j < adjl[i].size(); j++) {
				if (cs[adjl[i][j]] > cs[i]) {
					//cout << i << " " << adjl[i][j] << " " << cs[adjl[i][j]] - cs[i] << " | " << edge[pair<int, int>(i, j)] << endl;
					edgelength[edge[pair<int, int>(i, adjl[i][j])]] = cs[adjl[i][j]] - cs[i];
				}
			}
		}

		cout << "Case #" << cas + 1 << ": ";
		for (int i = 0; i < d; i++) {
			cout << edgelength[i] << " ";
		}
		cout << endl;
	}
	return 0;
}