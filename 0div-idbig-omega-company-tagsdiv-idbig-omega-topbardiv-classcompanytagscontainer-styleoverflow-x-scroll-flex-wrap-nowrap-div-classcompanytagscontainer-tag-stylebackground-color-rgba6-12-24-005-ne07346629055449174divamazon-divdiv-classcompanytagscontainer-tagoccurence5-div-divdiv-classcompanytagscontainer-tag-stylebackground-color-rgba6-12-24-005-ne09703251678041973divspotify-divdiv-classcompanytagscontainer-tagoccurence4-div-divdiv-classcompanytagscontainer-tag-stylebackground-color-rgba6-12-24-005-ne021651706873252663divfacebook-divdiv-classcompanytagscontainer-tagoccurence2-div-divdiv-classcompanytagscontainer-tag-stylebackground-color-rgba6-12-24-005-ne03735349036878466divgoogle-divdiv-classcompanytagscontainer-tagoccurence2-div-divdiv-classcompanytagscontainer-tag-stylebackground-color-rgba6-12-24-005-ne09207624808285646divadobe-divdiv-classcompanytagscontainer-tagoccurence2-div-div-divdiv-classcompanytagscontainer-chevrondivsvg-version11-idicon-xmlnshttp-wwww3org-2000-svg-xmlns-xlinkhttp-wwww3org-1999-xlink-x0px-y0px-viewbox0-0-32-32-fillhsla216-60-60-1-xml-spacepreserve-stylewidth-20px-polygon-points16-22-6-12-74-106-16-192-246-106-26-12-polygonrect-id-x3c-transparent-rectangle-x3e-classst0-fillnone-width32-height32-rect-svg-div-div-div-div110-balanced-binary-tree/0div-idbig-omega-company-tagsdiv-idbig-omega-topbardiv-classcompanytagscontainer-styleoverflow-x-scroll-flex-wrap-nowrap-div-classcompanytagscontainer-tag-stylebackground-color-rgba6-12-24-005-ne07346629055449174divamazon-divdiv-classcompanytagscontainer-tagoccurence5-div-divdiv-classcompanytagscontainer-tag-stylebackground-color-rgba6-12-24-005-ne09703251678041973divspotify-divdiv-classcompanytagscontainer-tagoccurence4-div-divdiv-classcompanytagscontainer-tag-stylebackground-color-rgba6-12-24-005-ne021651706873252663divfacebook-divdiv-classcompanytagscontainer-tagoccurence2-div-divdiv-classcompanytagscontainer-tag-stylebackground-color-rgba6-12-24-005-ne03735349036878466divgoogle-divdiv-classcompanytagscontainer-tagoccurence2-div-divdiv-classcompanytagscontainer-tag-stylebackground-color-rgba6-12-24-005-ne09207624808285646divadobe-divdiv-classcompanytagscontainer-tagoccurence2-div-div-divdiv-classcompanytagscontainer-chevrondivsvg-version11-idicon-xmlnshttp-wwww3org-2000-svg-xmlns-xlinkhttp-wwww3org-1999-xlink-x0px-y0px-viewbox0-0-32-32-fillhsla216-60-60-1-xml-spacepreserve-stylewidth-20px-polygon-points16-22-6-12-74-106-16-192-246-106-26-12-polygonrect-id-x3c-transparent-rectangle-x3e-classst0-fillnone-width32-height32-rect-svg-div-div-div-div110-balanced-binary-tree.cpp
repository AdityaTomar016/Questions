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
//     bool solve(TreeNode* root){
        
//     }
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
    
        int lh = height(root->left);
        int rh = height(root->right);
        
        return left && right && abs(lh-rh) <= 1;
    }
};