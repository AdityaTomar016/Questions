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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        
        vector<int>ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            
            ans.push_back(q.back()->val);
            
            while(sz--){
                auto x = q.front();
                q.pop();
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return ans;
    }
};