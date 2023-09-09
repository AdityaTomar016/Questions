class Solution {
public:
    int solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int take=0,nottake=0;
        
        if(nums[i] <= target){
            take = solve(0,nums,target-nums[i],dp);
        }
        
        nottake = solve(i+1,nums,target,dp);
        
        return dp[i][target] = take+nottake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};