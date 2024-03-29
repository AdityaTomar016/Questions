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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        vector<vector<int>>ans;
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto x = q.front();
                q.pop();
                TreeNode* curr = x.first;
                int row = x.second.first;
                int col = x.second.second;
                
                mp[col][row].push_back(curr->val);
                
                if(curr->left) q.push({curr->left,{row+1,col-1}});
                if(curr->right) q.push({curr->right,{row+1,col+1}});
            }
        }
        
        for(auto i: mp){
            vector<int>v;
            for(auto j: i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};