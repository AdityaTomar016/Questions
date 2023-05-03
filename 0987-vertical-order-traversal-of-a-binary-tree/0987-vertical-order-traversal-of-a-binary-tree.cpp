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
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto x = q.front();
                q.pop();
                
                TreeNode* node = x.first;
                int col = x.second.first;
                int row = x.second.second;
                
                mp[col][row].push_back(node->val);
                
                if(node->left){
                    q.push({node->left,{col-1,row+1}});
                }
                if(node->right){
                    q.push({node->right,{col+1,row+1}});
                }
            }
        }
        
        vector<vector<int>>res;
        for(auto i: mp){
            vector<int>v;
            for(auto j: i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    v.push_back(k);
                }
            }
            res.push_back(v);
        }
        
        return res;
    }
};