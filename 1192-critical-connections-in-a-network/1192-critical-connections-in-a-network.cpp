class Solution {
public:
    
    int timer = 0;
    
    void dfs(int i,int par, vector<int>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&ans,vector<int>adj[]){
        
        vis[i] = 1;
        tin[i] = timer;
        low[i] = timer;
        timer++;
        
        for(auto it: adj[i]){
            if(it == par){
                continue;
            }
            else if(!vis[it]){
                dfs(it,i,vis,tin,low,ans,adj);
                
                low[i] = min(low[i], low[it]);
                
                if(tin[i] < low[it]){
                    ans.push_back({i,it});
                }
            }
            else{
                low[i] = min(low[i], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
            
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>>ans;
        vector<int>tin(n,0),low(n,0),vis(n,0);
        
        dfs(0,-1,vis,tin,low,ans,adj);
        
        return ans;
    }
};