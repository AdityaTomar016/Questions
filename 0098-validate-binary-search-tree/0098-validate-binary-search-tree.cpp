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
    bool solve(TreeNode* min,TreeNode* max, TreeNode* root){
        
        if(!root) return true;
        
         if(min!=NULL && root->val <= min->val){
             return false;
         }
         if(max!=NULL && root->val >= max->val){
            return false;
         }
        
        
        return solve(min,root,root->left) && solve(root,max,root->right);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return solve(NULL,NULL,root);
    }
};