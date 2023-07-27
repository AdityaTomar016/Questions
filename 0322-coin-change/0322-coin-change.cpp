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
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        
        for(int amt=amount;amt>=0;amt--){
            if(amt%coins[n-1] == 0){
                dp[n-1][amt] = amt/coins[n-1];
            }
            else{
                dp[n-1][amt] = 1e9;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int amt=0;amt<=amount;amt++){
                
                int take = 1e9, nottake = 1e9;
        
                if(coins[i] <= amt){
                    take = 1 + dp[i][amt-coins[i]];
                }

                nottake = dp[i+1][amt];

                dp[i][amt] = min(take,nottake);
            }
        }
        
        if(dp[0][amount] >= 1e9){
            return -1;
        }
        
        return dp[0][amount];
    }
};