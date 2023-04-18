class Solution {
public:
    int solve(int n,vector<int>&dp){
        
        if(n <= 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += solve(i,dp)*solve(n-1-i,dp);
        }
        
        return dp[n] = sum;
    }
    int numTrees(int n) {
        
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            
            for(int j=0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
    }
};