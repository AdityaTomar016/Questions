class Solution {
public:
    bool ispal(int i,int j,string &s,vector<vector<int>>&dp){
        
        if(i > j) return true;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool equal = false;
        if(s[i] == s[j]){
            if(j-i <= 2){
                equal = true;
            }
            else{
                equal = equal || ispal(i+1,j-1,s,dp);
            }
        }
        
        return dp[i][j] = equal;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        string res = "";
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(s[i] == s[j] && ispal(i+1,j-1,s,dp)){
                    if(j-i+1 > maxi){
                        maxi = j-i+1;
                        res = s.substr(i,j-i+1);
                    }
                }
            }
        }
        
        return res;
    }
};