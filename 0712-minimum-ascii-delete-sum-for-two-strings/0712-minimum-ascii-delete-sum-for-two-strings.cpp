class Solution {
public:
    vector<vector<int>>dp;
    int lastsum(string &s,int i){
        int sum=0;
        while(i < s.size()){
            sum += int(s[i]);
            i++;
        }
        return sum;
    }
    int solve(int i,int j,string &s1,string &s2){
        
        if(i == s1.size() || j == s2.size()){
            if(i == s1.size() && j == s2.size()){
                return 0;
            }
            if(i == s1.size()){
                return lastsum(s2,j);
            }
            else{
                return lastsum(s1,i);
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int sum = 0;
        
        if(s1[i] == s2[j]){
            sum = 0 + solve(i+1,j+1,s1,s2);    
        }
        else{
            sum = min(int(s1[i]) + solve(i+1,j,s1,s2), 
                      int(s2[j]) + solve(i,j+1,s1,s2));
        }
        
        return dp[i][j] = sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        dp.resize(n,vector<int>(m,-1));
       return solve(0,0,s1,s2);
    }
};