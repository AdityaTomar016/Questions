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
    bool isleaf(TreeNode* root){
        if(!root) return false;
        
        if(!root->left && !root->right){
            return true;
        }
        
        return false;
    }
   void solve(TreeNode* root,int &sum){
       
       if(!root) return;
       
       if(root->left){
           if(isleaf(root->left)){
               sum += root->left->val;
           }
           else solve(root->left,sum);
       }
      
       solve(root->right,sum);
       
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        
        return sum;
    }
};