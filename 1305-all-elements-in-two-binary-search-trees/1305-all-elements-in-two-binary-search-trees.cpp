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
    void dfs(TreeNode* root, vector<int>&v){
        if(!root) return;
        
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>l1,l2,ans;
        dfs(root1,l1);
        dfs(root2,l2);
        
        int i=0,j=0;
        
        while(i<l1.size() && j<l2.size()){
            if(l1[i] > l2[j]){
                ans.push_back(l2[j++]);
            }
            else ans.push_back(l1[i++]);
        }
        
        while(i<l1.size()){
            ans.push_back(l1[i++]);
        }
        
        while(j<l2.size()){
            ans.push_back(l2[j++]);
        }

        return ans;
    }
};