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
    int maxLevelSum(TreeNode* root) {
        int currL=0,maxsum=INT_MIN,ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            int sum=0;
            currL++;
            
            while(sz--){
                auto x = q.front();
                q.pop();
                
                sum += x->val;
                
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            
            if(maxsum < sum){
                maxsum = sum;
                ans = currL;
            }
        }
        return ans;
    }
};