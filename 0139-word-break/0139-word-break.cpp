class Solution {
public:
    bool solve(int i,string s,unordered_set<string>set,vector<int> &dp){
        if(i == s.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        bool take = false;
        for(int j=i;j<s.size();j++){
            string word = s.substr(i,j-i+1);
            
            if(set.find(word) != set.end()){
                take = take || solve(j+1,s,set,dp);
            }
        }
        
        return dp[i] = take;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto it: wordDict){
            set.insert(it);
        }
        int n = s.size();
        
        vector<int>dp(n,-1);
        return solve(0,s,set,dp);
    }
};