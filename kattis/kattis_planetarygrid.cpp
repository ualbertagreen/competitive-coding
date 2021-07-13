#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x1, y1, x2, y2;
		cin >> a >> b >> x1 >> y1 >> x2 >> y2;
		int i = x1 / a, j = y1 / b;

		pair<int, int> p[4];
		p[0] = pair<int, int>(abs(x1 - a * i), abs(x2 - a * i) + abs(y2 - y1));
		p[1] = pair<int, int>(abs(x1 - a * (i + 1)), abs(x2 - a * (i + 1)) + abs(y2 - y1));
		p[2] = pair<int, int>(abs(y1 - b * j), abs(x2 - x1) + abs(y2 - b * j));
		p[3] = pair<int, int>(abs(y1 - b * (j + 1)), abs(x2 - x1) + abs(y2 - b * (j + 1)));

		pair<int, int> min = p[0];
		for (int i = 1; i < 4; i++) {
			if (p[i].first < min.first || (p[i].first = min.first && p[i].second < min.second))
				min = p[i];
		}

		int out = min.first + 
	}
	return 0;
}