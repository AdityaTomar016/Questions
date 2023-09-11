class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        
        int mod = 1e9+7;
        
        for(auto i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<long long>distance(n,1e18),ways(n,0);
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        
        pq.push({0,0});
        distance[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                long long nextnode = it.first;
                long long nextdis = it.second;
                
                if(distance[nextnode] > dis + nextdis){
                    distance[nextnode] = dis + nextdis;
                    pq.push({distance[nextnode], nextnode});
                    ways[nextnode] = ways[node];
                }
                else if(distance[nextnode]  == dis + nextdis){
                    ways[nextnode] = (ways[node]+ways[nextnode])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};