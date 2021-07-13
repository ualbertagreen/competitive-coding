#include <iostream>
#include <string>

using namespace std;

string path(int x, int y) {
	if (x*x + y*y == 1) {
		if (x == 1) return "E";
		if (x == -1) return "W";
		if (y == 1) return "N";
		if (y == -1) return "S";
	}

	if (x*x % 2 == y*y % 2) return "IMPOSSIBLE";

	if (x % 2 != 0) {
		string E = path((x - 1) / 2, y / 2);
		if (E != "IMPOSSIBLE") return "E" + E;

		string W = path((x + 1) / 2, y / 2);
		if (W != "IMPOSSIBLE") return "W" + W;
	}

	if (y % 2 != 0) {
		string N = path(x / 2, (y - 1) / 2);
		if (N != "IMPOSSIBLE") return "N" + N;

		string S = path(x / 2, (y + 1) / 2);
		if (S != "IMPOSSIBLE") return "S" + S;
	}

	return "IMPOSSIBLE";
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int x, y;
		cin >> x >> y;

		cout << "Case #" << cas + 1 << ": " << path(x, y) << endl;
	}
	return 0;
}