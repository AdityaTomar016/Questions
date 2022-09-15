/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void buildGraph(TreeNode* root,unordered_map<int,vector<int>>&graph){
    
    if(root->left){
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);
        buildGraph(root->left,graph);
    }
    
    if(root->right){
        graph[root->val].push_back(root->right->val);
        graph[root->right->val].push_back(root->val);
        buildGraph(root->right,graph);
    }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(k==0) return {target->val};
        
        unordered_map<int,vector<int>>graph;
        unordered_map<int,bool>vis;
        
        buildGraph(root,graph);
        
        vector<int>ans;
        queue<int>q;
        q.push(target->val);
        
        int cnt=0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                int x = q.front();
                q.pop();
                
                vis[x]=true;
                
                for(auto it: graph[x]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
            }
            cnt++;
            
            if(cnt == k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }
        return ans;
    }
};