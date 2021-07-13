#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int s = 0;
	while (cin >> n && n)
	{
		s++;
		cout << "Set #" << s << endl;
		vector<int> h;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			h.push_back(temp);
			sum += temp;
		}
		int ave = sum / h.size();

		int output = 0;
		for (int i = 0; i < n; i++)
		{
			output += abs(ave - h[i]);
		}
		cout << "The minimum number of moves is " << output / 2 << "." << endl << endl;
	}
	return 0;
}