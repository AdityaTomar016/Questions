class Solution {
public:
    int solve(int i,int buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i >= prices.size() || k == 0){
            return 0;
        }
        if(dp[i][buy][k] != -1){
            return dp[i][buy][k];
        }
        
        int take = 0 , nottake = 0;
        
        if(buy){
            take = -prices[i] + solve(i+1,0,k,prices,dp);
            nottake = solve(i+1,1,k,prices,dp);
        }
        else{
            take = prices[i] + solve(i+1,1,k-1,prices,dp);
            nottake = solve(i+1,0,k,prices,dp);
        }
        
        return dp[i][buy][k] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=2;k++){
                    int take = 0 , nottake = 0;
        
                    if(j){
                        take = -prices[i] + dp[i+1][0][k]; 
                        nottake = dp[i+1][1][k];
                    }
                    else{
                        take = prices[i] + dp[i+1][1][k-1];
                        nottake = dp[i+1][0][k];
                    }

                    dp[i][j][k] = max(take,nottake);
                }
            }
        }
        return dp[0][1][2];
    }
};