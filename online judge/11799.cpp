#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		vector<int> v;
		while (N--) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		cout << "Case " << i + 1 << ": " << *max_element(v.begin(), v.end()) << endl;
	}
	return 0;
}