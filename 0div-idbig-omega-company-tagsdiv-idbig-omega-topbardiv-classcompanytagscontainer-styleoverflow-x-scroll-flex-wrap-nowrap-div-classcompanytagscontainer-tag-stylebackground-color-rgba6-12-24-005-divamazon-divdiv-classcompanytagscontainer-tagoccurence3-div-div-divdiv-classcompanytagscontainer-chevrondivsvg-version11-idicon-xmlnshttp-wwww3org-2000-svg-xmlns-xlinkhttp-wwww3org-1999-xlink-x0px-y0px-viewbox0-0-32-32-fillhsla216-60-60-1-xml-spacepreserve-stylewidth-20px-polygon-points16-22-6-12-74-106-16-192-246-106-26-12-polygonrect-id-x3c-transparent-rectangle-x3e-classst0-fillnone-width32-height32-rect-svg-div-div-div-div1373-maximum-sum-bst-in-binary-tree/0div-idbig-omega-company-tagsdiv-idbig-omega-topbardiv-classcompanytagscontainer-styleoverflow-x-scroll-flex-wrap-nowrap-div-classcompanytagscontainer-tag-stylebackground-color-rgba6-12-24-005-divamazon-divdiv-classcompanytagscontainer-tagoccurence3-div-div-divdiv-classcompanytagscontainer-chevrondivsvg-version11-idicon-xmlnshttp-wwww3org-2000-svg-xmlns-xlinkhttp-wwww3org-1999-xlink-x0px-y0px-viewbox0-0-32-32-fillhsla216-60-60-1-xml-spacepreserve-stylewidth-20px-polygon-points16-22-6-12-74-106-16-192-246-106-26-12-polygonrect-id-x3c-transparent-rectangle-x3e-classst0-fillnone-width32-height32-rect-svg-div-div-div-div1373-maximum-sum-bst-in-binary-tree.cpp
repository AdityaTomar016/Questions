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
class Node{
    public:
    int maxi;
    int mini;
    int sum;
    Node(int maxi,int mini,int sum){
        this->maxi = maxi;
        this->mini = mini;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans=0;
    Node solve(TreeNode* root){
        if(!root){
            return Node(INT_MIN,INT_MAX,0);
        }
        Node node(INT_MIN,INT_MAX,0);
        Node left = solve(root->left);
        Node right = solve(root->right);
        
        if(root->val > left.maxi && root->val < right.mini){
            node = Node(max(root->val,right.maxi) , min(root->val,left.mini), root->val + left.sum + right.sum);
        }
        else{
            node = Node(INT_MAX,INT_MIN,max(left.sum,right.sum));
        }
        
        ans = max(ans, node.sum);
        
        return node;
    }
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        solve(root);
        
        return ans; 
    }
};