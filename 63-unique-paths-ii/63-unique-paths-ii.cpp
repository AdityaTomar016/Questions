class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        
        if(i==0 && j==0){
            return 1;
        }
        
        if(i<0 || j<0 || grid[i][j]){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int up = solve(i-1,j,grid,dp);
        int left = solve(i,j-1,grid,dp);
        
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(grid[0][0] || grid[n-1][m-1]) {
            return 0;
        }
        
        return solve(n-1,m-1,grid,dp);
    }
};