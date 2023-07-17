class Solution {
public:
    
    string longestPalindrome(string s) {
        int i=0,j=0,n=s.size();
        int maxi = 0;
        string ans = "";
        
       vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int diff=0;diff<n;diff++){
            int i=0,j=i+diff;
            while(j<n){
                
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(diff == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                    }
                    else dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j]){
                    if(maxi < dp[i][j]){
                        maxi = dp[i][j];
                        ans = s.substr(i,j-i+1);
                    }
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};