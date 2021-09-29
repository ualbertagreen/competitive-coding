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
    
    // recursive solution
    /*
    void recursiveTraversal(vector<int>& output, TreeNode* cur) {
        if (cur->left)
            recursiveTraversal(output, cur->left);
        output.push_back(cur->val);
        if (cur->right)
            recursiveTraversal(output, cur->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if (root)
            recursiveTraversal(output, root);
        
        return output;
    }
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<pair<TreeNode*, bool> > ancestors;
        
        if (root) // whether the left child has already been pushed
            ancestors.push(pair<TreeNode*, bool>(root, false)); 
        
        while (!ancestors.empty()) {
            TreeNode* cur = ancestors.top().first;
            if (cur->left && !ancestors.top().second) {
                ancestors.top().second = true;
                ancestors.push(pair<TreeNode*, bool>(cur->left, false));
                continue;
            }
            output.push_back(cur->val);
            ancestors.pop();
            if (cur->right)
                ancestors.push(pair<TreeNode*, bool>(cur->right, false));
        }
        
        return output;
    }
};