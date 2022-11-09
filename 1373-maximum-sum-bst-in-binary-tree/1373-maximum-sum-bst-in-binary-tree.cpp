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


int ans=0;

class Node{
    
    public: 
    int mini,maxi,sum;
    
    Node(int mini,int maxi,int sum){
        this->mini = mini;
        this->maxi = maxi;
        this->sum = sum;
    }
};

class Solution {
    
public:
    Node solve(TreeNode* root){
        
        if(!root){
            return Node(INT_MAX,INT_MIN,0);
        }
        
        Node p(INT_MAX,INT_MIN,0);
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(root->val > left.maxi && root->val < right.mini){
            
            p = Node(min(root->val,left.mini),max(root->val,right.maxi),left.sum + right.sum + root->val);
        }
        else{
            p = Node(INT_MIN,INT_MAX,max(left.sum,right.sum));
        }
        
        ans = max(ans,p.sum);
        
        return p;
    }
    int maxSumBST(TreeNode* root) {
        
        ans = 0;
        
        solve(root);
        
        return ans;
    }
};