class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int currsum=nums[i];
        int currval = nums[i];
        int idx = i + 1;
        
        while(idx<nums.size() && nums[idx]==currval){
            currsum += nums[idx];
            idx++;
        }
        
        while(idx<nums.size() && nums[idx]==currval+1){
            idx++;
        }
        
        return dp[i] = max(currsum +                                                                       solve(idx,nums,dp),solve(i+1,nums,dp));
        
        }
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>dp(nums.size()+1,-1);
        
        sort(nums.begin(),nums.end());
        
        return solve(0,nums,dp);
    }
};