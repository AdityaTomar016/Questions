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
    int solve(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int left=0,right=0;
        
        if(root->left)
        left = solve(root->left,ans);
        
        if(root->right)
        right = solve(root->right,ans);
        
        
        int nodeMax = max(root->val,max(root->val+left,max(root->val+right,root->val+left+right)));
        
        int singlePath = max(root->val,max(root->val+right,root->val+left));
        
        ans = max(ans,nodeMax);
        
        return singlePath;
    }
    int maxPathSum(TreeNode* root) {
        
        if(!root) return 0;
        
        int ans  = INT_MIN;
        
        solve(root,ans);
        
        return ans;
    }
};