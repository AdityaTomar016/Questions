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
//     bool solve(TreeNode* root){
//         if(!root){
//             return true;
//         }
        
//     }
    bool isCompleteTree(TreeNode* root) {
       bool nullnode = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            if(x == NULL){
                nullnode = true;
            }
            else{
                if(nullnode == true){
                    return false;
                }
                
                q.push(x->left);
                q.push(x->right);
            }
        }
        
        return true;
    }
};