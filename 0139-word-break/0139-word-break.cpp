class Solution {
public:
    bool solve(int i,int prev,string s,unordered_set<string>set,vector<vector<int>> &dp){
        if(i == s.size()){
            if(prev == s.size()){
                return true;
            }
            else if(set.find(s.substr(prev)) != set.end()){
                return true;
            }
            
            return false;
        }
        
        if(dp[i][prev] != -1){
            return dp[i][prev];
        }
        string word = "";
        word = s.substr(prev, i-prev+1);
        
        
        bool take = false, nottake = false;
        
        if(set.find(word) != set.end()){
            take = take || solve(i+1,i+1,s,set,dp);
        }
        nottake = solve(i+1,prev,s,set,dp);
        
        return dp[i][prev] = (take || nottake);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto it: wordDict){
            set.insert(it);
        }
        int n = s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        dp[n][n] = 1;
        
        for(int i=0;i<n;i++){
            string word = s.substr(i);
            if(set.find(word) != set.end()){
                dp[n][i] = 1;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                string word = s.substr(j, i-j+1);

                bool take = false, nottake = false;

                if(set.find(word) != set.end()){
                    take = take || dp[i+1][i+1];
                }
                nottake = dp[i+1][j];

                dp[i][j] = (take || nottake);
            }
        }
        return dp[0][0];
    }
};