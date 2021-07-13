#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		cout << "Case #" << cas + 1 << ": ";
		vector<int> jug;
		int a, b;
		cin >> a >> b;
		for (int i = 0; b > i; i++) {
			jug.push_back(0);
			for (int j = 0; a > j; j++) {
				b -= i;
				a -= j;
				jug[i]++;
			}
		}
	return 0;
}