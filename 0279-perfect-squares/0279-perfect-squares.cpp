class Solution {
public:
    int numSquares(int n) {
        
        vector<int>dp(n+1,0);
        dp[0]=0;
        
        int ans=n;
        
        
        for(int i=1;i<=n;i++){
            dp[i] = i;
            for(int j=0;j*j<=i;j++){
                int square = j*j;
                dp[i] = min(dp[i], 1 + dp[i-square]);
            }
        }
        
        return dp[n];

    }
};