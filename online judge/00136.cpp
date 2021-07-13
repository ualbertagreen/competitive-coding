#include <iostream>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	set<long long> ugly;
	ugly.insert(1);

	auto it = ugly.cbegin();
	for (int count = 1; count < 1500; count++)
	{
		ugly.insert(*it * 2);
		ugly.insert(*it * 3);
		ugly.insert(*it * 5);
		it++;
	}

	cout << "The 1500'th ugly number is " << *it << "." << endl;
	system("pause");
	return 0;
}