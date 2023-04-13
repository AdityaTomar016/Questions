class Solution {
public:
    int solve(int st,int end,vector<int>&arr,vector<vector<int>>&dp){
        if(st == end){
            return 0;
        }
        if(dp[st][end] != INT_MAX){
            return dp[st][end];
        }
        int ans = INT_MAX;
        
        for(int i=st;i<end;i++){
            
            int left = solve(st,i,arr,dp);
            int right = solve(i+1,end,arr,dp);
            int temp = *max_element(arr.begin()+st,arr.begin()+i+1) * *max_element(arr.begin()+i+1,arr.begin()+end+1);
            
            ans = min(ans,left+right+temp);
        }
        
        return dp[st][end] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),INT_MAX));
        return solve(0,arr.size()-1,arr,dp);
    }
};