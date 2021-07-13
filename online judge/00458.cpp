#include <iostream>

using namespace std;

int main()
{
	char a;
	while (cin.get(a))
	{
		if (a != '\n')
		{
			cout << (char)(a + '*' - '1');
		}
		else cout << a;
	}

	return 0;
}