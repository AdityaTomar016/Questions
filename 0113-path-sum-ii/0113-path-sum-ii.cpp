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
    void solve(TreeNode* root,int sum,vector<int>&ds,vector<vector<int>>&ans){
        
        if(!root) return;
        
        ds.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sum == root->val){
                ans.push_back(ds);
            }
        }
        
        if(root->left){
            solve(root->left,sum-root->val,ds,ans);
        }
        if(root->right){
            solve(root->right,sum-root->val,ds,ans);
        }
        
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ds;
        vector<vector<int>>ans;
        
        solve(root,targetSum,ds,ans);
        
        return ans;
    }
};