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
   
    TreeNode* first,*second,*pre=NULL;
    
    void solve(TreeNode* root){
        if(!root) return;
        
        solve(root->left);
        
        if(pre && pre->val > root->val){
            if(!first){
                first = pre;
            }
            second = root;
            
        }
        pre = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val,second->val);
    }
};