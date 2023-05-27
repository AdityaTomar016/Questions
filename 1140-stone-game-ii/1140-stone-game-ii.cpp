class Solution {
public:
    int solve(int i,int M,vector<int>&piles,vector<vector<int>>&dp){
        if(i >= piles.size()){
            return 0;
        }
        
        if(dp[i][M] != -1){
            return dp[i][M];
        }
        int total=0;
        int ans = INT_MIN;
        
        for(int j=0;j<2*M;j++){
            if(i+j < piles.size()) total += piles[i+j];
            ans = max(ans, total-solve(i+j+1,max(j+1,M),piles,dp));
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        for(auto i: piles){
            sum += i;
        }
        vector<vector<int>>dp(piles.size(),vector<int>(1e4+1,-1));
        return (solve(0,1,piles,dp) + sum)/2;
    }
};