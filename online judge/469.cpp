#include <iostream>
#include <array>
#include <queue>

using namespace std;

int rowset[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int colset[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int main() {
	int t; cin >> t >> ws;
	while (t--) {
		array<array<char, 101>, 101> lake;
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				lake[i][j] = ' ';
		int maxrow = 0, maxcol = 0;
		while (cin.peek() == 'L' || cin.peek() == 'W') {
			maxrow++;
			maxcol = 0;
			while (cin.peek() == 'L' || cin.peek() == 'W') {
				cin >> lake[maxrow][++maxcol];
			}
			cin >> ws;
		}
		/*
		for (int i = 1; i <= maxrow; i++) {
			for (int j = 1; j <= maxcol; j++) {
				cout << lake[i][j];
			}
			cout << endl;
		}
		*/
		int r, c;
		while (cin.peek() >= '0' && cin.peek() <= '9') {
			array<array<char, 101>, 101> copy = lake;
			cin >> r >> c;
			int count = 0;
			queue<pair<int, int>> q;
			q.push(pair<int, int>(r, c));
			while (!q.empty()) {
				pair<int, int> temp = q.front();
				q.pop();

				if (copy[temp.first][temp.second] == 'W') {
					count++;
					copy[temp.first][temp.second] = 'w';
					for (int i = 0; i < 8; i++) {
						q.push(pair<int, int>(temp.first + rowset[i], temp.second + colset[i]));
					}
				}
			}
			cout << count << endl;
			cin >> ws;
		}
		if (t)
			cout << endl;
	}
	return 0;
}