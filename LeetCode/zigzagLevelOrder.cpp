/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int> > bfs;
        if (root) bfs.push(pair<TreeNode*, int>(root, 0)); // node and depth
        
        vector<int> level;
        vector<vector<int> > output;
        
        while (!bfs.empty()) {
            TreeNode* cur = bfs.front().first;
            int depth = bfs.front().second;
            bfs.pop();
            
            if (cur->left) bfs.push(pair<TreeNode*, int>(cur->left, depth+1));
            if (cur->right) bfs.push(pair<TreeNode*, int>(cur->right, depth+1));
            
            level.push_back(cur->val);
            if (bfs.empty() || bfs.front().second != depth) {
                if (depth % 2 == 1) reverse(level.begin(), level.end());
                
                output.push_back(level);
                level.clear();
            }                        
        }
                                    
        return output;                            
    }
};