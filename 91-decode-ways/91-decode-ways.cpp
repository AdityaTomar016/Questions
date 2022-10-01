class Solution {
public:
    
    int solve(int i,string s,vector<int> &dp){
        
        if(s[i]=='0') return 0;
        
        if(i>=s.size()-1) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        string b = s.substr(i,2);
        
        int ways1 = solve(i+1,s,dp);
        int ways2 = 0;
        
        if(stoi(b) <= 26 && stoi(b) > 0){
            ways2 = solve(i+2,s,dp);
        }
        
        
        return dp[i] = ways1 + ways2;
    }
    int numDecodings(string s) {
        
        int n=s.size();
        vector<int>dp(n+1,-1);
        
        dp[0]=1;
        
        if(s[0]!='0') dp[1] = 1;
        else dp[1] = 0;
        
        for(int i=2;i<=n;i++){
            
            string b = s.substr(i-2,2);
        
            int ways1 = 0;
            int ways2 = 0;
            
            if(s[i-1]!='0') ways1 = dp[i-1];

            if(stoi(b) <= 26 && stoi(b) > 0 && s[i-2]!='0'){
                ways2 = dp[i-2];
            }
            
            dp[i] = ways1 + ways2;
        }
        return dp[n];
    }
};