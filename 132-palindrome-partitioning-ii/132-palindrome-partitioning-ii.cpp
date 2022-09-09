class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++; 
            end--;
        }
        return true;
    }
    
    
    int minCut(string s) {
        
        int n = s.size();
        vector<int>dp(n+1,0);
        
        dp[n] = 0;
        
        for(int idx=n-1;idx>=0;idx--){

        int mini = INT_MAX;
        
        for(int i=idx;i<n;i++){
            
            if(isPalindrome(s, idx, i)){
                
                int cost = 1 + dp[i+1];
                mini = min(mini, cost);
                
            }
        }
        dp[idx] = mini;
            
        }
        return dp[0] - 1;
    }
};