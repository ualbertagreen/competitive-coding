#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		int n, k;
		cin >> n >> k;

		vector<long long> tickets;
		for (int i = 0; i < n; i++) {
			long long temp; cin >> temp;
			tickets.push_back(temp);
		}

		sort(tickets.begin(), tickets.end());
		
		long long max1 = max(tickets[0] - 1, k - tickets[tickets.size() - 1]);
		long long max2 = min(tickets[0] - 1, k - tickets[tickets.size() - 1]);

		for (int i = 0; i < tickets.size() - 1; i++) {
			if ((tickets[i + 1] - tickets[i]) / 2 > max1) {
				max2 = max1;
				max1 = (tickets[i + 1] - tickets[i]) / 2;
				if ((tickets[i + 1] - tickets[i] - 1) / 2 > max2) {
					max2 = (tickets[i + 1] - tickets[i] - 1) / 2;
				}
			}
			else if ((tickets[i + 1] - tickets[i]) / 2 > max2) {
				max2 = (tickets[i + 1] - tickets[i]) / 2;
			}
		}

		long long ans = max1 + max2;

		for (int i = 0; i < tickets.size() - 1; i++) {
			if ((tickets[i + 1] - tickets[i] - 1) > ans) {
				ans = tickets[i + 1] - tickets[i];
			}
		}

		cout << "Case #" << cas << ": " << (long double)(ans) / (long double)k << endl;
	}
	return 0;
}