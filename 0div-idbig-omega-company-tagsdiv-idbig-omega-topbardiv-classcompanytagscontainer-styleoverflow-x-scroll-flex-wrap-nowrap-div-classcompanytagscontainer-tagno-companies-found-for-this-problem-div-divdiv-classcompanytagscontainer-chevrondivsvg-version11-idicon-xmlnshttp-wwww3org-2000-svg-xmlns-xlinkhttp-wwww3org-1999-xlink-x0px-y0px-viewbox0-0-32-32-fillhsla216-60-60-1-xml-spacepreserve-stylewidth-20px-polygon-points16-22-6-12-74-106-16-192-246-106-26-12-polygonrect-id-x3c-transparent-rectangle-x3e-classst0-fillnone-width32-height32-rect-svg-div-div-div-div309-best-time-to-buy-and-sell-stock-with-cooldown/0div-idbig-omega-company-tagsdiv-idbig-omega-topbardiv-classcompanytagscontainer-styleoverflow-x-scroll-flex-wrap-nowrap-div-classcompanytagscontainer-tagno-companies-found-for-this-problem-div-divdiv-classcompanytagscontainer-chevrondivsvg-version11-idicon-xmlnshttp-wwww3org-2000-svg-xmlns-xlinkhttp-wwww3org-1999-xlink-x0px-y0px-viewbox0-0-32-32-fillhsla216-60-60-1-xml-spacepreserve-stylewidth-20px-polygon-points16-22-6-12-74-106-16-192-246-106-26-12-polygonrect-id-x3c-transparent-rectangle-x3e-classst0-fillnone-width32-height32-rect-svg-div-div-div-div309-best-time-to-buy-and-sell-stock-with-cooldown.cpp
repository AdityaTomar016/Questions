class Solution {
public:
    int solve(int i,int buy,vector<int>&prices,vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int take=0,nottake=0;
        
        if(buy){
            take = -prices[i] + solve(i+1,0,prices,dp);
            nottake = solve(i+1,1,prices,dp);
        }
        else{
            take = prices[i] + solve(i+2,1,prices,dp);
            nottake = solve(i+1,0,prices,dp);
        }
        
        return dp[i][buy] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int take=0,nottake=0;
        
                if(j){
                    take = -prices[i] + dp[i+1][0]; 
                    nottake = dp[i+1][1]; 
                }
                else{
                    take = prices[i] + dp[i+2][1]; 
                    nottake = dp[i+1][0];
                }

                dp[i][j] = max(take,nottake);
            }
        }
        return dp[0][1];
    }
};