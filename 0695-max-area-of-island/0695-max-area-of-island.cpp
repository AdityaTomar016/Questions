class Solution {
public:
    
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        
        if(i >= n || j >= m || i < 0 || j < 0 || !grid[i][j]){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int area=0;
        
        area += solve(i+1,j,n,m,grid) + solve(i-1,j,n,m,grid) +                           solve(i,j+1,n,m,grid) + solve(i,j-1,n,m,grid);
        
        return area + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int area = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    area = max(area,solve(i,j,n,m,grid));
                }
            }
        }
        
        return area;
    }
};