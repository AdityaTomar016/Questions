class Solution {
public:
    set<pair<int,int>>set;
    
    int dfs(int i,int k,vector<int>&rank,vector<vector<int>>&ans,vector<int>adj[]){
        
        if(rank[i] >= 0){
            return rank[i];
        }
        
        int currMinRankAdj = k;
        rank[i] = k;
        
        for(auto it: adj[i]){
            if(rank[it] == k-1 || rank[it] > rank[i]){
                continue;
            }
            
            int adjrank = dfs(it,k+1,rank,ans,adj);
            currMinRankAdj = min(currMinRankAdj,adjrank);
            
            if(adjrank > rank[i]){
                ans.push_back({i,it});
            }
        }
        
        return currMinRankAdj;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
            
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>>ans;
        vector<int>rank(n,-2);
        
        dfs(0,0,rank,ans,adj);
        
        
        return ans;
    }
};