class Solution {
public:
    
    int lastsum(string &s,int i){
        int sum=0;
        while(i < s.size()){
            sum += int(s[i]);
            i++;
        }
        return sum;
    }
//     int solve(int i,int j,string &s1,string &s2){
        
//         if(i == s1.size() || j == s2.size()){
//             if(i == s1.size() && j == s2.size()){
//                 return 0;
//             }
//             if(i == s1.size()){
//                 return lastsum(s2,j);
//             }
//             else{
//                 return lastsum(s1,i);
//             }
//         }
        
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int sum = 0;
        
//         if(s1[i] == s2[j]){
//             sum = 0 + solve(i+1,j+1,s1,s2);    
//         }
//         else{
//             sum = min(int(s1[i]) + solve(i+1,j,s1,s2), 
//                       int(s2[j]) + solve(i,j+1,s1,s2));
//         }
        
//         return dp[i][j] = sum;
//     }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n][m] = 0;
        
        for(int j=0;j<m;j++){
            dp[n][j] = lastsum(s2,j);
        }
        for(int i=0;i<n;i++){
            dp[i][m] = lastsum(s1,i);
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int sum = 0;
        
                if(s1[i] == s2[j]){
                    sum = dp[i+1][j+1];    
                }
                else{
                    sum = min(int(s1[i]) + dp[i+1][j], 
                              int(s2[j]) + dp[i][j+1]);
                }

                dp[i][j] = sum;
            }
        }
       return dp[0][0];
    }
};