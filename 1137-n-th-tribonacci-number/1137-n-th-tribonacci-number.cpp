class Solution {
public:
//     int solve(int n,vector<int> &dp){
        
//         if(n == 0) return 0;
//         if(n == 1 || n == 2) return 1;
        
//         if(dp[n] != -1) return dp[n];
        
//         return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
//     }
    int tribonacci(int n) {
        
        vector<int>dp(n+1,0);
        
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 1;
        
//         if(n < 3){
//             return dp[n];
//         }
        
        for(int i=0;i<=n;i++){
            if(i == 0){
                dp[i] = 0;
            }
            else if(i == 1 || i == 2){
                dp[i] = 1;
            }
            else dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};