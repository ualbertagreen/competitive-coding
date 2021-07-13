#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> g;
	for (int i = 0; i < n * n; i++)
	{
		int temp;
		cin >> temp;
		g.push_back(temp);
	}

	vector<int> sum;
	for (int i = 0; i < n * n; i++)
	{
		int temp = 0;
		temp += g[i];
		if (i % n)
			temp += sum[i - 1];
		sum.push_back(temp);
	}

	int max = g[0];

	for (int i = 0; i < n; i++)
	{
		for (int j = -1; j < i; j++)
		{
			vector<int> col;
			col.push_back(sum[i] - ((j > 0)?sum[j]:0));
			for (int k = 1; k < n; k++)
			{
				col.push_back(((col[col.size() - 1] > 0) ? col[col.size() - 1] : 0) + sum[i + k*n] - ((j > 0) ? sum[j + k*n] : 0));
			}
			for (int k = 1; k < n; k++)
				if (col[k] > max)
					max = col[k];
		}
	}

	cout << max << endl;
	return 0;
}