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
    int buildPath (TreeNode* cur, unordered_map<TreeNode*, int>& paths) {
        if (cur == NULL) return 0;
        if (paths.find(cur) == paths.end()) {
            paths[cur] = cur->val + max(0, max(buildPath(cur->right, paths), buildPath(cur->left, paths)));
        }
                
        return paths[cur];
    }
    
    int maxPaths(TreeNode* cur, unordered_map<TreeNode*, int>& paths) {
        int path = cur->val + max(0, paths[cur->left]) + max(0, paths[cur->right]);
        
        if (cur->left) path = max(path, maxPaths(cur->left, paths));
        if (cur->right) path = max(path, maxPaths(cur->right, paths));
        
        return path;
    }
      
    int maxPathSum(TreeNode* root) {
        int ans;
        unordered_map<TreeNode*, int> paths;
        
        buildPath(root, paths);
        
        if (root) return maxPaths(root, paths);
        else return 0;    
    }
};