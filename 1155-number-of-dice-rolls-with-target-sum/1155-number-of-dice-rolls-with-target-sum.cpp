class Solution {
public:
    
    int mod = 1e9+7;
    
    int solve(int i,int n,int k,int target,vector<vector<int>>&dp){
        
        if(i==n){
            if(target==0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        int ans=0;
        
        for(int idx=1;idx<=k;idx++){
           
            if(idx <= target){
                int temp = solve(i+1,n,k,target-idx,dp)%mod;
                ans = ans%mod + temp%mod;
            }
        }
        
        
        return dp[i][target] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,n,k,target,dp);
    }
};