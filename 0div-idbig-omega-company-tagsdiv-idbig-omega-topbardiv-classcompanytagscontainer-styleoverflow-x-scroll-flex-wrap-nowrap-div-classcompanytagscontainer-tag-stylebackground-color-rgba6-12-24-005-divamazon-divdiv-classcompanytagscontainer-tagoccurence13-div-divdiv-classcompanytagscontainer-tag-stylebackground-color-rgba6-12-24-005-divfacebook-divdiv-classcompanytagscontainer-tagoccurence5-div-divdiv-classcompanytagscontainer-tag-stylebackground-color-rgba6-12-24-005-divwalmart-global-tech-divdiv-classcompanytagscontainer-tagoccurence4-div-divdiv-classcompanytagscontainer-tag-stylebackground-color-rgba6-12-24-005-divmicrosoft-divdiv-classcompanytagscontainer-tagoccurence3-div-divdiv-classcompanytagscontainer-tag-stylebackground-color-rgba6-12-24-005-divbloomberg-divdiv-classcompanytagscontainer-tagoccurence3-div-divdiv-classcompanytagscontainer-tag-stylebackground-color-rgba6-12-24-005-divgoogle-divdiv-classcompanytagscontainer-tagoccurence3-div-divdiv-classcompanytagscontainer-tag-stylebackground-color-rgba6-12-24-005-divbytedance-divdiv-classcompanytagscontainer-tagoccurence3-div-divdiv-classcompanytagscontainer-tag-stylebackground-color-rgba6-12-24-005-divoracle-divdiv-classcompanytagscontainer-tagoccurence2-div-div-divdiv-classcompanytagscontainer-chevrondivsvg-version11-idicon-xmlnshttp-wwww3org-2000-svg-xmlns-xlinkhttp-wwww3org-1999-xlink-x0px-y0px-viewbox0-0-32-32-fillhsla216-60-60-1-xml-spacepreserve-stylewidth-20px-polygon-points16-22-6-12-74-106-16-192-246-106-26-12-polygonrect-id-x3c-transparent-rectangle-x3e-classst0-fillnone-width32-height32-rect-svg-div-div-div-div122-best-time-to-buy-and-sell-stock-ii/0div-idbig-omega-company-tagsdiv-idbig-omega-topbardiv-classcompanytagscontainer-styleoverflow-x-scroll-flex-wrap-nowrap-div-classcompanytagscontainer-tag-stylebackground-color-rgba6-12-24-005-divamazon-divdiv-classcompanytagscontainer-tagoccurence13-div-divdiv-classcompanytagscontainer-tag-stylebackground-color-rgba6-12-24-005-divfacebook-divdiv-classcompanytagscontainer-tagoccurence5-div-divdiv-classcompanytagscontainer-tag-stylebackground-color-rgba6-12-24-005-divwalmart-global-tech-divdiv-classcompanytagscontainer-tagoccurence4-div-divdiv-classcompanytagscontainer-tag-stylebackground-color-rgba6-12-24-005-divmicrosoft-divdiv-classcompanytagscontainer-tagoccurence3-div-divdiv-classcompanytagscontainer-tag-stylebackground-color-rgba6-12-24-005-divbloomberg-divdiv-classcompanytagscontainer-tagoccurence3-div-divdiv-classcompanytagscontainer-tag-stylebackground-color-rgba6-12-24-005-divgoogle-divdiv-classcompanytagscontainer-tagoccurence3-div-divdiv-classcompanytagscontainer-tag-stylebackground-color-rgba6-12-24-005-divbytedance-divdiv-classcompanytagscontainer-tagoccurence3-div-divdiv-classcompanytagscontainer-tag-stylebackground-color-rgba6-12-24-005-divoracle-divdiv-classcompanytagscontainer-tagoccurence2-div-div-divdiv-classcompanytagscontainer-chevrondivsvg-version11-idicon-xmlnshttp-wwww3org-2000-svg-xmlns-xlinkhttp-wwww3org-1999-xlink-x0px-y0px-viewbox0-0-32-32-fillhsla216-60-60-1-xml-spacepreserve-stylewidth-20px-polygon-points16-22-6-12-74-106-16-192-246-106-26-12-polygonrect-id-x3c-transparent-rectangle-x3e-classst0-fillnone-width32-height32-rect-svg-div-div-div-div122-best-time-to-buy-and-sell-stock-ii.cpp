class Solution {
public:
    int solve(int i,int buy,vector<int>&prices,vector<vector<int>> &dp){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }       
        
        int take=0,nottake=0;
        
        if(buy == 1){
            take = -prices[i] + solve(i+1,0,prices,dp);
            nottake = solve(i+1,1,prices,dp);
        }
        else{
            take = prices[i] + solve(i+1,1,prices,dp);
            nottake = solve(i+1,0,prices,dp);
        }
        
        return dp[i][buy] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};