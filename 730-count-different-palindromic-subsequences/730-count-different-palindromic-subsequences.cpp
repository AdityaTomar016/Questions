class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i,int j, string s,vector<vector<int>>&dp){
        
       if(i>j) return 0;
        
        if(i==j) return 1;
        
        if(dp[i][j]!=0) return dp[i][j];
        
        int num = 0;
        if(s[i] == s[j]){
            
            num = 2 * solve(i+1,j-1,s,dp);
            
            int left = i+1;
            int right = j-1;
            
            while(left<=right && s[left]!=s[i]){
                left++;
            }
            while(left<=right && s[i]!=s[right]){
                right--;
            }
            
            if(left<right) {
                num -= solve(left+1,right-1,s,dp);
            }
            else if(left==right){
                num+=1;
            }
            else num+=2;
        }
        else{
            
        num += solve(i+1,j,s,dp) + solve(i,j-1,s,dp) - solve(i+1,j-1,s,dp);
            
        }
        
        if(num < 0){
            dp[i][j] = num + mod;
        }
        else dp[i][j] = num % mod;
        
        
        return dp[i][j];
    }
    int countPalindromicSubsequences(string s) {
        
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        
        for(int i=0;i<n;i++) dp[i][i]=1;
        
         for(int l=2;l<=n;l++) {
            for(int i=0;i<n-l+1;i++) {
                
                int j=i+l-1;
                
                if(s[i] == s[j]){
            
            dp[i][j] = 2 * solve(i+1,j-1,s,dp);
            
            int left = i+1;
            int right = j-1;
            
            while(left<=right && s[left]!=s[i]){
                left++;
            }
            while(left<=right && s[i]!=s[right]){
                right--;
            }
            
            if(left<right) {
                dp[i][j] -= dp[left+1][right-1];
            }
            else if(left==right){
                dp[i][j] += 1;
            }
            else dp[i][j] += 2;
        }
        else{
        dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
                
         if(dp[i][j] < 0){
            dp[i][j] = dp[i][j] + mod;
        }
        else dp[i][j] = dp[i][j] % mod;
                
            }
         }
        return dp[0][n-1]; 
    }
};