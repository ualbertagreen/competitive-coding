#include <iostream>

using namespace std;

int main()
{
	char a;
	bool left = true;
	while (cin.get(a))
	{
		if (a == '\"')
		{
			if (left) cout << "``";
			else cout << "\'\'";
			left = !left;
		}
		else cout << a;
	}

	return 0;
}