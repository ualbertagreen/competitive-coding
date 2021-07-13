#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> wage;
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			wage.push_back(temp);
		}
		sort(wage.begin(), wage.end());

		cout << "Case " << i + 1 << ": " << wage[1] << endl;
	}

	return 0;
}