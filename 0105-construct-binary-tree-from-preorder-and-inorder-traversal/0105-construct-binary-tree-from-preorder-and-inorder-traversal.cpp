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
    unordered_map<int,int>mp;
    int idx = 0;
    TreeNode* build(int st,int end,vector<int>& preorder, vector<int>& inorder){
        if(st > end){
            return NULL;
        }
        int curr = preorder[idx];
        idx++;
        
        TreeNode* node = new TreeNode(curr);
        if(st == end){
            return node;
        }
        
        int pos = mp[curr];
        node->left = build(st,pos-1,preorder,inorder);
        node->right = build(pos+1,end,preorder,inorder);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return build(0,preorder.size()-1,preorder,inorder);
    }
};