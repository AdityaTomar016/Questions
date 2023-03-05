class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i == n-1){
            return 0;
        }
        
        if(dp[i] != 1e9){
            return dp[i];
        }
        
        int curr = nums[i];
        int ans = 1e9;
        
        for(int idx = 1;idx <= curr; idx++){
            if(i+idx < n)
            dp[i] = min(dp[i],1+solve(i+idx,n,nums,dp));
        }
        
        return dp[i];
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1e9);
        
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;i--){
            int curr = nums[i];
            int ans = 1e9;

            for(int j = 1;j <= curr; j++){
                if(i+j < n)
                dp[i] = min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0];
    }
};