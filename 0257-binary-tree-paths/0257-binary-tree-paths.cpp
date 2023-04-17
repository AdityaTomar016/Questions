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
    void solve(TreeNode* root,string s,vector<string>&res){
        if(!root){
            return;
        }
        
        if(!root->right && !root->left){
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        if(root->left){
            solve(root->left, s + to_string(root->val) + "->",res);
        }
        if(root->right){
            solve(root->right, s + to_string(root->val) + "->",res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<string>res;
        string s = "";
        solve(root,s,res);
        return res;
    }
};