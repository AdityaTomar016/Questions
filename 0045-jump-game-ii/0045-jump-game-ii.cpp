class Solution {
public:
int solve(int i,int n,vector<int>&nums,vector<int>&dp){
    if(i == n-1){
        return 0;
    }

    if(dp[i] != 1e9){
        return dp[i];
    }

    int curr = nums[i];
    int mini = 1e9;

    for(int it=1;it<=curr;it++){
        if(i+it < n){
            mini = min(mini, 1 + solve(i+it,n,nums,dp));
        }
    }

    return dp[i] = mini;
}
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1e9);
        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            int curr = nums[i];
            int mini = 1e9;

            for(int it=1;it<=curr;it++){
                if(i+it < n){
                    mini = min(mini, 1 + dp[i+it]);
                }
            }

            dp[i] = mini;
        }
        return dp[0];
    }
};