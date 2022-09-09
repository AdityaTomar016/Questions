class Solution {
public:
    int solve(int i, int k, int n, vector<int>&arr, vector<int>&dp){
        
        
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int maxi = INT_MIN;
        int len=0;
        int ans = INT_MIN;
        
        for(int j=i;j<min(n,i+k);j++){
            
            len++;
            maxi = max(maxi,arr[j]);
            
            int sum = len*maxi + solve(j+1,k,n,arr,dp);
            ans = max(ans,sum);
            
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>dp(n+1,0);
        
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
            
            int maxi = INT_MIN;
            int len=0;
            int ans = INT_MIN;

            for(int j=i;j<min(n,i+k);j++){

                len++;
                maxi = max(maxi,arr[j]);

                int sum = len*maxi + dp[j+1];
                ans = max(ans,sum);

            }
            dp[i] = ans;
        }
        
        return dp[0];
    }
};