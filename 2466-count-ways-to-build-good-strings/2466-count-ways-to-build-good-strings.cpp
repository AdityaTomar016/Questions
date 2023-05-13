class Solution {
public:
    int mod = 1e9+7;
    long long solve(int len,int low,int high,int zero,int one,vector<long long>&dp){
        if(len > high){
            return 0;
        }
        
        if(dp[len] != -1){
            return dp[len];
        }
        long long take=solve(len+one,low,high,zero,one,dp);
        long long nottake=solve(len+zero,low,high,zero,one,dp);
        
        if(len + one>=low && len + one<=high){
            take += 1;
        }
        if(len + zero>=low && len + zero<=high){
            nottake += 1;
        }
        
        
        return dp[len] = (take + nottake)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(1e5+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};