class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=K;k++){
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
        return dp[0][1][K];
    }
};