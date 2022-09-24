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
    void solve(TreeNode* root,int target,vector<int>&ds,vector<vector<int>>&ans){
        
        if(!root) return;
        
        ds.push_back(root->val);
        
        if(!(root->left) && !(root->right) && target == root->val){
                ans.push_back(ds);
        }
            
        solve(root->left,target - root->val,ds,ans);
        solve(root->right,target - root->val,ds,ans);
        
        ds.pop_back();
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL) return {};
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        solve(root,targetSum,ds,ans);
        
        return ans;
    }
};