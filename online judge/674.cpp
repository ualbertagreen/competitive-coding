#include <iostream>

using namespace std;

int w[5][7500];

int ways(int c, int v) {
	if (c < 0)
		return 0;
	if (w[v][c])
		return w[v][c];

	if (v == 0) {
		w[v][c] = 1;
		return w[v][c];
	}
	if (v == 1) {
		w[v][c] = ways(c - 5, 0) + ways(c - 5, 1);
		return w[v][c];
	}
	if (v == 2) {
		w[v][c] = ways(c - 10, 0) + ways(c - 10, 1) + ways(c - 10, 2);
		return w[v][c];
	}
	if (v == 3) {
		w[v][c] = ways(c - 25, 0) + ways(c - 25, 1) + ways(c - 25, 2) + ways(c - 25, 3);
		return w[v][c];
	}
	if (v == 4) {
		w[v][c] = ways(c - 50, 0) + ways(c - 50, 1) + ways(c - 50, 2) + ways(c - 50, 3) + ways(c - 50, 4);
		return w[v][c];
	}
}

int main() {
	int c;
	w[0][0] = 1;
	while (cin >> c) {
		int out = 0;
		for (int i = 0; i < 5; i++)
			out += ways(c, i);
		cout << out << endl;
	}
	return 0;
}