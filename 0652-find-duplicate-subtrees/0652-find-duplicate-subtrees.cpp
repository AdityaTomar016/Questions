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
    unordered_map<string,int>mp;
    vector<TreeNode* > res;
    
    string solve(TreeNode* root){
        
        if(!root) return "";
        
        string s = "(";
        s += solve(root->left);
        s += to_string(root->val);
        s += solve(root->right);
        s += ")";
        
        if(mp[s] == 1){
            res.push_back(root);
        }
        
        mp[s]++;
        
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        if(!root) return {};
        
        solve(root);
        
        return res;
    }
};