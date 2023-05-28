class Solution {
public:
    
    int nthUglyNumber(int n) {
        
       vector<int>dp(n+1);
        dp[0] = 1;
        
        int p2=0,p3=0,p5=0;
        
        for(int i=1;i<=n;i++){
            int f2 = 2 * dp[p2];
            int f3 = 3 * dp[p3];
            int f5 = 5 * dp[p5];
            
            dp[i] = min({f2,f3,f5});
            
            if(dp[i] == f2) p2++;
            if(dp[i] == f3) p3++;
            if(dp[i] == f5) p5++;
        }
        
        return dp[n-1];
    }
};