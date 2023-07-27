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
        
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target + 1,0));
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int t=1;t<=target;t++){
            dp[n-1][t] = (t==nums[n-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            for(int t=1;t<=target;t++){
                
                bool take=false, nottake = false;
        
                if(t >= nums[i]){
                    take = take || dp[i+1][t-nums[i]];
                }

                nottake = dp[i+1][t];

                dp[i][t] = (take || nottake);
            }
        }
        return dp[0][target];
    }
};