class Solution {
public:
    int solve(int i,int st,int en,int m,vector<int>& nums, vector<int>& multi,vector<vector<int>>&dp){
        
        if(i==m){
            return 0;
        }
        
        if(dp[i][st]!=INT_MIN) return dp[i][st];
        
        int left = nums[st]*multi[i] + solve(i+1,st+1,en,m,nums,multi,dp);
        int right = nums[en]*multi[i] + solve(i+1,st,en-1,m,nums,multi,dp);
        
        return dp[i][st] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
       int n = nums.size();
       int m = multipliers.size();
       
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        
        return solve(0,0,n-1,m,nums,multipliers,dp);

    }
};