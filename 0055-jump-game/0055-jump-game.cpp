class Solution {
public:
//     bool solve(int i,vector<int>&nums,vector<int>&dp){

//         if(i == nums.size()-1){
//             return true;
//         }
//         if(i >= nums.size()){
//             return false;
//         }

//         if(dp[i] != -1){
//             return dp[i];
//         }

//         bool ans = false;



//         return dp[i] = ans;
//     }
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,0);
        
        dp[n-1] = true;
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i] == 0){
                dp[i] = false;
                continue;
            }
            
            for(int j=1;j<=nums[i];j++){
                if(i+j < n){
                    dp[i] = dp[i] || dp[i+j];
                }
                
                if(dp[i] == true){
                    break;
                }
            }
        }
        return dp[0];
    }
};