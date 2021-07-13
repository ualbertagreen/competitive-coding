#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int N = 0; N < n; N++)
	{
		int a, b;
		cin >> a >> b;
		int out = 0;
		for (int i = a; i <= b; i++)
		{
			if (i % 2)
				out += i;
		}
		cout << "Case " << N + 1 << ": " << out << endl;
	}

	return 0;
}