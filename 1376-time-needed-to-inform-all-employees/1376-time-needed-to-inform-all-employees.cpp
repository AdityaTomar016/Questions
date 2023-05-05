class Solution {
public:
    void dfs(int node,int curr,vector<int>adj[],vector<int>& informTime,int &ans){
        ans = max(ans,curr);
        
        for(auto it: adj[node]){
            dfs(it,curr+informTime[node],adj,informTime,ans);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans = 0;
        
        dfs(headID,0,adj,informTime,ans);
        return ans;
    }
};