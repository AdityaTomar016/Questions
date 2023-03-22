class Solution {
public:
    vector<int> dijkstra(int n,vector<vector<int>>adj[],int &ans){
        
        vector<int>dis(n+1,INT_MAX);               priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int node = x.second;
            int dist = x.first;
            
            for(auto it: adj[node]){
                int nextnode = it[0];
                int nextdis = it[1];
                
                ans = min(ans,nextdis);
                
                if(dist + nextdis < dis[nextnode]){
                    dis[nextnode] = dist + nextdis;
                    pq.push({dist+nextdis,nextnode});
                }
            }
        }
        return dis;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj[n+1];
        
        for(auto i: roads){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>dis(n+1,INT_MAX);
        int ans = INT_MAX;
        
        dis = dijkstra(n,adj,ans);
        
        if(dis[n] == INT_MAX){
            return -1;
        }
        
        return ans;
    }
};