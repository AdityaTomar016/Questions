class Solution {
public:
    int dfs(int node,vector<int>&vis,vector<int> adj[]){
        
        vis[node] = 1;
        int count=0;
        
        for(auto it: adj[node]){
            if(!vis[abs(it)]){
                count += dfs(abs(it),vis,adj) + (it > 0);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        
        
        vector<int>vis(n,0);
        
        
        return dfs(0,vis,adj);
    }
};