class Solution {
public:
    bool solve(int i,vector<int>&nums,vector<int>&dp){
        if(i == nums.size()-1){
            return true;
        }
        if(i >= nums.size()-1){
            return false;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int jumps = nums[i];
        
        bool takejump=false;
        
        for(int j=1;j<=jumps;j++){
            if(i+j < nums.size())
            takejump = takejump || solve(i+j,nums,dp);    
        }
        
        return dp[i] = takejump;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};