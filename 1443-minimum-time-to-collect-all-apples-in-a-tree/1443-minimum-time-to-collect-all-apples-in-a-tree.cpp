class Solution {
public:
    
    int dfs(int node,int cost,vector<bool>hasApple,vector<int>adj[],vector<int>&vis){
        
        if(vis[node] == 1){
            return 0;
        }
        
        vis[node] = 1;
        
        int childcost=0;
        
        for(auto it: adj[node]){
            childcost += dfs(it,2,hasApple,adj,vis);
        }
        
        if(childcost == 0 && hasApple[node] == false){
            return 0;
        }
        
        return cost+childcost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int>adj[n];
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n,0);
        
        return dfs(0,0,hasApple,adj,vis);
    }
};