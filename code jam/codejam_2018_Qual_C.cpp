#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int a; cin >> a;
		vector<vector<bool> > g(3, vector<bool>(3, false));
		cout << "10 2" << endl;
		int x, y;
		cin >> x >> y;
		int cx = x + 1, cy = y + 1;
		g[x - cx + 1][y - cy + 1] = true;
		while (a) {
			if (a <= 9) {
				while (x) {
					cout << cx << " " << cy << endl;
					cin >> x >> y;
					if (x == -1)
						return 0;
				}
				break;
			}

			while (!(g[0][0] && g[1][0] && g[2][0])) {
				cout << cx << " " << cy << endl;
				cin >> x >> y;
				if (x == -1)
					return 0;
				g[x - cx + 1][y - cy + 1] = true;
			}
			a -= 3;
			//cerr << a << endl;
			//for (int i = 0; i < 3; i++) {
			//	for (int j = 0; j < 3; j++) {
			//		cerr << g[i][j];
			//	}
			//	cerr << endl;
			//}

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 2; j++)
					g[i][j] = g[i][j + 1];
			cy++;
			g[0][2] = g[1][2] = g[2][2] = false;

			//for (int i = 0; i < 3; i++) {
			//	for (int j = 0; j < 3; j++) {
			//		cerr << g[i][j];
			//	}
			//	cerr << endl;
			//}
		}
	}
	return 0;
}