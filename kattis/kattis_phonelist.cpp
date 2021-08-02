#include <iostream>
#include <string>

using namespace std;

const int PHONE_SIZE = 10;

struct Trie {
	struct Trie *child[PHONE_SIZE];
	bool endnum;
};

struct Trie *createNode(void) {
	struct Trie *tNode = new Trie;
	tNode->endnum = false;
	for (int i = 0; i < PHONE_SIZE; i++) {
		tNode->child[i] = NULL;
	}
	return tNode;
}

void insert(struct Trie *root, string phone) {
	struct Trie *curr = root;
	for (int i = 0; i < phone.length(); i++) {
		int num = phone[i] - '0';
		if (!curr->child[num])
			curr->child[num] = createNode();
		curr = curr->child[num];
	}
	curr->endnum = true;
}

bool checkConsistent(struct Trie *root) {
	struct Trie *curr = root;
	for (int i = 0; i < PHONE_SIZE; i++) {
		if (curr->child[i]) {
			if (curr->endnum)
				return false;
			else
				if (!checkConsistent(curr->child[i]))
					return false;
		}
	}
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		struct Trie *root = createNode();
		int nums; cin >> nums;
		for (int i = 0; i < nums; i++) {
			string temp;
			cin >> temp;
			insert(root, temp);
		}

		if (checkConsistent(root))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}