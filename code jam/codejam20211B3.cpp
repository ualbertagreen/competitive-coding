#include <iostream>

using namespace std;

int solve(int block, int ones, int twos, int threes, int n) {
	if (threes == ones) return 3;
	if (block < 7 && threes <= n) return 3;
	if (twos == ones) return 2;
	if (block < 9 && twos <= n) return 2;
	return 1;
}

int main() {
	int t, n, b;
	long long p; 
	cin >> t >> n >> b >> p;

	for (int cas = 0; cas < t; cas++) {
		int ones = 1, twos = 1, threes = 1, tally = 0;

		for (int i = 0; i < n * b; i++) {
			int block; cin >> block;
			int sol = solve(block, ones, twos, threes, n);
//			cout << sol << " ";
			if (sol == 1) {
				cout << ones << endl;
				ones++;
			}
			else if (sol == 2) {
				cout << twos << endl;
				twos++;
			}
			else {
				cout << threes << endl;
				tally++;
				if (tally == b - 2) {
					tally = 0;
					threes++;
				}
			}
			
		}
	}
	int ans; cin >> ans;
	return 0;
}