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
    
    bool helper(TreeNode* root,set<int>&st,int k){
        if(!root) return false;
        
        int target = k-root->val;
        
        if(st.find(target) != st.end()){
            return true;
        }
        else{
            st.insert(root->val);
        }
        return helper(root->left,st,k) || helper(root->right,st,k);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>st;
        return helper(root,st,k);
    }
};