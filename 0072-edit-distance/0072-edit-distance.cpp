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
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};