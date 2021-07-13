#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int f; cin >> f;
		long long burden = 0;
		for (int j = 0; j < f; j++)
		{
			long long a, b, c;
			cin >> a >> b >> c;
			burden += a * c;
		}
		cout << burden << endl;
	}

	return 0;
}