class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {
        
       int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                     int left=0,right=0;
                    
                    if(i>0) left = dp[i-1][j];
                    else left = INT_MAX;
                    
                    if(j>0) right = dp[i][j-1];
                    else right = INT_MAX;
                    
                    dp[i][j] = grid[i][j] + min(left,right);
                }
               
            }
        }
        return dp[n-1][m-1];
    }
};