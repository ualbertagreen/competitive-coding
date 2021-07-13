#include <iostream>
#include <string>

using namespace std;

int main() {
	int t; cin >> t;
	int a, b;
	cin >> a >> b;

	for (int cas = 0; cas < t; cas++) {
		string hit = "";
		int x = 0, y = 0;
		while (hit != "HIT") {
			cout << (int) (x - 1e9) << " " << y << endl;
			cin >> hit;
			if (hit != "HIT") x++;
		} 

		hit = "";
		while (hit != "HIT") {
			cout << x << " " << (int) (y - 1e9) << endl;
			cin >> hit;
			if (hit != "HIT") y++;
		}

		for (int i = -5; i < 5; i++) {
			for (int j = -5; j < 5; j++) {
				cout << (int)(x - 1e9) + a + i << " " << (int)(y - 1e9) + b + j << endl;
				cin >> hit;
				if (hit == "CENTER") break;
			}
			if (hit == "CENTER") break;
		}
	}
	return 0;
}