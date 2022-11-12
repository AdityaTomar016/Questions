class Solution {
public:
    bool dfs(int i,int c, vector<int>&vis,vector<int>&col,vector<vector<int>>& graph){
        
        col[i] = c;
        vis[i] = 1;
        
        for(auto it: graph[i]){
            if(!vis[it]){
                if(!dfs(it,c^1,vis,col,graph)){
                    return false;
                }
            }
            else if(col[i] == col[it]){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
     
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++){
            if(!vis[i] && !dfs(i,0,vis,col,graph)){
                return false;
            }
        }
        return true;
    }
};