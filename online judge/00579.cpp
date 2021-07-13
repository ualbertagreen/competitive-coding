#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int H, M;
	while (cin >> H)
	{
		cin.get();
		cin >> M;
		if (H == 0 && M == 0)
			break;

		double Md = (double)M * 6.0;
		double Hd = (double)H * 30.0 + Md / 12.0;

		double output = abs(Md - Hd);

		cout << fixed << setprecision(3) << ((output < 180.0) ? output : (360.0 - output)) << endl;
	}

	return 0;
}