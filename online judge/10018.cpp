#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pal(long P)
{
	if (P < 10)
		return true;
	long temp = P;
	int digits = 0;
	while (temp > 9)
	{
		temp /= 10;
		digits++;
	}
	if (P % 10 == temp)
	{
		while (digits)
		{
			temp *= 10;
			digits--;
		}
		return pal((P - temp)/10);
	}
	else
		return false;
}

int main()
{
	int N; cin >> N;
	for (int n = 0; n < N; n++)
	{
		long P;
		cin >> P;
		int it = 0;
		while (!pal(P))
		{
			long P1 = 0;
			long temp = P;
			while (temp)
			{
				P1 *= 10;
				P1 += temp % 10;
				temp /= 10;
			}
			P += P1;
			it++;
		}

		cout << it << ' ' << P << endl;
	}

	return 0;
}