class Solution {
public:
//     bool valid(int st,int end,vector<int>nums){
        
//         if(end-st+1 == 2 && nums[end] == nums[st]){
//             return true;
//         }
//         else if(end-st+1 == 3){
//             if(nums[st] == nums[st+1] && nums[st] == nums[end]){
//                 return true;
//             }
//             else if(nums[st]+1 == nums[st+1] && nums[st]+2 == nums[end]){
//                 return true;
//             }
//         }
//         return false;
//     }
    bool solve(vector<int>&nums,int i,vector<int>&dp){
        if(i == nums.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        if(i + 1 < nums.size() && nums[i] == nums[i+1] ) {
            if(solve(nums, i + 2, dp)) return true;
            if(i + 2 < nums.size() && nums[i] == nums[i+2]){
                if(solve(nums, i + 3, dp)) return true;
            }
        }
        if(i + 2 < nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2] - 2 ){
            if(solve(nums, i + 3, dp)) return true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};