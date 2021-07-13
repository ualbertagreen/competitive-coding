#include <iostream>
#include <vector>

using namespace std;

vector<long long> solve(long long hour, long long minute, long long second) {
	long long ticks = 1000000000LL * 12LL * 3600LL;
	long long hticks = 1000000000LL * 3600LL;
	long long mticks = 1000000000LL * 12LL * 60LL;
	second = (second + ticks - hour) % ticks;
	minute = (minute + ticks - hour) % ticks;
	hour = 0;

	for (int i = 0; i < 12; i++) {
		hour += hticks * i;
		minute = (minute + hticks * i) % ticks;
		second = (second + hticks * i) & ticks;

		if ((minute - 12 * hour % ticks) % 11 != 0) continue;

		long long x = (minute - 12 * hour % ticks) / 11;
		if (((hour + x) * 12 * 60) % ticks == (second + x) % ticks) {
			vector<long long> ans;
			ans.push_back(((hour + x) / hticks) % 12);
			ans.push_back(((minute + x) / mticks) % 60);
			ans.push_back(((second + x) / mticks) % 60);
			ans.push_back(((second + x) % mticks) / 720);
			return ans;
		}
	}

	vector<long long> out(1, -1);
	return out;
}

vector<long long> check(long long a, long long b, long long c) {
	vector<long long> out;
	out = solve(a, b, c);
	if (out[0] != -1)
		return out;

	out = solve(a, c, b);
	if (out[0] != -1)
		return out;

	out = solve(b, a, c);
	if (out[0] != -1)
		return out;

	out = solve(b, c, a);
	if (out[0] != -1)
		return out;

	out = solve(c, b, a);
	if (out[0] != -1)
		return out;

	out = solve(c, a, b);
	if (out[0] != -1)
		return out;

	vector<long long> temp(4, -1);
	return temp;
}

int main() {
	int t;	cin >> t;

	for (int cas = 0; cas < t; cas++) {
		long long a, b, c;
		cin >> a >> b >> c;

		vector<long long> ans;
		ans = check(a, b, c);
		
		cout << "Case #" << cas << ": " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
	}
	return 0;
}