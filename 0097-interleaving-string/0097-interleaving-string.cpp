class Solution {
public:
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3,vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size() && k == s3.size()){
            return true;
        }
        if(i > s1.size() || j > s2.size() || k > s3.size()){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool first = false, second = false;
        
        if(s1[i] == s3[k]){
            first = solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j] == s3[k]){
            second = solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        
        return dp[i][j] = first || second;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        int k=s3.size()-1;
        
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                
                if(i == n && j == m){
                    dp[i][j] = 1;
                    continue;
                }
                int k = i+j;
                bool first = false, second = false;
        
                if(s1[i] == s3[i+j]){
                    first = dp[i+1][j];
                }
                if(s2[j] == s3[i+j]){
                    second = dp[i][j+1];
                }

                dp[i][j] = first || second;
            }
        }
        return dp[0][0];
    }
};