class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n =points.size();
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                
                adj[i].push_back({dis,j});
                adj[j].push_back({dis,i});
            }
        }
        
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans = 0;
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            if(vis[x.second] == 1) continue;
            
            vis[x.second] = 1;
            ans += x.first;
            
            for(auto it: adj[x.second]){
                if(!vis[it.second]){
                    pq.push(it);
                }
            }
        }
        
        return ans;
    }
};