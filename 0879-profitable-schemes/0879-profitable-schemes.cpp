class Solution {
public:
    int mod = 1e9+7;
    
    int solve(int i,int n,int p,int minProfit, vector<int>& group, vector<int>& profit,vector<vector<vector<int>>>&dp){
        
        if(i == group.size()){
            if(n >= 0 && p >= minProfit){
                return 1;
            }
            return 0;
        }
        else if(n < 0) return 0;
        
        if(dp[i][n][p] != -1){
            return dp[i][n][p];
        }
        
        int take = 0, nottake = 0;
        
        take = solve(i+1,n-group[i],min(p+profit[i],minProfit),minProfit,group,profit,dp);
        
        nottake = solve(i+1,n,p,minProfit,group,profit,dp);
        
        return dp[i][n][p] = (take+nottake)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sz = group.size();
        
        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(0,n,0,minProfit,group,profit,dp);
    }
};