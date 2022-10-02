class Solution {
public:
    
    int mod = 1e9+7;
    
//     int solve(int i,int n,int k,int target,vector<vector<int>>&dp){
        
//         if(i==n){
//             if(target==0){
//                 return 1;
//             }
//             return 0;
//         }
        
//         if(dp[i][target]!=-1) return dp[i][target];
        
//         int ans=0;
        
//         for(int idx=1;idx<=k;idx++){
           
//             if(idx <= target){
//                 int temp = solve(i+1,n,k,target-idx,dp)%mod;
//                 ans = ans%mod + temp%mod;
//             }
//         }
        
        
//         return dp[i][target] = ans%mod;
//     }
    int numRollsToTarget(int n, int f, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    
                    if(k<=j){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k])%mod;
                    }
                    
                }
            }
        }
        return dp[n][target];
    }
};