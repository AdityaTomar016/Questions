class Solution {
public:
    int solve(int i,int time,vector<int>& satisfaction,vector<vector<int>> &dp){
        if(i >= satisfaction.size()){
            return 0;
        }
        if(dp[i][time] != -1){
            return dp[i][time];
        }
        
        int take = 0, nottake = 0;
        if(satisfaction[i] < 0){
            nottake = solve(i+1,time,satisfaction,dp);
        }
        take = satisfaction[i]*time + solve(i+1,time+1,satisfaction,dp);
        
        return dp[i][time] = max(take,nottake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        
        sort(satisfaction.begin() , satisfaction.end());
        vector<vector<int>>dp(n,vector<int>(501,-1));
        return solve(0,1,satisfaction,dp);
    }
};