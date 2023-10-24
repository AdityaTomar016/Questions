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
    vector<int> largestValues(TreeNode* root) {
        
        if(!root) return {};
        
        vector<int>res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            int maxi = INT_MIN;
            while(sz--){
                auto x = q.front();
                q.pop();
                
                maxi = max(maxi,x->val);
                
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            
            res.push_back(maxi);
        }
        
        return res;
    }
};