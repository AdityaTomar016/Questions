class Solution {
public:
    void dfs(int node,int dis,vector<int>adj[],vector<int>&vis,vector<int>&pathvis,vector<int>&distance,int &ans){
        
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dis++;
                distance[it] = dis;
                dfs(it,dis,adj,vis,pathvis,distance,ans);
            }
            else if(pathvis[it]){
                ans = max(ans,dis-distance[it]+1);
                break;
            }
        }
        
        pathvis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>adj[n];
        
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>dis(n,0);
        
        
        for(int i=0;i<n;i++){
            if(edges[i] == -1) continue;
            
            adj[i].push_back(edges[i]);
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,0,adj,vis,pathvis,dis,ans);
            }
            
        }
        
        if(ans == INT_MIN) return -1;
        
        return ans;
    }
};