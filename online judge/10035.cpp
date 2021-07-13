#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long a, b;
	while (cin >> a >> b && (a != 0 || b != 0))
	{
		int carry = 0;
		bool c = false;
		while (a || b)
		{
			if (a % 10 + b % 10 + (c ? 1 : 0) >= 10)
			{
				carry++;
				c = true;
			}
			else
				c = false;
			a /= 10;
			b /= 10;
		}
		if (carry)
			cout << carry;
		else
			cout << "No";
		cout << " carry operation";

		if (carry > 1)
			cout << "s." << endl;
		else
			cout << "." << endl;
	}

	return 0;
}