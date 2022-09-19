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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        long long ans = 1;
        
        while(!q.empty()){
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            ans = max(ans,end-start+1);
            
            
            for(int i=0;i<size;i++){
                auto x = q.front().first;
                long long idx = q.front().second - start;
                
                q.pop();
                
                    if(x->left)
                    q.push({x->left,2*idx+1});
                
                    if(x->right)
                    q.push({x->right,2*idx+2});
            }
        }
        return ans;
    }
};