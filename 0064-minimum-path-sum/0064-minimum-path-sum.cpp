class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        
        if(i >= n || j >= m){
            return INT_MAX;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(i+1,j,n,m,grid,dp);
        int down = solve(i,j+1,n,m,grid,dp);
        
        return dp[i][j] = grid[i][j] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        
        dp[n-1][m-1] = grid[n-1][m-1];
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                if(i == n-1 && j == m-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int right = dp[i+1][j];
                int down = dp[i][j+1];

                dp[i][j] = grid[i][j] + min(right,down);
            }
        }
        return dp[0][0];
    }
};