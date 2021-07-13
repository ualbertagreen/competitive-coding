#include <iostream>

using namespace std;

int main()
{
	char a;
	bool word = false;
		int count = 0;
	while (cin.get(a))
	{
		if (a == '\n')
		{
			cout << count << endl;
			count = 0;
		}
		else if (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z'))
		{
			word = true;
		}
		else if (word)
		{
			word = false;
			count++;
		}
	}

	return 0;
}