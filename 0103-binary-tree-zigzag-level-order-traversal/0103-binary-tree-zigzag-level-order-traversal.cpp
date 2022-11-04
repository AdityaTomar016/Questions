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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int>>ans;
        vector<int>v;
        
        stack<TreeNode*>curr;
        stack<TreeNode*>next;
        
        bool leftright=true;
        
        curr.push(root);
        
        
        while(!curr.empty()){
            
            auto x = curr.top();
            curr.pop();
            v.push_back(x->val);
            
            if(leftright){
                if(x->left){
                    next.push(x->left);
                }
                if(x->right){
                    next.push(x->right);
                }
            }
            else{
                if(x->right){
                    next.push(x->right);
                }
                if(x->left){
                    next.push(x->left);
                }
            }
            if(curr.empty()){
                leftright = !leftright;
                swap(curr,next);
                ans.push_back(v);
                v.clear();
            }
        }
        
        return ans;
    }
};