class Solution {
public:
    void solve(int i,vector<int>&dis,vector<pair<int,int>>adj[]){
        
        dis[i] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,i});
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int node= x.second;
            int dist = x.first;
            
            for(auto it: adj[node]){
                int nextnode = it.first;
                int nextdis = it.second;
                
                if(dist + nextdis < dis[nextnode]){
                    dis[nextnode] = dist + nextdis;
                    pq.push({dis[nextnode],nextnode});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>>adj[n];
        
        for(auto i: edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int ans=0 , mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            vector<int>dis(n,1e9);
            
            solve(i,dis,adj);
            
            int curr=0;
            
            for(auto it: dis){
                if(it <= distanceThreshold){
                    curr++;
                }
            }
            
            if(curr <= mini){
                mini = curr;
                ans = i;
            }
        }
        
        return ans;
    }
};