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
    void flatten(TreeNode* root) {
        
        if(!root || !root->left && !root->right) return;
        
        if(root->left){ 
            
        flatten(root->left);
        
        TreeNode* curr = root->right;
        root->right = root->left;
        root->left = NULL;
        
        TreeNode* t = root->right;
        
        while(t->right!=NULL){
            t = t->right;
        }
        
        t->right = curr;
        }
        
        flatten(root->right);
    }
};