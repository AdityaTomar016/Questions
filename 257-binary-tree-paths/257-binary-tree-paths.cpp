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
    void solve(TreeNode* root,string ds,vector<string>&s){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            s.push_back(ds+to_string(root->val));
            return;
        }
        
        solve(root->left,ds+to_string(root->val)+"->",s);
        solve(root->right,ds+to_string(root->val)+"->",s);
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string ds = "";
        solve(root,ds,s);
        return s;
    }
};