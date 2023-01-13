class Solution {
public:
    vector<pair<int,int>>dir = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    
    double solve(int i,int j,int n,int k,vector<vector<vector<double>>>&dp){
        
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }
        
        if(k == 0){
            return 1;
        }
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        double total = 0;
        
        for(int it=0;it<dir.size();it++){
            int newr = dir[it].first;
            int newc = dir[it].second;
            
            total += 0.125 * solve(i+newr,j+newc,n,k-1,dp);
        }
        
        return dp[i][j][k] = total;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(row,col,n,k,dp);
    }
};