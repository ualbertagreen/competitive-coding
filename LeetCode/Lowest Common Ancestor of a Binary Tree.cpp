/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool recursiveAncestor(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if (cur == NULL) return false;
        
        int count = 0;
        
        if (cur == p || cur == q) {
            count++;
        }
        
        if (recursiveAncestor(cur->left, p, q, ans)) {
            count++;
        }
        if (recursiveAncestor(cur->right, p, q, ans)) {
            count++;
        }
        
        if (count == 2) ans = cur;
        return (bool)count;
    }    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        recursiveAncestor(root, p, q, ans);
        
        return ans;
    }
};