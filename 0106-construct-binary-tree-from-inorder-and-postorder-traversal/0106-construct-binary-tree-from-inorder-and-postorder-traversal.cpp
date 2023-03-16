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
    int idx;
    TreeNode* build(int st,int end,vector<int>& inorder, vector<int>& postorder)
    {
        if(st > end){
            return NULL;
        }
        
        int curr = postorder[idx];
        idx--;
        TreeNode* node = new TreeNode(curr);
        if(st == end){
            return node;
        }
        
        int pos = mp[curr];
        node->right = build(pos+1,end,inorder,postorder);
        node->left = build(st,pos-1,inorder,postorder);
        
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = postorder.size()-1;
        for(int i=0;i<postorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return build(0,postorder.size()-1,inorder,postorder);
    }
};