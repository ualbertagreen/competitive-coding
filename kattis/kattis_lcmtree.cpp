#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

const long long mod = 1e9 + 7;

vector<long long> treeval;

string printtree(int subtree) {
	string out = "";
	while (subtree) { 
		out += (subtree & 1) ? "1 " : "0 ";
		subtree = (subtree >> 1) & ~(1 << (sizeof(subtree) * CHAR_BIT - 1));
	}
	return out;
}

int pos(int bits) {
	int out = 0;
	while (bits) {
		bits = (bits >> 1) & ~(1 << (sizeof(bits) * CHAR_BIT - 1));
		out++; 
	}
	return out - 1;
}

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int bitcount(int bits) {
	int out = bits & 1;
	while (bits >>= 1) { out += bits & 1; }
	return out;
}
vector<int> maxpos(const vector<long long> &num, int subtree) {
	vector<int> out(1, pos(subtree & (-subtree)));
	for (int i = out[0] + 1; i < num.size(); i++)
		if (((1 << i) & subtree) && num[i] == num[out[0]])
			out.push_back(i);
	return out;
}

long long root(const vector<long long> &num, int subtree) {
	if (subtree)
		return num[pos(subtree & (-subtree))];
	return 0;
}

int treepart(int subtree, int counter) {
	int out = 0;
	for (; counter > 0; counter >>= 1) {
		out |= (subtree & (-subtree)) * (counter & 1);
		subtree &= ~(subtree & (-subtree));
	}
	return out;
}
/*
long long node_assign(const vector<long long> &num, int subtree, long long val) {
	vector<int> maxpos = ::maxpos(num, subtree);
	long long root = ::root(num, subtree);
	int lb = maxpos[0];
	while (num[--lb] == num[maxpos[0]]) {} lb++;
	int ub = maxpos[maxpos.size() - 1];
	while (num[++ub] == num[maxpos[0]]) {} ub--;

	int counter = (1 << (ub - lb + 1)) - 1;
	int rootnum = bitcount(subtree & (counter << lb));
	int treecut = subtree & (~((1 << (ub + 1)) - 1));
	for (; counter >= 0; counter--)
		if (bitcount(counter) == rootnum) {
			treeval[(counter << lb) | treecut] = val;
		}

	return val;
}
*/
int least(const vector<long long> &num, int subtree) {
	for (int i = 0, j = 1; i < num.size() && j < num.size(); i++) {
		if (((1 << i) & subtree) == 0) {
			j = max(i + 1, j);
			while (j < num.size() && num[i] == num[j]) {
				if ((1 << j) & subtree) {
					subtree |= 1 << i;
					subtree &= ~(1 << j);
					break;
				}
				j++;
			}
		}
	}
	return subtree;
}

long long solve(const vector<long long> &num, int subtree) {
//	cout << "subtree entry:  " << printtree(subtree) << ", newtree: " << printtree(least(num, subtree)) << ", value: " << treeval[subtree] << endl;
	if (subtree == 0) return 0;
	if (subtree == (subtree & (-subtree))) return 1;
	subtree = least(num, subtree);
	if (treeval[subtree] != -1) return treeval[subtree];

	long long out = 0;
	vector<int> roots = maxpos(num, subtree);
	for (int i = 0; i < roots.size(); i++) {
		int treecut = subtree & ~(1 << roots[i]);
		for (int counter = (1 << bitcount(treecut)) - 1; counter > 0; counter--) {
			int treepart = ::treepart(treecut, counter);
			if (treepart > (treecut & ~treepart) && root(num, subtree) == lcm(root(num, treepart), root(num, treecut & ~treepart)))
				out += (solve(num, treepart) * solve(num, treecut - treepart)) % mod;
//			cout << "tree: " << printtree(subtree) << "subtree: " << printtree(treepart) << "subtree: " << printtree(treecut & ~treepart) << "current value: " << out << endl;
		}
	}

//	cout << "subtree exit:   " << printtree(subtree) << ", value: " << out % mod << endl;
//	return node_assign(num, subtree, out % mod);
	return treeval[subtree] = out % mod;
}

int main() {
	int t; cin >> t;
	int subtree = 1;
	vector<long long> num;
	while (t--) {
		long long temp; cin >> temp;
		num.push_back(temp);
		subtree <<= 1;
	}
	subtree--;
	treeval.assign(subtree + 1, -1);
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	
//	for (int i = 0; i < num.size(); i++) { cout << num[i] << " "; } cout << endl;
	cout << solve(num, subtree) << endl;

//	cin >> t;
	return 0;
}