#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			for (int i = word.length() - 1; i >= 0; i--)
				cout << word[i];
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}