class Solution {
public:
    int solve(int i,int j,string word1,string word2,vector<vector<int>> &dp){
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ops = 0;
        
        if(word1[i] == word2[j]){
            ops = solve(i+1,j+1,word1,word2,dp);    
        }
        else{
            ops = 1 + min(solve(i,j+1,word1,word2,dp), min(solve(i+1,j,word1,word2,dp), solve(i+1,j+1,word1,word2,dp)));
        }
        return dp[i][j] = ops;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][m] = n-i;
        }
        for(int j=0;j<m;j++){
            dp[n][j] = m-j;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ops = 0;
        
                if(word1[i] == word2[j]){
                    ops = dp[i+1][j+1];    
                }
                else{
                    ops = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
                }
              dp[i][j] = ops;
            }
        }
        return dp[0][0];
    }
};