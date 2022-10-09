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
    bool dfs(TreeNode* root, set<int> &mp, int k){
        if(root==NULL) return false;
        
        if(mp.find(k-root->val)!=mp.end()) return true;
        else 
            mp.insert(root->val);
        
        return dfs(root->left,mp,k) || dfs(root->right,mp,k);
        
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>mp;
        return dfs(root,mp,k);
    }
};