#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int n, d;
		cin >> n >> d;

		vector<long long> a;
		for (int i = 0; i < n; i++) {
			long long temp;
			cin >> temp;
			a.push_back(temp);
		}

		sort(a.begin(), a.end());

		cout << "Case #" << cas + 1 << ": ";

		if (d == 2) { //cout << "d = 2" << endl;
			int out = 1;
			for (int i = 0; i < a.size() - 1; i++) {
				if (a[i] == a[i + 1]) {
					out = 0;
					break;
				}
			}
			cout << out << endl;
		}
		else { //cout << "d = 3" << endl;
			int out = 2;
			for (int i = 0; i < (int)a.size() - 2; i++) {
				//cout << i << " " << a.size() - 2 << " " << (i < (int)a.size() - 2) << endl;
				if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
					out = 0;
					break;
				}
			}

			for (int i = 0; i < a.size() - 1; i++) {
				if (a[i] == a[i + 1] && a[i] != a[a.size()-1]) {
					out = min(out, 1);
					break;
				}
			}

			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < i; j++) {
					if (a[i] == 2 * a[j]) {
						out = min(out, 1);
						break;
					}
				}
			}

			cout << out << endl;
		}
	}
	return 0;
}