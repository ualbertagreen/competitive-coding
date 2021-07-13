#include <iostream>

using namespace std;

int main() {
	char in;
	bool f = true;
	while (cin.get(in)) {
		if (in == '"') {
			if (f)
				cout << "``";
			else
				cout << "''";
			f = !f;
		}
		else
			cout << in;
	}
	return 0;
}