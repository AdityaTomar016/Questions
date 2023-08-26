class Solution {
public:
    int solve(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>> &dp){
        if(i == pairs.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        
        int take=0,nottake=0;
        
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(i+1,i,pairs,dp);   
        }
        
        nottake = solve(i+1,prev,pairs,dp);
        
        return dp[i][prev+1] = max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int n = pairs.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0,nottake=0;
        
                if(prev == -1 || pairs[i][0] > pairs[prev][1]){
                    take = 1 + dp[i+1][i+1];   
                }

                nottake = dp[i+1][prev+1]; 

                dp[i][prev+1] = max(take,nottake);
            }
        }
        
        return dp[0][0];
    }
};