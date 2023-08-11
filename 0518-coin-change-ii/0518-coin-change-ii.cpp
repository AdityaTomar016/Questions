class Solution {
public:
    int solve(int i,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(i == coins.size()-1){
            if(amount%coins[i] == 0){
                return 1;
            }
            return 0;
        }
        
        if(amount == 0){
            return 1;
        }
        
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int take = 0, nottake = 0;
        
        if(coins[i] <= amount){
            take = solve(i,amount-coins[i],coins,dp);
        }
        
        nottake = solve(i+1,amount,coins,dp);
        
        return dp[i][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        
        for(int am=0;am<=amount;am++){
            dp[n-1][am] = am%coins[n-1] == 0 ? 1 : 0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int am=0;am<=amount;am++){
                int take = 0, nottake = 0;
        
                if(coins[i] <= am){
                    take = dp[i][am-coins[i]];
                }

                nottake = dp[i+1][am]; 

                dp[i][am] = take+nottake;
            }
        }
        
        return dp[0][amount]; 
    }
};