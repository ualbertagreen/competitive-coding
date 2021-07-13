#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int r[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int c[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int a, b;
	int f = 0;
	while (cin >> a >> b && a != 0 && b != 0)
	{
		if (f)
			cout << endl;
		f++;
		vector< vector<int> > field;
		vector<int> row;
		row.assign(b + 2, 0);
		field.assign(a + 2, row);
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '*')
					field[i][j] = -1;
			}

		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				if (field[i][j] < 0)
					for (int k = 0; k < 8; k++)
						if (field[i + r[k]][j + c[k]] >= 0)
							field[i + r[k]][j + c[k]]++;


		cout << "Field #" << f << ":" << endl;
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				if (field[i][j] < 0)
					cout << '*';
				else
					cout << field[i][j];
			}
			cout << endl;
		}		
	}

	return 0;
}