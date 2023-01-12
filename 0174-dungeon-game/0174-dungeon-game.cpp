class Solution {
public:
   int solve(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<int>>&dp){
        
        if(i >= n || j >= m){
            return 1e9;
        }
       
        if(i == n-1 && j == m-1){
            
            if(mat[i][j] <= 0){
                return -mat[i][j] + 1;
            }
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
       
        int right = solve(i,j+1,n,m,mat,dp);
        int down = solve(i+1,j,n,m,mat,dp);
        
        int minhealth = min(down,right) - mat[i][j];
       
       if(minhealth <= 0){
           return dp[i][j] = 1;
       }
        
       return dp[i][j] = minhealth;
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,mat,dp);
    }
};