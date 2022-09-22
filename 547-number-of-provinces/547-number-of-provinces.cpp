class Solution {
public:
    void dfs(int i,vector<int>graph[],vector<int> &vis){
        
        vis[i]=1;
        
        for(auto it: graph[i]){
            if(!vis[it]){
                dfs(it,graph,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>graph[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }
        
        vector<int>vis(n,0);
        int count=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                count++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
            }
        }
        return count;
    }
};