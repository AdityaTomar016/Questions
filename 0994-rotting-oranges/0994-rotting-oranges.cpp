class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int ct=0;
        
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] > 0) ct++;
                
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int count=0;
        
        while(!q.empty()){
            
            int sz = q.size();
            count++;
            
            for(int i=0;i<sz;i++){
                
                auto t = q.front();
                q.pop();
                
                ct--;
                
                for(int i=0;i<4;i++) {
                    
                    int x = t.first + dir[i][0];
                    int y = t.second + dir[i][1];
                    
                    if(x<0 || y<0 || x>=n || y >= m || grid[x][y]!=1){
                        continue;
                   }
                   grid[x][y] = 2;
                    
                    q.push({x,y});
                }

            }
            
            
        }
        
        if(ct == 0) return max(0,count-1);
        return -1;
    }
};