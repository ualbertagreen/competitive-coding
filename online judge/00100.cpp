#include <iostream>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a << ' ' << b << ' ';
		if (a > b)
		{
			int temp = b;
			b = a;
			a = temp;
		}

		int max = 0;
		for (int i = a; i <= b; i++)
		{
			int n = i;
			int count = 1;
			while (n != 1)
			{
				if (n % 2)
					n = n * 3 + 1;
				else
					n /= 2;
				count++;
			}
			if (count > max)
				max = count;
		}
		cout << max << endl;
	}

	return 0;
}