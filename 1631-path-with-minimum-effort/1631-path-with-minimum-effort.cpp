class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int diff = x.first;
            int row = x.second.first;
            int col = x.second.second;
            
            if(row == n-1 && col == m-1) return diff;
            
            for(auto it: dir){
                int newr = row + it[0];
                int newc = col + it[1];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    
                    int newdis = max(diff,abs(heights[newr][newc] - heights[row][col]));
                    
                    if(dist[newr][newc] > newdis){
                        dist[newr][newc] = newdis;
                        pq.push({newdis, {newr,newc}});
                    }
                    
                    
                }
            }
        }
        
        return 0;
    }
};