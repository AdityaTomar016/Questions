class Solution {
public:
    int solve(int i,int allow,vector<int>&prices,vector<vector<int>>&dp){
        
        if(i >= prices.size()){
            return 0;
        }
        
        if(dp[i][allow] != -1){
            return dp[i][allow];
        }
        int take=0,nottake=0;
            
        if(allow == 1){
            take = -prices[i] + solve(i+1,0,prices,dp);
            nottake = solve(i+1,allow,prices,dp);
        }    
        else{
            take = prices[i] + solve(i+1,1,prices,dp);
            nottake = solve(i+1,allow,prices,dp);
        }
        
        return dp[i][allow] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};