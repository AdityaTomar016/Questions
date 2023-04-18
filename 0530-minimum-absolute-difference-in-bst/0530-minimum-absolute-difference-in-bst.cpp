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
    void solve(TreeNode* root,int &val,int &mini){
        if(root->left){
            solve(root->left,val,mini);
        }
        
        if(val != -1){
            mini = min(mini,root->val - val);
        }
        
        val = root->val;
        
        if(root->right){
            solve(root->right,val,mini);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int val = -1,mini = INT_MAX;
        solve(root,val,mini);
        return mini;
    }
};