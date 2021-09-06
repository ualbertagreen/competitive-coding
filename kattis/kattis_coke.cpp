#include <iostream>
#include <algorithm>

using namespace std;

int memo[151][101][51];

int buy(int c, int c1, int c5, int c10) {
	if (c1 < 0 || c5 < 0 || c10 < 0)
		return 1500;

	if (c == 0)
		return 0;

	if (c5 == 0 && c10 == 0)
		return c * 8;

	if (memo[c][c5][c10] != -1)
		return memo[c][c5][c10];

	memo[c][c5][c10] = min(min(buy(c - 1, c1 + 2, c5, c10 - 1) + 1, buy(c - 1, c1 - 3, c5 + 1, c10 - 1) + 4),
						   min(buy(c - 1, c1 - 3, c5 - 1, c10) + 4, buy(c - 1, c1 + 2, c5 - 2, c10) + 2));

	return memo[c][c5][c10];
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int c, c1, c5, c10;
		cin >> c >> c1 >> c5 >> c10;

		for (int i = 0; i < 151; i++)
			for (int j = 0; j < 101; j++)
				for (int k = 0; k < 51; k++)
					memo[i][j][k] = -1;

		cout << buy(c, c1, c5, c10) << endl;
	}
	return 0;
}