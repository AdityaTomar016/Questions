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
    void inorder(TreeNode* root,vector<int>&in){
        if(!root) return;
        
        if(root->left) inorder(root->left,in);
        in.push_back(root->val);
        if(root->right) inorder(root->right,in);
        
        return;
    }
    int minDiffInBST(TreeNode* root) {
        
        vector<int>in;
        inorder(root,in);
        
        int mini = INT_MAX;
        
        for(int i=1;i<in.size();i++){
            mini = min(mini, in[i] - in[i-1]);
        }
        
        return mini;
    }
};