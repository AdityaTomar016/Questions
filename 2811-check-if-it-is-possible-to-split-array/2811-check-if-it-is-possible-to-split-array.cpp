class Solution {
public:
    bool solve(int i,int j,int sum,int m,vector<int>& nums,vector<vector<int>> &dp){
        if(j - i <= 1){
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool left = false, right = false;
        
        if(sum-nums[j] >= m){
            right = solve(i,j-1,sum-nums[j],m,nums,dp);
        }
        if(sum-nums[i] >= m){
            left = solve(i+1,j,sum-nums[i],m,nums,dp);
        }
        
        return dp[i][j] = (left || right);
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int i=0,j=n-1;
        int sum=0;
        
        for(auto i: nums){
            sum += i;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(i,j,sum,m,nums,dp);
    }
};