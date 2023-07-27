class Solution {
public:
    int solve(int i,vector<int>& coins, int amount,int n,vector<vector<int>> &dp){
        if(i == n-1){
            if(amount%coins[i] == 0){
                return amount/coins[i];
            }
            return 1e9;
        }
        
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int take = 1e9, nottake = 1e9;
        
        if(coins[i] <= amount){
            take = 1 + solve(i,coins,amount-coins[i],n,dp);
        }
        
        nottake = solve(i+1,coins,amount,n,dp);
        
        return dp[i][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount,n,dp);
        
        if(ans == 1e9) return -1;
        
        return ans;
    }
};