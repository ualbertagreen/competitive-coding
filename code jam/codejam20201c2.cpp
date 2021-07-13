#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void M(int cas) {
	vector<pair<string, string>> mr;

	for (int i = 0; i < 10000; i++) {
		string x; string y;
		cin >> x >> y;
		mr.push_back(pair<string, string>(x, y));
	}

	sort(mr.begin(), mr.end());

	vector<char> D;
	for (int i = 0; i < 10000; i++) {
		int found = -1;
		if (mr[i].first.length() == mr[i].second.length()) {
			bool f = false;
			for (int k = 0; k < D.size(); k++) {
				if (mr[i].second[0] == D[k]) {
					f = true;
					break;
				}
			}

			if (!f) {
				found = 0;
			}
		}

		if (found != -1) {
			D.push_back(mr[i].second[found]);
			//cout << D[D.size() - 1] << endl;
		}
	}

	cout << "Case #" << cas + 1 << ": ";

	for (int i = 0; i < mr.size(); i++) {
		bool found = false;
		for (int j = 0; j < mr[i].second.length(); j++) {
			found = false;
			for (int k = 0; k < D.size(); k++) {
				if (mr[i].second[j] == D[k]) {
					found = true;
					break;
				}
			}

			if (!found) {
				cout << mr[i].second[j];
				break;
			}
		}

		if (!found) {
			break;
		}
	}

	for (int i = 0; i < D.size(); i++) {
		cout << D[i];
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int U; cin >> U;

		vector<pair<string, string>> mr;

		for (int i = 0; i < 10000; i++) {
			string x; string y;
			cin >> x >> y;
			mr.push_back(pair<string, string>(x, y));
		}

		vector<pair<int, char>> count;
		for (int i = 0; i < 26; i++) {
			count.push_back(pair<int, char>(0, 'A' + i));
		}

		for (int i = 0; i < mr.size(); i++) {
			count[mr[i].second[0] - 'A'].first++;
		}

		sort(count.begin(), count.end());

		vector<char> D;
		for (int i = 0; i < 9; i++) {
			D.push_back(count[count.size() - i - 1].second);
		}

		cout << "Case #" << cas + 1 << ": ";

		for (int i = 0; i < mr.size(); i++) {
			bool found = false;
			for (int j = 0; j < mr[i].second.length(); j++) {
				found = false;
				for (int k = 0; k < D.size(); k++) {
					if (mr[i].second[j] == D[k]) {
						found = true;
						break;
					}
				}

				if (!found) {
					cout << mr[i].second[j];
					break;
				}
			}

			if (!found) {
				break;
			}
		}

		for (int i = 0; i < D.size(); i++) {
			cout << D[i];
		}
		cout << endl;
	}
	return 0;
}