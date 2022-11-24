class Solution {
public:
//     int solve(int i,int prev,vector<int>&nums,int n,vector<vector<int>> &dp){
        
//         if(i == n){
//             return 0;
//         }
        
//         if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
//         int nottake = solve(i+1,prev,nums,n,dp);
//         int take=-1;
        
//         if(prev == -1 || nums[prev] < nums[i]){
//             take = 1 + solve(i+1,i,nums,n,dp);
//         }
        
//         return dp[i][prev+1] = max(nottake,take);
//     }
    int lengthOfLIS(vector<int>& nums) {  
        
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                
                int nottake = dp[i+1][j+1];
                int take = -1;
                
                if(j == -1 || nums[j] < nums[i]){
                    take = 1 + dp[i+1][i+1];
                }
                
                dp[i][j+1] = max(take,nottake);
            }
        }
        
        
        return dp[0][0];
    }
};