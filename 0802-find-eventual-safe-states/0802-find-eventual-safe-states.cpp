class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>& graph){
        
        vis[i] = 1;
        
        for(auto it: graph[i]){
            if(vis[it]==0 && dfs(it,vis,graph) || vis[it] == 1){
                return true;
            }
        }
        
        vis[i] = 2;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0),ans;
        
        for(int i=0;i<n;i++){
            if(vis[i] == 2 || !dfs(i,vis,graph)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};