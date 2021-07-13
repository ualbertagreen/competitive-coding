#include <iostream>

using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		int x, y;
		cin >> x >> y;
		while (N--) {
			int x1, y1;
			cin >> x1 >> y1;
			if (x1 > x && y1 > y)
				cout << "NE" << endl;
			else if (x1 < x && y1 > y)
				cout << "NO" << endl;
			else if (x1 < x && y1 < y)
				cout << "SO" << endl;
			else if (x1 > x && y1 < y)
				cout << "SE" << endl;
			else
				cout << "divisa" << endl;
		}
	}
	return 0;
}