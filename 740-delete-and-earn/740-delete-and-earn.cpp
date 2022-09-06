class Solution {
public:
//     int solve(int i,vector<int>&nums,vector<int>&dp){
        
//         if(i>=nums.size()){
//             return 0;
//         }
        
//         if(dp[i]!=-1) return dp[i];
        
//         int currsum=nums[i];
//         int currval = nums[i];
//         int idx = i + 1;
        
//         while(idx<nums.size() && nums[idx]==currval){
//             currsum += nums[idx];
//             idx++;
//         }
        
//         while(idx<nums.size() && nums[idx]==currval+1){
//             idx++;
//         }
        
//         return dp[i] = max(currsum +                                                                       solve(idx,nums,dp),solve(i+1,nums,dp));
        
//         }
    int deleteAndEarn(vector<int>& nums) {
        
        int n = 10001;
        vector<int>dp(n,0);
        vector<int>sum(n,0);
        
        for(auto num: nums){
        sum[num] += num;
    }
        
        dp[0]=0;
        dp[1]=sum[1];
        
         for(int i=2; i<n; i++){
        dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
    }
    
    return dp[n-1];
    }
};