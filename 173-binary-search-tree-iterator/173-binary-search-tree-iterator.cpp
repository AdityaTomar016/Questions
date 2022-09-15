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
// 3 7 9 15 20
class BSTIterator {
public:
    int idx=0;
    vector<int>in;
    
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) inorder(root->left);
        in.push_back(root->val);
        if(root->right) inorder(root->right);
    } 
    BSTIterator(TreeNode* root) {
        
        in.clear();
        inorder(root);
        
    }
    
    int next() {
        return in[idx++];
    }
    
    bool hasNext() {
        if(idx<in.size()){
            return true;
        }
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */