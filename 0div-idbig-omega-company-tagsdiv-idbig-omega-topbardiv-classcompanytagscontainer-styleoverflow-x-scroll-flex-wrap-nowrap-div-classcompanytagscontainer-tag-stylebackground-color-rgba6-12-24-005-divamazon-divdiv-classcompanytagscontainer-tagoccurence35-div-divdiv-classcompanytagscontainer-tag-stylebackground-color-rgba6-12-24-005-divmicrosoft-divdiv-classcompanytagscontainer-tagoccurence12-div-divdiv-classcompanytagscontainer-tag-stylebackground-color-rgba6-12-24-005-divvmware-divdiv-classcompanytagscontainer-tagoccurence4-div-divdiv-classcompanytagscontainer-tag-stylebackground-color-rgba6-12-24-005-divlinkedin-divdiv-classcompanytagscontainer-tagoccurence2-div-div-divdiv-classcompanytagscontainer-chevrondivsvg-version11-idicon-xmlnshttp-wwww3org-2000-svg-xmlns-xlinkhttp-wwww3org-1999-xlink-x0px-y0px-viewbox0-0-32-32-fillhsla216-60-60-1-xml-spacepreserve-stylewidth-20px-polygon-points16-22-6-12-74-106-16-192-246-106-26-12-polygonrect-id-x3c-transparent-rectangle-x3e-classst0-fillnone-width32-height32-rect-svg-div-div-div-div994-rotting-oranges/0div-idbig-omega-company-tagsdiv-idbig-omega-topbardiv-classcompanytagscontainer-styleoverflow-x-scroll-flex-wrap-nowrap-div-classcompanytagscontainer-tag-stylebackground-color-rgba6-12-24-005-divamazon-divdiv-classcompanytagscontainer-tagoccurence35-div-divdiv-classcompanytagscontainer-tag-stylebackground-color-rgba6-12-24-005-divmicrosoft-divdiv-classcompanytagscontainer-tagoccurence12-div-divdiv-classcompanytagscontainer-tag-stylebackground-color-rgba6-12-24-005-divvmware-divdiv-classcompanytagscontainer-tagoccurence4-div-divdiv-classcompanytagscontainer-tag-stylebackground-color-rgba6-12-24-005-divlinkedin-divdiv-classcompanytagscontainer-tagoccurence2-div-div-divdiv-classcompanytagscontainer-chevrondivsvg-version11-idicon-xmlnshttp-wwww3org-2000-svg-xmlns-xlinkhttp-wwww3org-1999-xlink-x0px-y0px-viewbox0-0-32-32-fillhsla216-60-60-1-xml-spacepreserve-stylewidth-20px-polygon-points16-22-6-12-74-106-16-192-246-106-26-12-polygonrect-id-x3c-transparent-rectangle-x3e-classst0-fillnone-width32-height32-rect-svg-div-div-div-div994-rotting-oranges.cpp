class Solution {
public:
    
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int time=-1;
        queue<pair<int,int>>q;
        bool flag=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] > 0) flag=true;
                
                if(grid[i][j] == 2){
                    q.push({i,j});    
                }
            }
        }
        
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int it=0;it<4;it++){
                    int x = i+dx[it];
                    int y = j+dy[it];
                    
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;    
                }
            }
        }
        
        if(!flag) return 0;
        
        return time;
    }
};