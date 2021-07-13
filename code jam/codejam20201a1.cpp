#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
	int t; cin >> t;
	for (int cas = 0; cas < t; cas++) {
		int n; cin >> n;
		vector<string> p;
		string out = "";
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			temp.erase(0, 1);
			p.push_back(temp);
			if (temp.size() > out.size())
				out = temp;
		}

		//cerr << p.size() << endl;
		
		for (int i = 0; i < p.size(); i++) {
			//cerr << p[i] << ", " << p[i].size() << endl;
			for (int j = 0; j < p[i].size(); j++) {
				//cerr << p[i][p[i].size() - j - 1] << ", " << out[out.size() - j - 1] << endl;
				if (p[i][p[i].size() - j - 1] != out[out.size() - j - 1]) {
					out += "*";
					break;
				}
			}
		}

		if (out[out.size() - 1] == '*') {
			out = "*";
		}

		cout << "Case #" << cas + 1 << ": " << out << endl;
	}

	cin >> t;
	return 0;
}