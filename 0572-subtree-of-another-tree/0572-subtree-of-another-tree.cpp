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
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        bool sameNode = (p->val == q->val);
        
        return sameNode && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root){
            return false;
        }
        
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        
        return (root->val == subRoot->val && isSameTree(root,subRoot)) || left || right;
    }
};