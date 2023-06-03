class Solution {
public:
    int solve(int i,vector<pair<int,int>>count,int m,int n,vector<vector<vector<int>>>&dp){
        if(i >= count.size() || !count[i].first && !count[i].second){
            return 0;
        }
        
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int take = 0 ,nottake = 0;
        
        if(count[i].first <= m && count[i].second <= n){
            take = 1 + solve(i+1,count,m-count[i].first,n-count[i].second,dp);
        }
        
        nottake = solve(i+1,count,m,n,dp);
        
        return dp[i][m][n] = max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int sz = strs.size();
        vector<pair<int,int>>count(sz);
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int k=0;k<sz;k++){
            int one=0,zero=0;
            for(auto ch: strs[k]){
                if(ch == '1') one++;
                else zero++;
            }    
            
            for(int z=m;z>=zero;z--){
                for(int o=n;o>=one;o--){
                    dp[z][o] = max(dp[z][o], 1 + dp[z-zero][o-one]);
                }
            }
            
        }
        
        return dp[m][n];
    }
};