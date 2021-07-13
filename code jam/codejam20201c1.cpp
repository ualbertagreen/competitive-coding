#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int x, y;
		cin >> x >> y;
		string path;
		cin >> path;

		int steps = -1;
		for (int i = 0; i < path.length(); i++) {
			char s = path[i];
			if (s == 'S') y--;
			if (s == 'N') y++;
			if (s == 'W') x--;
			if (s == 'E') x++;

			//cout << x << ", " << y << endl;
			if (abs(x) + abs(y) <= i + 1) {
				steps = i + 1;
				break;
			}
		}

		cout << "Case #" << cas + 1 << ": ";
		if (steps == -1) cout << "IMPOSSIBLE";
		else cout << steps;
		cout << endl;
	}
	return 0;
}