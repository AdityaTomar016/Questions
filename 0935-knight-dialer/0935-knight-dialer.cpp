class Solution {
public:
    int mod = 1e9+7;
    long solve(int i,int j,int n,vector<vector<vector<long>>>&dp){
    if(i>=4 || i<0 || j>=3 || j<0 || (i == 3 && j != 1)){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(dp[n][i][j] > 0){
            return dp[n][i][j];
        }
        dp[n][i][j] = solve(i+1,j+2,n-1,dp)%mod + 
                  solve(i+1,j-2,n-1,dp)%mod + 
                  solve(i-1,j+2,n-1,dp)%mod + 
                  solve(i-1,j-2,n-1,dp)%mod + 
                  solve(i+2,j+1,n-1,dp)%mod + 
                  solve(i-2,j+1,n-1,dp)%mod + 
                  solve(i+2,j-1,n-1,dp)%mod + 
                  solve(i-2,j-1,n-1,dp)%mod;

        
        return dp[n][i][j];
        
    }
    int knightDialer(int n) {
        vector<vector<vector<long>>>dp(n+1,vector<vector<long>>(4,vector<long>(3,0)));
        
        long ans = 0;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans = (ans + solve(i,j,n,dp))%mod;
            }
        }
        return ans;
    }
};