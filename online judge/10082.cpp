#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	long double n, p;
	while (cin >> n >> p)
	{
		cout << fixed << setprecision(0) << pow(p, 1.0 / n) << endl;
	}
	return 0;
}