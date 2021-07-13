#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << endl;
		int a, f;
		cin >> a >> f;
		for (int j = 0; j < f; j++)
		{
			if (j)
				cout << endl;
			for (int k = 1; k <= a; k++)
			{
				for (int l = 0; l < k; l++)
					cout << k;
				cout << endl;
			}
			for (int k = a - 1; k > 0; k--)
			{
				for (int l = 0; l < k; l++)
					cout << k;
				cout << endl;
			}
		}
	}
	return 0;
}