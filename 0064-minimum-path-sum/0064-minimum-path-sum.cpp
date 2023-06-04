class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        }
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = grid[i][j]+min(solve(i+1,j,grid,dp),solve(i,j+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp);
    }
};