/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int> > bfs;
        if (root) bfs.push(pair<Node*, int>(root, 0));
        
        while(!bfs.empty()) {
            Node* cur = bfs.front().first;
            int level = bfs.front().second;
            bfs.pop();
            
            if (cur->left) bfs.push(pair<Node*, int>(cur->left, level+1));
            if (cur->right) bfs.push(pair<Node*, int>(cur->right, level+1));
            
            if (level == bfs.front().second) cur->next = bfs.front().first;
        }
        
        return root;
    }
};