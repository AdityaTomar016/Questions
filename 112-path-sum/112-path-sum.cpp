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
    bool solve(TreeNode* root,int target){
        
        if(!root){
            return false;
        }
        
        if(!root->left && !root->right){
            if(target == root->val){
                return true;
            }
            
            return false;
        }
        
        
        return solve(root->left,target-root->val) || 
               solve(root->right,target-root->val);
        
    }
    bool hasPathSum(TreeNode* root, int target) {
        return solve(root,target);
    }
};