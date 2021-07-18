#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> arr;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		arr.push_back(temp);
	}
	vector<bool> small(n, false);
	vector<bool> large(n, false);

	long long min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] >= min) {
			small[i] = true;
			min = arr[i];
		}
	}

	long long  max = arr[arr.size() - 1] + 1;
	for (int i = n-1; i >= 0; i--) {
		if (arr[i] < max) {
			large[i] = true;
			max = arr[i];
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (small[i] && large[i]) {
			count++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	if (small[i])
	//		cout << "+ ";
	//	else
	//		cout << "- ";
	//}
	//cout << endl;

	//for (int i = 0; i < n; i++) {
	//	if (large[i])
	//		cout << "+ ";
	//	else
	//		cout << "- ";
	//}
	//cout << endl;

	cout << count << endl;
	//cin >> n;
	return 0;
}