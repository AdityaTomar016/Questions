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
    bool solve(TreeNode* root,TreeNode* maxi,TreeNode* mini){
        if(!root) return true;
        
        bool left=false,right=false;
        
        if(!maxi || root->val < maxi->val){
            left = solve(root->left,root,mini);
        }
        if(!mini || root->val > mini->val){
            right = solve(root->right,maxi,root);
        }
        
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        
        return solve(root,NULL,NULL);
    }
};