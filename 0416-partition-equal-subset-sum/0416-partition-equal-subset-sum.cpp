class Solution {
public:
    bool solve(int i,vector<int>&nums,int target,vector<vector<int>> &dp){
        
        if(target == 0){
            return true;
        }
        if(i == nums.size()-1){
            return target == nums[i];
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        bool take=false, nottake = false;
        
        if(target >= nums[i]){
            take = take || solve(i+1,nums,target-nums[i],dp);
        }
        
        nottake = solve(i+1,nums,target,dp);
        
        return dp[i][target] = (take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(auto i: nums){
            sum += i;
        }
        
        if(sum%2) return false;
        
        vector<vector<int>>dp(n,vector<int>(sum/2 + 1,-1));
        return solve(0,nums,sum/2,dp);
    }
};