class Solution {
public:
    int solve(int i,int j,string s,string t,vector<vector<int>> &dp){
        
        if(j == t.size()){
            return 1;
        }
        
        if(i >= s.size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int take=0,nottake = 0;
        
        if(s[i] == t[j]){
            take = solve(i+1,j+1,s,t,dp);
        }
        nottake = solve(i+1,j,s,t,dp);
        
        return dp[i][j] = take+nottake;
    }
    int numDistinct(string s, string t) {
        vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
        
        for(int i=0;i<=s.size();i++){
            dp[i][t.size()] = 1;
        }
        
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                
                double take=0,nottake = 0;
                
                if(s[i] == t[j]){
                    take = dp[i+1][j+1];
                }
                nottake = dp[i+1][j];
                
                dp[i][j] = take+nottake;
            }
        }
        return (int)dp[0][0];
    }
};