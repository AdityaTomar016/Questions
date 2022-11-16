class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n+1];
        
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(n+1,INT_MAX);
        dist[src] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int stops = x.first;
            int node = x.second.first;
            int dis = x.second.second;
            
            if(stops > k) continue;
            
            for(auto it: adj[node]){
                int adjnode = it.first;
                int nextdis = it.second;
                
                if(dist[adjnode] > dis + nextdis){
                    dist[adjnode] = dis + nextdis;
                    q.push({stops+1, {adjnode, nextdis + dis}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
    }
};