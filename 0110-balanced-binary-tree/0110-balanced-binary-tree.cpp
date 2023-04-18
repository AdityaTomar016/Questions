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
    int height(TreeNode* root){
        if(!root) return 0;
        
        int lh = 0, rh = 0;
        
        if(root->left) lh = height(root->left);
        if(root->right) rh = height(root->right);
        
        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh) > 1) return false;
        
        return true;
    }
};