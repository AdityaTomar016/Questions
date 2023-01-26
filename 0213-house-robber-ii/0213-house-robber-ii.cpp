class Solution {
public:
     int solve(int i,vector<int>&nums,vector<int>&dp){
        
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int take = nums[i] + solve(i+2,nums,dp);
        int nottake = solve(i+1,nums,dp);
        
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
         
        vector<int>v1,v2;
        
        for(int i=0;i<n;i++){
            if(i != 0){
                v2.push_back(nums[i]);
            }
            if(i != n-1){
                v1.push_back(nums[i]);
            }
        }
        
        if(n > 1){
            int left = solve(0,v2,dp);
            
            for(int i=0;i<n;i++){
                dp[i] = -1;
            }
            
            int right = solve(0,v1,dp);
            
            return max(left,right);
        }
        
        return nums[0];
    }
};