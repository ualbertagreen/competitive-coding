#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a;
	while (cin >> a)
	{
		vector<int> rancher;
		vector<int> ranchdif;
		if (a == 1)
		{
			int temp;
			cin >> temp;
			cout << "Jolly" << endl;
			continue;
		}
		for (int i = 0; i < a; i++)
		{
			int temp;
			cin >> temp;
			rancher.push_back(temp);
		}
		for (int i = 1; i < rancher.size(); i++)
		{
			ranchdif.push_back(abs(rancher[i] - rancher[i - 1]));
		}
		sort(ranchdif.begin(), ranchdif.end());

		bool jolly = true;
		for (int i = 0; i < ranchdif.size(); i++)
			if (ranchdif[i] != i + 1)
				jolly = false;

		if (jolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}