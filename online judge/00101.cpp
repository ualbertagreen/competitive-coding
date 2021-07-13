#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct blo
{
	int value;
	int parent = -1;
	int child = -1;
};

int main()
{
	int B; cin >> B;
	vector<blo> blocks;
	for (int i = 0; i < B; i++)
	{
		blo temp; temp.value = i;
		blocks.push_back(temp);
	}

	string ins;
	while (cin >> ins && ins != "quit")
	{
		int a, b;
		string ins2;
		cin >> a >> ins2 >> b;
		bool illegal = false;
		int c = a; 
		while (c != -1)
		{
			c = blocks[c].child;
			if (c == b)
				illegal = true;
		}
		c = b;
		while (c != -1)
		{
			c = blocks[c].child;
			if (c == a)
				illegal = true;
		}
		if (illegal)
			continue;

		if (ins == "move")
		{
			c = blocks[a].child;
			while (c != -1)
			{
				blocks[c].parent = -1;
				c = blocks[c].child;
			}
			blocks[a].child = -1;
		}

		if (ins2 == "onto")
		{
			c = blocks[b].child;
			while (c != -1)
			{
				blocks[c].parent = -1;
				c = blocks[c].child;
			}
			blocks[b].child = -1;
		}

		while (blocks[b].child != -1)
		{
			b = blocks[b].child;
		}
		if (blocks[a].parent != -1)
			blocks[blocks[a].parent].child = -1;
		blocks[a].parent = b;
		blocks[b].child = a;
	}

	for (int i = 0; i < B; i++)
	{
		cout << i << ": ";
		if (blocks[i].parent != -1)
		{
			cout << endl;
			continue;
		}
		int j = i;
		while (j != -1)
		{
			cout << j << " ";
			j = blocks[j].child;
		}
		cout << endl;
	}
	return 0;
}