class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }
        
        if(n==1) return 1;
        
       vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            int dis = x.first;
            int row = x.second.first;
            int col = x.second.second;
            
            for(auto dir : directions){

                int newr = row + dir[0];
                int newc = col + dir[1];


                if(newr >= 0 && newr < n && newc >= 0 && newc < m && 
                grid[newr][newc] == 0 && dist[newr][newc] > dis +1){

                    dist[newr][newc] = dis + 1;

                    if(newr == n-1 && newc == m-1){
                        return dis + 1;
                    }

                    q.push({dis+1, {newr, newc}});
                }
            }
                
            
        }
        
        return -1;
        
    }
};